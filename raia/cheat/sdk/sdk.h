#pragma once

#include "declare.h"

#include "global.h"
#include "cheat/sdk/offsets.h"
#include "cheat/sdk/field_types.h"
#include "cheat/sdk/il2cpp.h"
#include "um.h"
#include "hexrays.h"

#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "math/quat.h"
#include "math/mat4x4.h"

#include <md5.h>

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

        static string* create( const wchar_t* str ) {
            string* ( *fast_allocate_string )( int ) =
                ( decltype( fast_allocate_string ) )( game_assembly + Offsets::String::FastAllocateString );

            um::caller& caller = um::get_caller_for_thread();

            size_t length = wcslen( str );
            string* string = caller( fast_allocate_string, length );
            if ( !is_valid_ptr( string ) )
                return nullptr;

            string->length = length;
            wcscpy( string->buffer, str );

            return string;
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

        T& at( int32_t index ) {
            return items->buffer[ index ];
        }
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

    class action {
    public:
        FIELD( void*, invoke_impl, 0x18 );
    };
}

namespace unity {
    namespace internals {
        namespace math {
            struct trsx {
            public:
                vector3 t;
            private:
                uint8_t _[ 0x4 ];
            public:
                vector4 q;
                vector3 s;
            private:
                uint8_t __[ 0x4 ];
            };

            inline vector3 quat_mul_vec( const vector4& q, const vector3& u ) {
                const vector3 c0 = vector3( -2.f, 2.f, -2.f );
                const vector3 c1 = vector3( -2.f, -2.f, 2.f );
                const vector3 c2 = vector3( 2.f, -2.f, -2.f );

                vector3 qyxw = vector3( q.y, q.x, q.w );
                vector3 qzwx = vector3( q.z, q.w, q.x );
                vector3 qwzy = vector3( q.w, q.z, q.y );

                vector3 m0 = ( c0 * q.y ) * qyxw - ( c2 * q.z ) * qzwx;
                vector3 m1 = ( c1 * q.z ) * qwzy - ( c0 * q.x ) * qyxw;
                vector3 m2 = ( c2 * q.x ) * qzwx - ( c1 * q.y ) * qwzy;

                return vector3( ( u + ( m0 * u.x ) ) + ( ( m1 * u.y ) + ( m2 * u.z ) ) );
            }

            inline vector3 mul( trsx& x, vector3& v ) {
                return x.t + quat_mul_vec( x.q, v * x.s );
            }
        }

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

        struct transform_hierarchy {
            FIELD( math::trsx*, local_transforms, 0x18 );
            FIELD( int32_t*, parent_indices, 0x20 );
        };

        struct transform_access {
            transform_hierarchy* hierarchy;
            uint32_t index;
        };

        class scripting_gc_handle {
        public:
            FIELD( il2cpp_object*, object, 0x10 );
        };

        class object {
        public:
            FIELD( scripting_gc_handle, mono_reference, 0x18 );
        };

        class transform {
        public:
            FIELD( transform_access, transform_data, 0x38 );

            vector3 get_position() {
                transform_access transform_access = transform_data;
                if ( transform_access.index > 65536u || !is_valid_ptr( transform_access.hierarchy ) )
                    return vector3();

                transform_hierarchy* hierarchy = transform_access.hierarchy;
                if ( !is_valid_ptr( hierarchy->local_transforms ) || !is_valid_ptr( hierarchy->parent_indices ) )
                    return vector3();

                math::trsx* local_transforms = hierarchy->local_transforms;

                vector3 global_t = local_transforms[ transform_data.index ].t;

                int32_t* parent_indices = hierarchy->parent_indices;
                int32_t parent_index = parent_indices[ transform_data.index ];

                int32_t iterations = 0;

                while ( parent_index >= 0 && iterations++ < 256 ) {
                    global_t = math::mul( local_transforms[ parent_index ], global_t );
                    parent_index = parent_indices[ parent_index ];
                }

                return global_t;
            }
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

        class d3d11_texture {
        public:
            FIELD( ID3D11ShaderResourceView*, srv, 0x8 );
        };

        class texture {
        public:
            FIELD( uint32_t, texture_id, 0x50 );

            d3d11_texture* get_native_texture_ptr() {
                d3d11_texture* ( *get_texture )( void*, uint32_t ) = ( decltype( get_texture ) )( unity_player + 0x90C490 );

                um::caller& caller = um::get_caller_for_thread();

                return caller( get_texture, nullptr, texture_id );
            }
        };
    }

    namespace collections {
        template <typename T>
        struct native_array {
            T* buffer;
            int length;
            int allocator_label;
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

    struct ray {
        vector3 origin;
        vector3 direction;
    };

    struct raycast_hit {
        vector3 point;
        vector3 normal;
        uint32_t face_id;
        float distance;
        vector2 uv;
        int collider;
    };

    enum query_trigger_interaction {
        use_global,
        ignore,
        collide
    };

    struct mathf {
    public:
        static bool is_power_of_two( int value ) {
            return ( value & ( value - 1 ) ) == 0;
        }

        static int clamp( int value, int min, int max ) {
            return ( value < min ) ? min : ( value > max ) ? max : value;
        }

        static float clamp( float value, float min, float max ) {
            return ( value < min ) ? min : ( value > max ) ? max : value;
        }

        static float clamp01( float value ) {
            return ( value < 0.f ) ? 0.f : ( value > 1.f ) ? 1.f : value;
        }

        static int min( int a, int b ) {
            return a < b ? a : b;
        }

        static float max( float a, float b ) {
            return a > b ? a : b;
        }

        static float lerp( float a, float b, float t ) {
            return a + ( b - a ) * clamp01( t );
        }
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
        sys::array<T*>* get_components_in_children() {
            sys::array<T*>* ( *get_components_internal )( game_object*, il2cpp_object*, bool, bool recursive, bool include_inactive, bool reverse, void* ) =
                ( decltype( get_components_internal ) )( unity_player + Offsets::GameObject::GetComponentsInternal );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_components_internal, this, T::type_object_, false, true, false, false, nullptr );
        }

        template <typename T>
        T* add_component() {
            T* ( *internal_add_component_with_type )( game_object*, il2cpp_object* ) = 
                ( decltype( internal_add_component_with_type ) )( unity_player + Offsets::GameObject::Internal_AddComponentWithType );

            um::caller& caller = um::get_caller_for_thread();

            return caller( internal_add_component_with_type, this, T::type_object_ );
        }

        static inline il2cpp_class* klass_;
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

        vector3 get_euler_angles() {
            void ( *get_euler_angles )( vector3*, transform* ) =
                ( decltype( get_euler_angles ) )( game_assembly + Offsets::Transform::get_eulerAngles );

            um::caller& caller = um::get_caller_for_thread();

            vector3* euler_angles = caller.push<vector3>();
            caller( get_euler_angles, euler_angles, this );
            return *euler_angles;
        }

        vector3 get_position() {
            internals::transform* native_transform = ( internals::transform* )cached_ptr;
            if ( !is_valid_ptr( native_transform ) )
                return vector3();

            return native_transform->get_position();
        }

        void set_position( const vector3& position ) {
            void ( *set_position_injected )( transform*, vector3* ) =
                ( decltype( set_position_injected ) )( unity_player + Offsets::Transform::set_position_Injected );

            um::caller& caller = um::get_caller_for_thread();

            vector3* _position = caller.push<vector3>( position );

            caller( set_position_injected, this, _position );
        }

        void get_position_and_rotation( vector3* position, quaternion* rotation ) {
            void ( *get_position_and_rotation )( transform*, vector3*, quaternion* ) = 
                ( decltype( get_position_and_rotation ) )( unity_player + Offsets::Transform::GetPositionAndRotation );

            um::caller& caller = um::get_caller_for_thread();

            vector3* _position = caller.push<vector3>();
            quaternion* _rotation = caller.push<quaternion>();

            caller( get_position_and_rotation, this, _position, _rotation );

            *position = *_position;
            *rotation = *_rotation;
        }

        vector3 get_lossy_scale() {
            void ( *get_lossy_scale_injected )( transform*, vector3* ) =
                ( decltype( get_lossy_scale_injected ) )( unity_player + Offsets::Transform::get_lossyScale_Injected );

            um::caller& caller = um::get_caller_for_thread();

            vector3* lossy_scale = caller.push<vector3>();
            caller( get_lossy_scale_injected, this, lossy_scale );
            return *lossy_scale;
        }

        vector3 inverse_transform_point( const vector3& position ) {
            void ( *inverse_transform_point_injected )( transform*, vector3*, vector3* ) =
                ( decltype( inverse_transform_point_injected ) )( unity_player + Offsets::Transform::InverseTransformPoint_Injected );

            um::caller& caller = um::get_caller_for_thread();

            vector3* _position = caller.push<vector3>( position );
            vector3* result = caller.push<vector3>();

            caller( inverse_transform_point_injected, this, _position, result );

            return *result;
        }

        quaternion get_rotation() {
            void ( *get_rotation_injected )( transform*, quaternion* ) =
                ( decltype( get_rotation_injected ) )( game_assembly + Offsets::Transform::get_rotation_Injected );

            um::caller& caller = um::get_caller_for_thread();

            quaternion* rotation = caller.push<quaternion>();
            caller( get_rotation_injected, this, rotation );
            return *rotation;
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
            float ( *get_time )( ) = decltype( get_time )( unity_player + Offsets::Time::get_time );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_time );
        }

        static float get_delta_time() {
            float ( *get_delta_time )( ) = decltype( get_delta_time )( unity_player + Offsets::Time::get_deltaTime );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_delta_time );
        }

        static float get_fixed_time() {
            float ( *get_fixed_time )( ) = decltype( get_fixed_time )( unity_player + Offsets::Time::get_fixedTime );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_fixed_time );
        }

        static float get_real_time_since_startup() {
            float ( *get_real_time_since_startup )( ) = 
                decltype( get_real_time_since_startup )( unity_player + Offsets::Time::get_realtimeSinceStartup );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_real_time_since_startup );
        }

        static int32_t get_frame_count() {
            int32_t( *get_frame_count )( ) =
                decltype( get_frame_count )( unity_player + Offsets::Time::get_frameCount );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_frame_count );
        }
    };

    class input {
    public:
        static vector2 get_mouse_position() {
            vector2* ( *get_mouse_position_injected )( vector2* ) = 
                decltype( get_mouse_position_injected )( unity_player + Offsets::Input::get_mousePosition_Injected );

            um::caller& caller = um::get_caller_for_thread();

            vector2* mouse_position = caller.push<vector2>();
            caller( get_mouse_position_injected, mouse_position );
            return *mouse_position;
        }

        static vector2 get_mouse_scroll_delta() {
            vector2* ( *get_mouse_scroll_delta_injected )( vector2* ) = 
                decltype( get_mouse_scroll_delta_injected )( unity_player + Offsets::Input::get_mouseScrollDelta_Injected );

            um::caller& caller = um::get_caller_for_thread();

            vector2* scroll_delta = caller.push<vector2>();
            caller( get_mouse_scroll_delta_injected, scroll_delta );
            return *scroll_delta;
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

    class screen {
    public:
        static int get_width() {
            int( *get_width )( ) = ( decltype( get_width ) )( unity_player + Offsets::Screen::get_width );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_width );
        }

        static int get_height() {
            int( *get_height )( ) = ( decltype( get_height ) )( unity_player + Offsets::Screen::get_height );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_height );
        }
    };

    class texture : public object {
    public:
        internals::texture* get_native_texture() {
            return ( internals::texture* )cached_ptr;
        }

        ID3D11ShaderResourceView* get_srv() {
            internals::texture* native_texture = get_native_texture();
            if ( !is_valid_ptr( native_texture ) )
                return nullptr;

            internals::d3d11_texture* d3d11_texture = native_texture->get_native_texture_ptr();
            if ( !is_valid_ptr( d3d11_texture ) )
                return nullptr;

            return d3d11_texture->srv;
        }
    };

    class texture2d : public texture {
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

    class sprite : public object {
    public:
        texture2d* get_texture() {
            texture2d* ( *get_texture )( sprite* ) =
                ( decltype( get_texture ) )( unity_player + Offsets::Sprite::get_texture );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_texture, this );
        }
    };

    class shader : public object {
    public:
        static shader* find( const sys::string& name ) {
            shader* ( *find )( sys::string* ) =
                ( decltype( find ) )( game_assembly + Offsets::Shader::Find );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* _name = caller.push<sys::string>( name );

            return caller( find, _name );
        }

        static int property_to_id( const sys::string& name ) {
            int ( *property_to_id )( sys::string* ) =
                ( decltype( property_to_id ) )( unity_player + Offsets::Shader::PropertyToID );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* _name = caller.push<sys::string>( name );

            return caller( property_to_id, _name );
        }

        int get_property_count() {
            int ( *get_property_count )( shader* ) =
                ( decltype( get_property_count ) )( unity_player + Offsets::Shader::GetPropertyCount );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_property_count, this );
        }

        sys::string* get_property_name( int index ) {
            sys::string* ( *get_property_name )( shader*, int ) =
                ( decltype( get_property_name ) )( unity_player + Offsets::Shader::GetPropertyName );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_property_name, this, index );
        }

        int get_property_type( int index ) {
            int ( *get_property_type )( shader*, int ) =
                ( decltype( get_property_type ) )( unity_player + Offsets::Shader::GetPropertyType );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_property_type, this, index );
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

            color* _color = caller.push<color>( value );

            return caller( set_color_impl_injected, this, name, _color );
        }

        void set_texture( int name, texture* value ) {
            void ( *set_texture_impl )( material*, int, texture* ) =
                ( decltype( set_texture_impl ) )( unity_player + Offsets::Material::SetTextureImpl );

            um::caller& caller = um::get_caller_for_thread();

            return caller( set_texture_impl, this, name, value );
        }

        shader* get_shader() {
            shader* ( *get_shader )( material* ) =
                ( decltype( get_shader ) )( unity_player + Offsets::Material::get_shader );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_shader, this );
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

    class renderer : public component {
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

        static inline il2cpp_object* type_object_;
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

            color* _color = caller.push<color>( background_color );

            return caller( clear_render_target_injected, this, clear_flags, _color, 1.f, 0u );
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
        static asset_bundle* load_from_file( const sys::string& path, uint32_t crc, uint64_t offset ) {
            asset_bundle* ( *load_from_file_internal )( sys::string*, uint32_t, uint64_t ) =
                ( decltype( load_from_file_internal ) )( unity_player + Offsets::AssetBundle::LoadFromFile_Internal );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* _path = caller.push<sys::string>( path );

            return caller( load_from_file_internal, _path, crc, offset );
        }

        void unload( bool unload_all_loaded_objects ) {
            void ( *unload )( asset_bundle*, bool ) =
                ( decltype( unload ) )( unity_player + Offsets::AssetBundle::Unload );

            um::caller& caller = um::get_caller_for_thread();

            return caller( unload, this, unload_all_loaded_objects );
        }

        template <typename T>
        T* load_asset( const sys::string& name ) {
            T* ( *load_asset_internal )( asset_bundle*, sys::string*, il2cpp_object* ) =
                ( decltype( load_asset_internal ) )( unity_player + Offsets::AssetBundle::LoadAsset_Internal );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* _name = caller.push<sys::string>( name );

            return caller( load_asset_internal, this, _name, T::type_object_ );
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

    class physics {
    public:
        static bool raycast( vector3 origin, vector3 direction, raycast_hit* hit_info, float max_distance, int layer_mask, int query_trigger_interaction ) {
            bool ( *raycast )( vector3*, vector3*, raycast_hit*, float, int, int ) =
                ( decltype( raycast ) )( game_assembly + Offsets::Physics::Raycast );

            um::caller& caller = um::get_caller_for_thread();

            vector3* _origin = caller.push<vector3>( origin );
            vector3* _direction = caller.push<vector3>( direction );
            raycast_hit* _hit_info = caller.push<raycast_hit>();

            bool result = caller( raycast, _origin, _direction, _hit_info, max_distance, layer_mask, query_trigger_interaction );

            *hit_info = *_hit_info;

            return result;
        }

        static int raycast_non_alloc( vector3 origin, vector3 direction, sys::array<raycast_hit>* results, float max_distance, int layer_mask, int query_trigger_interaction ) {
            int ( *raycast_non_alloc )( vector3*, vector3*, sys::array<raycast_hit>*, float, int, int ) =
                ( decltype( raycast_non_alloc ) )( game_assembly + Offsets::Physics::RaycastNonAlloc );

            um::caller& caller = um::get_caller_for_thread();

            vector3* _origin = caller.push<vector3>( origin );
            vector3* _direction = caller.push<vector3>( direction );

            return caller( raycast_non_alloc, _origin, _direction, results, max_distance, layer_mask, query_trigger_interaction );
        }

        static bool check_capsule( vector3 start, vector3 end, float radius, int layer_mask, int query_trigger_interaction ) {
            bool ( *check_capsule )( vector3*, vector3*, float, int, int ) =
                ( decltype( check_capsule ) )( game_assembly + Offsets::Physics::CheckCapsule );

            um::caller& caller = um::get_caller_for_thread();

            vector3* _start = caller.push<vector3>( start );
            vector3* _end = caller.push<vector3>( end );

            return caller( check_capsule, _start, _end, radius, layer_mask, query_trigger_interaction );
        }
    };

    // I don't know that this is actually from Unity, but it's in their namespace
    class string_ex {
    public:
        static constexpr uint32_t manifest_hash( const char* str ) {
            md5::Digest digest = md5::compute( str );

            return ( uint32_t )( ( int )( digest[ 0 ] ) | ( ( int )digest[ 1 ] << 8 ) | 
                ( ( int )digest[ 2 ] << 16 ) | ( ( int )digest[ 3 ] << 24 ) );
        }
    };

    // UnityEngine.UI.Image
    class image {
    public:
        FIELD( unity::sprite*, sprite, Offsets::Image::m_Sprite );
    };

    class instanced_debug_draw {
    public:
        enum transform_type {
            none,
            world_space,
            screen_aligned,
            pixel_space
        };

        struct instance_creation_data {
            matrix4x4 matrix;
            color color;
            vector3 pos_offset;
            float duration;
            float line_width;
            int sub_mesh_index;
            transform_type transform_type;
            bool use_distance_fade;
            bool use_depth_test;
        };

        void add_instance( const instance_creation_data& data ) {
            void ( *add_instance )( instanced_debug_draw*, instance_creation_data* ) =
                ( decltype( add_instance ) )( game_assembly + Offsets::InstancedDebugDraw::AddInstance );

            um::caller& caller = um::get_caller_for_thread();

            instance_creation_data* _data = caller.push<instance_creation_data>( data );

            return caller( add_instance, this, _data );
        }

        void line( vector3 start, vector3 end, color color, float duration, bool distance_fade, bool ztest ) {
            vector3 delta = end - start;
            quaternion q = quaternion::identity;

            if ( vector3::magnitude( delta ) > 0.01f ) {
                look_rotation_to_quaternion( delta, vector3::up, q );
            }

            instance_creation_data instance = {
                .matrix = matrix4x4::trs( start, q, vector3( 1.f, 1.f, vector3::magnitude(delta) ) ),
                .color = color,
                .pos_offset = vector3(),
                .duration = duration,
                .line_width = 1.f,
                .sub_mesh_index = 2,
                .transform_type = transform_type::world_space,
                .use_distance_fade = distance_fade,
                .use_depth_test = ztest
            };

            add_instance( instance );
        }

        static inline il2cpp_class* klass_;
    };

    struct bounds {
        vector3 center;
        vector3 extents;
    };
}

namespace rust {
    namespace bones {
        enum : int {
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
    }

    namespace ragdoll_bones {
        enum : int {
            neck = 45,
            head = 46,
            spine1 = 17,
            spine3 = 19,
            spine4 = 20,
            l_clavicle = 22,
            r_clavicle = 55,
            l_upperarm = 23,
            r_upperarm = 56,
            l_forearm = 24,
            r_forearm = 57,
            l_hand = 25,
            r_hand = 58,
            l_hip = 1,
            r_hip = 11,
            l_knee = 2,
            r_knee = 12,
            l_foot = 3,
            r_foot = 13
        };
    }
    
    namespace item_category {
        enum : int {
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
    }

    enum ammo_types : int {
        pistol_9mm = 1,
        rifle_556mm = 2,
        shotgun_12gauge = 4,
        bow_arrow = 8,
        handmade_shell = 16,
        rocket = 32,
        nails = 64,
        ammo_40mm = 128,
        snowball = 256,
        speargun_bolt = 512,
        torpedo = 1024,
        mlrs_rocket = 2048,
        missile_seeking = 4096,
        catapult_boulder = 8192,
        ballista_arrow = 16384,
        dart = 32768,
    };

    struct entity_ref {
    public:
        base_entity* ent_cached;
        networkable_id id_cached;

        rust::base_entity* get( bool serverside ) {
            rust::base_entity* ( *get )( entity_ref*, bool ) =
                ( decltype( get ) )( game_assembly + Offsets::EntityRef::Get );

            um::caller& caller = um::get_caller_for_thread();

            entity_ref* _this = caller.push<entity_ref>( *this );

            return caller( get, _this, serverside );
        }
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

    template <typename T>
    class list_hash_set {
    public:
        FIELD( sys::buffer_list<T>*, vals, Offsets::ListHashSet::vals );
    };

    template <typename T>
    class list_component {
    public:
        class static_fields {
        public:
            FIELD( list_hash_set<T*>*, instance_list, Offsets::ListComponent::InstanceList );
        };

        static inline static_fields* static_fields_;
    };

    template <typename T>
    class resource_ref {
    public:
        FIELD( sys::string*, guid, 0x10 );
        FIELD( T*, cached_object, 0x18 )
    };

    class game_object_ref : public resource_ref<unity::game_object> {
    public:

    };

    class string_pool {
    public:
        static uint32_t get( const sys::string& str ) {
            uint32_t( *get )( sys::string* ) =
                ( decltype( get ) )( game_assembly + Offsets::StringPool::Get );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* _str = caller.push<sys::string>( str );

            return caller( get, _str );
        }
    };

    namespace network {
        enum send_method {
            reliable,
            reliable_unordered,
            unreliable
        };

        enum priority {
            immediate,
            normal
        };

        struct send_info {
        public:
            FIELD( int, method, Offsets::Network_SendInfo::method );
            FIELD( int8_t, channel, Offsets::Network_SendInfo::channel );
            FIELD( int, priority, Offsets::Network_SendInfo::priority );
            FIELD( sys::list<network::connection*>*, connections, Offsets::Network_SendInfo::connections );
            FIELD( network::connection*, connection, Offsets::Network_SendInfo::connection );

            send_info( network::connection* _connection ) {
                method = send_method::reliable;
                channel = 0u;
                priority = priority::normal;
                connections = nullptr;
                connection = _connection;
            }

        private:
            uint8_t _[ 64 ];
        };

        class connection {
        public:

        };

        class net_write {
        public:
            void write_byte( uint8_t value ) {
                void ( *write_byte )( net_write*, uint8_t ) =
                    ( decltype( write_byte ) )( game_assembly + Offsets::Network_NetWrite::WriteByte );

                um::caller& caller = um::get_caller_for_thread();

                return caller( write_byte, this, value );
            }

            void string( const sys::string& value ) {
                void ( *string )( net_write*, sys::string* ) =
                    ( decltype( string ) )( game_assembly + Offsets::Network_NetWrite::String );

                um::caller& caller = um::get_caller_for_thread();

                sys::string* _value = caller.push<sys::string>( value );

                return caller( string, this, _value );
            }

            void send( send_info info ) {
                void ( *send )( net_write*, send_info* ) =
                    ( decltype( send ) )( game_assembly + Offsets::Network_NetWrite::Send );

                um::caller& caller = um::get_caller_for_thread();

                send_info* _info = caller.push<send_info>( info );

                return caller( send, this, _info );
            }

            template <typename T>
            void write( const T& value ) {
                uint8_t* bytes = ( uint8_t* )&value;

                for ( size_t i = 0; i < sizeof( T ); i++ ) {
                    write_byte( bytes[ i ] );
                }
            }

            void packet_id( uint8_t type ) {
                write<uint8_t>( type + 140u );
            }
        };

        class message {
        public:
            enum type : uint8_t {
                rpc_message = 9,
                tick = 15
            };
        };

        class base_network {
        public:
            net_write* start_write() {
                net_write*( *start_write )( base_network* ) =
                    ( decltype( start_write ) )( game_assembly + Offsets::Network_BaseNetwork::StartWrite );

                um::caller& caller = um::get_caller_for_thread();

                return caller( start_write, this );
            }
        };

        class client : public base_network {
        public:
            FIELD( network::connection*, connection, Offsets::Network_Client::Connection );
            FIELD( sys::string*, connected_address, Offsets::Network_Client::ConnectedAddress );
            FIELD( int, connected_port, Offsets::Network_Client::ConnectedPort );
            FIELD( sys::string*, server_name, Offsets::Network_Client::ServerName );
        };

        class net {
        public:
            class static_fields {
            public:
                FIELD( client*, cl, Offsets::Network_Net::cl );
            };

            static inline static_fields* static_fields_;
        };

        class networkable {
        public:
            FIELD( networkable_id, id, Offsets::Network_Networkable::ID );
        };
    }

    class base_networkable : public unity::component {
    public:
        FIELD( uint32_t, prefab_id, Offsets::BaseNetworkable::prefabID );
        FIELD( network::networkable*, net, Offsets::BaseNetworkable::net );
        FIELD( base_entity*, parent_entity, Offsets::BaseNetworkable::parentEntity );
        FIELD( sys::list<base_entity*>*, children, Offsets::BaseNetworkable::children );
        
        static inline il2cpp_class* klass_;
    };

    namespace interpolation {
        struct transform_snapshot {
            float time;
            vector3 pos;
            quaternion rot;
        };
    }

    template <typename T>
    class interpolator {
    public:
        FIELD( sys::list<T>*, list, Offsets::Interpolator::list );
        FIELD( T, last, Offsets::Interpolator::last );
    };

    class position_lerp {
    public:
        FIELD( rust::interpolator<rust::interpolation::transform_snapshot>*, interpolator, Offsets::PositionLerp::interpolator );
    };

    class model {
    public:
        FIELD( unity::transform*, eye_bone, Offsets::Model::eyeBone );
        FIELD( sys::array<unity::transform*>*, bone_transforms, Offsets::Model::boneTransforms );
        
        static inline il2cpp_object* type_object_;
    };

    struct obb {
        quaternion rotation;
        vector3 position;
        vector3 extents;
        vector3 forward;
        vector3 right;
        vector3 up;
        float reject;

        obb() = default;
        obb( const vector3& position, const vector3& scale, const quaternion& rotation, const unity::bounds& bounds ) {
            this->rotation = rotation;
            this->position = position + rotate_vector_by_quaternion( rotation, scale * bounds.center );
            this->extents = scale * bounds.extents;
            this->forward = rotate_vector_by_quaternion( rotation, vector3::forward );
            this->right = rotate_vector_by_quaternion( rotation, vector3::right );
            this->up = rotate_vector_by_quaternion( rotation, vector3::up );
            this->reject = vector3::sqr_magnitude( this->extents );
        }

        vector3 closest_point( const vector3& target ) {
            struct axis_test {
                vector3 direction;
                float extent;
                bool inside = false;
            };

            axis_test axes[] = {
                { this->right, this->extents.x },
                { this->up, this->extents.y },
                { this->forward, this->extents.z }
            };

            vector3 result = this->position;
            vector3 closest_point = target - this->position;

            for ( auto& axis : axes ) {
                float projection = vector3::dot( closest_point, axis.direction );

                if ( projection > axis.extent ) {
                    result += axis.direction * axis.extent;
                }

                else if ( projection < -axis.extent ) {
                    result -= axis.direction * axis.extent;
                }

                else {
                    result += axis.direction * projection;
                    axis.inside = true;
                }
            }

            for ( const auto& axis : axes ) {
                if ( !axis.inside ) {
                    return result;
                }
            }

            return target;
        }
    };

    class base_entity : public base_networkable {
    public:
        enum flag : int {
            placeholder = 1,
            on = 2,
            on_fire = 4,
            open = 8,
            locked = 16,
            debugging = 32,
            disabled = 64,
            reserved1 = 128,
            reserved2 = 256,
            reserved3 = 512,
            reserved4 = 1024,
            reserved5 = 2048,
            broken = 4096,
            busy = 8192,
            reserved6 = 16384,
            reserved7 = 32768,
            reserved8 = 65536,
            reserved9 = 131072,
            reserved10 = 262144,
            reserved11 = 524288,
            in_use = 1048576,
            reserved12 = 2097152,
            reserved13 = 4194304,
            unused_23 = 8388608,
            _protected = 16777216,
            transferring = 33554432,
            reserved14 = 67108864,
            reserved15 = 134217728,
            reserved16 = 268435456,
            reserved17 = 536870912,
            reserved18 = 1073741824,
            reserved19 = -2147483648
        };

        FIELD( rust::position_lerp*, position_lerp, Offsets::BaseEntity::positionLerp );
        FIELD( unity::bounds, bounds, Offsets::BaseEntity::bounds );
        FIELD( rust::model*, model, Offsets::BaseEntity::model );
        FIELD( int, flags, Offsets::BaseEntity::flags );

        bool has_flag( base_entity::flag f ) {
            return ( flags & f ) == f;
        }

        template <typename T>
        void write_arg( network::net_write* net_write, const T& value ) {
            if constexpr ( std::is_same_v<T, sys::string> ) {
                net_write->string( value );
            } else {
                net_write->write<T>( value );
            }
        }

        template <typename... Args>
        void server_rpc( const sys::string& name, Args... args ) {
            if ( !is_valid_ptr( net ) )
                return;

            network::client* client = network::net::static_fields_->cl;
            if ( !is_valid_ptr( client ) )
                return;

            network::net_write* net_write = client->start_write();
            if ( !is_valid_ptr( net_write ) )
                return;

            net_write->packet_id( network::message::type::rpc_message );
            net_write->write<networkable_id>( net->id );
            net_write->write<uint32_t>( string_pool::get( name ) );

            ( write_arg( net_write, args ), ... );

            net_write->send( network::send_info( client->connection ) );
        }

        vector3 get_world_velocity() {
            void ( *get_world_velocity )( vector3*, base_entity* ) =
                ( decltype( get_world_velocity ) )( game_assembly + Offsets::BaseEntity::GetWorldVelocity );

            um::caller& caller = um::get_caller_for_thread();

            vector3* world_velocity = caller.push<vector3>();
            caller( get_world_velocity, world_velocity, this );
            return *world_velocity;
        }

        obb world_space_bounds() {
            unity::transform* transform = this->get_transform();
            if ( !is_valid_ptr( transform ) )
                return obb();

            return obb( transform->get_position(), transform->get_lossy_scale(), transform->get_rotation(), bounds );
        }

        vector3 closest_point( const vector3& position ) {
            return world_space_bounds().closest_point( position );
        }

        float distance( const vector3& position ) {
            return vector3::magnitude( closest_point( position ) - position );
        }
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
        FIELD( vector3, new_velocity, Offsets::PlayerModel::newVelocity );
    };

    class player_input {
    public:
        FIELD( vector2, body_angles, Offsets::PlayerInput::bodyAngles );
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
                values[ i ] = ( ( ( values[ i ] ^ 0xE633D41A ) - 1884862503 ) << 10 )
                    | ( unsigned __int64 )( ( ( values[ i ] ^ 0xE633D41A ) - 1884862503 ) >> 22 );
            }
        );

        ENCRYPTED_VALUE( float, jump_time, Offsets::PlayerWalkMovement::jumpTime, {},
            {
                values[ i ] = ( ( ( values[ i ] ^ 0xCB6231F5 ) - 2001543673 ) << 9 )
                    | ( unsigned __int64 )( ( ( values[ i ] ^ 0xCB6231F5 ) - 2001543673 ) >> 23 );
            }
        );

        ENCRYPTED_VALUE( float, land_time, Offsets::PlayerWalkMovement::landTime, {},
            {
                uint32_t a = ( values[ i ] + 2004458784 ) ^ 0xE8F71746;

                values[ i ] = ( a << 24 ) | ( unsigned __int64 )( a >> 8 );
            }
        );

        ENCRYPTED_VALUE( float, ground_angle_new, Offsets::PlayerWalkMovement::groundAngleNew, {},
            {
                values[ i ] = ( ( ( ( values[ i ] + 363794016 ) << 11 ) |
                    ( ( unsigned int )( values[ i ] + 363794016 ) >> 21 ) ) + 1313402687 ) ^ 0xD9DC236ALL;
            }
        );

        ENCRYPTED_VALUE( float, next_sprint_time, Offsets::PlayerWalkMovement::nextSprintTime, {},
            {
                values[ i ] = ( ( ( values[ i ] << 9 ) | 
                    ( values[ i ] >> 23 ) ) - 2117961953 ) ^ 0xDF49665DLL;
            }
        );

        void teleport_to( const vector3& position, base_player* player ) {
            void ( *teleport_to )( player_walk_movement*, vector3*, base_player*  ) =
                ( decltype( teleport_to ) )( game_assembly + Offsets::PlayerWalkMovement::TeleportTo );

            um::caller& caller = um::get_caller_for_thread();

            vector3* _position = caller.push<vector3>( position );

            caller( teleport_to, this, _position, player );
        }

        static inline il2cpp_class* klass_;
    };

    class model_state {
    public:
        enum flag : int {
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

        bool has_flag( flag f ) {
            return ( flags & f ) == f;
        }

        void set_flag( flag f, bool b ) {
            if ( b ) {
                flags |= f;
            } else {
                flags &= ~f;
            }
        }
    };

    class player_eyes {
    public:
        // Yes, these are flipped and correct - fn(ret, this), not fn(this, ret)
        vector3 get_position() {
            void ( *get_position )( vector3*, player_eyes* ) = ( decltype( get_position ) )( game_assembly + Offsets::PlayerEyes::get_position );

            um::caller& caller = um::get_caller_for_thread();

            vector3* position = caller.push<vector3>();
            caller( get_position, position, this );
            return *position;
        }

        quaternion get_rotation() {
            void ( *get_rotation )( quaternion*, player_eyes* ) = ( decltype( get_rotation ) )( game_assembly + Offsets::PlayerEyes::get_rotation );

            um::caller& caller = um::get_caller_for_thread();

            quaternion* rotation = caller.push<quaternion>();
            caller( get_rotation, rotation, this );
            return *rotation;
        }

        vector3 body_forward() {
            return rotate_vector_by_quaternion( get_rotation(), vector3::forward );
        }

        static inline il2cpp_class* klass_;
        static inline il2cpp_object* type_object_;
    };

    class phrase {
    public:
        FIELD( sys::string*, legacy_english, Offsets::Translate_Phrase::legacyEnglish );
    };

    class item_definition : public unity::behaviour {
    public:
        FIELD( int, item_id, Offsets::ItemDefinition::itemid );
        FIELD( phrase*, display_name, Offsets::ItemDefinition::displayName );
        FIELD( unity::sprite*, icon_sprite, Offsets::ItemDefinition::iconSprite );
        FIELD( int, category, Offsets::ItemDefinition::category );
    };

    class item {
    public:
        FIELD( float, condition, Offsets::Item::_condition );
        FIELD( float, max_condition, Offsets::Item::_maxCondition );
        FIELD( item_definition*, info, Offsets::Item::info );
        FIELD( item_id, uid, Offsets::Item::uid );
        FIELD( int, amount, Offsets::Item::amount );
        FIELD( int, position, Offsets::Item::position );
        FIELD( item_container*, contents, Offsets::Item::contents );
        FIELD( entity_ref, world_entity, Offsets::Item::worldEnt );
        FIELD( entity_ref, held_entity, Offsets::Item::heldEntity );
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
        // BasePlayer.PlayerFlags
        enum flag {
            unused1 = 1,
            unused2 = 2,
            is_admin = 4,
            receiving_snapshot = 8,
            sleeping = 16,
            spectating = 32,
            wounded = 64,
            is_developer = 128,
            connected = 256,
            third_person_viewmode = 1024,
            eyes_viewmode = 2048,
            chat_mute = 4096,
            no_sprint = 8192,
            aiming = 16384,
            display_sash = 32768,
            relaxed = 65536,
            safe_zone = 131072,
            server_fall = 262144,
            incapacitated = 524288,
            workbench1 = 1048576,
            workbench2 = 2097152,
            workbench3 = 4194304,
            voice_range_boost = 8388608,
            modify_clan = 16777216,
            loading_after_transfer = 33554432,
            no_respawn_zone = 67108864,
            is_in_tutorial = 134217728,
            is_restrained = 268435456,
            creative_mode = 536870912,
            waiting_for_gesture_interaction = 1073741824,
            ragdolling = -2147483648
        };

        enum camera_mode {
            first_person,
            third_person,
            eyes,
            first_person_with_arms,
            death_cam_classic
        };

        FIELD( rust::player_model*, player_model, Offsets::BasePlayer::playerModel );
        FIELD( player_input*, input, Offsets::BasePlayer::input );
        FIELD( player_walk_movement*, movement, Offsets::BasePlayer::movement );
        FIELD( base_entity*, looking_at_entity, Offsets::BasePlayer::_lookingAtEntity );
        FIELD( uint64_t, current_team, Offsets::BasePlayer::currentTeam );

        ENCRYPTED_VALUE( uint64_t, cl_active_item, Offsets::BasePlayer::clActiveItem,
            {
                values[ i ] = ( ( ( values[ i ] ^ 0x71497B0A ) - 918352004 ) << 7 ) | 
                    ( ( ( values[ i ] ^ 0x71497B0Au ) - 918352004 ) >> 25 );
            }, {}
        );

        FIELD( rust::model_state*, model_state, Offsets::BasePlayer::modelState );
        FIELD( player_tick*, last_sent_tick, Offsets::BasePlayer::lastSentTick );
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

            return _wcstoui64( user_id_string->buffer, nullptr, 10 );
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
                item* _item = items->buffer[ i ];
                if ( !is_valid_ptr( _item ) )
                    continue;

                if ( _item->uid == active_item_id ) {
                    return _item;
                }
            }

            return nullptr;
        }

        held_entity* get_held_entity() {
            item* held_item = get_held_item();
            if ( !held_item )
                return nullptr;

            base_entity* _held_entity = held_item->held_entity.ent_cached;
            if ( !is_valid_ptr( _held_entity ) )
                return nullptr;

            return _held_entity->as<held_entity>();
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

        bool is_on_ground() {
            if ( !is_valid_ptr( model_state ) )
                return false;

            return model_state->has_flag( rust::model_state::flag::on_ground );
        }

        bool has_player_flag( flag f ) {
            return ( player_flags & f ) == f;
        }

        void set_player_flag( flag f, bool b ) {
            if ( b ) {
                player_flags |= f;
            } else {
                player_flags &= ~f;
            }
        }

        int32_t get_ideal_view_mode() {
            int32_t( *get_ideal_view_mode )( base_player* ) =
                ( decltype( get_ideal_view_mode ) )( game_assembly + Offsets::BasePlayer::get_idealViewMode );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_ideal_view_mode, this );
        }

        void send_projectile_update( player_projectile_update* update ) {
            void( *send_projectile_update )( base_player*, player_projectile_update* ) =
                ( decltype( send_projectile_update ) )( game_assembly + Offsets::BasePlayer::SendProjectileUpdate );

            um::caller& caller = um::get_caller_for_thread();

            return caller( send_projectile_update, this, update );
        }

        static float get_radius() {
            return 0.5f;
        }

        static float get_height( bool ducked ) {
            if ( ducked ) {
                return 1.1f;
            }

            return 1.8f;
        }

        static float get_jump_height() {
            return 1.5f;
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
        class punch_entry {
        public:
            FIELD( vector3, amount, Offsets::PunchEntry::amount );
            FIELD( float, duration, Offsets::PunchEntry::duration );
            FIELD( float, start_time, Offsets::PunchEntry::startTime );
            FIELD( vector3, amount_added, Offsets::PunchEntry::amountAdded );
        };

        FIELD( sys::list<punch_entry*>*, punches, Offsets::HeldEntity::_punches );

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

    class recoil_properties {
    public:
        FIELD( float, recoil_yaw_min, Offsets::RecoilProperties::recoilYawMin );
        FIELD( float, recoil_yaw_max, Offsets::RecoilProperties::recoilYawMax );
        FIELD( float, recoil_pitch_min, Offsets::RecoilProperties::recoilPitchMin );
        FIELD( float, recoil_pitch_max, Offsets::RecoilProperties::recoilPitchMax );
        FIELD( recoil_properties*, new_recoil_override, Offsets::RecoilProperties::newRecoilOverride );
    };

    class base_projectile : public attack_entity {
    public:
        class magazine {
        public:
            FIELD( int, capacity, Offsets::BaseProjectile_Magazine::capacity );
            FIELD( int, contents, Offsets::BaseProjectile_Magazine::contents );
            FIELD( item_definition*, ammo_type, Offsets::BaseProjectile_Magazine::ammoType );
        };

        FIELD( float, projectile_velocity_scale, Offsets::BaseProjectile::projectileVelocityScale );
        FIELD( bool, automatic, Offsets::BaseProjectile::automatic );
        FIELD( magazine*, primary_magazine, Offsets::BaseProjectile::primaryMagazine );
        FIELD( float, aim_sway, Offsets::BaseProjectile::aimSway );
        FIELD( float, aim_sway_speed, Offsets::BaseProjectile::aimSwaySpeed );
        FIELD( recoil_properties*, recoil, Offsets::BaseProjectile::recoil );;
        FIELD( float, aim_cone, Offsets::BaseProjectile::aimCone );
        FIELD( uint32_t, cached_mod_hash, Offsets::BaseProjectile::cachedModHash );
        FIELD( float, sight_aim_cone_scale, Offsets::BaseProjectile::sightAimConeScale );
        FIELD( float, sight_aim_cone_offset, Offsets::BaseProjectile::sightAimConeOffset );
        FIELD( float, hip_aim_cone_scale, Offsets::BaseProjectile::hipAimConeScale );
        FIELD( float, hip_aim_cone_offset, Offsets::BaseProjectile::hipAimConeOffset );

        float get_projectile_velocity_scale() {
            return projectile_velocity_scale;
        }

        static inline il2cpp_class* klass_;
    };

    class bow_weapon : public base_projectile {
    public:
        static inline il2cpp_class* klass_;
    };

    class compound_bow_weapon : public bow_weapon {
    public:
        FIELD( float, string_hold_duration_max, Offsets::CompoundBowWeapon::stringHoldDurationMax );		
        FIELD( float, string_bonus_velocity, Offsets::CompoundBowWeapon::stringBonusVelocity );
        
        float get_string_bonus_scale() {
            float ( *get_string_bonus_scale )( compound_bow_weapon* ) =
                ( decltype( get_string_bonus_scale ) )( game_assembly + Offsets::CompoundBowWeapon::GetStringBonusScale );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_string_bonus_scale, this );
        }

        float get_projectile_velocity_scale( bool get_max = false ) {
            float scale = get_max ? 1.f : get_string_bonus_scale();
            return projectile_velocity_scale + string_bonus_velocity * scale;
        }

        static inline il2cpp_class* klass_;
    };

    class crossbow_weapon : public base_projectile {
    public:
        static inline il2cpp_class* klass_;
    };

    class mini_crossbow : public base_projectile {
    public:
        static inline il2cpp_class* klass_;
    };

    class flint_strike_weapon : public base_projectile {
    public:
        FIELD( recoil_properties*, strike_recoil, Offsets::FlintStrikeWeapon::strikeRecoil );
        FIELD( bool, did_spark_this_frame, Offsets::FlintStrikeWeapon::_didSparkThisFrame );

        static inline il2cpp_class* klass_;
    };

    class spin_up_weapon : public base_projectile {
    public:
        static inline il2cpp_class* klass_;
    };

    class base_launcher : public base_projectile {
    public:
        static inline il2cpp_class* klass_;
    };

    namespace convar {
        class debugging {
        public:
            static void debugcamera() {
                void ( *debugcamera )( void* ) =
                    ( decltype( debugcamera ) )( game_assembly + Offsets::ConVar_Debugging::debugcamera );

                um::caller& caller = um::get_caller_for_thread();

                return caller( debugcamera, nullptr );
            }

            static void noclip() {
                void ( *noclip )( void* ) =
                    ( decltype( noclip ) )( game_assembly + Offsets::ConVar_Debugging::noclip );

                um::caller& caller = um::get_caller_for_thread();

                return caller( noclip, nullptr );
            }
        };

        class graphics {
        public:
            class static_fields {
            public:
                ENCRYPTED_VALUE( float, fov, Offsets::ConVar_Graphics_Static::_fov, {},
                    {
                        values[ i ] = ( ( ( ( ( values[ i ] << 28 ) | ( values[ i ] >> 4 ) ) + 1102425063 ) << 13 ) |
                            ( ( ( ( values[ i ] << 28 ) | ( values[ i ] >> 4 ) ) + 1102425063 ) >> 19 ) ) ^ 0x747AE41DLL;
                    }
                );
            };

            static inline static_fields* static_fields_;
        };
    }

    class outline_manager {
    public:
        static inline il2cpp_class* klass_;
    };

    class projectile_shoot {
    public:
        class projectile {
        public:
            FIELD( vector3, start_position, Offsets::ProtoBuf_ProjectileShoot_Projectile::startPos );
            FIELD( vector3, start_velocity, Offsets::ProtoBuf_ProjectileShoot_Projectile::startVel );
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

        static player_projectile_update* create() {
            return ( player_projectile_update* )il2cpp_object_new( player_projectile_update::klass_ );
        }

        void dispose() {
            void ( *dispose )( player_projectile_update* ) =
                ( decltype( dispose ) )( game_assembly + Offsets::ProtoBuf_PlayerProjectileUpdate::Dispose );

            um::caller& caller = um::get_caller_for_thread();

            return caller( dispose, this );
        }

        static inline il2cpp_class* klass_;
    };

    class attack {
    public:
        FIELD( vector3, point_start, Offsets::ProtoBuf_Attack::pointStart );
        FIELD( vector3, point_end, Offsets::ProtoBuf_Attack::pointEnd );
        FIELD( networkable_id, hit_id, Offsets::ProtoBuf_Attack::hitID );
        FIELD( uint32_t, hit_bone, Offsets::ProtoBuf_Attack::hitBone );
        FIELD( vector3, hit_normal_local, Offsets::ProtoBuf_Attack::hitNormalLocal );
        FIELD( vector3, hit_position_local, Offsets::ProtoBuf_Attack::hitPositionLocal );
        FIELD( vector3, hit_normal_world, Offsets::ProtoBuf_Attack::hitNormalWorld );
        FIELD( vector3, hit_position_world, Offsets::ProtoBuf_Attack::hitPositionWorld );
        FIELD( uint32_t, hit_part_id, Offsets::ProtoBuf_Attack::hitPartID );
        FIELD( uint32_t, hit_material_id, Offsets::ProtoBuf_Attack::hitMaterialID );
        FIELD( networkable_id, src_parent_id, Offsets::ProtoBuf_Attack::srcParentID );
        FIELD( networkable_id, dst_parent_id, Offsets::ProtoBuf_Attack::dstParentID );
    };

    class player_attack {
    public:
        FIELD( rust::attack*, attack, Offsets::ProtoBuf_PlayerAttack::attack );
    };

    class player_projectile_attack {
    public:
        FIELD( rust::player_attack*, player_attack, Offsets::ProtoBuf_PlayerProjectileAttack::playerAttack );

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
        FIELD( vector3, intermediate_position, Offsets::PlayerTick::intermediatePosition );

        static inline il2cpp_class* klass_;
    };

    class hit_test {
    public:
        FIELD( int32_t, type, Offsets::HitTest::type );
        FIELD( unity::ray, attack_ray, Offsets::HitTest::AttackRay );
        FIELD( float, max_distance, Offsets::HitTest::MaxDistance );
        FIELD( bool, did_hit, Offsets::HitTest::DidHit );
        FIELD( unity::game_object*, game_object, Offsets::HitTest::gameObject );
        FIELD( base_entity*, ignore_entity, Offsets::HitTest::ignoreEntity );
        FIELD( base_entity*, hit_entity, Offsets::HitTest::HitEntity );
        FIELD( vector3, hit_point, Offsets::HitTest::HitPoint );
        FIELD( vector3, hit_normal, Offsets::HitTest::HitNormal );
        FIELD( unity::transform*, hit_transform, Offsets::HitTest::HitTransform );
        FIELD( uint32_t, hit_part, Offsets::HitTest::HitPart );
        FIELD( sys::string*, hit_materal, Offsets::HitTest::HitMaterial );

    private:
        uint8_t _[ 256 ];
    };

    class projectile : public unity::behaviour {
    public:
        FIELD( vector3, initial_velocity, Offsets::Projectile::initialVelocity );
        FIELD( float, drag, Offsets::Projectile::drag );
        FIELD( float, gravity_modifier, Offsets::Projectile::gravityModifier );
        FIELD( float, thickness, Offsets::Projectile::thickness );
        FIELD( float, initial_distance, Offsets::Projectile::initialDistance );
        FIELD( vector3, swim_scale, Offsets::Projectile::swimScale );
        FIELD( vector3, swim_speed, Offsets::Projectile::swimSpeed );
        FIELD( base_player*, owner, Offsets::Projectile::owner );
        FIELD( projectile*, source_projectile_prefab, Offsets::Projectile::sourceProjectilePrefab );
        FIELD( rust::hit_test*, hit_test, Offsets::Projectile::hitTest );
        FIELD( float, integrity, Offsets::Projectile::integrity );
        FIELD( float, max_distance, Offsets::Projectile::maxDistance );
        FIELD( vector3, current_velocity, Offsets::Projectile::currentVelocity );
        FIELD( vector3, current_position, Offsets::Projectile::currentPosition );
        FIELD( float, traveled_distance, Offsets::Projectile::traveledDistance );
        FIELD( float, traveled_time, Offsets::Projectile::traveledTime );
        FIELD( float, launch_time, Offsets::Projectile::launchTime );
        FIELD( vector3, previous_position, Offsets::Projectile::previousPosition );
        FIELD( vector3, previous_velocity, Offsets::Projectile::previousVelocity );
        FIELD( float, previous_traveled_time, Offsets::Projectile::previousTraveledTime );
        FIELD( int, projectile_id, Offsets::Projectile::projectileID );
        FIELD( vector3, sent_position, Offsets::Projectile::sentPosition );

        void update_velocity( float delta_time ) {
            void( *update_velocity )( projectile*, float ) =
                ( decltype( update_velocity ) )( game_assembly + Offsets::Projectile::UpdateVelocity );

            um::caller& caller = um::get_caller_for_thread();

            caller( update_velocity, this, delta_time );
        }

        bool is_alive() {
            return integrity > 0.001f
                && max_distance > traveled_distance
                && traveled_time < 8.f;
        }

        void do_hit( rust::hit_test* test, const vector3& point, const vector3& normal ) {
            void ( *do_hit )( projectile*, rust::hit_test*, vector3*, vector3* ) = 
                ( decltype( do_hit ) )( game_assembly + Offsets::Projectile::DoHit );

            um::caller& caller = um::get_caller_for_thread();

            rust::hit_test* _test = caller.push<rust::hit_test>( *test );
            vector3* _point = caller.push<vector3>( point );
            vector3* _normal = caller.push<vector3>( normal );

            return caller( do_hit, this, _test, _point, _normal );
        }

        static inline il2cpp_class* klass_;
        static inline il2cpp_object* type_object_;
    };

    class local_player {
    public:
        static base_player* get_entity() {
            base_player* ( *get_entity )() = ( decltype( get_entity ) )( game_assembly + Offsets::LocalPlayer::get_Entity );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_entity );
        }

        static void item_command( uint64_t item_id, const sys::string& command ) {
            void ( *item_command )( uint64_t, sys::string* ) =
                ( decltype( item_command ) )( game_assembly + Offsets::LocalPlayer::ItemCommand );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* _command = caller.push<sys::string>( command );

            return caller( item_command, item_id, _command );
        }

        static void move_item( uint64_t item_id, uint64_t target_container, int32_t target_slot, int32_t amount ) {
            void ( *move_item )( uint64_t, uint64_t, int32_t, int32_t ) =
                ( decltype( move_item ) )( game_assembly + Offsets::LocalPlayer::MoveItem );

            um::caller& caller = um::get_caller_for_thread();

            return caller( move_item, item_id, target_container, target_slot, amount );
        }
    };

    class item_icon : public unity::behaviour {
    public:
        FIELD( unity::image*, background_image, Offsets::ItemIcon::backgroundImage );

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
        FIELD( float, ambient_multiplier, Offsets::TOD_NightParameters::AmbientMultiplier );
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

    class item_mod_projectile {
    public:
        FIELD( game_object_ref*, projectile_object, Offsets::ItemModProjectile::projectileObject );
        FIELD( int, ammo_type, Offsets::ItemModProjectile::ammoType );
        FIELD( float, projectile_spread, Offsets::ItemModProjectile::projectileSpread );
        FIELD( float, projectile_velocity, Offsets::ItemModProjectile::projectileVelocity );
        FIELD( float, projectile_velocity_spread, Offsets::ItemModProjectile::projectileVelocitySpread );

        float get_max_velocity() {
            return projectile_velocity + projectile_velocity_spread;
        }

        static inline il2cpp_object* type_object_;
    };

    class game_manifest {
    public:
        static unity::object* guid_to_object( sys::string* guid ) {
            unity::object* ( *guid_to_object )( sys::string* ) =
                ( decltype( guid_to_object ) )( game_assembly + Offsets::GameManifest::GUIDToObject );

            um::caller& caller = um::get_caller_for_thread();

            return caller( guid_to_object, guid );
        }
    };

    class projectile_weapon_mod : public base_entity {
    public:
        struct modifier {
            bool enabled;
            float scalar;
            float offset;
        };

        FIELD( modifier, repeat_delay, Offsets::ProjectileWeaponMod::repeatDelay );
        FIELD( modifier, projectile_velocity, Offsets::ProjectileWeaponMod::projectileVelocity );
        FIELD( modifier, projectile_damage, Offsets::ProjectileWeaponMod::projectileDamage );
        FIELD( modifier, projectile_distance, Offsets::ProjectileWeaponMod::projectileDistance );
        FIELD( modifier, aim_sway, Offsets::ProjectileWeaponMod::aimsway );
        FIELD( modifier, aim_sway_speed, Offsets::ProjectileWeaponMod::aimswaySpeed );
        FIELD( modifier, recoil, Offsets::ProjectileWeaponMod::recoil );
        FIELD( modifier, sight_aim_cone, Offsets::ProjectileWeaponMod::sightAimCone );
        FIELD( modifier, hip_aim_cone, Offsets::ProjectileWeaponMod::hipAimCone );
        FIELD( bool, needs_on_for_effects, Offsets::ProjectileWeaponMod::needsOnForEffects );

        static inline il2cpp_class* klass_;
    };
    
    class game_physics {
    public:
        class static_fields {
        public:
            FIELD( sys::array<unity::raycast_hit>*, hit_buffer, Offsets::GamePhysics_Static::hitBuffer );
        };

        static bool trace( unity::ray ray, float radius, unity::raycast_hit* hit_info, float max_distance, int layer_mask, int query_trigger_interaction, base_entity* ignore_entity ) {
            bool ( *trace )( unity::ray*, float, unity::raycast_hit*, float, int, int, base_entity* ) =
                ( decltype( trace ) )( game_assembly + Offsets::GamePhysics::Trace );

            um::caller& caller = um::get_caller_for_thread();

            unity::ray* _ray = caller.push<unity::ray>( ray );
            unity::raycast_hit* _hit_info = caller.push<unity::raycast_hit>();

            bool result = caller( trace, _ray, radius, _hit_info, max_distance, layer_mask, query_trigger_interaction, ignore_entity );

            if ( hit_info ) {
                *hit_info = *_hit_info;
            }

            return result;
        }

        static bool line_of_sight( vector3 p0, vector3 p1, int32_t layer_mask ) {
            return !trace( unity::ray( p0, p1 - p0 ), 0.f, nullptr, vector3::distance( p0, p1 ), layer_mask, unity::query_trigger_interaction::ignore, nullptr );
        }

        static inline static_fields* static_fields_;
    };

    class antihack {
    public:
        static inline float projectile_forgiveness = 0.495f; /* 0.5f */

        static inline float flyhack_extrusion = 2.f;
        static inline float flyhack_margin = 0.1f;
        static inline float flyhack_forgiveness_vertical = 1.f;
        static inline float flyhack_forgiveness_horizontal = 1.5f;
    };

    class server_projectile {
    public:
        static inline int mask = 1237003025;
    };

    class steam_client_wrapper {
    public:
        // This function isn't labeled as static, but it doesn't use this
        static unity::texture* get_avatar_texture( uint64_t steam_id ) {
            unity::texture* ( *get_avatar_texture )( steam_client_wrapper*, uint64_t ) =
                ( decltype( get_avatar_texture ) )( game_assembly + Offsets::SteamClientWrapper::GetAvatarTexture );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_avatar_texture, nullptr, steam_id );
        }
    };

    // These following classes are wrapped in this parent class to give much needed context when in use
    class console_system {
    public:
        class command {
        public:
            FIELD( sys::action*, set_override, Offsets::ConsoleSystem_Command::SetOveride );
            FIELD( sys::action*, call, Offsets::ConsoleSystem_Command::Call );
        };

        struct option {
        public:
            FIELD( bool, is_from_server, Offsets::ConsoleSystem_Option::IsFromServer );

        private:
            uint8_t _[ 64 ];
        };

        class arg : public il2cpp_object {
        public:
            FIELD( rust::console_system::option, option, Offsets::ConsoleSystem_Arg::Option );

            static inline il2cpp_class* klass_;
        };

        class index {
        public:
            class client {
            public:
                static command* find( sys::string* name ) {
                    command* ( *find )( sys::string* ) =
                        ( decltype( find ) )( game_assembly + Offsets::ConsoleSystem_Index_Client::Find );

                    um::caller& caller = um::get_caller_for_thread();

                    return caller( find, name );
                }
            };
        };
    };

    class patrol_helicopter {
    public:
        static inline il2cpp_class* klass_;
    };

    class effect : public il2cpp_object {
    public:
        FIELD( vector3, world_pos, Offsets::Effect::worldPos );
        FIELD( sys::string*, pooled_string, Offsets::Effect::pooledString );

        static inline il2cpp_class* klass_;
    };

    class effect_network {
    public:
        class static_fields {
        public:
            FIELD( rust::effect*, effect, Offsets::EffectNetwork_Static::effect );
        };

        static inline static_fields* static_fields_;
    };

    class world {
    public:
        class static_fields {
        public:
            FIELD( int, size, Offsets::World_Static::_size );
        };

        static inline static_fields* static_fields_;
    };

    class map_helper {
    public:
        static vector2i position_to_grid( vector3 position ) {
            int world_size = world::static_fields_->size;
            float num = 146.28572f;
            int num2 = ( int )( world_size / num + 0.001f );
            float num3 = ( float )( ( uint32_t )world_size / ( uint32_t )( ( long )num2 ) );
            vector2 vec = vector2( ( float )( -( float )( ( uint32_t )world_size ) ) / 2.f, world_size / 2.f );
            vector2 vec2 = vector2( position.x - vec.x, vec.y - position.z );
            int x = ( int )( vec2.x / num3 );
            int y = ( int )( vec2.y / num3 );
            return vector2i( x, y );
        }

        static const char* grid_to_string( vector2i grid, char* buffer, size_t size ) {
            grid.x = unity::mathf::max( grid.x, 0 );
            int i = grid.x + 1;
            int buffer_index = 0;
            while ( i > 0 ) {
                i--;
                if ( buffer_index < size - 1 ) {
                    buffer[ buffer_index++ ] = ( char )( 'A' + i % 26 );
                }
                i /= 26;
            }
            for ( int start = 0, end = buffer_index - 1; start < end; ++start, --end ) {
                char temp = buffer[ start ];
                buffer[ start ] = buffer[ end ];
                buffer[ end ] = temp;
            }
            if ( buffer_index < size - 1 ) {
                buffer[ buffer_index++ ] = '\0';
                snprintf( buffer + buffer_index - 1, size - buffer_index + 1, S( "%d" ), grid.y );
            }
            else {
                buffer[ size - 1 ] = '\0';
            }
            return buffer;
        }
    };

    class buttons {
    public:
        class con_button {
        public:
            FIELD( bool, is_down, Offsets::Buttons_ConButton::IsDown );
        };

        class static_fields {
        public:
            FIELD( con_button*, use, Offsets::Buttons_Static::Use );
        };

        static inline static_fields* static_fields_;
    };

    class ui_belt {
    public:
        FIELD( sys::list<item_icon*>*, item_icons, Offsets::UIBelt::ItemIcons );

        static inline il2cpp_class* klass_;
    };

    class lootable_corpse {
    public:
        FIELD( uint64_t, player_steam_id, Offsets::LootableCorpse::playerSteamID );
        FIELD( sys::string*, player_name, Offsets::LootableCorpse::_playerName );
    };

    class player_corpse : public lootable_corpse {
    public:
        static inline il2cpp_class* klass_;
    };

    class dropped_item_container {
    public:
        FIELD( uint64_t, player_steam_id, Offsets::DroppedItemContainer::playerSteamID );
        FIELD( sys::string*, player_name, Offsets::DroppedItemContainer::_playerName );

        static inline il2cpp_class* klass_;
    };

    class buffer_stream {
    public:
        FIELD( sys::array<uint8_t>*, buffer, Offsets::BufferStream::_buffer );
    };

    class loot_panel {
    public:
        static item_container* get_container_00() {
            item_container* ( *get_container_00 )() =
                ( decltype( get_container_00 ) )( game_assembly + Offsets::LootPanel::get_Container_00 );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_container_00 );
        }
    };

#define BYTE_TO_FLOAT( b ) ( float )b * 0.003921569f
#define FLOAT_TO_BYTE( f ) ( uint8_t )f * 255.999f;
#define SHORT_TO_FLOAT( s ) ( float )s * 3.051944E-05f;

    template <typename T>
    class terrain_map {
    public:
        FIELD( int, res, Offsets::TerrainMap::res );
        FIELD( unity::collections::native_array<T>, src, Offsets::TerrainMap::src );

        int index( float normalized, int res ) {
            int num = ( int )( normalized * ( float )res );
            if ( num < 0 ) {
                return 0;
            }

            else if ( num <= res - 1 ) {
                return num;
            }

            return res - 1;
        }
    };

    class terrain_height_map : public terrain_map<uint16_t> {
    public:
        FIELD( float, norm_y, Offsets::TerrainHeightMap::normY );

        float get_height( float norm_x, float norm_z, vector3 terrain_position, vector3 terrain_size, int res, uint16_t* height_map ) {
            return terrain_position.y + get_height_01( norm_x, norm_z, res, height_map ) * terrain_size.y;
        }

        float get_height_01( float norm_x, float norm_z, int res, uint16_t* height_map ) {
            int num = res - 1;
            float num2 = norm_x * ( float )num;
            float num3 = norm_z * ( float )num;
            int num4 = unity::mathf::clamp( ( int )num2, 0, num );
            int num5 = unity::mathf::clamp( ( int )num3, 0, num );
            int num6 = unity::mathf::min( num4 + 1, num );
            int num7 = unity::mathf::min( num5 + 1, num );
            float height = get_height_01( num4, num5, res, height_map );
            float height2 = get_height_01( num6, num5, res, height_map );
            float height3 = get_height_01( num4, num7, res, height_map );
            float height4 = get_height_01( num6, num7, res, height_map );
            float num8 = num2 - ( float )num4;
            float num9 = num3 - ( float )num5;
            float num10 = unity::mathf::lerp( height, height2, num8 );
            float num11 = unity::mathf::lerp( height3, height4, num8 );
            return unity::mathf::lerp( num10, num11, num9 );
        }

        float get_height_01( int x, int z, int res, uint16_t* height_map ) {
            int index = z * res + x; 
            return SHORT_TO_FLOAT( height_map[ index ] );
        }

        vector3 get_normal( float norm_x, float norm_z, int res, uint16_t* height_map, float norm_y ) {
            int num = res - 1;
            float num2 = norm_x * ( float )num;
            float num3 = norm_z * ( float )num;
            int num4 = unity::mathf::clamp( ( int )num2, 0, num );
            int num5 = unity::mathf::clamp( ( int )num3, 0, num );
            int num6 = unity::mathf::min( num4 + 1, num );
            int num7 = unity::mathf::min( num5 + 1, num );
            vector3 normal = get_normal( num4, num5, res, height_map, norm_y );
            vector3 normal2 = get_normal( num6, num5, res, height_map, norm_y );
            vector3 normal3 = get_normal( num4, num7, res, height_map, norm_y );
            vector3 normal4 = get_normal( num6, num7, res, height_map, norm_y );
            float num8 = num2 - ( float )num4;
            float num9 = num3 - ( float )num5;
            vector3 vector = vector3::slerp( normal, normal2, num8 );
            vector3 vector2 = vector3::slerp( normal3, normal4, num8 );
            return vector3::normalize( vector3::slerp( vector, vector2, num9 ) );
        }

        vector3 get_normal( int x, int z, int res, uint16_t* height_map, float norm_y ) {
            int num = res - 1;
            int num2 = unity::mathf::clamp( x - 1, 0, num );
            int num3 = unity::mathf::clamp( z - 1, 0, num );
            int num4 = unity::mathf::clamp( x + 1, 0, num );
            int num5 = unity::mathf::clamp( z + 1, 0, num );
            float num6 = ( get_height_01( num4, num3, res, height_map ) - get_height_01( num2, num3, res, height_map ) ) * 0.5f;
            float num7 = ( get_height_01( num2, num5, res, height_map ) - get_height_01( num2, num3, res, height_map ) ) * 0.5f;
            return vector3::normalize( vector3( -num6, norm_y, -num7 ) );
        }
    };

    class terrain_splat_map : public terrain_map<uint8_t> {
    public:
        float get_splat( float norm_x, float norm_z, int mask, int res, uint8_t* splat_map ) {
            int num = res - 1;
            float num2 = norm_x * ( float )num;
            float num3 = norm_z * ( float )num;
            int num4 = unity::mathf::clamp( ( int )num2, 0, num );
            int num5 = unity::mathf::clamp( ( int )num3, 0, num );
            int num6 = unity::mathf::min( num4 + 1, num );
            int num7 = unity::mathf::min( num5 + 1, num );
            float num8 = unity::mathf::lerp( get_splat( num4, num5, mask, res, splat_map ), get_splat( num6, num5, mask, res, splat_map ), num2 - ( float )num4 );
            float num9 = unity::mathf::lerp( get_splat( num4, num7, mask, res, splat_map ), get_splat( num6, num7, mask, res, splat_map ), num2 - ( float )num4 );
            return unity::mathf::lerp( num8, num9, num3 - ( float )num5 );
        }

        float get_splat( int x, int z, int mask, int res, uint8_t* splat_map ) {
            int index = ( mask * res + z ) * res + x;
            return BYTE_TO_FLOAT( splat_map[ index ] );
        }
    };

    class terrain_topology_map : public terrain_map<int32_t> {
    public:
        int get_topology( float norm_x, float norm_z, float radius, vector3 terrain_one_over_size, int res, int32_t* topology_map ) {
            int num = 0;
            float num2 = terrain_one_over_size.x * radius;
            float num3 = radius * radius;
            int num4 = index( norm_x, res );
            int num5 = index( norm_z, res );
            int num6 = index( norm_x - num2, res );
            int num7 = index( norm_x + num2, res );
            int num8 = index( norm_z - num2, res );
            int num9 = index( norm_z + num2, res );
            for ( int i = num8; i <= num9; i++ ) {
                int num10 = i - num5;
                int num11 = num10 * num10;
                for ( int j = num6; j <= num7; j++ ) {
                    int num12 = j - num4;
                    if ( ( float )( num12 * num12 + num11 ) <= num3 ) {
                        num |= topology_map[ i * res + j ];
                    }
                }
            }

            return num;
        }
    };

    class terrain_texturing {
    public:
        FIELD( float, terrain_size, Offsets::TerrainTexturing::terrainSize );
        FIELD( int, shore_map_size, Offsets::TerrainTexturing::shoreMapSize );
        FIELD( float, shore_distance_scale, Offsets::TerrainTexturing::shoreDistanceScale );
        FIELD( unity::collections::native_array<vector4>, shore_vectors, Offsets::TerrainTexturing::shoreVectors );

        std::pair<vector3, float> get_coarse_vector_to_shore( vector2 uv, int shore_map_size, vector4* shore_vectors, float shore_distance_scale ) {
            int num = shore_map_size;
            int num2 = num - 1;
            float num3 = uv.x * ( float )num2;
            float num4 = uv.y * ( float )num2;
            int num5 = ( int )num3;
            int num6 = ( int )num4;
            float num7 = num3 - ( float )num5;
            float num8 = num4 - ( float )num6;
            num5 = ( ( num5 >= 0 ) ? num5 : 0 );
            num6 = ( ( num6 >= 0 ) ? num6 : 0 );
            num5 = ( ( num5 <= num2 ) ? num5 : num2 );
            num6 = ( ( num6 <= num2 ) ? num6 : num2 );
            int num9 = ( ( num3 < ( float )num2 ) ? 1 : 0 );
            int num10 = ( ( num4 < ( float )num2 ) ? num : 0 );
            int num11 = num6 * num + num5;
            int num12 = num11 + num9;
            int num13 = num11 + num10;
            int num14 = num13 + num9;
            vector4 xyz = shore_vectors[ num11 ];
            vector4 xyz2 = shore_vectors[ num12 ];
            vector4 xyz3 = shore_vectors[ num13 ];
            vector4 xyz4 = shore_vectors[ num14 ];
            vector3 vector;
            vector.x = ( xyz2.x - xyz.x ) * num7 + xyz.x;
            vector.y = ( xyz2.y - xyz.y ) * num7 + xyz.y;
            vector.z = ( xyz2.z - xyz.z ) * num7 + xyz.z;
            vector3 vector2;
            vector2.x = ( xyz4.x - xyz3.x ) * num7 + xyz3.x;
            vector2.y = ( xyz4.y - xyz3.y ) * num7 + xyz3.y;
            vector2.z = ( xyz4.z - xyz3.z ) * num7 + xyz3.z;
            float num15 = ( vector2.x - vector.x ) * num8 + vector.x;
            float num16 = ( vector2.y - vector.y ) * num8 + vector.y;
            float num17 = ( vector2.z - vector.z ) * num8 + vector.z;
            return { vector3( num15, 0.f, num16 ), num17 * shore_distance_scale };
        }
    };

    class terrain_meta {
    public:
        class static_fields {
        public:
            FIELD( vector3, position, Offsets::TerrainMeta::Position );
            FIELD( vector3, size, Offsets::TerrainMeta::Size );
            FIELD( vector3, one_over_size, Offsets::TerrainMeta::OneOverSize );
            FIELD( terrain_height_map*, height_map, Offsets::TerrainMeta::HeightMap );
            FIELD( terrain_splat_map*, splat_map, Offsets::TerrainMeta::SplatMap );
            FIELD( terrain_topology_map*, topology_map, Offsets::TerrainMeta::TopologyMap );
            FIELD( terrain_texturing*, texturing, Offsets::TerrainMeta::Texturing );
        };

        static inline static_fields* static_fields_;
    };

    class cursor_manager {
    public:
        class static_fields {
        public:
            FIELD( int, i_hold_open, 0x0 );
            FIELD( int, i_previous_open, 0x4 );
        };

        static inline static_fields* static_fields_;
    };

    enum building_grade {
        twigs,
        wood,
        stone,
        metal,
        top_tier
    };

    class building_block : public base_combat_entity {
    public:
        FIELD( int, grade, Offsets::BuildingBlock::grade );

        bool has_upgrade_privilege( int grade, uint64_t skin, base_player* player ) {
            bool ( *has_upgrade_privilege )( building_block*, int, uint64_t, base_player* ) =
                ( decltype( has_upgrade_privilege ) )( game_assembly + Offsets::BuildingBlock::HasUpgradePrivilege );

            um::caller& caller = um::get_caller_for_thread();

            return caller( has_upgrade_privilege, this, grade, skin, player );
        }

        bool can_afford_upgrade( int grade, uint64_t skin, base_player* player ) {
            bool ( *can_afford_upgrade )( building_block*, int, uint64_t, base_player* ) =
                ( decltype( can_afford_upgrade ) )( game_assembly + Offsets::BuildingBlock::CanAffordUpgrade );

            um::caller& caller = um::get_caller_for_thread();

            return caller( can_afford_upgrade, this, grade, skin, player );
        }

        static inline il2cpp_class* klass_;
    };

    class base_view_model : public unity::behaviour {
    public:
        FIELD( bool, use_view_model_camera, Offsets::BaseViewModel::useViewModelCamera );

        static base_view_model* get_active_model() {
            base_view_model*( *get_active_model )( ) = ( decltype( get_active_model ) )( game_assembly + Offsets::BaseViewModel::get_ActiveModel );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_active_model );
        }
    };
}
