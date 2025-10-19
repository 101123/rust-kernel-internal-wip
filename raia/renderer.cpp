#include "renderer.h"

#include "dx.h"	
#include "um.h"
#include "util.h"

#include "fonts.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_impl_dx11.h>

#include <glfn.h>

#include <uncompress_lzma2.h>

#include <memory>

ID3D11Device* device;
ID3D11DeviceContext* device_context;
ID3D11RenderTargetView* render_target_view;

ImFontAtlas* font_atlas;
ImFont* fonts[ 8 ];
ImDrawListSharedData* shared_data;
ImDrawList* draw_list;
ImDrawData* draw_data;

class stream_reader {
public:
	stream_reader() = delete;
	stream_reader( const uint8_t* buffer ) :
		buffer_( buffer ), position_( 0ull ) {};

	uint8_t* get_position() {
		return ( uint8_t* )( buffer_ + position_ );
	}

	template <typename T>
	T read( size_t size = sizeof( T ) ) {
		T buffer = {};
		memcpy( &buffer, ( void* )get_position(), size );
		position_ += size;
		return buffer;
	}

	uint8_t* read( size_t size ) {
		uint8_t* buffer = get_position();
		position_ += size;
		return buffer;
	}

private:
	const uint8_t* buffer_;
	size_t position_;
};

ImFont* load_font( uint8_t* font_data, float font_size, bool uppercase = false ) {
	stream_reader stream( font_data );

	uint32_t width = stream.read<uint32_t>();
	uint32_t height = stream.read<uint32_t>();
	uint8_t* texture = stream.read( width * height * 4 );

	ImFontAtlasRectId rect = ImFontAtlasPackAddRect( font_atlas, width, height );
	if ( rect == ImFontAtlasRectId_Invalid )
		return nullptr;

	ImTextureRect* texture_rect = ImFontAtlasPackGetRect( font_atlas, rect );
	if ( !texture_rect )
		return nullptr;

	ImTextureData texture_data = ImTextureData();
	texture_data.Format = ImTextureFormat_RGBA32;
	texture_data.Width = width;
	texture_data.Height = height;
	texture_data.BytesPerPixel = 4;
	texture_data.Pixels = texture;

	ImFontAtlasTextureBlockCopy( &texture_data, 0, 0, font_atlas->TexData, texture_rect->x, texture_rect->y, texture_rect->w, texture_rect->h );

	// Needs to be done otherwise the ImTextureData destructor will attempt to free our data
	texture_data.Pixels = nullptr;

	ImFont* font = IM_NEW( ImFont );
	font->ContainerAtlas = font_atlas;
	font->CurrentRasterizerDensity = 1.f;
	font->LegacySize = font_size;

	ImFontBaked* baked = font->GetFontBaked( font_size );

	uint32_t glyphs = stream.read<uint32_t>();
	for ( size_t i = 0; i < glyphs; i++ ) {
		glyph_data glyph_info = stream.read<glyph_data>();

		ImFontGlyph glyph = ImFontGlyph();
		glyph.Visible = true;
		glyph.Codepoint = glyph_info.id;
		glyph.AdvanceX = ( float )glyph_info.x_advance;
		glyph.X0 = 0.f;
		glyph.Y0 = 0.f;
		glyph.X1 = ( float )glyph_info.width;
		glyph.Y1 = ( float )glyph_info.height;
		glyph.U0 = ( ( float )texture_rect->x + ( float )glyph_info.x ) / ( float )font_atlas->TexData->Width;
		glyph.V0 = ( ( float )texture_rect->y + ( float )glyph_info.y ) / ( float )font_atlas->TexData->Height;
		glyph.U1 = ( ( float )texture_rect->x + ( float )glyph_info.x + ( float )glyph_info.width ) / ( float )font_atlas->TexData->Width;
		glyph.V1 = ( ( float )texture_rect->y + ( float )glyph_info.y + ( float )glyph_info.height ) / ( float )font_atlas->TexData->Height;

		ImFontAtlasBakedAddFontGlyph( font_atlas, baked, nullptr, &glyph );
	}

	// Remap lowercase keys to uppercase
	if ( uppercase ) {
		for ( size_t i = 'a'; i <= 'z'; i++ ) {
			for ( size_t j = 0; j < baked->Glyphs.size(); j++ ) {
				const ImFontGlyph& glyph = baked->Glyphs[ j ];
				const uint32_t upper = i - 32u;

				if ( glyph.Codepoint == upper ) {
					baked->IndexAdvanceX[ i ] = baked->IndexAdvanceX[ upper ];
					baked->IndexLookup[ i ] = j;
				}
			}
		}
	}

	return font;
}

ImFont* load_compressed_glfn_font( uint8_t* compressed, size_t compressed_size, float font_size, std::initializer_list<std::pair<uint16_t, uint16_t>> ranges ) {
	stream_reader compressed_stream( compressed );

	size_t uncompressed_size = compressed_stream.read<int>();
	auto uncompressed = std::make_unique<uint8_t[]>( uncompressed_size );
	if ( !uncompressed.get() )
		return nullptr;

	if ( uncompress_lzma2( compressed_stream.get_position(), &compressed_size, uncompressed.get(), &uncompressed_size ) != uncompress_status::UNCOMPRESS_OK )
		return nullptr;

	stream_reader stream( uncompressed.get() );

	glf_file_header_s header = stream.read<glf_file_header_s>();
	glf_texture_header_s texture_header = stream.read<glf_texture_header_s>();

	int width = texture_header.iWidth;
	int height = texture_header.iHeight;

	auto rgba32 = std::make_unique<uint8_t[]>( width * height * 4 );
	if ( !rgba32.get() )
		return nullptr;

	uint8_t* grayscale = stream.read( width * height );

	// Convert grayscale to rgb
	for ( size_t i = 0; i < width * height; i++ ) {
		uint8_t* rgba = &rgba32[ i * 4 ];

		rgba[ 0 ] = 255;
		rgba[ 1 ] = 255;
		rgba[ 2 ] = 255;
		rgba[ 3 ] = grayscale[ i ];
	}

	ImFontAtlasRectId rect = ImFontAtlasPackAddRect( font_atlas, width, height );
	if ( rect == ImFontAtlasRectId_Invalid )
		return nullptr;

	ImTextureRect* texture_rect = ImFontAtlasPackGetRect( font_atlas, rect );
	if ( !texture_rect ) 
		return nullptr;

	ImTextureData texture_data = ImTextureData();
	texture_data.Format = ImTextureFormat_RGBA32;
	texture_data.Width = width;
	texture_data.Height = height;
	texture_data.BytesPerPixel = 4;
	texture_data.Pixels = rgba32.get();

	ImFontAtlasTextureBlockCopy( &texture_data, 0, 0, font_atlas->TexData, texture_rect->x, texture_rect->y, texture_rect->w, texture_rect->h );

	// This needs to be done otherwise the ImTextureData destructor will attempt to free our data
	texture_data.Pixels = nullptr;

	ImFont* font = IM_NEW( ImFont );
	font->ContainerAtlas = font_atlas;
	font->CurrentRasterizerDensity = 1.f;
	font->LegacySize = font_size;

	ImFontBaked* baked = font->GetFontBaked( font_size );

	int size = stream.read<int>();
	int size_read = 0;

	for ( const auto& range : ranges ) {
		for ( uint16_t codepoint = range.first; codepoint <= range.second && size_read < size; codepoint++ ) {
			glf_glyph_t glyph_info = stream.read<glf_glyph_t>();

			for ( size_t i = 0; i < glyph_info.nKerningPairs; ++i ) {
				glf_kerning_pair_t kerning_pair = stream.read<glf_kerning_pair_t>();
				size_read += sizeof( kerning_pair );
			}

			ImFontGlyph glyph = ImFontGlyph();
			glyph.Visible = true;
			glyph.Codepoint = codepoint;
			glyph.AdvanceX = ( float )glyph_info.iAdvance;
			glyph.X0 = ( float )glyph_info.iLeftBearing;
			glyph.Y0 = ( float )( -glyph_info.iTopBearing + header.fm.iAscent );
			glyph.X1 = glyph.X0 + ( float )glyph_info.iWidth;
			glyph.Y1 = glyph.Y0 + ( float )glyph_info.iHeight;
			glyph.U0 = ( ( float )texture_rect->x + ( float )glyph_info.iX ) / ( float )font_atlas->TexData->Width;
			glyph.V0 = ( ( float )texture_rect->y + ( float )glyph_info.iY ) / ( float )font_atlas->TexData->Height;
			glyph.U1 = ( ( float )texture_rect->x + ( float )glyph_info.iX + ( float )glyph_info.iWidth ) / ( float )font_atlas->TexData->Width;
			glyph.V1 = ( ( float )texture_rect->y + ( float )glyph_info.iY + ( float )glyph_info.iHeight ) / ( float )font_atlas->TexData->Height;

			ImFontAtlasBakedAddFontGlyph( font_atlas, baked, nullptr, &glyph );

			size_read += sizeof( glyph_info );
		}
	}

	return font;
}

bool renderer::init( IDXGISwapChain* swapchain ) {
	if ( swapchain->GetDevice( __uuidof( ID3D11Device ), ( void** )&device ) != S_OK )
		return false;

	device->GetImmediateContext( &device_context );

	util::com_ptr<ID3D11Texture2D> back_buffer;
	if ( swapchain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( void** )back_buffer.ptr_to() ) != S_OK )
		return false;

	if ( device->CreateRenderTargetView( back_buffer.get(), nullptr, &render_target_view ) != S_OK )
		return false;

	auto alloc_func = []( size_t size, void* _ ) -> void* { return um::malloc( size ); };
	auto free_func = []( void* ptr, void* _ ) -> void { um::free( ptr, 0ull ); };

	ImGui::SetAllocatorFunctions( alloc_func, free_func );

	GImGui = ( ImGuiContext* )um::malloc( sizeof( ImGuiContext ) );
	memset( GImGui, 0, sizeof( ImGuiContext ) );

	ImGui_ImplDX11_Init( device, device_context );

	font_atlas = IM_NEW( ImFontAtlas );
	// Texture repacks don't work properly, so this is necessary
	font_atlas->TexMinWidth = 1024;
	font_atlas->TexMinHeight = 1024;
	ImFontAtlasBuildInit( font_atlas );

	fonts[ fonts::verdana ] = load_compressed_glfn_font( antialiased_verdana_12_glfn, sizeof( antialiased_verdana_12_glfn ), 12.f, { { 0x0, 0xFF }, { 0x400, 0x4FF } } );
	fonts[ fonts::small_fonts ] = load_font( outlined_smallfonts_8, 8.f, true );

	ImGui_ImplDX11_UpdateTexture( font_atlas->TexData );

	shared_data = IM_NEW( ImDrawListSharedData );
	shared_data->TexUvWhitePixel = font_atlas->TexUvWhitePixel;
	shared_data->TexUvLines = font_atlas->TexUvLines;
	shared_data->FontAtlas = font_atlas;
	shared_data->CurveTessellationTol = 1.25f;
	shared_data->InitialFlags = ImDrawListFlags_AntiAliasedLines | ImDrawListFlags_AntiAliasedLines | ImDrawListFlags_AntiAliasedFill | ImDrawListFlags_AllowVtxOffset;
	shared_data->SetCircleTessellationMaxError( 0.3f );

	draw_list = IM_NEW( ImDrawList( shared_data ) );

	draw_data = IM_NEW( ImDrawData );
	draw_data->Valid = true;
	draw_data->CmdListsCount = 1;
	draw_data->CmdLists.push_back( draw_list );
	draw_data->FramebufferScale = ImVec2( 1.f, 1.f );
	draw_data->OwnerViewport = nullptr;
	draw_data->Textures = nullptr;

	return true;
}

void renderer::destroy() {
	if ( GImGui ) {
		um::free( GImGui, sizeof( ImGuiContext ) );
	}

	// IM_DELETE checks the pointer
	IM_DELETE( font_atlas );

	IM_DELETE( fonts[ fonts::verdana ] );
	IM_DELETE( fonts[ fonts::small_fonts ] );

	IM_DELETE( shared_data );
	IM_DELETE( draw_list );
	IM_DELETE( draw_data );

	if ( device ) {
		device->Release();
	}

	if ( device_context ) {
		device_context->Release();
	}

	if ( render_target_view ) {
		render_target_view->Release();
	}
}

void renderer::begin_frame() {
	if ( font_atlas->TexData->Status == ImTextureStatus_WantUpdates ) {
		ImGui_ImplDX11_UpdateTexture( font_atlas->TexData );
	}

	ImGui_ImplDX11_NewFrame();

	draw_list->_ResetForNewFrame();
	draw_list->PushClipRect( ImVec2( 0.f, 0.f ), ImVec2( ( float )screen_width, ( float )screen_height ) );
	draw_list->PushTexture( font_atlas->TexRef );
}

void renderer::end_frame() {
	draw_data->TotalIdxCount = draw_list->IdxBuffer.size();
	draw_data->TotalVtxCount = draw_list->VtxBuffer.size();
	draw_data->DisplayPos = ImVec2( 0.f, 0.f );
	draw_data->DisplaySize = ImVec2( ( float )screen_width, ( float )screen_height );

	device_context->OMSetRenderTargets( 1, &render_target_view, nullptr );

	ImGui_ImplDX11_RenderDrawData( draw_data );
}

void renderer::draw_rect( float x, float y, float width, float height, float thickness, uint32_t color, float rounding ) {
	draw_list->AddRect( ImVec2( x, y ), ImVec2( x + width, y + height ), color, rounding, ImDrawFlags_None, thickness );
}

void renderer::draw_filled_rect( float x, float y, float width, float height, uint32_t color, float rounding ) {
	draw_list->AddRectFilled( ImVec2( x, y ), ImVec2( x + width, y + height ), color, rounding );
}

void renderer::draw_filled_rect_with_flags( float x, float y, float width, float height, uint32_t color, float rounding, uint32_t flags ) {
	draw_list->AddRectFilled( ImVec2( x, y ), ImVec2( x + width, y + height ), color, rounding, flags );
}

void renderer::draw_filled_rect_multi_color( float x, float y, float width, float height, uint32_t colors[ 4 ] ) {
	draw_list->AddRectFilledMultiColor( ImVec2( x, y ), ImVec2( x + width, y + height ), colors[ 0 ], colors[ 1 ], colors[ 2 ], colors[ 3 ] );
}

void renderer::draw_circle( float x, float y, float radius, float thickness, uint32_t color ) {
	draw_list->AddCircle( ImVec2( x, y ), radius, color, 0, thickness );
}

void renderer::draw_filled_circle( float x, float y, float radius, uint32_t color ) {
	draw_list->AddCircleFilled( ImVec2( x, y ), radius, color );
}

void renderer::draw_line( float x1, float y1, float x2, float y2, float thickness, uint32_t color ) {
	draw_list->AddLine( ImVec2( x1, y1 ), ImVec2( x2, y2 ), color, thickness );
}

void renderer::draw_text( float x, float y, uint32_t font, uint32_t flags, uint32_t color, const char* text ) {
	ImFont* _font = fonts[ font ];
	float size = _font->LegacySize;

	if ( flags & text_flags::centered ) {
		ImVec2 text_size = _font->CalcTextSizeA( size, FLT_MAX, 0.f, text );
		x -= text_size.x / 2.f;
	}

	// Small fonts centering "fix"
	if ( font == fonts::small_fonts ) {
		x -= 1.f;
	}

	// Make the alpha of the drop shadow/outline less than the alpha of the text
	int alpha = std::max( ( int )( ( color & IM_COL32_A_MASK ) >> IM_COL32_A_SHIFT ) - 55, 0 );

	if ( flags & text_flags::drop_shadow ) {
		draw_list->AddText( _font, size, ImVec2( x + 1.f, y + 1.f ), IM_COL32( 0, 0, 0, alpha ), text );
	}

	else if ( flags & text_flags::outline ) {
        draw_list->AddText( _font, size, ImVec2( x + 1.f, y + 1.f ), IM_COL32( 0, 0, 0, alpha ), text );
        draw_list->AddText( _font, size, ImVec2( x - 1.f, y - 1.f ), IM_COL32( 0, 0, 0, alpha ), text );
        draw_list->AddText( _font, size, ImVec2( x + 1.f, y - 1.f ), IM_COL32( 0, 0, 0, alpha ), text );
        draw_list->AddText( _font, size, ImVec2( x - 1.f, y + 1.f ), IM_COL32( 0, 0, 0, alpha ), text );
        draw_list->AddText( _font, size, ImVec2( x + 1.f, y ), IM_COL32( 0, 0, 0, alpha ), text );
        draw_list->AddText( _font, size, ImVec2( x - 1.f, y ), IM_COL32( 0, 0, 0, alpha ), text );
        draw_list->AddText( _font, size, ImVec2( x, y - 1.f ), IM_COL32( 0, 0, 0, alpha ), text );
        draw_list->AddText( _font, size, ImVec2( x, y + 1.f ), IM_COL32( 0, 0, 0, alpha ), text );
    }

	draw_list->AddText( _font, size, ImVec2( x, y ), color, text );
}

void renderer::draw_text( float x, float y, uint32_t font, uint32_t flags, uint32_t color, const wchar_t* text ) {
	char buffer[ 512 ];
	ImTextStrToUtf8( buffer, sizeof( buffer ), ( ImWchar* )text, ( ImWchar* )( text + wcslen( text ) + 1 ) );

	draw_text( x, y, font, flags, color, buffer );
}

void renderer::draw_image( float x, float y, float width, float height, uint32_t color, ID3D11ShaderResourceView* srv ) {
	draw_list->AddImage( ImTextureRef( ( ImTextureID )srv ), ImVec2( x, y ), ImVec2( x + width, y + height ), ImVec2( 0.f, 0.f ), ImVec2( 1.f, 1.f ), color );
}

void renderer::draw_unity_image( float x, float y, float width, float height, uint32_t color, float rounding, ID3D11ShaderResourceView* srv ) {
	draw_list->AddCallback( ( ImDrawCallback )ImGui_ImplDX11_SetUnity, nullptr );
	draw_list->AddImageRounded( ImTextureRef( ( ImTextureID )srv ), ImVec2( x, y ), ImVec2( x + width, y + height ), ImVec2( 0.f, 1.f ), ImVec2( 1.f, 0.f ), color, rounding );
	draw_list->AddCallback( ( ImDrawCallback )ImGui_ImplDX11_RestoreUnity, nullptr );
}

void renderer::push_clip_rect( float x, float y, float width, float height ) {
	draw_list->PushClipRect( ImVec2( x, y ), ImVec2( x + width, y + height ) );
}

void renderer::pop_clip_rect() {
	draw_list->PopClipRect();
}

vector2 renderer::calc_text_size( uint32_t font, const char* text ) {
	ImFont* _font = fonts[ font ];
	ImVec2 size = _font->CalcTextSizeA( _font->LegacySize, FLT_MAX, 0.f, text );

	return vector2( size.x, size.y );
}

void renderer::wstr_to_utf8( const wchar_t* in, char* out, int out_size ) {
	ImTextStrToUtf8( out, out_size, in, in + wcslen( in ) + 1llu );
}