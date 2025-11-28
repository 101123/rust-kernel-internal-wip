#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x6928bd7c;
		constexpr const static size_t gc_handles = 0xd85c0b0;
		constexpr const static size_t il2cpp_resolve_icall = 0x5cc360;
		constexpr const static size_t il2cpp_array_new = 0x5cc380;
		constexpr const static size_t il2cpp_assembly_get_image = 0x11b90;
		constexpr const static size_t il2cpp_class_from_name = 0x5cc4f0;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x5cc800;
		constexpr const static size_t il2cpp_class_get_type = 0x5cc8a0;
		constexpr const static size_t il2cpp_domain_get = 0x5cce00;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x5cce20;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x5cd6e0;
		constexpr const static size_t il2cpp_gchandle_new = 0x5cd690;
		constexpr const static size_t il2cpp_gchandle_free = 0x5cd780;
		constexpr const static size_t il2cpp_method_get_name = 0x3620;
		constexpr const static size_t il2cpp_object_new = 0x5cde30;
		constexpr const static size_t il2cpp_type_get_object = 0x5ce620;
	}

#define Object_TypeDefinitionIndex 17400

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xb222d80;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 17371

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

#define Component_TypeDefinitionIndex 17358

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 17352

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 17435

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xb22eb30;
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

#define Camera_TypeDefinitionIndex 17149

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

#define Time_TypeDefinitionIndex 17422

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

#define Material_TypeDefinitionIndex 17212

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

#define MaterialPropertyBlock_TypeDefinitionIndex 17208

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xb1e28d0;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 17211

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xb1e6440;
		constexpr const static size_t PropertyToID = 0xaa6a0;
		constexpr const static size_t GetPropertyCount = 0xaea30;
		constexpr const static size_t GetPropertyName = 0xad8f0;
		constexpr const static size_t GetPropertyType = 0xadb90;
	}

#define Mesh_TypeDefinitionIndex 17267

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

#define Renderer_TypeDefinitionIndex 17209

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterial = 0x9ffe0;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 17270

	namespace Texture {

		// Functions
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 17272

	namespace Texture2D {

		// Functions
		constexpr const static size_t ctor = 0xb1fc450;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define Sprite_TypeDefinitionIndex 17441

	namespace Sprite {

		// Functions
		constexpr const static size_t get_texture = 0x119300;
	}

#define RenderTexture_TypeDefinitionIndex 17277

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xb205200;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17748

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb249390;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17724

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xb2431e0;
	}

#define ComputeBuffer_TypeDefinitionIndex 17413

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb2269d0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xb226c20;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 17216

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb1ed4e0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xb1ed210;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 22693

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xb26c680;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 17189

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 17300

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex -1

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 17186

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex -1

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

#define Application_TypeDefinitionIndex 17131

	namespace Application {

		// Functions
		constexpr const static size_t get_version = 0x5f350;
		constexpr const static size_t Quit = 0x5d790;
		constexpr const static size_t get_isFocused = 0x5ddc0;
	}

#define Gradient_TypeDefinitionIndex 17298

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 24060

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xb2b1a50;
		constexpr const static size_t RaycastNonAlloc = 0xb2b4120;
		constexpr const static size_t CheckCapsule = 0xb2b58e0;
	}

#define Image_TypeDefinitionIndex 21578

	namespace Image {

		// Offsets
		constexpr const static size_t m_Sprite = 0xd0;
	}

#define GraphicsSettings_TypeDefinitionIndex 17746

	namespace GraphicsSettings {

		// Functions
		constexpr const static size_t get_INTERNAL_defaultRenderPipeline = 0x127f00;
	}

#define Cursor_TypeDefinitionIndex 17287

	namespace Cursor {

		// Functions
		constexpr const static size_t get_visible = 0xed7a0;
	}

#define BaseNetworkable_TypeDefinitionIndex 7484

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x60;
		constexpr const static size_t parentEntity = 0x70;
		constexpr const static size_t children = 0x40;
	}

	// obf name: ::%60d2fc0d4b243e4efca4ef7e2715233e8ba3c920
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%60d2fc0d4b243e4efca4ef7e2715233e8ba3c920"
#define BaseNetworkable_Static_ClassNameShort "%60d2fc0d4b243e4efca4ef7e2715233e8ba3c920"
#define BaseNetworkable_Static_TypeDefinitionIndex 7483

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x18;
	}

	// obf name: ::%efaa0b174ce665aea1af01e67f6f48014846485e
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%efaa0b174ce665aea1af01e67f6f48014846485e"
#define BaseNetworkable_EntityRealm_ClassNameShort "%efaa0b174ce665aea1af01e67f6f48014846485e"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 7481

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x4f2f920;
	}

	// obf name: ::%750342e66f6b7ee47a275b21b5101a4cfe31d16e
#define System_ListDictionary_ClassName "%750342e66f6b7ee47a275b21b5101a4cfe31d16e<%c1767efe9c341bde85a4bd167af5ca27bb6d3d0d,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%750342e66f6b7ee47a275b21b5101a4cfe31d16e"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x10;

		// Functions
		constexpr const static size_t TryGetValue = 0x77059c0;
		constexpr const static size_t TryGetValue_methodinfo = 0xd4d6288;
	}

	// obf name: ::%b95337cbfdb5dc46bbe68c0394c38519ded054ce
#define System_BufferList_ClassName "%b95337cbfdb5dc46bbe68c0394c38519ded054ce<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%b95337cbfdb5dc46bbe68c0394c38519ded054ce"
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
		constexpr const static size_t Instance = 0x28;
	}

#define Model_TypeDefinitionIndex 1534

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t eyeBone = 0x38;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 4558

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xb0;
		constexpr const static size_t model = 0xd8;
		constexpr const static size_t flags = 0xe0;
		constexpr const static size_t triggers = 0x140;
		constexpr const static size_t positionLerp = 0x178;

		// Functions
		constexpr const static size_t ServerRPC = 0x2ebeea0;
		constexpr const static size_t FindBone = 0x2e5c140;
		constexpr const static size_t GetWorldVelocity = 0x2eb53a0;
		constexpr const static size_t GetParentVelocity = 0x2e6c040;
	}

	// obf name: ::%2277dd49acd590343e09e46de3092d5a84bc5813
#define PositionLerp_ClassName "%2277dd49acd590343e09e46de3092d5a84bc5813"
#define PositionLerp_ClassNameShort "%2277dd49acd590343e09e46de3092d5a84bc5813"
#define PositionLerp_TypeDefinitionIndex 2635

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x28;
	}

	// obf name: ::%0317e4bd1013fada8dc3b485ecdf509014a4d8ac
#define Interpolator_ClassName "%0317e4bd1013fada8dc3b485ecdf509014a4d8ac<%68cbfc9d30c40049bd3dfc1c04b1f7fe9f7363ee>"
#define Interpolator_ClassNameShort "%0317e4bd1013fada8dc3b485ecdf509014a4d8ac"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 148

	namespace BaseCombatEntity {

		// Offsets
		constexpr const static size_t skeletonProperties = 0x1d0;
		constexpr const static size_t baseProtection = 0x1d8;
		constexpr const static size_t lifestate = 0x244;
		constexpr const static size_t markAttackerHostile = 0x24a;
		constexpr const static size_t _health = 0x250;
		constexpr const static size_t _maxHealth = 0x254;
		constexpr const static size_t lastNotifyFrame = 0x264;
	}

#define SkeletonProperties_TypeDefinitionIndex 775

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 773

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 1939

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 1938

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%97d2e8287861d9bb0d529fbd5656a05930eb6ac1
#define DamageTypeList_ClassName "%97d2e8287861d9bb0d529fbd5656a05930eb6ac1"
#define DamageTypeList_ClassNameShort "%97d2e8287861d9bb0d529fbd5656a05930eb6ac1"
#define DamageTypeList_TypeDefinitionIndex 1889

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 3404

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 6117

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
		constexpr const static size_t ItemModWearable = 0x148;
	}

#define RecoilProperties_TypeDefinitionIndex 5697

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

#define BaseProjectile_Magazine_Definition_TypeDefinitionIndex 6136

	namespace BaseProjectile_Magazine_Definition {

		// Offsets
		constexpr const static size_t builtInSize = 0x0;
	}

#define BaseProjectile_Magazine_TypeDefinitionIndex 6137

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t definition = 0x10;
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 2403

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x248;
		constexpr const static size_t repeatDelay = 0x24c;
		constexpr const static size_t animationDelay = 0x250;
		constexpr const static size_t noHeadshots = 0x29e;
		constexpr const static size_t nextAttackTime = 0x2a0;
		constexpr const static size_t timeSinceDeploy = 0x2b8;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x16338b0;
		constexpr const static size_t StartAttackCooldown = 0x16367b0;
	}

#define BaseProjectile_TypeDefinitionIndex 6142

	namespace BaseProjectile {

		// Offsets
		constexpr const static size_t projectileVelocityScale = 0x2ec;
		constexpr const static size_t automatic = 0x2f0;
		constexpr const static size_t reloadTime = 0x330;
		constexpr const static size_t primaryMagazine = 0x338;
		constexpr const static size_t fractionalReload = 0x340;
		constexpr const static size_t aimSway = 0x358;
		constexpr const static size_t aimSwaySpeed = 0x35c;
		constexpr const static size_t recoil = 0x360;
		constexpr const static size_t aimconeCurve = 0x368;
		constexpr const static size_t aimCone = 0x370;
		constexpr const static size_t hipAimCone = 0x374;
		constexpr const static size_t noAimingWhileCycling = 0x38d;
		constexpr const static size_t isBurstWeapon = 0x397;
		constexpr const static size_t cachedModHash = 0x3c8;
		constexpr const static size_t sightAimConeScale = 0x3cc;
		constexpr const static size_t sightAimConeOffset = 0x3d0;
		constexpr const static size_t hipAimConeScale = 0x3d4;
		constexpr const static size_t hipAimConeOffset = 0x3d8;

		// Functions
		constexpr const static size_t LaunchProjectile = 0x4139410;
		constexpr const static size_t LaunchProjectileClientSide = 0x4145c50;
		constexpr const static size_t ScaleRepeatDelay = 0x4139b40;
		constexpr const static size_t GetAimCone = 0x4128450;
		constexpr const static size_t GetAimCone_vtableoff = 0x3e98;
		constexpr const static size_t UpdateAmmoDisplay = 0x4132e50;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3ff8;
	}

#define BaseLauncher_TypeDefinitionIndex 5891

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 7343

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%201e6809d4e9967da3ea260fb25b633650885cc9
#define HitTest_ClassName "%201e6809d4e9967da3ea260fb25b633650885cc9"
#define HitTest_ClassNameShort "%201e6809d4e9967da3ea260fb25b633650885cc9"
#define HitTest_TypeDefinitionIndex 5176

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x74;
		constexpr const static size_t AttackRay = 0x50;
		constexpr const static size_t RayHit = 0x7c;
		constexpr const static size_t damageProperties = 0x48;
		constexpr const static size_t gameObject = 0x18;
		constexpr const static size_t collider = 0x10;
		constexpr const static size_t ignoredTypes = 0x30;
		constexpr const static size_t HitTransform = 0xc0;
		constexpr const static size_t HitPart = 0x70;
		constexpr const static size_t HitMaterial = 0x38;
		constexpr const static size_t DidHit = 0x68;
		constexpr const static size_t MaxDistance = 0xbc;
		constexpr const static size_t HitPoint = 0x24;
		constexpr const static size_t HitNormal = 0xb0;
		constexpr const static size_t ignoreEntity = 0xa8;
		constexpr const static size_t HitEntity = 0xd0;
	}

#define Projectile_TypeDefinitionIndex 2392

	namespace Projectile {

		// Offsets
		constexpr const static size_t initialVelocity = 0x28;
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t thickness = 0x3c;
		constexpr const static size_t initialDistance = 0x44;
		constexpr const static size_t swimScale = 0xf0;
		constexpr const static size_t swimSpeed = 0xfc;
		constexpr const static size_t owner = 0x110;
		constexpr const static size_t sourceProjectilePrefab = 0x1d0;
		constexpr const static size_t mod = 0x1e0;
		constexpr const static size_t hitTest = 0x118;
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
		constexpr const static size_t CalculateEffectScale = 0x15c9b60;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x248;
		constexpr const static size_t SetEffectScale = 0x15d39a0;
		constexpr const static size_t UpdateVelocity = 0x15f4480;
		constexpr const static size_t Retire = 0x15cb710;
		constexpr const static size_t DoHit = 0x15d5b70;
	}

	// obf name: ::%1e2116f1fdfeb7540c01e99040e4d0c76a13da10
#define HitInfo_ClassName "%1e2116f1fdfeb7540c01e99040e4d0c76a13da10"
#define HitInfo_ClassNameShort "%1e2116f1fdfeb7540c01e99040e4d0c76a13da10"
#define HitInfo_TypeDefinitionIndex 3614

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x98;
		constexpr const static size_t damageTypes = 0xa8;

		// Functions
		constexpr const static size_t get_boneArea = 0x25a6600;
	}

	// obf name: ::%b2d836dd8c23e73c89f074ba7eaa81f6d854f7b8
#define GameTrace_ClassName "%b2d836dd8c23e73c89f074ba7eaa81f6d854f7b8"
#define GameTrace_ClassNameShort "%b2d836dd8c23e73c89f074ba7eaa81f6d854f7b8"
#define GameTrace_TypeDefinitionIndex 6751

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x47abc60;
	}

#define BaseMelee_TypeDefinitionIndex 2459

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2e0;
		constexpr const static size_t maxDistance = 0x2f8;
		constexpr const static size_t attackRadius = 0x2fc;
		constexpr const static size_t blockSprintOnAttack = 0x301;
		constexpr const static size_t gathering = 0x330;
		constexpr const static size_t canThrowAsProjectile = 0x339;

		// Functions
		constexpr const static size_t ProcessAttack = 0x16b59f0;
		constexpr const static size_t DoThrow = 0x16adad0;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 6745

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x418;
		constexpr const static size_t strikeRecoil = 0x420;
		constexpr const static size_t _didSparkThisFrame = 0x428;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 7462

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x430;
		constexpr const static size_t stringBonusVelocity = 0x43c;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x4efd3f0;
	}

	// obf name: ::%1e266cecdd2785c008d8f740d653b171315f1a43
#define ItemContainer_ClassName "%1e266cecdd2785c008d8f740d653b171315f1a43"
#define ItemContainer_ClassNameShort "%1e266cecdd2785c008d8f740d653b171315f1a43"
#define ItemContainer_TypeDefinitionIndex 5467

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x20;
		constexpr const static size_t itemList = 0x28;

		// Functions
		constexpr const static size_t GetSlot = 0x382be90;
	}

#define PlayerLoot_TypeDefinitionIndex 738

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 6989

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerMain = 0x30;
		constexpr const static size_t containerWear = 0x60;
		constexpr const static size_t containerBelt = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x4a495f0;
	}

#define PlayerEyes_TypeDefinitionIndex 4883

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x31cbba0;
		constexpr const static size_t get_rotation = 0x31d7a80;
		constexpr const static size_t set_rotation = 0x31e3870;
		constexpr const static size_t HeadForward = 0x31e3a70;
	}

	// obf name: ::%e336c5138351f10c5f42644b55cd5f2447eb9777
#define PlayerEyes_Static_ClassName "PlayerEyes/%e336c5138351f10c5f42644b55cd5f2447eb9777"
#define PlayerEyes_Static_ClassNameShort "%e336c5138351f10c5f42644b55cd5f2447eb9777"
#define PlayerEyes_Static_TypeDefinitionIndex 4882

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x8;
	}

	// obf name: ::%75ccfa7deb6e73ba07df02f089e4d908551d4e82
#define PlayerBelt_ClassName "%75ccfa7deb6e73ba07df02f089e4d908551d4e82"
#define PlayerBelt_ClassNameShort "%75ccfa7deb6e73ba07df02f089e4d908551d4e82"
#define PlayerBelt_TypeDefinitionIndex 5681

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x3ac4050;
		constexpr const static size_t GetActiveItem = 0x3ac48c0;
	}

	// obf name: ::%c3080a2f3378e86ae39a7b053e14e870915efec0
#define LocalPlayer_ClassName "%c3080a2f3378e86ae39a7b053e14e870915efec0"
#define LocalPlayer_ClassNameShort "%c3080a2f3378e86ae39a7b053e14e870915efec0"
#define LocalPlayer_TypeDefinitionIndex 474

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x2f95c00;
		constexpr const static size_t MoveItem = 0x2fa7c30;
		constexpr const static size_t get_Entity = 0x2fa83a0;
	}

	// obf name: ::%e324a9603e1cd8c27db85b7db595a01227ef59b7
#define LocalPlayer_Static_ClassName "%c3080a2f3378e86ae39a7b053e14e870915efec0/%e324a9603e1cd8c27db85b7db595a01227ef59b7"
#define LocalPlayer_Static_ClassNameShort "%e324a9603e1cd8c27db85b7db595a01227ef59b7"
#define LocalPlayer_Static_TypeDefinitionIndex 473

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x150;
	}

	// obf name: ::%40bb921307a5a4a04d2b3c4444cb330686dd4836
#define BasePlayer_Static_ClassName "BasePlayer/%40bb921307a5a4a04d2b3c4444cb330686dd4836"
#define BasePlayer_Static_ClassNameShort "%40bb921307a5a4a04d2b3c4444cb330686dd4836"
#define BasePlayer_Static_TypeDefinitionIndex 2685

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0xf08;
	}

#define BasePlayer_TypeDefinitionIndex 2686

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x360;
		constexpr const static size_t input = 0x2c0;
		constexpr const static size_t movement = 0x570;
		constexpr const static size_t currentTeam = 0x480;
		constexpr const static size_t clActiveItem = 0x4b0;
		constexpr const static size_t modelState = 0x468;
		constexpr const static size_t playerFlags = 0x5c8;
		constexpr const static size_t eyes = 0x408;
		constexpr const static size_t playerRigidbody = 0x368;
		constexpr const static size_t userID = 0x610;
		constexpr const static size_t UserIDString = 0x278;
		constexpr const static size_t inventory = 0x310;
		constexpr const static size_t _displayName = 0x2e8;
		constexpr const static size_t _lookingAt = 0x2a0;
		constexpr const static size_t lastSentTickTime = 0x584;
		constexpr const static size_t CurrentTutorialAllowance = 0x5a0;
		constexpr const static size_t nextVisThink = 0x5a8;
		constexpr const static size_t lastSentTick = 0x5f8;
		constexpr const static size_t mounted = 0x500;
		constexpr const static size_t Belt = 0x290;
		constexpr const static size_t _lookingAtEntity = 0x358;
		constexpr const static size_t currentGesture = 0x530;
		constexpr const static size_t weaponMoveSpeedScale = 0x6a0;
		constexpr const static size_t clothingBlocksAiming = 0x6a4;
		constexpr const static size_t clothingMoveSpeedReduction = 0x6a8;
		constexpr const static size_t clothingWaterSpeedBonus = 0x6ac;
		constexpr const static size_t equippingBlocked = 0x6b4;

		// Functions
		constexpr const static size_t MakeVisible = 0x19c9280;
		constexpr const static size_t ClientUpdateLocalPlayer = 0x1a432e0;
		constexpr const static size_t Menu_AssistPlayer = 0x19bade0;
		constexpr const static size_t OnViewModeChanged = 0x19d2bd0;
		constexpr const static size_t ChatMessage = 0x19268a0;
		constexpr const static size_t IsOnGround = 0x18f9a00;
		constexpr const static size_t GetSpeed = 0x19862e0;
		constexpr const static size_t CanBuild = 0x1a69540;
		constexpr const static size_t SendProjectileUpdate = 0x19a1570;
		constexpr const static size_t GetMounted = 0x192f010;
		constexpr const static size_t GetHeldEntity = 0x1a14180;
		constexpr const static size_t get_inventory = 0x19a4080;
		constexpr const static size_t get_eyes = 0x1a81b70;
		constexpr const static size_t SendClientTick = 0x193dee0;
		constexpr const static size_t ClientInput = 0x1a60060;
		constexpr const static size_t ClientInput_vtableoff = 0x4048;
		constexpr const static size_t MaxHealth = 0x19c7df0;
		constexpr const static size_t MaxHealth_vtableoff = 0x1698;
		constexpr const static size_t OnAttacked = 0x195d630;
		constexpr const static size_t OnAttacked_vtableoff = 0x18b8;
		constexpr const static size_t get_idealViewMode = 0x19b7230;
	}

#define ScientistNPC_TypeDefinitionIndex 7382

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 3986

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 439

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 4030

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 2334

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 1015

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 4135

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t Init = 0x2a54830;
		constexpr const static size_t BlockJump = 0x2a60d80;
		constexpr const static size_t BlockSprint = 0x2a41490;
		constexpr const static size_t GroundCheck = 0x2a3abe0;
		constexpr const static size_t ClientInput = 0x2a45b70;
		constexpr const static size_t ClientInput_vtableoff = 0x418;
		constexpr const static size_t DoFixedUpdate = 0x2a46b00;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x1a8;
		constexpr const static size_t FrameUpdate = 0x2a45fe0;
		constexpr const static size_t FrameUpdate_vtableoff = 0x1c8;
		constexpr const static size_t TeleportTo = 0x2a64670;
		constexpr const static size_t TeleportTo_vtableoff = 0x208;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 3081

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x388;
		constexpr const static size_t cachedProtectedMinutes = 0x390;
	}

#define WorldItem_TypeDefinitionIndex 4629

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1b0;
		constexpr const static size_t item = 0x1b8;
	}

#define HackableLockedCrate_TypeDefinitionIndex 6739

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x3a0;
		constexpr const static size_t hackSeconds = 0x3b0;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 1488

	namespace ProjectileWeaponMod {

		// Offsets
		constexpr const static size_t repeatDelay = 0x1d0;
		constexpr const static size_t projectileVelocity = 0x1dc;
		constexpr const static size_t projectileDamage = 0x1e8;
		constexpr const static size_t projectileDistance = 0x1f4;
		constexpr const static size_t aimsway = 0x200;
		constexpr const static size_t aimswaySpeed = 0x20c;
		constexpr const static size_t recoil = 0x218;
		constexpr const static size_t sightAimCone = 0x224;
		constexpr const static size_t hipAimCone = 0x230;
		constexpr const static size_t magazineCapacity = 0x244;
		constexpr const static size_t needsOnForEffects = 0x250;
	}

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 1484

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%4f273e05fc773ee4cfe2dec53d85707492f810e8
#define ConsoleSystem_ClassName "%4f273e05fc773ee4cfe2dec53d85707492f810e8"
#define ConsoleSystem_ClassNameShort "%4f273e05fc773ee4cfe2dec53d85707492f810e8"
#define ConsoleSystem_TypeDefinitionIndex 24036

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x65a3e70;
	}

	// obf name: ::%7e2bbb0636e0047d6b4c8984dbcdb1fd162a9116
#define ConsoleSystem_Index_Static_ClassName "%4f273e05fc773ee4cfe2dec53d85707492f810e8/%27ed6c9f358665329f4f1fec8f89a75e1f327188.%7e2bbb0636e0047d6b4c8984dbcdb1fd162a9116"
#define ConsoleSystem_Index_Static_ClassNameShort "%7e2bbb0636e0047d6b4c8984dbcdb1fd162a9116"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 24029

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x70;
	}

#define LootableCorpse_TypeDefinitionIndex 677

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2c0;
		constexpr const static size_t _playerName = 0x2b0;
	}

#define DroppedItemContainer_TypeDefinitionIndex 6713

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x290;
		constexpr const static size_t _playerName = 0x278;
	}

#define MainCamera_TypeDefinitionIndex 6675

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x80;
		constexpr const static size_t mainCameraTransform = 0xd0;

		// Functions
		constexpr const static size_t Update = 0x46bcbe0;
		constexpr const static size_t OnPreCull = 0x46c1ce0;
		constexpr const static size_t Trace = 0x46bef00;
	}

#define CameraMan_TypeDefinitionIndex 3512

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%cc88295f2346860dd9bcfe7a0d89fbd0492fb79a
#define PlayerTick_ClassName "%cc88295f2346860dd9bcfe7a0d89fbd0492fb79a"
#define PlayerTick_ClassNameShort "%cc88295f2346860dd9bcfe7a0d89fbd0492fb79a"
#define PlayerTick_TypeDefinitionIndex 7962

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x30;
		constexpr const static size_t modelState = 0x50;
		constexpr const static size_t activeItem = 0x38;
		constexpr const static size_t parentID = 0x40;
		constexpr const static size_t position = 0x20;
		constexpr const static size_t eyePos = 0x14;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9381a70;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9387cc0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%eccacae4f23ae1daf4a52c0a548e557e6720a5a5
#define InputMessage_ClassName "%eccacae4f23ae1daf4a52c0a548e557e6720a5a5"
#define InputMessage_ClassNameShort "%eccacae4f23ae1daf4a52c0a548e557e6720a5a5"
#define InputMessage_TypeDefinitionIndex 7955

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x2c;
		constexpr const static size_t aimAngles = 0x10;
		constexpr const static size_t mouseDelta = 0x20;
	}

	// obf name: ::%ad68c06c27d0bb3a12bce530f993f2899ee90f15
#define InputState_ClassName "%ad68c06c27d0bb3a12bce530f993f2899ee90f15"
#define InputState_ClassNameShort "%ad68c06c27d0bb3a12bce530f993f2899ee90f15"
#define InputState_TypeDefinitionIndex 524

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x20;
	}

#define PlayerInput_TypeDefinitionIndex 4044

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%ad0d9ded037cff10a5f2cab8e2658d7cf3fd7d7d
#define ModelState_ClassName "%ad0d9ded037cff10a5f2cab8e2658d7cf3fd7d7d"
#define ModelState_ClassNameShort "%ad0d9ded037cff10a5f2cab8e2658d7cf3fd7d7d"
#define ModelState_TypeDefinitionIndex 7810

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x14;
		constexpr const static size_t waterLevel = 0x74;
		constexpr const static size_t lookDir = 0x34;
	}

	// obf name: ::%3b46c33d14d2aa0d8a09353d22166dfd2b6a20d0
#define Item_ClassName "%3b46c33d14d2aa0d8a09353d22166dfd2b6a20d0"
#define Item_ClassNameShort "%3b46c33d14d2aa0d8a09353d22166dfd2b6a20d0"
#define Item_TypeDefinitionIndex 6805

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x20;
		constexpr const static size_t uid = 0x10;
		constexpr const static size_t clientAmmoCount = 0xd4;
		constexpr const static size_t _condition = 0x2c;
		constexpr const static size_t _maxCondition = 0x8c;
		constexpr const static size_t position = 0x38;
		constexpr const static size_t amount = 0x80;
		constexpr const static size_t contents = 0x40;
		constexpr const static size_t parent = 0x58;
		constexpr const static size_t heldEntity = 0x48;
		constexpr const static size_t worldEnt = 0x70;

		// Functions
		constexpr const static size_t get_iconSprite = 0x48523a0;
	}

	// obf name: ::%837a63d5a1ab42d37244ed4e6e9bc8a22807b08c
#define WaterLevel_ClassName "%837a63d5a1ab42d37244ed4e6e9bc8a22807b08c"
#define WaterLevel_ClassNameShort "%837a63d5a1ab42d37244ed4e6e9bc8a22807b08c"
#define WaterLevel_TypeDefinitionIndex 6287

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x42aafb0;
		constexpr const static size_t GetWaterLevel = 0x42a3010;
	}

	// obf name: ::%108c53b774028c4afd068ecc0a9a8667c9a2b28d
#define ConVar_Graphics_Static_ClassName "%43411895d23ea28715587ed4d596765544aebe49/%108c53b774028c4afd068ecc0a9a8667c9a2b28d"
#define ConVar_Graphics_Static_ClassNameShort "%108c53b774028c4afd068ecc0a9a8667c9a2b28d"
#define ConVar_Graphics_Static_TypeDefinitionIndex 2665

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x2c8;

		// Functions
		constexpr const static size_t _fov_getter = 0x3e4c2b0;
		constexpr const static size_t _fov_setter = 0x3e1bb20;
	}

#define BaseFishingRod_TypeDefinitionIndex 4959

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x268;
		constexpr const static size_t currentBobber = 0x270;
		constexpr const static size_t MaxCastDistance = 0x28c;
		constexpr const static size_t BobberPreview = 0x298;
		constexpr const static size_t clientStrainAmountNormalised = 0x2d8;
		constexpr const static size_t strainGainMod = 0x2e8;
		constexpr const static size_t aimAnimationReady = 0x2f0;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x33073c0;
		constexpr const static size_t EvaluateFishingPosition = 0x33227a0;
	}

#define FishingBobber_TypeDefinitionIndex 3208

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x290;
	}

#define GameManifest_TypeDefinitionIndex 2723

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x1b13120;
	}

	// obf name: ::%e430b19d3ed041afe55a94e2f72a74046d9505c2
#define GameManager_ClassName "%e430b19d3ed041afe55a94e2f72a74046d9505c2"
#define GameManager_ClassNameShort "%e430b19d3ed041afe55a94e2f72a74046d9505c2"
#define GameManager_TypeDefinitionIndex 3976

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x10;

		// Functions
		constexpr const static size_t CreatePrefab = 0x28f55d0;
	}

	// obf name: ::%135f603df0e5fc98353fcbb71b00917546fc18d2
#define GameManager_Static_ClassName "%e430b19d3ed041afe55a94e2f72a74046d9505c2/%135f603df0e5fc98353fcbb71b00917546fc18d2"
#define GameManager_Static_ClassNameShort "%135f603df0e5fc98353fcbb71b00917546fc18d2"
#define GameManager_Static_TypeDefinitionIndex 3975

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x20;
	}

	// obf name: ::%87aad5730c8a0ef008af2189108289632cd56cfc
#define PrefabPoolCollection_ClassName "%87aad5730c8a0ef008af2189108289632cd56cfc"
#define PrefabPoolCollection_ClassNameShort "%87aad5730c8a0ef008af2189108289632cd56cfc"
#define PrefabPoolCollection_TypeDefinitionIndex 330

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x18;
	}

	// obf name: ::%b06a0eac38bddb9a3bcaf1e4f8fc580674136b44
#define PrefabPool_ClassName "%b06a0eac38bddb9a3bcaf1e4f8fc580674136b44"
#define PrefabPool_ClassNameShort "%b06a0eac38bddb9a3bcaf1e4f8fc580674136b44"
#define PrefabPool_TypeDefinitionIndex 3087

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x28;
	}

#define ItemModProjectile_TypeDefinitionIndex 6798

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

#define CraftingQueue_TypeDefinitionIndex 1764

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%b0a05b5c08a4cd2d4472efaf8cff9c5bd201a626
#define CraftingQueue_Static_ClassName "CraftingQueue/%b0a05b5c08a4cd2d4472efaf8cff9c5bd201a626"
#define CraftingQueue_Static_ClassNameShort "%b0a05b5c08a4cd2d4472efaf8cff9c5bd201a626"
#define CraftingQueue_Static_TypeDefinitionIndex 1763

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x30;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 3304

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%745a840c35fbfa1d01a651f6e14d19a8dd44d21d
#define Planner_Static_ClassName "Planner/%745a840c35fbfa1d01a651f6e14d19a8dd44d21d"
#define Planner_Static_ClassNameShort "%745a840c35fbfa1d01a651f6e14d19a8dd44d21d"
#define Planner_Static_TypeDefinitionIndex 6820

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x88;
	}

	// obf name: ::%09b834ddbd5d0bc78118a5175b7eafb344cf1b83
#define Planner_Guide_ClassName "Planner/%09b834ddbd5d0bc78118a5175b7eafb344cf1b83"
#define Planner_Guide_ClassNameShort "%09b834ddbd5d0bc78118a5175b7eafb344cf1b83"
#define Planner_Guide_TypeDefinitionIndex 6816

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x90;
	}

#define Planner_TypeDefinitionIndex 6821

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x270;
	}

#define Construction_TypeDefinitionIndex 7086

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0x100;
		constexpr const static size_t grades = 0x148;
	}

#define BuildingBlock_TypeDefinitionIndex 3599

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2c0;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 6883

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x228;
		constexpr const static size_t _punches = 0x1d0;
		constexpr const static size_t viewModel = 0x230;

		// Functions
		constexpr const static size_t OnDeploy = 0x4990ab0;
	}

	// obf name: ::%1b86a9ad4fab0ee70ed455cf13ff71e0aa3eb4db
#define PunchEntry_ClassName "HeldEntity/%1b86a9ad4fab0ee70ed455cf13ff71e0aa3eb4db"
#define PunchEntry_ClassNameShort "%1b86a9ad4fab0ee70ed455cf13ff71e0aa3eb4db"
#define PunchEntry_TypeDefinitionIndex 6881

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x10;
		constexpr const static size_t startTime = 0x2c;
		constexpr const static size_t amountAdded = 0x14;
		constexpr const static size_t amount = 0x20;
	}

#define IronSights_TypeDefinitionIndex 3127

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 1318

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 1307

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0x78;
		constexpr const static size_t model = 0x88;
		constexpr const static size_t lower = 0xa8;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x5512600;
		constexpr const static size_t OnCameraPositionChanged = 0x5506380;
		constexpr const static size_t OnCameraPositionChanged_vtableoff = 0x218;
	}

#define ViewModel_TypeDefinitionIndex 2159

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x138a3d0;
		constexpr const static size_t PlayString = 0x138a820;
	}

#define MedicalTool_TypeDefinitionIndex 5023

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x300;
	}

#define WaterBody_TypeDefinitionIndex 2590

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x60;
	}

	// obf name: ::%ea9467a5dc2511cb7bcc68e8ddcbe8015e0bc699
#define WaterSystem_Static_ClassName "WaterSystem/%ea9467a5dc2511cb7bcc68e8ddcbe8015e0bc699"
#define WaterSystem_Static_ClassNameShort "%ea9467a5dc2511cb7bcc68e8ddcbe8015e0bc699"
#define WaterSystem_Static_TypeDefinitionIndex 819

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x168;
	}

#define WaterSystem_TypeDefinitionIndex 820

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x4f57c40;
	}

#define TerrainMeta_TypeDefinitionIndex 1905

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x188;
		constexpr const static size_t HeightMap = 0x758;
		constexpr const static size_t SplatMap = 0x3e0;
		constexpr const static size_t TopologyMap = 0x140;
		constexpr const static size_t Texturing = 0x440;
	}

#define TerrainCollision_TypeDefinitionIndex 6228

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x423be10;
	}

#define TerrainHeightMap_TypeDefinitionIndex 629

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 1831

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 4998

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t terrainSize = 0xa0;
		constexpr const static size_t shoreDistanceScale = 0xa4;
		constexpr const static size_t shoreVectors = 0x0;
	}

	// obf name: ::%b65850ee463150823a425f35333dd91c4831cbbe
#define World_Static_ClassName "%9e11ba2f233ef777a6eae07f54330312b8cfb061/%b65850ee463150823a425f35333dd91c4831cbbe"
#define World_Static_ClassNameShort "%b65850ee463150823a425f35333dd91c4831cbbe"
#define World_Static_TypeDefinitionIndex 4343

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x20c;
	}

#define ItemIcon_TypeDefinitionIndex 1317

	namespace ItemIcon {

		// Offsets
		constexpr const static size_t backgroundImage = 0xe8;

		// Functions
		constexpr const static size_t TryToMove = 0x55270b0;
		constexpr const static size_t TryToMove_vtableoff = 0x3f8;
		constexpr const static size_t RunTimedAction = 0x5522d60;
	}

	// obf name: ::%03cb0d32bf7ffd91cd31db00b4ff483c6cb0a971
#define ItemIcon_Static_ClassName "ItemIcon/%03cb0d32bf7ffd91cd31db00b4ff483c6cb0a971"
#define ItemIcon_Static_ClassNameShort "%03cb0d32bf7ffd91cd31db00b4ff483c6cb0a971"
#define ItemIcon_Static_TypeDefinitionIndex 1316

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x40;
	}

	// obf name: ::%41b9e21da78421c2631e76b7cb9c611ff9dfeb2d
#define EffectData_ClassName "%41b9e21da78421c2631e76b7cb9c611ff9dfeb2d"
#define EffectData_ClassNameShort "%41b9e21da78421c2631e76b7cb9c611ff9dfeb2d"
#define EffectData_TypeDefinitionIndex 7855

	namespace EffectData {

		// Offsets
		constexpr const static size_t entity = 0x58;
		constexpr const static size_t source = 0x18;
	}

	// obf name: ::%ff3a17672f835112e077cad4475533c4e21f6f33
#define Effect_ClassName "%ff3a17672f835112e077cad4475533c4e21f6f33"
#define Effect_ClassNameShort "%ff3a17672f835112e077cad4475533c4e21f6f33"
#define Effect_TypeDefinitionIndex 5163

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x90;
		constexpr const static size_t worldPos = 0xa4;
	}

	// obf name: ::%8134ed04beda728bf42ca5e44ea461bb7a7bcf99
#define EffectLibrary_ClassName "%8134ed04beda728bf42ca5e44ea461bb7a7bcf99"
#define EffectLibrary_ClassNameShort "%8134ed04beda728bf42ca5e44ea461bb7a7bcf99"
#define EffectLibrary_TypeDefinitionIndex 5090

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x349c340;
	}

	// obf name: ::%da59b4c83db9a943e03d0ab75bffb58cd401f6b4
#define EffectNetwork_ClassName "%da59b4c83db9a943e03d0ab75bffb58cd401f6b4"
#define EffectNetwork_ClassNameShort "%da59b4c83db9a943e03d0ab75bffb58cd401f6b4"
#define EffectNetwork_TypeDefinitionIndex 1672

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%349ed5b61085f7cede4596956ae4cbcf18d4c304
#define EffectNetwork_Static_ClassName "%da59b4c83db9a943e03d0ab75bffb58cd401f6b4/%349ed5b61085f7cede4596956ae4cbcf18d4c304"
#define EffectNetwork_Static_ClassNameShort "%349ed5b61085f7cede4596956ae4cbcf18d4c304"
#define EffectNetwork_Static_TypeDefinitionIndex 1671

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x28;

		// Functions
		constexpr const static size_t cctor = 0xe7c6c0;
	}

#define BuildingBlock_TypeDefinitionIndex 3599

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x300;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x251b830;
		constexpr const static size_t HasUpgradePrivilege = 0x250a830;
		constexpr const static size_t CanAffordUpgrade = 0x2524250;
	}

	// obf name: ::%63e975ba59c170d5666bc433d1b907ff4d392bfd
#define GameObjectEx_ClassName "%63e975ba59c170d5666bc433d1b907ff4d392bfd"
#define GameObjectEx_ClassNameShort "%63e975ba59c170d5666bc433d1b907ff4d392bfd"
#define GameObjectEx_TypeDefinitionIndex 5054

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x3419630;
	}

#define UIDeathScreen_TypeDefinitionIndex 1719

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0xf1b9f0;
	}

	// obf name: ::%7fc5e0d2308b5297ab24192e23dfebed557ad3de
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%7fc5e0d2308b5297ab24192e23dfebed557ad3de"
#define BaseScreenShake_Static_ClassNameShort "%7fc5e0d2308b5297ab24192e23dfebed557ad3de"
#define BaseScreenShake_Static_TypeDefinitionIndex 5445

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x30;
	}

#define FlashbangOverlay_TypeDefinitionIndex 5486

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t flashLength = 0x40;
	}

	// obf name: ::%f5cff05c659516490e0ccbb95c271da2b5168e0d
#define StringPool_ClassName "%f5cff05c659516490e0ccbb95c271da2b5168e0d"
#define StringPool_ClassNameShort "%f5cff05c659516490e0ccbb95c271da2b5168e0d"
#define StringPool_TypeDefinitionIndex 5429

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x108;

		// Functions
		constexpr const static size_t Get = 0x37f2440;
	}

	// obf name: ::%faf63a382b19ae1bd7c1670cb2115096493c9247
#define Network_Networkable_ClassName "%faf63a382b19ae1bd7c1670cb2115096493c9247"
#define Network_Networkable_ClassNameShort "%faf63a382b19ae1bd7c1670cb2115096493c9247"
#define Network_Networkable_TypeDefinitionIndex 19783

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x58;
	}

	// obf name: ::%763ff9015469afca9c96d41effec830e7650a28b
#define Network_Net_ClassName "%763ff9015469afca9c96d41effec830e7650a28b"
#define Network_Net_ClassNameShort "%763ff9015469afca9c96d41effec830e7650a28b"
#define Network_Net_TypeDefinitionIndex 8136

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x58;
	}

	// obf name: ::%28bddf12b286a3f0c18e46cf297a439fd077953d
#define Network_Client_ClassName "%28bddf12b286a3f0c18e46cf297a439fd077953d"
#define Network_Client_ClassNameShort "%28bddf12b286a3f0c18e46cf297a439fd077953d"
#define Network_Client_TypeDefinitionIndex 19802

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf8;
		constexpr const static size_t ConnectedPort = 0x100;
		constexpr const static size_t ConnectedAddress = 0x108;
		constexpr const static size_t ServerName = 0x110;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x6662aa0;
		constexpr const static size_t DestroyNetworkable = 0x6662cf0;
	}

	// obf name: ::%5091769e946629d8bf99a864b9b98324172ec7a7
#define Network_BaseNetwork_ClassName "%5091769e946629d8bf99a864b9b98324172ec7a7"
#define Network_BaseNetwork_ClassNameShort "%5091769e946629d8bf99a864b9b98324172ec7a7"
#define Network_BaseNetwork_TypeDefinitionIndex 19786

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x6642b60;
	}

	// obf name: ::%014060d17992c939dec5f8fca692f7625c527308
#define Network_SendInfo_ClassName "%014060d17992c939dec5f8fca692f7625c527308"
#define Network_SendInfo_ClassNameShort "%014060d17992c939dec5f8fca692f7625c527308"
#define Network_SendInfo_TypeDefinitionIndex 19767

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%94d8887b3bbd7c62f5d0f19faa94cfc78768f905
#define Network_Message_ClassName "%94d8887b3bbd7c62f5d0f19faa94cfc78768f905"
#define Network_Message_ClassNameShort "%94d8887b3bbd7c62f5d0f19faa94cfc78768f905"
#define Network_Message_TypeDefinitionIndex 19760

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x20;
		constexpr const static size_t read = 0x18;
	}

	// obf name: ::%e00f0672886efceb568cc74ac6f65dd40fccafb2
#define Network_NetRead_ClassName "%e00f0672886efceb568cc74ac6f65dd40fccafb2"
#define Network_NetRead_ClassNameShort "%e00f0672886efceb568cc74ac6f65dd40fccafb2"
#define Network_NetRead_TypeDefinitionIndex 19799

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x40;
	}

	// obf name: ::%5a82ca0a6fd1924edd2029c82ef55b2c54ebda8d
#define Network_NetWrite_ClassName "%5a82ca0a6fd1924edd2029c82ef55b2c54ebda8d"
#define Network_NetWrite_ClassNameShort "%5a82ca0a6fd1924edd2029c82ef55b2c54ebda8d"
#define Network_NetWrite_TypeDefinitionIndex 19793

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x48;

		// Functions
		constexpr const static size_t WriteByte = 0x66501b0;
		constexpr const static size_t String = 0x6656590;
		constexpr const static size_t Send = 0x6653270;
	}

#define LootPanel_TypeDefinitionIndex 6624

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x45fba70;
	}

#define UIInventory_TypeDefinitionIndex 6673

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x46b2d40;
	}

#define GrowableEntity_TypeDefinitionIndex 1647

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c8;
		constexpr const static size_t State = 0x2d8;
	}

#define PlantProperties_TypeDefinitionIndex 3532

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 3531

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 21649

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 9567

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
		constexpr const static size_t get_Instance = 0x98ad70;
	}

	// obf name: ::%9f86673693235e949bbaea4e76cb22cce94e3ae2
#define TOD_Sky_Static_ClassName "TOD_Sky/%9f86673693235e949bbaea4e76cb22cce94e3ae2"
#define TOD_Sky_Static_ClassNameShort "%9f86673693235e949bbaea4e76cb22cce94e3ae2"
#define TOD_Sky_Static_TypeDefinitionIndex 9566

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x98;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 8712

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0x72ab00;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 8560

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9749

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 10002

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 10375

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 8580

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8325

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 1880

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 1638

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 2989

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 163

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

#define EnvironmentManager_TypeDefinitionIndex 5095

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x349f5c0;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%723166405cf6deaf01da0a8a5d74a96bbc3e18a3/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24776

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 7091

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 7092

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 1676

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
		constexpr const static size_t InstanceList = 0x30;
	}

	// obf name: ::%f5f00f8adeb108d684a66434dfb64653f9033eab
#define ListHashSet_ClassName "%f5f00f8adeb108d684a66434dfb64653f9033eab<UIChat>"
#define ListHashSet_ClassNameShort "%f5f00f8adeb108d684a66434dfb64653f9033eab"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 2839

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x280;
		constexpr const static size_t weakspots = 0x3e8;
	}

#define Chainsaw_TypeDefinitionIndex 2979

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x394;
	}

	// obf name: ::%a60e19fa77bcc100d14db7cdd67ed93e356ea5f6
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%a60e19fa77bcc100d14db7cdd67ed93e356ea5f6"
#define CameraUpdateHook_Static_ClassNameShort "%a60e19fa77bcc100d14db7cdd67ed93e356ea5f6"
#define CameraUpdateHook_Static_TypeDefinitionIndex 3322

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x18;
	}

#define SteamClientWrapper_TypeDefinitionIndex 3636

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x25de190;
	}

	// obf name: ::%f5f3544a1469305262cf76956efa0e3b833e2847
#define AimConeUtil_ClassName "%f5f3544a1469305262cf76956efa0e3b833e2847"
#define AimConeUtil_ClassNameShort "%f5f3544a1469305262cf76956efa0e3b833e2847"
#define AimConeUtil_TypeDefinitionIndex 3411

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x233a840;
	}

	// obf name: ::%b5de2f855121d1c98ade011f3e0065eb3a930bd7
#define Buttons_ConButton_ClassName "%867e3f2d06c1c4314f8ce1dac0ad455db9ca358f/%b5de2f855121d1c98ade011f3e0065eb3a930bd7"
#define Buttons_ConButton_ClassNameShort "%b5de2f855121d1c98ade011f3e0065eb3a930bd7"
#define Buttons_ConButton_TypeDefinitionIndex 3483

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%5a27baa970ad289c35e85ff22c59291c45f72292
#define Buttons_Static_ClassName "%867e3f2d06c1c4314f8ce1dac0ad455db9ca358f/%5a27baa970ad289c35e85ff22c59291c45f72292"
#define Buttons_Static_ClassNameShort "%5a27baa970ad289c35e85ff22c59291c45f72292"
#define Buttons_Static_TypeDefinitionIndex 3484

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0xd88;
		constexpr const static size_t Attack = 0xbe0;
		constexpr const static size_t Attack2 = 0xb38;
		constexpr const static size_t Forward = 0x270;
		constexpr const static size_t Backward = 0x338;
		constexpr const static size_t Right = 0xe40;
		constexpr const static size_t Left = 0x7d0;
		constexpr const static size_t Sprint = 0x20;
		constexpr const static size_t Use = 0x778;

		// Functions
		constexpr const static size_t Pets_setter = 0x3e16dc0;
	}

#define PlayerModel_TypeDefinitionIndex 873

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x1f0;
		constexpr const static size_t position = 0x1f8;
		constexpr const static size_t newVelocity = 0x21c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 3418

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x50;
	}

#define BaseMountable_TypeDefinitionIndex 4881

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x29c;
		constexpr const static size_t yawClamp = 0x2a4;
		constexpr const static size_t canWieldItems = 0x2ac;
	}

#define ProgressBar_TypeDefinitionIndex 1181

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 6831

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x418;
		constexpr const static size_t wasAiming = 0x428;
	}

#define CrossbowWeapon_TypeDefinitionIndex 4174

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 1700

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%e1ffe184afe066e8784b055bb9dd5a285177bc86
#define ConVar_Admin_Static_ClassName "%541d1b76a12933812be20b1ab7226529f8f2dec3/%e1ffe184afe066e8784b055bb9dd5a285177bc86"
#define ConVar_Admin_Static_ClassNameShort "%e1ffe184afe066e8784b055bb9dd5a285177bc86"
#define ConVar_Admin_Static_TypeDefinitionIndex 5886

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x104;

		// Functions
		constexpr const static size_t admintime_getter = 0x3e27750;
		constexpr const static size_t admintime_setter = 0x3e059c0;
	}

	// obf name: ::%7830855d8ec2051b250daf5f39419f999c8eb5ee
#define ConVar_Player_Static_ClassName "%933285de20eaf78422987a1d72125c03743cbad4/%7830855d8ec2051b250daf5f39419f999c8eb5ee"
#define ConVar_Player_Static_ClassNameShort "%7830855d8ec2051b250daf5f39419f999c8eb5ee"
#define ConVar_Player_Static_TypeDefinitionIndex 6641

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x130;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x3e36500;
		constexpr const static size_t clientTickRate_setter = 0x3e51ff0;
	}

#define ColliderInfo_TypeDefinitionIndex 5966

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 5675

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x220;
		constexpr const static size_t HasAuth = 0x230;
		constexpr const static size_t HasGuestAuth = 0x231;
	}

#define AutoTurret_TypeDefinitionIndex 3372

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x378;
		constexpr const static size_t lastYaw = 0x3d8;
		constexpr const static size_t muzzlePos = 0x3f8;
		constexpr const static size_t gun_yaw = 0x410;
		constexpr const static size_t gun_pitch = 0x418;
		constexpr const static size_t sightRange = 0x420;
	}

#define Client_TypeDefinitionIndex 3009

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x1e7d350;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%fcf373903711cf42615aa81ff5b9b517ec79e94b
#define ItemManager_Static_ClassName "%a5693b06182222945134c06e98be22c7d3d2efee/%fcf373903711cf42615aa81ff5b9b517ec79e94b"
#define ItemManager_Static_ClassNameShort "%fcf373903711cf42615aa81ff5b9b517ec79e94b"
#define ItemManager_Static_TypeDefinitionIndex 5415

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x40;
		constexpr const static size_t itemDictionary = 0x1d8;
		constexpr const static size_t itemDictionaryByName = 0x58;
	}

	// obf name: ::%e197993d3645ab2bfe81e7ef15774867da955ec5
#define ConVar_Server_Static_ClassName "%c1bf9dcf0f300aed684781131388dcf1f9183b15/%e197993d3645ab2bfe81e7ef15774867da955ec5"
#define ConVar_Server_Static_ClassNameShort "%e197993d3645ab2bfe81e7ef15774867da955ec5"
#define ConVar_Server_Static_TypeDefinitionIndex 3048

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 1813

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x102fbd0;
	}

#define LoadingScreen_TypeDefinitionIndex 5224

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x30;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 6413

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%84f3f4b711e469e9efe2d332e1ad468077929646"
#define MapView_Static_ClassNameShort "%84f3f4b711e469e9efe2d332e1ad468077929646"
#define MapView_TypeDefinitionIndex 1241

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x0;
	}

	// obf name: ::%1a3b31e81349358e8d8f30608f4d7313e913514e
#define GamePhysics_Static_ClassName "%92946689538565638fed26fc7901ce07cda60024/%1a3b31e81349358e8d8f30608f4d7313e913514e"
#define GamePhysics_Static_ClassNameShort "%1a3b31e81349358e8d8f30608f4d7313e913514e"
#define GamePhysics_Static_TypeDefinitionIndex 2847

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0xa0;
	}

	// obf name: ::%92946689538565638fed26fc7901ce07cda60024
#define GamePhysics_ClassName "%92946689538565638fed26fc7901ce07cda60024"
#define GamePhysics_ClassNameShort "%92946689538565638fed26fc7901ce07cda60024"
#define GamePhysics_TypeDefinitionIndex 2848

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x1c70db0;
		constexpr const static size_t LineOfSightInternal = 0x1c7feb0;
		constexpr const static size_t Verify = 0x1c67600;
	}

#define InstancedDebugDraw_TypeDefinitionIndex 7052

	namespace InstancedDebugDraw {

		// Functions
		constexpr const static size_t AddInstance = 0x4adc260;
	}

	// obf name: ::%c5764343a99941c0a11af9bc3d206e1616cace75
#define RaycastHitEx_ClassName "%c5764343a99941c0a11af9bc3d206e1616cace75"
#define RaycastHitEx_ClassNameShort "%c5764343a99941c0a11af9bc3d206e1616cace75"
#define RaycastHitEx_TypeDefinitionIndex 6353

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x435b2c0;
	}

	// obf name: ::%173f57ad4875adac1f623a71b199827d6183527c
#define OnParentDestroyingEx_ClassName "%173f57ad4875adac1f623a71b199827d6183527c"
#define OnParentDestroyingEx_ClassNameShort "%173f57ad4875adac1f623a71b199827d6183527c"
#define OnParentDestroyingEx_TypeDefinitionIndex 5379

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x370c910;
	}

	// obf name: ::%c1fecc97a77e2413dfeeb0e89dd0d0fe079cba85
#define ConsoleNetwork_ClassName "%c1fecc97a77e2413dfeeb0e89dd0d0fe079cba85"
#define ConsoleNetwork_ClassNameShort "%c1fecc97a77e2413dfeeb0e89dd0d0fe079cba85"
#define ConsoleNetwork_TypeDefinitionIndex 1643

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0xe581f0;
	}

#define ThrownWeapon_TypeDefinitionIndex 4268

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e8;
	}

#define MapInterface_TypeDefinitionIndex 6857

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 2037

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 1241

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 5707

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c8;
	}

#define PlayerCorpse_TypeDefinitionIndex 73

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f8;
	}

#define TimedExplosive_TypeDefinitionIndex 2851

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1bc;
	}

#define SmokeGrenade_TypeDefinitionIndex 5155

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x260;
	}

#define GrenadeWeapon_TypeDefinitionIndex 6577

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x300;
	}

#define ViewmodelLower_TypeDefinitionIndex 2707

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%9f085a0b90a3fe382bd203e43df005f427473090
#define ConVar_Client_Static_ClassName "%53f541519a505b0523cf5ab028f0af791f9cad57/%9f085a0b90a3fe382bd203e43df005f427473090"
#define ConVar_Client_Static_ClassNameShort "%9f085a0b90a3fe382bd203e43df005f427473090"
#define ConVar_Client_Static_TypeDefinitionIndex 4953

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x830;
		constexpr const static size_t camspeed = 0x754;
	}

#define SamSite_TypeDefinitionIndex 1134

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b8;
		constexpr const static size_t Flag_TargetMode = 0x3f4;
	}

#define ServerProjectile_TypeDefinitionIndex 978

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 2207

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 2822

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 783

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 3620

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 7461

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 172

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%94725e92d3e0f26335f9a535b45d4f690d1cb18b
#define Facepunch_Network_Raknet_Client_ClassName "%94725e92d3e0f26335f9a535b45d4f690d1cb18b"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%94725e92d3e0f26335f9a535b45d4f690d1cb18b"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 23459

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x66e6ec0;
		constexpr const static size_t IsConnected_vtableoff = 0x2e8;
	}

	// obf name: ::%7b644347e22dde2366010891a21416619334bcec
#define EncryptedValue_ClassName "%7b644347e22dde2366010891a21416619334bcec<System/Int32>"
#define EncryptedValue_ClassNameShort "%7b644347e22dde2366010891a21416619334bcec"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%5668ce76effdc7b2b281c5100f8b1c1e0bd8d79f
#define HiddenValue_ClassName "%5668ce76effdc7b2b281c5100f8b1c1e0bd8d79f<BaseNetworkable/%efaa0b174ce665aea1af01e67f6f48014846485e>"
#define HiddenValue_ClassNameShort "%5668ce76effdc7b2b281c5100f8b1c1e0bd8d79f"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define ItemModRFListener_TypeDefinitionIndex 2113

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x13278c0;
	}

#define UIFogOverlay_TypeDefinitionIndex 2207

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x40;
	}

	// obf name: ::%e70dfe599960a7fc452b8c5d7867f59ced49b970
#define BufferStream_ClassName "%e70dfe599960a7fc452b8c5d7867f59ced49b970"
#define BufferStream_ClassNameShort "%e70dfe599960a7fc452b8c5d7867f59ced49b970"
#define BufferStream_TypeDefinitionIndex 7997

	namespace BufferStream {

		// Offsets
		constexpr const static size_t _buffer = 0x10;

		// Functions
		constexpr const static size_t EnsureCapacity = 0x9507ef0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 918

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 1433

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 1187

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x53856a0;
	}

#define OutlineManager_TypeDefinitionIndex 3369

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%91629f3f23a58fdb49e1aca65ab576f4a87dc97d
#define ConsoleSystem_Command_ClassName "%4f273e05fc773ee4cfe2dec53d85707492f810e8/%91629f3f23a58fdb49e1aca65ab576f4a87dc97d"
#define ConsoleSystem_Command_ClassNameShort "%91629f3f23a58fdb49e1aca65ab576f4a87dc97d"
#define ConsoleSystem_Command_TypeDefinitionIndex 24021

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x10;
		constexpr const static size_t SetOveride = 0x88;
		constexpr const static size_t Call = 0x18;
	}

	// obf name: ::%f4519156e38d599a807c1db086a52a0e3ee3069a
#define ConsoleSystem_Option_ClassName "%4f273e05fc773ee4cfe2dec53d85707492f810e8/%f4519156e38d599a807c1db086a52a0e3ee3069a"
#define ConsoleSystem_Option_ClassNameShort "%f4519156e38d599a807c1db086a52a0e3ee3069a"
#define ConsoleSystem_Option_TypeDefinitionIndex 24031

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%577dc0ef5bc7d3844cc42b33cb1d6b72a11f6201
#define ConsoleSystem_Arg_ClassName "%4f273e05fc773ee4cfe2dec53d85707492f810e8/%577dc0ef5bc7d3844cc42b33cb1d6b72a11f6201"
#define ConsoleSystem_Arg_ClassNameShort "%577dc0ef5bc7d3844cc42b33cb1d6b72a11f6201"
#define ConsoleSystem_Arg_TypeDefinitionIndex 24019

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x30;
	}

	// obf name: ::%b77c6dbd17dc495f544f14cb8d1eb1cffe93741f
#define ConsoleSystem_Index_Client_ClassName "%4f273e05fc773ee4cfe2dec53d85707492f810e8/%27ed6c9f358665329f4f1fec8f89a75e1f327188.%b77c6dbd17dc495f544f14cb8d1eb1cffe93741f"
#define ConsoleSystem_Index_Client_ClassNameShort "%b77c6dbd17dc495f544f14cb8d1eb1cffe93741f"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 24027

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x65af240;
	}

#define String_TypeDefinitionIndex 10831

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x87a0290;
	}

	// obf name: ::%06234647570c0104389a92e86a6ec22cb5247de4
#define EntityRef_ClassName "%06234647570c0104389a92e86a6ec22cb5247de4"
#define EntityRef_ClassNameShort "%06234647570c0104389a92e86a6ec22cb5247de4"
#define EntityRef_TypeDefinitionIndex 5905

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x3d660d0;
	}

#define ConVar_Debugging_TypeDefinitionIndex -1

	namespace ConVar_Debugging {

		// Functions
		constexpr const static size_t debugcamera = 0x3e04800;
		constexpr const static size_t noclip = 0x256edf0;
	}

#define CursorManager_TypeDefinitionIndex 2111

	namespace CursorManager {

		// Offsets
	}

	// obf name: ::%82ff370d59079df29c6374be4017ca3a2e58cfac
#define ProtoBuf_ProjectileShoot_ClassName "%82ff370d59079df29c6374be4017ca3a2e58cfac"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%82ff370d59079df29c6374be4017ca3a2e58cfac"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7774

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9c7c5c0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9c7c260;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%8c388995b961d21d57036de6e47b7467ec9eecf2
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%82ff370d59079df29c6374be4017ca3a2e58cfac/%8c388995b961d21d57036de6e47b7467ec9eecf2"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%8c388995b961d21d57036de6e47b7467ec9eecf2"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7773

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t startPos = 0x28;
		constexpr const static size_t startVel = 0x14;
		constexpr const static size_t seed = 0x34;
	}

	// obf name: ::%e19d0120960b8806f1903829445bda677e3649c6
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%e19d0120960b8806f1903829445bda677e3649c6"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%e19d0120960b8806f1903829445bda677e3649c6"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7549

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t curPosition = 0x28;
		constexpr const static size_t curVelocity = 0x18;
		constexpr const static size_t travelTime = 0x24;
		constexpr const static size_t ShouldPool = 0x11;

		// Functions
		constexpr const static size_t Dispose = 0x8ecb0b0;
		constexpr const static size_t WriteToStreamDelta = 0x8ed1a00;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8ec8b70;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%40c989b4c6cf1261467203bfcc30358592854e6b
#define ProtoBuf_PlayerProjectileAttack_ClassName "%40c989b4c6cf1261467203bfcc30358592854e6b"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%40c989b4c6cf1261467203bfcc30358592854e6b"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7600

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x28;
		constexpr const static size_t hitDistance = 0x10;
		constexpr const static size_t travelTime = 0x14;
		constexpr const static size_t playerAttack = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9662c40;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9664510;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%86baa117f142eb13907fbe613087ae59dc58a974
#define ProtoBuf_PlayerAttack_ClassName "%86baa117f142eb13907fbe613087ae59dc58a974"
#define ProtoBuf_PlayerAttack_ClassNameShort "%86baa117f142eb13907fbe613087ae59dc58a974"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7644

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x24;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%2433424ce51ae272a8dbc682447bb03a54494bd4
#define ProtoBuf_Attack_ClassName "%2433424ce51ae272a8dbc682447bb03a54494bd4"
#define ProtoBuf_Attack_ClassNameShort "%2433424ce51ae272a8dbc682447bb03a54494bd4"
#define ProtoBuf_Attack_TypeDefinitionIndex 7982

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x6c;
		constexpr const static size_t pointEnd = 0x3c;
		constexpr const static size_t hitID = 0x60;
		constexpr const static size_t hitBone = 0x68;
		constexpr const static size_t hitNormalLocal = 0x78;
		constexpr const static size_t hitPositionLocal = 0x30;
		constexpr const static size_t hitNormalWorld = 0x20;
		constexpr const static size_t hitPositionWorld = 0x4c;
		constexpr const static size_t hitPartID = 0x58;
		constexpr const static size_t hitMaterialID = 0x2c;
		constexpr const static size_t srcParentID = 0x10;
		constexpr const static size_t dstParentID = 0x18;
	}
}