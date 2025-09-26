#pragma once

#include "global.h"
#include "cheat/sdk/offsets.h"
#include "cheat/sdk/field_types.h"
#include "cheat/sdk/il2cpp.h"
#include "um.h"
#include "hexrays.h"

#include "math/vec2.h"
#include "math/vec3.h"
#include "math/mat4x4.h"

namespace sys {
    class string {
    private:
        uint8_t _[ 0x10 ];
    public:
        int length;
        wchar_t buffer[ 128 ];
        
        string( const wchar_t* str ) {
            length = wcslen( str );
            wcscpy( buffer, str );
            buffer[ length ] = '\0';
        }
    };

    template <typename T>
    class array {
    private:
        uint8_t _[ 0x18 ];
    public:
        uint64_t size;
        T buffer[ 0 ];
    };

    template <typename T>
    class list : public il2cpp_object {
    private:
        uint8_t _[ 0x10 ];
    public:
        sys::array<T>* items;
        int size;
    };

    template <typename T>
    class buffer_list {
    public:
        FIELD( int, count, Offsets::System_BufferList::count );
        FIELD( sys::array<T>*, buffer, Offsets::System_BufferList::buffer );
    };

    template <typename K, typename V>
    class dictionary {
    public:
        struct entry {
            int hash_code;
            int next;
            K key;
            V value;
        };

        FIELD( sys::array<entry>*, entries, 0x18 );
        FIELD( int, count, 0x20 );
    };

    template <typename K, typename V>
    class list_dictionary {
    public:
        FIELD( buffer_list<V>*, vals, Offsets::System_ListDictionary::vals );
    };
}

namespace unity_internal {

}

namespace unity {
    class object;
    class game_object;
    class component;
    class transform;
    class texture;
}

namespace unity {
    namespace internals {
        template <typename T>
        struct pptr {
            int32_t instance_id;
        };

        template <typename T>
        struct dynamic_array {
        public:
            T* buffer;
        private:
            uint8_t _[ 0x8 ];
        public:
            uint64_t size;
            uint64_t capacity;
        };

        struct shared_renderer_data {
        private:
            uint8_t _[ 0xE8 ];
            uint32_t __ : 12;
        public:
            uint32_t is_visible : 1;
        };

        class scripting_gc_handle {
        public:
            FIELD( il2cpp_object*, object, 0x10 );
        };

        class object {
        public:
            FIELD( scripting_gc_handle, mono_reference, 0x18 );
        };

        class camera {
        public:
            FIELD( matrix4x4, culling_matrix, 0x30C );
            FIELD( int, culling_mask, 0x43C );
            FIELD( vector3, last_position, 0x454 );
        };

        class shader : public object {
        public:

        };

        class material : public object {
        public:
            
        };

        class renderer {
        public:
            FIELD( shared_renderer_data, renderer_data, 0x40 );
            FIELD( dynamic_array<pptr<material>>, materials, 0x148 );
            FIELD( int, scene_handle, 0x168 );

            bool is_in_scene() {
                return scene_handle != -1;
            }

            bool is_visible_in_scene() {
                // Don't copy the renderer data
                internals::shared_renderer_data* renderer_data = _address_of_renderer_data();

                return renderer_data->is_visible;
            }
        };
    }

    enum key_code {
        backspace = 8, _delete = 127, tab = 9, clear = 12,
        _return = 13, pause = 19, _escape = 27, space = 32,
        keypad0 = 256, keypad1 = 257, keypad2 = 258, keypad3 = 259,
        keypad4 = 260, keypad5 = 261, keypad6 = 262, keypad7 = 263,
        keypad8 = 264, keypad9 = 265, keypad_period = 266, keypad_divide = 267,
        keypad_multiply = 268, keypad_minus = 269, keypad_plus = 270, keypad_enter = 271,
        keypad_equals = 272, up_arrow = 273, down_arrow = 274, right_arrow = 275,
        left_arrow = 276, insert = 277, home = 278, end = 279,
        page_up = 280, page_down = 281, f1 = 282, f2 = 283,
        f3 = 284, f4 = 285, f5 = 286, f6 = 287,
        f7 = 288, f8 = 289, f9 = 290, f10 = 291,
        f11 = 292, f12 = 293, f13 = 294, f14 = 295,
        f15 = 296, alpha_0 = 48, alpha1 = 49, alpha_2 = 50,
        alpha3 = 51, alpha4 = 52, alpha5 = 53, alpha6 = 54,
        alpha7 = 55, alpha8 = 56, alpha9 = 57, exclaim = 33,
        double_quote = 34, hash = 35, dollar = 36, percent = 37,
        ampersand = 38, quote = 39, left_paren = 40, right_paren = 41,
        asterisk = 42, plus = 43, comma = 44, minus = 45,
        period = 46, slash = 47, colon = 58, semicolon = 59,
        less = 60, equals = 61, greater = 62, question = 63,
        at = 64, left_bracket = 91, backslash = 92, right_bracket = 93,
        caret = 94, underscore = 95, back_quote = 96, a = 97,
        b = 98, c = 99, d = 100, e = 101,
        f = 102, g = 103, h = 104, i = 105,
        j = 106, k = 107, l = 108, m = 109,
        n = 110, o = 111, p = 112, q = 113,
        r = 114, s = 115, t = 116, u = 117,
        v = 118, w = 119, x = 120, y = 121,
        z = 122, left_curly_bracket = 123, pipe = 124, right_curly_bracket = 125, tilde = 126,
        numlock = 300, caps_lock = 301, scroll_lock = 302, right_shift = 303,
        left_shift = 304, right_control = 305, left_control = 306, right_alt = 307,
        left_alt = 308, left_command = 310, left_apple = 310, left_windows = 311,
        right_command = 309, right_apple = 309, right_windows = 312, alt_gr = 313,
        help = 315, pr = 316, sys_req = 317, break_ = 318,
        menu = 319, mouse0 = 323, mouse1 = 324, mouse2 = 325,
        mouse3 = 326, mouse4 = 327, mouse5 = 328, mouse6 = 329
    };

    enum hide_flags {
        hide_and_dont_save = 61
    };

    struct color {
        float r, g, b, a;

        color() 
            : r( 1.f ), g( 1.f ), b( 1.f ), a( 1.f ) {};

        color( float _r, float _g, float _b, float _a ) 
            : r( _r ), g( _g ), b( _b ), a( _a ) {};

        color( uint32_t rgba ) : r( ( ( rgba >> 0 ) & 255 ) / 255.f ), g( ( ( rgba >> 8 ) & 255 ) / 255.f ),
            b( ( ( rgba >> 16 ) & 255 ) / 255.f ), a( ( ( rgba >> 24 ) & 255 ) / 255.f ) {}
    };

    struct gradient_color_key {
        color color;
        float time;
    };

    struct gradient_alpha_key {
        float alpha;
        float time;
    };

    struct render_target_identifier {
        static render_target_identifier* ctor( texture* tex ) {
            void( *ctor )( render_target_identifier*, texture* ) = 
                ( decltype( ctor ) )( game_assembly + Offsets::RenderTargetIdentifier::ctor );

            um::caller& caller = um::get_caller_for_thread();

            render_target_identifier* object = ( render_target_identifier* )il2cpp_object_new( render_target_identifier::klass_ );
            caller( ctor, object, tex );

            return object;
        }

        static inline il2cpp_class* klass_;
    };

    class object : public il2cpp_object {
    public:
        FIELD( uintptr_t, cached_ptr, Offsets::Object::m_CachedPtr );

        int32_t get_instance_id() {
            int32_t ( *get_instance_id )( object* ) = ( decltype( get_instance_id ) )( game_assembly + Offsets::Object::GetInstanceID );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_instance_id, this );
        }

        sys::string* get_name() {
            sys::string* ( *get_name )( object* ) = ( decltype( get_name ) )( unity_player + Offsets::Object::GetName );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_name, this );
        }

        void set_hide_flags( int hide_flags ) {
            void ( *set_hide_flags )( object*, int ) = ( decltype( set_hide_flags ) )( unity_player + Offsets::Object::set_hideFlags );

            um::caller& caller = um::get_caller_for_thread();

            return caller( set_hide_flags, this, hide_flags );
        }
    };

    class game_object : public object {
    public:
        template <typename T>
        T* get_component() {
            T* ( *get_component )( game_object*, il2cpp_object* ) = ( decltype( get_component ) )( unity_player + Offsets::GameObject::GetComponent );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_component, this, T::type_object_ );
        }

        template <typename T>
        sys::array<T*>* get_components() {
            sys::array<T*>* ( *get_components_internal )( game_object*, il2cpp_object*, bool, bool, bool, bool, void* ) =
                ( decltype( get_components_internal ) )( unity_player + Offsets::GameObject::GetComponentsInternal );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_components_internal, this, T::type_object_, false, false, true, false, nullptr );
        }

        template <typename T>
        T* add_component() {
            T* ( *internal_add_component_with_type )( game_object*, il2cpp_object* ) = 
                ( decltype( internal_add_component_with_type ) )( unity_player + Offsets::GameObject::Internal_AddComponentWithType );

            um::caller& caller = um::get_caller_for_thread();

            return caller( internal_add_component_with_type, this, T::type_object_ );
        }
    };

    class component : public object {
    public:
        game_object* get_game_object() {
            game_object* ( *get_game_object )( component* ) = ( decltype( get_game_object ) )( unity_player + Offsets::Component::get_gameObject );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_game_object, this );
        }

        transform* get_transform() {
            transform* ( *get_transform )( component* ) = ( decltype( get_transform ) )( unity_player + Offsets::Component::get_transform );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_transform, this );
        }

        static inline il2cpp_object* type_object_;
    };

    class behaviour : public component {
    public:
        bool get_enabled() {
            bool ( *get_enabled )( behaviour* ) = ( decltype( get_enabled ) )( unity_player + Offsets::Behaviour::get_enabled );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_enabled, this );
        }

        void set_enabled( bool value ) {
            void ( *set_enabled )( behaviour*, bool ) = ( decltype( set_enabled ) )( unity_player + Offsets::Behaviour::set_enabled );

            um::caller& caller = um::get_caller_for_thread();

            return caller( set_enabled, this, value );
        }

        static inline il2cpp_class* klass_;
    };

    class transform : public component {
    public:
        transform* get_child( int index ) {
            transform* ( *get_child )( transform*, int ) = 
                ( decltype( get_child ) )( unity_player + Offsets::Transform::GetChild );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_child, this, index );
        }

        int get_child_count() {
            int ( *get_child_count )( transform* ) =
                ( decltype( get_child_count ) )( unity_player + Offsets::Transform::get_childCount );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_child_count, this );
        }

        vector3 get_position() {
            void ( *get_position_injected )( transform*, vector3* ) = ( decltype( get_position_injected ) )( unity_player + Offsets::Transform::get_position_Injected );

            um::caller& caller = um::get_caller_for_thread();

            vector3* position = caller.push<vector3>();
            caller( get_position_injected, this, position );
            return *position;
        }
    };

    class camera : public behaviour {
    public:
        internals::camera* get_native_camera() {
            return ( internals::camera* )cached_ptr;
        }
    };

    class time {
    public:
        static float get_time() {
            float ( *get_time )() = decltype( get_time )( unity_player + Offsets::Time::get_time );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_time );
        }
    };

    class input {
    public:
        static vector2 get_mouse_position() {
            vector2* ( *get_mouse_position_injected )( vector2* ) = decltype( get_mouse_position_injected )( unity_player + Offsets::Input::get_mousePosition_Injected );

            um::caller& caller = um::get_caller_for_thread();

            vector2* mouse_position = caller.push<vector2>();
            caller( get_mouse_position_injected, mouse_position );
            return *mouse_position;
        }

        static bool get_mouse_button_down( int button ) {
            bool ( *get_mouse_button_down )( int ) = decltype( get_mouse_button_down )( unity_player + Offsets::Input::GetMouseButtonDown );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_mouse_button_down, button );
        }

        static bool get_mouse_button_up( int button ) {
            bool ( *get_mouse_button_up )( int ) = decltype( get_mouse_button_up )( unity_player + Offsets::Input::GetMouseButtonUp );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_mouse_button_up, button );
        }

        static bool get_mouse_button( int button ) {
            bool ( *get_mouse_button )( int ) = decltype( get_mouse_button )( unity_player + Offsets::Input::GetMouseButton );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_mouse_button, button );
        }

        static bool get_key_down( key_code key ) {
            bool( *get_key_down_int )( int ) = ( decltype( get_key_down_int ) )( unity_player + Offsets::Input::GetKeyDownInt );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_key_down_int, key );
        }

        static bool get_key_up( key_code key ) {
            bool( *get_key_up_int )( int ) = ( decltype( get_key_up_int ) )( unity_player + Offsets::Input::GetKeyUpInt );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_key_up_int, key );
        }

        static bool get_key( key_code key ) {
            bool( *get_key_int )( int ) = ( decltype( get_key_int ) )( unity_player + Offsets::Input::GetKeyInt );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_key_int, key );
        }
    };

    class texture {
    public:
    };

    class render_texture : public texture {
    public:
        static render_texture* get_temporary( int width, int height, int depth_buffer ) {
            render_texture*( *get_temporary )( int, int, int ) =
                ( decltype( get_temporary ) )( game_assembly + Offsets::RenderTexture::GetTemporary );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_temporary, width, height, depth_buffer );
        }

        static void release_temporary( render_texture* rt ) {
            void ( *release_temporary )( render_texture* ) =
                ( decltype( release_temporary ) )( unity_player + Offsets::RenderTexture::ReleaseTemporary );

            um::caller& caller = um::get_caller_for_thread();

            return caller( release_temporary, rt );
        }
    };

    class shader : public object {
    public:
        static shader* find( sys::string name ) {
            shader* ( *find )( sys::string* ) =
                ( decltype( find ) )( game_assembly + Offsets::Shader::Find );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* name_ = caller.push<sys::string>( name );

            return caller( find, name_ );
        }

        static int property_to_id( sys::string name ) {
            int ( *property_to_id )( sys::string* ) =
                ( decltype( property_to_id ) )( unity_player + Offsets::Shader::PropertyToID );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* name_ = caller.push<sys::string>( name );

            return caller( property_to_id, name_ );
        }

        static inline il2cpp_object* type_object_;
    };

    class material : public object {
    public:
        static material* ctor( shader* shader_ ) {
            void( *create_with_shader )( material*, shader* ) =
                ( decltype( create_with_shader ) )( unity_player + Offsets::Material::CreateWithShader );

            um::caller& caller = um::get_caller_for_thread();

            material* object = ( material* )il2cpp_object_new( material::klass_ );

            il2cpp_gchandle_new( object, true );
            caller( create_with_shader, object, shader_ );
            object->set_hide_flags( hide_flags::hide_and_dont_save );

            return object;
        }

        void set_float( int name, float value ) {
            void ( *set_float_impl )( material*, int, float ) =
                ( decltype( set_float_impl ) )( unity_player + Offsets::Material::SetFloatImpl );

            um::caller& caller = um::get_caller_for_thread();

            return caller( set_float_impl, this, name, value );
        }

        void set_color( int name, color value ) {
            void ( *set_color_impl_injected )( material*, int, color* ) =
                ( decltype( set_color_impl_injected ) )( unity_player + Offsets::Material::SetColorImpl_Injected );

            um::caller& caller = um::get_caller_for_thread();

            color* color_ = caller.push<color>( value );

            return caller( set_color_impl_injected, this, name, color_ );
        }

        void set_texture( int name, texture* value ) {
            void ( *set_texture_impl )( material*, int, texture* ) =
                ( decltype( set_texture_impl ) )( unity_player + Offsets::Material::SetTextureImpl );

            um::caller& caller = um::get_caller_for_thread();

            return caller( set_texture_impl, this, name, value );
        }

        void set_shader( shader* value) {
            void ( *set_shader )( material*, shader* ) =
                ( decltype( set_shader ) )( unity_player + Offsets::Material::set_shader );

            um::caller& caller = um::get_caller_for_thread();

            return caller( set_shader, this, value );
        }

        static inline il2cpp_class* klass_;
        static inline il2cpp_object* type_object_;
    };

    class renderer : object {
    public:
        bool get_enabled() {
            bool ( *get_enabled )( renderer* ) =
                ( decltype( get_enabled ) )( unity_player + Offsets::Renderer::get_enabled );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_enabled, this );
        }

        bool get_is_visible() {
            bool ( *get_is_visible )( renderer* ) =
                ( decltype( get_is_visible ) )( unity_player + Offsets::Renderer::get_isVisible );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_is_visible, this );
        }

        sys::array<material*>* get_materials() {
            sys::array<material*>* ( *get_material_array )( renderer* ) =
                ( decltype( get_material_array ) )( unity_player + Offsets::Renderer::GetMaterialArray );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_material_array, this );
        }

        internals::renderer* get_native_renderer() {
            return ( internals::renderer* )cached_ptr;
        }
    };

    class command_buffer : public il2cpp_object {
    public:
        static command_buffer* ctor() {
            void( *ctor )( command_buffer* ) =
                ( decltype( ctor ) )( game_assembly + Offsets::CommandBuffer::ctor );

            um::caller& caller = um::get_caller_for_thread();

            command_buffer* object = ( command_buffer* )il2cpp_object_new( command_buffer::klass_ );
            caller( ctor, object );

            return object;
        }

        void clear() {
            void( *clear )( command_buffer* ) = ( decltype( clear ) )( unity_player + Offsets::CommandBuffer::Clear );

            um::caller& caller = um::get_caller_for_thread();

            return caller( clear, this );
        }

        void set_render_target( render_target_identifier* rt ) {
            void ( *set_render_target_single_internal_injected )( command_buffer*, render_target_identifier* ) =
                ( decltype( set_render_target_single_internal_injected ) )( unity_player + Offsets::CommandBuffer::SetRenderTargetSingle_Internal_Injected );

            um::caller& caller = um::get_caller_for_thread();

            return caller( set_render_target_single_internal_injected, this, rt );
        }

        void clear_render_target( bool clear_depth, bool clear_color, color background_color ) {
            void ( *clear_render_target_injected )( command_buffer*, int, color*, float, uint32_t ) =
                ( decltype( clear_render_target_injected ) )( unity_player + Offsets::CommandBuffer::ClearRenderTarget_Injected );

            um::caller& caller = um::get_caller_for_thread();

            // UnityEngine.Rendering.RTClearFlags, 0 = None, 1 = Color, 6 = DepthStencil
            int clear_flags = ( clear_color ? 1 : 0 ) | ( clear_depth ? 6 : 0 );

            color* color_ = caller.push<color>( background_color );

            return caller( clear_render_target_injected, this, clear_flags, color_, 1.f, 0u );
        }

        void draw_renderer( renderer* renderer_, material* material_ ) {
            void ( *internal_draw_renderer )( command_buffer*, renderer*, material*, int, int ) =
                ( decltype( internal_draw_renderer ) )( unity_player + Offsets::CommandBuffer::Internal_DrawRenderer );

            um::caller& caller = um::get_caller_for_thread();

            return caller( internal_draw_renderer, this, renderer_, material_, 0, -1 );
        }

        static inline il2cpp_class* klass_;
    };

    class graphics {
    public:
        static void blit( texture* source, render_texture* dest, material* mat ) {
            void ( *internal_blit_material_5 )( texture*, render_texture*, material*, int, bool ) =
                ( decltype( internal_blit_material_5 ) )( unity_player + Offsets::Graphics::Internal_BlitMaterial5 );

            um::caller& caller = um::get_caller_for_thread();

            return caller( internal_blit_material_5, source, dest, mat, -1, true );
        }

        static void execute_command_buffer( command_buffer* buffer ) {
            void ( *execute_command_buffer )( command_buffer* ) =
                ( decltype( execute_command_buffer ) )( unity_player + Offsets::Graphics::ExecuteCommandBuffer );

            um::caller& caller = um::get_caller_for_thread();

            return caller( execute_command_buffer, buffer );
        }
    };

    class asset_bundle {
    public:
        static asset_bundle* load_from_file( sys::string path, uint32_t crc, uint64_t offset ) {
            asset_bundle* ( *load_from_file_internal )( sys::string*, uint32_t, uint64_t ) =
                ( decltype( load_from_file_internal ) )( unity_player + Offsets::AssetBundle::LoadFromFile_Internal );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* path_ = caller.push<sys::string>( path );

            return caller( load_from_file_internal, path_, crc, offset );
        }

        void unload( bool unload_all_loaded_objects ) {
            void ( *unload )( asset_bundle*, bool ) =
                ( decltype( unload ) )( unity_player + Offsets::AssetBundle::Unload );

            um::caller& caller = um::get_caller_for_thread();

            return caller( unload, this, unload_all_loaded_objects );
        }

        template <typename T>
        T* load_asset( sys::string name ) {
            T* ( *load_asset_internal )( asset_bundle*, sys::string*, il2cpp_object* ) =
                ( decltype( load_asset_internal ) )( unity_player + Offsets::AssetBundle::LoadAsset_Internal );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* name_ = caller.push<sys::string>( name );

            return caller( load_asset_internal, this, name_, T::type_object_ );
        }
    };

    class gradient {
    public:
        void set_keys( const std::initializer_list<gradient_color_key>& color_keys, const std::initializer_list<gradient_alpha_key>& alpha_keys ) {
            void ( *set_keys )( gradient*, sys::array<gradient_color_key>*, sys::array<gradient_alpha_key>* ) =
                ( decltype( set_keys ) )( unity_player + Offsets::Gradient::SetKeys );

            um::caller& caller = um::get_caller_for_thread();

            size_t color_keys_size = sizeof( gradient_color_key ) * color_keys.size();
            size_t alpha_keys_size = sizeof( gradient_alpha_key ) * alpha_keys.size();

            sys::array<gradient_color_key>* _color_keys = ( sys::array<gradient_color_key>* )
                caller.alloc( sizeof( sys::array<gradient_color_key> ) + color_keys_size, alignof( sys::array<gradient_color_key> ) );

            sys::array<gradient_alpha_key>* _alpha_keys = ( sys::array<gradient_alpha_key>* )
                caller.alloc( sizeof( sys::array<gradient_alpha_key> ) + alpha_keys_size, alignof( sys::array<gradient_alpha_key> ) );

            _color_keys->size = color_keys.size();
            _alpha_keys->size = alpha_keys.size();

            memcpy( _color_keys->buffer, color_keys.begin(), color_keys_size );
            memcpy( _alpha_keys->buffer, alpha_keys.begin(), alpha_keys_size );

            caller( set_keys, this, _color_keys, _alpha_keys );
        }
    };
}

namespace rust {
    class base_networkable;
    class model;
    class base_entity;
    class networkable;
    class item_container;
    class base_player;
    class held_entity;
}

namespace rust {
    enum bones {
        neck = 46,
        head = 47,
        spine1 = 18,
        spine3 = 21,
        spine4 = 22,
        l_clavicle = 23,
        r_clavicle = 54,
        l_upperarm = 24,
        r_upperarm = 55,
        l_forearm = 25,
        r_forearm = 56,
        l_hand = 26,
        r_hand = 57,
        l_hip = 1,
        r_hip = 13,
        l_knee = 2,
        r_knee = 14,
        l_foot = 3,
        r_foot = 15
    };

    enum item_category {
        weapon,
        construction,
        items,
        resources,
        attire,
        tool,
        medical,
        food,
        ammunition,
        traps,
        misc,
        all,
        common,
        component,
        search,
        favourite,
        electrical,
        fun
    };

    template <typename T>
    class singleton_component {
    public:
        class static_fields {
        public:
            FIELD( T*, instance, Offsets::SingletonComponent::Instance );
        };

        static inline static_fields* static_fields_;
    };

    class base_networkable : public unity::component {
    public:
        FIELD( uint32_t, prefab_id, Offsets::BaseNetworkable::prefabID );
        FIELD( networkable*, net, Offsets::BaseNetworkable::net );
        FIELD( base_entity*, parent_entity, Offsets::BaseNetworkable::parentEntity );
        FIELD( sys::list<base_entity*>*, children, Offsets::BaseNetworkable::children );
        
        static inline il2cpp_class* klass_;
    };

    class model {
    public:
        FIELD( sys::array<unity::transform*>*, bone_transforms, Offsets::Model::boneTransforms );
    };

    class base_entity : public base_networkable {
    public:
        FIELD( rust::model*, model, Offsets::BaseEntity::model );
        FIELD( int, flags, Offsets::BaseEntity::flags );
    };

    using networkable_id = uint64_t;

    class networkable {
    public:
        FIELD( networkable_id, id, Offsets::Network_Networkable::ID );
    };

    class rust_camera {
    public:
        FIELD( float, ambient_light_night, Offsets::RustCamera::ambientLightNight );
        FIELD( float, ambient_light_multiplier, Offsets::RustCamera::ambientLightMultiplier );
    };

    class main_camera {
    public:
        class static_fields {
        public:
            FIELD( unity::camera*, main_camera, Offsets::MainCamera::mainCamera );
        };

        static inline il2cpp_class* klass_;
        static inline static_fields* static_fields_;
    };

    enum lifestate : int {
        alive,
        dead
    };

    class protection_properties {
    public:
        FIELD( sys::array<float>*, amounts, Offsets::ProtectionProperties::amounts );
    };

    class base_combat_entity : public base_entity {
    public:
        FIELD( protection_properties*, base_protection, Offsets::BaseCombatEntity::baseProtection );
        FIELD( int, lifestate, Offsets::BaseCombatEntity::lifestate );
        FIELD( float, health, Offsets::BaseCombatEntity::_health );
        FIELD( float, max_health, Offsets::BaseCombatEntity::_maxHealth );
    };

    class skinned_multi_mesh {
    public:
        FIELD( sys::list<unity::renderer*>*, renderers, Offsets::SkinnedMultiMesh::Renderers );
    };

    class player_model {
    public:
        FIELD( skinned_multi_mesh*, multi_mesh, Offsets::PlayerModel::_multiMesh );
    };

    class player_input {

    };

    class base_movement : public unity::behaviour {
    public:
        FIELD( bool, admin_cheat, Offsets::BaseMovement::adminCheat );
        FIELD( base_player*, owner, Offsets::BaseMovement::Owner );
        FIELD( vector3, target_movement, Offsets::BaseMovement::TargetMovement );
        FIELD( float, grounded, Offsets::BaseMovement::Grounded );
    };

    class trigger_ladder {
    public:

    };

    class player_walk_movement : public base_movement {
    public:
        FIELD( trigger_ladder*, ladder, Offsets::PlayerWalkMovement::ladder );

        ENCRYPTED_VALUE( float, ground_time, Offsets::PlayerWalkMovement::groundTime, {},
            {
                values[ i ] = ( ( ( ( values[ i ] << 6 ) | ( values[ i ] >> 26 ) ) ^ 0xBECB992 ) << 28 )
                    | ( ( ( ( values[ i ] << 6 ) | ( values[ i ] >> 26 ) ) ^ 0xBECB992 ) >> 4 );
            }
        );

        ENCRYPTED_VALUE( float, jump_time, Offsets::PlayerWalkMovement::jumpTime, {},
            {
                int64_t a = 2LL * ( ( ( 16 * values[ i ] ) | ( values[ i ] >> 28 ) ) - 1519640036 );

                values[ i ] = ( ( unsigned int )a | HIDWORD( a ) ) + 1461189103;
            }
        );

        ENCRYPTED_VALUE( float, land_time, Offsets::PlayerWalkMovement::landTime, {},
            {
                values[ i ] = ( ( ( ( values[ i ] - 1165896616 ) ^ 0x979988FA ) + 1086581408 ) << 31 )
                    | ( unsigned __int64 )( ( ( ( values[ i ] - 1165896616 ) ^ 0x979988FA ) + 1086581408 ) >> 1 );
            }
        );

        ENCRYPTED_VALUE( float, ground_angle_new, Offsets::PlayerWalkMovement::groundAngleNew, {},
            {
                uint32_t a = ( ( ( values[ i ] << 9 ) | ( values[ i ] >> 23 ) ) + 1658094625 ) ^ 0xFD09D9DE;

                values[ i ] = ( a << 9 ) | ( a >> 23 );
            }
        );

        ENCRYPTED_VALUE( float, next_sprint_time, Offsets::PlayerWalkMovement::nextSprintTime, {},
            {
                values[ i ] = ( ( ( values[ i ] << 22 ) | ( values[ i ] >> 10 ) ) ^ 0xBE426B50 ) + 1940450374;
            }
        );

        static inline il2cpp_class* klass_;
    };

    class model_state {
    public:
        enum flag {
            ducked = 1,
            jumped = 2,
            on_ground = 4,
            sleeping = 8,
            sprinting = 16,
            on_ladder = 32,
            flying = 64,
            aiming = 128,
            prone = 256,
            mounted = 512,
            relaxed = 1024,
            on_phone = 2048,
            crawling = 4096,
            loading = 8192,
            head_look = 16384,
            has_parachute = 32768,
            blocking = 65536,
            ragdolling = 131072,
            catching = 262144
        };

        FIELD( float, water_level, Offsets::ModelState::waterLevel );
        FIELD( vector3, look_direction, Offsets::ModelState::lookDir );
        FIELD( int, flags, Offsets::ModelState::flags );

        bool has_flag( model_state::flag f ) {
            return ( flags & f ) == f;
        }

        void set_flag( model_state::flag f, bool b ) {
            if ( b ) {
                flags |= f;
            } else {
                flags &= ~f;
            }
        }
    };

    class player_eyes {
    public:
        static inline il2cpp_class* klass_;
        static inline il2cpp_object* type_object_;
    };

    class phrase {
    public:
        FIELD( sys::string*, legacy_english, Offsets::Translate_Phrase::legacyEnglish );
    };

    class item_definition {
    public:
        FIELD( int, item_id, Offsets::ItemDefinition::itemid );
        FIELD( phrase*, display_name, Offsets::ItemDefinition::displayName );
        FIELD( int, category, Offsets::ItemDefinition::category );
    };

    class item {
    public:
        FIELD( float, condition, Offsets::Item::_condition );
        FIELD( float, max_condition, Offsets::Item::_maxCondition );
        FIELD( item_definition*, info, Offsets::Item::info );
        FIELD( uint64_t, uid, Offsets::Item::uid );
        FIELD( int, amount, Offsets::Item::amount );
        FIELD( int, position, Offsets::Item::position );
        FIELD( item_container*, contents, Offsets::Item::contents );
        FIELD( base_entity*, world_entity, Offsets::Item::worldEnt );
        FIELD( base_entity*, held_entity, Offsets::Item::heldEntity );
    };

    class item_container {
    public:
        FIELD( uint64_t, uid, Offsets::ItemContainer::uid );
        FIELD( sys::list<item*>*, item_list, Offsets::ItemContainer::itemList );
    };

    class player_loot {
    public:
        FIELD( sys::list<item_container*>*, containers, Offsets::PlayerLoot::containers );
    };

    class player_inventory {
    public:
        FIELD( item_container*, container_main, Offsets::PlayerInventory::containerMain );
        FIELD( item_container*, container_belt, Offsets::PlayerInventory::containerBelt );
        FIELD( item_container*, container_wear, Offsets::PlayerInventory::containerWear );
        FIELD( player_loot*, loot, Offsets::PlayerInventory::loot );

        static inline il2cpp_class* klass_;
        static inline il2cpp_object* type_object_;
    };

    class input_state {
    public:

    };

    class base_player : public base_combat_entity {
    public:
        FIELD( rust::player_model*, player_model, Offsets::BasePlayer::playerModel );
        FIELD( player_input*, input, Offsets::BasePlayer::input );
        FIELD( player_walk_movement*, movement, Offsets::BasePlayer::movement );
        FIELD( uint64_t, current_team, Offsets::BasePlayer::currentTeam );

        ENCRYPTED_VALUE( uint64_t, cl_active_item, Offsets::BasePlayer::clActiveItem,
            {
                values[ i ] = ( ( ( values[ i ] - 39167478 ) << 8 ) | 
                    ( ( unsigned int )( values[ i ] - 39167478 ) >> 24 ) ) - 813727899;
            }, {}
        );

        FIELD( rust::model_state*, model_state, Offsets::BasePlayer::modelState );
        FIELD( int, player_flags, Offsets::BasePlayer::playerFlags );
        FIELD( sys::string*, user_id_string, Offsets::BasePlayer::UserIDString );
        FIELD( sys::string*, display_name, Offsets::BasePlayer::_displayName );

        player_eyes* get_eyes() {
            unity::game_object* game_object = get_game_object();
            if ( !is_valid_ptr( game_object ) )
                return nullptr;

            return game_object->get_component<rust::player_eyes>();
        }

        uint64_t get_user_id() {
            if ( !is_valid_ptr( user_id_string ) )
                return 0ull;

            return wcstoull( user_id_string->buffer, nullptr, 10 );
        }

        player_inventory* get_inventory() {
            unity::game_object* game_object = get_game_object();
            if ( !is_valid_ptr( game_object ) )
                return nullptr;

            return game_object->get_component<rust::player_inventory>();
        }

        float get_speed( float running, float ducking, float crawling ) {
            float ( *get_speed )( base_player*, float, float, float ) =
                ( decltype( get_speed ) )( game_assembly + Offsets::BasePlayer::GetSpeed );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_speed, this, running, ducking, crawling );
        }

        item* get_held_item() {
            player_inventory* inventory = get_inventory();
            if ( !is_valid_ptr( inventory ) )
                return nullptr;

            item_container* belt = inventory->container_belt;
            if ( !is_valid_ptr( belt ) )
                return nullptr;

            sys::list<item*>* items_list = belt->item_list;
            if ( !is_valid_ptr( items_list ) || !is_valid_ptr( items_list->items ) )
                return nullptr;

            sys::array<item*>* items = items_list->items;
            if ( !is_valid_ptr( items ) )
                return nullptr;

            uint64_t active_item_id = cl_active_item;

            for ( size_t i = 0; i < items_list->size; i++ ) {
                item* item_ = items->buffer[ i ];
                if ( !is_valid_ptr( item_ ) )
                    continue;

                if ( item_->uid == active_item_id ) {
                    return item_;
                }
            }

            return nullptr;
        }

        held_entity* get_held_entity() {
            item* held_item = get_held_item();
            if ( !held_item )
                return nullptr;

            base_entity* held_entity_ = held_item->held_entity;
            if ( !is_valid_ptr( held_entity_ ) )
                return nullptr;

            return held_entity_->as<held_entity>();
        }

        // This works completely differently from the actual BasePlayer.OnLadder
        bool on_ladder() {
            player_walk_movement* _movement = movement->as<player_walk_movement>();
            if ( !_movement )
                return false;

            return _movement->ladder != nullptr;
        }

        // This may only work for the local player, but that's we need it to work for
        bool is_swimming() {
            if ( !is_valid_ptr( model_state ) )
                return false;

            return model_state->water_level > 0.65f;
        }

        static inline il2cpp_class* klass_;
    };

    class scientist_npc : public base_player {
    public:
        static inline il2cpp_class* klass_;
    };

    class tunnel_dweller : public base_player {
    public:
        static inline il2cpp_class* klass_;
    };

    class underwater_dweller : public base_player {
    public:
        static inline il2cpp_class* klass_;
    };

    class scarecrow_npc : public base_player {
    public:
        static inline il2cpp_class* klass_;
    };

    class gingerbread_npc : public base_player {
    public:
        static inline il2cpp_class* klass_;
    };

    class held_entity : public base_entity {
    public:
        static inline il2cpp_class* klass_;
        static inline il2cpp_object* type_object_;
    };

    class attack_entity : public held_entity {
    public:
        static inline il2cpp_class* klass_;
    };

    class base_melee : public attack_entity {
    public:
        static inline il2cpp_class* klass_;
    };

    class base_projectile : public attack_entity {
    public:
        static inline il2cpp_class* klass_;
    };

    class graphics {
    public:
        class static_fields {
        public:
            ENCRYPTED_VALUE( float, fov, Offsets::ConVar_Graphics_Static::_fov, {},
                {
                    values[ i ] = ( ( ( values[ i ] << 22 ) | 
                        ( values[ i ] >> 10 ) ) ^ 0x5A40F656 ) - 1305720721;
                }
            );
        };

        static inline static_fields* static_fields_;
    };

    class outline_manager {
    public:
        static inline il2cpp_class* klass_;
    };

    class projectile_shoot {
    public:
        class projectile {
        public:
            FIELD( vector3, start_pos, Offsets::ProtoBuf_ProjectileShoot_Projectile::startPos );
            FIELD( vector3, start_vel, Offsets::ProtoBuf_ProjectileShoot_Projectile::startVel );
        };

        FIELD( sys::list<projectile*>*, projectiles, Offsets::ProtoBuf_ProjectileShoot::projectiles );

        static inline il2cpp_class* klass_;
    };

    class player_projectile_update {
    public:
        FIELD( int, projectile_id, Offsets::ProtoBuf_PlayerProjectileUpdate::projectileID );
        FIELD( vector3, cur_position, Offsets::ProtoBuf_PlayerProjectileUpdate::curPosition );
        FIELD( vector3, cur_velocity, Offsets::ProtoBuf_PlayerProjectileUpdate::curVelocity );
        FIELD( float, travel_time, Offsets::ProtoBuf_PlayerProjectileUpdate::travelTime );
        FIELD( bool, should_pool, Offsets::ProtoBuf_PlayerProjectileUpdate::ShouldPool );

        static inline il2cpp_class* klass_;
    };

    class player_projectile_attack {
    public:
        static inline il2cpp_class* klass_;
    };

    class input_message {
    public:

    };

    class player_tick {
    public:
        FIELD( input_message*, input_state, Offsets::PlayerTick::inputState );
        FIELD( vector3, position, Offsets::PlayerTick::position );
        FIELD( rust::model_state*, model_state, Offsets::PlayerTick::modelState );
        FIELD( uint64_t, active_item, Offsets::PlayerTick::activeItem );
        FIELD( vector3, eye_pos, Offsets::PlayerTick::eyePos );
        FIELD( uint64_t, parent_id, Offsets::PlayerTick::parentID );

        static inline il2cpp_class* klass_;
    };

    class projectile {
    public:

    };

    class local_player {
    public:
        static base_player* get_entity() {
            base_player* ( *get_entity )() = ( decltype( get_entity ) )( game_assembly + Offsets::LocalPlayer::get_Entity );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_entity );
        }
    };

    class item_icon {
    public:
        void run_timed_action() {
            void ( *run_timed_action )( item_icon* ) = 
                ( decltype( run_timed_action ) )( game_assembly + Offsets::ItemIcon::RunTimedAction );

            um::caller& caller = um::get_caller_for_thread();

            return caller( run_timed_action, this );
        }

        static inline il2cpp_class* klass_;
    };

    class world_item : public base_entity {
    public:
        FIELD( rust::item*, item, Offsets::WorldItem::item );
    };

    class client {
    public:
        static inline il2cpp_class* klass_;
    };

    class tod_night_parameters {
    public:
        FIELD( unity::gradient*, ambient_color, Offsets::TOD_NightParameters::AmbientColor );
    };

    class tod_ambient_parameters {
    public:
        FIELD( float, saturation, Offsets::TOD_AmbientParameters::Saturation );
    };

    class tod_sky {
    public:
        FIELD( tod_night_parameters*, night, Offsets::TOD_Sky::Night );
        FIELD( tod_ambient_parameters*, ambient, Offsets::TOD_Sky::Ambient );

        static tod_sky* get_instance() {
            tod_sky* ( *get_instance )( ) =
                ( decltype( get_instance ) )( game_assembly + Offsets::TOD_Sky::get_Instance );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_instance );
        }
    };
}
