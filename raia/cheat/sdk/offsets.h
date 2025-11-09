#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x690f239b;
		constexpr const static size_t gc_handles = 0xd51b230;
		constexpr const static size_t il2cpp_resolve_icall = 0x5c21f0;
		constexpr const static size_t il2cpp_array_new = 0x5c2210;
		constexpr const static size_t il2cpp_assembly_get_image = 0x16150;
		constexpr const static size_t il2cpp_class_from_name = 0x5c2380;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x5c2690;
		constexpr const static size_t il2cpp_class_get_type = 0x5c2730;
		constexpr const static size_t il2cpp_domain_get = 0x5c2c90;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x5c2cb0;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x5c3570;
		constexpr const static size_t il2cpp_gchandle_new = 0x5c3520;
		constexpr const static size_t il2cpp_gchandle_free = 0x5c3610;
		constexpr const static size_t il2cpp_method_get_name = 0x2d30;
		constexpr const static size_t il2cpp_object_new = 0x5c3cc0;
		constexpr const static size_t il2cpp_type_get_object = 0x5c44b0;
	}

#define Object_TypeDefinitionIndex 17063

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xaf7a710;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 17034

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

#define Component_TypeDefinitionIndex 17021

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 17015

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 17098

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xaf86140;
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

#define Camera_TypeDefinitionIndex 16813

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

#define Time_TypeDefinitionIndex 17085

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

#define Material_TypeDefinitionIndex 16876

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16872

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xaf3a610;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16875

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xaf3dfa0;
		constexpr const static size_t PropertyToID = 0xaa6a0;
		constexpr const static size_t GetPropertyCount = 0xaea30;
		constexpr const static size_t GetPropertyName = 0xad8f0;
		constexpr const static size_t GetPropertyType = 0xadb90;
	}

#define Mesh_TypeDefinitionIndex 16931

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

#define Renderer_TypeDefinitionIndex 16873

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterial = 0x9ffe0;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16934

	namespace Texture {

		// Functions
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16936

	namespace Texture2D {

		// Functions
		constexpr const static size_t ctor = 0xaf53c90;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define Sprite_TypeDefinitionIndex 17104

	namespace Sprite {

		// Functions
		constexpr const static size_t get_texture = 0x119300;
	}

#define RenderTexture_TypeDefinitionIndex 16941

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xaf5c940;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17411

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xafa0690;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17387

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xaf9a4e0;
	}

#define ComputeBuffer_TypeDefinitionIndex 17076

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xaf7e290;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xaf7e4e0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16880

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xaf44d40;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xaf44a70;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 22346

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xafc2dc0;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16853

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16964

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24785

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16850

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24677

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

#define Application_TypeDefinitionIndex 16796

	namespace Application {

		// Functions
		constexpr const static size_t get_version = 0x5f350;
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16962

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23634

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xb009250;
		constexpr const static size_t RaycastNonAlloc = 0xb00b920;
		constexpr const static size_t CheckCapsule = 0xb00d0f0;
	}

#define Image_TypeDefinitionIndex 21231

	namespace Image {

		// Offsets
		constexpr const static size_t m_Sprite = 0xd0;
	}

#define GraphicsSettings_TypeDefinitionIndex 17409

	namespace GraphicsSettings {

		// Functions
		constexpr const static size_t get_INTERNAL_defaultRenderPipeline = 0x127f00;
	}

#define BaseNetworkable_TypeDefinitionIndex 5764

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x28;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x40;
	}

	// obf name: ::%319a7219ff8473dcd97f2fca31ca79c4fc3882f9
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%319a7219ff8473dcd97f2fca31ca79c4fc3882f9"
#define BaseNetworkable_Static_ClassNameShort "%319a7219ff8473dcd97f2fca31ca79c4fc3882f9"
#define BaseNetworkable_Static_TypeDefinitionIndex 5763

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x20;
	}

	// obf name: ::%1f51a2517ef3ffd3b51ac024cf55fdbac84e5bb7
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%1f51a2517ef3ffd3b51ac024cf55fdbac84e5bb7"
#define BaseNetworkable_EntityRealm_ClassNameShort "%1f51a2517ef3ffd3b51ac024cf55fdbac84e5bb7"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 5761

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x3a5f110;
	}

	// obf name: ::%21cb5c3b47e37e7b22a92604494704285b638558
#define System_ListDictionary_ClassName "%21cb5c3b47e37e7b22a92604494704285b638558<%ae04c6bbd32a1477fdc1c8cf05109f1d0e965e9c,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%21cb5c3b47e37e7b22a92604494704285b638558"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x10;

		// Functions
		constexpr const static size_t TryGetValue = 0x6d3f7c0;
		constexpr const static size_t TryGetValue_methodinfo = 0xd1bd6f0;
	}

	// obf name: ::%9da2bd96b1b0e8bfd0670320514502a263d23013
#define System_BufferList_ClassName "%9da2bd96b1b0e8bfd0670320514502a263d23013<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%9da2bd96b1b0e8bfd0670320514502a263d23013"
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
		constexpr const static size_t Instance = 0x20;
	}

#define Model_TypeDefinitionIndex 6771

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t eyeBone = 0x38;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 3232

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0x158;
		constexpr const static size_t positionLerp = 0x130;

		// Functions
		constexpr const static size_t ServerRPC = 0x1f28b90;
		constexpr const static size_t FindBone = 0x1f2c870;
		constexpr const static size_t GetWorldVelocity = 0x1f41520;
		constexpr const static size_t GetParentVelocity = 0x1f41520;
	}

	// obf name: ::%57cbc0c6f930f9e6e9991010e9bd25c6a26d5b3f
#define PositionLerp_ClassName "%57cbc0c6f930f9e6e9991010e9bd25c6a26d5b3f"
#define PositionLerp_ClassNameShort "%57cbc0c6f930f9e6e9991010e9bd25c6a26d5b3f"
#define PositionLerp_TypeDefinitionIndex 2597

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x30;
	}

	// obf name: ::%e5b7ceec0e3aa6667558a0945312784fbeb6ccda
#define Interpolator_ClassName "%e5b7ceec0e3aa6667558a0945312784fbeb6ccda<%7d8fe19b229fb41e6871a5f1ddcef98b6fe6511e>"
#define Interpolator_ClassNameShort "%e5b7ceec0e3aa6667558a0945312784fbeb6ccda"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 6709

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

#define SkeletonProperties_TypeDefinitionIndex 763

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 761

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 6969

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 6968

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%9a9736971eeb4378257b6e3e3a9d4dfb86fe0ce1
#define DamageTypeList_ClassName "%9a9736971eeb4378257b6e3e3a9d4dfb86fe0ce1"
#define DamageTypeList_ClassNameShort "%9a9736971eeb4378257b6e3e3a9d4dfb86fe0ce1"
#define DamageTypeList_TypeDefinitionIndex 4032

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 3683

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 4266

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
		constexpr const static size_t ItemModWearable = 0x188;
	}

#define RecoilProperties_TypeDefinitionIndex 5836

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

#define BaseProjectile_Magazine_Definition_TypeDefinitionIndex 7217

	namespace BaseProjectile_Magazine_Definition {

		// Offsets
		constexpr const static size_t builtInSize = 0x0;
	}

#define BaseProjectile_Magazine_TypeDefinitionIndex 7218

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t definition = 0x10;
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 6880

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x484c260;
		constexpr const static size_t StartAttackCooldown = 0x484e810;
	}

#define BaseProjectile_TypeDefinitionIndex 7223

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
		constexpr const static size_t LaunchProjectile = 0x4c4e110;
		constexpr const static size_t LaunchProjectileClientSide = 0x4c4c320;
		constexpr const static size_t ScaleRepeatDelay = 0x4c48df0;
		constexpr const static size_t GetAimCone = 0x4c47900;
		constexpr const static size_t GetAimCone_vtableoff = 0x3fc8;
		constexpr const static size_t UpdateAmmoDisplay = 0x4c33b20;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3dd8;
	}

#define BaseLauncher_TypeDefinitionIndex 6378

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 4015

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%5fd71201ea98cf9272d6478e7513d82189b8dd65
#define HitTest_ClassName "%5fd71201ea98cf9272d6478e7513d82189b8dd65"
#define HitTest_ClassNameShort "%5fd71201ea98cf9272d6478e7513d82189b8dd65"
#define HitTest_TypeDefinitionIndex 7131

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0xac;
		constexpr const static size_t AttackRay = 0x30;
		constexpr const static size_t RayHit = 0x68;
		constexpr const static size_t damageProperties = 0x98;
		constexpr const static size_t gameObject = 0xb0;
		constexpr const static size_t collider = 0x58;
		constexpr const static size_t ignoredTypes = 0xc8;
		constexpr const static size_t HitTransform = 0xd8;
		constexpr const static size_t HitPart = 0x64;
		constexpr const static size_t HitMaterial = 0xc0;
		constexpr const static size_t DidHit = 0x20;
		constexpr const static size_t MaxDistance = 0x60;
		constexpr const static size_t HitPoint = 0x24;
		constexpr const static size_t HitNormal = 0xa0;
		constexpr const static size_t ignoreEntity = 0x18;
		constexpr const static size_t HitEntity = 0x48;
	}

#define Projectile_TypeDefinitionIndex 4928

	namespace Projectile {

		// Offsets
		constexpr const static size_t initialVelocity = 0x28;
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t thickness = 0x3c;
		constexpr const static size_t initialDistance = 0x44;
		constexpr const static size_t swimScale = 0xf0;
		constexpr const static size_t swimSpeed = 0xfc;
		constexpr const static size_t owner = 0x120;
		constexpr const static size_t sourceProjectilePrefab = 0x108;
		constexpr const static size_t mod = 0x1d0;
		constexpr const static size_t hitTest = 0x110;
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
		constexpr const static size_t CalculateEffectScale = 0x3157a50;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x3f8;
		constexpr const static size_t SetEffectScale = 0x313f5a0;
		constexpr const static size_t UpdateVelocity = 0x3158650;
		constexpr const static size_t Retire = 0x31361b0;
		constexpr const static size_t DoHit = 0x3129820;
	}

	// obf name: ::%08f7e76630592c8728ce8448006e74da002fbc71
#define HitInfo_ClassName "%08f7e76630592c8728ce8448006e74da002fbc71"
#define HitInfo_ClassNameShort "%08f7e76630592c8728ce8448006e74da002fbc71"
#define HitInfo_TypeDefinitionIndex 493

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0xd8;
		constexpr const static size_t damageTypes = 0xe8;

		// Functions
		constexpr const static size_t get_boneArea = 0x2d9e100;
	}

	// obf name: ::%634bd5afd1fbe2c2f5f33ffb78dd711a2bc698ad
#define GameTrace_ClassName "%634bd5afd1fbe2c2f5f33ffb78dd711a2bc698ad"
#define GameTrace_ClassNameShort "%634bd5afd1fbe2c2f5f33ffb78dd711a2bc698ad"
#define GameTrace_TypeDefinitionIndex 607

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x39dbef0;
	}

#define BaseMelee_TypeDefinitionIndex 5517

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x371f690;
		constexpr const static size_t DoThrow = 0x3715a60;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 5873

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x410;
		constexpr const static size_t strikeRecoil = 0x418;
		constexpr const static size_t _didSparkThisFrame = 0x420;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 3624

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x428;
		constexpr const static size_t stringBonusVelocity = 0x434;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x23a0710;
	}

	// obf name: ::%28ba1a708507345b93a467053e03a55ee3af70e0
#define ItemContainer_ClassName "%28ba1a708507345b93a467053e03a55ee3af70e0"
#define ItemContainer_ClassNameShort "%28ba1a708507345b93a467053e03a55ee3af70e0"
#define ItemContainer_TypeDefinitionIndex 6431

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x78;
		constexpr const static size_t itemList = 0x50;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x42a6740;
	}

#define PlayerLoot_TypeDefinitionIndex 1140

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 705

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerMain = 0x38;
		constexpr const static size_t containerWear = 0x58;
		constexpr const static size_t containerBelt = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x4695790;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 947

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x4e872f0;
		constexpr const static size_t get_rotation = 0x4e8bfe0;
		constexpr const static size_t set_rotation = 0x4ea86f0;
		constexpr const static size_t HeadForward = 0x4e8c270;
	}

	// obf name: ::%1f0a57613d51bfc82652113edf6256b02f576770
#define PlayerEyes_Static_ClassName "PlayerEyes/%1f0a57613d51bfc82652113edf6256b02f576770"
#define PlayerEyes_Static_ClassNameShort "%1f0a57613d51bfc82652113edf6256b02f576770"
#define PlayerEyes_Static_TypeDefinitionIndex 946

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x16c;
	}

	// obf name: ::%b50eeb562c8139594d5616d6908ca4f615c316c8
#define PlayerBelt_ClassName "%b50eeb562c8139594d5616d6908ca4f615c316c8"
#define PlayerBelt_ClassNameShort "%b50eeb562c8139594d5616d6908ca4f615c316c8"
#define PlayerBelt_TypeDefinitionIndex 5019

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x3257dd0;
		constexpr const static size_t GetActiveItem = 0x3259e80;
	}

	// obf name: ::%6e643d0010c13217a5d86e1ff89b67fffa4bb04f
#define LocalPlayer_ClassName "%6e643d0010c13217a5d86e1ff89b67fffa4bb04f"
#define LocalPlayer_ClassNameShort "%6e643d0010c13217a5d86e1ff89b67fffa4bb04f"
#define LocalPlayer_TypeDefinitionIndex 5385

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x35c15a0;
		constexpr const static size_t MoveItem = 0x35c7b80;
		constexpr const static size_t get_Entity = 0x35b8690;
	}

	// obf name: ::%2d292b7f4eac3b9f6a76ef3f8ece36bb1d8ebc8d
#define LocalPlayer_Static_ClassName "%6e643d0010c13217a5d86e1ff89b67fffa4bb04f/%2d292b7f4eac3b9f6a76ef3f8ece36bb1d8ebc8d"
#define LocalPlayer_Static_ClassNameShort "%2d292b7f4eac3b9f6a76ef3f8ece36bb1d8ebc8d"
#define LocalPlayer_Static_TypeDefinitionIndex 5384

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x40;
	}

	// obf name: ::%815f36d8efdefc38b014b131c5ca625a29a11ece
#define BasePlayer_Static_ClassName "BasePlayer/%815f36d8efdefc38b014b131c5ca625a29a11ece"
#define BasePlayer_Static_ClassNameShort "%815f36d8efdefc38b014b131c5ca625a29a11ece"
#define BasePlayer_Static_TypeDefinitionIndex 6236

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x17e8;
	}

#define BasePlayer_TypeDefinitionIndex 6237

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x478;
		constexpr const static size_t input = 0x2d0;
		constexpr const static size_t movement = 0x5b0;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x290;
		constexpr const static size_t playerFlags = 0x5a8;
		constexpr const static size_t eyes = 0x360;
		constexpr const static size_t playerRigidbody = 0x4d8;
		constexpr const static size_t userID = 0x5f0;
		constexpr const static size_t UserIDString = 0x458;
		constexpr const static size_t inventory = 0x3c0;
		constexpr const static size_t _displayName = 0x5c0;
		constexpr const static size_t _lookingAt = 0x2b8;
		constexpr const static size_t lastSentTickTime = 0x564;
		constexpr const static size_t lastSentTick = 0x320;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x550;
		constexpr const static size_t _lookingAtEntity = 0x610;
		constexpr const static size_t currentGesture = 0x600;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x4075560;
		constexpr const static size_t Menu_AssistPlayer = 0x3f00150;
		constexpr const static size_t OnViewModeChanged = 0x402f820;
		constexpr const static size_t ChatMessage = 0x3faf250;
		constexpr const static size_t IsOnGround = 0x3eedaa0;
		constexpr const static size_t GetSpeed = 0x3f9f950;
		constexpr const static size_t SendProjectileUpdate = 0x3fe2c00;
		constexpr const static size_t SendProjectileAttack = 0x3f80510;
		constexpr const static size_t CanBuild = 0x401a520;
		constexpr const static size_t GetMounted = 0x3f99630;
		constexpr const static size_t GetHeldEntity = 0x3f86f90;
		constexpr const static size_t get_inventory = 0x3f402c0;
		constexpr const static size_t get_eyes = 0x4054c50;
		constexpr const static size_t SendClientTick = 0x3f8ddb0;
		constexpr const static size_t ClientInput = 0x3f5e650;
		constexpr const static size_t ClientInput_vtableoff = 0x3ac8;
		constexpr const static size_t MaxHealth = 0x3fae9c0;
		constexpr const static size_t MaxHealth_vtableoff = 0x2dd8;
		constexpr const static size_t OnAttacked = 0x3f03b90;
		constexpr const static size_t OnAttacked_vtableoff = 0x1f08;
		constexpr const static size_t get_idealViewMode = 0x404e730;
	}

#define ScientistNPC_TypeDefinitionIndex 328

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 2664

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 182

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 5231

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 2183

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 5415

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 597

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xd8;
		constexpr const static size_t ladder = 0xe8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x383a7e0;
		constexpr const static size_t BlockSprint = 0x3843b40;
		constexpr const static size_t GroundCheck = 0x385afa0;
		constexpr const static size_t Init = 0x383efc0;
		constexpr const static size_t ClientInput = 0x386bad0;
		constexpr const static size_t ClientInput_vtableoff = 0x438;
		constexpr const static size_t DoFixedUpdate = 0x3865df0;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x378;
		constexpr const static size_t FrameUpdate = 0x386afd0;
		constexpr const static size_t FrameUpdate_vtableoff = 0x1a8;
		constexpr const static size_t TeleportTo = 0x38607c0;
		constexpr const static size_t TeleportTo_vtableoff = 0x3a8;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 6203

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 6934

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 4445

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 215

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 211

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%f0267d300992b3de7f9b5fa8b1bfede2185e7c6a
#define ConsoleSystem_ClassName "%f0267d300992b3de7f9b5fa8b1bfede2185e7c6a"
#define ConsoleSystem_ClassNameShort "%f0267d300992b3de7f9b5fa8b1bfede2185e7c6a"
#define ConsoleSystem_TypeDefinitionIndex 23619

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x638efb0;
	}

	// obf name: ::%52e72efa3e4ea3b96e9d12feaec0bbc52cee261c
#define ConsoleSystem_Index_Static_ClassName "%f0267d300992b3de7f9b5fa8b1bfede2185e7c6a/%b1e414bf7de63ce834c52a9616965a45d5722de0.%52e72efa3e4ea3b96e9d12feaec0bbc52cee261c"
#define ConsoleSystem_Index_Static_ClassNameShort "%52e72efa3e4ea3b96e9d12feaec0bbc52cee261c"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23612

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x78;
	}

#define LootableCorpse_TypeDefinitionIndex 2654

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2a8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 3900

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 5036

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x90;
		constexpr const static size_t mainCameraTransform = 0x38;

		// Functions
		constexpr const static size_t Update = 0x32a99c0;
		constexpr const static size_t OnPreCull = 0x32a8280;
		constexpr const static size_t Trace = 0x32a2ef0;
	}

#define CameraMan_TypeDefinitionIndex 5623

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%d2e46eef5c0cb68dda8ae81ada94adc24015a272
#define PlayerTick_ClassName "%d2e46eef5c0cb68dda8ae81ada94adc24015a272"
#define PlayerTick_ClassNameShort "%d2e46eef5c0cb68dda8ae81ada94adc24015a272"
#define PlayerTick_TypeDefinitionIndex 7618

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x30;
		constexpr const static size_t modelState = 0x48;
		constexpr const static size_t activeItem = 0x40;
		constexpr const static size_t parentID = 0x50;
		constexpr const static size_t position = 0x10;
		constexpr const static size_t eyePos = 0x24;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8e47300;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8e40560;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%08d9e6ebf99bc5825e15c2e0970fed6857bd20cb
#define InputMessage_ClassName "%08d9e6ebf99bc5825e15c2e0970fed6857bd20cb"
#define InputMessage_ClassNameShort "%08d9e6ebf99bc5825e15c2e0970fed6857bd20cb"
#define InputMessage_TypeDefinitionIndex 7544

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x20;
		constexpr const static size_t aimAngles = 0x10;
		constexpr const static size_t mouseDelta = 0x28;
	}

	// obf name: ::%4b88400350cf62216335c3e6292827a724f7a09e
#define InputState_ClassName "%4b88400350cf62216335c3e6292827a724f7a09e"
#define InputState_ClassNameShort "%4b88400350cf62216335c3e6292827a724f7a09e"
#define InputState_TypeDefinitionIndex 2853

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x18;
		constexpr const static size_t previous = 0x10;
	}

#define PlayerInput_TypeDefinitionIndex 2833

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%8fa5cf4951c8ad73c878c110bfd5863da7669549
#define ModelState_ClassName "%8fa5cf4951c8ad73c878c110bfd5863da7669549"
#define ModelState_ClassNameShort "%8fa5cf4951c8ad73c878c110bfd5863da7669549"
#define ModelState_TypeDefinitionIndex 7398

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x10;
		constexpr const static size_t waterLevel = 0x28;
		constexpr const static size_t lookDir = 0x44;
	}

	// obf name: ::%705ed9788f875b88e6eccbc30499caa6a6d77bfc
#define Item_ClassName "%705ed9788f875b88e6eccbc30499caa6a6d77bfc"
#define Item_ClassNameShort "%705ed9788f875b88e6eccbc30499caa6a6d77bfc"
#define Item_TypeDefinitionIndex 4238

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0xb8;
		constexpr const static size_t uid = 0x90;
		constexpr const static size_t clientAmmoCount = 0x38;
		constexpr const static size_t _condition = 0x70;
		constexpr const static size_t _maxCondition = 0xa4;
		constexpr const static size_t position = 0x6c;
		constexpr const static size_t amount = 0xa0;
		constexpr const static size_t parent = 0xc8;
		constexpr const static size_t contents = 0xe0;
		constexpr const static size_t worldEnt = 0x48;
		constexpr const static size_t heldEntity = 0x80;

		// Functions
		constexpr const static size_t get_iconSprite = 0x2a32940;
	}

	// obf name: ::%d14c36427718255cc840e29a218c75a1d722c22f
#define WaterLevel_ClassName "%d14c36427718255cc840e29a218c75a1d722c22f"
#define WaterLevel_ClassNameShort "%d14c36427718255cc840e29a218c75a1d722c22f"
#define WaterLevel_TypeDefinitionIndex 5673

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x3925b20;
		constexpr const static size_t GetWaterLevel = 0x39306a0;
	}

	// obf name: ::%b16a97fd54d7b4c3598216cd73471038c066f841
#define ConVar_Graphics_Static_ClassName "%44a3bc4d62fdc41bf09d0e30ce6d6da2a10df7e0/%b16a97fd54d7b4c3598216cd73471038c066f841"
#define ConVar_Graphics_Static_ClassNameShort "%b16a97fd54d7b4c3598216cd73471038c066f841"
#define ConVar_Graphics_Static_TypeDefinitionIndex 2491

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x270;

		// Functions
		constexpr const static size_t _fov_getter = 0x4452470;
		constexpr const static size_t _fov_setter = 0x444f690;
	}

#define BaseFishingRod_TypeDefinitionIndex 1658

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x260;
		constexpr const static size_t currentBobber = 0x268;
		constexpr const static size_t MaxCastDistance = 0x284;
		constexpr const static size_t BobberPreview = 0x290;
		constexpr const static size_t clientStrainAmountNormalised = 0x2d0;
		constexpr const static size_t strainGainMod = 0x2d8;
		constexpr const static size_t aimAnimationReady = 0x2e8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0xdf6b30;
		constexpr const static size_t EvaluateFishingPosition = 0xe14460;
	}

#define FishingBobber_TypeDefinitionIndex 957

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 3073

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x1db06b0;
	}

	// obf name: ::%d67ea1a2ff6508b623bc6ccedc56fa1702f23eb6
#define GameManager_ClassName "%d67ea1a2ff6508b623bc6ccedc56fa1702f23eb6"
#define GameManager_ClassNameShort "%d67ea1a2ff6508b623bc6ccedc56fa1702f23eb6"
#define GameManager_TypeDefinitionIndex 6783

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x18;

		// Functions
		constexpr const static size_t CreatePrefab = 0x4766b00;
	}

	// obf name: ::%e6785243f8be7d4f5700c9187600b1b16b8128a0
#define GameManager_Static_ClassName "%d67ea1a2ff6508b623bc6ccedc56fa1702f23eb6/%e6785243f8be7d4f5700c9187600b1b16b8128a0"
#define GameManager_Static_ClassNameShort "%e6785243f8be7d4f5700c9187600b1b16b8128a0"
#define GameManager_Static_TypeDefinitionIndex 6782

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x20;
	}

	// obf name: ::%9c8db1612deafe421bc6a228fe42125d4b414d18
#define PrefabPoolCollection_ClassName "%9c8db1612deafe421bc6a228fe42125d4b414d18"
#define PrefabPoolCollection_ClassNameShort "%9c8db1612deafe421bc6a228fe42125d4b414d18"
#define PrefabPoolCollection_TypeDefinitionIndex 741

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%aeb2d8dc61d2f852c8e7f09b3f78801f0f4a9263
#define PrefabPool_ClassName "%aeb2d8dc61d2f852c8e7f09b3f78801f0f4a9263"
#define PrefabPool_ClassNameShort "%aeb2d8dc61d2f852c8e7f09b3f78801f0f4a9263"
#define PrefabPool_TypeDefinitionIndex 912

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x20;
	}

#define ItemModProjectile_TypeDefinitionIndex 2084

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

#define CraftingQueue_TypeDefinitionIndex 6636

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%4f0bb4bdf94adcb12cfc4d303e2d172e0444da43
#define CraftingQueue_Static_ClassName "CraftingQueue/%4f0bb4bdf94adcb12cfc4d303e2d172e0444da43"
#define CraftingQueue_Static_ClassNameShort "%4f0bb4bdf94adcb12cfc4d303e2d172e0444da43"
#define CraftingQueue_Static_TypeDefinitionIndex 6635

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x30;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 672

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%a950aef3dceb782f1b39889949518a9d1a309c5d
#define Planner_Static_ClassName "Planner/%a950aef3dceb782f1b39889949518a9d1a309c5d"
#define Planner_Static_ClassNameShort "%a950aef3dceb782f1b39889949518a9d1a309c5d"
#define Planner_Static_TypeDefinitionIndex 3928

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x140;
	}

	// obf name: ::%eb419074937ce9361a905a86dc9bf27c991cb78e
#define Planner_Guide_ClassName "Planner/%eb419074937ce9361a905a86dc9bf27c991cb78e"
#define Planner_Guide_ClassNameShort "%eb419074937ce9361a905a86dc9bf27c991cb78e"
#define Planner_Guide_TypeDefinitionIndex 3924

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x50;
	}

#define Planner_TypeDefinitionIndex 3929

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x268;
	}

#define Construction_TypeDefinitionIndex 3885

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x178;
	}

#define BuildingBlock_TypeDefinitionIndex 3269

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x308;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 2736

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x190c150;
	}

	// obf name: ::%e3e6626cc16924fba1fa853b1eceeb9f94403f70
#define PunchEntry_ClassName "HeldEntity/%e3e6626cc16924fba1fa853b1eceeb9f94403f70"
#define PunchEntry_ClassNameShort "%e3e6626cc16924fba1fa853b1eceeb9f94403f70"
#define PunchEntry_TypeDefinitionIndex 2734

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x10;
		constexpr const static size_t duration = 0x2c;
		constexpr const static size_t amount = 0x14;
		constexpr const static size_t amountAdded = 0x20;
	}

#define IronSights_TypeDefinitionIndex 904

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 1848

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 5986

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xe8;
		constexpr const static size_t model = 0x80;
		constexpr const static size_t lower = 0xa0;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x3cb2ac0;
	}

#define ViewModel_TypeDefinitionIndex 3635

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x23b6960;
		constexpr const static size_t PlayString = 0x23b9ba0;
	}

#define MedicalTool_TypeDefinitionIndex 3523

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 1085

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x60;
	}

	// obf name: ::%2634340c88b66dbf3ebcb398921c1333f35383f4
#define WaterSystem_Static_ClassName "WaterSystem/%2634340c88b66dbf3ebcb398921c1333f35383f4"
#define WaterSystem_Static_ClassNameShort "%2634340c88b66dbf3ebcb398921c1333f35383f4"
#define WaterSystem_Static_TypeDefinitionIndex 2010

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x40;
	}

#define WaterSystem_TypeDefinitionIndex 2011

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x11fdac0;
	}

#define TerrainMeta_TypeDefinitionIndex 4759

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x540;
		constexpr const static size_t HeightMap = 0x148;
		constexpr const static size_t SplatMap = 0x630;
		constexpr const static size_t TopologyMap = 0x428;
		constexpr const static size_t Texturing = 0x420;
	}

#define TerrainCollision_TypeDefinitionIndex 7101

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x4aa0360;
	}

#define TerrainHeightMap_TypeDefinitionIndex 5661

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 3379

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 6074

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%216c8741e4d2a92c865e4b9f3e84fd471503293f
#define World_Static_ClassName "%f94f8690f41971b1f099d684aed47352de20314b/%216c8741e4d2a92c865e4b9f3e84fd471503293f"
#define World_Static_ClassNameShort "%216c8741e4d2a92c865e4b9f3e84fd471503293f"
#define World_Static_TypeDefinitionIndex 5106

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x2d0;
	}

#define ItemIcon_TypeDefinitionIndex 1748

	namespace ItemIcon {

		// Offsets
		constexpr const static size_t backgroundImage = 0xe8;

		// Functions
		constexpr const static size_t TryToMove = 0xee6af0;
		constexpr const static size_t TryToMove_vtableoff = 0x3a8;
		constexpr const static size_t RunTimedAction = 0xefb840;
	}

	// obf name: ::%b7e81b88b98fb3bb1f1c1e1bf5ce047f1dc8854e
#define ItemIcon_Static_ClassName "ItemIcon/%b7e81b88b98fb3bb1f1c1e1bf5ce047f1dc8854e"
#define ItemIcon_Static_ClassNameShort "%b7e81b88b98fb3bb1f1c1e1bf5ce047f1dc8854e"
#define ItemIcon_Static_TypeDefinitionIndex 1747

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x18;
	}

	// obf name: ::%23c14cef0ffd7e256c0348206d28bab151b7297c
#define EffectData_ClassName "%23c14cef0ffd7e256c0348206d28bab151b7297c"
#define EffectData_ClassNameShort "%23c14cef0ffd7e256c0348206d28bab151b7297c"
#define EffectData_TypeDefinitionIndex 7543

	namespace EffectData {

		// Offsets
		constexpr const static size_t source = 0x28;
	}

	// obf name: ::%94610652915d0e7843f3130f3b2978581a9880e5
#define Effect_ClassName "%94610652915d0e7843f3130f3b2978581a9880e5"
#define Effect_ClassNameShort "%94610652915d0e7843f3130f3b2978581a9880e5"
#define Effect_TypeDefinitionIndex 2750

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x60;
		constexpr const static size_t worldPos = 0xa8;
	}

	// obf name: ::%5ce9fcfdc093233e8b561542ed2e98e5c2c624c4
#define EffectLibrary_ClassName "%5ce9fcfdc093233e8b561542ed2e98e5c2c624c4"
#define EffectLibrary_ClassNameShort "%5ce9fcfdc093233e8b561542ed2e98e5c2c624c4"
#define EffectLibrary_TypeDefinitionIndex 2640

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x1842f60;
	}

	// obf name: ::%016ae150da6528f8493208cff3bbfe5a57e06216
#define EffectNetwork_ClassName "%016ae150da6528f8493208cff3bbfe5a57e06216"
#define EffectNetwork_ClassNameShort "%016ae150da6528f8493208cff3bbfe5a57e06216"
#define EffectNetwork_TypeDefinitionIndex 3961

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%5488e71757fdce3c6af17bd7be9fdc05c1ee6892
#define EffectNetwork_Static_ClassName "%016ae150da6528f8493208cff3bbfe5a57e06216/%5488e71757fdce3c6af17bd7be9fdc05c1ee6892"
#define EffectNetwork_Static_ClassNameShort "%5488e71757fdce3c6af17bd7be9fdc05c1ee6892"
#define EffectNetwork_Static_TypeDefinitionIndex 3960

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x18;

		// Functions
		constexpr const static size_t cctor = 0x2787fe0;
	}

#define BuildingBlock_TypeDefinitionIndex 3269

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x2013c60;
		constexpr const static size_t HasUpgradePrivilege = 0x1ffd7b0;
		constexpr const static size_t CanAffordUpgrade = 0x2004de0;
	}

	// obf name: ::%aea70d960a779878a6e850c3cb898437ed357501
#define GameObjectEx_ClassName "%aea70d960a779878a6e850c3cb898437ed357501"
#define GameObjectEx_ClassNameShort "%aea70d960a779878a6e850c3cb898437ed357501"
#define GameObjectEx_TypeDefinitionIndex 25

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0xb51bb0;
	}

#define UIDeathScreen_TypeDefinitionIndex 6176

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x3eb0620;
	}

	// obf name: ::%0cf6a2e1ae3a91be35a09403dac1b54a1c58de15
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%0cf6a2e1ae3a91be35a09403dac1b54a1c58de15"
#define BaseScreenShake_Static_ClassNameShort "%0cf6a2e1ae3a91be35a09403dac1b54a1c58de15"
#define BaseScreenShake_Static_TypeDefinitionIndex 3542

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x60;
	}

#define FlashbangOverlay_TypeDefinitionIndex 3557

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x10;
		constexpr const static size_t flashLength = 0x40;
	}

	// obf name: ::%9fc1e618d71f3d53afb63624110246f117446d40
#define StringPool_ClassName "%9fc1e618d71f3d53afb63624110246f117446d40"
#define StringPool_ClassNameShort "%9fc1e618d71f3d53afb63624110246f117446d40"
#define StringPool_TypeDefinitionIndex 6244

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x0;

		// Functions
		constexpr const static size_t Get = 0x40ae7f0;
	}

	// obf name: ::%51b8917f5c5f49b45f4246e19d81987800bcaafd
#define Network_Networkable_ClassName "%51b8917f5c5f49b45f4246e19d81987800bcaafd"
#define Network_Networkable_ClassNameShort "%51b8917f5c5f49b45f4246e19d81987800bcaafd"
#define Network_Networkable_TypeDefinitionIndex 18423

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x30;
	}

	// obf name: ::%ba146df80124ea910527d3be1f0a6ae611e61ccf
#define Network_Net_ClassName "%ba146df80124ea910527d3be1f0a6ae611e61ccf"
#define Network_Net_ClassNameShort "%ba146df80124ea910527d3be1f0a6ae611e61ccf"
#define Network_Net_TypeDefinitionIndex 7826

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x40;
	}

	// obf name: ::%a6bad2278ee5c789f8a38ad50108da888b68748c
#define Network_Client_ClassName "%a6bad2278ee5c789f8a38ad50108da888b68748c"
#define Network_Client_ClassNameShort "%a6bad2278ee5c789f8a38ad50108da888b68748c"
#define Network_Client_TypeDefinitionIndex 18482

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0x100;
		constexpr const static size_t ConnectedPort = 0xd4;
		constexpr const static size_t ServerName = 0xd8;
		constexpr const static size_t ConnectedAddress = 0xf8;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x6471ae0;
		constexpr const static size_t DestroyNetworkable = 0x6471570;
	}

	// obf name: ::%04121e0e0818055d8871bd6bd418cea9a0ced388
#define Network_BaseNetwork_ClassName "%04121e0e0818055d8871bd6bd418cea9a0ced388"
#define Network_BaseNetwork_ClassNameShort "%04121e0e0818055d8871bd6bd418cea9a0ced388"
#define Network_BaseNetwork_TypeDefinitionIndex 18456

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x642f1b0;
	}

	// obf name: ::%ac91827f5991d96be15455269f3e4eb58f41c47b
#define Network_SendInfo_ClassName "%ac91827f5991d96be15455269f3e4eb58f41c47b"
#define Network_SendInfo_ClassNameShort "%ac91827f5991d96be15455269f3e4eb58f41c47b"
#define Network_SendInfo_TypeDefinitionIndex 18468

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%849b275fad2844ea729c57cb84eb0d5ed5748d6a
#define Network_Message_ClassName "%849b275fad2844ea729c57cb84eb0d5ed5748d6a"
#define Network_Message_ClassNameShort "%849b275fad2844ea729c57cb84eb0d5ed5748d6a"
#define Network_Message_TypeDefinitionIndex 18453

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%79c7a11983530b2693c506eba2ee64d34848475c
#define Network_NetRead_ClassName "%79c7a11983530b2693c506eba2ee64d34848475c"
#define Network_NetRead_ClassNameShort "%79c7a11983530b2693c506eba2ee64d34848475c"
#define Network_NetRead_TypeDefinitionIndex 18444

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x30;
	}

	// obf name: ::%bcc73477fe5ee5442c4774bd11e2652608fcf080
#define Network_NetWrite_ClassName "%bcc73477fe5ee5442c4774bd11e2652608fcf080"
#define Network_NetWrite_ClassNameShort "%bcc73477fe5ee5442c4774bd11e2652608fcf080"
#define Network_NetWrite_TypeDefinitionIndex 18480

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x38;

		// Functions
		constexpr const static size_t WriteByte = 0x646be20;
		constexpr const static size_t String = 0x646fc60;
		constexpr const static size_t Send = 0x64690e0;
	}

#define LootPanel_TypeDefinitionIndex 7180

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x4bd0410;
	}

#define UIInventory_TypeDefinitionIndex 2999

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x1cd8dc0;
	}

#define GrowableEntity_TypeDefinitionIndex 4932

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 4630

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 4629

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 21302

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 8943

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
		constexpr const static size_t get_Instance = 0x8856d0;
	}

	// obf name: ::%1950ba55a6493b3267a327011f991f41463b2ba8
#define TOD_Sky_Static_ClassName "TOD_Sky/%1950ba55a6493b3267a327011f991f41463b2ba8"
#define TOD_Sky_Static_ClassNameShort "%1950ba55a6493b3267a327011f991f41463b2ba8"
#define TOD_Sky_Static_TypeDefinitionIndex 8942

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0xc8;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 9821

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xa488d0;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9616

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9027

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 7809

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 7976

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 7844

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 9023

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 5306

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 289

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 4731

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 4680

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

#define EnvironmentManager_TypeDefinitionIndex 1485

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0xc6ea00;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%90cab61e283c4aa1a238cee513f386fbfaac0ed0/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24410

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 6505

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 6506

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 6848

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
		constexpr const static size_t InstanceList = 0x18;
	}

	// obf name: ::%f14a4aa3f25cf47b7a6d23908365b3b06af2b032
#define ListHashSet_ClassName "%f14a4aa3f25cf47b7a6d23908365b3b06af2b032<UIChat>"
#define ListHashSet_ClassNameShort "%f14a4aa3f25cf47b7a6d23908365b3b06af2b032"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 3839

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3e8;
	}

#define Chainsaw_TypeDefinitionIndex 1738

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x38c;
	}

	// obf name: ::%e86757185c3602f90d3ca242d190a98555130db1
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%e86757185c3602f90d3ca242d190a98555130db1"
#define CameraUpdateHook_Static_ClassNameShort "%e86757185c3602f90d3ca242d190a98555130db1"
#define CameraUpdateHook_Static_TypeDefinitionIndex 1527

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x100;
	}

#define SteamClientWrapper_TypeDefinitionIndex 4664

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x2dda640;
	}

	// obf name: ::%6ff64142c432a57b536e2d81883a156160c2a253
#define AimConeUtil_ClassName "%6ff64142c432a57b536e2d81883a156160c2a253"
#define AimConeUtil_ClassNameShort "%6ff64142c432a57b536e2d81883a156160c2a253"
#define AimConeUtil_TypeDefinitionIndex 1714

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0xeba700;
	}

	// obf name: ::%b7c9bbf24f77a08639f2e8c384c19d763935e2ff
#define Buttons_ConButton_ClassName "%46d543a5ffea0258dd9e68c01fd1167aa518f930/%b7c9bbf24f77a08639f2e8c384c19d763935e2ff"
#define Buttons_ConButton_ClassNameShort "%b7c9bbf24f77a08639f2e8c384c19d763935e2ff"
#define Buttons_ConButton_TypeDefinitionIndex 1904

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%ee852aef4ce642a283042e21cd7292658014494b
#define Buttons_Static_ClassName "%46d543a5ffea0258dd9e68c01fd1167aa518f930/%ee852aef4ce642a283042e21cd7292658014494b"
#define Buttons_Static_ClassNameShort "%ee852aef4ce642a283042e21cd7292658014494b"
#define Buttons_Static_TypeDefinitionIndex 1905

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x5c8;
		constexpr const static size_t Attack = 0x3e0;
		constexpr const static size_t Attack2 = 0x6f8;
		constexpr const static size_t Forward = 0x2e0;
		constexpr const static size_t Backward = 0x2b8;
		constexpr const static size_t Right = 0x238;
		constexpr const static size_t Left = 0x30;
		constexpr const static size_t Sprint = 0x330;
		constexpr const static size_t Use = 0xc68;

		// Functions
		constexpr const static size_t Pets_setter = 0x4449590;
	}

#define PlayerModel_TypeDefinitionIndex 1402

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x2b8;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 866

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x40;
	}

#define BaseMountable_TypeDefinitionIndex 4041

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 1313

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x10;
		constexpr const static size_t timeCounter = 0x2c;
	}

#define BowWeapon_TypeDefinitionIndex 6734

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x410;
		constexpr const static size_t wasAiming = 0x420;
	}

#define CrossbowWeapon_TypeDefinitionIndex 2711

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 5766

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%625823cc072e8419acc8a03585f7f8f7435a2a66
#define ConVar_Admin_Static_ClassName "%a337290e60635e9345591fb3e5b5ae82b3f894ba/%625823cc072e8419acc8a03585f7f8f7435a2a66"
#define ConVar_Admin_Static_ClassNameShort "%625823cc072e8419acc8a03585f7f8f7435a2a66"
#define ConVar_Admin_Static_TypeDefinitionIndex 3387

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x130;

		// Functions
		constexpr const static size_t admintime_getter = 0x44518b0;
		constexpr const static size_t admintime_setter = 0x4485940;
	}

	// obf name: ::%c2ae7c5cbc925380cdee7c77e493a39c03a37b2b
#define ConVar_Player_Static_ClassName "%ace601a73fc99fe7989c08f1581b5d8e842f8e8f/%c2ae7c5cbc925380cdee7c77e493a39c03a37b2b"
#define ConVar_Player_Static_ClassNameShort "%c2ae7c5cbc925380cdee7c77e493a39c03a37b2b"
#define ConVar_Player_Static_TypeDefinitionIndex 5519

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0xe0;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x4469fd0;
		constexpr const static size_t clientTickRate_setter = 0x446f1c0;
	}

#define ColliderInfo_TypeDefinitionIndex 3030

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 134

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 3887

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x0;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x0;
	}

#define Client_TypeDefinitionIndex 3810

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x25843b0;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%d9fb19535c70c85ed2489517ef2efeba67dfa589
#define ItemManager_Static_ClassName "%687148435474bbc5ee7ed6c44b4ff2a3a33b39fc/%d9fb19535c70c85ed2489517ef2efeba67dfa589"
#define ItemManager_Static_ClassNameShort "%d9fb19535c70c85ed2489517ef2efeba67dfa589"
#define ItemManager_Static_TypeDefinitionIndex 5906

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0xa8;
		constexpr const static size_t itemDictionary = 0x170;
		constexpr const static size_t itemDictionaryByName = 0x88;
	}

	// obf name: ::%61e14019cc535adc295a5d4fa6e17c1e311e24d9
#define ConVar_Server_Static_ClassName "%8ff4e6dc10172b4c6b23c89705bc82d87b88e9cd/%61e14019cc535adc295a5d4fa6e17c1e311e24d9"
#define ConVar_Server_Static_ClassNameShort "%61e14019cc535adc295a5d4fa6e17c1e311e24d9"
#define ConVar_Server_Static_TypeDefinitionIndex 1523

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 6621

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x45e9d70;
	}

#define LoadingScreen_TypeDefinitionIndex 417

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x30;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 4190

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%941e3c074f1a8d4b888f9c245ba4d1c2f0c41d7d"
#define MapView_Static_ClassNameShort "%941e3c074f1a8d4b888f9c245ba4d1c2f0c41d7d"
#define MapView_TypeDefinitionIndex 1077

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x5030560;
	}

	// obf name: ::%9a2d82794f4aee71ea521e8d132032ca5b4ffdea
#define GamePhysics_Static_ClassName "%be6984e6016f9b5058b65b9a3523537fc67cb630/%9a2d82794f4aee71ea521e8d132032ca5b4ffdea"
#define GamePhysics_Static_ClassNameShort "%9a2d82794f4aee71ea521e8d132032ca5b4ffdea"
#define GamePhysics_Static_TypeDefinitionIndex 7064

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x50;
	}

	// obf name: ::%be6984e6016f9b5058b65b9a3523537fc67cb630
#define GamePhysics_ClassName "%be6984e6016f9b5058b65b9a3523537fc67cb630"
#define GamePhysics_ClassNameShort "%be6984e6016f9b5058b65b9a3523537fc67cb630"
#define GamePhysics_TypeDefinitionIndex 7065

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x4a2c2b0;
		constexpr const static size_t LineOfSightInternal = 0x4a21030;
		constexpr const static size_t Verify = 0x4a39440;
	}

#define InstancedDebugDraw_TypeDefinitionIndex 153

	namespace InstancedDebugDraw {

		// Functions
		constexpr const static size_t AddInstance = 0xb71950;
	}

	// obf name: ::%6ca47319e53e516f981c04c71f616633d785c6ab
#define RaycastHitEx_ClassName "%6ca47319e53e516f981c04c71f616633d785c6ab"
#define RaycastHitEx_ClassNameShort "%6ca47319e53e516f981c04c71f616633d785c6ab"
#define RaycastHitEx_TypeDefinitionIndex 3980

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x27a6c40;
	}

	// obf name: ::%4141dcf862af6c15f4251261efd7fe794514e398
#define OnParentDestroyingEx_ClassName "%4141dcf862af6c15f4251261efd7fe794514e398"
#define OnParentDestroyingEx_ClassNameShort "%4141dcf862af6c15f4251261efd7fe794514e398"
#define OnParentDestroyingEx_TypeDefinitionIndex 2864

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x1a8ffc0;
	}

	// obf name: ::%0d3315e09b65c551bbc821012409ef8470ccd94b
#define ConsoleNetwork_ClassName "%0d3315e09b65c551bbc821012409ef8470ccd94b"
#define ConsoleNetwork_ClassNameShort "%0d3315e09b65c551bbc821012409ef8470ccd94b"
#define ConsoleNetwork_TypeDefinitionIndex 1671

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0xe3c040;
	}

#define ThrownWeapon_TypeDefinitionIndex 3075

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 5868

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 6243

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 1077

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 1071

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 1036

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 6701

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 4772

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 5918

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 2141

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%f4b7213a3f2f51c909ff4af343cd3a5445316a06
#define ConVar_Client_Static_ClassName "%ae5841ed633cf16d3c70ca00c4459e9e409c0381/%f4b7213a3f2f51c909ff4af343cd3a5445316a06"
#define ConVar_Client_Static_ClassNameShort "%f4b7213a3f2f51c909ff4af343cd3a5445316a06"
#define ConVar_Client_Static_TypeDefinitionIndex 6367

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x1ec;
		constexpr const static size_t camspeed = 0x850;
	}

#define SamSite_TypeDefinitionIndex 473

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 2339

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 6807

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 6422

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 3501

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 6926

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 2156

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 806

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%7159d8eaef008e975202970d3448a73257a4e2d4
#define Facepunch_Network_Raknet_Client_ClassName "%7159d8eaef008e975202970d3448a73257a4e2d4"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%7159d8eaef008e975202970d3448a73257a4e2d4"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 23118

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x64bfc10;
		constexpr const static size_t IsConnected_vtableoff = 0x428;
	}

	// obf name: ::%a16eaa49b590c98740b96aae2126765dffecf7fa
#define EncryptedValue_ClassName "%a16eaa49b590c98740b96aae2126765dffecf7fa<System/Int32>"
#define EncryptedValue_ClassNameShort "%a16eaa49b590c98740b96aae2126765dffecf7fa"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%3519e712b597cdb888edf00e735e8029b87262e9
#define HiddenValue_ClassName "%3519e712b597cdb888edf00e735e8029b87262e9<BaseNetworkable/%1f51a2517ef3ffd3b51ac024cf55fdbac84e5bb7>"
#define HiddenValue_ClassNameShort "%3519e712b597cdb888edf00e735e8029b87262e9"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex -1

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x0;
	}

#define ItemModRFListener_TypeDefinitionIndex 1700

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0xe58130;
	}

#define UIFogOverlay_TypeDefinitionIndex 6807

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x10;
	}

	// obf name: ::%3ee051ec1755c04d5da5c37b77b785dbc2ed784a
#define BufferStream_ClassName "%3ee051ec1755c04d5da5c37b77b785dbc2ed784a"
#define BufferStream_ClassNameShort "%3ee051ec1755c04d5da5c37b77b785dbc2ed784a"
#define BufferStream_TypeDefinitionIndex 7571

	namespace BufferStream {

		// Offsets
		constexpr const static size_t _buffer = 0x20;

		// Functions
		constexpr const static size_t EnsureCapacity = 0x8cbd2c0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 4255

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 4525

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 6554

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x43d3c10;
	}

#define OutlineManager_TypeDefinitionIndex 1378

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%16273f633cc9f3d8c1547e331e6e4bebcd97b288
#define ConsoleSystem_Command_ClassName "%f0267d300992b3de7f9b5fa8b1bfede2185e7c6a/%16273f633cc9f3d8c1547e331e6e4bebcd97b288"
#define ConsoleSystem_Command_ClassNameShort "%16273f633cc9f3d8c1547e331e6e4bebcd97b288"
#define ConsoleSystem_Command_TypeDefinitionIndex 23604

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x18;
		constexpr const static size_t SetOveride = 0x80;
		constexpr const static size_t Call = 0x90;
	}

	// obf name: ::%b41c268f942f3ee9b2578977d5f2b664b42f15be
#define ConsoleSystem_Option_ClassName "%f0267d300992b3de7f9b5fa8b1bfede2185e7c6a/%b41c268f942f3ee9b2578977d5f2b664b42f15be"
#define ConsoleSystem_Option_ClassNameShort "%b41c268f942f3ee9b2578977d5f2b664b42f15be"
#define ConsoleSystem_Option_TypeDefinitionIndex 23614

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%664de498b7a51a76899cbf46b9f0c97dceca87f0
#define ConsoleSystem_Arg_ClassName "%f0267d300992b3de7f9b5fa8b1bfede2185e7c6a/%664de498b7a51a76899cbf46b9f0c97dceca87f0"
#define ConsoleSystem_Arg_ClassNameShort "%664de498b7a51a76899cbf46b9f0c97dceca87f0"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23602

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x48;
	}

	// obf name: ::%1901ba97d3f84a5cb02f7ec9c2066fcd6a4b4c25
#define ConsoleSystem_Index_Client_ClassName "%f0267d300992b3de7f9b5fa8b1bfede2185e7c6a/%b1e414bf7de63ce834c52a9616965a45d5722de0.%1901ba97d3f84a5cb02f7ec9c2066fcd6a4b4c25"
#define ConsoleSystem_Index_Client_ClassNameShort "%1901ba97d3f84a5cb02f7ec9c2066fcd6a4b4c25"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23610

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x639cd50;
	}

#define String_TypeDefinitionIndex 10495

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x853f3f0;
	}

	// obf name: ::%86f7b6ccdcc7e9e4b6151118c8e43a691ff1e1d3
#define EntityRef_ClassName "%86f7b6ccdcc7e9e4b6151118c8e43a691ff1e1d3"
#define EntityRef_ClassNameShort "%86f7b6ccdcc7e9e4b6151118c8e43a691ff1e1d3"
#define EntityRef_TypeDefinitionIndex 4257

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x2a89890;
	}

#define ConVar_Debugging_TypeDefinitionIndex -1

	namespace ConVar_Debugging {

		// Functions
		constexpr const static size_t debugcamera = 0x4476630;
		constexpr const static size_t noclip = 0x1cf8c60;
	}

#define CursorManager_TypeDefinitionIndex 1189

	namespace CursorManager {

		// Offsets
	}

	// obf name: ::%3bc3e0d62a3cc239476464b83f4284d7893b029b
#define ProtoBuf_ProjectileShoot_ClassName "%3bc3e0d62a3cc239476464b83f4284d7893b029b"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%3bc3e0d62a3cc239476464b83f4284d7893b029b"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7301

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9293c70;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9292020;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%32b709af1617d4d9f277ffd2f63058040167bd9e
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%3bc3e0d62a3cc239476464b83f4284d7893b029b/%32b709af1617d4d9f277ffd2f63058040167bd9e"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%32b709af1617d4d9f277ffd2f63058040167bd9e"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7300

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t startPos = 0x20;
		constexpr const static size_t startVel = 0x2c;
		constexpr const static size_t seed = 0x18;
	}

	// obf name: ::%f57ef9557d7a2817d10a118dac329006f198fd4c
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%f57ef9557d7a2817d10a118dac329006f198fd4c"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%f57ef9557d7a2817d10a118dac329006f198fd4c"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7692

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t curPosition = 0x10;
		constexpr const static size_t curVelocity = 0x28;
		constexpr const static size_t travelTime = 0x24;
		constexpr const static size_t ShouldPool = 0x1d;

		// Functions
		constexpr const static size_t Dispose = 0x91561b0;
		constexpr const static size_t WriteToStreamDelta = 0x915ba80;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x915c510;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%d04a17ce96f09b46d97e6e89af5381582e222061
#define ProtoBuf_PlayerProjectileAttack_ClassName "%d04a17ce96f09b46d97e6e89af5381582e222061"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%d04a17ce96f09b46d97e6e89af5381582e222061"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7588

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x24;
		constexpr const static size_t hitDistance = 0x14;
		constexpr const static size_t travelTime = 0x10;
		constexpr const static size_t playerAttack = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8d4ac60;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8d45c00;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%829e4e46f9c965dd39b758b25e5ac252976ba57c
#define ProtoBuf_PlayerAttack_ClassName "%829e4e46f9c965dd39b758b25e5ac252976ba57c"
#define ProtoBuf_PlayerAttack_ClassNameShort "%829e4e46f9c965dd39b758b25e5ac252976ba57c"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7367

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%be9cb2f1b3a2fbdebaf61339e611602b99fc9d60
#define ProtoBuf_Attack_ClassName "%be9cb2f1b3a2fbdebaf61339e611602b99fc9d60"
#define ProtoBuf_Attack_ClassNameShort "%be9cb2f1b3a2fbdebaf61339e611602b99fc9d60"
#define ProtoBuf_Attack_TypeDefinitionIndex 7697

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x18;
		constexpr const static size_t pointEnd = 0x70;
		constexpr const static size_t hitID = 0x10;
		constexpr const static size_t hitBone = 0x44;
		constexpr const static size_t hitNormalLocal = 0x48;
		constexpr const static size_t hitPositionLocal = 0x7c;
		constexpr const static size_t hitNormalWorld = 0x34;
		constexpr const static size_t hitPositionWorld = 0x60;
		constexpr const static size_t hitPartID = 0x40;
		constexpr const static size_t hitMaterialID = 0x88;
		constexpr const static size_t srcParentID = 0x28;
		constexpr const static size_t dstParentID = 0x58;
	}
}