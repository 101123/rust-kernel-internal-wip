#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68df8b6d;
		constexpr const static size_t gc_handles = 0xd85cd40;
		constexpr const static size_t il2cpp_resolve_icall = 0x7b7810;
		constexpr const static size_t il2cpp_array_new = 0x7b7830;
		constexpr const static size_t il2cpp_assembly_get_image = 0x4e4a0;
		constexpr const static size_t il2cpp_class_from_name = 0x7b79a0;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x7b7cb0;
		constexpr const static size_t il2cpp_class_get_type = 0x7b7d50;
		constexpr const static size_t il2cpp_domain_get = 0x7b82b0;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x7b82d0;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x7b8b90;
		constexpr const static size_t il2cpp_gchandle_new = 0x7b8b40;
		constexpr const static size_t il2cpp_gchandle_free = 0x7b8c30;
		constexpr const static size_t il2cpp_method_get_name = 0x8260;
		constexpr const static size_t il2cpp_object_new = 0x7b92e0;
		constexpr const static size_t il2cpp_type_get_object = 0x7b9ad0;
	}

#define Object_TypeDefinitionIndex 16757

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xb127ae0;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16728

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

#define Component_TypeDefinitionIndex 16715

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16709

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 16792

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xb1334a0;
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

#define Camera_TypeDefinitionIndex 16507

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16779

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

#define Material_TypeDefinitionIndex 16570

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16566

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xb0e7520;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16569

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xb0eace0;
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16625

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

#define Renderer_TypeDefinitionIndex 16567

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16628

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16630

	namespace Texture2D {
		constexpr const static size_t ctor = 0xb100f20;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define RenderTexture_TypeDefinitionIndex 16635

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xb109bd0;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17105

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb14dba0;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17081

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xb1479c0;
	}

#define ComputeBuffer_TypeDefinitionIndex 16770

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb12b660;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xb12b8b0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16574

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb0f1d60;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xb0f1ac0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 21883

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xb170400;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16547

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16658

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24468

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16544

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24346

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

#define Application_TypeDefinitionIndex 16490

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16656

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23303

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xb1b61e0;
		constexpr const static size_t RaycastNonAlloc = 0xb1b88b0;
	}

#define BaseNetworkable_TypeDefinitionIndex 1570

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x28;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x50;
	}

	// obf name: ::%8b07c762e7d2101cb06ab154fcd0058d4f20a392
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%8b07c762e7d2101cb06ab154fcd0058d4f20a392"
#define BaseNetworkable_Static_ClassNameShort "%8b07c762e7d2101cb06ab154fcd0058d4f20a392"
#define BaseNetworkable_Static_TypeDefinitionIndex 1569

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x8;
	}

	// obf name: ::%de5e04a9dade5aa6cd67b83af102cb57c9335946
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%de5e04a9dade5aa6cd67b83af102cb57c9335946"
#define BaseNetworkable_EntityRealm_ClassNameShort "%de5e04a9dade5aa6cd67b83af102cb57c9335946"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 1567

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x10c6940;
	}

	// obf name: ::%4771a879f5a17554180d1640278dea611d422864
#define System_ListDictionary_ClassName "%4771a879f5a17554180d1640278dea611d422864<%b5722172903d9feec45d2a73492736c64037d4d8,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%4771a879f5a17554180d1640278dea611d422864"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x6f239d0;
		constexpr const static size_t TryGetValue_methodinfo = 0xd501b08;
	}

	// obf name: ::%60a0a37849134a71cca25353ca8aeeeba2b64a6f
#define System_BufferList_ClassName "%60a0a37849134a71cca25353ca8aeeeba2b64a6f<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%60a0a37849134a71cca25353ca8aeeeba2b64a6f"
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

#define Model_TypeDefinitionIndex 1395

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 1031

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0x118;
		constexpr const static size_t positionLerp = 0x170;

		// Functions
		constexpr const static size_t ServerRPC = 0x5184160;
		constexpr const static size_t FindBone = 0x513de60;
		constexpr const static size_t GetWorldVelocity = 0x516beb0;
		constexpr const static size_t GetParentVelocity = 0x5197230;
	}

	// obf name: ::%fd4b846456d0f6e2e6e9903490d6916bc6dbd701
#define PositionLerp_ClassName "%fd4b846456d0f6e2e6e9903490d6916bc6dbd701"
#define PositionLerp_ClassNameShort "%fd4b846456d0f6e2e6e9903490d6916bc6dbd701"
#define PositionLerp_TypeDefinitionIndex 6541

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x40;
	}

	// obf name: ::%956e31d5c640377923ffd6bbc9e1cf6a3cfa33fc
#define Interpolator_ClassName "%956e31d5c640377923ffd6bbc9e1cf6a3cfa33fc<%f4f96f7872d5fc3730f0552b55390a1b098238cc>"
#define Interpolator_ClassNameShort "%956e31d5c640377923ffd6bbc9e1cf6a3cfa33fc"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 988

	namespace BaseCombatEntity {

		// Offsets
		constexpr const static size_t skeletonProperties = 0x1c8;
		constexpr const static size_t baseProtection = 0x1d0;
		constexpr const static size_t lifestate = 0x23c;
		constexpr const static size_t markAttackerHostile = 0x242;
		constexpr const static size_t _health = 0x244;
		constexpr const static size_t _maxHealth = 0x248;
		constexpr const static size_t lastNotifyFrame = 0x258;
	}

#define SkeletonProperties_TypeDefinitionIndex 2606

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 2604

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 3563

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 3562

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%72441985416c777f159528a82af8ea4d7d2d6234
#define DamageTypeList_ClassName "%72441985416c777f159528a82af8ea4d7d2d6234"
#define DamageTypeList_ClassNameShort "%72441985416c777f159528a82af8ea4d7d2d6234"
#define DamageTypeList_TypeDefinitionIndex 3216

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 4832

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 2615

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x40;
		constexpr const static size_t iconSprite = 0x50;
		constexpr const static size_t category = 0x58;
		constexpr const static size_t stackable = 0x70;
		constexpr const static size_t rarity = 0x88;
		constexpr const static size_t ItemModWearable = 0x168;
	}

#define RecoilProperties_TypeDefinitionIndex 3886

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 1067

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 827

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x4eeb370;
		constexpr const static size_t StartAttackCooldown = 0x4ee98d0;
	}

#define BaseProjectile_TypeDefinitionIndex 1071

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
		constexpr const static size_t LaunchProjectile = 0x5275c90;
		constexpr const static size_t LaunchProjectileClientSide = 0x527a650;
		constexpr const static size_t ScaleRepeatDelay = 0x5276d70;
		constexpr const static size_t GetAimCone = 0x524ea30;
		constexpr const static size_t GetAimCone_vtableoff = 0x3b88;
		constexpr const static size_t UpdateAmmoDisplay = 0x526f7a0;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3fb8;
	}

#define BaseLauncher_TypeDefinitionIndex 3138

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 412

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%361ea762a3a15510eb6664f85222b55e24d9cb6f
#define HitTest_ClassName "%361ea762a3a15510eb6664f85222b55e24d9cb6f"
#define HitTest_ClassNameShort "%361ea762a3a15510eb6664f85222b55e24d9cb6f"
#define HitTest_TypeDefinitionIndex 5806

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x2c;
		constexpr const static size_t AttackRay = 0xb8;
		constexpr const static size_t RayHit = 0x30;
		constexpr const static size_t damageProperties = 0xb0;
		constexpr const static size_t gameObject = 0x90;
		constexpr const static size_t collider = 0x70;
		constexpr const static size_t ignoredTypes = 0x88;
		constexpr const static size_t HitTransform = 0x60;
		constexpr const static size_t HitPart = 0xd4;
		constexpr const static size_t HitMaterial = 0x78;
		constexpr const static size_t DidHit = 0x81;
		constexpr const static size_t MaxDistance = 0x98;
		constexpr const static size_t HitPoint = 0x18;
		constexpr const static size_t HitNormal = 0xa0;
		constexpr const static size_t ignoreEntity = 0x10;
		constexpr const static size_t HitEntity = 0x68;
	}

#define Projectile_TypeDefinitionIndex 6349

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
		constexpr const static size_t hitTest = 0x108;
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
		constexpr const static size_t CalculateEffectScale = 0x45551e0;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x278;
		constexpr const static size_t SetEffectScale = 0x4545490;
		constexpr const static size_t UpdateVelocity = 0x456b640;
		constexpr const static size_t Retire = 0x4564f20;
		constexpr const static size_t DoHit = 0x4566b40;
	}

	// obf name: ::%f61616485bf0a4f77af50e77e0ba57435dacabfd
#define HitInfo_ClassName "%f61616485bf0a4f77af50e77e0ba57435dacabfd"
#define HitInfo_ClassNameShort "%f61616485bf0a4f77af50e77e0ba57435dacabfd"
#define HitInfo_TypeDefinitionIndex 6335

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0xa0;
		constexpr const static size_t damageTypes = 0x70;

		// Functions
		constexpr const static size_t get_boneArea = 0x4540590;
	}

	// obf name: ::%a3851eff089d745f0d9d7defc8f899922a07455b
#define GameTrace_ClassName "%a3851eff089d745f0d9d7defc8f899922a07455b"
#define GameTrace_ClassNameShort "%a3851eff089d745f0d9d7defc8f899922a07455b"
#define GameTrace_TypeDefinitionIndex 4282

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x2ddcc20;
	}

#define BaseMelee_TypeDefinitionIndex 3071

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x1f76660;
		constexpr const static size_t DoThrow = 0x1f78df0;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 3870

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x408;
		constexpr const static size_t strikeRecoil = 0x410;
		constexpr const static size_t _didSparkThisFrame = 0x418;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 1906

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x420;
		constexpr const static size_t stringBonusVelocity = 0x42c;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x1410c90;
	}

	// obf name: ::%175f238252acd8ce95b29c0178c725bb493f84d8
#define ItemContainer_ClassName "%175f238252acd8ce95b29c0178c725bb493f84d8"
#define ItemContainer_ClassNameShort "%175f238252acd8ce95b29c0178c725bb493f84d8"
#define ItemContainer_TypeDefinitionIndex 3559

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x50;
		constexpr const static size_t itemList = 0x58;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x24cd190;
	}

#define PlayerLoot_TypeDefinitionIndex 6082

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 2768

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x28;
		constexpr const static size_t containerWear = 0x30;
		constexpr const static size_t containerMain = 0x58;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x1c335e0;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 1306

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x54bc9f0;
		constexpr const static size_t get_rotation = 0x54be830;
		constexpr const static size_t set_rotation = 0x54e10a0;
		constexpr const static size_t HeadForward = 0x54c8c50;
	}

	// obf name: ::%f68ca49c0b1c4d4a563ba57b3f56f20db0c34f49
#define PlayerEyes_Static_ClassName "PlayerEyes/%f68ca49c0b1c4d4a563ba57b3f56f20db0c34f49"
#define PlayerEyes_Static_ClassNameShort "%f68ca49c0b1c4d4a563ba57b3f56f20db0c34f49"
#define PlayerEyes_Static_TypeDefinitionIndex 1305

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x1bc;
	}

	// obf name: ::%1cd6bcd197d9ca30b58e9a6562a8df7c4acbee09
#define PlayerBelt_ClassName "%1cd6bcd197d9ca30b58e9a6562a8df7c4acbee09"
#define PlayerBelt_ClassNameShort "%1cd6bcd197d9ca30b58e9a6562a8df7c4acbee09"
#define PlayerBelt_TypeDefinitionIndex 3499

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x23f3ed0;
		constexpr const static size_t GetActiveItem = 0x23faf70;
	}

	// obf name: ::%d553910822fe0b8fb8406a250757ed697e68424a
#define LocalPlayer_ClassName "%d553910822fe0b8fb8406a250757ed697e68424a"
#define LocalPlayer_ClassNameShort "%d553910822fe0b8fb8406a250757ed697e68424a"
#define LocalPlayer_TypeDefinitionIndex 3515

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x2419050;
		constexpr const static size_t MoveItem = 0x2412800;
		constexpr const static size_t get_Entity = 0x2423000;
	}

	// obf name: ::%8431d1bedca71b0174161511f3af50561b767e82
#define LocalPlayer_Static_ClassName "%d553910822fe0b8fb8406a250757ed697e68424a/%8431d1bedca71b0174161511f3af50561b767e82"
#define LocalPlayer_Static_ClassNameShort "%8431d1bedca71b0174161511f3af50561b767e82"
#define LocalPlayer_Static_TypeDefinitionIndex 3514

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0xb0;
	}

	// obf name: ::%0887015d376ee21856d23fa9dc977c5c6592c1bd
#define BasePlayer_Static_ClassName "BasePlayer/%0887015d376ee21856d23fa9dc977c5c6592c1bd"
#define BasePlayer_Static_ClassNameShort "%0887015d376ee21856d23fa9dc977c5c6592c1bd"
#define BasePlayer_Static_TypeDefinitionIndex 4967

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x430;
	}

#define BasePlayer_TypeDefinitionIndex 4968

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x5b8;
		constexpr const static size_t input = 0x418;
		constexpr const static size_t movement = 0x400;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x560;
		constexpr const static size_t playerFlags = 0x598;
		constexpr const static size_t eyes = 0x4b8;
		constexpr const static size_t playerRigidbody = 0x408;
		constexpr const static size_t userID = 0x5e0;
		constexpr const static size_t UserIDString = 0x478;
		constexpr const static size_t inventory = 0x5d8;
		constexpr const static size_t _displayName = 0x608;
		constexpr const static size_t _lookingAt = 0x328;
		constexpr const static size_t lastSentTickTime = 0x554;
		constexpr const static size_t lastSentTick = 0x2b0;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x2c0;
		constexpr const static size_t _lookingAtEntity = 0x450;
		constexpr const static size_t currentGesture = 0x5a0;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x367e0c0;
		constexpr const static size_t Menu_AssistPlayer = 0x360e8c0;
		constexpr const static size_t OnViewModeChanged = 0x3623890;
		constexpr const static size_t ChatMessage = 0x36b9440;
		constexpr const static size_t IsOnGround = 0x356cc20;
		constexpr const static size_t GetSpeed = 0x36b75c0;
		constexpr const static size_t SendProjectileUpdate = 0x35fbed0;
		constexpr const static size_t SendProjectileAttack = 0x35643f0;
		constexpr const static size_t CanBuild = 0x363c490;
		constexpr const static size_t GetMounted = 0x362a6f0;
		constexpr const static size_t GetHeldEntity = 0x3648520;
		constexpr const static size_t get_inventory = 0x35b4a70;
		constexpr const static size_t get_eyes = 0x3685910;
		constexpr const static size_t SendClientTick = 0x36b24d0;
		constexpr const static size_t ClientInput = 0x36670a0;
		constexpr const static size_t ClientInput_vtableoff = 0x3c48;
		constexpr const static size_t MaxHealth = 0x365ce50;
		constexpr const static size_t MaxHealth_vtableoff = 0x1008;
		constexpr const static size_t OnAttacked = 0x35a2f90;
		constexpr const static size_t OnAttacked_vtableoff = 0x1888;
	}

#define ScientistNPC_TypeDefinitionIndex 6799

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 2477

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 4137

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 3590

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 5139

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 3830

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 4211

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x2d23ce0;
		constexpr const static size_t BlockSprint = 0x2d0aaa0;
		constexpr const static size_t GroundCheck = 0x2d27fb0;
		constexpr const static size_t ClientInput = 0x2cecc60;
		constexpr const static size_t ClientInput_vtableoff = 0x438;
		constexpr const static size_t DoFixedUpdate = 0x2d1cb20;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x418;
		constexpr const static size_t FrameUpdate = 0x2cf8700;
		constexpr const static size_t FrameUpdate_vtableoff = 0x2b8;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 5911

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 1149

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 1291

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 4201

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 4197

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%9fa4840f4831a87aa2be807e7a44bb63fc1aa4a8
#define ConsoleSystem_ClassName "%9fa4840f4831a87aa2be807e7a44bb63fc1aa4a8"
#define ConsoleSystem_ClassNameShort "%9fa4840f4831a87aa2be807e7a44bb63fc1aa4a8"
#define ConsoleSystem_TypeDefinitionIndex 23287

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x65863e0;
	}

	// obf name: ::%f31461898b65a851a9487a18b2fe34cafab817e7
#define ConsoleSystem_Index_Static_ClassName "%9fa4840f4831a87aa2be807e7a44bb63fc1aa4a8/%28b33906d561a0f8b775ed5432c60a7c262988de.%f31461898b65a851a9487a18b2fe34cafab817e7"
#define ConsoleSystem_Index_Static_ClassNameShort "%f31461898b65a851a9487a18b2fe34cafab817e7"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23280

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x18;
	}

#define LootableCorpse_TypeDefinitionIndex 3472

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2c8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 3631

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 3403

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x30;
		constexpr const static size_t mainCameraTransform = 0x88;

		// Functions
		constexpr const static size_t Update = 0x22ea900;
		constexpr const static size_t OnPreCull = 0x22e4d50;
		constexpr const static size_t Trace = 0x22e4dd0;
	}

#define CameraMan_TypeDefinitionIndex 5587

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%ac580ce24e5cef592c1d4e7f4b8d728cd0a7f596
#define PlayerTick_ClassName "%ac580ce24e5cef592c1d4e7f4b8d728cd0a7f596"
#define PlayerTick_ClassNameShort "%ac580ce24e5cef592c1d4e7f4b8d728cd0a7f596"
#define PlayerTick_TypeDefinitionIndex 7345

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x20;
		constexpr const static size_t modelState = 0x18;
		constexpr const static size_t activeItem = 0x10;
		constexpr const static size_t parentID = 0x58;
		constexpr const static size_t intermediatePosition = 0x4c;
		constexpr const static size_t position = 0x28;
		constexpr const static size_t eyePos = 0x40;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x98fdc40;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x98f3120;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%7b929ced0bc310bf8a08363facb81d288525ec45
#define InputMessage_ClassName "%7b929ced0bc310bf8a08363facb81d288525ec45"
#define InputMessage_ClassNameShort "%7b929ced0bc310bf8a08363facb81d288525ec45"
#define InputMessage_TypeDefinitionIndex 7215

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x14;
		constexpr const static size_t aimAngles = 0x1c;
		constexpr const static size_t mouseDelta = 0x28;
	}

	// obf name: ::%521f09912e7393e31fe7b4ec00b86aef3a32e41f
#define InputState_ClassName "%521f09912e7393e31fe7b4ec00b86aef3a32e41f"
#define InputState_ClassNameShort "%521f09912e7393e31fe7b4ec00b86aef3a32e41f"
#define InputState_TypeDefinitionIndex 914

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x20;
		constexpr const static size_t previous = 0x18;
	}

#define PlayerInput_TypeDefinitionIndex 3465

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%8752e965a20685c0e7637b6b8c1b32289051fc9a
#define ModelState_ClassName "%8752e965a20685c0e7637b6b8c1b32289051fc9a"
#define ModelState_ClassNameShort "%8752e965a20685c0e7637b6b8c1b32289051fc9a"
#define ModelState_TypeDefinitionIndex 7615

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x64;
		constexpr const static size_t waterLevel = 0x60;
		constexpr const static size_t lookDir = 0x24;
	}

	// obf name: ::%bba33a7da087e6f01050ecd9a68e548fbab111be
#define Item_ClassName "%bba33a7da087e6f01050ecd9a68e548fbab111be"
#define Item_ClassNameShort "%bba33a7da087e6f01050ecd9a68e548fbab111be"
#define Item_TypeDefinitionIndex 3319

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0xc8;
		constexpr const static size_t uid = 0xe0;
		constexpr const static size_t _maxCondition = 0x4c;
		constexpr const static size_t _condition = 0x54;
		constexpr const static size_t position = 0xb8;
		constexpr const static size_t amount = 0xc0;
		constexpr const static size_t parent = 0x80;
		constexpr const static size_t contents = 0x90;
		constexpr const static size_t worldEnt = 0x38;
		constexpr const static size_t heldEntity = 0x70;

		// Functions
		constexpr const static size_t get_iconSprite = 0x21ade50;
	}

	// obf name: ::%2c2f915dc13c6d3b67d01fed887cd7ad569c8b51
#define WaterLevel_ClassName "%2c2f915dc13c6d3b67d01fed887cd7ad569c8b51"
#define WaterLevel_ClassNameShort "%2c2f915dc13c6d3b67d01fed887cd7ad569c8b51"
#define WaterLevel_TypeDefinitionIndex 3390

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x229b7a0;
		constexpr const static size_t GetWaterLevel = 0x22b16b0;
	}

	// obf name: ::%124197d7cc8a4c2fc7f06756156acf6c3d097594
#define ConVar_Graphics_Static_ClassName "%4830f3c8b6fe96a78811e778ba51de9d4262792b/%124197d7cc8a4c2fc7f06756156acf6c3d097594"
#define ConVar_Graphics_Static_ClassNameShort "%124197d7cc8a4c2fc7f06756156acf6c3d097594"
#define ConVar_Graphics_Static_TypeDefinitionIndex 3175

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x48c;

		// Functions
		constexpr const static size_t _fov_getter = 0x2add3a0;
		constexpr const static size_t _fov_setter = 0x2abf6c0;
	}

#define BaseFishingRod_TypeDefinitionIndex 6089

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
		constexpr const static size_t UpdateLineRenderer = 0x4172680;
		constexpr const static size_t EvaluateFishingPosition = 0x417d750;
	}

#define FishingBobber_TypeDefinitionIndex 3723

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 1104

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x52bfea0;
	}

	// obf name: ::%81a73aefbbb55c952314128443285a1f81e89262
#define GameManager_ClassName "%81a73aefbbb55c952314128443285a1f81e89262"
#define GameManager_ClassNameShort "%81a73aefbbb55c952314128443285a1f81e89262"
#define GameManager_TypeDefinitionIndex 568

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x28;

		// Functions
		constexpr const static size_t CreatePrefab = 0x3762430;
	}

	// obf name: ::%fb27c86616bf9598f2258a3726439ab5a92831a5
#define GameManager_Static_ClassName "%81a73aefbbb55c952314128443285a1f81e89262/%fb27c86616bf9598f2258a3726439ab5a92831a5"
#define GameManager_Static_ClassNameShort "%fb27c86616bf9598f2258a3726439ab5a92831a5"
#define GameManager_Static_TypeDefinitionIndex 567

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x38;
	}

	// obf name: ::%73d4e4e1846cd7719544d2060eb0ebcc0574efc3
#define PrefabPoolCollection_ClassName "%73d4e4e1846cd7719544d2060eb0ebcc0574efc3"
#define PrefabPoolCollection_ClassNameShort "%73d4e4e1846cd7719544d2060eb0ebcc0574efc3"
#define PrefabPoolCollection_TypeDefinitionIndex 4484

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%4384fe47ff83903e5b754e4cf777c9c33100d4a5
#define PrefabPool_ClassName "%4384fe47ff83903e5b754e4cf777c9c33100d4a5"
#define PrefabPool_ClassNameShort "%4384fe47ff83903e5b754e4cf777c9c33100d4a5"
#define PrefabPool_TypeDefinitionIndex 4432

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x28;
	}

#define ItemModProjectile_TypeDefinitionIndex 5458

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

#define CraftingQueue_TypeDefinitionIndex 1757

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%95499e5cab779d4ebdf0be9890803c5a19fce7b8
#define CraftingQueue_Static_ClassName "CraftingQueue/%95499e5cab779d4ebdf0be9890803c5a19fce7b8"
#define CraftingQueue_Static_ClassNameShort "%95499e5cab779d4ebdf0be9890803c5a19fce7b8"
#define CraftingQueue_Static_TypeDefinitionIndex 1756

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x18;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 1843

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%bf8bf32a5f0b5bcd55a4f9331debb644f9fa9618
#define Planner_Static_ClassName "Planner/%bf8bf32a5f0b5bcd55a4f9331debb644f9fa9618"
#define Planner_Static_ClassNameShort "%bf8bf32a5f0b5bcd55a4f9331debb644f9fa9618"
#define Planner_Static_TypeDefinitionIndex 5037

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x68;
	}

	// obf name: ::%4484f25522698d028f6bd118c666330aab5f39ae
#define Planner_Guide_ClassName "Planner/%4484f25522698d028f6bd118c666330aab5f39ae"
#define Planner_Guide_ClassNameShort "%4484f25522698d028f6bd118c666330aab5f39ae"
#define Planner_Guide_TypeDefinitionIndex 5033

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0xa0;
	}

#define Planner_TypeDefinitionIndex 5038

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x270;
	}

#define Construction_TypeDefinitionIndex 4936

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x138;
	}

#define BuildingBlock_TypeDefinitionIndex 1041

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x300;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 908

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x5012e30;
	}

	// obf name: ::%fcc12e1d36ea6464f4ae4815391122b9454d0ce0
#define PunchEntry_ClassName "HeldEntity/%fcc12e1d36ea6464f4ae4815391122b9454d0ce0"
#define PunchEntry_ClassNameShort "%fcc12e1d36ea6464f4ae4815391122b9454d0ce0"
#define PunchEntry_TypeDefinitionIndex 906

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x10;
		constexpr const static size_t duration = 0x20;
		constexpr const static size_t amountAdded = 0x14;
		constexpr const static size_t amount = 0x24;
	}

#define IronSights_TypeDefinitionIndex 4224

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 2572

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 959

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xe0;
		constexpr const static size_t model = 0xb0;
		constexpr const static size_t lower = 0xe8;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x50f3820;
	}

#define ViewModel_TypeDefinitionIndex 3509

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x2407ee0;
		constexpr const static size_t PlayString = 0x24046f0;
	}

#define MedicalTool_TypeDefinitionIndex 4112

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 2465

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x58;
	}

	// obf name: ::%2c26d44217dcf1a76f020e8acf2a5dedc056d22a
#define WaterSystem_Static_ClassName "WaterSystem/%2c26d44217dcf1a76f020e8acf2a5dedc056d22a"
#define WaterSystem_Static_ClassNameShort "%2c26d44217dcf1a76f020e8acf2a5dedc056d22a"
#define WaterSystem_Static_TypeDefinitionIndex 114

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x150;
	}

#define WaterSystem_TypeDefinitionIndex 115

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x4fb7e20;
	}

#define TerrainMeta_TypeDefinitionIndex 3815

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x6c8;
		constexpr const static size_t HeightMap = 0x690;
		constexpr const static size_t SplatMap = 0x3c8;
		constexpr const static size_t TopologyMap = 0x6c0;
		constexpr const static size_t Texturing = 0x548;
	}

#define TerrainCollision_TypeDefinitionIndex 666

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x4301640;
	}

#define TerrainHeightMap_TypeDefinitionIndex 4404

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 5442

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 5755

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%fa8810164136b27b8a441e9e4860d57339aca387
#define World_Static_ClassName "%ce1dac65bc032353dfa80757ab6ba260ddbb1559/%fa8810164136b27b8a441e9e4860d57339aca387"
#define World_Static_ClassNameShort "%fa8810164136b27b8a441e9e4860d57339aca387"
#define World_Static_TypeDefinitionIndex 3730

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0xc0;
	}

#define ItemIcon_TypeDefinitionIndex 6577

	namespace ItemIcon {

		// Functions
		constexpr const static size_t TryToMove = 0x489ba40;
		constexpr const static size_t TryToMove_vtableoff = 0x3b8;
		constexpr const static size_t RunTimedAction = 0x48b4090;
	}

	// obf name: ::%3e1655daf4310083ea2ea4f654a6784b472c6b1b
#define ItemIcon_Static_ClassName "ItemIcon/%3e1655daf4310083ea2ea4f654a6784b472c6b1b"
#define ItemIcon_Static_ClassNameShort "%3e1655daf4310083ea2ea4f654a6784b472c6b1b"
#define ItemIcon_Static_TypeDefinitionIndex 6576

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x30;
	}

	// obf name: ::%b7b411af0da87e7a1ef260459172b915a193607b
#define Effect_ClassName "%b7b411af0da87e7a1ef260459172b915a193607b"
#define Effect_ClassNameShort "%b7b411af0da87e7a1ef260459172b915a193607b"
#define Effect_TypeDefinitionIndex 369

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0xa0;
		constexpr const static size_t worldPos = 0x88;
	}

	// obf name: ::%2a78c0fc57ce844ccfa96b1c766cf8f52ffa9148
#define EffectNetwork_ClassName "%2a78c0fc57ce844ccfa96b1c766cf8f52ffa9148"
#define EffectNetwork_ClassNameShort "%2a78c0fc57ce844ccfa96b1c766cf8f52ffa9148"
#define EffectNetwork_TypeDefinitionIndex 6008

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%a4848a6b149a7e5d158f28aad7f4e788f4460ebe
#define EffectNetwork_Static_ClassName "%2a78c0fc57ce844ccfa96b1c766cf8f52ffa9148/%a4848a6b149a7e5d158f28aad7f4e788f4460ebe"
#define EffectNetwork_Static_ClassNameShort "%a4848a6b149a7e5d158f28aad7f4e788f4460ebe"
#define EffectNetwork_Static_TypeDefinitionIndex 6007

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x18;

		// Functions
		constexpr const static size_t cctor = 0x40c2ff0;
	}

#define BuildingBlock_TypeDefinitionIndex 1041

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x51baf00;
		constexpr const static size_t HasUpgradePrivilege = 0x51c11f0;
		constexpr const static size_t CanAffordUpgrade = 0x51c4f20;
	}

	// obf name: ::%5c380d5a3db1159657a92b1ab9686c1f979514fe
#define GameObjectEx_ClassName "%5c380d5a3db1159657a92b1ab9686c1f979514fe"
#define GameObjectEx_ClassNameShort "%5c380d5a3db1159657a92b1ab9686c1f979514fe"
#define GameObjectEx_TypeDefinitionIndex 3806

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x27126d0;
	}

#define UIDeathScreen_TypeDefinitionIndex 2058

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x155e830;
	}

	// obf name: ::%6591b7c3f45ac1522cfcf8cf044a02fb23a9b50a
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%6591b7c3f45ac1522cfcf8cf044a02fb23a9b50a"
#define BaseScreenShake_Static_ClassNameShort "%6591b7c3f45ac1522cfcf8cf044a02fb23a9b50a"
#define BaseScreenShake_Static_TypeDefinitionIndex 4180

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0xa8;
	}

#define FlashbangOverlay_TypeDefinitionIndex 6778

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t flashLength = 0x50;
	}

	// obf name: ::%5c07dd66a6194e93d714d37b8fc08e67a90e9cd3
#define StringPool_ClassName "%5c07dd66a6194e93d714d37b8fc08e67a90e9cd3"
#define StringPool_ClassNameShort "%5c07dd66a6194e93d714d37b8fc08e67a90e9cd3"
#define StringPool_TypeDefinitionIndex 3115

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x120;

		// Functions
		constexpr const static size_t Get = 0x1fc51c0;
	}

	// obf name: ::%421fc86a5a6da91a3e97add9595aa00f318b692e
#define Network_Networkable_ClassName "%421fc86a5a6da91a3e97add9595aa00f318b692e"
#define Network_Networkable_ClassNameShort "%421fc86a5a6da91a3e97add9595aa00f318b692e"
#define Network_Networkable_TypeDefinitionIndex 19129

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x18;
	}

	// obf name: ::%3eb3deb49e9ee0407d1b4c2e1f77fdde9950d715
#define Network_Net_ClassName "%3eb3deb49e9ee0407d1b4c2e1f77fdde9950d715"
#define Network_Net_ClassNameShort "%3eb3deb49e9ee0407d1b4c2e1f77fdde9950d715"
#define Network_Net_TypeDefinitionIndex 7977

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x20;
	}

	// obf name: ::%0401355c762410df10296f0d6956014dbf2d8b48
#define Network_Client_ClassName "%0401355c762410df10296f0d6956014dbf2d8b48"
#define Network_Client_ClassNameShort "%0401355c762410df10296f0d6956014dbf2d8b48"
#define Network_Client_TypeDefinitionIndex 19154

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0x100;
		constexpr const static size_t ConnectedPort = 0xfc;
		constexpr const static size_t ServerName = 0xd0;
		constexpr const static size_t ConnectedAddress = 0xe0;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x6650780;
		constexpr const static size_t DestroyNetworkable = 0x66509c0;
	}

	// obf name: ::%4ef588b26d6ee39d2f8bdfe16942c0420366d00b
#define Network_BaseNetwork_ClassName "%4ef588b26d6ee39d2f8bdfe16942c0420366d00b"
#define Network_BaseNetwork_ClassNameShort "%4ef588b26d6ee39d2f8bdfe16942c0420366d00b"
#define Network_BaseNetwork_TypeDefinitionIndex 19149

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x6640480;
	}

	// obf name: ::%b437146d90c38f0ea2aad8bebb2ac1dcecae1b50
#define Network_SendInfo_ClassName "%b437146d90c38f0ea2aad8bebb2ac1dcecae1b50"
#define Network_SendInfo_ClassNameShort "%b437146d90c38f0ea2aad8bebb2ac1dcecae1b50"
#define Network_SendInfo_TypeDefinitionIndex 19141

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%e5fdad534418c7645187a48dcd2cc6dde8c0023e
#define Network_Message_ClassName "%e5fdad534418c7645187a48dcd2cc6dde8c0023e"
#define Network_Message_ClassNameShort "%e5fdad534418c7645187a48dcd2cc6dde8c0023e"
#define Network_Message_TypeDefinitionIndex 19165

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%6d2cbf6836f74d8fbe33e63a6e5423d17f529905
#define Network_NetRead_ClassName "%6d2cbf6836f74d8fbe33e63a6e5423d17f529905"
#define Network_NetRead_ClassNameShort "%6d2cbf6836f74d8fbe33e63a6e5423d17f529905"
#define Network_NetRead_TypeDefinitionIndex 19172

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x40;
	}

	// obf name: ::%0e0f996f5d373ae8edf38c52c6a000d7f2194af9
#define Network_NetWrite_ClassName "%0e0f996f5d373ae8edf38c52c6a000d7f2194af9"
#define Network_NetWrite_ClassNameShort "%0e0f996f5d373ae8edf38c52c6a000d7f2194af9"
#define Network_NetWrite_TypeDefinitionIndex 19167

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x40;

		// Functions
		constexpr const static size_t WriteByte = 0x6659690;
		constexpr const static size_t String = 0x6657e40;
		constexpr const static size_t Send = 0x665bd10;
	}

#define LootPanel_TypeDefinitionIndex 1289

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x549a080;
	}

#define UIInventory_TypeDefinitionIndex 6564

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x487d250;
	}

#define GrowableEntity_TypeDefinitionIndex 5791

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 7089

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 7088

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 20988

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 9215

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
		constexpr const static size_t get_Instance = 0xc6f060;
	}

	// obf name: ::%e4d00af1f60857c8bc9a4d4c4f112e2ffb98e348
#define TOD_Sky_Static_ClassName "TOD_Sky/%e4d00af1f60857c8bc9a4d4c4f112e2ffb98e348"
#define TOD_Sky_Static_ClassNameShort "%e4d00af1f60857c8bc9a4d4c4f112e2ffb98e348"
#define TOD_Sky_Static_TypeDefinitionIndex 9214

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x28;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 8413

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xa23360;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9690

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 8571

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 9124

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 9352

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 8323

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8529

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 1850

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 3673

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 5941

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 3393

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

#define EnvironmentManager_TypeDefinitionIndex 4707

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x32c8250;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%bf6bb3e624e9fed03a0553735955901e8fd302a0/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24046

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 3910

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 3911

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 721

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
		constexpr const static size_t InstanceList = 0x10;
	}

	// obf name: ::%4afdd38e20930b3074bd9455370a505f707d9db6
#define ListHashSet_ClassName "%4afdd38e20930b3074bd9455370a505f707d9db6<UIChat>"
#define ListHashSet_ClassNameShort "%4afdd38e20930b3074bd9455370a505f707d9db6"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 3707

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3f0;
	}

#define Chainsaw_TypeDefinitionIndex 6986

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%8181e2ac3e5f70d270859a40c921e1809f533095
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%8181e2ac3e5f70d270859a40c921e1809f533095"
#define CameraUpdateHook_Static_ClassNameShort "%8181e2ac3e5f70d270859a40c921e1809f533095"
#define CameraUpdateHook_Static_TypeDefinitionIndex 2352

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0xb0;
	}

#define SteamClientWrapper_TypeDefinitionIndex 4793

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x33b5330;
	}

	// obf name: ::%5748666da387c36d6e267739c6fb5a107aae57f8
#define AimConeUtil_ClassName "%5748666da387c36d6e267739c6fb5a107aae57f8"
#define AimConeUtil_ClassNameShort "%5748666da387c36d6e267739c6fb5a107aae57f8"
#define AimConeUtil_TypeDefinitionIndex 6491

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x477dc00;
	}

	// obf name: ::%aea64d3b117cbec0e888fb6775a599b7aa6d6439
#define Buttons_ConButton_ClassName "%14491e4062303f498fdead30cf466b9fd2a8a8c0/%aea64d3b117cbec0e888fb6775a599b7aa6d6439"
#define Buttons_ConButton_ClassNameShort "%aea64d3b117cbec0e888fb6775a599b7aa6d6439"
#define Buttons_ConButton_TypeDefinitionIndex 5696

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%4995c0abfe66c7b308501632df23f0f44db0ed6c
#define Buttons_Static_ClassName "%14491e4062303f498fdead30cf466b9fd2a8a8c0/%4995c0abfe66c7b308501632df23f0f44db0ed6c"
#define Buttons_Static_ClassNameShort "%4995c0abfe66c7b308501632df23f0f44db0ed6c"
#define Buttons_Static_TypeDefinitionIndex 5697

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x530;
		constexpr const static size_t Attack = 0x768;
		constexpr const static size_t Attack2 = 0x338;
		constexpr const static size_t Forward = 0x1b8;
		constexpr const static size_t Backward = 0x90;
		constexpr const static size_t Right = 0x408;
		constexpr const static size_t Left = 0xbf0;
		constexpr const static size_t Sprint = 0x658;

		// Functions
		constexpr const static size_t Pets_setter = 0x2af1020;
	}

#define PlayerModel_TypeDefinitionIndex 4827

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x1e0;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 6874

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x40;
	}

#define BaseMountable_TypeDefinitionIndex 2758

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 3322

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 5611

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x408;
		constexpr const static size_t wasAiming = 0x418;
	}

#define CrossbowWeapon_TypeDefinitionIndex 3543

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 5934

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%5e0ef200816083fd685996c2163bfd564d87243e
#define ConVar_Admin_Static_ClassName "%9a2aa179b3f99e544b261c1d5e447b0204fb11d5/%5e0ef200816083fd685996c2163bfd564d87243e"
#define ConVar_Admin_Static_ClassNameShort "%5e0ef200816083fd685996c2163bfd564d87243e"
#define ConVar_Admin_Static_TypeDefinitionIndex 1880

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x170;

		// Functions
		constexpr const static size_t admintime_getter = 0x2aa5910;
		constexpr const static size_t admintime_setter = 0x2acf430;
	}

	// obf name: ::%f2a5991165f27970ce132089e14465417e371252
#define ConVar_Player_Static_ClassName "%3e39e6e13650d1bbdc03298ff11dba279827fa1e/%f2a5991165f27970ce132089e14465417e371252"
#define ConVar_Player_Static_ClassNameShort "%f2a5991165f27970ce132089e14465417e371252"
#define ConVar_Player_Static_TypeDefinitionIndex 3459

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x14;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x2aca770;
		constexpr const static size_t clientTickRate_setter = 0x2aacd90;
	}

#define ColliderInfo_TypeDefinitionIndex 2980

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 1886

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 5915

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x368;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x3fc5f30;
	}

#define Client_TypeDefinitionIndex 6661

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x4943ef0;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%58446db6f31bda1f9b3ec1d679df7f3aaa95d895
#define ItemManager_Static_ClassName "%ffa77779c8d84cfea98ab7b418e30f7558adeec3/%58446db6f31bda1f9b3ec1d679df7f3aaa95d895"
#define ItemManager_Static_ClassNameShort "%58446db6f31bda1f9b3ec1d679df7f3aaa95d895"
#define ItemManager_Static_TypeDefinitionIndex 744

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x78;
		constexpr const static size_t itemDictionary = 0xd8;
		constexpr const static size_t itemDictionaryByName = 0x58;
	}

	// obf name: ::%095a45f6ddd7a4d052c2e696a39ad0d77cba2296
#define ConVar_Server_Static_ClassName "%f96c7cf5cad2eb6e12f89794d1c8863c582db9d1/%095a45f6ddd7a4d052c2e696a39ad0d77cba2296"
#define ConVar_Server_Static_ClassNameShort "%095a45f6ddd7a4d052c2e696a39ad0d77cba2296"
#define ConVar_Server_Static_TypeDefinitionIndex 1672

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 7020

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x4d1e260;
	}

#define LoadingScreen_TypeDefinitionIndex 4375

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 752

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%b15ccc07502aaf07efab8333d4b2c91ecbca5bb4"
#define MapView_Static_ClassNameShort "%b15ccc07502aaf07efab8333d4b2c91ecbca5bb4"
#define MapView_TypeDefinitionIndex 3528

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x24322c0;
	}

	// obf name: ::%c2007a2712ef89bc6772c9b7d3eb96c2c758e875
#define GamePhysics_Static_ClassName "%8ac616b3a55a33f46e42dc2155c45b1c66780b50/%c2007a2712ef89bc6772c9b7d3eb96c2c758e875"
#define GamePhysics_Static_ClassNameShort "%c2007a2712ef89bc6772c9b7d3eb96c2c758e875"
#define GamePhysics_Static_TypeDefinitionIndex 2427

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x38;
	}

	// obf name: ::%8ac616b3a55a33f46e42dc2155c45b1c66780b50
#define GamePhysics_ClassName "%8ac616b3a55a33f46e42dc2155c45b1c66780b50"
#define GamePhysics_ClassNameShort "%8ac616b3a55a33f46e42dc2155c45b1c66780b50"
#define GamePhysics_TypeDefinitionIndex 2428

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x18b4e30;
		constexpr const static size_t LineOfSightInternal = 0x18bd9a0;
		constexpr const static size_t Verify = 0x18c5ed0;
	}

#define DDraw_TypeDefinitionIndex 1803

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x128d1e0;
		constexpr const static size_t Line = 0x1282000;
	}

	// obf name: ::%ef71a3960a42c20da889f40bda901d800562eadd
#define RaycastHitEx_ClassName "%ef71a3960a42c20da889f40bda901d800562eadd"
#define RaycastHitEx_ClassNameShort "%ef71a3960a42c20da889f40bda901d800562eadd"
#define RaycastHitEx_TypeDefinitionIndex 5173

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x38f7cc0;
	}

	// obf name: ::%c712e6bc3df91996c1cdcf4245d88bf65e151bd1
#define OnParentDestroyingEx_ClassName "%c712e6bc3df91996c1cdcf4245d88bf65e151bd1"
#define OnParentDestroyingEx_ClassNameShort "%c712e6bc3df91996c1cdcf4245d88bf65e151bd1"
#define OnParentDestroyingEx_TypeDefinitionIndex 105

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x4dc7d50;
	}

	// obf name: ::%e5521bf95a6962bc29dac039b1f0c2b170712860
#define ConsoleNetwork_ClassName "%e5521bf95a6962bc29dac039b1f0c2b170712860"
#define ConsoleNetwork_ClassNameShort "%e5521bf95a6962bc29dac039b1f0c2b170712860"
#define ConsoleNetwork_TypeDefinitionIndex 4502

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x3030ee0;
	}

#define ThrownWeapon_TypeDefinitionIndex 3426

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 5527

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 5786

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 3528

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 3823

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 2159

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 4640

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 4047

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 779

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 448

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%cbc646d5b296d2abfc5da8a9f1b579dbc6ed8091
#define ConVar_Client_Static_ClassName "%602a1644113e48f010127392c95bdbbf9181a642/%cbc646d5b296d2abfc5da8a9f1b579dbc6ed8091"
#define ConVar_Client_Static_ClassNameShort "%cbc646d5b296d2abfc5da8a9f1b579dbc6ed8091"
#define ConVar_Client_Static_TypeDefinitionIndex 2932

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x824;
		constexpr const static size_t camspeed = 0x90c;
	}

#define SamSite_TypeDefinitionIndex 4263

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 6531

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 5414

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 6832

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 2282

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 2812

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 4649

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 2475

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%e25f696d9fa488c039cd4fe8047dcda967364213
#define Facepunch_Network_Raknet_Client_ClassName "%e25f696d9fa488c039cd4fe8047dcda967364213"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%e25f696d9fa488c039cd4fe8047dcda967364213"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 22591

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x66abf10;
		constexpr const static size_t IsConnected_vtableoff = 0x268;
	}

	// obf name: ::%62bbe661556a4c81c62636170e22f13c28bf2d4a
#define EncryptedValue_ClassName "%62bbe661556a4c81c62636170e22f13c28bf2d4a<System/Int32>"
#define EncryptedValue_ClassNameShort "%62bbe661556a4c81c62636170e22f13c28bf2d4a"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%2bc4191d239019d40fcfea7b2f199a376171bea9
#define HiddenValue_ClassName "%2bc4191d239019d40fcfea7b2f199a376171bea9<BaseNetworkable/%de5e04a9dade5aa6cd67b83af102cb57c9335946>"
#define HiddenValue_ClassNameShort "%2bc4191d239019d40fcfea7b2f199a376171bea9"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 7001

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x4d03d80;
	}

#define ItemModRFListener_TypeDefinitionIndex 3679

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x25a1e50;
	}

#define UIFogOverlay_TypeDefinitionIndex 5414

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x10;
	}

	// obf name: ::%168f74aa267d31f3b81ece4b70b41f9dd73a79b4
#define BufferStream_ClassName "%168f74aa267d31f3b81ece4b70b41f9dd73a79b4"
#define BufferStream_ClassNameShort "%168f74aa267d31f3b81ece4b70b41f9dd73a79b4"
#define BufferStream_TypeDefinitionIndex 7165

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x953c3b0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 5388

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 1098

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 434

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x2a07bc0;
	}

#define OutlineManager_TypeDefinitionIndex 6915

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%6163299dd2341a143eb953657deb007a3320ce98
#define ConsoleSystem_Command_ClassName "%9fa4840f4831a87aa2be807e7a44bb63fc1aa4a8/%6163299dd2341a143eb953657deb007a3320ce98"
#define ConsoleSystem_Command_ClassNameShort "%6163299dd2341a143eb953657deb007a3320ce98"
#define ConsoleSystem_Command_TypeDefinitionIndex 23272

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x18;
		constexpr const static size_t SetOveride = 0x80;
		constexpr const static size_t Call = 0x38;
	}

	// obf name: ::%e9d8028114888288ea23002b738c86d1a26c43e8
#define ConsoleSystem_Option_ClassName "%9fa4840f4831a87aa2be807e7a44bb63fc1aa4a8/%e9d8028114888288ea23002b738c86d1a26c43e8"
#define ConsoleSystem_Option_ClassNameShort "%e9d8028114888288ea23002b738c86d1a26c43e8"
#define ConsoleSystem_Option_TypeDefinitionIndex 23282

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%8e6e5cf6574a58d6579b4081dde7bc45adc1017c
#define ConsoleSystem_Arg_ClassName "%9fa4840f4831a87aa2be807e7a44bb63fc1aa4a8/%8e6e5cf6574a58d6579b4081dde7bc45adc1017c"
#define ConsoleSystem_Arg_ClassNameShort "%8e6e5cf6574a58d6579b4081dde7bc45adc1017c"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23270

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x38;
	}

	// obf name: ::%d5bcbe30a9a220b5da2bb78f893492f711182e40
#define ConsoleSystem_Index_Client_ClassName "%9fa4840f4831a87aa2be807e7a44bb63fc1aa4a8/%28b33906d561a0f8b775ed5432c60a7c262988de.%d5bcbe30a9a220b5da2bb78f893492f711182e40"
#define ConsoleSystem_Index_Client_ClassNameShort "%d5bcbe30a9a220b5da2bb78f893492f711182e40"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23278

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x6594a80;
	}

#define String_TypeDefinitionIndex 10203

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x875e610;
	}

	// obf name: ::%1f9bef7f62804332e61dac070683d0ed1d6a4e1c
#define ProtoBuf_ProjectileShoot_ClassName "%1f9bef7f62804332e61dac070683d0ed1d6a4e1c"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%1f9bef7f62804332e61dac070683d0ed1d6a4e1c"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7587

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x92800c0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x927c3d0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%eb15423b5a49b8166d1a96d50c384676b0998afa
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%1f9bef7f62804332e61dac070683d0ed1d6a4e1c/%eb15423b5a49b8166d1a96d50c384676b0998afa"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%eb15423b5a49b8166d1a96d50c384676b0998afa"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7586

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x24;
		constexpr const static size_t startPos = 0x28;
		constexpr const static size_t startVel = 0x14;
		constexpr const static size_t seed = 0x34;
	}

	// obf name: ::%970aa9f11cb15c095180ea21b85c1f2a836d33c1
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%970aa9f11cb15c095180ea21b85c1f2a836d33c1"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%970aa9f11cb15c095180ea21b85c1f2a836d33c1"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7620

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x1c;
		constexpr const static size_t curPosition = 0x2c;
		constexpr const static size_t curVelocity = 0x20;
		constexpr const static size_t travelTime = 0x14;
		constexpr const static size_t ShouldPool = 0x10;

		// Functions
		constexpr const static size_t Dispose = 0x93beae0;
		constexpr const static size_t WriteToStreamDelta = 0x93b53e0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x93ba950;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%ad504b69ffe511f53d3b15585c340eae5663e603
#define ProtoBuf_PlayerProjectileAttack_ClassName "%ad504b69ffe511f53d3b15585c340eae5663e603"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%ad504b69ffe511f53d3b15585c340eae5663e603"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7169

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x20;
		constexpr const static size_t hitDistance = 0x30;
		constexpr const static size_t travelTime = 0x2c;
		constexpr const static size_t playerAttack = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9880430;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x987d250;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%561a448eaabaeaaafd48c7c59bb779e90088a9ef
#define ProtoBuf_PlayerAttack_ClassName "%561a448eaabaeaaafd48c7c59bb779e90088a9ef"
#define ProtoBuf_PlayerAttack_ClassNameShort "%561a448eaabaeaaafd48c7c59bb779e90088a9ef"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7309

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x24;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%a76a8e69a8b5b49e8130f633ed06ed2698fa7df4
#define ProtoBuf_Attack_ClassName "%a76a8e69a8b5b49e8130f633ed06ed2698fa7df4"
#define ProtoBuf_Attack_ClassNameShort "%a76a8e69a8b5b49e8130f633ed06ed2698fa7df4"
#define ProtoBuf_Attack_TypeDefinitionIndex 7181

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x2c;
		constexpr const static size_t pointEnd = 0x6c;
		constexpr const static size_t hitID = 0x50;
		constexpr const static size_t hitBone = 0x80;
		constexpr const static size_t hitNormalLocal = 0x3c;
		constexpr const static size_t hitPositionLocal = 0x1c;
		constexpr const static size_t hitNormalWorld = 0x5c;
		constexpr const static size_t hitPositionWorld = 0x10;
		constexpr const static size_t hitPartID = 0x28;
		constexpr const static size_t hitMaterialID = 0x58;
		constexpr const static size_t srcParentID = 0x78;
		constexpr const static size_t dstParentID = 0x48;
	}
}