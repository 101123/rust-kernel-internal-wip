#include "dx.h"
#include "um.h"

HRESULT IUnknown::QueryInterface( REFIID riid, void** ppvObject ) {
    HRESULT( *query_interface )( IUnknown*, IID*, void** ) =
        ( decltype( query_interface ) )( ( ( ( *( void*** )( this ) )[ 0 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    IID* guid = caller.push<IID>( riid );
    void** object = caller.push<void*>();
    HRESULT result = caller( query_interface, this, guid, object );

    *ppvObject = *object;

    return result;
}

ULONG IUnknown::AddRef() {
    ULONG( *add_ref )( IUnknown* ) =
        ( decltype( add_ref ) )( ( ( ( *( void*** )( this ) )[ 1 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    return caller( add_ref, this );
}

ULONG IUnknown::Release() {
    ULONG( *release )( IUnknown* ) =
        ( decltype( release ) )( ( ( ( *( void*** )( this ) )[ 2 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    return caller( release, this );
}

HRESULT IDXGIObject::GetParent( REFIID riid, void** ppParent ) {
    HRESULT( *get_parent )( IUnknown*, IID*, void** ) =
        ( decltype( get_parent ) )( ( ( ( *( void*** )( this ) )[ 6 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    IID* guid = caller.push<IID>( riid );
    void** parent = caller.push<void*>();
    HRESULT result = caller( get_parent, this, guid, parent );

    *ppParent = *parent;

    return result;
}

HRESULT IDXGIDeviceSubObject::GetDevice( REFIID riid, void** ppDevice ) {
    HRESULT( *get_device )( IDXGIDeviceSubObject*, IID*, void** ) =
        ( decltype( get_device ) )( ( ( ( *( void*** )( this ) )[ 7 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    IID* guid = caller.push<IID>( riid );
    void** device = caller.push<void*>();
    HRESULT result = caller( get_device, this, guid, device );

    *ppDevice = *device;

    return result;
}

HRESULT IDXGISwapChain::GetBuffer( UINT Buffer, REFIID riid, void** ppSurface ) {
    HRESULT( *get_buffer )( IDXGISwapChain*, UINT, IID*, void** ) =
        ( decltype( get_buffer ) )( ( ( ( *( void*** )( this ) )[ 9 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    IID* guid = caller.push<IID>( riid );
    void** surface = caller.push<void*>();
    HRESULT result = caller( get_buffer, this, Buffer, guid, surface );

    *ppSurface = *surface;

    return result;
}

void ID3D11DeviceContext::VSSetConstantBuffers( UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppConstantBuffers ) {
    void( *vs_set_constant_buffers )( ID3D11DeviceContext*, UINT, UINT, ID3D11Buffer* const* ) =
        ( decltype( vs_set_constant_buffers ) )( ( ( ( *( void*** )( this ) )[ 7 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11Buffer* const* constant_buffers = ppConstantBuffers ? caller.push_array( ppConstantBuffers, NumBuffers ) : nullptr;

    caller( vs_set_constant_buffers, this, StartSlot, NumBuffers, constant_buffers );
}

// 8
void ID3D11DeviceContext::PSSetShaderResources( UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView* const* ppShaderResourceViews ) {
    void( *ps_set_shader_resources )( ID3D11DeviceContext*, UINT, UINT, ID3D11ShaderResourceView* const* ) =
        ( decltype( ps_set_shader_resources ) )( ( ( ( *( void*** )( this ) )[ 8 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11ShaderResourceView* const* shader_resource_views = ppShaderResourceViews ? caller.push_array( ppShaderResourceViews, NumViews ) : nullptr;

    caller( ps_set_shader_resources, this, StartSlot, NumViews, shader_resource_views );
}

// 9
void ID3D11DeviceContext::PSSetShader( ID3D11PixelShader* pPixelShader, ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances ) {
    void( *ps_set_shader )( ID3D11DeviceContext*, ID3D11PixelShader*, ID3D11ClassInstance* const*, UINT ) =
        ( decltype( ps_set_shader ) )( ( ( ( *( void*** )( this ) )[ 9 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11ClassInstance* const* class_instances = ppClassInstances ? caller.push_array( ppClassInstances, NumClassInstances ) : nullptr;

    caller( ps_set_shader, this, pPixelShader, class_instances, NumClassInstances );
}

// 10
void ID3D11DeviceContext::PSSetSamplers( UINT StartSlot, UINT NumSamplers, ID3D11SamplerState* const* ppSamplers ) {
    void( *ps_set_samplers )( ID3D11DeviceContext*, UINT, UINT, ID3D11SamplerState* const* ) =
        ( decltype( ps_set_samplers ) )( ( ( ( *( void*** )( this ) )[ 10 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11SamplerState* const* samplers = ppSamplers ? caller.push_array( ppSamplers, NumSamplers ) : nullptr;

    caller( ps_set_samplers, this, StartSlot, NumSamplers, samplers );
}

// 11
void ID3D11DeviceContext::VSSetShader( ID3D11VertexShader* pVertexShader, ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances ) {
    void( *vs_set_shader )( ID3D11DeviceContext*, ID3D11VertexShader*, ID3D11ClassInstance* const*, UINT ) =
        ( decltype( vs_set_shader ) )( ( ( ( *( void*** )( this ) )[ 11 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11ClassInstance* const* class_instances = ppClassInstances ? caller.push_array( ppClassInstances, NumClassInstances ) : nullptr;

    caller( vs_set_shader, this, pVertexShader, class_instances, NumClassInstances );
}

// 12
void ID3D11DeviceContext::DrawIndexed( UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation ) {
    void( *draw_indexed )( ID3D11DeviceContext*, UINT, UINT, INT ) =
        ( decltype( draw_indexed ) )( ( ( ( *( void*** )( this ) )[ 12 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    caller( draw_indexed, this, IndexCount, StartIndexLocation, BaseVertexLocation );
}

HRESULT ID3D11DeviceContext::Map( ID3D11Resource* pResource, UINT Subresource, D3D11_MAP MapType, UINT MapFlags, D3D11_MAPPED_SUBRESOURCE* pMappedResource ) {
    HRESULT( *map )( ID3D11DeviceContext*, ID3D11Resource*, UINT, D3D11_MAP, UINT, D3D11_MAPPED_SUBRESOURCE* ) =
        ( decltype( map ) )( ( ( ( *( void*** )( this ) )[ 14 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_MAPPED_SUBRESOURCE* resource = pMappedResource ? caller.push<D3D11_MAPPED_SUBRESOURCE>() : nullptr;
    HRESULT result = caller( map, this, pResource, Subresource, MapType, MapFlags, resource );

    if ( pMappedResource ) {
        *pMappedResource = *resource;
    }

    return result;
}

void ID3D11DeviceContext::Unmap( ID3D11Resource* pResource, UINT Subresource ) {
    void( *unmap )( ID3D11DeviceContext*, ID3D11Resource*, UINT ) =
        ( decltype( unmap ) )( ( ( ( *( void*** )( this ) )[ 15 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    caller( unmap, this, pResource, Subresource );
}

// 17
void ID3D11DeviceContext::IASetInputLayout( ID3D11InputLayout* pInputLayout ) {
    void( *ia_set_input_layout )( ID3D11DeviceContext*, ID3D11InputLayout* ) =
        ( decltype( ia_set_input_layout ) )( ( ( ( *( void*** )( this ) )[ 17 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    caller( ia_set_input_layout, this, pInputLayout );
}

// 18
void ID3D11DeviceContext::IASetVertexBuffers( UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppVertexBuffers, const UINT* pStrides, const UINT* pOffsets ) {
    void( *ia_set_vertex_buffers )( ID3D11DeviceContext*, UINT, UINT, ID3D11Buffer* const*, const UINT*, const UINT* ) =
        ( decltype( ia_set_vertex_buffers ) )( ( ( ( *( void*** )( this ) )[ 18 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11Buffer* const* vertex_buffers = ppVertexBuffers ? caller.push_array( ppVertexBuffers, NumBuffers ) : nullptr;
    const UINT* strides = pStrides ? caller.push_array( pStrides, NumBuffers ) : nullptr;
    const UINT* offsets = pOffsets ? caller.push_array( pOffsets, NumBuffers ) : nullptr;

    caller( ia_set_vertex_buffers, this, StartSlot, NumBuffers, vertex_buffers, strides, offsets );
}

// 19
void ID3D11DeviceContext::IASetIndexBuffer( ID3D11Buffer* pIndexBuffer, DXGI_FORMAT Format, UINT Offset ) {
    void( *ia_set_index_buffer )( ID3D11DeviceContext*, ID3D11Buffer*, DXGI_FORMAT, UINT ) =
        ( decltype( ia_set_index_buffer ) )( ( ( ( *( void*** )( this ) )[ 19 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    caller( ia_set_index_buffer, this, pIndexBuffer, Format, Offset );
}

// 23
void ID3D11DeviceContext::GSSetShader( ID3D11GeometryShader* pShader, ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances ) {
    void( *gs_set_shader )( ID3D11DeviceContext*, ID3D11GeometryShader*, ID3D11ClassInstance* const*, UINT ) =
        ( decltype( gs_set_shader ) )( ( ( ( *( void*** )( this ) )[ 23 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11ClassInstance* const* class_instances = ppClassInstances ? caller.push_array( ppClassInstances, NumClassInstances ) : nullptr;

    caller( gs_set_shader, this, pShader, class_instances, NumClassInstances );
}

// 24
void ID3D11DeviceContext::IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY Topology ) {
    void( *ia_set_primitive_topology )( ID3D11DeviceContext*, D3D11_PRIMITIVE_TOPOLOGY ) =
        ( decltype( ia_set_primitive_topology ) )( ( ( ( *( void*** )( this ) )[ 24 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    caller( ia_set_primitive_topology, this, Topology );
}

void ID3D11DeviceContext::OMSetRenderTargets( UINT NumViews, ID3D11RenderTargetView* const* ppRenderTargetViews, ID3D11DepthStencilView* pDepthStencilView ) {
    void( *om_set_render_targets )( ID3D11DeviceContext*, UINT, ID3D11RenderTargetView* const*, ID3D11DepthStencilView* ) =
        ( decltype( om_set_render_targets ) )( ( ( ( *( void*** )( this ) )[ 33 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11RenderTargetView* const* render_target_views = ppRenderTargetViews ? caller.push_array( ppRenderTargetViews, NumViews ) : nullptr;

    caller( om_set_render_targets, this, NumViews, render_target_views, pDepthStencilView );
}

void ID3D11DeviceContext::OMSetBlendState( ID3D11BlendState* pBlendState, const FLOAT BlendFactor[ 4 ], UINT SampleMask ) {
    void( *om_set_blend_state )( ID3D11DeviceContext*, ID3D11BlendState*, const FLOAT[ 4 ], UINT ) =
        ( decltype( om_set_blend_state ) )( ( ( ( *( void*** )( this ) )[ 35 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    const FLOAT* blend_factor = BlendFactor ? caller.push_array( BlendFactor, 4 ) : nullptr;

    caller( om_set_blend_state, this, pBlendState, blend_factor, SampleMask );
}

// 36
void ID3D11DeviceContext::OMSetDepthStencilState( ID3D11DepthStencilState* pDepthStencilState, UINT StencilRef ) {
    void( *om_set_depth_stencil_state )( ID3D11DeviceContext*, ID3D11DepthStencilState*, UINT ) =
        ( decltype( om_set_depth_stencil_state ) )( ( ( ( *( void*** )( this ) )[ 36 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    caller( om_set_depth_stencil_state, this, pDepthStencilState, StencilRef );
}

// 43
void ID3D11DeviceContext::RSSetState( ID3D11RasterizerState* pRasterizerState ) {
    void( *rs_set_state )( ID3D11DeviceContext*, ID3D11RasterizerState* ) =
        ( decltype( rs_set_state ) )( ( ( ( *( void*** )( this ) )[ 43 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    caller( rs_set_state, this, pRasterizerState );
}

void ID3D11DeviceContext::RSSetViewports( UINT NumViewports, const D3D11_VIEWPORT* pViewports ) {
    void( *rs_set_viewports )( ID3D11DeviceContext*, UINT, const D3D11_VIEWPORT* ) =
        ( decltype( rs_set_viewports ) )( ( ( ( *( void*** )( this ) )[ 44 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    const D3D11_VIEWPORT* viewports = pViewports ? caller.push_array( pViewports, NumViewports ) : nullptr;

    caller( rs_set_viewports, this, NumViewports, viewports );
}

// 45
void ID3D11DeviceContext::RSSetScissorRects( UINT NumRects, const D3D11_RECT* pRects ) {
    void( *rs_set_scissor_rects )( ID3D11DeviceContext*, UINT, const D3D11_RECT* ) =
        ( decltype( rs_set_scissor_rects ) )( ( ( ( *( void*** )( this ) )[ 45 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    const D3D11_RECT* rects = pRects ? caller.push_array( pRects, NumRects ) : nullptr;

    caller( rs_set_scissor_rects, this, NumRects, rects );
}

// 48 - pSrcData must be user accessible
void ID3D11DeviceContext::UpdateSubresource( ID3D11Resource* pDstResource, UINT DstSubresource, const D3D11_BOX* pDstBox, const void* pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch ) {
    void( *update_subresource )( ID3D11DeviceContext*, ID3D11Resource*, UINT, const D3D11_BOX*, const void*, UINT, UINT ) =
        ( decltype( update_subresource ) )( ( ( ( *( void*** )( this ) )[ 48 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    const D3D11_BOX* dst_box = pDstBox ? caller.push<D3D11_BOX>( *pDstBox ) : nullptr;

    caller( update_subresource, this, pDstResource, DstSubresource, dst_box, pSrcData, SrcRowPitch, SrcDepthPitch );
}

// 50
void ID3D11DeviceContext::ClearRenderTargetView( ID3D11RenderTargetView* pRenderTargetView, const FLOAT ColorRGBA[ 4 ] ) {
    void( *clear_render_target_view )( ID3D11DeviceContext*, ID3D11RenderTargetView*, const FLOAT[ 4 ] ) =
        ( decltype( clear_render_target_view ) )( ( ( ( *( void*** )( this ) )[ 50 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    const FLOAT* color_rgba = caller.push_array( ColorRGBA, 4 );

    caller( clear_render_target_view, this, pRenderTargetView, color_rgba );
}

// 60
void ID3D11DeviceContext::HSSetShader( ID3D11HullShader* pHullShader, ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances ) {
    void( *hs_set_shader )( ID3D11DeviceContext*, ID3D11HullShader*, ID3D11ClassInstance* const*, UINT ) =
        ( decltype( hs_set_shader ) )( ( ( ( *( void*** )( this ) )[ 60 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11ClassInstance* const* class_instances = ppClassInstances ? caller.push_array( ppClassInstances, NumClassInstances ) : nullptr;

    caller( hs_set_shader, this, pHullShader, class_instances, NumClassInstances );
}

// 64
void ID3D11DeviceContext::DSSetShader( ID3D11DomainShader* pDomainShader, ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances ) {
    void( *ds_set_shader )( ID3D11DeviceContext*, ID3D11DomainShader*, ID3D11ClassInstance* const*, UINT ) =
        ( decltype( ds_set_shader ) )( ( ( ( *( void*** )( this ) )[ 64 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11ClassInstance* const* class_instances = ppClassInstances ? caller.push_array( ppClassInstances, NumClassInstances ) : nullptr;

    caller( ds_set_shader, this, pDomainShader, class_instances, NumClassInstances );
}

// 69
void ID3D11DeviceContext::CSSetShader( ID3D11ComputeShader* pComputeShader, ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances ) {
    void( *cs_set_shader )( ID3D11DeviceContext*, ID3D11ComputeShader*, ID3D11ClassInstance* const*, UINT ) =
        ( decltype( cs_set_shader ) )( ( ( ( *( void*** )( this ) )[ 69 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11ClassInstance* const* class_instances = ppClassInstances ? caller.push_array( ppClassInstances, NumClassInstances ) : nullptr;

    caller( cs_set_shader, this, pComputeShader, class_instances, NumClassInstances );
}

#define alloc_array push_array

// 72
void ID3D11DeviceContext::VSGetConstantBuffers( UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppConstantBuffers ) {
    void( *vs_get_constant_buffers )( ID3D11DeviceContext*, UINT, UINT, ID3D11Buffer** ) =
        ( decltype( vs_get_constant_buffers ) )( ( ( ( *( void*** )( this ) )[ 72 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11Buffer** constant_buffers = ppConstantBuffers ? caller.alloc_array( ppConstantBuffers, NumBuffers ) : nullptr;

    caller( vs_get_constant_buffers, this, StartSlot, NumBuffers, constant_buffers );

    if ( ppConstantBuffers ) {
        memcpy( ppConstantBuffers, constant_buffers, NumBuffers * sizeof( ID3D11Buffer* ) );
    }
}

// 73
void ID3D11DeviceContext::PSGetShaderResources( UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView** ppShaderResourceViews ) {
    void( *ps_get_shader_resources )( ID3D11DeviceContext*, UINT, UINT, ID3D11ShaderResourceView** ) =
        ( decltype( ps_get_shader_resources ) )( ( ( ( *( void*** )( this ) )[ 73 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11ShaderResourceView** shader_resource_views = ppShaderResourceViews ? caller.alloc_array( ppShaderResourceViews, NumViews ) : nullptr;

    caller( ps_get_shader_resources, this, StartSlot, NumViews, shader_resource_views );

    if ( ppShaderResourceViews ) {
        memcpy( ppShaderResourceViews, shader_resource_views, NumViews * sizeof( ID3D11ShaderResourceView* ) );
    }
}

// 74
void ID3D11DeviceContext::PSGetShader( ID3D11PixelShader** ppPixelShader, ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances ) {
    void( *ps_get_shader )( ID3D11DeviceContext*, ID3D11PixelShader**, ID3D11ClassInstance**, UINT* ) =
        ( decltype( ps_get_shader ) )( ( ( ( *( void*** )( this ) )[ 74 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    uint32_t count = ppClassInstances ? *pNumClassInstances : 0u;

    ID3D11PixelShader** pixel_shader = caller.push<ID3D11PixelShader*>();
    ID3D11ClassInstance** class_instances = ppClassInstances ? caller.alloc_array( ppClassInstances, count ) : nullptr;
    uint32_t* num_class_instances = pNumClassInstances ? caller.push<uint32_t>( *pNumClassInstances ) : nullptr;

    caller( ps_get_shader, this, pixel_shader, class_instances, num_class_instances );

    *ppPixelShader = *pixel_shader;

    if ( ppClassInstances ) {
        memcpy( ppClassInstances, class_instances, count * sizeof( ID3D11ClassInstance* ) );
    }

    if ( pNumClassInstances ) {
        *pNumClassInstances = *num_class_instances;
    }
}

// 75
void ID3D11DeviceContext::PSGetSamplers( UINT StartSlot, UINT NumSamplers, ID3D11SamplerState** ppSamplers ) {
    void( *ps_get_samplers )( ID3D11DeviceContext*, UINT, UINT, ID3D11SamplerState** ) =
        ( decltype( ps_get_samplers ) )( ( ( ( *( void*** )( this ) )[ 75 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11SamplerState** samplers = ppSamplers ? caller.alloc_array( ppSamplers, NumSamplers ) : nullptr;

    caller( ps_get_samplers, this, StartSlot, NumSamplers, samplers );

    if ( ppSamplers ) {
        memcpy( ppSamplers, samplers, NumSamplers * sizeof( ID3D11SamplerState* ) );
    }
}

// 76
void ID3D11DeviceContext::VSGetShader( ID3D11VertexShader** ppVertexShader, ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances ) {
    void( *vs_get_shader )( ID3D11DeviceContext*, ID3D11VertexShader**, ID3D11ClassInstance**, UINT* ) =
        ( decltype( vs_get_shader ) )( ( ( ( *( void*** )( this ) )[ 76 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    uint32_t count = ppClassInstances ? *pNumClassInstances : 0u;

    ID3D11VertexShader** vertex_shader = caller.push<ID3D11VertexShader*>();
    ID3D11ClassInstance** class_instances = ppClassInstances ? caller.alloc_array( ppClassInstances, count ) : nullptr;
    uint32_t* num_class_instances = pNumClassInstances ? caller.push<uint32_t>( *pNumClassInstances ) : nullptr;

    caller( vs_get_shader, this, vertex_shader, class_instances, num_class_instances );

    *ppVertexShader = *vertex_shader;

    if ( ppClassInstances ) {
        memcpy( ppClassInstances, class_instances, count * sizeof( ID3D11ClassInstance* ) );
    }

    if ( pNumClassInstances ) {
        *pNumClassInstances = *num_class_instances;
    }
}

// 78
void ID3D11DeviceContext::IAGetInputLayout( ID3D11InputLayout** ppInputLayout ) {
    void( *ia_get_input_layout )( ID3D11DeviceContext*, ID3D11InputLayout** ) =
        ( decltype( ia_get_input_layout ) )( ( ( ( *( void*** )( this ) )[ 78 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11InputLayout** input_layout = caller.push<ID3D11InputLayout*>();

    caller( ia_get_input_layout, this, input_layout );

    *ppInputLayout = *input_layout;
}

// 79
void ID3D11DeviceContext::IAGetVertexBuffers( UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppVertexBuffers, UINT* pStrides, UINT* pOffsets ) {
    void( *ia_get_vertex_buffers )( ID3D11DeviceContext*, UINT, UINT, ID3D11Buffer**, UINT*, UINT* ) =
        ( decltype( ia_get_vertex_buffers ) )( ( ( ( *( void*** )( this ) )[ 79 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11Buffer** vertex_buffers = ppVertexBuffers ? caller.alloc_array( ppVertexBuffers, NumBuffers ) : nullptr;
    UINT* strides = pStrides ? caller.alloc_array( pStrides, NumBuffers ) : nullptr;
    UINT* offsets = pOffsets ? caller.alloc_array( pOffsets, NumBuffers ) : nullptr;

    caller( ia_get_vertex_buffers, this, StartSlot, NumBuffers, vertex_buffers, strides, offsets );

    if ( ppVertexBuffers ) {
        memcpy( ppVertexBuffers, vertex_buffers, NumBuffers * sizeof( ID3D11Buffer* ) );
    }

    if ( pStrides ) {
        memcpy( pStrides, strides, NumBuffers * sizeof( UINT ) );
    }

    if ( pOffsets ) {
        memcpy( pOffsets, offsets, NumBuffers * sizeof( UINT ) );
    }
}

// 80
void ID3D11DeviceContext::IAGetIndexBuffer( ID3D11Buffer** pIndexBuffer, DXGI_FORMAT* Format, UINT* Offset ) {
    void( *ia_get_index_buffer )( ID3D11DeviceContext*, ID3D11Buffer**, DXGI_FORMAT*, UINT* ) =
        ( decltype( ia_get_index_buffer ) )( ( ( ( *( void*** )( this ) )[ 80 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11Buffer** index_buffer = pIndexBuffer ? caller.push<ID3D11Buffer*>() : nullptr;
    DXGI_FORMAT* format = Format ? caller.push<DXGI_FORMAT>() : nullptr;
    UINT* offset = Offset ? caller.push<UINT>() : nullptr;

    caller( ia_get_index_buffer, this, index_buffer, format, offset );

    if ( pIndexBuffer ) {
        *pIndexBuffer = *index_buffer;
    }

    if ( Format ) {
        *Format = *format;
    }

    if ( Offset ) {
        *Offset = *offset;
    }
}

// 82
void ID3D11DeviceContext::GSGetShader( ID3D11GeometryShader** ppGeometryShader, ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances ) {
    void( *gs_get_shader )( ID3D11DeviceContext*, ID3D11GeometryShader**, ID3D11ClassInstance**, UINT* ) =
        ( decltype( gs_get_shader ) )( ( ( ( *( void*** )( this ) )[ 82 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    uint32_t count = pNumClassInstances ? *pNumClassInstances : 0u;

    ID3D11GeometryShader** geometry_shader = caller.push<ID3D11GeometryShader*>();
    ID3D11ClassInstance** class_instances = ppClassInstances ? caller.alloc_array( ppClassInstances, count ) : nullptr;
    uint32_t* num_class_instances = pNumClassInstances ? caller.push<uint32_t>( *pNumClassInstances ) : nullptr;

    caller( gs_get_shader, this, geometry_shader, class_instances, num_class_instances );

    *ppGeometryShader = *geometry_shader;

    if ( ppClassInstances ) {
        memcpy( ppClassInstances, class_instances, count * sizeof( ID3D11ClassInstance* ) );
    }

    if ( pNumClassInstances ) {
        *pNumClassInstances = *num_class_instances;
    }
}

// 83
void ID3D11DeviceContext::IAGetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY* pTopology ) {
    void( *ia_get_primitive_topology )( ID3D11DeviceContext*, D3D11_PRIMITIVE_TOPOLOGY* ) =
        ( decltype( ia_get_primitive_topology ) )( ( ( ( *( void*** )( this ) )[ 83 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_PRIMITIVE_TOPOLOGY* topology = caller.push<D3D11_PRIMITIVE_TOPOLOGY>();

    caller( ia_get_primitive_topology, this, topology );

    *pTopology = *topology;
}

// 91
void ID3D11DeviceContext::OMGetBlendState( ID3D11BlendState** ppBlendState, FLOAT BlendFactor[ 4 ], UINT* pSampleMask ) {
    void( *om_get_blend_state )( ID3D11DeviceContext*, ID3D11BlendState**, FLOAT[ 4 ], UINT* ) =
        ( decltype( om_get_blend_state ) )( ( ( ( *( void*** )( this ) )[ 91 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11BlendState** blend_state = ppBlendState ? caller.push<ID3D11BlendState*>() : nullptr;
    FLOAT* blend_factor = BlendFactor ? caller.alloc_array( BlendFactor, 4 ) : nullptr;
    UINT* sample_mask = pSampleMask ? caller.push<UINT>() : nullptr;

    caller( om_get_blend_state, this, blend_state, blend_factor, sample_mask );

    if ( ppBlendState ) {
        *ppBlendState = *blend_state;
    }

    if ( BlendFactor ) {
        memcpy( BlendFactor, blend_factor, sizeof( float ) * 4 );
    }

    if ( pSampleMask ) {
        *pSampleMask = *sample_mask;
    }
}

// 92
void ID3D11DeviceContext::OMGetDepthStencilState( ID3D11DepthStencilState** ppDepthStencilState, UINT* pStencilRef ) {
    void( *om_get_depth_stencil_state )( ID3D11DeviceContext*, ID3D11DepthStencilState**, UINT* ) =
        ( decltype( om_get_depth_stencil_state ) )( ( ( ( *( void*** )( this ) )[ 92 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11DepthStencilState** depth_stencil_state = ppDepthStencilState ? caller.push<ID3D11DepthStencilState*>() : nullptr;
    UINT* stencil_ref = pStencilRef ? caller.push<UINT>() : nullptr;

    caller( om_get_depth_stencil_state, this, depth_stencil_state, stencil_ref );

    if ( ppDepthStencilState ) {
        *ppDepthStencilState = *depth_stencil_state;
    }

    if ( pStencilRef ) {
        *pStencilRef = *stencil_ref;
    }
}

// 94
void ID3D11DeviceContext::RSGetState( ID3D11RasterizerState** ppRasterizerState ) {
    void( *rs_get_state )( ID3D11DeviceContext*, ID3D11RasterizerState** ) =
        ( decltype( rs_get_state ) )( ( ( ( *( void*** )( this ) )[ 94 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11RasterizerState** rasterizer_state = caller.push<ID3D11RasterizerState*>();

    caller( rs_get_state, this, rasterizer_state );

    *ppRasterizerState = *rasterizer_state;
}

// 95
void ID3D11DeviceContext::RSGetViewports( UINT* pNumViewports, D3D11_VIEWPORT* pViewports ) {
    void( *rs_get_viewports )( ID3D11DeviceContext*, UINT*, D3D11_VIEWPORT* ) =
        ( decltype( rs_get_viewports ) )( ( ( ( *( void*** )( this ) )[ 95 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    UINT* num_viewports = caller.push<UINT>( *pNumViewports );
    D3D11_VIEWPORT* viewports = pViewports ? caller.alloc_array( pViewports, *pNumViewports ) : nullptr;

    caller( rs_get_viewports, this, num_viewports, viewports );

    *pNumViewports = *num_viewports;

    if ( pViewports ) {
        memcpy( pViewports, viewports, *pNumViewports * sizeof( D3D11_VIEWPORT ) );
    }
}

// 96
void ID3D11DeviceContext::RSGetScissorRects( UINT* pNumRects, D3D11_RECT* pRects ) {
    void( *rs_get_scissor_rects )( ID3D11DeviceContext*, UINT*, D3D11_RECT* ) =
        ( decltype( rs_get_scissor_rects ) )( ( ( ( *( void*** )( this ) )[ 96 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    UINT* num_rects = caller.push<UINT>( *pNumRects );
    D3D11_RECT* rects = pRects ? caller.alloc_array( pRects, *pNumRects ) : nullptr;

    caller( rs_get_scissor_rects, this, num_rects, rects );

    *pNumRects = *num_rects;

    if ( pRects ) {
        memcpy( pRects, rects, *pNumRects * sizeof( D3D11_RECT ) );
    }
}

HRESULT ID3D11Device::CreateBuffer( const D3D11_BUFFER_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Buffer** ppBuffer ) {
    HRESULT( *create_buffer )( ID3D11Device*, const D3D11_BUFFER_DESC*, const D3D11_SUBRESOURCE_DATA*, ID3D11Buffer** ) =
        ( decltype( create_buffer ) )( ( ( ( *( void*** )( this ) )[ 3 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_BUFFER_DESC* desc = caller.push<D3D11_BUFFER_DESC>( *pDesc );
    ID3D11Buffer** buffer = ppBuffer ? caller.push<ID3D11Buffer*>() : nullptr;
    HRESULT result = caller( create_buffer, this, desc, pInitialData, buffer );

    if ( ppBuffer ) {
        *ppBuffer = *buffer;
    }

    return result;
}

HRESULT ID3D11Device::CreateTexture2D( const D3D11_TEXTURE2D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture2D** ppTexture2D ) {
    HRESULT( *create_texture_2d )( ID3D11Device*, const D3D11_TEXTURE2D_DESC*, const D3D11_SUBRESOURCE_DATA*, ID3D11Texture2D** ) =
        ( decltype( create_texture_2d ) )( ( ( ( *( void*** )( this ) )[ 5 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_TEXTURE2D_DESC* desc = caller.push<D3D11_TEXTURE2D_DESC>( *pDesc );
    D3D11_SUBRESOURCE_DATA* initial_data = pInitialData ? caller.push<D3D11_SUBRESOURCE_DATA>( *pInitialData ) : nullptr;
    ID3D11Texture2D** texture2d = ppTexture2D ? caller.push<ID3D11Texture2D*>() : nullptr;

    HRESULT result = caller( create_texture_2d, this, desc, initial_data, texture2d );

    if ( ppTexture2D ) {
        *ppTexture2D = *texture2d;
    }

    return result;
}

HRESULT ID3D11Device::CreateShaderResourceView( ID3D11Resource* pResource, const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc, ID3D11ShaderResourceView** ppSRView ) {
    HRESULT( *create_shader_resource_view )( ID3D11Device*, ID3D11Resource*, const D3D11_SHADER_RESOURCE_VIEW_DESC*, ID3D11ShaderResourceView** ) =
        ( decltype( create_shader_resource_view ) )( ( ( ( *( void*** )( this ) )[ 7 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_SHADER_RESOURCE_VIEW_DESC* desc = pDesc ? caller.push<D3D11_SHADER_RESOURCE_VIEW_DESC>( *pDesc ) : nullptr;
    ID3D11ShaderResourceView** sr_view = ppSRView ? caller.push<ID3D11ShaderResourceView*>() : nullptr;
    HRESULT result = caller( create_shader_resource_view, this, pResource, desc, sr_view );

    if ( ppSRView ) {
        *ppSRView = *sr_view;
    }

    return result;
}

HRESULT ID3D11Device::CreateRenderTargetView( ID3D11Resource* pResource, const D3D11_RENDER_TARGET_VIEW_DESC* pDesc, ID3D11RenderTargetView** ppRTView ) {
    HRESULT( *create_render_target_view )( ID3D11Device*, ID3D11Resource*, const D3D11_RENDER_TARGET_VIEW_DESC*, ID3D11RenderTargetView** ) =
        ( decltype( create_render_target_view ) )( ( ( ( *( void*** )( this ) )[ 9 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_RENDER_TARGET_VIEW_DESC* desc = pDesc ? caller.push<D3D11_RENDER_TARGET_VIEW_DESC>( *pDesc ) : nullptr;
    ID3D11RenderTargetView** rt_view = ppRTView ? caller.push<ID3D11RenderTargetView*>() : nullptr;
    HRESULT result = caller( create_render_target_view, this, pResource, desc, rt_view );

    if ( ppRTView ) {
        *ppRTView = *rt_view;
    }

    return result;
}

HRESULT ID3D11Device::CreateInputLayout( D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout** ppInputLayout ) {
    HRESULT( *create_input_layout )( ID3D11Device*, const D3D11_INPUT_ELEMENT_DESC*, UINT, const void*, SIZE_T, ID3D11InputLayout** ) =
        ( decltype( create_input_layout ) )( ( ( ( *( void*** )( this ) )[ 11 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_INPUT_ELEMENT_DESC* input_element_descs =
        ( D3D11_INPUT_ELEMENT_DESC* )caller.alloc( NumElements * sizeof( D3D11_INPUT_ELEMENT_DESC ), alignof( D3D11_INPUT_ELEMENT_DESC ) );

    for ( uint32_t i = 0; i < NumElements; i++ ) {
        D3D11_INPUT_ELEMENT_DESC* dst = &input_element_descs[ i ];
        D3D11_INPUT_ELEMENT_DESC* src = &pInputElementDescs[ i ];

        memcpy( dst, src, sizeof( D3D11_INPUT_ELEMENT_DESC ) );

        // SemanticName is a pointer
        dst->SemanticName = caller.push_string( src->SemanticName );
    }

    void* shader_bytecode = um::malloc( BytecodeLength );
    memcpy( shader_bytecode, pShaderBytecodeWithInputSignature, BytecodeLength );

    ID3D11InputLayout** input_layout = ppInputLayout ? caller.push<ID3D11InputLayout*>() : nullptr;
    HRESULT result = caller( create_input_layout, this, input_element_descs, NumElements, shader_bytecode, BytecodeLength, input_layout );

    um::free( shader_bytecode, BytecodeLength );

    if ( ppInputLayout ) {
        *ppInputLayout = *input_layout;
    }

    return result;
}

HRESULT ID3D11Device::CreateVertexShader( const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11VertexShader** ppVertexShader ) {
    HRESULT( *create_vertex_shader )( ID3D11Device*, const void*, SIZE_T, ID3D11ClassLinkage*, ID3D11VertexShader** ) =
        ( decltype( create_vertex_shader ) )( ( ( ( *( void*** )( this ) )[ 12 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    void* shader_bytecode = um::malloc( BytecodeLength );
    memcpy( shader_bytecode, pShaderBytecode, BytecodeLength );

    ID3D11VertexShader** vertex_shader = ppVertexShader ? caller.push<ID3D11VertexShader*>() : nullptr;
    HRESULT result = caller( create_vertex_shader, this, shader_bytecode, BytecodeLength, pClassLinkage, vertex_shader );

    um::free( shader_bytecode, BytecodeLength );

    if ( ppVertexShader ) {
        *ppVertexShader = *vertex_shader;
    }

    return result;
}

HRESULT ID3D11Device::CreatePixelShader( const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11PixelShader** ppPixelShader ) {
    HRESULT( *create_pixel_shader )( ID3D11Device*, const void*, SIZE_T, ID3D11ClassLinkage*, ID3D11PixelShader** ) =
        ( decltype( create_pixel_shader ) )( ( ( ( *( void*** )( this ) )[ 15 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    void* shader_bytecode = um::malloc( BytecodeLength );
    memcpy( shader_bytecode, pShaderBytecode, BytecodeLength );

    ID3D11PixelShader** pixel_shader = ppPixelShader ? caller.push<ID3D11PixelShader*>() : nullptr;
    HRESULT result = caller( create_pixel_shader, this, shader_bytecode, BytecodeLength, pClassLinkage, pixel_shader );

    um::free( shader_bytecode, BytecodeLength );

    if ( ppPixelShader ) {
        *ppPixelShader = *pixel_shader;
    }

    return result;
}

HRESULT ID3D11Device::CreateBlendState( const D3D11_BLEND_DESC* pBlendStateDesc, ID3D11BlendState** ppBlendState ) {
    HRESULT( *create_blend_state )( ID3D11Device*, const D3D11_BLEND_DESC*, ID3D11BlendState** ) =
        ( decltype( create_blend_state ) )( ( ( ( *( void*** )( this ) )[ 20 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_BLEND_DESC* desc = caller.push<D3D11_BLEND_DESC>( *pBlendStateDesc );
    ID3D11BlendState** blend_state = ppBlendState ? caller.push<ID3D11BlendState*>() : nullptr;
    HRESULT result = caller( create_blend_state, this, desc, blend_state );

    if ( ppBlendState ) {
        *ppBlendState = *blend_state;
    }

    return result;
}

// 21
HRESULT ID3D11Device::CreateDepthStencilState( const D3D11_DEPTH_STENCIL_DESC* pDepthStencilDesc, ID3D11DepthStencilState** ppDepthStencilState ) {
    HRESULT( *create_depth_stencil_state )( ID3D11Device*, const D3D11_DEPTH_STENCIL_DESC*, ID3D11DepthStencilState** ) =
        ( decltype( create_depth_stencil_state ) )( ( ( ( *( void*** )( this ) )[ 21 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_DEPTH_STENCIL_DESC* depth_stencil_desc = caller.push<D3D11_DEPTH_STENCIL_DESC>( *pDepthStencilDesc );
    ID3D11DepthStencilState** depth_stencil_state = ppDepthStencilState ? caller.push<ID3D11DepthStencilState*>() : nullptr;

    HRESULT result = caller( create_depth_stencil_state, this, depth_stencil_desc, depth_stencil_state );

    if ( ppDepthStencilState ) {
        *ppDepthStencilState = *depth_stencil_state;
    }

    return result;
}

// 22
HRESULT ID3D11Device::CreateRasterizerState( const D3D11_RASTERIZER_DESC* pRasterizerDesc, ID3D11RasterizerState** ppRasterizerState ) {
    HRESULT( *create_rasterizer_state )( ID3D11Device*, const D3D11_RASTERIZER_DESC*, ID3D11RasterizerState** ) =
        ( decltype( create_rasterizer_state ) )( ( ( ( *( void*** )( this ) )[ 22 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_RASTERIZER_DESC* rasterizer_desc = caller.push<D3D11_RASTERIZER_DESC>( *pRasterizerDesc );
    ID3D11RasterizerState** rasterizer_state = ppRasterizerState ? caller.push<ID3D11RasterizerState*>() : nullptr;

    HRESULT result = caller( create_rasterizer_state, this, rasterizer_desc, rasterizer_state );

    if ( ppRasterizerState ) {
        *ppRasterizerState = *rasterizer_state;
    }

    return result;
}

HRESULT ID3D11Device::CreateSamplerState( const D3D11_SAMPLER_DESC* pSamplerDesc, ID3D11SamplerState** ppSamplerState ) {
    HRESULT( *create_sampler_state )( ID3D11Device*, const D3D11_SAMPLER_DESC*, ID3D11SamplerState** ) =
        ( decltype( create_sampler_state ) )( ( ( ( *( void*** )( this ) )[ 23 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    D3D11_SAMPLER_DESC* desc = caller.push<D3D11_SAMPLER_DESC>( *pSamplerDesc );
    ID3D11SamplerState** sampler_state = ppSamplerState ? caller.push<ID3D11SamplerState*>() : nullptr;
    HRESULT result = caller( create_sampler_state, this, desc, sampler_state );

    if ( ppSamplerState ) {
        *ppSamplerState = *sampler_state;
    }

    return result;
}

void ID3D11Device::GetImmediateContext( ID3D11DeviceContext** ppImmediateContext ) {
    void( *get_immediate_context )( ID3D11Device*, ID3D11DeviceContext** ) =
        ( decltype( get_immediate_context ) )( ( ( ( *( void*** )( this ) )[ 40 ] ) ) );

    um::caller& caller = um::get_caller_for_thread();

    ID3D11DeviceContext** immediate_context = caller.push<ID3D11DeviceContext*>();
    caller( get_immediate_context, this, immediate_context );

    *ppImmediateContext = *immediate_context;
}