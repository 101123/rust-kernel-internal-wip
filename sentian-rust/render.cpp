#include "render.h"

#include "dx.h"
#include "um.h"

#include "fonts.h"

#include "cheat/sdk/sdk.h"
#include "cheat/entities.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_impl_dx11.h>

#include <algorithm>

template <typename T>
class ComPtr {
public:
	ComPtr() : 
		object_( nullptr ) {};

	~ComPtr() {
		if ( object_ ) {
			object_->Release();
		}
	}

	ComPtr( const ComPtr& ) = delete;
	ComPtr& operator=( const ComPtr& other ) = delete;

	ComPtr( ComPtr&& other ) {
		object_ = other.object_;
		other.object_ = nullptr;
	}

	ComPtr& operator=( ComPtr&& other ) {
		if ( &other != this ) {
			if ( object_ ) {
				object_->Release();
			}

			object_ = other.object_;
			other.object_ = nullptr;
		}

		return *this;
	}

	T* get() {
		return object_;
	}

	T** ptr_to() {
		return &object_;
	}

private:
	T* object_;
};

class StreamReader {
public:
	StreamReader() = delete;
	StreamReader( const uint8_t* buffer ) : 
		buffer_( buffer ), position_( 0ull ) {};

	template <typename T>
	T read( size_t size = sizeof( T ) ) {
		T buffer = {};
		memcpy( &buffer, ( void* )( buffer_ + position_ ), size );
		position_ += size;
		return buffer;
	}

	void* read( size_t size ) {
		void* buffer = ( void* )( buffer_ + position_ );
		position_ += size;
		return buffer;
	}

private:
	const uint8_t* buffer_;
	size_t position_;
};

enum Fonts {
	Verdana,
	Tahoma,
	SmallFonts
};

enum TextFlags {
	None = 0,
	Centered = 1,
	DropShadow = 2
};

class ImRenderer {
public:
	bool init( IDXGISwapChain* swap_chain ) {
		if ( swap_chain->GetDevice( __uuidof( ID3D11Device ), ( void** )&device_ ) != S_OK )
			return false;

		device_->GetImmediateContext( &device_context_ );

		LOG( "ID3D11Device: %p, ID3D11DeviceContext: %p\n", device_, device_context_ );

		ComPtr<ID3D11Texture2D> back_buffer;
		if ( swap_chain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( void** )back_buffer.ptr_to() ) != S_OK )
			return false;

		LOG( "ID3D11Texture2D: %p\n", back_buffer.get() );

		if ( device_->CreateRenderTargetView( back_buffer.get(), nullptr, &rtv_ ) != S_OK )
			return false;

		LOG( "ID3D11RenderTargetView: %p\n", rtv_ );
		
		auto alloc_func = []( size_t size, void* _ ) -> void* { return um::malloc( size ); };
		auto free_func = []( void* ptr, void* _ ) -> void { um::free( ptr, 0ull ); };

		ImGui::SetAllocatorFunctions( alloc_func, free_func );

		GImGui = ( ImGuiContext* )um::malloc( sizeof( ImGuiContext ) );
		memset( GImGui, 0, sizeof( ImGuiContext ) );

		ImGui_ImplDX11_Init( device_, device_context_ );

		font_atlas_ = IM_NEW( ImFontAtlas );
		// Texture repacks don't work properly, so this is necessary
		font_atlas_->TexMinWidth = 1024;
		font_atlas_->TexMinHeight = 1024;
		ImFontAtlasBuildInit( font_atlas_ );

		LOG( "ImFontAtlas: %p\n", font_atlas_ );

		fonts_[ Fonts::Verdana ] = create_font( antialiased_verdana_12, 12.f );
		fonts_[ Fonts::Tahoma ] = nullptr;
		fonts_[ Fonts::SmallFonts ] = create_font( outlined_smallfonts_8, 8.f, true );

		ImGui_ImplDX11_UpdateTexture( font_atlas_->TexData );

		shared_data_ = IM_NEW( ImDrawListSharedData );
		shared_data_->TexUvWhitePixel = font_atlas_->TexUvWhitePixel;
		shared_data_->TexUvLines = font_atlas_->TexUvLines;
		shared_data_->FontAtlas = font_atlas_;
		shared_data_->CurveTessellationTol = 1.25f;
		shared_data_->InitialFlags = ImDrawListFlags_AntiAliasedLines | ImDrawListFlags_AntiAliasedLines | ImDrawListFlags_AntiAliasedFill | ImDrawListFlags_AllowVtxOffset;
		shared_data_->SetCircleTessellationMaxError( 0.3f );

		LOG( "ImDrawListSharedData: %p\n", shared_data_ );

		draw_list_ = IM_NEW( ImDrawList( shared_data_ ) );

		LOG( "ImDrawList: %p\n", draw_list_ );

		draw_data_ = IM_NEW( ImDrawData );
		draw_data_->Valid = true;
		draw_data_->CmdListsCount = 1;
		draw_data_->CmdLists.push_back( draw_list_ );
		draw_data_->FramebufferScale = ImVec2( 1.f, 1.f );
		draw_data_->OwnerViewport = nullptr;
		draw_data_->Textures = nullptr;

		LOG( "ImDrawData: %p\n", draw_data_ );

		return true;
	}

	void destroy() {
		if ( GImGui ) {
			um::free( GImGui, sizeof( ImGuiContext ) );
		}

		// IM_DELETE checks the pointer
		IM_DELETE( font_atlas_ );

		IM_DELETE( fonts_[ Fonts::Verdana ] );
		IM_DELETE( fonts_[ Fonts::Tahoma ] );
		IM_DELETE( fonts_[ Fonts::SmallFonts ] );

		IM_DELETE( shared_data_ );
		IM_DELETE( draw_list_ );
		IM_DELETE( draw_data_ );

		if ( device_ ) {
			device_->Release();
		}

		if ( device_context_ ) {
			device_context_->Release();
		}

		if ( rtv_ ) {
			rtv_->Release();
		}
	}

	ImFont* create_font( uint8_t* font_data, float font_size, bool uppercase = false ) {
		StreamReader stream( font_data );

		uint32_t width = stream.read<uint32_t>();
		uint32_t height = stream.read<uint32_t>();
		void* texture = stream.read( width * height * 4 );

		ImFontAtlasRectId rect = ImFontAtlasPackAddRect( font_atlas_, width, height );
		if ( rect == ImFontAtlasRectId_Invalid )
			return nullptr;

		ImTextureRect* texture_rect = ImFontAtlasPackGetRect( font_atlas_, rect );
		if ( !texture_rect )
			return nullptr;

		ImTextureData texture_data = ImTextureData();
		texture_data.Format = ImTextureFormat_RGBA32;
		texture_data.Width = width;
		texture_data.Height = height;
		texture_data.BytesPerPixel = 4;
		texture_data.Pixels = ( unsigned char* )texture;

		ImFontAtlasTextureBlockCopy( &texture_data, 0, 0, font_atlas_->TexData, texture_rect->x, texture_rect->y, texture_rect->w, texture_rect->h );

		// Needs to be done otherwise the ImTextureData destructor will attempt to free our data
		texture_data.Pixels = nullptr;

		ImFont* font = IM_NEW( ImFont );
		font->ContainerAtlas = font_atlas_;
		font->CurrentRasterizerDensity = 1.f;
		font->LegacySize = font_size;

		ImFontBaked* baked = font->GetFontBaked( font_size );

		uint32_t glyphs = stream.read<uint32_t>();
		for ( size_t i = 0; i < glyphs; i++ ) {
			GlyphData glyph_data = stream.read<GlyphData>();

			ImFontGlyph glyph = ImFontGlyph();
			glyph.Visible = true;
			glyph.Codepoint = glyph_data.id;
			glyph.AdvanceX = ( float )glyph_data.x_advance;
			glyph.X0 = 0.f;
			glyph.Y0 = 0.f;
			glyph.X1 = ( float )glyph_data.width;
			glyph.Y1 = ( float )glyph_data.height;
			glyph.U0 = ( ( float )texture_rect->x + ( float )glyph_data.x ) / ( float )font_atlas_->TexData->Width;
			glyph.V0 = ( ( float )texture_rect->y + ( float )glyph_data.y ) / ( float )font_atlas_->TexData->Height;
			glyph.U1 = ( ( float )texture_rect->x + ( float )glyph_data.x + ( float )glyph_data.width ) / ( float )font_atlas_->TexData->Width;
			glyph.V1 = ( ( float )texture_rect->y + ( float )glyph_data.y + ( float )glyph_data.height ) / ( float )font_atlas_->TexData->Height;

			ImFontAtlasBakedAddFontGlyph( font_atlas_, baked, nullptr, &glyph );
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

	void begin_frame() {
		if ( font_atlas_->TexData->Status == ImTextureStatus_WantUpdates ) {
			ImGui_ImplDX11_UpdateTexture( font_atlas_->TexData );
		}

		ImGui_ImplDX11_NewFrame();

		draw_list_->_ResetForNewFrame();
		draw_list_->PushClipRect( ImVec2( 0.f, 0.f ), ImVec2( 2560.f, 1440.f ) );
		draw_list_->PushTexture( font_atlas_->TexRef );
	}

	void end_frame() {
		draw_data_->TotalIdxCount = draw_list_->IdxBuffer.size();
		draw_data_->TotalVtxCount = draw_list_->VtxBuffer.size();
		draw_data_->DisplayPos = ImVec2( 0.f, 0.f );
		draw_data_->DisplaySize = ImVec2( 2560.f, 1440.f );

		device_context_->OMSetRenderTargets( 1, &rtv_, nullptr );

		ImGui_ImplDX11_RenderDrawData( draw_data_ );
	}

	void draw_rect( float x, float y, float width, float height, float thickness, uint32_t color, float rounding = 0.f ) {
		draw_list_->AddRect( ImVec2( x, y ), ImVec2( x + width, y + height ), color, rounding, ImDrawFlags_None, thickness );
	}

	void draw_filled_rect( float x, float y, float width, float height, uint32_t color, float rounding = 0.f ) {
		draw_list_->AddRectFilled( ImVec2( x, y ), ImVec2( x + width, y + height ), color, rounding );
	}

	void draw_filled_rect_multi_color( float x, float y, float width, float height, uint32_t colors[ 4 ] ) {
		draw_list_->AddRectFilledMultiColor( ImVec2( x, y ), ImVec2( x + width, y + height ), colors[ 0 ], colors[ 1 ], colors[ 2 ], colors[ 3 ] );
	}

	void draw_circle( float x, float y, float radius, float thickness, uint32_t color ) {
		draw_list_->AddCircle( ImVec2( x, y ), radius, color, 0, thickness );
	}

	void draw_filled_circle( float x, float y, float radius, uint32_t color ) {
		draw_list_->AddCircleFilled( ImVec2( x, y ), radius, color );
	}

	void draw_line( float x1, float y1, float x2, float y2, float thickness, uint32_t color ) {
		draw_list_->AddLine( ImVec2( x1, y1 ), ImVec2( x2, y2 ), color, thickness );
	}

	void draw_text( float x, float y, Fonts font_idx, uint32_t flags, uint32_t color, const char* text ) {
		ImFont* font = fonts_[ font_idx ];
		float size = font->LegacySize;

		if ( flags & TextFlags::Centered ) {
			ImVec2 bounds = font->CalcTextSizeA( size, FLT_MAX, 0.f, text );
			x -= bounds.x / 2.f;
		}

		// Small fonts centering "fix"
		if ( font_idx == Fonts::SmallFonts ) {
			x -= 1.f;
		}

		if ( flags & TextFlags::DropShadow ) {
			draw_list_->AddText( font, size, ImVec2( x + 1.f, y + 1.f ), IM_COL32( 0, 0, 0, 200 ), text );
		}

		draw_list_->AddText( font, size, ImVec2( x, y ), color, text );
	}

	void draw_text( float x, float y, Fonts font_idx, uint32_t flags, uint32_t color, const wchar_t* text ) {
		char buffer[ 512 ];
		ImTextStrToUtf8( buffer, sizeof( buffer ), ( ImWchar* )text, ( ImWchar* )( text + wcslen( text ) + 1 ) );

		draw_text( x, y, font_idx, flags, color, buffer );
	}

	void push_clip_rect( float x, float y, float width, float height ) {
		draw_list_->PushClipRect( ImVec2( x, y ), ImVec2( x + width, y + height ) );
	}

	void pop_clip_rect() {
		draw_list_->PopClipRect();
	}

private:
	ID3D11Device* device_;
	ID3D11DeviceContext* device_context_;
	ID3D11RenderTargetView* rtv_;

	ImFontAtlas* font_atlas_;
	ImFont* fonts_[ 8 ];
	ImDrawListSharedData* shared_data_;
	ImDrawList* draw_list_;
	ImDrawData* draw_data_;
};

ImRenderer renderer;
bool renderer_init = false;

Matrix4x4 view_matrix;
Vector3 camera_position;

struct w2s_result {
	bool success;
	Vector2 screen;
};

bool w2s( const Vector3& world, Vector2& screen ) {
	float w = Vector3::dot( Vector3( view_matrix[ 3 ], view_matrix[ 7 ], view_matrix[ 11 ] ), world ) + view_matrix[ 15 ];
	if ( w < 0.098f )
		return false;

	screen = Vector2(
		( 2560.f * 0.5f ) * ( 1.f + ( Vector3::dot( Vector3( view_matrix[ 0 ], view_matrix[ 4 ], view_matrix[ 8 ] ), world ) + view_matrix[ 12 ] ) / w ),
		( 1440.f * 0.5f ) * ( 1.f - ( Vector3::dot( Vector3( view_matrix[ 1 ], view_matrix[ 5 ], view_matrix[ 9 ] ), world ) + view_matrix[ 13 ] ) / w )
	) + Vector2( 0.f, 0.f );

	return true;
}

struct Bounds {
	float left = FLT_MAX;
	float right = FLT_MIN;
	float top = FLT_MAX;
	float bottom = FLT_MIN;
};

bool get_player_bounds( Bounds& bounds, const w2s_result* w2s, size_t count, float distance ) {
	for ( size_t i = 0; i < count; i++ ) {
		if ( !w2s[ i ].success )
			continue;

		const Vector2& position = w2s[ i ].screen;

		if ( position.x < bounds.left )
			bounds.left = position.x;

		if ( position.x > bounds.right )
			bounds.right = position.x;

		if ( position.y < bounds.top )
			bounds.top = position.y;

		if ( position.y > bounds.bottom )
			bounds.bottom = position.y;
	}

	if ( bounds.left == FLT_MAX )
		return false;

	if ( bounds.right == FLT_MIN )
		return false;

	if ( bounds.top == FLT_MAX )
		return false;

	if ( bounds.bottom == FLT_MIN )
		return false;

	float padding = ( 1.f / distance ) * 75.f;

	bounds.left = floorf( bounds.left - max( padding, 2.f ) );
	bounds.right = floorf( bounds.right + max( padding, 4.f ) );
	bounds.top = floorf( bounds.top - max( padding, 2.f ) );
	bounds.bottom = floorf( bounds.bottom + max( padding, 4.f ) );

	if ( bounds.top < 0.f && ( bounds.bottom <= max( padding, 4.f ) || bounds.bottom > 1440.f ) )
		return false;

	if ( bounds.left < 0.f && bounds.right <= max( padding, 4.f ) )
		return false;

	return true;
}

int bone_connections[][ 2 ] = {
	{ 1, 0 }, { 0, 3 }, { 3, 2 },
	{ 3, 4 }, { 4, 6 }, { 6, 8 },
	{ 8, 10 }, { 2, 12 }, { 12, 14 },
	{ 14, 16 }, { 3, 5 }, { 5, 7 },
	{ 7, 9 }, { 9, 11 }, { 2, 13 },
	{ 13, 15 }, { 15, 17 }
};

// Actually draws both players and scientists
void draw_players( const entity_vector<rust::base_player*, cached_player>& players ) {
	for ( const auto& [ player, cached_player ] : players ) {
		const auto& bone_data = cached_player.bone_data;

		float distance = Vector3::distance( camera_position, bone_data.positions[ 17 ] );

		w2s_result w2s_results[ _countof( bone_data.positions ) ];

		for ( size_t i = 0; i < _countof( bone_data.positions ); i++ ) {
			w2s_results[ i ].success = w2s( bone_data.positions[ i ], w2s_results[ i ].screen );
		}

		// Preserve actual head result
		w2s_result head_w2s = w2s_results[ 1 ];

		// Get the head result for bounds, where we add a vertical offset so that the bounds are above the players head
		w2s_results[ 1 ].success = w2s( bone_data.positions[ 1 ] + Vector3( 0.f, 0.105f, 0.f ), w2s_results[ 1 ].screen );

		// Implicit ctor called on bounds
		Bounds bounds;
		if ( !get_player_bounds( bounds, w2s_results, _countof( bone_data.positions ), distance ) )
			continue;
		
		// Restore actual head result
		w2s_results[ 1 ] = head_w2s;

		float half = ( bounds.right - bounds.left ) / 2.f;

		// Bounding box
		{
			renderer.draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 3.f, COL32( 0, 0, 0, 130 ) );
			renderer.draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 1.f, COL32( 125, 195, 255, 255 ) );
		}

		// Skeleton
		{
			for ( size_t j = 0; j < _countof( bone_connections ); j++ ) {
				const w2s_result& a_w2s = w2s_results[ bone_connections[ j ][ 0 ] ];
				const w2s_result& b_w2s = w2s_results[ bone_connections[ j ][ 1 ] ];
				if ( !a_w2s.success || !b_w2s.success )
					continue;

				const Vector2& a_pos = a_w2s.screen;
				const Vector2& b_pos = b_w2s.screen;

				renderer.draw_line( a_pos.x, a_pos.y, b_pos.x, b_pos.y, 1.f, COL32( 125, 195, 255, 255 ) );
			}
		}

		// Name
		{
			renderer.draw_text( bounds.left + half, bounds.top - 14.f, Fonts::Verdana, TextFlags::Centered | TextFlags::DropShadow, COL32( 125, 195, 255, 220 ), cached_player.name );
		}

		float offset = 0.f;

		// Held item
		{
			if ( cached_player.active_item != -1 ) {
				renderer.draw_text( bounds.left + half, bounds.bottom + 1.f, Fonts::SmallFonts, TextFlags::Centered, COL32( 125, 195, 255, 220 ), cached_player.belt_items[ cached_player.active_item ].name );
				offset += 8.f + 1.f;
			}
		}

		// Distance
		{
			char buffer[ 16 ] = {};
			snprintf( buffer, sizeof( buffer ), "%dM", ( int )distance );
			renderer.draw_text( bounds.left + half, bounds.bottom + 1.f + offset, Fonts::SmallFonts, TextFlags::Centered, COL32( 125, 195, 255, 220 ), buffer );
		}
	}
}

void draw_esp() {
	auto static_fields = rust::main_camera::s_static_fields;
	if ( !is_valid_ptr( static_fields ) )
		return;

	unity::camera* main_camera = static_fields->main_camera;
	if ( !is_valid_ptr( main_camera ) )
		return;

	auto main_camera_internal = ( unity::camera::internal* )main_camera->cached_ptr;
	if ( !is_valid_ptr( main_camera_internal ) )
		return;

	view_matrix = main_camera_internal->m_CullingMatrix;
	camera_position = main_camera_internal->m_LastPosition;

	util::scoped_spinlock lock( &entity_manager::cache_lock );

	entity_collection entities = entity_manager::get_entities();

	for ( const auto& [ entity, cached_entity ] : entities.resources ) {
		Vector2 screen;
		if ( !w2s( cached_entity.m_position, screen ) )
			continue;

		float distance = Vector3::distance( camera_position, cached_entity.m_position );

		char buffer[ 16 ] = {};
		snprintf( buffer, sizeof( buffer ), "%dM\n", static_cast< int >( distance ) );

		renderer.draw_text( screen.x, screen.y, Fonts::SmallFonts, TextFlags::Centered, cached_entity.m_visual->m_color, cached_entity.m_visual->m_display_name );
		renderer.draw_text( screen.x, screen.y + 8.f, Fonts::SmallFonts, TextFlags::Centered, IM_COL32_WHITE, buffer );
	}

	draw_players( entities.players );
}

#include "cheat/glow.h"

void on_render( IDXGISwapChain* swap_chain ) {
	if ( !renderer_init ) {
		if ( !( renderer_init = renderer.init( swap_chain ) ) ) {
			return;
		}
	}

	renderer.begin_frame();

	renderer.draw_text( 10.f, 10.f, Fonts::Verdana, TextFlags::DropShadow, COL32( 255, 255, 255, 255 ), "sentian.gg" );

	draw_esp();

	renderer.end_frame();
}