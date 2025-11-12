#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x6913111f;
		constexpr const static size_t gc_handles = 0xd38cdd0;
		constexpr const static size_t il2cpp_resolve_icall = 0x5bcd70;
		constexpr const static size_t il2cpp_array_new = 0x5bcd90;
		constexpr const static size_t il2cpp_assembly_get_image = 0x26920;
		constexpr const static size_t il2cpp_class_from_name = 0x5bcf00;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x5bd210;
		constexpr const static size_t il2cpp_class_get_type = 0x5bd2b0;
		constexpr const static size_t il2cpp_domain_get = 0x5bd810;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x5bd830;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x5be0f0;
		constexpr const static size_t il2cpp_gchandle_new = 0x5be0a0;
		constexpr const static size_t il2cpp_gchandle_free = 0x5be190;
		constexpr const static size_t il2cpp_method_get_name = 0x39f0;
		constexpr const static size_t il2cpp_object_new = 0x5be840;
		constexpr const static size_t il2cpp_type_get_object = 0x5bf030;
	}

#define Object_TypeDefinitionIndex 17059

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xadf5240;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 17030

	namespace GameObject {

		// Functions
		constexpr const static size_t SetActive = 0xfc850;
		constexpr const static size_t Internal_AddComponentWithType = 0xfbc60;
		constexpr const static size_t GetComponent = 0xf96d0;
		constexpr const static size_t GetComponentCount = 0x6a3f0;
		constexpr const static size_t GetComponentInChildren = 0xfa820;
		constexpr const static size_t GetComponentInParent = 0xfaba0;
		constexpr const static size_t GetComponentsInternal = 0xfaf30;
		constexpr const static size_t Internal_CreateGameObject = 0xff2b0;
		constexpr const static size_t get_layer = 0x77100;
		constexpr const static size_t get_tag = 0xfce00;
		constexpr const static size_t get_transform = 0xfc270;
	}

#define Component_TypeDefinitionIndex 17017

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 17011

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 17094

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xae00e80;
		constexpr const static size_t GetChild = 0x115600;
		constexpr const static size_t GetParent = 0x111e60;
		constexpr const static size_t GetRoot = 0x113f70;
		constexpr const static size_t InverseTransformDirection_Injected = 0x113150;
		constexpr const static size_t InverseTransformPoint_Injected = 0x113cb0;
		constexpr const static size_t InverseTransformVector_Injected = 0x1136d0;
		constexpr const static size_t GetPositionAndRotation = 0x1127f0;
		constexpr const static size_t SetLocalPositionAndRotation_Injected = 0x112650;
		constexpr const static size_t SetPositionAndRotation_Injected = 0x112510;
		constexpr const static size_t TransformDirection_Injected = 0x112e90;
		constexpr const static size_t TransformPoint_Injected = 0x1139f0;
		constexpr const static size_t TransformVector_Injected = 0x113410;
		constexpr const static size_t get_childCount = 0x773b0;
		constexpr const static size_t get_localPosition_Injected = 0x111170;
		constexpr const static size_t get_localRotation_Injected = 0x111920;
		constexpr const static size_t get_localScale_Injected = 0x111be0;
		constexpr const static size_t get_lossyScale_Injected = 0x114e80;
		constexpr const static size_t get_position_Injected = 0x110ef0;
		constexpr const static size_t get_rotation_Injected = 0x111670;
		constexpr const static size_t set_localPosition_Injected = 0x1112b0;
		constexpr const static size_t set_localRotation_Injected = 0x111aa0;
		constexpr const static size_t set_localScale_Injected = 0x111d20;
		constexpr const static size_t set_position_Injected = 0x111030;
		constexpr const static size_t set_rotation_Injected = 0x1117e0;
	}

#define Camera_TypeDefinitionIndex 16809

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
		constexpr const static size_t GetAllCamerasCount = 0x72b30;
		constexpr const static size_t CopyFrom = 0x73ce0;
		constexpr const static size_t set_cullingMask = 0x67710;
		constexpr const static size_t set_clearFlags = 0x692c0;
		constexpr const static size_t set_backgroundColor_Injected = 0x69040;
		constexpr const static size_t set_targetTexture = 0x6d950;
		constexpr const static size_t Render = 0x73270;
		constexpr const static size_t RenderWithShader = 0x733b0;
	}

#define Time_TypeDefinitionIndex 17081

	namespace Time {

		// Functions
		constexpr const static size_t get_deltaTime = 0x10f8e0;
		constexpr const static size_t get_fixedDeltaTime = 0x10f9a0;
		constexpr const static size_t get_fixedTime = 0x10f8f0;
		constexpr const static size_t get_frameCount = 0x10fc80;
		constexpr const static size_t get_realtimeSinceStartup = 0x10fca0;
		constexpr const static size_t get_smoothDeltaTime = 0x10fa80;
		constexpr const static size_t get_time = 0x10f870;
	}

#define Material_TypeDefinitionIndex 16872

	namespace Material {

		// Functions
		constexpr const static size_t SetFloatImpl = 0xb6da0;
		constexpr const static size_t SetColorImpl_Injected = 0xb6ee0;
		constexpr const static size_t SetTextureImpl = 0xb7140;
		constexpr const static size_t CreateWithMaterial = 0xaf1c0;
		constexpr const static size_t CreateWithShader = 0xaf050;
		constexpr const static size_t SetBufferImpl = 0xb7490;
		constexpr const static size_t set_shader = 0xaf740;
		constexpr const static size_t get_shader = 0xaf5e0;
	}

#define MaterialPropertyBlock_TypeDefinitionIndex 16868

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xadb4df0;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16871

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xadb89d0;
		constexpr const static size_t PropertyToID = 0xaa6a0;
		constexpr const static size_t GetPropertyCount = 0xaea30;
		constexpr const static size_t GetPropertyName = 0xad8f0;
		constexpr const static size_t GetPropertyType = 0xadb90;
	}

#define Mesh_TypeDefinitionIndex 16927

	namespace Mesh {

		// Functions
		constexpr const static size_t Internal_Create = 0xcba60;
		constexpr const static size_t MarkDynamicImpl = 0xd6cc0;
		constexpr const static size_t ClearImpl = 0xd6790;
		constexpr const static size_t set_subMeshCount = 0xd5900;
		constexpr const static size_t SetVertexBufferParamsFromPtr = 0xcc4d0;
		constexpr const static size_t SetIndexBufferParams = 0xcbf50;
		constexpr const static size_t InternalSetVertexBufferData = 0xcc7d0;
		constexpr const static size_t InternalSetIndexBufferData = 0xcc1c0;
		constexpr const static size_t SetAllSubMeshesAtOnceFromNativeArray = 0xd63a0;
		constexpr const static size_t UploadMeshDataImpl = 0xd6f70;
	}

#define Renderer_TypeDefinitionIndex 16869

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterial = 0x9ffe0;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16930

	namespace Texture {

		// Functions
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16932

	namespace Texture2D {

		// Functions
		constexpr const static size_t ctor = 0xadcea60;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define Sprite_TypeDefinitionIndex 17100

	namespace Sprite {

		// Functions
		constexpr const static size_t get_texture = 0x119300;
	}

#define RenderTexture_TypeDefinitionIndex 16937

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xadd7690;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17407

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae1b070;
		constexpr const static size_t Clear = 0x12f580;
		constexpr const static size_t SetRenderTargetSingle_Internal_Injected = 0x138fc0;
		constexpr const static size_t ClearRenderTarget_Injected = 0x132050;
		constexpr const static size_t SetViewport_Injected = 0x131020;
		constexpr const static size_t SetViewProjectionMatrices_Injected = 0x136ef0;
		constexpr const static size_t EnableScissorRect_Injected = 0x131190;
		constexpr const static size_t DisableScissorRect = 0x131300;
		constexpr const static size_t Internal_DrawProceduralIndexedIndirect_Injected = 0x130300;
		constexpr const static size_t Internal_DrawMesh_Injected = 0x12f610;
		constexpr const static size_t Internal_DrawRenderer = 0x12f990;
	}

#define RenderTargetIdentifier_TypeDefinitionIndex 17383

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xae153c0;
	}

#define ComputeBuffer_TypeDefinitionIndex 17072

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xadf8de0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xadf9030;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16876

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xadbfa40;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xadbf770;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 22268

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xae3d8e0;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16849

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16960

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24797

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16846

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24675

	namespace Input {

		// Functions
		constexpr const static size_t get_mousePosition_Injected = 0x221990;
		constexpr const static size_t get_mouseScrollDelta_Injected = 0x221a90;
		constexpr const static size_t GetMouseButtonDown = 0x220c30;
		constexpr const static size_t GetMouseButtonUp = 0x220d00;
		constexpr const static size_t GetMouseButton = 0x220b30;
		constexpr const static size_t GetKeyDownInt = 0x220a60;
		constexpr const static size_t GetKeyUpInt = 0x220990;
		constexpr const static size_t GetKeyInt = 0x220880;
	}

#define Application_TypeDefinitionIndex 16792

	namespace Application {

		// Functions
		constexpr const static size_t get_version = 0x5f350;
		constexpr const static size_t Quit = 0x5d790;
		constexpr const static size_t get_isFocused = 0x5ddc0;
	}

#define Gradient_TypeDefinitionIndex 16958

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23649

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xae83460;
		constexpr const static size_t RaycastNonAlloc = 0xae85b30;
		constexpr const static size_t CheckCapsule = 0xae873e0;
	}

#define Image_TypeDefinitionIndex 21228

	namespace Image {

		// Offsets
		constexpr const static size_t m_Sprite = 0xd0;
	}

#define GraphicsSettings_TypeDefinitionIndex 17405

	namespace GraphicsSettings {

		// Functions
		constexpr const static size_t get_INTERNAL_defaultRenderPipeline = 0x127f00;
	}

#define Cursor_TypeDefinitionIndex 16947

	namespace Cursor {

		// Functions
		constexpr const static size_t get_visible = 0xed7a0;
	}

#define BaseNetworkable_TypeDefinitionIndex 4389

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x58;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x40;
	}

	// obf name: ::%e24d140708fb6596151556472b34dce8ef6ecf0c
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%e24d140708fb6596151556472b34dce8ef6ecf0c"
#define BaseNetworkable_Static_ClassNameShort "%e24d140708fb6596151556472b34dce8ef6ecf0c"
#define BaseNetworkable_Static_TypeDefinitionIndex 4388

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x8;
	}

	// obf name: ::%66323faacf2159c1b2f4947a5b1f230c0bd2b466
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%66323faacf2159c1b2f4947a5b1f230c0bd2b466"
#define BaseNetworkable_EntityRealm_ClassNameShort "%66323faacf2159c1b2f4947a5b1f230c0bd2b466"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 4386

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x2e3a380;
	}

	// obf name: ::%78763bea9997b581199e7acecd70d97c15158239
#define System_ListDictionary_ClassName "%78763bea9997b581199e7acecd70d97c15158239<%098306a25a5044cc572e348a0456e98bb3f02729,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%78763bea9997b581199e7acecd70d97c15158239"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x6c7d3c0;
		constexpr const static size_t TryGetValue_methodinfo = 0xd005710;
	}

	// obf name: ::%a4f7c601540fa233340e31e3a251c0d9af21b4e0
#define System_BufferList_ClassName "%a4f7c601540fa233340e31e3a251c0d9af21b4e0<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%a4f7c601540fa233340e31e3a251c0d9af21b4e0"
#define System_BufferList_TypeDefinitionIndex -1

	namespace System_BufferList {

		// Offsets
		constexpr const static size_t count = 0x18;
		constexpr const static size_t buffer = 0x10;
	}

	// obf name: ::SingletonComponent`1
#define SingletonComponent_ClassName "SingletonComponent<MainCamera>"
#define SingletonComponent_ClassNameShort "SingletonComponent`1"
#define SingletonComponent_TypeDefinitionIndex -1

	namespace SingletonComponent {

		// Offsets
		constexpr const static size_t Instance = 0x48;
	}

#define Model_TypeDefinitionIndex 3339

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t eyeBone = 0x38;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 493

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0x90;
		constexpr const static size_t positionLerp = 0x100;

		// Functions
		constexpr const static size_t ServerRPC = 0x2c55290;
		constexpr const static size_t FindBone = 0x2c5e830;
		constexpr const static size_t GetWorldVelocity = 0x2c93a40;
		constexpr const static size_t GetParentVelocity = 0x2c64de0;
	}

	// obf name: ::%7ee7c7ccbc97168d644522051a8d9a638526c4ee
#define PositionLerp_ClassName "%7ee7c7ccbc97168d644522051a8d9a638526c4ee"
#define PositionLerp_ClassNameShort "%7ee7c7ccbc97168d644522051a8d9a638526c4ee"
#define PositionLerp_TypeDefinitionIndex 1493

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x38;
	}

	// obf name: ::%ee05c1732c9268a0a8ee605e9cef2d8bcee5d29a
#define Interpolator_ClassName "%ee05c1732c9268a0a8ee605e9cef2d8bcee5d29a<%101a5910c4bb2b5069c9fdb77f7f9ad0a02cd16a>"
#define Interpolator_ClassNameShort "%ee05c1732c9268a0a8ee605e9cef2d8bcee5d29a"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 5657

	namespace BaseCombatEntity {

		// Offsets
		constexpr const static size_t skeletonProperties = 0x1c8;
		constexpr const static size_t baseProtection = 0x1d0;
		constexpr const static size_t lifestate = 0x23c;
		constexpr const static size_t markAttackerHostile = 0x242;
		constexpr const static size_t _health = 0x248;
		constexpr const static size_t _maxHealth = 0x24c;
		constexpr const static size_t lastNotifyFrame = 0x258;
	}

#define SkeletonProperties_TypeDefinitionIndex 6665

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 6663

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 3598

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 3597

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%49fbc04a01434ad5bacdc41af8545264d5cabb6a
#define DamageTypeList_ClassName "%49fbc04a01434ad5bacdc41af8545264d5cabb6a"
#define DamageTypeList_ClassNameShort "%49fbc04a01434ad5bacdc41af8545264d5cabb6a"
#define DamageTypeList_TypeDefinitionIndex 6171

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 5965

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 4852

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x40;
		constexpr const static size_t iconSprite = 0x50;
		constexpr const static size_t category = 0x58;
		constexpr const static size_t stackable = 0x78;
		constexpr const static size_t rarity = 0x90;
		constexpr const static size_t condition = 0xb8;
		constexpr const static size_t ItemModWearable = 0x170;
	}

#define RecoilProperties_TypeDefinitionIndex 806

	namespace RecoilProperties {

		// Offsets
		constexpr const static size_t recoilYawMin = 0x18;
		constexpr const static size_t recoilYawMax = 0x1c;
		constexpr const static size_t recoilPitchMin = 0x20;
		constexpr const static size_t recoilPitchMax = 0x24;
		constexpr const static size_t overrideAimconeWithCurve = 0x5c;
		constexpr const static size_t aimconeProbabilityCurve = 0x70;
		constexpr const static size_t newRecoilOverride = 0x80;
	}

#define BaseProjectile_Magazine_Definition_TypeDefinitionIndex 5001

	namespace BaseProjectile_Magazine_Definition {

		// Offsets
		constexpr const static size_t builtInSize = 0x0;
	}

#define BaseProjectile_Magazine_TypeDefinitionIndex 5002

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t definition = 0x10;
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 5616

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x3a8b5a0;
		constexpr const static size_t StartAttackCooldown = 0x3a87790;
	}

#define BaseProjectile_TypeDefinitionIndex 5007

	namespace BaseProjectile {

		// Offsets
		constexpr const static size_t projectileVelocityScale = 0x2e4;
		constexpr const static size_t automatic = 0x2e8;
		constexpr const static size_t reloadTime = 0x328;
		constexpr const static size_t primaryMagazine = 0x330;
		constexpr const static size_t fractionalReload = 0x338;
		constexpr const static size_t aimSway = 0x34c;
		constexpr const static size_t aimSwaySpeed = 0x350;
		constexpr const static size_t recoil = 0x358;
		constexpr const static size_t aimconeCurve = 0x360;
		constexpr const static size_t aimCone = 0x368;
		constexpr const static size_t hipAimCone = 0x36c;
		constexpr const static size_t noAimingWhileCycling = 0x385;
		constexpr const static size_t isBurstWeapon = 0x38f;
		constexpr const static size_t cachedModHash = 0x3c0;
		constexpr const static size_t sightAimConeScale = 0x3c4;
		constexpr const static size_t sightAimConeOffset = 0x3c8;
		constexpr const static size_t hipAimConeScale = 0x3cc;
		constexpr const static size_t hipAimConeOffset = 0x3d0;

		// Functions
		constexpr const static size_t LaunchProjectile = 0x349ecd0;
		constexpr const static size_t LaunchProjectileClientSide = 0x349ef60;
		constexpr const static size_t ScaleRepeatDelay = 0x349b0c0;
		constexpr const static size_t GetAimCone = 0x34a3ed0;
		constexpr const static size_t GetAimCone_vtableoff = 0x4068;
		constexpr const static size_t UpdateAmmoDisplay = 0x3498460;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3ec8;
	}

#define BaseLauncher_TypeDefinitionIndex 4533

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 4930

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%d1192a78ab4a34ed95c396962a5891a69b9a9038
#define HitTest_ClassName "%d1192a78ab4a34ed95c396962a5891a69b9a9038"
#define HitTest_ClassNameShort "%d1192a78ab4a34ed95c396962a5891a69b9a9038"
#define HitTest_TypeDefinitionIndex 7

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x8c;
		constexpr const static size_t AttackRay = 0xac;
		constexpr const static size_t RayHit = 0x10;
		constexpr const static size_t damageProperties = 0x80;
		constexpr const static size_t gameObject = 0xa0;
		constexpr const static size_t collider = 0xd0;
		constexpr const static size_t ignoredTypes = 0x60;
		constexpr const static size_t HitTransform = 0x50;
		constexpr const static size_t HitPart = 0x78;
		constexpr const static size_t HitMaterial = 0x58;
		constexpr const static size_t DidHit = 0x3c;
		constexpr const static size_t MaxDistance = 0x48;
		constexpr const static size_t HitNormal = 0x6c;
		constexpr const static size_t HitPoint = 0x90;
		constexpr const static size_t ignoreEntity = 0x40;
		constexpr const static size_t HitEntity = 0xc8;
	}

#define Projectile_TypeDefinitionIndex 420

	namespace Projectile {

		// Offsets
		constexpr const static size_t initialVelocity = 0x28;
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t thickness = 0x3c;
		constexpr const static size_t initialDistance = 0x44;
		constexpr const static size_t swimScale = 0xf0;
		constexpr const static size_t swimSpeed = 0xfc;
		constexpr const static size_t owner = 0x1e0;
		constexpr const static size_t sourceProjectilePrefab = 0x1d0;
		constexpr const static size_t mod = 0x110;
		constexpr const static size_t hitTest = 0x120;
		constexpr const static size_t launchTime = 0x174;
		constexpr const static size_t currentVelocity = 0x154;
		constexpr const static size_t currentPosition = 0x160;
		constexpr const static size_t maxDistance = 0x138;
		constexpr const static size_t traveledDistance = 0x16c;
		constexpr const static size_t traveledTime = 0x170;
		constexpr const static size_t previousTraveledTime = 0x19c;
		constexpr const static size_t sentPosition = 0x178;
		constexpr const static size_t previousPosition = 0x184;
		constexpr const static size_t previousVelocity = 0x190;
		constexpr const static size_t integrity = 0x134;

		// Functions
		constexpr const static size_t CalculateEffectScale = 0x255be60;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x418;
		constexpr const static size_t SetEffectScale = 0x2534fd0;
		constexpr const static size_t UpdateVelocity = 0x252a6f0;
		constexpr const static size_t Retire = 0x253c9d0;
		constexpr const static size_t DoHit = 0x2559200;
	}

	// obf name: ::%1671fffcb5ee642648a31fcc87f518da4325bfa3
#define HitInfo_ClassName "%1671fffcb5ee642648a31fcc87f518da4325bfa3"
#define HitInfo_ClassNameShort "%1671fffcb5ee642648a31fcc87f518da4325bfa3"
#define HitInfo_TypeDefinitionIndex 6188

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x98;
		constexpr const static size_t damageTypes = 0x18;

		// Functions
		constexpr const static size_t get_boneArea = 0x41389c0;
	}

	// obf name: ::%ce7a29d1dd9dc7c28eee55b7427136ee2df5c2d7
#define GameTrace_ClassName "%ce7a29d1dd9dc7c28eee55b7427136ee2df5c2d7"
#define GameTrace_ClassNameShort "%ce7a29d1dd9dc7c28eee55b7427136ee2df5c2d7"
#define GameTrace_TypeDefinitionIndex 6930

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x49eba40;
	}

#define BaseMelee_TypeDefinitionIndex 3354

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x20db850;
		constexpr const static size_t DoThrow = 0x20de620;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 229

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x410;
		constexpr const static size_t strikeRecoil = 0x418;
		constexpr const static size_t _didSparkThisFrame = 0x420;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 1590

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x428;
		constexpr const static size_t stringBonusVelocity = 0x434;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0xbc92c0;
	}

	// obf name: ::%291fcc9d063986aab1d5d29df1fe654e71505230
#define ItemContainer_ClassName "%291fcc9d063986aab1d5d29df1fe654e71505230"
#define ItemContainer_ClassNameShort "%291fcc9d063986aab1d5d29df1fe654e71505230"
#define ItemContainer_TypeDefinitionIndex 5729

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x28;
		constexpr const static size_t itemList = 0x68;

		// Functions
		constexpr const static size_t GetSlot = 0x3c79b80;
	}

#define PlayerLoot_TypeDefinitionIndex 4900

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 6159

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerWear = 0x28;
		constexpr const static size_t containerMain = 0x60;
		constexpr const static size_t containerBelt = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x40dff20;
	}

#define PlayerEyes_TypeDefinitionIndex 5974

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x3ed1c20;
		constexpr const static size_t get_rotation = 0x3ebbe10;
		constexpr const static size_t set_rotation = 0x3ead830;
		constexpr const static size_t HeadForward = 0x3eb6c60;
	}

	// obf name: ::%66726173fbd049099b78b5fb2de318c870b24f71
#define PlayerEyes_Static_ClassName "PlayerEyes/%66726173fbd049099b78b5fb2de318c870b24f71"
#define PlayerEyes_Static_ClassNameShort "%66726173fbd049099b78b5fb2de318c870b24f71"
#define PlayerEyes_Static_TypeDefinitionIndex 5973

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x3c;
	}

	// obf name: ::%9eb36966bc3c5c65de6d06d6c9c8374ce8a97183
#define PlayerBelt_ClassName "%9eb36966bc3c5c65de6d06d6c9c8374ce8a97183"
#define PlayerBelt_ClassNameShort "%9eb36966bc3c5c65de6d06d6c9c8374ce8a97183"
#define PlayerBelt_TypeDefinitionIndex 5861

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x3dbe210;
		constexpr const static size_t GetActiveItem = 0x3db82f0;
	}

	// obf name: ::%d49418a7c4dcc6ab8f0fbc0d8abc9e0ba71113d4
#define LocalPlayer_ClassName "%d49418a7c4dcc6ab8f0fbc0d8abc9e0ba71113d4"
#define LocalPlayer_ClassNameShort "%d49418a7c4dcc6ab8f0fbc0d8abc9e0ba71113d4"
#define LocalPlayer_TypeDefinitionIndex 2514

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x1668a10;
		constexpr const static size_t MoveItem = 0x16726d0;
		constexpr const static size_t get_Entity = 0x1666b30;
	}

	// obf name: ::%1c3f3e015dc6a8d54507c3a6705e57aa818574ab
#define LocalPlayer_Static_ClassName "%d49418a7c4dcc6ab8f0fbc0d8abc9e0ba71113d4/%1c3f3e015dc6a8d54507c3a6705e57aa818574ab"
#define LocalPlayer_Static_ClassNameShort "%1c3f3e015dc6a8d54507c3a6705e57aa818574ab"
#define LocalPlayer_Static_TypeDefinitionIndex 2513

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x200;
	}

	// obf name: ::%66af625cc078d684001cd7c06f3230789f7b5cfe
#define BasePlayer_Static_ClassName "BasePlayer/%66af625cc078d684001cd7c06f3230789f7b5cfe"
#define BasePlayer_Static_ClassNameShort "%66af625cc078d684001cd7c06f3230789f7b5cfe"
#define BasePlayer_Static_TypeDefinitionIndex 2871

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x11a8;
	}

#define BasePlayer_TypeDefinitionIndex 2872

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x550;
		constexpr const static size_t input = 0x458;
		constexpr const static size_t movement = 0x400;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x270;
		constexpr const static size_t playerFlags = 0x5a8;
		constexpr const static size_t eyes = 0x5c8;
		constexpr const static size_t playerRigidbody = 0x2c8;
		constexpr const static size_t userID = 0x5f0;
		constexpr const static size_t UserIDString = 0x318;
		constexpr const static size_t inventory = 0x360;
		constexpr const static size_t _displayName = 0x350;
		constexpr const static size_t _lookingAt = 0x2f0;
		constexpr const static size_t lastSentTickTime = 0x564;
		constexpr const static size_t lastSentTick = 0x5b8;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x5d8;
		constexpr const static size_t _lookingAtEntity = 0x4b0;
		constexpr const static size_t currentGesture = 0x5e8;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x1a91e90;
		constexpr const static size_t Menu_AssistPlayer = 0x1a07850;
		constexpr const static size_t OnViewModeChanged = 0x19e25b0;
		constexpr const static size_t ChatMessage = 0x1ac6e80;
		constexpr const static size_t IsOnGround = 0x1a17330;
		constexpr const static size_t GetSpeed = 0x1b59360;
		constexpr const static size_t SendProjectileUpdate = 0x1aa9070;
		constexpr const static size_t CanBuild = 0x1ae0d80;
		constexpr const static size_t GetMounted = 0x1a98470;
		constexpr const static size_t GetHeldEntity = 0x1a961c0;
		constexpr const static size_t get_inventory = 0x1a72d60;
		constexpr const static size_t get_eyes = 0x1acf4b0;
		constexpr const static size_t SendClientTick = 0x1a40ed0;
		constexpr const static size_t ClientInput = 0x1a7f840;
		constexpr const static size_t ClientInput_vtableoff = 0x3bc8;
		constexpr const static size_t MaxHealth = 0x1a1f0b0;
		constexpr const static size_t MaxHealth_vtableoff = 0x1d98;
		constexpr const static size_t OnAttacked = 0x1b0a680;
		constexpr const static size_t OnAttacked_vtableoff = 0xe38;
		constexpr const static size_t get_idealViewMode = 0x1a2f870;
	}

#define ScientistNPC_TypeDefinitionIndex 1945

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 1607

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 5670

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 3769

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 93

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 5110

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 4827

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t Init = 0x323eba0;
		constexpr const static size_t BlockJump = 0x325e190;
		constexpr const static size_t BlockSprint = 0x3246560;
		constexpr const static size_t GroundCheck = 0x323b020;
		constexpr const static size_t ClientInput = 0x3248600;
		constexpr const static size_t ClientInput_vtableoff = 0x3d8;
		constexpr const static size_t DoFixedUpdate = 0x3244ad0;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x1b8;
		constexpr const static size_t FrameUpdate = 0x326c220;
		constexpr const static size_t FrameUpdate_vtableoff = 0x3f8;
		constexpr const static size_t TeleportTo = 0x32399e0;
		constexpr const static size_t TeleportTo_vtableoff = 0x238;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 6791

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 2709

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 992

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 5049

	namespace ProjectileWeaponMod {

		// Offsets
		constexpr const static size_t repeatDelay = 0x1c8;
		constexpr const static size_t projectileVelocity = 0x1d4;
		constexpr const static size_t projectileDamage = 0x1e0;
		constexpr const static size_t projectileDistance = 0x1ec;
		constexpr const static size_t aimsway = 0x1f8;
		constexpr const static size_t aimswaySpeed = 0x204;
		constexpr const static size_t recoil = 0x210;
		constexpr const static size_t sightAimCone = 0x21c;
		constexpr const static size_t hipAimCone = 0x228;
		constexpr const static size_t magazineCapacity = 0x23c;
		constexpr const static size_t needsOnForEffects = 0x248;
	}

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 5045

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%10f0671cb5dd7148fdc54e242b89e51bf4acdcb8
#define ConsoleSystem_ClassName "%10f0671cb5dd7148fdc54e242b89e51bf4acdcb8"
#define ConsoleSystem_ClassNameShort "%10f0671cb5dd7148fdc54e242b89e51bf4acdcb8"
#define ConsoleSystem_TypeDefinitionIndex 23602

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x62a5c30;
	}

	// obf name: ::%c93514fb1e834ec0db1cea819ee8a2b250bfd323
#define ConsoleSystem_Index_Static_ClassName "%10f0671cb5dd7148fdc54e242b89e51bf4acdcb8/%c57e089bcdcce47080a39527f5f66dfa7a68f085.%c93514fb1e834ec0db1cea819ee8a2b250bfd323"
#define ConsoleSystem_Index_Static_ClassNameShort "%c93514fb1e834ec0db1cea819ee8a2b250bfd323"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23595

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x78;
	}

#define LootableCorpse_TypeDefinitionIndex 3728

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2c8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 907

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 4839

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0xc0;
		constexpr const static size_t mainCameraTransform = 0x60;

		// Functions
		constexpr const static size_t Update = 0x32a5330;
		constexpr const static size_t OnPreCull = 0x32b0e30;
		constexpr const static size_t Trace = 0x32ac1f0;
	}

#define CameraMan_TypeDefinitionIndex 1502

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%8f1bf919eb255550a4f86fe3ac7951ed6195bbd1
#define PlayerTick_ClassName "%8f1bf919eb255550a4f86fe3ac7951ed6195bbd1"
#define PlayerTick_ClassNameShort "%8f1bf919eb255550a4f86fe3ac7951ed6195bbd1"
#define PlayerTick_TypeDefinitionIndex 7399

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x20;
		constexpr const static size_t modelState = 0x38;
		constexpr const static size_t activeItem = 0x18;
		constexpr const static size_t parentID = 0x40;
		constexpr const static size_t position = 0x28;
		constexpr const static size_t eyePos = 0x48;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x955a300;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x954ee10;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%c244fd8658d70d50cc7ce3e9d6448977d1ea318b
#define InputMessage_ClassName "%c244fd8658d70d50cc7ce3e9d6448977d1ea318b"
#define InputMessage_ClassNameShort "%c244fd8658d70d50cc7ce3e9d6448977d1ea318b"
#define InputMessage_TypeDefinitionIndex 7576

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x2c;
		constexpr const static size_t mouseDelta = 0x10;
		constexpr const static size_t aimAngles = 0x20;
	}

	// obf name: ::%0fab0faecdedde7b4956a9474849e2b341cd06f6
#define InputState_ClassName "%0fab0faecdedde7b4956a9474849e2b341cd06f6"
#define InputState_ClassNameShort "%0fab0faecdedde7b4956a9474849e2b341cd06f6"
#define InputState_TypeDefinitionIndex 1177

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x20;
		constexpr const static size_t previous = 0x10;
	}

#define PlayerInput_TypeDefinitionIndex 3455

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%6c058dd2eb8b72556c78c17e8461c0a2be178024
#define ModelState_ClassName "%6c058dd2eb8b72556c78c17e8461c0a2be178024"
#define ModelState_ClassNameShort "%6c058dd2eb8b72556c78c17e8461c0a2be178024"
#define ModelState_TypeDefinitionIndex 7348

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x2c;
		constexpr const static size_t waterLevel = 0x28;
		constexpr const static size_t lookDir = 0x70;
	}

	// obf name: ::%8016b155b4f1594b1720b9bd4612f832fb134af1
#define Item_ClassName "%8016b155b4f1594b1720b9bd4612f832fb134af1"
#define Item_ClassNameShort "%8016b155b4f1594b1720b9bd4612f832fb134af1"
#define Item_TypeDefinitionIndex 521

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x28;
		constexpr const static size_t uid = 0xe0;
		constexpr const static size_t clientAmmoCount = 0x80;
		constexpr const static size_t _condition = 0x98;
		constexpr const static size_t _maxCondition = 0xc8;
		constexpr const static size_t position = 0x24;
		constexpr const static size_t amount = 0xd0;
		constexpr const static size_t contents = 0x18;
		constexpr const static size_t parent = 0xc0;
		constexpr const static size_t heldEntity = 0x58;
		constexpr const static size_t worldEnt = 0xa8;

		// Functions
		constexpr const static size_t get_iconSprite = 0x2f63260;
	}

	// obf name: ::%201271282f7c693f781385474ef0d16ec4022bb5
#define WaterLevel_ClassName "%201271282f7c693f781385474ef0d16ec4022bb5"
#define WaterLevel_ClassNameShort "%201271282f7c693f781385474ef0d16ec4022bb5"
#define WaterLevel_TypeDefinitionIndex 1020

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x4ed2d20;
		constexpr const static size_t GetWaterLevel = 0x4ebab80;
	}

	// obf name: ::%98a5634a94d352af28c4cb47d7f652964ebce0e4
#define ConVar_Graphics_Static_ClassName "%b16327b208302c4af9b812f3c9d84d0c8811d548/%98a5634a94d352af28c4cb47d7f652964ebce0e4"
#define ConVar_Graphics_Static_ClassNameShort "%98a5634a94d352af28c4cb47d7f652964ebce0e4"
#define ConVar_Graphics_Static_TypeDefinitionIndex 2087

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x324;

		// Functions
		constexpr const static size_t _fov_getter = 0x2574bc0;
		constexpr const static size_t _fov_setter = 0x2597800;
	}

#define BaseFishingRod_TypeDefinitionIndex 4372

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x260;
		constexpr const static size_t currentBobber = 0x268;
		constexpr const static size_t MaxCastDistance = 0x284;
		constexpr const static size_t BobberPreview = 0x290;
		constexpr const static size_t clientStrainAmountNormalised = 0x2d0;
		constexpr const static size_t strainGainMod = 0x2f8;
		constexpr const static size_t aimAnimationReady = 0x2e8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x2db46a0;
		constexpr const static size_t EvaluateFishingPosition = 0x2dc19f0;
	}

#define FishingBobber_TypeDefinitionIndex 3116

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 1264

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x51570b0;
	}

	// obf name: ::%cff8cb7abf463eca00390c72592d7775f5bf6f1a
#define GameManager_ClassName "%cff8cb7abf463eca00390c72592d7775f5bf6f1a"
#define GameManager_ClassNameShort "%cff8cb7abf463eca00390c72592d7775f5bf6f1a"
#define GameManager_TypeDefinitionIndex 3629

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x10;

		// Functions
		constexpr const static size_t CreatePrefab = 0x23fa9d0;
	}

	// obf name: ::%d9adec66eb1372e6cb3105f4966362f5c9cadf5c
#define GameManager_Static_ClassName "%cff8cb7abf463eca00390c72592d7775f5bf6f1a/%d9adec66eb1372e6cb3105f4966362f5c9cadf5c"
#define GameManager_Static_ClassNameShort "%d9adec66eb1372e6cb3105f4966362f5c9cadf5c"
#define GameManager_Static_TypeDefinitionIndex 3628

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x10;
	}

	// obf name: ::%4d538b7466a94a591fe8864317760c8464683551
#define PrefabPoolCollection_ClassName "%4d538b7466a94a591fe8864317760c8464683551"
#define PrefabPoolCollection_ClassNameShort "%4d538b7466a94a591fe8864317760c8464683551"
#define PrefabPoolCollection_TypeDefinitionIndex 2667

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x18;
	}

	// obf name: ::%1563dfa550c391cc7b564c364e9b539fe36d4682
#define PrefabPool_ClassName "%1563dfa550c391cc7b564c364e9b539fe36d4682"
#define PrefabPool_ClassNameShort "%1563dfa550c391cc7b564c364e9b539fe36d4682"
#define PrefabPool_TypeDefinitionIndex 1519

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x18;
	}

#define ItemModProjectile_TypeDefinitionIndex 2939

	namespace ItemModProjectile {

		// Offsets
		constexpr const static size_t projectileObject = 0x20;
		constexpr const static size_t ammoType = 0x30;
		constexpr const static size_t projectileSpread = 0x38;
		constexpr const static size_t projectileVelocity = 0x3c;
		constexpr const static size_t projectileVelocitySpread = 0x40;
		constexpr const static size_t useCurve = 0x44;
		constexpr const static size_t spreadScalar = 0x48;
		constexpr const static size_t category = 0x60;
	}

#define CraftingQueue_TypeDefinitionIndex 4780

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%64e2e8c06c08861804058a06bc0863fa858354bb
#define CraftingQueue_Static_ClassName "CraftingQueue/%64e2e8c06c08861804058a06bc0863fa858354bb"
#define CraftingQueue_Static_ClassNameShort "%64e2e8c06c08861804058a06bc0863fa858354bb"
#define CraftingQueue_Static_TypeDefinitionIndex 4779

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x1a;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 7031

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%eeb9c69b845222fcb0d9040dc634863ad5ef53b8
#define Planner_Static_ClassName "Planner/%eeb9c69b845222fcb0d9040dc634863ad5ef53b8"
#define Planner_Static_ClassNameShort "%eeb9c69b845222fcb0d9040dc634863ad5ef53b8"
#define Planner_Static_TypeDefinitionIndex 2206

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x98;
	}

	// obf name: ::%471f40032c2cd1cf29ed5a559b9f6c91f6c08ba7
#define Planner_Guide_ClassName "Planner/%471f40032c2cd1cf29ed5a559b9f6c91f6c08ba7"
#define Planner_Guide_ClassNameShort "%471f40032c2cd1cf29ed5a559b9f6c91f6c08ba7"
#define Planner_Guide_TypeDefinitionIndex 2202

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x60;
	}

#define Planner_TypeDefinitionIndex 2207

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x270;
	}

#define Construction_TypeDefinitionIndex 6506

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x148;
	}

#define BuildingBlock_TypeDefinitionIndex 1147

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x318;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 6970

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x4a36db0;
	}

	// obf name: ::%d4ff8d1b2a59ca0fe2e735a6dce23c7944c45fd3
#define PunchEntry_ClassName "HeldEntity/%d4ff8d1b2a59ca0fe2e735a6dce23c7944c45fd3"
#define PunchEntry_ClassNameShort "%d4ff8d1b2a59ca0fe2e735a6dce23c7944c45fd3"
#define PunchEntry_TypeDefinitionIndex 6968

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x28;
		constexpr const static size_t startTime = 0x2c;
		constexpr const static size_t amountAdded = 0x10;
		constexpr const static size_t amount = 0x1c;
	}

#define IronSights_TypeDefinitionIndex 3740

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 4304

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 7089

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xe0;
		constexpr const static size_t model = 0xb8;
		constexpr const static size_t lower = 0xd0;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x4ba7660;
		constexpr const static size_t OnCameraPositionChanged = 0x4ba5c40;
		constexpr const static size_t OnCameraPositionChanged_vtableoff = 0x288;
	}

#define ViewModel_TypeDefinitionIndex 5626

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x3a93f30;
		constexpr const static size_t PlayString = 0x3a92410;
	}

#define MedicalTool_TypeDefinitionIndex 4886

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 3228

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x60;
	}

	// obf name: ::%27a1507ff0e44e79c3d2f41c580fd64d9b33cd04
#define WaterSystem_Static_ClassName "WaterSystem/%27a1507ff0e44e79c3d2f41c580fd64d9b33cd04"
#define WaterSystem_Static_ClassNameShort "%27a1507ff0e44e79c3d2f41c580fd64d9b33cd04"
#define WaterSystem_Static_TypeDefinitionIndex 5722

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x0;
	}

#define WaterSystem_TypeDefinitionIndex 5723

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x3c1f750;
	}

#define TerrainMeta_TypeDefinitionIndex 295

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x688;
		constexpr const static size_t HeightMap = 0xa0;
		constexpr const static size_t SplatMap = 0x520;
		constexpr const static size_t TopologyMap = 0x658;
		constexpr const static size_t Texturing = 0x5a0;
	}

#define TerrainCollision_TypeDefinitionIndex 2978

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x1c6b010;
	}

#define TerrainHeightMap_TypeDefinitionIndex 974

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 5677

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 6716

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%69a71773d3f6e09d78cfbe861cc5fa3418306165
#define World_Static_ClassName "%76715f05db082223753425d5f8a9ee9378a32161/%69a71773d3f6e09d78cfbe861cc5fa3418306165"
#define World_Static_ClassNameShort "%69a71773d3f6e09d78cfbe861cc5fa3418306165"
#define World_Static_TypeDefinitionIndex 2195

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x7c;
	}

#define ItemIcon_TypeDefinitionIndex 2629

	namespace ItemIcon {

		// Offsets
		constexpr const static size_t backgroundImage = 0xe8;

		// Functions
		constexpr const static size_t TryToMove = 0x17494e0;
		constexpr const static size_t TryToMove_vtableoff = 0x398;
		constexpr const static size_t RunTimedAction = 0x175f390;
	}

	// obf name: ::%fdb83a08afe36aa4834b0631407515c51f44c17d
#define ItemIcon_Static_ClassName "ItemIcon/%fdb83a08afe36aa4834b0631407515c51f44c17d"
#define ItemIcon_Static_ClassNameShort "%fdb83a08afe36aa4834b0631407515c51f44c17d"
#define ItemIcon_Static_TypeDefinitionIndex 2628

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x8;
	}

	// obf name: ::%f3d590fbd8480647e55ee84221617da65992b797
#define EffectData_ClassName "%f3d590fbd8480647e55ee84221617da65992b797"
#define EffectData_ClassNameShort "%f3d590fbd8480647e55ee84221617da65992b797"
#define EffectData_TypeDefinitionIndex 7386

	namespace EffectData {

		// Offsets
		constexpr const static size_t source = 0x20;
	}

	// obf name: ::%76dea61e7fd9a4e6637da14ec1476dc0ce5f6350
#define Effect_ClassName "%76dea61e7fd9a4e6637da14ec1476dc0ce5f6350"
#define Effect_ClassNameShort "%76dea61e7fd9a4e6637da14ec1476dc0ce5f6350"
#define Effect_TypeDefinitionIndex 3074

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0xa8;
		constexpr const static size_t worldPos = 0x74;
	}

	// obf name: ::%dd5bdb0b94747da135889bb823d43cfb39b4772a
#define EffectLibrary_ClassName "%dd5bdb0b94747da135889bb823d43cfb39b4772a"
#define EffectLibrary_ClassNameShort "%dd5bdb0b94747da135889bb823d43cfb39b4772a"
#define EffectLibrary_TypeDefinitionIndex 4375

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x2de8de0;
	}

	// obf name: ::%3581cb976b5bc8aa6801801c166c4a6b25a8e648
#define EffectNetwork_ClassName "%3581cb976b5bc8aa6801801c166c4a6b25a8e648"
#define EffectNetwork_ClassNameShort "%3581cb976b5bc8aa6801801c166c4a6b25a8e648"
#define EffectNetwork_TypeDefinitionIndex 732

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%a3b7016c1950f301e2be3d95999145268f778ff4
#define EffectNetwork_Static_ClassName "%3581cb976b5bc8aa6801801c166c4a6b25a8e648/%a3b7016c1950f301e2be3d95999145268f778ff4"
#define EffectNetwork_Static_ClassNameShort "%a3b7016c1950f301e2be3d95999145268f778ff4"
#define EffectNetwork_Static_TypeDefinitionIndex 731

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x18;

		// Functions
		constexpr const static size_t cctor = 0x4067d70;
	}

#define BuildingBlock_TypeDefinitionIndex 1147

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x5050a30;
		constexpr const static size_t HasUpgradePrivilege = 0x50362c0;
		constexpr const static size_t CanAffordUpgrade = 0x506a9a0;
	}

	// obf name: ::%5110d05a99e6c6d5ac54bc2fa1a432a28b6db224
#define GameObjectEx_ClassName "%5110d05a99e6c6d5ac54bc2fa1a432a28b6db224"
#define GameObjectEx_ClassNameShort "%5110d05a99e6c6d5ac54bc2fa1a432a28b6db224"
#define GameObjectEx_TypeDefinitionIndex 5604

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x3a7da10;
	}

#define UIDeathScreen_TypeDefinitionIndex 371

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x20ede20;
	}

	// obf name: ::%ce68584997c442fc8cad7c52bc284c30c54ae9c6
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%ce68584997c442fc8cad7c52bc284c30c54ae9c6"
#define BaseScreenShake_Static_ClassNameShort "%ce68584997c442fc8cad7c52bc284c30c54ae9c6"
#define BaseScreenShake_Static_TypeDefinitionIndex 1210

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x78;
	}

#define FlashbangOverlay_TypeDefinitionIndex 351

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x8;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%3f9bec337daf673e7478d3f5ce62adbafb7c62a0
#define StringPool_ClassName "%3f9bec337daf673e7478d3f5ce62adbafb7c62a0"
#define StringPool_ClassNameShort "%3f9bec337daf673e7478d3f5ce62adbafb7c62a0"
#define StringPool_TypeDefinitionIndex 2439

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x10;

		// Functions
		constexpr const static size_t Get = 0x1514620;
	}

	// obf name: ::%c5a94eb6d6f67c30227627252029c30530f767f7
#define Network_Networkable_ClassName "%c5a94eb6d6f67c30227627252029c30530f767f7"
#define Network_Networkable_ClassNameShort "%c5a94eb6d6f67c30227627252029c30530f767f7"
#define Network_Networkable_TypeDefinitionIndex 18757

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x20;
	}

	// obf name: ::%3a0799e51ac46cfeb2a4ee06197e3a9f9e4c7c97
#define Network_Net_ClassName "%3a0799e51ac46cfeb2a4ee06197e3a9f9e4c7c97"
#define Network_Net_ClassNameShort "%3a0799e51ac46cfeb2a4ee06197e3a9f9e4c7c97"
#define Network_Net_TypeDefinitionIndex 10080

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x8;
	}

	// obf name: ::%2c60280aa5174b0e7a74215bf29c03d73603c2c4
#define Network_Client_ClassName "%2c60280aa5174b0e7a74215bf29c03d73603c2c4"
#define Network_Client_ClassNameShort "%2c60280aa5174b0e7a74215bf29c03d73603c2c4"
#define Network_Client_TypeDefinitionIndex 18761

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf8;
		constexpr const static size_t ConnectedPort = 0x110;
		constexpr const static size_t ConnectedAddress = 0xd8;
		constexpr const static size_t ServerName = 0xe8;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x636bdb0;
		constexpr const static size_t DestroyNetworkable = 0x636b6a0;
	}

	// obf name: ::%d7b7d0101ea0612ec6c8f428570f1c7669f783a7
#define Network_BaseNetwork_ClassName "%d7b7d0101ea0612ec6c8f428570f1c7669f783a7"
#define Network_BaseNetwork_ClassNameShort "%d7b7d0101ea0612ec6c8f428570f1c7669f783a7"
#define Network_BaseNetwork_TypeDefinitionIndex 18739

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x63212f0;
	}

	// obf name: ::%cd45767e2bd25aaf253385545641dcd4ad1e2517
#define Network_SendInfo_ClassName "%cd45767e2bd25aaf253385545641dcd4ad1e2517"
#define Network_SendInfo_ClassNameShort "%cd45767e2bd25aaf253385545641dcd4ad1e2517"
#define Network_SendInfo_TypeDefinitionIndex 18751

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%e1afd20100f1be760731c347795748f4c17f095e
#define Network_Message_ClassName "%e1afd20100f1be760731c347795748f4c17f095e"
#define Network_Message_ClassNameShort "%e1afd20100f1be760731c347795748f4c17f095e"
#define Network_Message_TypeDefinitionIndex 18766

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%c98fc297a3a4b8aebb2053d3b13f521eff4cda36
#define Network_NetRead_ClassName "%c98fc297a3a4b8aebb2053d3b13f521eff4cda36"
#define Network_NetRead_ClassNameShort "%c98fc297a3a4b8aebb2053d3b13f521eff4cda36"
#define Network_NetRead_TypeDefinitionIndex 18787

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x38;
	}

	// obf name: ::%db3fe2b8a7bac2d3a5d6d6e22840eedb135466ce
#define Network_NetWrite_ClassName "%db3fe2b8a7bac2d3a5d6d6e22840eedb135466ce"
#define Network_NetWrite_ClassNameShort "%db3fe2b8a7bac2d3a5d6d6e22840eedb135466ce"
#define Network_NetWrite_TypeDefinitionIndex 18741

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x40;

		// Functions
		constexpr const static size_t WriteByte = 0x6339480;
		constexpr const static size_t String = 0x6336400;
		constexpr const static size_t Send = 0x633d7a0;
	}

#define LootPanel_TypeDefinitionIndex 3968

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x29221c0;
	}

#define UIInventory_TypeDefinitionIndex 5288

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x3788160;
	}

#define GrowableEntity_TypeDefinitionIndex 4355

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 1105

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 1104

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 21299

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 8266

	namespace TOD_Sky {

		// Offsets
		constexpr const static size_t Cycle = 0x40;
		constexpr const static size_t Atmosphere = 0x50;
		constexpr const static size_t Day = 0x58;
		constexpr const static size_t Night = 0x60;
		constexpr const static size_t Stars = 0x78;
		constexpr const static size_t Clouds = 0x80;
		constexpr const static size_t Ambient = 0x98;

		// Functions
		constexpr const static size_t get_Instance = 0x6f77d0;
	}

	// obf name: ::%9de37b63d4d81d87592796b34dde9a329c7313b2
#define TOD_Sky_Static_ClassName "TOD_Sky/%9de37b63d4d81d87592796b34dde9a329c7313b2"
#define TOD_Sky_Static_ClassNameShort "%9de37b63d4d81d87592796b34dde9a329c7313b2"
#define TOD_Sky_Static_TypeDefinitionIndex 8265

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x70;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 9022

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0x885220;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 8449

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9788

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8685

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 9260

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 8732

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 9846

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 4274

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 6562

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 6600

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 4153

	namespace ItemModCompostable {

		// Offsets
		constexpr const static size_t MaxBaitStack = 0x28;
	}

	// obf name: ::ResourceRef`1
#define GameObjectRef_ClassName "ResourceRef<UnityEngine/GameObject>"
#define GameObjectRef_ClassNameShort "ResourceRef`1"
#define GameObjectRef_TypeDefinitionIndex -1

	namespace GameObjectRef {

		// Offsets
		constexpr const static size_t guid = 0x10;
	}

#define EnvironmentManager_TypeDefinitionIndex 6631

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x4657ec0;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%ef838a2b1121f69925dfcebaa55455fd5ec4bdbe/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24410

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 5015

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 5016

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 1871

	namespace UIChat {

		// Offsets
		constexpr const static size_t chatArea = 0x28;
	}

	// obf name: ::ListComponent`1
#define ListComponent_ClassName "ListComponent<UIChat>"
#define ListComponent_ClassNameShort "ListComponent`1"
#define ListComponent_TypeDefinitionIndex -1

	namespace ListComponent {

		// Offsets
		constexpr const static size_t InstanceList = 0x48;
	}

	// obf name: ::%a03b56a37ef5f1042cc89fc719e52219a2395575
#define ListHashSet_ClassName "%a03b56a37ef5f1042cc89fc719e52219a2395575<UIChat>"
#define ListHashSet_ClassNameShort "%a03b56a37ef5f1042cc89fc719e52219a2395575"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 2341

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3f0;
	}

#define Chainsaw_TypeDefinitionIndex 1754

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x38c;
	}

	// obf name: ::%a1c57da571c1c4c0130b04130a7b048a8218bf9f
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%a1c57da571c1c4c0130b04130a7b048a8218bf9f"
#define CameraUpdateHook_Static_ClassNameShort "%a1c57da571c1c4c0130b04130a7b048a8218bf9f"
#define CameraUpdateHook_Static_TypeDefinitionIndex 4206

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x88;
	}

#define SteamClientWrapper_TypeDefinitionIndex 5846

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x3d8ce60;
	}

	// obf name: ::%48be176a41cc4bddee0a1338943ee74f258d690b
#define AimConeUtil_ClassName "%48be176a41cc4bddee0a1338943ee74f258d690b"
#define AimConeUtil_ClassNameShort "%48be176a41cc4bddee0a1338943ee74f258d690b"
#define AimConeUtil_TypeDefinitionIndex 517

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x30b9720;
	}

	// obf name: ::%c387b4f4bf5eec97967672e3c9419129ff2420de
#define Buttons_ConButton_ClassName "%831a561502fe074c74078660a3fbca132ec8863d/%c387b4f4bf5eec97967672e3c9419129ff2420de"
#define Buttons_ConButton_ClassNameShort "%c387b4f4bf5eec97967672e3c9419129ff2420de"
#define Buttons_ConButton_TypeDefinitionIndex 62

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%eb869b2a59452107181deea9b3e4c43cc507ca21
#define Buttons_Static_ClassName "%831a561502fe074c74078660a3fbca132ec8863d/%eb869b2a59452107181deea9b3e4c43cc507ca21"
#define Buttons_Static_ClassNameShort "%eb869b2a59452107181deea9b3e4c43cc507ca21"
#define Buttons_Static_TypeDefinitionIndex 63

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x860;
		constexpr const static size_t Attack = 0x470;
		constexpr const static size_t Attack2 = 0xa30;
		constexpr const static size_t Forward = 0x6d0;
		constexpr const static size_t Backward = 0xc80;
		constexpr const static size_t Right = 0x430;
		constexpr const static size_t Left = 0x30;
		constexpr const static size_t Sprint = 0x580;
		constexpr const static size_t Use = 0x950;

		// Functions
		constexpr const static size_t Pets_setter = 0x25898d0;
	}

#define PlayerModel_TypeDefinitionIndex 5708

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x270;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 1073

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 6328

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 428

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x10;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 6942

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x410;
		constexpr const static size_t wasAiming = 0x420;
	}

#define CrossbowWeapon_TypeDefinitionIndex 3800

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 2746

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%bd5d22beed06d7be7deeed6ff5b579002e16dfa2
#define ConVar_Admin_Static_ClassName "%7a89a8f44890266a2e7ab0b22801008bb426e635/%bd5d22beed06d7be7deeed6ff5b579002e16dfa2"
#define ConVar_Admin_Static_ClassNameShort "%bd5d22beed06d7be7deeed6ff5b579002e16dfa2"
#define ConVar_Admin_Static_TypeDefinitionIndex 3057

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x1ac;

		// Functions
		constexpr const static size_t admintime_getter = 0x2596510;
		constexpr const static size_t admintime_setter = 0x25c3010;
	}

	// obf name: ::%ec4bee0b946099fdc1931ecc2a16aff4c6620e21
#define ConVar_Player_Static_ClassName "%58a04f16b61841472404ae71a094f06353f685b8/%ec4bee0b946099fdc1931ecc2a16aff4c6620e21"
#define ConVar_Player_Static_ClassNameShort "%ec4bee0b946099fdc1931ecc2a16aff4c6620e21"
#define ConVar_Player_Static_TypeDefinitionIndex 2029

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x50;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x257ba80;
		constexpr const static size_t clientTickRate_setter = 0x2593880;
	}

#define ColliderInfo_TypeDefinitionIndex 5433

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 3111

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 1900

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x378;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;
	}

#define Client_TypeDefinitionIndex 3966

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x28e0c60;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%cef213936538c1310da14d9b836584457684ce4a
#define ItemManager_Static_ClassName "%d924fa423fa97b89ef66f419db0fddc7d15fcc10/%cef213936538c1310da14d9b836584457684ce4a"
#define ItemManager_Static_ClassNameShort "%cef213936538c1310da14d9b836584457684ce4a"
#define ItemManager_Static_TypeDefinitionIndex 6224

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x20;
		constexpr const static size_t itemDictionary = 0x138;
		constexpr const static size_t itemDictionaryByName = 0x30;
	}

	// obf name: ::%087c6457a9d6d27e8d76223574c7599fe9c6d87c
#define ConVar_Server_Static_ClassName "%f2d385dc901b12b7e4a9fe736cbbe139ec10d9bd/%087c6457a9d6d27e8d76223574c7599fe9c6d87c"
#define ConVar_Server_Static_ClassNameShort "%087c6457a9d6d27e8d76223574c7599fe9c6d87c"
#define ConVar_Server_Static_TypeDefinitionIndex 4599

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 4222

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x2b6ac70;
	}

#define LoadingScreen_TypeDefinitionIndex 4879

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x30;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 5481

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%4cc5cc0ee3f1d9535fdba7138135cce69484ff3f"
#define MapView_Static_ClassNameShort "%4cc5cc0ee3f1d9535fdba7138135cce69484ff3f"
#define MapView_TypeDefinitionIndex 6720

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x4783df0;
	}

	// obf name: ::%8c9912b1aba9d9f222e8df797949dfe206d570e1
#define GamePhysics_Static_ClassName "%416658db1332ba9ff3c9259cd4a209206221b367/%8c9912b1aba9d9f222e8df797949dfe206d570e1"
#define GamePhysics_Static_ClassNameShort "%8c9912b1aba9d9f222e8df797949dfe206d570e1"
#define GamePhysics_Static_TypeDefinitionIndex 3484

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x0;
	}

	// obf name: ::%416658db1332ba9ff3c9259cd4a209206221b367
#define GamePhysics_ClassName "%416658db1332ba9ff3c9259cd4a209206221b367"
#define GamePhysics_ClassNameShort "%416658db1332ba9ff3c9259cd4a209206221b367"
#define GamePhysics_TypeDefinitionIndex 3485

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x2225040;
		constexpr const static size_t LineOfSightInternal = 0x222a560;
		constexpr const static size_t Verify = 0x225d5c0;
	}

#define InstancedDebugDraw_TypeDefinitionIndex 7006

	namespace InstancedDebugDraw {

		// Functions
		constexpr const static size_t AddInstance = 0x4a70630;
	}

	// obf name: ::%96dd8f3cc5662a19393bbf3c00ef60d4108f648b
#define RaycastHitEx_ClassName "%96dd8f3cc5662a19393bbf3c00ef60d4108f648b"
#define RaycastHitEx_ClassNameShort "%96dd8f3cc5662a19393bbf3c00ef60d4108f648b"
#define RaycastHitEx_TypeDefinitionIndex 1085

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x4fe4450;
	}

	// obf name: ::%ee053878fb53654402c09ebae3f49673559ea562
#define OnParentDestroyingEx_ClassName "%ee053878fb53654402c09ebae3f49673559ea562"
#define OnParentDestroyingEx_ClassNameShort "%ee053878fb53654402c09ebae3f49673559ea562"
#define OnParentDestroyingEx_TypeDefinitionIndex 7075

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x4b330d0;
	}

	// obf name: ::%e26b9b586f457cb2055d810c31dd0f9702dc1df4
#define ConsoleNetwork_ClassName "%e26b9b586f457cb2055d810c31dd0f9702dc1df4"
#define ConsoleNetwork_ClassNameShort "%e26b9b586f457cb2055d810c31dd0f9702dc1df4"
#define ConsoleNetwork_TypeDefinitionIndex 4064

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x2a0dcd0;
	}

#define ThrownWeapon_TypeDefinitionIndex 6983

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 3644

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 4556

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 6720

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 6723

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 5087

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 6426

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 6139

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 6570

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 3283

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%7a6705e3ef96bea8b6b5c3212b8b708a0a564450
#define ConVar_Client_Static_ClassName "%7022e73ef165e05869b9e59ea84543db7cf7b2e8/%7a6705e3ef96bea8b6b5c3212b8b708a0a564450"
#define ConVar_Client_Static_ClassNameShort "%7a6705e3ef96bea8b6b5c3212b8b708a0a564450"
#define ConVar_Client_Static_TypeDefinitionIndex 6512

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x7c0;
		constexpr const static size_t camspeed = 0x764;
	}

#define SamSite_TypeDefinitionIndex 2730

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 1289

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 2765

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 3135

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 1974

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 449

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 1098

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 5429

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%81f8905bb8261857620f7a4ef3d95fa2402224a7
#define Facepunch_Network_Raknet_Client_ClassName "%81f8905bb8261857620f7a4ef3d95fa2402224a7"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%81f8905bb8261857620f7a4ef3d95fa2402224a7"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 22943

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x63f3350;
		constexpr const static size_t IsConnected_vtableoff = 0x438;
	}

	// obf name: ::%11a1baf559e0bfc3b9018205eb315087ee1ed84c
#define EncryptedValue_ClassName "%11a1baf559e0bfc3b9018205eb315087ee1ed84c<System/Int32>"
#define EncryptedValue_ClassNameShort "%11a1baf559e0bfc3b9018205eb315087ee1ed84c"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%a7af0a5ce0badce46a6d647aad75c77616b2e4ee
#define HiddenValue_ClassName "%a7af0a5ce0badce46a6d647aad75c77616b2e4ee<BaseNetworkable/%66323faacf2159c1b2f4947a5b1f230c0bd2b466>"
#define HiddenValue_ClassNameShort "%a7af0a5ce0badce46a6d647aad75c77616b2e4ee"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define ItemModRFListener_TypeDefinitionIndex 3489

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x2284330;
	}

#define UIFogOverlay_TypeDefinitionIndex 2765

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x30;
	}

	// obf name: ::%e51ecad687ace38b3f82ad33212000f9b9e85db6
#define BufferStream_ClassName "%e51ecad687ace38b3f82ad33212000f9b9e85db6"
#define BufferStream_ClassNameShort "%e51ecad687ace38b3f82ad33212000f9b9e85db6"
#define BufferStream_TypeDefinitionIndex 7501

	namespace BufferStream {

		// Offsets
		constexpr const static size_t _buffer = 0x20;

		// Functions
		constexpr const static size_t EnsureCapacity = 0x9883a10;
	}

#define FreeableLootContainer_TypeDefinitionIndex 1219

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 337

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 855

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x4b7fa80;
	}

#define OutlineManager_TypeDefinitionIndex 2673

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%354cfc6ffc30c4c45402bc49e92be87746a6a59c
#define ConsoleSystem_Command_ClassName "%10f0671cb5dd7148fdc54e242b89e51bf4acdcb8/%354cfc6ffc30c4c45402bc49e92be87746a6a59c"
#define ConsoleSystem_Command_ClassNameShort "%354cfc6ffc30c4c45402bc49e92be87746a6a59c"
#define ConsoleSystem_Command_TypeDefinitionIndex 23587

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x10;
		constexpr const static size_t SetOveride = 0x78;
		constexpr const static size_t Call = 0x38;
	}

	// obf name: ::%386ff67ebb7e7bbff93f45817d29374b67916404
#define ConsoleSystem_Option_ClassName "%10f0671cb5dd7148fdc54e242b89e51bf4acdcb8/%386ff67ebb7e7bbff93f45817d29374b67916404"
#define ConsoleSystem_Option_ClassNameShort "%386ff67ebb7e7bbff93f45817d29374b67916404"
#define ConsoleSystem_Option_TypeDefinitionIndex 23597

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%721f8ef1be192bdc63417f1e12f698d091691088
#define ConsoleSystem_Arg_ClassName "%10f0671cb5dd7148fdc54e242b89e51bf4acdcb8/%721f8ef1be192bdc63417f1e12f698d091691088"
#define ConsoleSystem_Arg_ClassNameShort "%721f8ef1be192bdc63417f1e12f698d091691088"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23585

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x48;
	}

	// obf name: ::%fc2e0c6c8bf33b09d837d2e31460aeb9a207a85d
#define ConsoleSystem_Index_Client_ClassName "%10f0671cb5dd7148fdc54e242b89e51bf4acdcb8/%c57e089bcdcce47080a39527f5f66dfa7a68f085.%fc2e0c6c8bf33b09d837d2e31460aeb9a207a85d"
#define ConsoleSystem_Index_Client_ClassNameShort "%fc2e0c6c8bf33b09d837d2e31460aeb9a207a85d"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23593

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x62b6530;
	}

#define String_TypeDefinitionIndex 10492

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x8450c30;
	}

	// obf name: ::%f48dc9f86c05ec05f8e02fcf87facfa6951ff707
#define EntityRef_ClassName "%f48dc9f86c05ec05f8e02fcf87facfa6951ff707"
#define EntityRef_ClassNameShort "%f48dc9f86c05ec05f8e02fcf87facfa6951ff707"
#define EntityRef_TypeDefinitionIndex 5079

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x3578590;
	}

#define ConVar_Debugging_TypeDefinitionIndex -1

	namespace ConVar_Debugging {

		// Functions
		constexpr const static size_t debugcamera = 0x25a7bc0;
		constexpr const static size_t noclip = 0x25b5cd0;
	}

#define CursorManager_TypeDefinitionIndex 4683

	namespace CursorManager {

		// Offsets
	}

	// obf name: ::%26d21e53fc3454aaf790b97061885ec87be2ebf5
#define ProtoBuf_ProjectileShoot_ClassName "%26d21e53fc3454aaf790b97061885ec87be2ebf5"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%26d21e53fc3454aaf790b97061885ec87be2ebf5"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7572

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8a38b60;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8a3a520;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%4b8f6a219d7c0f1c07f3bbfc68732782d17e22f7
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%26d21e53fc3454aaf790b97061885ec87be2ebf5/%4b8f6a219d7c0f1c07f3bbfc68732782d17e22f7"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%4b8f6a219d7c0f1c07f3bbfc68732782d17e22f7"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7571

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t startPos = 0x28;
		constexpr const static size_t startVel = 0x1c;
		constexpr const static size_t seed = 0x10;
	}

	// obf name: ::%0951a0ad8d1520feeb5cd757da2f4ce8f270ded4
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%0951a0ad8d1520feeb5cd757da2f4ce8f270ded4"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%0951a0ad8d1520feeb5cd757da2f4ce8f270ded4"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7404

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t curPosition = 0x10;
		constexpr const static size_t curVelocity = 0x28;
		constexpr const static size_t travelTime = 0x1c;
		constexpr const static size_t ShouldPool = 0x34;

		// Functions
		constexpr const static size_t Dispose = 0x959b350;
		constexpr const static size_t WriteToStreamDelta = 0x9597180;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9592b50;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%64257d67498d2687ddaf773d33b032eee6ca534f
#define ProtoBuf_PlayerProjectileAttack_ClassName "%64257d67498d2687ddaf773d33b032eee6ca534f"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%64257d67498d2687ddaf773d33b032eee6ca534f"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7519

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x28;
		constexpr const static size_t hitDistance = 0x1c;
		constexpr const static size_t travelTime = 0x14;
		constexpr const static size_t playerAttack = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x99120f0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9913720;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%48857fb1f1db6587e9d06a2975e70927149df0f9
#define ProtoBuf_PlayerAttack_ClassName "%48857fb1f1db6587e9d06a2975e70927149df0f9"
#define ProtoBuf_PlayerAttack_ClassNameShort "%48857fb1f1db6587e9d06a2975e70927149df0f9"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7282

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%670057548ac177b826c423a71ef6fbe7f579f138
#define ProtoBuf_Attack_ClassName "%670057548ac177b826c423a71ef6fbe7f579f138"
#define ProtoBuf_Attack_ClassNameShort "%670057548ac177b826c423a71ef6fbe7f579f138"
#define ProtoBuf_Attack_TypeDefinitionIndex 7673

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x30;
		constexpr const static size_t pointEnd = 0x3c;
		constexpr const static size_t hitID = 0x78;
		constexpr const static size_t hitBone = 0x2c;
		constexpr const static size_t hitNormalLocal = 0x68;
		constexpr const static size_t hitPositionLocal = 0x5c;
		constexpr const static size_t hitNormalWorld = 0x18;
		constexpr const static size_t hitPositionWorld = 0x50;
		constexpr const static size_t hitPartID = 0x24;
		constexpr const static size_t hitMaterialID = 0x80;
		constexpr const static size_t srcParentID = 0x48;
		constexpr const static size_t dstParentID = 0x10;
	}
}