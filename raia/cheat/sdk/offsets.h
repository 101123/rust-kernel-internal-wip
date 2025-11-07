#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x690ddc77;
		constexpr const static size_t gc_handles = 0xd3e5190;
		constexpr const static size_t il2cpp_resolve_icall = 0x5c3c20;
		constexpr const static size_t il2cpp_array_new = 0x5c3c40;
		constexpr const static size_t il2cpp_assembly_get_image = 0x398e0;
		constexpr const static size_t il2cpp_class_from_name = 0x5c3db0;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x5c40c0;
		constexpr const static size_t il2cpp_class_get_type = 0x5c4160;
		constexpr const static size_t il2cpp_domain_get = 0x5c46c0;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x5c46e0;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x5c4fa0;
		constexpr const static size_t il2cpp_gchandle_new = 0x5c4f50;
		constexpr const static size_t il2cpp_gchandle_free = 0x5c5040;
		constexpr const static size_t il2cpp_method_get_name = 0x3100;
		constexpr const static size_t il2cpp_object_new = 0x5c56f0;
		constexpr const static size_t il2cpp_type_get_object = 0x5c5ee0;
	}

#define Object_TypeDefinitionIndex 17065

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xae44610;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 17036

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

#define Component_TypeDefinitionIndex 17023

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 17017

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 17100

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xae50230;
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

#define Camera_TypeDefinitionIndex 16815

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

#define Time_TypeDefinitionIndex 17087

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

#define Material_TypeDefinitionIndex 16878

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16874

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xae042f0;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16877

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xae07e60;
		constexpr const static size_t PropertyToID = 0xaa6a0;
		constexpr const static size_t GetPropertyCount = 0xaea30;
		constexpr const static size_t GetPropertyName = 0xad8f0;
		constexpr const static size_t GetPropertyType = 0xadb90;
	}

#define Mesh_TypeDefinitionIndex 16933

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

#define Renderer_TypeDefinitionIndex 16875

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterial = 0x9ffe0;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16936

	namespace Texture {

		// Functions
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16938

	namespace Texture2D {

		// Functions
		constexpr const static size_t ctor = 0xae1dca0;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define Sprite_TypeDefinitionIndex 17106

	namespace Sprite {

		// Functions
		constexpr const static size_t get_texture = 0x119300;
	}

#define RenderTexture_TypeDefinitionIndex 16943

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xae26950;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17413

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae6a6e0;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17389

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xae645d0;
	}

#define ComputeBuffer_TypeDefinitionIndex 17078

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae481b0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xae48400;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16882

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae0ee90;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xae0ebc0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 22300

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xae8cf70;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16855

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16966

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24805

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16852

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24683

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

#define Application_TypeDefinitionIndex 16798

	namespace Application {

		// Functions
		constexpr const static size_t get_version = 0x5f350;
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16964

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23656

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xaed28e0;
		constexpr const static size_t RaycastNonAlloc = 0xaed4fb0;
		constexpr const static size_t CheckCapsule = 0xaed6780;
	}

#define Image_TypeDefinitionIndex 21235

	namespace Image {

		// Offsets
		constexpr const static size_t m_Sprite = 0xd0;
	}

#define GraphicsSettings_TypeDefinitionIndex 17411

	namespace GraphicsSettings {

		// Functions
		constexpr const static size_t get_INTERNAL_defaultRenderPipeline = 0x127f00;
	}

#define BaseNetworkable_TypeDefinitionIndex 2112

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x28;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x40;
	}

	// obf name: ::%118f6d422743ceba612e89543e1e41f27208cdbe
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%118f6d422743ceba612e89543e1e41f27208cdbe"
#define BaseNetworkable_Static_ClassNameShort "%118f6d422743ceba612e89543e1e41f27208cdbe"
#define BaseNetworkable_Static_TypeDefinitionIndex 2111

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x28;
	}

	// obf name: ::%171ac9b646b488e2a8769d91e0fc7765de5a3b84
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%171ac9b646b488e2a8769d91e0fc7765de5a3b84"
#define BaseNetworkable_EntityRealm_ClassNameShort "%171ac9b646b488e2a8769d91e0fc7765de5a3b84"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 2109

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x14678d0;
	}

	// obf name: ::%69a553efb0e4b8ecf49bbdcae6557759ce8e8388
#define System_ListDictionary_ClassName "%69a553efb0e4b8ecf49bbdcae6557759ce8e8388<%d9e059f608e4db9887a77eae17d686cc0b6985a0,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%69a553efb0e4b8ecf49bbdcae6557759ce8e8388"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x20;

		// Functions
		constexpr const static size_t TryGetValue = 0x6ca5a40;
		constexpr const static size_t TryGetValue_methodinfo = 0xd0d6288;
	}

	// obf name: ::%c8a8cccbdabe4e818e29f1473cdd0c5642f5a458
#define System_BufferList_ClassName "%c8a8cccbdabe4e818e29f1473cdd0c5642f5a458<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%c8a8cccbdabe4e818e29f1473cdd0c5642f5a458"
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
		constexpr const static size_t Instance = 0x10;
	}

#define Model_TypeDefinitionIndex 6654

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t eyeBone = 0x38;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 1004

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0x160;
		constexpr const static size_t positionLerp = 0x88;

		// Functions
		constexpr const static size_t ServerRPC = 0x50a90e0;
		constexpr const static size_t FindBone = 0x5074400;
		constexpr const static size_t GetWorldVelocity = 0x5089970;
		constexpr const static size_t GetParentVelocity = 0x50ab7b0;
	}

	// obf name: ::%68c0b44ad84c37e3c0b199f8f606c0b0819935b4
#define PositionLerp_ClassName "%68c0b44ad84c37e3c0b199f8f606c0b0819935b4"
#define PositionLerp_ClassNameShort "%68c0b44ad84c37e3c0b199f8f606c0b0819935b4"
#define PositionLerp_TypeDefinitionIndex 199

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x40;
	}

	// obf name: ::%2f26a2b10d447ff7d0c3fad200e5d9b7167c8abb
#define Interpolator_ClassName "%2f26a2b10d447ff7d0c3fad200e5d9b7167c8abb<%b80a12436bc36b1b1d2efecd8af14d921473c568>"
#define Interpolator_ClassNameShort "%2f26a2b10d447ff7d0c3fad200e5d9b7167c8abb"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 1903

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

#define SkeletonProperties_TypeDefinitionIndex 1460

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 1458

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 1603

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 1602

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%7face6f1dbdd1bdd98cf56b07593111ab0261a67
#define DamageTypeList_ClassName "%7face6f1dbdd1bdd98cf56b07593111ab0261a67"
#define DamageTypeList_ClassNameShort "%7face6f1dbdd1bdd98cf56b07593111ab0261a67"
#define DamageTypeList_TypeDefinitionIndex 2178

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 5299

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 5160

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

#define RecoilProperties_TypeDefinitionIndex 5758

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

#define BaseProjectile_Magazine_Definition_TypeDefinitionIndex 1924

	namespace BaseProjectile_Magazine_Definition {

		// Offsets
		constexpr const static size_t builtInSize = 0x0;
	}

#define BaseProjectile_Magazine_TypeDefinitionIndex 1925

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t definition = 0x10;
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 557

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x45e47d0;
		constexpr const static size_t StartAttackCooldown = 0x45e7050;
	}

#define BaseProjectile_TypeDefinitionIndex 1930

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
		constexpr const static size_t LaunchProjectile = 0x12ba820;
		constexpr const static size_t LaunchProjectileClientSide = 0x12d4d20;
		constexpr const static size_t ScaleRepeatDelay = 0x12d4310;
		constexpr const static size_t GetAimCone = 0x12dc780;
		constexpr const static size_t GetAimCone_vtableoff = 0x4128;
		constexpr const static size_t UpdateAmmoDisplay = 0x12c1e70;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3d38;
	}

#define BaseLauncher_TypeDefinitionIndex 1077

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 3004

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%bcf55a68f5dad796c0e0a236b90e1e65cee275bf
#define HitTest_ClassName "%bcf55a68f5dad796c0e0a236b90e1e65cee275bf"
#define HitTest_ClassNameShort "%bcf55a68f5dad796c0e0a236b90e1e65cee275bf"
#define HitTest_TypeDefinitionIndex 397

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x84;
		constexpr const static size_t AttackRay = 0x38;
		constexpr const static size_t RayHit = 0xa4;
		constexpr const static size_t damageProperties = 0x58;
		constexpr const static size_t gameObject = 0x30;
		constexpr const static size_t collider = 0x68;
		constexpr const static size_t ignoredTypes = 0x18;
		constexpr const static size_t HitTransform = 0x70;
		constexpr const static size_t HitPart = 0xd0;
		constexpr const static size_t HitMaterial = 0x98;
		constexpr const static size_t DidHit = 0x60;
		constexpr const static size_t MaxDistance = 0x10;
		constexpr const static size_t HitPoint = 0x20;
		constexpr const static size_t HitNormal = 0x78;
		constexpr const static size_t ignoreEntity = 0x50;
		constexpr const static size_t HitEntity = 0x88;
	}

#define Projectile_TypeDefinitionIndex 424

	namespace Projectile {

		// Offsets
		constexpr const static size_t initialVelocity = 0x28;
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t thickness = 0x3c;
		constexpr const static size_t initialDistance = 0x44;
		constexpr const static size_t swimScale = 0xf0;
		constexpr const static size_t swimSpeed = 0xfc;
		constexpr const static size_t owner = 0x118;
		constexpr const static size_t sourceProjectilePrefab = 0x1e0;
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
		constexpr const static size_t CalculateEffectScale = 0x3398f50;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x1d8;
		constexpr const static size_t SetEffectScale = 0x33ddcb0;
		constexpr const static size_t UpdateVelocity = 0x33d3840;
		constexpr const static size_t Retire = 0x3397de0;
		constexpr const static size_t DoHit = 0x33bfab0;
	}

	// obf name: ::%4484b370b7348fd11db310a369cd4744a62aa188
#define HitInfo_ClassName "%4484b370b7348fd11db310a369cd4744a62aa188"
#define HitInfo_ClassNameShort "%4484b370b7348fd11db310a369cd4744a62aa188"
#define HitInfo_TypeDefinitionIndex 3376

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x30;
		constexpr const static size_t damageTypes = 0x58;

		// Functions
		constexpr const static size_t get_boneArea = 0x21f46f0;
	}

	// obf name: ::%783023505235b6c600de80e0057243df9e456e68
#define GameTrace_ClassName "%783023505235b6c600de80e0057243df9e456e68"
#define GameTrace_ClassNameShort "%783023505235b6c600de80e0057243df9e456e68"
#define GameTrace_TypeDefinitionIndex 5973

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x3d95b70;
	}

#define BaseMelee_TypeDefinitionIndex 383

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x2e3e740;
		constexpr const static size_t DoThrow = 0x2e47050;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 3740

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x410;
		constexpr const static size_t strikeRecoil = 0x418;
		constexpr const static size_t _didSparkThisFrame = 0x420;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 4479

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x428;
		constexpr const static size_t stringBonusVelocity = 0x434;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x2fd16a0;
	}

	// obf name: ::%7b7959420c9bc26e8aed0ab9e84da980976b25d1
#define ItemContainer_ClassName "%7b7959420c9bc26e8aed0ab9e84da980976b25d1"
#define ItemContainer_ClassNameShort "%7b7959420c9bc26e8aed0ab9e84da980976b25d1"
#define ItemContainer_TypeDefinitionIndex 6717

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x18;
		constexpr const static size_t itemList = 0x58;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x4562ce0;
	}

#define PlayerLoot_TypeDefinitionIndex 526

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 4245

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x28;
		constexpr const static size_t containerMain = 0x38;
		constexpr const static size_t containerWear = 0x60;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x2d566d0;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 1236

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x53606f0;
		constexpr const static size_t get_rotation = 0x5385b90;
		constexpr const static size_t set_rotation = 0x5366c80;
		constexpr const static size_t HeadForward = 0x53890a0;
	}

	// obf name: ::%90e907216c557c6bb10b788e33ed3f8dd6ade00e
#define PlayerEyes_Static_ClassName "PlayerEyes/%90e907216c557c6bb10b788e33ed3f8dd6ade00e"
#define PlayerEyes_Static_ClassNameShort "%90e907216c557c6bb10b788e33ed3f8dd6ade00e"
#define PlayerEyes_Static_TypeDefinitionIndex 1235

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x148;
	}

	// obf name: ::%84cf600b0986125ec1bd22bb876e9d15a6e61788
#define PlayerBelt_ClassName "%84cf600b0986125ec1bd22bb876e9d15a6e61788"
#define PlayerBelt_ClassNameShort "%84cf600b0986125ec1bd22bb876e9d15a6e61788"
#define PlayerBelt_TypeDefinitionIndex 2653

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x1add280;
		constexpr const static size_t GetActiveItem = 0x1acf360;
	}

	// obf name: ::%fcaa62b74a864dbf2fb51d531a7422247d3ed197
#define LocalPlayer_ClassName "%fcaa62b74a864dbf2fb51d531a7422247d3ed197"
#define LocalPlayer_ClassNameShort "%fcaa62b74a864dbf2fb51d531a7422247d3ed197"
#define LocalPlayer_TypeDefinitionIndex 6983

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x4872150;
		constexpr const static size_t MoveItem = 0x486ecd0;
		constexpr const static size_t get_Entity = 0x485ca30;
	}

	// obf name: ::%98e842b46bba36f933fe04405975a53694af22eb
#define LocalPlayer_Static_ClassName "%fcaa62b74a864dbf2fb51d531a7422247d3ed197/%98e842b46bba36f933fe04405975a53694af22eb"
#define LocalPlayer_Static_ClassNameShort "%98e842b46bba36f933fe04405975a53694af22eb"
#define LocalPlayer_Static_TypeDefinitionIndex 6982

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x10;
	}

	// obf name: ::%9ddd0c004ec78c6d6574cf4f52792be9fd728d10
#define BasePlayer_Static_ClassName "BasePlayer/%9ddd0c004ec78c6d6574cf4f52792be9fd728d10"
#define BasePlayer_Static_ClassNameShort "%9ddd0c004ec78c6d6574cf4f52792be9fd728d10"
#define BasePlayer_Static_TypeDefinitionIndex 888

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x13b8;
	}

#define BasePlayer_TypeDefinitionIndex 889

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x2d8;
		constexpr const static size_t input = 0x670;
		constexpr const static size_t movement = 0x2e0;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x408;
		constexpr const static size_t playerFlags = 0x5a8;
		constexpr const static size_t eyes = 0x5e8;
		constexpr const static size_t playerRigidbody = 0x320;
		constexpr const static size_t userID = 0x5f0;
		constexpr const static size_t UserIDString = 0x2b0;
		constexpr const static size_t inventory = 0x428;
		constexpr const static size_t _displayName = 0x450;
		constexpr const static size_t _lookingAt = 0x358;
		constexpr const static size_t lastSentTickTime = 0x564;
		constexpr const static size_t lastSentTick = 0x2c8;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x578;
		constexpr const static size_t _lookingAtEntity = 0x4d8;
		constexpr const static size_t currentGesture = 0x400;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x4e2eb80;
		constexpr const static size_t Menu_AssistPlayer = 0x4f42000;
		constexpr const static size_t OnViewModeChanged = 0x4f4d730;
		constexpr const static size_t ChatMessage = 0x4daa0b0;
		constexpr const static size_t IsOnGround = 0x4da9de0;
		constexpr const static size_t GetSpeed = 0x4f33220;
		constexpr const static size_t SendProjectileUpdate = 0x4e16d80;
		constexpr const static size_t SendProjectileAttack = 0x4ec1d40;
		constexpr const static size_t CanBuild = 0x4e3f7f0;
		constexpr const static size_t GetMounted = 0x4f0e300;
		constexpr const static size_t GetHeldEntity = 0x4f40bb0;
		constexpr const static size_t get_inventory = 0x4e80b90;
		constexpr const static size_t get_eyes = 0x4e71990;
		constexpr const static size_t SendClientTick = 0x4dd13c0;
		constexpr const static size_t ClientInput = 0x4ed0580;
		constexpr const static size_t ClientInput_vtableoff = 0x3bd8;
		constexpr const static size_t MaxHealth = 0x4db3b60;
		constexpr const static size_t MaxHealth_vtableoff = 0x2e28;
		constexpr const static size_t OnAttacked = 0x4e70550;
		constexpr const static size_t OnAttacked_vtableoff = 0x2da8;
		constexpr const static size_t get_idealViewMode = 0x4e24e50;
	}

#define ScientistNPC_TypeDefinitionIndex 4294

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 1021

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 429

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 3049

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 1683

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 1018

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 184

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x120dab0;
		constexpr const static size_t BlockSprint = 0x11d88d0;
		constexpr const static size_t GroundCheck = 0x12046a0;
		constexpr const static size_t ClientInput = 0x11fc650;
		constexpr const static size_t ClientInput_vtableoff = 0x408;
		constexpr const static size_t DoFixedUpdate = 0x11f49f0;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x2e8;
		constexpr const static size_t FrameUpdate = 0x11d6700;
		constexpr const static size_t FrameUpdate_vtableoff = 0x238;
		constexpr const static size_t TeleportTo = 0x11e7fa0;
		constexpr const static size_t TeleportTo_vtableoff = 0x418;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 940

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 5260

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 6753

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 3163

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 3159

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%caf64598daac7e0606379476f2456ac550463394
#define ConsoleSystem_ClassName "%caf64598daac7e0606379476f2456ac550463394"
#define ConsoleSystem_ClassNameShort "%caf64598daac7e0606379476f2456ac550463394"
#define ConsoleSystem_TypeDefinitionIndex 23635

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x62bd970;
	}

	// obf name: ::%3c73ff05820f3315faf49bf56ae0e08aad01290b
#define ConsoleSystem_Index_Static_ClassName "%caf64598daac7e0606379476f2456ac550463394/%afb3dd7cec8bc52544e139ccd436a436854ddd5a.%3c73ff05820f3315faf49bf56ae0e08aad01290b"
#define ConsoleSystem_Index_Static_ClassNameShort "%3c73ff05820f3315faf49bf56ae0e08aad01290b"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23628

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0xb8;
	}

#define LootableCorpse_TypeDefinitionIndex 6491

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2c8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 1524

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 391

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x8;
		constexpr const static size_t mainCameraTransform = 0x50;

		// Functions
		constexpr const static size_t Update = 0x2f912a0;
		constexpr const static size_t OnPreCull = 0x2f96d70;
		constexpr const static size_t Trace = 0x2f8da70;
	}

#define CameraMan_TypeDefinitionIndex 5763

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%0595ceac67957ae1af1fae0047d371f7f0307192
#define PlayerTick_ClassName "%0595ceac67957ae1af1fae0047d371f7f0307192"
#define PlayerTick_ClassNameShort "%0595ceac67957ae1af1fae0047d371f7f0307192"
#define PlayerTick_TypeDefinitionIndex 7370

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x38;
		constexpr const static size_t modelState = 0x20;
		constexpr const static size_t activeItem = 0x30;
		constexpr const static size_t parentID = 0x40;
		constexpr const static size_t position = 0x14;
		constexpr const static size_t eyePos = 0x48;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x937d270;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x93796d0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%e98bb5093edfcf05a7bff55c9be319981b0ae0a7
#define InputMessage_ClassName "%e98bb5093edfcf05a7bff55c9be319981b0ae0a7"
#define InputMessage_ClassNameShort "%e98bb5093edfcf05a7bff55c9be319981b0ae0a7"
#define InputMessage_TypeDefinitionIndex 7645

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x1c;
		constexpr const static size_t mouseDelta = 0x10;
		constexpr const static size_t aimAngles = 0x24;
	}

	// obf name: ::%5e5fd780a011fc73841c94057a416d91966ac611
#define InputState_ClassName "%5e5fd780a011fc73841c94057a416d91966ac611"
#define InputState_ClassNameShort "%5e5fd780a011fc73841c94057a416d91966ac611"
#define InputState_TypeDefinitionIndex 6533

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x20;
	}

#define PlayerInput_TypeDefinitionIndex 918

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%c0d3d0c45ca07629489aae96acefb24186888fe9
#define ModelState_ClassName "%c0d3d0c45ca07629489aae96acefb24186888fe9"
#define ModelState_ClassNameShort "%c0d3d0c45ca07629489aae96acefb24186888fe9"
#define ModelState_TypeDefinitionIndex 7434

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x44;
		constexpr const static size_t waterLevel = 0x30;
		constexpr const static size_t lookDir = 0x34;
	}

	// obf name: ::%cf9aa09c0958f5d18a1bb36d32f28198a54f67ca
#define Item_ClassName "%cf9aa09c0958f5d18a1bb36d32f28198a54f67ca"
#define Item_ClassNameShort "%cf9aa09c0958f5d18a1bb36d32f28198a54f67ca"
#define Item_TypeDefinitionIndex 5836

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x88;
		constexpr const static size_t uid = 0x38;
		constexpr const static size_t clientAmmoCount = 0x70;
		constexpr const static size_t _condition = 0x24;
		constexpr const static size_t _maxCondition = 0xc0;
		constexpr const static size_t position = 0xa8;
		constexpr const static size_t amount = 0xe4;
		constexpr const static size_t parent = 0x68;
		constexpr const static size_t contents = 0xb0;
		constexpr const static size_t worldEnt = 0x40;
		constexpr const static size_t heldEntity = 0x50;

		// Functions
		constexpr const static size_t get_iconSprite = 0x3c354c0;
	}

	// obf name: ::%2e06d166cb48fdd198943fe9300aa85433422494
#define WaterLevel_ClassName "%2e06d166cb48fdd198943fe9300aa85433422494"
#define WaterLevel_ClassNameShort "%2e06d166cb48fdd198943fe9300aa85433422494"
#define WaterLevel_TypeDefinitionIndex 303

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x221b400;
		constexpr const static size_t GetWaterLevel = 0x221e800;
	}

	// obf name: ::%637c6ee3198b1e55c3cb54298a967231e556987d
#define ConVar_Graphics_Static_ClassName "%118dc04c3bb53f9df2ab8d26d826f25862fd31e8/%637c6ee3198b1e55c3cb54298a967231e556987d"
#define ConVar_Graphics_Static_ClassNameShort "%637c6ee3198b1e55c3cb54298a967231e556987d"
#define ConVar_Graphics_Static_TypeDefinitionIndex 2483

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x3ac;

		// Functions
		constexpr const static size_t _fov_getter = 0x2af4300;
		constexpr const static size_t _fov_setter = 0x2b0fc40;
	}

#define BaseFishingRod_TypeDefinitionIndex 3135

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x260;
		constexpr const static size_t currentBobber = 0x268;
		constexpr const static size_t MaxCastDistance = 0x284;
		constexpr const static size_t BobberPreview = 0x290;
		constexpr const static size_t clientStrainAmountNormalised = 0x2d0;
		constexpr const static size_t strainGainMod = 0x2e0;
		constexpr const static size_t aimAnimationReady = 0x2e8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x2005de0;
		constexpr const static size_t EvaluateFishingPosition = 0x201b910;
	}

#define FishingBobber_TypeDefinitionIndex 3808

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 6234

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x4039e60;
	}

	// obf name: ::%8256863f5fd78ea43c01cd2996af2fddb2025942
#define GameManager_ClassName "%8256863f5fd78ea43c01cd2996af2fddb2025942"
#define GameManager_ClassNameShort "%8256863f5fd78ea43c01cd2996af2fddb2025942"
#define GameManager_TypeDefinitionIndex 7197

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x28;

		// Functions
		constexpr const static size_t CreatePrefab = 0x4aedbd0;
	}

	// obf name: ::%68ed1074783664922bec05626ae010f8558ec25f
#define GameManager_Static_ClassName "%8256863f5fd78ea43c01cd2996af2fddb2025942/%68ed1074783664922bec05626ae010f8558ec25f"
#define GameManager_Static_ClassNameShort "%68ed1074783664922bec05626ae010f8558ec25f"
#define GameManager_Static_TypeDefinitionIndex 7196

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x8;
	}

	// obf name: ::%40b16ccd0e28945086301b85882acdacfbde716c
#define PrefabPoolCollection_ClassName "%40b16ccd0e28945086301b85882acdacfbde716c"
#define PrefabPoolCollection_ClassNameShort "%40b16ccd0e28945086301b85882acdacfbde716c"
#define PrefabPoolCollection_TypeDefinitionIndex 3498

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%ae2b4a1a37f9351789ee56bc042ceb9cb902e39f
#define PrefabPool_ClassName "%ae2b4a1a37f9351789ee56bc042ceb9cb902e39f"
#define PrefabPool_ClassNameShort "%ae2b4a1a37f9351789ee56bc042ceb9cb902e39f"
#define PrefabPool_TypeDefinitionIndex 340

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x18;
	}

#define ItemModProjectile_TypeDefinitionIndex 6003

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

#define CraftingQueue_TypeDefinitionIndex 2621

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%cb66889d5c0034eb9fb897062e8e2e4dc09134cd
#define CraftingQueue_Static_ClassName "CraftingQueue/%cb66889d5c0034eb9fb897062e8e2e4dc09134cd"
#define CraftingQueue_Static_ClassNameShort "%cb66889d5c0034eb9fb897062e8e2e4dc09134cd"
#define CraftingQueue_Static_TypeDefinitionIndex 2620

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x2a;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 5332

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%45e9ef4d44013eed2bb887f55b749fa20d97dc03
#define Planner_Static_ClassName "Planner/%45e9ef4d44013eed2bb887f55b749fa20d97dc03"
#define Planner_Static_ClassNameShort "%45e9ef4d44013eed2bb887f55b749fa20d97dc03"
#define Planner_Static_TypeDefinitionIndex 6162

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x178;
	}

	// obf name: ::%6b9cbe46a36bace5c99456ec03c35abd421ab6d5
#define Planner_Guide_ClassName "Planner/%6b9cbe46a36bace5c99456ec03c35abd421ab6d5"
#define Planner_Guide_ClassNameShort "%6b9cbe46a36bace5c99456ec03c35abd421ab6d5"
#define Planner_Guide_TypeDefinitionIndex 6158

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0xa0;
	}

#define Planner_TypeDefinitionIndex 6163

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x288;
	}

#define Construction_TypeDefinitionIndex 5323

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x1a0;
	}

#define BuildingBlock_TypeDefinitionIndex 2129

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x318;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 1213

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x5345210;
	}

	// obf name: ::%dcb392fe0f1f2eb0fb9f8a6b85780496b5cd0ba5
#define PunchEntry_ClassName "HeldEntity/%dcb392fe0f1f2eb0fb9f8a6b85780496b5cd0ba5"
#define PunchEntry_ClassNameShort "%dcb392fe0f1f2eb0fb9f8a6b85780496b5cd0ba5"
#define PunchEntry_TypeDefinitionIndex 1211

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x10;
		constexpr const static size_t duration = 0x20;
		constexpr const static size_t amountAdded = 0x14;
		constexpr const static size_t amount = 0x24;
	}

#define IronSights_TypeDefinitionIndex 3910

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 6784

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 1455

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xc0;
		constexpr const static size_t model = 0x88;
		constexpr const static size_t lower = 0xc8;

		// Functions
		constexpr const static size_t get_ActiveModel = 0xdb64d0;
	}

#define ViewModel_TypeDefinitionIndex 928

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x4fd1690;
		constexpr const static size_t PlayString = 0x4fd1110;
	}

#define MedicalTool_TypeDefinitionIndex 6239

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 618

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x68;
	}

	// obf name: ::%12d4e752bcfcee504911f701dee06e5822220e11
#define WaterSystem_Static_ClassName "WaterSystem/%12d4e752bcfcee504911f701dee06e5822220e11"
#define WaterSystem_Static_ClassNameShort "%12d4e752bcfcee504911f701dee06e5822220e11"
#define WaterSystem_Static_TypeDefinitionIndex 5023

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x108;
	}

#define WaterSystem_TypeDefinitionIndex 5024

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x342c2e0;
	}

#define TerrainMeta_TypeDefinitionIndex 3770

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0xe8;
		constexpr const static size_t HeightMap = 0x98;
		constexpr const static size_t SplatMap = 0x578;
		constexpr const static size_t TopologyMap = 0x698;
		constexpr const static size_t Texturing = 0x3a8;
	}

#define TerrainCollision_TypeDefinitionIndex 2790

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x1c52890;
	}

#define TerrainHeightMap_TypeDefinitionIndex 6764

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 3197

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 367

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%59d406571d1e95b4af755671e9343c52c3faaea7
#define World_Static_ClassName "%2f8fd5039d580e5cf624b37892c81f755c545a27/%59d406571d1e95b4af755671e9343c52c3faaea7"
#define World_Static_ClassNameShort "%59d406571d1e95b4af755671e9343c52c3faaea7"
#define World_Static_TypeDefinitionIndex 6405

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x70;
	}

#define ItemIcon_TypeDefinitionIndex 4619

	namespace ItemIcon {

		// Offsets
		constexpr const static size_t backgroundImage = 0xe8;

		// Functions
		constexpr const static size_t TryToMove = 0x30ed4e0;
		constexpr const static size_t TryToMove_vtableoff = 0x558;
		constexpr const static size_t RunTimedAction = 0x30df5e0;
	}

	// obf name: ::%ed5af3d24caaf725dae39902927f1391dd455f70
#define ItemIcon_Static_ClassName "ItemIcon/%ed5af3d24caaf725dae39902927f1391dd455f70"
#define ItemIcon_Static_ClassNameShort "%ed5af3d24caaf725dae39902927f1391dd455f70"
#define ItemIcon_Static_TypeDefinitionIndex 4618

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x38;
	}

	// obf name: ::%9e9b3d9b146db7e0cb98efbef8cfa5da6f04af8c
#define EffectData_ClassName "%9e9b3d9b146db7e0cb98efbef8cfa5da6f04af8c"
#define EffectData_ClassNameShort "%9e9b3d9b146db7e0cb98efbef8cfa5da6f04af8c"
#define EffectData_TypeDefinitionIndex 7380

	namespace EffectData {

		// Offsets
		constexpr const static size_t source = 0x28;
	}

	// obf name: ::%3052b38d7c42f30057163dc9cfd37e1cf3816cfd
#define Effect_ClassName "%3052b38d7c42f30057163dc9cfd37e1cf3816cfd"
#define Effect_ClassNameShort "%3052b38d7c42f30057163dc9cfd37e1cf3816cfd"
#define Effect_TypeDefinitionIndex 1179

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0xa0;
		constexpr const static size_t worldPos = 0x80;
	}

	// obf name: ::%4b24a4e18abc21b49382097c88d269910216bc96
#define EffectLibrary_ClassName "%4b24a4e18abc21b49382097c88d269910216bc96"
#define EffectLibrary_ClassNameShort "%4b24a4e18abc21b49382097c88d269910216bc96"
#define EffectLibrary_TypeDefinitionIndex 464

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x3b06860;
	}

	// obf name: ::%dee288f7b74ed5eec12c7eea5c65d4f55c819ce0
#define EffectNetwork_ClassName "%dee288f7b74ed5eec12c7eea5c65d4f55c819ce0"
#define EffectNetwork_ClassNameShort "%dee288f7b74ed5eec12c7eea5c65d4f55c819ce0"
#define EffectNetwork_TypeDefinitionIndex 3850

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%e501cee83e2d155fe62acf19b2391c25693ad42a
#define EffectNetwork_Static_ClassName "%dee288f7b74ed5eec12c7eea5c65d4f55c819ce0/%e501cee83e2d155fe62acf19b2391c25693ad42a"
#define EffectNetwork_Static_ClassNameShort "%e501cee83e2d155fe62acf19b2391c25693ad42a"
#define EffectNetwork_Static_TypeDefinitionIndex 3849

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x28;

		// Functions
		constexpr const static size_t cctor = 0x27d18d0;
	}

#define BuildingBlock_TypeDefinitionIndex 2129

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x1484b30;
		constexpr const static size_t HasUpgradePrivilege = 0x1480910;
		constexpr const static size_t CanAffordUpgrade = 0x14a7980;
	}

	// obf name: ::%de08a3fce9e9e75bcfb9474faac4039a7f9d393d
#define GameObjectEx_ClassName "%de08a3fce9e9e75bcfb9474faac4039a7f9d393d"
#define GameObjectEx_ClassNameShort "%de08a3fce9e9e75bcfb9474faac4039a7f9d393d"
#define GameObjectEx_TypeDefinitionIndex 1326

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0xc2c3e0;
	}

#define UIDeathScreen_TypeDefinitionIndex 4746

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x3228c60;
	}

	// obf name: ::%2374db49842fa9c8a221e8c214706ee14075d934
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%2374db49842fa9c8a221e8c214706ee14075d934"
#define BaseScreenShake_Static_ClassNameShort "%2374db49842fa9c8a221e8c214706ee14075d934"
#define BaseScreenShake_Static_TypeDefinitionIndex 4977

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x120;
	}

#define FlashbangOverlay_TypeDefinitionIndex 5573

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x38;
		constexpr const static size_t flashLength = 0x40;
	}

	// obf name: ::%eecc9c131916f8c003df0924c6b21c4c1a47c753
#define StringPool_ClassName "%eecc9c131916f8c003df0924c6b21c4c1a47c753"
#define StringPool_ClassNameShort "%eecc9c131916f8c003df0924c6b21c4c1a47c753"
#define StringPool_TypeDefinitionIndex 3246

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x38;

		// Functions
		constexpr const static size_t Get = 0x213ae60;
	}

	// obf name: ::%572ed407025d8efed8f70abb911d69f3402a1131
#define Network_Networkable_ClassName "%572ed407025d8efed8f70abb911d69f3402a1131"
#define Network_Networkable_ClassNameShort "%572ed407025d8efed8f70abb911d69f3402a1131"
#define Network_Networkable_TypeDefinitionIndex 18806

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x18;
	}

	// obf name: ::%e611e5c155e7886f0509c73f4cf1b0479aa13082
#define Network_Net_ClassName "%e611e5c155e7886f0509c73f4cf1b0479aa13082"
#define Network_Net_ClassNameShort "%e611e5c155e7886f0509c73f4cf1b0479aa13082"
#define Network_Net_TypeDefinitionIndex 9932

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x30;
	}

	// obf name: ::%08016b067c442e2b6be5b1767b99603aec9a9422
#define Network_Client_ClassName "%08016b067c442e2b6be5b1767b99603aec9a9422"
#define Network_Client_ClassNameShort "%08016b067c442e2b6be5b1767b99603aec9a9422"
#define Network_Client_TypeDefinitionIndex 18809

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf8;
		constexpr const static size_t ConnectedPort = 0xf0;
		constexpr const static size_t ConnectedAddress = 0x108;
		constexpr const static size_t ServerName = 0x120;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x63a1090;
		constexpr const static size_t DestroyNetworkable = 0x63a1470;
	}

	// obf name: ::%d027713e0a23e9a40595a6e177d932b654905c5b
#define Network_BaseNetwork_ClassName "%d027713e0a23e9a40595a6e177d932b654905c5b"
#define Network_BaseNetwork_ClassNameShort "%d027713e0a23e9a40595a6e177d932b654905c5b"
#define Network_BaseNetwork_TypeDefinitionIndex 18744

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x633a4b0;
	}

	// obf name: ::%91c6f52875b8a3fc0e59f461fb4cd065c50f9c82
#define Network_SendInfo_ClassName "%91c6f52875b8a3fc0e59f461fb4cd065c50f9c82"
#define Network_SendInfo_ClassNameShort "%91c6f52875b8a3fc0e59f461fb4cd065c50f9c82"
#define Network_SendInfo_TypeDefinitionIndex 18759

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%1740571b2acae49282bbaaf3afd5d5c7a55e6cdf
#define Network_Message_ClassName "%1740571b2acae49282bbaaf3afd5d5c7a55e6cdf"
#define Network_Message_ClassNameShort "%1740571b2acae49282bbaaf3afd5d5c7a55e6cdf"
#define Network_Message_TypeDefinitionIndex 18800

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%9d64308cc356cd176611b84c34925e3c9fd63ac7
#define Network_NetRead_ClassName "%9d64308cc356cd176611b84c34925e3c9fd63ac7"
#define Network_NetRead_ClassNameShort "%9d64308cc356cd176611b84c34925e3c9fd63ac7"
#define Network_NetRead_TypeDefinitionIndex 18766

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x40;
	}

	// obf name: ::%fb7174dfc9cc4d0cd139d8638637ea52994a71fb
#define Network_NetWrite_ClassName "%fb7174dfc9cc4d0cd139d8638637ea52994a71fb"
#define Network_NetWrite_ClassNameShort "%fb7174dfc9cc4d0cd139d8638637ea52994a71fb"
#define Network_NetWrite_TypeDefinitionIndex 18815

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x48;

		// Functions
		constexpr const static size_t WriteByte = 0x63a5eb0;
		constexpr const static size_t String = 0x63a6af0;
		constexpr const static size_t Send = 0x63acac0;
	}

#define LootPanel_TypeDefinitionIndex 6335

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x41364d0;
	}

#define UIInventory_TypeDefinitionIndex 4034

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x29b0520;
	}

#define GrowableEntity_TypeDefinitionIndex 3625

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 3015

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 3014

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 21306

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 9638

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
		constexpr const static size_t get_Instance = 0x9e1da0;
	}

	// obf name: ::%17844af9641f9f5a09be50923175f86daa3dd2fb
#define TOD_Sky_Static_ClassName "TOD_Sky/%17844af9641f9f5a09be50923175f86daa3dd2fb"
#define TOD_Sky_Static_ClassNameShort "%17844af9641f9f5a09be50923175f86daa3dd2fb"
#define TOD_Sky_Static_TypeDefinitionIndex 9637

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x90;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 10090

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xadb390;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 7780

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9365

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8003

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 7951

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 9486

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8136

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 194

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 1812

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 4984

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 3038

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

#define EnvironmentManager_TypeDefinitionIndex 3999

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x296f7a0;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%c95fb8e8319a94b2ef4918383691c7c4d69d4064/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24375

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 2399

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 2400

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 604

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
		constexpr const static size_t InstanceList = 0x8;
	}

	// obf name: ::%28bb1c504a46c76c570517f1ca702eabaf53256a
#define ListHashSet_ClassName "%28bb1c504a46c76c570517f1ca702eabaf53256a<UIChat>"
#define ListHashSet_ClassNameShort "%28bb1c504a46c76c570517f1ca702eabaf53256a"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 3081

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3e8;
	}

#define Chainsaw_TypeDefinitionIndex 3493

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x38c;
	}

	// obf name: ::%7e2681f1da0e013227eec9627eeedb439ac19271
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%7e2681f1da0e013227eec9627eeedb439ac19271"
#define CameraUpdateHook_Static_ClassNameShort "%7e2681f1da0e013227eec9627eeedb439ac19271"
#define CameraUpdateHook_Static_TypeDefinitionIndex 2420

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x40;
	}

#define SteamClientWrapper_TypeDefinitionIndex 4944

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x336a1f0;
	}

	// obf name: ::%b98eb6408c1010f576863e3fb8ace2ec91ad7eb7
#define AimConeUtil_ClassName "%b98eb6408c1010f576863e3fb8ace2ec91ad7eb7"
#define AimConeUtil_ClassNameShort "%b98eb6408c1010f576863e3fb8ace2ec91ad7eb7"
#define AimConeUtil_TypeDefinitionIndex 2651

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x1ac60f0;
	}

	// obf name: ::%3b6257cf4928b636bf330e418a209f64f94313f2
#define Buttons_ConButton_ClassName "%c4e4f3453c5f48df3e20d085e1b60d3ab3875431/%3b6257cf4928b636bf330e418a209f64f94313f2"
#define Buttons_ConButton_ClassNameShort "%3b6257cf4928b636bf330e418a209f64f94313f2"
#define Buttons_ConButton_TypeDefinitionIndex 2737

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x14;
	}

	// obf name: ::%3a25c0bc6a8ba621f0a2c93dc44e6094f0e156ca
#define Buttons_Static_ClassName "%c4e4f3453c5f48df3e20d085e1b60d3ab3875431/%3a25c0bc6a8ba621f0a2c93dc44e6094f0e156ca"
#define Buttons_Static_ClassNameShort "%3a25c0bc6a8ba621f0a2c93dc44e6094f0e156ca"
#define Buttons_Static_TypeDefinitionIndex 2738

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x478;
		constexpr const static size_t Attack = 0xf78;
		constexpr const static size_t Attack2 = 0x8f8;
		constexpr const static size_t Forward = 0x7c0;
		constexpr const static size_t Backward = 0x530;
		constexpr const static size_t Right = 0xbf0;
		constexpr const static size_t Left = 0x438;
		constexpr const static size_t Sprint = 0x728;
		constexpr const static size_t Use = 0x328;

		// Functions
		constexpr const static size_t Pets_setter = 0x2ad43e0;
	}

#define PlayerModel_TypeDefinitionIndex 6672

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x3d8;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 5489

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x50;
	}

#define BaseMountable_TypeDefinitionIndex 1064

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 5233

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x30;
		constexpr const static size_t timeCounter = 0x2c;
	}

#define BowWeapon_TypeDefinitionIndex 5138

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x410;
		constexpr const static size_t wasAiming = 0x420;
	}

#define CrossbowWeapon_TypeDefinitionIndex 1469

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 6333

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%c63534f60164410c1f9020334dfb97449a9df557
#define ConVar_Admin_Static_ClassName "%c53285300964f91f4c11a4640bcca1c575aa0578/%c63534f60164410c1f9020334dfb97449a9df557"
#define ConVar_Admin_Static_ClassNameShort "%c63534f60164410c1f9020334dfb97449a9df557"
#define ConVar_Admin_Static_TypeDefinitionIndex 3722

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x38;

		// Functions
		constexpr const static size_t admintime_getter = 0x2b12bb0;
		constexpr const static size_t admintime_setter = 0x2afe880;
	}

	// obf name: ::%3218a39e67eb4e318983d4eaf9dab80f31aa36a5
#define ConVar_Player_Static_ClassName "%cb3605cc492dc4fab7701e3d0fc70a731c5965a4/%3218a39e67eb4e318983d4eaf9dab80f31aa36a5"
#define ConVar_Player_Static_ClassNameShort "%3218a39e67eb4e318983d4eaf9dab80f31aa36a5"
#define ConVar_Player_Static_TypeDefinitionIndex 1855

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x14;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x2b03c60;
		constexpr const static size_t clientTickRate_setter = 0x2ae23b0;
	}

#define ColliderInfo_TypeDefinitionIndex 5745

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 409

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 2262

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

#define Client_TypeDefinitionIndex 6830

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x4677fb0;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%906236cbc63f10c5988cbbf79f650f4855764b0e
#define ItemManager_Static_ClassName "%5cd92996eac7a60082bf8bd4b8e941e18b50de49/%906236cbc63f10c5988cbbf79f650f4855764b0e"
#define ItemManager_Static_ClassNameShort "%906236cbc63f10c5988cbbf79f650f4855764b0e"
#define ItemManager_Static_TypeDefinitionIndex 5066

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x88;
		constexpr const static size_t itemDictionary = 0x1f0;
		constexpr const static size_t itemDictionaryByName = 0x118;
	}

	// obf name: ::%e49ccc826a0d9ad68aa8ff871bc2e66068f85b29
#define ConVar_Server_Static_ClassName "%b6a09d11c8e92a5f72c7a361b02181d780f896c0/%e49ccc826a0d9ad68aa8ff871bc2e66068f85b29"
#define ConVar_Server_Static_ClassNameShort "%e49ccc826a0d9ad68aa8ff871bc2e66068f85b29"
#define ConVar_Server_Static_TypeDefinitionIndex 127

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 1164

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x52d9e10;
	}

#define LoadingScreen_TypeDefinitionIndex 5633

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x30;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 4307

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%9223aba26042e7723b1fec04e0bab90da39bbbe3"
#define MapView_Static_ClassNameShort "%9223aba26042e7723b1fec04e0bab90da39bbbe3"
#define MapView_TypeDefinitionIndex 7108

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x4a18c50;
	}

	// obf name: ::%e0ead001a7e9c1bd7eb1585133cd62227549e5a0
#define GamePhysics_Static_ClassName "%6ead327ad95e23b4fa65a0c71e667f5da2f9c5ad/%e0ead001a7e9c1bd7eb1585133cd62227549e5a0"
#define GamePhysics_Static_ClassNameShort "%e0ead001a7e9c1bd7eb1585133cd62227549e5a0"
#define GamePhysics_Static_TypeDefinitionIndex 6531

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x10;
	}

	// obf name: ::%6ead327ad95e23b4fa65a0c71e667f5da2f9c5ad
#define GamePhysics_ClassName "%6ead327ad95e23b4fa65a0c71e667f5da2f9c5ad"
#define GamePhysics_ClassNameShort "%6ead327ad95e23b4fa65a0c71e667f5da2f9c5ad"
#define GamePhysics_TypeDefinitionIndex 6532

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x42c8dd0;
		constexpr const static size_t LineOfSightInternal = 0x42e3e30;
		constexpr const static size_t Verify = 0x42dcfd0;
	}

#define InstancedDebugDraw_TypeDefinitionIndex 5440

	namespace InstancedDebugDraw {

		// Functions
		constexpr const static size_t AddInstance = 0x3847a10;
	}

	// obf name: ::%ab0d4352cc5d682b5d91f45f1dc4cdea36cd6744
#define RaycastHitEx_ClassName "%ab0d4352cc5d682b5d91f45f1dc4cdea36cd6744"
#define RaycastHitEx_ClassNameShort "%ab0d4352cc5d682b5d91f45f1dc4cdea36cd6744"
#define RaycastHitEx_TypeDefinitionIndex 4446

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x2fb0780;
	}

	// obf name: ::%6ecbd288c33663afc7503639aeebec3ae418b3af
#define OnParentDestroyingEx_ClassName "%6ecbd288c33663afc7503639aeebec3ae418b3af"
#define OnParentDestroyingEx_ClassNameShort "%6ecbd288c33663afc7503639aeebec3ae418b3af"
#define OnParentDestroyingEx_TypeDefinitionIndex 2455

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x1848040;
	}

	// obf name: ::%77f7ed4f9fbff9aa527d22dd422b1deec1548e45
#define ConsoleNetwork_ClassName "%77f7ed4f9fbff9aa527d22dd422b1deec1548e45"
#define ConsoleNetwork_ClassNameShort "%77f7ed4f9fbff9aa527d22dd422b1deec1548e45"
#define ConsoleNetwork_TypeDefinitionIndex 1691

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x105b460;
	}

#define ThrownWeapon_TypeDefinitionIndex 5881

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 1379

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 4021

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 7108

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 2511

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 4609

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 2343

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 5561

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 4652

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 4682

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%86580b5fee1631f0c4129a373cade26e4a103b38
#define ConVar_Client_Static_ClassName "%893c31c6d098c0b7a8ee64142bbd1acf8f91040e/%86580b5fee1631f0c4129a373cade26e4a103b38"
#define ConVar_Client_Static_ClassNameShort "%86580b5fee1631f0c4129a373cade26e4a103b38"
#define ConVar_Client_Static_TypeDefinitionIndex 451

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x930;
		constexpr const static size_t camspeed = 0x22c;
	}

#define SamSite_TypeDefinitionIndex 151

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 4967

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 3314

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x28;
	}

#define FoliageGrid_TypeDefinitionIndex 4578

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 5422

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 2283

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 3387

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 2379

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%63106edfe9ae4edfc3b123167e01f7c24e924556
#define Facepunch_Network_Raknet_Client_ClassName "%63106edfe9ae4edfc3b123167e01f7c24e924556"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%63106edfe9ae4edfc3b123167e01f7c24e924556"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 23126

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x63f55c0;
		constexpr const static size_t IsConnected_vtableoff = 0x528;
	}

	// obf name: ::%0188bee8f52ee3b63a64795b1ee4aafa257e1032
#define EncryptedValue_ClassName "%0188bee8f52ee3b63a64795b1ee4aafa257e1032<System/Int32>"
#define EncryptedValue_ClassNameShort "%0188bee8f52ee3b63a64795b1ee4aafa257e1032"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%cff7731776b97594f83b482e8ef5037f78675020
#define HiddenValue_ClassName "%cff7731776b97594f83b482e8ef5037f78675020<BaseNetworkable/%171ac9b646b488e2a8769d91e0fc7765de5a3b84>"
#define HiddenValue_ClassNameShort "%cff7731776b97594f83b482e8ef5037f78675020"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x20;
		constexpr const static size_t _hasValue = 0x10;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex -1

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x0;
	}

#define ItemModRFListener_TypeDefinitionIndex 4028

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x29a18f0;
	}

#define UIFogOverlay_TypeDefinitionIndex 3314

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
	}

	// obf name: ::%32490dddfed47b0395213968e7db07c61e4222c5
#define BufferStream_ClassName "%32490dddfed47b0395213968e7db07c61e4222c5"
#define BufferStream_ClassNameShort "%32490dddfed47b0395213968e7db07c61e4222c5"
#define BufferStream_TypeDefinitionIndex 7323

	namespace BufferStream {

		// Offsets
		constexpr const static size_t _buffer = 0x20;

		// Functions
		constexpr const static size_t EnsureCapacity = 0x92098e0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 306

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 813

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 6512

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x427fd50;
	}

#define OutlineManager_TypeDefinitionIndex 3980

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%b6a3bdc1ec9c8844adf58fb44e19bf3c6c72b4a8
#define ConsoleSystem_Command_ClassName "%caf64598daac7e0606379476f2456ac550463394/%b6a3bdc1ec9c8844adf58fb44e19bf3c6c72b4a8"
#define ConsoleSystem_Command_ClassNameShort "%b6a3bdc1ec9c8844adf58fb44e19bf3c6c72b4a8"
#define ConsoleSystem_Command_TypeDefinitionIndex 23620

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x18;
		constexpr const static size_t SetOveride = 0x20;
		constexpr const static size_t Call = 0x78;
	}

	// obf name: ::%fbb0beb057868c4affd8c6cdaa7951259d245364
#define ConsoleSystem_Option_ClassName "%caf64598daac7e0606379476f2456ac550463394/%fbb0beb057868c4affd8c6cdaa7951259d245364"
#define ConsoleSystem_Option_ClassNameShort "%fbb0beb057868c4affd8c6cdaa7951259d245364"
#define ConsoleSystem_Option_TypeDefinitionIndex 23630

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%519ac7dbfcfff996db433338a93739ef36ea1b63
#define ConsoleSystem_Arg_ClassName "%caf64598daac7e0606379476f2456ac550463394/%519ac7dbfcfff996db433338a93739ef36ea1b63"
#define ConsoleSystem_Arg_ClassNameShort "%519ac7dbfcfff996db433338a93739ef36ea1b63"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23618

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x48;
	}

	// obf name: ::%6b345416a435e1d4d3fe09e0edc7499ab4dedc0a
#define ConsoleSystem_Index_Client_ClassName "%caf64598daac7e0606379476f2456ac550463394/%afb3dd7cec8bc52544e139ccd436a436854ddd5a.%6b345416a435e1d4d3fe09e0edc7499ab4dedc0a"
#define ConsoleSystem_Index_Client_ClassNameShort "%6b345416a435e1d4d3fe09e0edc7499ab4dedc0a"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23626

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x62ca620;
	}

#define String_TypeDefinitionIndex 10495

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x8468e00;
	}

	// obf name: ::%79eeba6329fe163ec5d418385002a047565eb59a
#define EntityRef_ClassName "%79eeba6329fe163ec5d418385002a047565eb59a"
#define EntityRef_ClassNameShort "%79eeba6329fe163ec5d418385002a047565eb59a"
#define EntityRef_TypeDefinitionIndex 3920

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x2889f20;
	}

#define ConVar_Debugging_TypeDefinitionIndex -1

	namespace ConVar_Debugging {

		// Functions
		constexpr const static size_t debugcamera = 0x2affe50;
		constexpr const static size_t noclip = 0x2aff180;
	}

#define CursorManager_TypeDefinitionIndex 4499

	namespace CursorManager {

		// Offsets
	}

	// obf name: ::%4cddf804f0ed2a9174d1b04c44bce79c288febbc
#define ProtoBuf_ProjectileShoot_ClassName "%4cddf804f0ed2a9174d1b04c44bce79c288febbc"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%4cddf804f0ed2a9174d1b04c44bce79c288febbc"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7462

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x10;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9704670;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9707b60;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%847fe66e39bc620acb91ed10150718979e77dd3b
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%4cddf804f0ed2a9174d1b04c44bce79c288febbc/%847fe66e39bc620acb91ed10150718979e77dd3b"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%847fe66e39bc620acb91ed10150718979e77dd3b"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7461

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t startPos = 0x2c;
		constexpr const static size_t startVel = 0x20;
		constexpr const static size_t seed = 0x18;
	}

	// obf name: ::%518cd9bef7413470719b7e7cb491d8867b3a4f8e
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%518cd9bef7413470719b7e7cb491d8867b3a4f8e"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%518cd9bef7413470719b7e7cb491d8867b3a4f8e"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7404

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x24;
		constexpr const static size_t curPosition = 0x10;
		constexpr const static size_t curVelocity = 0x28;
		constexpr const static size_t travelTime = 0x20;
		constexpr const static size_t ShouldPool = 0x34;

		// Functions
		constexpr const static size_t Dispose = 0x94e06f0;
		constexpr const static size_t WriteToStreamDelta = 0x94e0910;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x94e42c0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%28f67beb6e9492ba907c5015744a89bd338c05b9
#define ProtoBuf_PlayerProjectileAttack_ClassName "%28f67beb6e9492ba907c5015744a89bd338c05b9"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%28f67beb6e9492ba907c5015744a89bd338c05b9"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7541

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x20;
		constexpr const static size_t hitDistance = 0x34;
		constexpr const static size_t travelTime = 0x30;
		constexpr const static size_t playerAttack = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x89181a0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x890fe70;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%bb726b156686e4b5e887ac1c295296dc09dec176
#define ProtoBuf_PlayerAttack_ClassName "%bb726b156686e4b5e887ac1c295296dc09dec176"
#define ProtoBuf_PlayerAttack_ClassNameShort "%bb726b156686e4b5e887ac1c295296dc09dec176"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7699

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%383f30186ef908c146e9b21e96bcaa88c916b405
#define ProtoBuf_Attack_ClassName "%383f30186ef908c146e9b21e96bcaa88c916b405"
#define ProtoBuf_Attack_ClassNameShort "%383f30186ef908c146e9b21e96bcaa88c916b405"
#define ProtoBuf_Attack_TypeDefinitionIndex 7516

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x1c;
		constexpr const static size_t pointEnd = 0x50;
		constexpr const static size_t hitID = 0x40;
		constexpr const static size_t hitBone = 0x18;
		constexpr const static size_t hitNormalLocal = 0x68;
		constexpr const static size_t hitPositionLocal = 0x78;
		constexpr const static size_t hitNormalWorld = 0x5c;
		constexpr const static size_t hitPositionWorld = 0x28;
		constexpr const static size_t hitPartID = 0x74;
		constexpr const static size_t hitMaterialID = 0x4c;
		constexpr const static size_t srcParentID = 0x38;
		constexpr const static size_t dstParentID = 0x10;
	}
}