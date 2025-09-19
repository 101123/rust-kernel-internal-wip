#pragma once

#include "global.h"
#include "cheat/sdk/offsets.h"
#include "cheat/sdk/field_types.h"
#include "cheat/sdk/il2cpp.h"
#include "um.h"

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
    class list {
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
    enum key_code {
        a = 97, b = 98, c = 99, d = 100, e = 101,
        f = 102, g = 103, h = 104, i = 105,
        j = 106, k = 107, l = 108, m = 109,
        n = 110, o = 111, p = 112, q = 113,
        r = 114, s = 115, t = 116, u = 117,
        v = 118, w = 119, x = 120, y = 121,
        z = 122,

        end = 279,

        f11 = 292
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

    struct render_target_identifier {
        static render_target_identifier* ctor( texture* tex ) {
            void( *ctor )( render_target_identifier*, texture* ) = 
                ( decltype( ctor ) )( game_assembly + Offsets::RenderTargetIdentifier::ctor );

            um::caller& caller = um::get_caller_for_thread();

            render_target_identifier* object = ( render_target_identifier* )il2cpp_object_new( render_target_identifier::s_klass );
            caller( ctor, object, tex );

            return object;
        }

        static inline il2cpp_class* s_klass;
    };

    class object : public il2cpp_object {
    public:
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

        FIELD( uintptr_t, cached_ptr, Offsets::Object::m_CachedPtr );
    };

    class game_object : public object {
    public:
        template <typename T>
        T* get_component() {
            T* ( *get_component )( game_object*, il2cpp_object* ) = ( decltype( get_component ) )( unity_player + Offsets::GameObject::GetComponent );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_component, this, T::s_type_object );
        }

        template <typename T>
        T* add_component() {
            T* ( *internal_add_component_with_type )( game_object*, il2cpp_object* ) = 
                ( decltype( internal_add_component_with_type ) )( unity_player + Offsets::GameObject::Internal_AddComponentWithType );

            um::caller& caller = um::get_caller_for_thread();

            return caller( internal_add_component_with_type, this, T::s_type_object );
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

        Vector3 get_position() {
            void ( *get_position_injected )( transform*, Vector3* ) = ( decltype( get_position_injected ) )( unity_player + Offsets::Transform::get_position_Injected );

            um::caller& caller = um::get_caller_for_thread();

            Vector3* position = caller.push<Vector3>();
            caller( get_position_injected, this, position );
            return *position;
        }
    };

    class camera : public object {
    public:
        class internal {
        public:
            FIELD( Matrix4x4, m_CullingMatrix, 0x30C );
            FIELD( int, m_CullingMask, 0x43C );
            FIELD( Vector3, m_LastPosition, 0x454 );
        };
    };

    class input {
    public:
        static Vector2 get_mouse_position() {
            Vector2* ( *get_mouse_position_injected )( Vector2* ) = decltype( get_mouse_position_injected )( unity_player + Offsets::Input::get_mousePosition_Injected );

            um::caller& caller = um::get_caller_for_thread();

            Vector2* mouse_position = caller.push<Vector2>();
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

        static bool get_key_down( int key ) {
            bool( *get_key_down_int )( int ) = ( decltype( get_key_down_int ) )( unity_player + Offsets::Input::GetKeyDownInt );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_key_down_int, key );
        }

        static bool get_key_up( int key ) {
            bool( *get_key_up_int )( int ) = ( decltype( get_key_up_int ) )( unity_player + Offsets::Input::GetKeyUpInt );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_key_up_int, key );
        }

        static bool get_key( int key ) {
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
        static int property_to_id( sys::string name ) {
            int ( *property_to_id )( sys::string* ) =
                ( decltype( property_to_id ) )( unity_player + Offsets::Shader::PropertyToID );

            um::caller& caller = um::get_caller_for_thread();

            sys::string* name_ = caller.push<sys::string>( name );

            return caller( property_to_id, name_ );
        }

        static inline il2cpp_object* s_type_object;
    };

    class material : public object {
    public:
        static material* ctor( shader* shader_ ) {
            void( *create_with_shader )( material*, shader* ) =
                ( decltype( create_with_shader ) )( unity_player + Offsets::Material::CreateWithShader );

            um::caller& caller = um::get_caller_for_thread();

            material* object = ( material* )il2cpp_object_new( material::s_klass );

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

        static inline il2cpp_class* s_klass;
        static inline il2cpp_object* s_type_object;
    };

    class renderer {
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
    };

    class command_buffer : public il2cpp_object {
    public:
        static command_buffer* ctor() {
            void( *ctor )( command_buffer* ) =
                ( decltype( ctor ) )( game_assembly + Offsets::CommandBuffer::ctor );

            um::caller& caller = um::get_caller_for_thread();

            command_buffer* object = ( command_buffer* )il2cpp_object_new( command_buffer::s_klass );
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

        static inline il2cpp_class* s_klass;
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

            return caller( load_asset_internal, this, name_, T::s_type_object );
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

    class base_networkable : public unity::component {
    public:
        class entity_realm {
        public:
            typedef sys::list_dictionary<uint64_t, base_networkable*>* T;
            HIDDEN_VALUE( T, entity_list, Offsets::BaseNetworkable_EntityRealm::entityList,
                {
                    values[ i ] = ( ( values[ i ] - 1535577983 ) ^ 0xB11ADB22 ) - 1978993725;
                }
            );
        };

        class static_fields {
        public:
            HIDDEN_VALUE( entity_realm*, client_entities, Offsets::BaseNetworkable_Static::clientEntities,
                {
                    values[ i ] = ( ( ( ( ( values[ i ] << 19 ) | ( values[ i ] >> 13 ) ) + 911315647 ) << 29 ) | 
                        ( ( ( ( values[ i ] << 19 ) | ( values[ i ] >> 13 ) ) + 911315647 ) >> 3 ) ) ^ 0x1D9F762B;
                }
            );
        };

        FIELD( uint32_t, prefab_id, Offsets::BaseNetworkable::prefabID );
        FIELD( networkable*, net, Offsets::BaseNetworkable::net );
        FIELD( base_entity*, parent_entity, Offsets::BaseNetworkable::parentEntity );
        FIELD( sys::list<base_entity*>*, children, Offsets::BaseNetworkable::children );
        
        static inline il2cpp_class* s_klass;
        static inline static_fields* s_static_fields;
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

    class main_camera {
    public:
        class static_fields {
        public:
            FIELD( unity::camera*, main_camera, Offsets::MainCamera::mainCamera );
        };

        static inline il2cpp_class* s_klass;
        static inline static_fields* s_static_fields;
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

    class base_movement {
    public:
        FIELD( Vector3, target_movement, Offsets::BaseMovement::TargetMovement );
        FIELD( base_player*, owner, Offsets::BaseMovement::Owner );
    };

    class player_walk_movement : public base_movement {
    public:
        static inline il2cpp_class* s_klass;
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
        static inline il2cpp_class* s_klass;
        static inline il2cpp_object* s_type_object;
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

        static inline il2cpp_class* s_klass;
        static inline il2cpp_object* s_type_object;
    };

    class base_player : public base_combat_entity {
    public:
        FIELD( rust::player_model*, player_model, Offsets::BasePlayer::playerModel );
        FIELD( player_input*, input, Offsets::BasePlayer::input );
        FIELD( player_walk_movement*, movement, Offsets::BasePlayer::movement );
        FIELD( uint64_t, current_team, Offsets::BasePlayer::currentTeam );

        ENCRYPTED_VALUE( uint64_t, cl_active_item, Offsets::BasePlayer::clActiveItem,
            {
                values[ i ] = ( ( ( values[ i ] << 9 ) | ( values[ i ] >> 23 ) ) + 2090236210 ) ^ 0xCF2B9AF;
            }, {}
        );

        FIELD( rust::model_state*, model_state, Offsets::BasePlayer::modelState );
        FIELD( int, player_flags, Offsets::BasePlayer::playerFlags );

        ENCRYPTED_VALUE( uint64_t, user_id, Offsets::BasePlayer::userID,
            {
                values[ i ] = ( ( ( values[ i ] + 2124885473 ) << 16 ) | 
                    ( ( unsigned int )( values[ i ] + 2124885473 ) >> 16 ) ) + 73061426;
            }, {}
        );

        FIELD( sys::string*, display_name, Offsets::BasePlayer::_displayName );

        float get_speed( float running, float ducking, float crawling ) {
            float ( *get_speed )( base_player*, float, float, float ) =
                ( decltype( get_speed ) )( game_assembly + Offsets::BasePlayer::GetSpeed );

            um::caller& caller = um::get_caller_for_thread();

            return caller( get_speed, this, running, ducking, crawling );
        }

        player_eyes* get_eyes() {
            unity::game_object* game_object = get_game_object();
            if ( !is_valid_ptr( game_object ) )
                return nullptr;

            return game_object->get_component<rust::player_eyes>();
        }

        player_inventory* get_inventory() {
            unity::game_object* game_object = get_game_object();
            if ( !is_valid_ptr( game_object ) )
                return nullptr;

            return game_object->get_component<rust::player_inventory>();
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

            // The list contains the actual count, not the underlying array
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

        static inline il2cpp_class* s_klass;
    };

    class scientist_npc : public base_player {
    public:
        static inline il2cpp_class* s_klass;
    };

    class tunnel_dweller : public base_player {
    public:
        static inline il2cpp_class* s_klass;
    };

    class underwater_dweller : public base_player {
    public:
        static inline il2cpp_class* s_klass;
    };

    class scarecrow_npc : public base_player {
    public:
        static inline il2cpp_class* s_klass;
    };

    class gingerbread_npc : public base_player {
    public:
        static inline il2cpp_class* s_klass;
    };

    class held_entity : public base_entity {
    public:
        static inline il2cpp_class* s_klass;
        static inline il2cpp_object* s_type_object;
    };

    class attack_entity : public held_entity {
    public:
        static inline il2cpp_class* s_klass;
    };

    class base_melee : public attack_entity {
    public:
        static inline il2cpp_class* s_klass;
    };

    class base_projectile : public attack_entity {
    public:
        static inline il2cpp_class* s_klass;
    };

    class graphics {
    public:
        class static_fields {
        public:
            ENCRYPTED_VALUE( float, fov, Offsets::ConVar_Graphics_Static::_fov, {},
                {
                    values[ i ] = ( ( ( ( values[ i ] ^ 0x6474F8E ) << 10 ) | 
                        ( ( values[ i ] ^ 0x6474F8Eu ) >> 22 ) ) ^ 0x1640A091 ) + 988246765;
                }
            );
        };

        static inline static_fields* s_static_fields;
    };

    class outline_manager {
    public:
        static inline il2cpp_class* s_klass;
    };

    class projectile_shoot {
    public:
        class projectile {
        public:
            FIELD( Vector3, start_pos, Offsets::ProtoBuf_ProjectileShoot_Projectile::startPos );
            FIELD( Vector3, start_vel, Offsets::ProtoBuf_ProjectileShoot_Projectile::startVel );
        };

        FIELD( sys::list<projectile*>*, projectiles, Offsets::ProtoBuf_ProjectileShoot::projectiles );

        static inline il2cpp_class* s_klass;
    };

    class player_projectile_update {
    public:
        FIELD( int, projectile_id, Offsets::ProtoBuf_PlayerProjectileUpdate::projectileID );
        FIELD( Vector3, cur_position, Offsets::ProtoBuf_PlayerProjectileUpdate::curPosition );
        FIELD( Vector3, cur_velocity, Offsets::ProtoBuf_PlayerProjectileUpdate::curVelocity );
        FIELD( float, travel_time, Offsets::ProtoBuf_PlayerProjectileUpdate::travelTime );
        FIELD( bool, should_pool, Offsets::ProtoBuf_PlayerProjectileUpdate::ShouldPool );

        static inline il2cpp_class* s_klass;
    };

    class player_projectile_attack {
    public:
        static inline il2cpp_class* s_klass;
    };

    class input_message {
    public:

    };

    class player_tick {
    public:
        FIELD( input_message*, input_state, Offsets::PlayerTick::inputState );
        FIELD( Vector3, position, Offsets::PlayerTick::position );
        FIELD( rust::model_state*, model_state, Offsets::PlayerTick::modelState );
        FIELD( uint64_t, active_item, Offsets::PlayerTick::activeItem );
        FIELD( Vector3, eye_pos, Offsets::PlayerTick::eyePos );
        FIELD( uint64_t, parent_id, Offsets::PlayerTick::parentID );

        static inline il2cpp_class* s_klass;
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

        static inline il2cpp_class* s_klass;
    };
}
