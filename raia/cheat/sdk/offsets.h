#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68e5277e;
		constexpr const static size_t gc_handles = 0xd81c1c0;
		constexpr const static size_t il2cpp_resolve_icall = 0x7a5c30;
		constexpr const static size_t il2cpp_array_new = 0x7a5c50;
		constexpr const static size_t il2cpp_assembly_get_image = 0x123e40;
		constexpr const static size_t il2cpp_class_from_name = 0x7a5dc0;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x7a60d0;
		constexpr const static size_t il2cpp_class_get_type = 0x7a6170;
		constexpr const static size_t il2cpp_domain_get = 0x7a66d0;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x7a66f0;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x7a6fb0;
		constexpr const static size_t il2cpp_gchandle_new = 0x7a6f60;
		constexpr const static size_t il2cpp_gchandle_free = 0x7a7050;
		constexpr const static size_t il2cpp_method_get_name = 0x4970;
		constexpr const static size_t il2cpp_object_new = 0x7a7700;
		constexpr const static size_t il2cpp_type_get_object = 0x7a7ef0;
	}

#define Object_TypeDefinitionIndex 16763

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xb0dcf30;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16734

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

#define Component_TypeDefinitionIndex 16721

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16715

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 16798

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xb0e8ad0;
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

#define Camera_TypeDefinitionIndex 16513

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16785

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

#define Material_TypeDefinitionIndex 16576

	namespace Material {

		// Functions
		constexpr const static size_t SetFloatImpl = 0xb6da0;
		constexpr const static size_t SetColorImpl_Injected = 0xb6ee0;
		constexpr const static size_t SetTextureImpl = 0xb7140;
		constexpr const static size_t CreateWithMaterial = 0xaf1c0;
		constexpr const static size_t CreateWithShader = 0xaf050;
		constexpr const static size_t SetBufferImpl = 0xb7490;
		constexpr const static size_t set_shader = 0xaf740;
	}

#define MaterialPropertyBlock_TypeDefinitionIndex 16572

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xb09ccf0;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16575

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xb0a0420;
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16631

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

#define Renderer_TypeDefinitionIndex 16573

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16634

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16636

	namespace Texture2D {
		constexpr const static size_t ctor = 0xb0b6530;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define RenderTexture_TypeDefinitionIndex 16641

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xb0bf170;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17111

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb103000;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17087

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xb0fd030;
	}

#define ComputeBuffer_TypeDefinitionIndex 16776

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb0e0a40;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xb0e0c90;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16580

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb0a73b0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xb0a70e0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 21916

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xb125540;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16553

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16664

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24479

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16550

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24357

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

#define Application_TypeDefinitionIndex 16496

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16662

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23294

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xb16b370;
		constexpr const static size_t RaycastNonAlloc = 0xb16da40;
	}

#define BaseNetworkable_TypeDefinitionIndex 4175

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x50;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x40;
	}

	// obf name: ::%330f8db071ad7041d1baafaa4ac53a1c51394ff1
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%330f8db071ad7041d1baafaa4ac53a1c51394ff1"
#define BaseNetworkable_Static_ClassNameShort "%330f8db071ad7041d1baafaa4ac53a1c51394ff1"
#define BaseNetworkable_Static_TypeDefinitionIndex 4174

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x38;
	}

	// obf name: ::%63fcb16c26f67f4df901ee108183bb9e4960b3c0
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%63fcb16c26f67f4df901ee108183bb9e4960b3c0"
#define BaseNetworkable_EntityRealm_ClassNameShort "%63fcb16c26f67f4df901ee108183bb9e4960b3c0"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 4172

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x2d2b0c0;
	}

	// obf name: ::%755488969cd06668ff85bc5bd0a17c819113de19
#define System_ListDictionary_ClassName "%755488969cd06668ff85bc5bd0a17c819113de19<%b988204fb9336a18fbb80a04d6243dfa884d1716,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%755488969cd06668ff85bc5bd0a17c819113de19"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x20;

		// Functions
		constexpr const static size_t TryGetValue = 0x767d7a0;
		constexpr const static size_t TryGetValue_methodinfo = 0xd4f8700;
	}

	// obf name: ::%075ad6f7e9950907bbf6354b8216070d3935f082
#define System_BufferList_ClassName "%075ad6f7e9950907bbf6354b8216070d3935f082<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%075ad6f7e9950907bbf6354b8216070d3935f082"
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

#define Model_TypeDefinitionIndex 6190

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t eyeBone = 0x38;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 4056

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0xa0;
		constexpr const static size_t positionLerp = 0x118;

		// Functions
		constexpr const static size_t ServerRPC = 0x2c11a10;
		constexpr const static size_t FindBone = 0x2bc6620;
		constexpr const static size_t GetWorldVelocity = 0x2bc1450;
		constexpr const static size_t GetParentVelocity = 0x2bd6bf0;
	}

	// obf name: ::%2d47b47ed1ba49ffb868bbfd9962aa4decb6f3e5
#define PositionLerp_ClassName "%2d47b47ed1ba49ffb868bbfd9962aa4decb6f3e5"
#define PositionLerp_ClassNameShort "%2d47b47ed1ba49ffb868bbfd9962aa4decb6f3e5"
#define PositionLerp_TypeDefinitionIndex 2637

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x30;
	}

	// obf name: ::%9bc4a1fc266ce4f28860e2a9200320da6a3166b9
#define Interpolator_ClassName "%9bc4a1fc266ce4f28860e2a9200320da6a3166b9<%fb118e06b131ad05647823fe10e1b577196ed612>"
#define Interpolator_ClassNameShort "%9bc4a1fc266ce4f28860e2a9200320da6a3166b9"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 1305

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

#define SkeletonProperties_TypeDefinitionIndex 4358

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 4356

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 6222

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 6221

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%5a70867db60b4eeb582b7c22dcfa2b7f047e1092
#define DamageTypeList_ClassName "%5a70867db60b4eeb582b7c22dcfa2b7f047e1092"
#define DamageTypeList_ClassNameShort "%5a70867db60b4eeb582b7c22dcfa2b7f047e1092"
#define DamageTypeList_TypeDefinitionIndex 4491

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 3593

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 6701

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x40;
		constexpr const static size_t iconSprite = 0x50;
		constexpr const static size_t category = 0x58;
		constexpr const static size_t stackable = 0x70;
		constexpr const static size_t rarity = 0x88;
		constexpr const static size_t ItemModWearable = 0x178;
	}

#define RecoilProperties_TypeDefinitionIndex 5228

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 3861

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 927

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x5075880;
		constexpr const static size_t StartAttackCooldown = 0x5077be0;
	}

#define BaseProjectile_TypeDefinitionIndex 3865

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
		constexpr const static size_t isBurstWeapon = 0x38a;
		constexpr const static size_t cachedModHash = 0x3bc;
		constexpr const static size_t sightAimConeScale = 0x3c0;
		constexpr const static size_t sightAimConeOffset = 0x3c4;
		constexpr const static size_t hipAimConeScale = 0x3c8;
		constexpr const static size_t hipAimConeOffset = 0x3cc;

		// Functions
		constexpr const static size_t LaunchProjectile = 0x2a08a00;
		constexpr const static size_t LaunchProjectileClientSide = 0x29fa410;
		constexpr const static size_t ScaleRepeatDelay = 0x2a0ecc0;
		constexpr const static size_t GetAimCone = 0x2a04fa0;
		constexpr const static size_t GetAimCone_vtableoff = 0x3f88;
		constexpr const static size_t UpdateAmmoDisplay = 0x2a17540;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x4168;
	}

#define BaseLauncher_TypeDefinitionIndex 3113

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 2906

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%d913d35e355e74a0e7bcfd365ac1a86c08b9b0ac
#define HitTest_ClassName "%d913d35e355e74a0e7bcfd365ac1a86c08b9b0ac"
#define HitTest_ClassNameShort "%d913d35e355e74a0e7bcfd365ac1a86c08b9b0ac"
#define HitTest_TypeDefinitionIndex 5980

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x10;
		constexpr const static size_t AttackRay = 0x80;
		constexpr const static size_t RayHit = 0x40;
		constexpr const static size_t damageProperties = 0xd0;
		constexpr const static size_t gameObject = 0x98;
		constexpr const static size_t collider = 0xb0;
		constexpr const static size_t ignoredTypes = 0x18;
		constexpr const static size_t HitTransform = 0xc0;
		constexpr const static size_t HitPart = 0xd8;
		constexpr const static size_t HitMaterial = 0x28;
		constexpr const static size_t DidHit = 0x20;
		constexpr const static size_t MaxDistance = 0x3c;
		constexpr const static size_t HitNormal = 0x30;
		constexpr const static size_t HitPoint = 0xa0;
		constexpr const static size_t HitEntity = 0x70;
		constexpr const static size_t ignoreEntity = 0xb8;
	}

#define Projectile_TypeDefinitionIndex 2820

	namespace Projectile {

		// Offsets
		constexpr const static size_t initialVelocity = 0x28;
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t thickness = 0x3c;
		constexpr const static size_t initialDistance = 0x44;
		constexpr const static size_t swimScale = 0xf0;
		constexpr const static size_t swimSpeed = 0xfc;
		constexpr const static size_t owner = 0x1d0;
		constexpr const static size_t sourceProjectilePrefab = 0x120;
		constexpr const static size_t mod = 0x1e0;
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
		constexpr const static size_t CalculateEffectScale = 0x1eb59c0;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x288;
		constexpr const static size_t SetEffectScale = 0x1ea2f50;
		constexpr const static size_t UpdateVelocity = 0x1eb9f80;
		constexpr const static size_t Retire = 0x1e9e300;
		constexpr const static size_t DoHit = 0x1eca300;
	}

	// obf name: ::%c5e70e40ea0cc5686c60d5fbb5f02af3745d3937
#define HitInfo_ClassName "%c5e70e40ea0cc5686c60d5fbb5f02af3745d3937"
#define HitInfo_ClassNameShort "%c5e70e40ea0cc5686c60d5fbb5f02af3745d3937"
#define HitInfo_TypeDefinitionIndex 2781

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0xb0;
		constexpr const static size_t damageTypes = 0x48;

		// Functions
		constexpr const static size_t get_boneArea = 0x1e6ff60;
	}

	// obf name: ::%425efc6f4d8e1ac94a29b465d4ece38282cea302
#define GameTrace_ClassName "%425efc6f4d8e1ac94a29b465d4ece38282cea302"
#define GameTrace_ClassNameShort "%425efc6f4d8e1ac94a29b465d4ece38282cea302"
#define GameTrace_TypeDefinitionIndex 4662

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x32b1540;
	}

#define BaseMelee_TypeDefinitionIndex 5775

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x40b7390;
		constexpr const static size_t DoThrow = 0x40c68e0;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 4819

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x408;
		constexpr const static size_t strikeRecoil = 0x410;
		constexpr const static size_t _didSparkThisFrame = 0x418;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 7109

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x420;
		constexpr const static size_t stringBonusVelocity = 0x42c;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x4e51d40;
	}

	// obf name: ::%6e3e7815b87f6a473840b3315c3e296eab5c8f23
#define ItemContainer_ClassName "%6e3e7815b87f6a473840b3315c3e296eab5c8f23"
#define ItemContainer_ClassNameShort "%6e3e7815b87f6a473840b3315c3e296eab5c8f23"
#define ItemContainer_TypeDefinitionIndex 2002

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x20;
		constexpr const static size_t itemList = 0x68;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x140b5f0;
	}

#define PlayerLoot_TypeDefinitionIndex 6455

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 5427

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x28;
		constexpr const static size_t containerMain = 0x58;
		constexpr const static size_t containerWear = 0x60;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x3b52f90;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 4779

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x3421420;
		constexpr const static size_t get_rotation = 0x3412c50;
		constexpr const static size_t set_rotation = 0x3408670;
		constexpr const static size_t HeadForward = 0x3427870;
	}

	// obf name: ::%895c2a32cc8c31927ebfabb7ea02249885e7c276
#define PlayerEyes_Static_ClassName "PlayerEyes/%895c2a32cc8c31927ebfabb7ea02249885e7c276"
#define PlayerEyes_Static_ClassNameShort "%895c2a32cc8c31927ebfabb7ea02249885e7c276"
#define PlayerEyes_Static_TypeDefinitionIndex 4778

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x14;
	}

	// obf name: ::%96586207b96c12a8440a9ce8967b1acf10599997
#define PlayerBelt_ClassName "%96586207b96c12a8440a9ce8967b1acf10599997"
#define PlayerBelt_ClassNameShort "%96586207b96c12a8440a9ce8967b1acf10599997"
#define PlayerBelt_TypeDefinitionIndex 5899

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x41b3940;
		constexpr const static size_t GetActiveItem = 0x41b55f0;
	}

	// obf name: ::%996d186120d5baffaa0df59e14e07ff9c96f3291
#define LocalPlayer_ClassName "%996d186120d5baffaa0df59e14e07ff9c96f3291"
#define LocalPlayer_ClassNameShort "%996d186120d5baffaa0df59e14e07ff9c96f3291"
#define LocalPlayer_TypeDefinitionIndex 6839

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x4b92680;
		constexpr const static size_t MoveItem = 0x4b8b750;
		constexpr const static size_t get_Entity = 0x4b94b00;
	}

	// obf name: ::%b9911844a69bfbcddd83bb257db816f4ccfe1959
#define LocalPlayer_Static_ClassName "%996d186120d5baffaa0df59e14e07ff9c96f3291/%b9911844a69bfbcddd83bb257db816f4ccfe1959"
#define LocalPlayer_Static_ClassNameShort "%b9911844a69bfbcddd83bb257db816f4ccfe1959"
#define LocalPlayer_Static_TypeDefinitionIndex 6838

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x310;
	}

	// obf name: ::%1e1d2db01320baab1b75f94cd6486d13f791fa65
#define BasePlayer_Static_ClassName "BasePlayer/%1e1d2db01320baab1b75f94cd6486d13f791fa65"
#define BasePlayer_Static_ClassNameShort "%1e1d2db01320baab1b75f94cd6486d13f791fa65"
#define BasePlayer_Static_TypeDefinitionIndex 5769

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x1230;
	}

#define BasePlayer_TypeDefinitionIndex 5770

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x2e0;
		constexpr const static size_t input = 0x360;
		constexpr const static size_t movement = 0x400;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x408;
		constexpr const static size_t playerFlags = 0x598;
		constexpr const static size_t eyes = 0x480;
		constexpr const static size_t playerRigidbody = 0x4b0;
		constexpr const static size_t userID = 0x5e0;
		constexpr const static size_t UserIDString = 0x350;
		constexpr const static size_t inventory = 0x5b8;
		constexpr const static size_t _displayName = 0x6a0;
		constexpr const static size_t _lookingAt = 0x560;
		constexpr const static size_t lastSentTickTime = 0x554;
		constexpr const static size_t lastSentTick = 0x4d8;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x428;
		constexpr const static size_t _lookingAtEntity = 0x308;
		constexpr const static size_t currentGesture = 0x320;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x3ff9c20;
		constexpr const static size_t Menu_AssistPlayer = 0x40552a0;
		constexpr const static size_t OnViewModeChanged = 0x3f4f6c0;
		constexpr const static size_t ChatMessage = 0x40983a0;
		constexpr const static size_t IsOnGround = 0x3f26540;
		constexpr const static size_t GetSpeed = 0x4023df0;
		constexpr const static size_t SendProjectileUpdate = 0x40a2650;
		constexpr const static size_t SendProjectileAttack = 0x3f4eb90;
		constexpr const static size_t CanBuild = 0x40a93c0;
		constexpr const static size_t GetMounted = 0x409ca70;
		constexpr const static size_t GetHeldEntity = 0x3fe4110;
		constexpr const static size_t get_inventory = 0x401a090;
		constexpr const static size_t get_eyes = 0x3fec140;
		constexpr const static size_t SendClientTick = 0x3f2f330;
		constexpr const static size_t ClientInput = 0x3fc1600;
		constexpr const static size_t ClientInput_vtableoff = 0x3b58;
		constexpr const static size_t MaxHealth = 0x3fe05d0;
		constexpr const static size_t MaxHealth_vtableoff = 0x24d8;
		constexpr const static size_t OnAttacked = 0x3f700e0;
		constexpr const static size_t OnAttacked_vtableoff = 0x1a68;
		constexpr const static size_t get_idealViewMode = 0x4044bc0;
	}

#define ScientistNPC_TypeDefinitionIndex 5992

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 7072

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 2892

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 4947

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 6238

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 6879

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 5647

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xd8;
		constexpr const static size_t ladder = 0xe8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x3ddf060;
		constexpr const static size_t BlockSprint = 0x3db76d0;
		constexpr const static size_t GroundCheck = 0x3de4150;
		constexpr const static size_t ClientInput = 0x3de6240;
		constexpr const static size_t ClientInput_vtableoff = 0x258;
		constexpr const static size_t DoFixedUpdate = 0x3db4da0;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x338;
		constexpr const static size_t FrameUpdate = 0x3de66e0;
		constexpr const static size_t FrameUpdate_vtableoff = 0x218;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 112

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 5453

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 2237

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 6439

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
		constexpr const static size_t needsOnForEffects = 0x248;
	}

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 6435

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%986757212214280adb3a62a1a7f802d7bad535ca
#define ConsoleSystem_ClassName "%986757212214280adb3a62a1a7f802d7bad535ca"
#define ConsoleSystem_ClassNameShort "%986757212214280adb3a62a1a7f802d7bad535ca"
#define ConsoleSystem_TypeDefinitionIndex 23346

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x655cc90;
	}

	// obf name: ::%72d1d3cc46b50463372be47329b0a41977981a33
#define ConsoleSystem_Index_Static_ClassName "%986757212214280adb3a62a1a7f802d7bad535ca/%ebf7b422f5cdb1571195e462a53ef14f992beb3a.%72d1d3cc46b50463372be47329b0a41977981a33"
#define ConsoleSystem_Index_Static_ClassNameShort "%72d1d3cc46b50463372be47329b0a41977981a33"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23339

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0xc8;
	}

#define LootableCorpse_TypeDefinitionIndex 4908

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2c8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 705

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 923

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x98;
		constexpr const static size_t mainCameraTransform = 0x50;

		// Functions
		constexpr const static size_t Update = 0x5065630;
		constexpr const static size_t OnPreCull = 0x5068e40;
		constexpr const static size_t Trace = 0x505eac0;
	}

#define CameraMan_TypeDefinitionIndex 6234

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%d354c8280bd35e702496cfae0244f13a123f9b0c
#define PlayerTick_ClassName "%d354c8280bd35e702496cfae0244f13a123f9b0c"
#define PlayerTick_ClassNameShort "%d354c8280bd35e702496cfae0244f13a123f9b0c"
#define PlayerTick_TypeDefinitionIndex 7500

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x20;
		constexpr const static size_t modelState = 0x50;
		constexpr const static size_t activeItem = 0x38;
		constexpr const static size_t parentID = 0x60;
		constexpr const static size_t intermediatePosition = 0x28;
		constexpr const static size_t position = 0x10;
		constexpr const static size_t eyePos = 0x40;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8f37b40;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8f36f20;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%ddb6daf0bde1b444928530b9d5415ce85e6e48dd
#define InputMessage_ClassName "%ddb6daf0bde1b444928530b9d5415ce85e6e48dd"
#define InputMessage_ClassNameShort "%ddb6daf0bde1b444928530b9d5415ce85e6e48dd"
#define InputMessage_TypeDefinitionIndex 7151

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x14;
		constexpr const static size_t aimAngles = 0x18;
		constexpr const static size_t mouseDelta = 0x24;
	}

	// obf name: ::%f0fe4e7b40690dbdf5f66fb47f2ac2a2fbe33da7
#define InputState_ClassName "%f0fe4e7b40690dbdf5f66fb47f2ac2a2fbe33da7"
#define InputState_ClassNameShort "%f0fe4e7b40690dbdf5f66fb47f2ac2a2fbe33da7"
#define InputState_TypeDefinitionIndex 3094

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x20;
		constexpr const static size_t previous = 0x18;
	}

#define PlayerInput_TypeDefinitionIndex 1591

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%8068da256a8caaa1a6268f571ce413e28917dc57
#define ModelState_ClassName "%8068da256a8caaa1a6268f571ce413e28917dc57"
#define ModelState_ClassNameShort "%8068da256a8caaa1a6268f571ce413e28917dc57"
#define ModelState_TypeDefinitionIndex 7553

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x34;
		constexpr const static size_t waterLevel = 0x4c;
		constexpr const static size_t lookDir = 0x28;
	}

	// obf name: ::%f08f10fdcb532d6d37045aba3c491d5185ec7e04
#define Item_ClassName "%f08f10fdcb532d6d37045aba3c491d5185ec7e04"
#define Item_ClassNameShort "%f08f10fdcb532d6d37045aba3c491d5185ec7e04"
#define Item_TypeDefinitionIndex 3940

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x98;
		constexpr const static size_t uid = 0xc8;
		constexpr const static size_t _maxCondition = 0x28;
		constexpr const static size_t _condition = 0x74;
		constexpr const static size_t position = 0x18;
		constexpr const static size_t amount = 0xb0;
		constexpr const static size_t contents = 0xd0;
		constexpr const static size_t parent = 0xe0;
		constexpr const static size_t worldEnt = 0x40;
		constexpr const static size_t heldEntity = 0x50;

		// Functions
		constexpr const static size_t get_iconSprite = 0x2acaf30;
	}

	// obf name: ::%1c3222876f0127f1372ecfedfc78393b62f14889
#define WaterLevel_ClassName "%1c3222876f0127f1372ecfedfc78393b62f14889"
#define WaterLevel_ClassNameShort "%1c3222876f0127f1372ecfedfc78393b62f14889"
#define WaterLevel_TypeDefinitionIndex 5048

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x36d4630;
		constexpr const static size_t GetWaterLevel = 0x36f3b60;
	}

	// obf name: ::%62c56dffe30f7aca14cde47d3004ed66ccf980b6
#define ConVar_Graphics_Static_ClassName "%72fa929fa07314f9cb22560cc4de1ab882b70674/%62c56dffe30f7aca14cde47d3004ed66ccf980b6"
#define ConVar_Graphics_Static_ClassNameShort "%62c56dffe30f7aca14cde47d3004ed66ccf980b6"
#define ConVar_Graphics_Static_TypeDefinitionIndex 185

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x54;

		// Functions
		constexpr const static size_t _fov_getter = 0x17d6600;
		constexpr const static size_t _fov_setter = 0x1810360;
	}

#define BaseFishingRod_TypeDefinitionIndex 7027

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x260;
		constexpr const static size_t currentBobber = 0x268;
		constexpr const static size_t MaxCastDistance = 0x284;
		constexpr const static size_t BobberPreview = 0x290;
		constexpr const static size_t clientStrainAmountNormalised = 0x2d0;
		constexpr const static size_t strainGainMod = 0x2c8;
		constexpr const static size_t aimAnimationReady = 0x2e8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x4d38a70;
		constexpr const static size_t EvaluateFishingPosition = 0x4d3da30;
	}

#define FishingBobber_TypeDefinitionIndex 2795

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 3538

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x2674e90;
	}

	// obf name: ::%c55ae2f5aec8a87d0e15c5a726db839f60389d24
#define GameManager_ClassName "%c55ae2f5aec8a87d0e15c5a726db839f60389d24"
#define GameManager_ClassNameShort "%c55ae2f5aec8a87d0e15c5a726db839f60389d24"
#define GameManager_TypeDefinitionIndex 5283

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x20;

		// Functions
		constexpr const static size_t CreatePrefab = 0x39d8020;
	}

	// obf name: ::%f6c44088d9d9187ba8393f01743e26ce402c9424
#define GameManager_Static_ClassName "%c55ae2f5aec8a87d0e15c5a726db839f60389d24/%f6c44088d9d9187ba8393f01743e26ce402c9424"
#define GameManager_Static_ClassNameShort "%f6c44088d9d9187ba8393f01743e26ce402c9424"
#define GameManager_Static_TypeDefinitionIndex 5282

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x10;
	}

	// obf name: ::%967b9d3ab37bb64423884b51c8ea6fb17f67313d
#define PrefabPoolCollection_ClassName "%967b9d3ab37bb64423884b51c8ea6fb17f67313d"
#define PrefabPoolCollection_ClassNameShort "%967b9d3ab37bb64423884b51c8ea6fb17f67313d"
#define PrefabPoolCollection_TypeDefinitionIndex 501

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%a80bea2ab906d71b5350d4686f2ab65e73eebfcd
#define PrefabPool_ClassName "%a80bea2ab906d71b5350d4686f2ab65e73eebfcd"
#define PrefabPool_ClassNameShort "%a80bea2ab906d71b5350d4686f2ab65e73eebfcd"
#define PrefabPool_TypeDefinitionIndex 281

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x28;
	}

#define ItemModProjectile_TypeDefinitionIndex 6547

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

#define CraftingQueue_TypeDefinitionIndex 1724

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%ce802b31edcd9a5f55530bbbacc25b8464890190
#define CraftingQueue_Static_ClassName "CraftingQueue/%ce802b31edcd9a5f55530bbbacc25b8464890190"
#define CraftingQueue_Static_ClassNameShort "%ce802b31edcd9a5f55530bbbacc25b8464890190"
#define CraftingQueue_Static_TypeDefinitionIndex 1723

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x10;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 5941

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%d594c2cab76b8cd9afec1e3b595c218932fae89c
#define Planner_Static_ClassName "Planner/%d594c2cab76b8cd9afec1e3b595c218932fae89c"
#define Planner_Static_ClassNameShort "%d594c2cab76b8cd9afec1e3b595c218932fae89c"
#define Planner_Static_TypeDefinitionIndex 7092

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0xe8;
	}

	// obf name: ::%04c8863bbd25b378a6ffaa5d5319bcaadd293848
#define Planner_Guide_ClassName "Planner/%04c8863bbd25b378a6ffaa5d5319bcaadd293848"
#define Planner_Guide_ClassNameShort "%04c8863bbd25b378a6ffaa5d5319bcaadd293848"
#define Planner_Guide_TypeDefinitionIndex 7088

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x80;
	}

#define Planner_TypeDefinitionIndex 7093

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x270;
	}

#define Construction_TypeDefinitionIndex 5264

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x130;
	}

#define BuildingBlock_TypeDefinitionIndex 3302

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2b8;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 3425

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x2556ad0;
	}

	// obf name: ::%f37b1220bbbd0b321e60cebf2eaabe2aaa233401
#define PunchEntry_ClassName "HeldEntity/%f37b1220bbbd0b321e60cebf2eaabe2aaa233401"
#define PunchEntry_ClassNameShort "%f37b1220bbbd0b321e60cebf2eaabe2aaa233401"
#define PunchEntry_TypeDefinitionIndex 3423

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x10;
		constexpr const static size_t duration = 0x20;
		constexpr const static size_t amountAdded = 0x14;
		constexpr const static size_t amount = 0x24;
	}

#define IronSights_TypeDefinitionIndex 6270

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 5776

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 5395

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xc0;
		constexpr const static size_t model = 0xa8;
		constexpr const static size_t lower = 0xb8;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x3b237b0;
	}

#define ViewModel_TypeDefinitionIndex 962

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x50bdb50;
		constexpr const static size_t PlayString = 0x50bec60;
	}

#define MedicalTool_TypeDefinitionIndex 621

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 933

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x60;
	}

	// obf name: ::%44508f0850eb716dd1301ad2a5140efe20dad968
#define WaterSystem_Static_ClassName "WaterSystem/%44508f0850eb716dd1301ad2a5140efe20dad968"
#define WaterSystem_Static_ClassNameShort "%44508f0850eb716dd1301ad2a5140efe20dad968"
#define WaterSystem_Static_TypeDefinitionIndex 4182

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x228;
	}

#define WaterSystem_TypeDefinitionIndex 4183

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x2d39040;
	}

#define TerrainMeta_TypeDefinitionIndex 4330

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x3f0;
		constexpr const static size_t HeightMap = 0x4d8;
		constexpr const static size_t SplatMap = 0x60;
		constexpr const static size_t TopologyMap = 0xf0;
		constexpr const static size_t Texturing = 0x4b0;
	}

#define TerrainCollision_TypeDefinitionIndex 6406

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x46fb990;
	}

#define TerrainHeightMap_TypeDefinitionIndex 6625

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 2445

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 1489

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%f628b4568a0f986b9c9dea11b64547ade757e55c
#define World_Static_ClassName "%3aa3e0512c385e1db56aa1b9a385e690abd4389e/%f628b4568a0f986b9c9dea11b64547ade757e55c"
#define World_Static_ClassNameShort "%f628b4568a0f986b9c9dea11b64547ade757e55c"
#define World_Static_TypeDefinitionIndex 2827

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x220;
	}

#define ItemIcon_TypeDefinitionIndex 6931

	namespace ItemIcon {

		// Functions
		constexpr const static size_t TryToMove = 0x4c35ad0;
		constexpr const static size_t TryToMove_vtableoff = 0x448;
		constexpr const static size_t RunTimedAction = 0x4c2ba10;
	}

	// obf name: ::%ced887d611dc4aba4cabedcc1e8127965b6d278b
#define ItemIcon_Static_ClassName "ItemIcon/%ced887d611dc4aba4cabedcc1e8127965b6d278b"
#define ItemIcon_Static_ClassNameShort "%ced887d611dc4aba4cabedcc1e8127965b6d278b"
#define ItemIcon_Static_TypeDefinitionIndex 6930

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x30;
	}

	// obf name: ::%f809138ed8ce06d1995d2799933002cd43d17769
#define Effect_ClassName "%f809138ed8ce06d1995d2799933002cd43d17769"
#define Effect_ClassNameShort "%f809138ed8ce06d1995d2799933002cd43d17769"
#define Effect_TypeDefinitionIndex 1800

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x88;
		constexpr const static size_t worldPos = 0x70;
	}

	// obf name: ::%31a6e5460b171299d1ba334630486a6c4bc9859c
#define EffectLibrary_ClassName "%31a6e5460b171299d1ba334630486a6c4bc9859c"
#define EffectLibrary_ClassNameShort "%31a6e5460b171299d1ba334630486a6c4bc9859c"
#define EffectLibrary_TypeDefinitionIndex 942

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x5094870;
	}

	// obf name: ::%97449f55cbbb48d1de300699931d551bb8762f0c
#define EffectNetwork_ClassName "%97449f55cbbb48d1de300699931d551bb8762f0c"
#define EffectNetwork_ClassNameShort "%97449f55cbbb48d1de300699931d551bb8762f0c"
#define EffectNetwork_TypeDefinitionIndex 1404

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%0977d1d5723a6ce36a762241a4d5ab7bdab92fa8
#define EffectNetwork_Static_ClassName "%97449f55cbbb48d1de300699931d551bb8762f0c/%0977d1d5723a6ce36a762241a4d5ab7bdab92fa8"
#define EffectNetwork_Static_ClassNameShort "%0977d1d5723a6ce36a762241a4d5ab7bdab92fa8"
#define EffectNetwork_Static_TypeDefinitionIndex 1403

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x8;

		// Functions
		constexpr const static size_t cctor = 0x55c2ca0;
	}

#define BuildingBlock_TypeDefinitionIndex 3302

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x23e5db0;
		constexpr const static size_t HasUpgradePrivilege = 0x23c7ba0;
		constexpr const static size_t CanAffordUpgrade = 0x23d2110;
	}

	// obf name: ::%2f6cba595b4548aeb452c9848f7e707d56732110
#define GameObjectEx_ClassName "%2f6cba595b4548aeb452c9848f7e707d56732110"
#define GameObjectEx_ClassNameShort "%2f6cba595b4548aeb452c9848f7e707d56732110"
#define GameObjectEx_TypeDefinitionIndex 3479

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x25c65c0;
	}

#define UIDeathScreen_TypeDefinitionIndex 3322

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x2430830;
	}

	// obf name: ::%415f137e0dd7d21a6b72d841427a8091823f48de
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%415f137e0dd7d21a6b72d841427a8091823f48de"
#define BaseScreenShake_Static_ClassNameShort "%415f137e0dd7d21a6b72d841427a8091823f48de"
#define BaseScreenShake_Static_TypeDefinitionIndex 583

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x18;
	}

#define FlashbangOverlay_TypeDefinitionIndex 2881

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x10;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%705f287fd644f840d15f6b142ca32a9f7ed7d21e
#define StringPool_ClassName "%705f287fd644f840d15f6b142ca32a9f7ed7d21e"
#define StringPool_ClassNameShort "%705f287fd644f840d15f6b142ca32a9f7ed7d21e"
#define StringPool_TypeDefinitionIndex 3246

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x0;

		// Functions
		constexpr const static size_t Get = 0x2385fd0;
	}

	// obf name: ::%12d5147dddca515d611c3ccdc426b42cc827d1fb
#define Network_Networkable_ClassName "%12d5147dddca515d611c3ccdc426b42cc827d1fb"
#define Network_Networkable_ClassNameShort "%12d5147dddca515d611c3ccdc426b42cc827d1fb"
#define Network_Networkable_TypeDefinitionIndex 19165

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x18;
	}

	// obf name: ::%911e080a0df461f2fa20922defdaa2abdbaca656
#define Network_Net_ClassName "%911e080a0df461f2fa20922defdaa2abdbaca656"
#define Network_Net_ClassNameShort "%911e080a0df461f2fa20922defdaa2abdbaca656"
#define Network_Net_TypeDefinitionIndex 9670

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x38;
	}

	// obf name: ::%261ec8dae17a75e729991c1c623af2755a3695a9
#define Network_Client_ClassName "%261ec8dae17a75e729991c1c623af2755a3695a9"
#define Network_Client_ClassNameShort "%261ec8dae17a75e729991c1c623af2755a3695a9"
#define Network_Client_TypeDefinitionIndex 19175

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xe0;
		constexpr const static size_t ConnectedPort = 0xd8;
		constexpr const static size_t ServerName = 0xf0;
		constexpr const static size_t ConnectedAddress = 0x108;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x6638d60;
		constexpr const static size_t DestroyNetworkable = 0x6638bf0;
	}

	// obf name: ::%405a178ce7b7306032aaf3c43a6ed433eeb93b97
#define Network_BaseNetwork_ClassName "%405a178ce7b7306032aaf3c43a6ed433eeb93b97"
#define Network_BaseNetwork_ClassNameShort "%405a178ce7b7306032aaf3c43a6ed433eeb93b97"
#define Network_BaseNetwork_TypeDefinitionIndex 19148

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x6607700;
	}

	// obf name: ::%19b47569818acb68080153f044c0d0e5c67b3d7f
#define Network_SendInfo_ClassName "%19b47569818acb68080153f044c0d0e5c67b3d7f"
#define Network_SendInfo_ClassNameShort "%19b47569818acb68080153f044c0d0e5c67b3d7f"
#define Network_SendInfo_TypeDefinitionIndex 19142

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%9025b2dceac0b45236d01f23de377d782f54b2e5
#define Network_Message_ClassName "%9025b2dceac0b45236d01f23de377d782f54b2e5"
#define Network_Message_ClassNameShort "%9025b2dceac0b45236d01f23de377d782f54b2e5"
#define Network_Message_TypeDefinitionIndex 19169

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x20;
		constexpr const static size_t read = 0x18;
	}

	// obf name: ::%e57c36bf20206eace8093cfd3365fac32f2208a7
#define Network_NetRead_ClassName "%e57c36bf20206eace8093cfd3365fac32f2208a7"
#define Network_NetRead_ClassNameShort "%e57c36bf20206eace8093cfd3365fac32f2208a7"
#define Network_NetRead_TypeDefinitionIndex 19154

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x38;
	}

	// obf name: ::%54e5240d9471825c06a3d81285a60af42ab52fee
#define Network_NetWrite_ClassName "%54e5240d9471825c06a3d81285a60af42ab52fee"
#define Network_NetWrite_ClassNameShort "%54e5240d9471825c06a3d81285a60af42ab52fee"
#define Network_NetWrite_TypeDefinitionIndex 19140

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x40;

		// Functions
		constexpr const static size_t WriteByte = 0x65f1f80;
		constexpr const static size_t String = 0x65f2c40;
		constexpr const static size_t Send = 0x65f1a20;
	}

#define LootPanel_TypeDefinitionIndex 7029

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x4d5e8c0;
	}

#define UIInventory_TypeDefinitionIndex 4156

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x2cfabe0;
	}

#define GrowableEntity_TypeDefinitionIndex 3934

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 252

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 251

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 20996

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 7744

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
		constexpr const static size_t get_Instance = 0xb71e80;
	}

	// obf name: ::%4554e1be573b7fecfda7ba05561be00c7ad5780e
#define TOD_Sky_Static_ClassName "TOD_Sky/%4554e1be573b7fecfda7ba05561be00c7ad5780e"
#define TOD_Sky_Static_ClassNameShort "%4554e1be573b7fecfda7ba05561be00c7ad5780e"
#define TOD_Sky_Static_TypeDefinitionIndex 7743

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x40;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 9647

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xdfbcb0;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 8698

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9233

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 7770

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 8298

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 8263

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 9607

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 4846

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 5063

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 1241

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 4244

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

#define EnvironmentManager_TypeDefinitionIndex 3957

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x2af0750;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%d42decd73a979beba5e6c04a7b91a6d11163410b/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24092

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 1261

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 1262

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 2163

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
		constexpr const static size_t InstanceList = 0x28;
	}

	// obf name: ::%0d6c1e6aff81a09766edc1c0e054df1d39b08207
#define ListHashSet_ClassName "%0d6c1e6aff81a09766edc1c0e054df1d39b08207<UIChat>"
#define ListHashSet_ClassNameShort "%0d6c1e6aff81a09766edc1c0e054df1d39b08207"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 2369

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3f0;
	}

#define Chainsaw_TypeDefinitionIndex 4247

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%dd616c88cdb1a68d242a41ce64a33759fc76f015
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%dd616c88cdb1a68d242a41ce64a33759fc76f015"
#define CameraUpdateHook_Static_ClassNameShort "%dd616c88cdb1a68d242a41ce64a33759fc76f015"
#define CameraUpdateHook_Static_TypeDefinitionIndex 2593

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0xc8;
	}

#define SteamClientWrapper_TypeDefinitionIndex 3791

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x28ff130;
	}

	// obf name: ::%a9b222f0dffa0a58268bd21e7d63dafd919aee80
#define AimConeUtil_ClassName "%a9b222f0dffa0a58268bd21e7d63dafd919aee80"
#define AimConeUtil_ClassNameShort "%a9b222f0dffa0a58268bd21e7d63dafd919aee80"
#define AimConeUtil_TypeDefinitionIndex 5330

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x3a63be0;
	}

	// obf name: ::%75677b26eca214f4b6436c2c2a655e096240f178
#define Buttons_ConButton_ClassName "%9710038f63f362674dbf05d9c62b8b9449cbc2b8/%75677b26eca214f4b6436c2c2a655e096240f178"
#define Buttons_ConButton_ClassNameShort "%75677b26eca214f4b6436c2c2a655e096240f178"
#define Buttons_ConButton_TypeDefinitionIndex 5974

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%ed8cc9b8ec36fa4938121104ea2aa9cea414861d
#define Buttons_Static_ClassName "%9710038f63f362674dbf05d9c62b8b9449cbc2b8/%ed8cc9b8ec36fa4938121104ea2aa9cea414861d"
#define Buttons_Static_ClassNameShort "%ed8cc9b8ec36fa4938121104ea2aa9cea414861d"
#define Buttons_Static_TypeDefinitionIndex 5975

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0xc58;
		constexpr const static size_t Attack = 0x28;
		constexpr const static size_t Attack2 = 0x690;
		constexpr const static size_t Forward = 0x870;
		constexpr const static size_t Backward = 0x30;
		constexpr const static size_t Right = 0x80;
		constexpr const static size_t Left = 0xfa0;
		constexpr const static size_t Sprint = 0x3d8;
		constexpr const static size_t Use = 0xf50;

		// Functions
		constexpr const static size_t Pets_setter = 0x17d3470;
	}

#define PlayerModel_TypeDefinitionIndex 1377

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x298;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 1808

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 549

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 5519

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t timeCounter = 0x2c;
	}

#define BowWeapon_TypeDefinitionIndex 821

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x408;
		constexpr const static size_t wasAiming = 0x418;
	}

#define CrossbowWeapon_TypeDefinitionIndex 3066

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 6141

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%7f68b0e3eebac70243ffcb31ac0ae77582b6390d
#define ConVar_Admin_Static_ClassName "%7eaba44e940ea34c14b81c5dcf937fd336756a1d/%7f68b0e3eebac70243ffcb31ac0ae77582b6390d"
#define ConVar_Admin_Static_ClassNameShort "%7f68b0e3eebac70243ffcb31ac0ae77582b6390d"
#define ConVar_Admin_Static_TypeDefinitionIndex 4254

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x94;

		// Functions
		constexpr const static size_t admintime_getter = 0x17f5ef0;
		constexpr const static size_t admintime_setter = 0x17fe640;
	}

	// obf name: ::%1aa6b79638ce107798ceebb6f1028d44b5f8f547
#define ConVar_Player_Static_ClassName "%3323a28af2e1c9ca5fa7cfeaedd9ad918dc56924/%1aa6b79638ce107798ceebb6f1028d44b5f8f547"
#define ConVar_Player_Static_ClassNameShort "%1aa6b79638ce107798ceebb6f1028d44b5f8f547"
#define ConVar_Player_Static_TypeDefinitionIndex 4780

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0xcc;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x17dfa80;
		constexpr const static size_t clientTickRate_setter = 0x17f7dd0;
	}

#define ColliderInfo_TypeDefinitionIndex 6169

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 4785

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 6594

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x370;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x4932930;
	}

#define Client_TypeDefinitionIndex 5989

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x42a7010;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%8e7ff3691dafc3ab5f426a14632e6d8f2091c5e6
#define ItemManager_Static_ClassName "%82a119ab3f15f4e109c8c51fde3fb4f2fc1e2e79/%8e7ff3691dafc3ab5f426a14632e6d8f2091c5e6"
#define ItemManager_Static_ClassNameShort "%8e7ff3691dafc3ab5f426a14632e6d8f2091c5e6"
#define ItemManager_Static_TypeDefinitionIndex 5012

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x120;
		constexpr const static size_t itemDictionary = 0x60;
		constexpr const static size_t itemDictionaryByName = 0x1e8;
	}

	// obf name: ::%67325f73f62aa73090aa8444181a59fa15953957
#define ConVar_Server_Static_ClassName "%42273b56a5596f0dafe7faa7373a3663994ef6f5/%67325f73f62aa73090aa8444181a59fa15953957"
#define ConVar_Server_Static_ClassNameShort "%67325f73f62aa73090aa8444181a59fa15953957"
#define ConVar_Server_Static_TypeDefinitionIndex 4822

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 4951

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x35d9ca0;
	}

#define LoadingScreen_TypeDefinitionIndex 1127

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 3567

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%26b3d413a20427776351b1156dd6f3493e94cdab"
#define MapView_Static_ClassNameShort "%26b3d413a20427776351b1156dd6f3493e94cdab"
#define MapView_TypeDefinitionIndex 5291

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x39b39d0;
	}

	// obf name: ::%f1634a8ddc23cc651f093aacf3aadf52841e78cc
#define GamePhysics_Static_ClassName "%e6bc3d7d073e0e265f73bccc32210691258038d8/%f1634a8ddc23cc651f093aacf3aadf52841e78cc"
#define GamePhysics_Static_ClassNameShort "%f1634a8ddc23cc651f093aacf3aadf52841e78cc"
#define GamePhysics_Static_TypeDefinitionIndex 2137

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x18;
	}

	// obf name: ::%e6bc3d7d073e0e265f73bccc32210691258038d8
#define GamePhysics_ClassName "%e6bc3d7d073e0e265f73bccc32210691258038d8"
#define GamePhysics_ClassNameShort "%e6bc3d7d073e0e265f73bccc32210691258038d8"
#define GamePhysics_TypeDefinitionIndex 2138

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x1584d60;
		constexpr const static size_t LineOfSightInternal = 0x158e630;
		constexpr const static size_t Verify = 0x158af60;
	}

#define DDraw_TypeDefinitionIndex 1355

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x54aa020;
		constexpr const static size_t Line = 0x54a1c00;
	}

	// obf name: ::%d6c65cfb500f59d82de544261a99dad4da7084e0
#define RaycastHitEx_ClassName "%d6c65cfb500f59d82de544261a99dad4da7084e0"
#define RaycastHitEx_ClassNameShort "%d6c65cfb500f59d82de544261a99dad4da7084e0"
#define RaycastHitEx_TypeDefinitionIndex 788

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x4ee8f60;
	}

	// obf name: ::%66e49d8b704d18ff68f5dc3d2785afae2afc9923
#define OnParentDestroyingEx_ClassName "%66e49d8b704d18ff68f5dc3d2785afae2afc9923"
#define OnParentDestroyingEx_ClassNameShort "%66e49d8b704d18ff68f5dc3d2785afae2afc9923"
#define OnParentDestroyingEx_TypeDefinitionIndex 2296

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x1793180;
	}

	// obf name: ::%acb9e440ba2404262623e336b123a8f33d465006
#define ConsoleNetwork_ClassName "%acb9e440ba2404262623e336b123a8f33d465006"
#define ConsoleNetwork_ClassNameShort "%acb9e440ba2404262623e336b123a8f33d465006"
#define ConsoleNetwork_TypeDefinitionIndex 3941

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x2adf250;
	}

#define ThrownWeapon_TypeDefinitionIndex 848

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 2465

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 3080

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 5291

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 86

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 2987

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 6412

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 4533

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 1900

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 3183

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%f47ec9fac2bd9e616c2c5fa7a697e1dd5dc6d382
#define ConVar_Client_Static_ClassName "%228ca8bcfbcf42356b22eb5741294ca847d26cc2/%f47ec9fac2bd9e616c2c5fa7a697e1dd5dc6d382"
#define ConVar_Client_Static_ClassNameShort "%f47ec9fac2bd9e616c2c5fa7a697e1dd5dc6d382"
#define ConVar_Client_Static_TypeDefinitionIndex 3596

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x740;
		constexpr const static size_t camspeed = 0x654;
	}

#define SamSite_TypeDefinitionIndex 4974

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 3859

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 2010

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 2437

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 4740

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 692

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 71

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 6249

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%516a0e46e9aa632b781f05fe2de734f1d0510f41
#define Facepunch_Network_Raknet_Client_ClassName "%516a0e46e9aa632b781f05fe2de734f1d0510f41"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%516a0e46e9aa632b781f05fe2de734f1d0510f41"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 22799

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x6689c50;
		constexpr const static size_t IsConnected_vtableoff = 0x278;
	}

	// obf name: ::%5950ded95f0b76d436a177cd1152232093eb3f5f
#define EncryptedValue_ClassName "%5950ded95f0b76d436a177cd1152232093eb3f5f<System/Int32>"
#define EncryptedValue_ClassNameShort "%5950ded95f0b76d436a177cd1152232093eb3f5f"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%9c7088e108ad59001a49bda737532a441f2cddd8
#define HiddenValue_ClassName "%9c7088e108ad59001a49bda737532a441f2cddd8<BaseNetworkable/%63fcb16c26f67f4df901ee108183bb9e4960b3c0>"
#define HiddenValue_ClassNameShort "%9c7088e108ad59001a49bda737532a441f2cddd8"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x20;
		constexpr const static size_t _hasValue = 0x10;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 2735

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x1dfeab0;
	}

#define ItemModRFListener_TypeDefinitionIndex 3346

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x24989e0;
	}

#define UIFogOverlay_TypeDefinitionIndex 2010

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x28;
	}

	// obf name: ::%f3ecea47c775c4c3f163e85e257ffbfa09f10579
#define BufferStream_ClassName "%f3ecea47c775c4c3f163e85e257ffbfa09f10579"
#define BufferStream_ClassNameShort "%f3ecea47c775c4c3f163e85e257ffbfa09f10579"
#define BufferStream_TypeDefinitionIndex 7392

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x8b5ffa0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 441

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 1024

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 5736

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x3ef19f0;
	}

#define OutlineManager_TypeDefinitionIndex 6526

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%483a8b36a76bff40a2c10c0a703d53d2799ffd88
#define ConsoleSystem_Command_ClassName "%986757212214280adb3a62a1a7f802d7bad535ca/%483a8b36a76bff40a2c10c0a703d53d2799ffd88"
#define ConsoleSystem_Command_ClassNameShort "%483a8b36a76bff40a2c10c0a703d53d2799ffd88"
#define ConsoleSystem_Command_TypeDefinitionIndex 23331

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x80;
		constexpr const static size_t SetOveride = 0x48;
		constexpr const static size_t Call = 0x10;
	}

	// obf name: ::%48c093b2eac69a2003168a1d0f83ef996d34e522
#define ConsoleSystem_Option_ClassName "%986757212214280adb3a62a1a7f802d7bad535ca/%48c093b2eac69a2003168a1d0f83ef996d34e522"
#define ConsoleSystem_Option_ClassNameShort "%48c093b2eac69a2003168a1d0f83ef996d34e522"
#define ConsoleSystem_Option_TypeDefinitionIndex 23341

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%274936256d9aaf6728cbf41bf319daf622ae7e1c
#define ConsoleSystem_Arg_ClassName "%986757212214280adb3a62a1a7f802d7bad535ca/%274936256d9aaf6728cbf41bf319daf622ae7e1c"
#define ConsoleSystem_Arg_ClassNameShort "%274936256d9aaf6728cbf41bf319daf622ae7e1c"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23329

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x28;
	}

	// obf name: ::%0d431f450e58d60786f358d97891cd74f0cdc176
#define ConsoleSystem_Index_Client_ClassName "%986757212214280adb3a62a1a7f802d7bad535ca/%ebf7b422f5cdb1571195e462a53ef14f992beb3a.%0d431f450e58d60786f358d97891cd74f0cdc176"
#define ConsoleSystem_Index_Client_ClassNameShort "%0d431f450e58d60786f358d97891cd74f0cdc176"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23337

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x6561850;
	}

#define String_TypeDefinitionIndex 10203

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x8737830;
	}

	// obf name: ::%c3bd32572d2fae84caee003d98a4cf36e40ae143
#define EntityRef_ClassName "%c3bd32572d2fae84caee003d98a4cf36e40ae143"
#define EntityRef_ClassNameShort "%c3bd32572d2fae84caee003d98a4cf36e40ae143"
#define EntityRef_TypeDefinitionIndex 4188

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x2db5070;
	}

	// obf name: ::%4f1b766c02fc7e5db55b06c2b7e6f521c64f288a
#define ProtoBuf_ProjectileShoot_ClassName "%4f1b766c02fc7e5db55b06c2b7e6f521c64f288a"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%4f1b766c02fc7e5db55b06c2b7e6f521c64f288a"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7475

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x10;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8e3bb10;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8e3f8b0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%5e7fb1c7fc8c09f7113ae77d9a12818476f04475
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%4f1b766c02fc7e5db55b06c2b7e6f521c64f288a/%5e7fb1c7fc8c09f7113ae77d9a12818476f04475"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%5e7fb1c7fc8c09f7113ae77d9a12818476f04475"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7474

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x2c;
		constexpr const static size_t startPos = 0x10;
		constexpr const static size_t startVel = 0x1c;
		constexpr const static size_t seed = 0x30;
	}

	// obf name: ::%ad6ca8a4741098f3d2bea9d59cafa0b122812f34
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%ad6ca8a4741098f3d2bea9d59cafa0b122812f34"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%ad6ca8a4741098f3d2bea9d59cafa0b122812f34"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7250

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x28;
		constexpr const static size_t curPosition = 0x2c;
		constexpr const static size_t curVelocity = 0x14;
		constexpr const static size_t travelTime = 0x20;
		constexpr const static size_t ShouldPool = 0x24;

		// Functions
		constexpr const static size_t Dispose = 0x95bc900;
		constexpr const static size_t WriteToStreamDelta = 0x95bd3c0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x95b7ee0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%b6ee24167f785e0c5ed2ccada21144a80c1383c8
#define ProtoBuf_PlayerProjectileAttack_ClassName "%b6ee24167f785e0c5ed2ccada21144a80c1383c8"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%b6ee24167f785e0c5ed2ccada21144a80c1383c8"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7166

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x18;
		constexpr const static size_t hitDistance = 0x10;
		constexpr const static size_t travelTime = 0x28;
		constexpr const static size_t playerAttack = 0x30;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x97370a0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x97387c0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%7dd9890a0961ea35a5e8dd2de4682eeb8fa3ff92
#define ProtoBuf_PlayerAttack_ClassName "%7dd9890a0961ea35a5e8dd2de4682eeb8fa3ff92"
#define ProtoBuf_PlayerAttack_ClassNameShort "%7dd9890a0961ea35a5e8dd2de4682eeb8fa3ff92"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7194

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%97ba427289366c471afa1e9142e19ad0caa264b5
#define ProtoBuf_Attack_ClassName "%97ba427289366c471afa1e9142e19ad0caa264b5"
#define ProtoBuf_Attack_ClassNameShort "%97ba427289366c471afa1e9142e19ad0caa264b5"
#define ProtoBuf_Attack_TypeDefinitionIndex 7376

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x18;
		constexpr const static size_t pointEnd = 0x78;
		constexpr const static size_t hitID = 0x50;
		constexpr const static size_t hitBone = 0x10;
		constexpr const static size_t hitNormalLocal = 0x6c;
		constexpr const static size_t hitPositionLocal = 0x60;
		constexpr const static size_t hitNormalWorld = 0x30;
		constexpr const static size_t hitPositionWorld = 0x3c;
		constexpr const static size_t hitPartID = 0x84;
		constexpr const static size_t hitMaterialID = 0x4c;
		constexpr const static size_t srcParentID = 0x28;
		constexpr const static size_t dstParentID = 0x58;
	}
}