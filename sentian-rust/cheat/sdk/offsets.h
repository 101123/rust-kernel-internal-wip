#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68c6fb71;
		constexpr const static size_t gc_handles = 0xd58e700;
		constexpr const static size_t il2cpp_resolve_icall = 0x7a62e0;
		constexpr const static size_t il2cpp_array_new = 0x7a6300;
		constexpr const static size_t il2cpp_assembly_get_image = 0x44e70;
		constexpr const static size_t il2cpp_class_from_name = 0x7a6470;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x7a6780;
		constexpr const static size_t il2cpp_class_get_type = 0x7a6820;
		constexpr const static size_t il2cpp_domain_get = 0x7a6d80;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x7a6da0;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x7a7660;
		constexpr const static size_t il2cpp_gchandle_new = 0x7a7610;
		constexpr const static size_t il2cpp_gchandle_free = 0x7a7700;
		constexpr const static size_t il2cpp_method_get_name = 0x4a10;
		constexpr const static size_t il2cpp_object_new = 0x7a7db0;
		constexpr const static size_t il2cpp_type_get_object = 0x7a85a0;
	}

#define Object_TypeDefinitionIndex 16569

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xaeb8240;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16540

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

#define Component_TypeDefinitionIndex 16527

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16521

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 16604

	namespace Transform {

		// Functions
		constexpr const static size_t GetChild = 0x115600;
		constexpr const static size_t GetParent = 0x111e60;
		constexpr const static size_t GetRoot = 0x113f70;
		constexpr const static size_t InverseTransformDirection_Injected = 0x113150;
		constexpr const static size_t InverseTransformPoint_Injected = 0x113cb0;
		constexpr const static size_t InverseTransformVector_Injected = 0x1136d0;
		constexpr const static size_t SetLocalPositionAndRotation_Injected = 0x112650;
		constexpr const static size_t SetPositionAndRotation_Injected = 0x112510;
		constexpr const static size_t TransformDirection_Injected = 0x112e90;
		constexpr const static size_t TransformPoint_Injected = 0x1139f0;
		constexpr const static size_t TransformVector_Injected = 0x113410;
		constexpr const static size_t get_childCount = 0x773b0;
		constexpr const static size_t get_eulerAngles = 0x773b0;
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

#define Camera_TypeDefinitionIndex 16319

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16591

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

#define Material_TypeDefinitionIndex 16382

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16378

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xae78530;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16381

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xae7bda0;
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16437

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

#define Renderer_TypeDefinitionIndex 16379

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16440

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16442

	namespace Texture2D {
		constexpr const static size_t ctor = 0xae91e30;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define RenderTexture_TypeDefinitionIndex 16447

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xae9ab10;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 16917

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xaeddcb0;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 16893

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xaed7d20;
	}

#define ComputeBuffer_TypeDefinitionIndex 16582

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xaebbd00;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xaebbf50;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16386

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae82df0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xae82b20;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex -1

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xaf003d0;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16359

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16470

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

#define Screen_TypeDefinitionIndex 16356

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

#define Application_TypeDefinitionIndex 16302

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define BaseNetworkable_TypeDefinitionIndex 4618

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x28;
		constexpr const static size_t parentEntity = 0x60;
		constexpr const static size_t children = 0x50;
	}

	// obf name: ::%dc2db299def2b441d24fbdbf718467342cd96c18
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%dc2db299def2b441d24fbdbf718467342cd96c18"
#define BaseNetworkable_Static_ClassNameShort "%dc2db299def2b441d24fbdbf718467342cd96c18"
#define BaseNetworkable_Static_TypeDefinitionIndex 4617

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x18;
	}

	// obf name: ::%ce43eb5300c8064b6297f5a6e29f3868c1e37d31
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%ce43eb5300c8064b6297f5a6e29f3868c1e37d31"
#define BaseNetworkable_EntityRealm_ClassNameShort "%ce43eb5300c8064b6297f5a6e29f3868c1e37d31"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 4615

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x32ee630;
	}

	// obf name: ::%a1ab65a8cdd831bfa87e0bf8614454d03f3c111d
#define System_ListDictionary_ClassName "%a1ab65a8cdd831bfa87e0bf8614454d03f3c111d<%9b1f6663473d97d360b712eb419b8a256976bbd3,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%a1ab65a8cdd831bfa87e0bf8614454d03f3c111d"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x759da10;
		constexpr const static size_t TryGetValue_methodinfo = 0xd29cc40;
	}

	// obf name: ::%de9766e8f2a667fbc27349e552f91cf6d65fec84
#define System_BufferList_ClassName "%de9766e8f2a667fbc27349e552f91cf6d65fec84<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%de9766e8f2a667fbc27349e552f91cf6d65fec84"
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

#define Model_TypeDefinitionIndex 1681

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 5045

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa0;
		constexpr const static size_t model = 0xc8;
		constexpr const static size_t flags = 0xd0;
		constexpr const static size_t triggers = 0x80;
		constexpr const static size_t positionLerp = 0x160;

		// Functions
		constexpr const static size_t ServerRPC = 0x3783dd0;
		constexpr const static size_t FindBone = 0x37783b0;
		constexpr const static size_t GetWorldVelocity = 0x3790590;
		constexpr const static size_t GetParentVelocity = 0x377f730;
	}

	// obf name: ::%8b23cb037e0040f1dfb7f7884b2b057b83af96fd
#define PositionLerp_ClassName "%8b23cb037e0040f1dfb7f7884b2b057b83af96fd"
#define PositionLerp_ClassNameShort "%8b23cb037e0040f1dfb7f7884b2b057b83af96fd"
#define PositionLerp_TypeDefinitionIndex 2514

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x18;
	}

	// obf name: ::%1e58520cbf75e061ec1fbe00ead78ca5831f06eb
#define Interpolator_ClassName "%1e58520cbf75e061ec1fbe00ead78ca5831f06eb<%c8de7afb4161119267a3bad4c4212bac35ee1c5c>"
#define Interpolator_ClassNameShort "%1e58520cbf75e061ec1fbe00ead78ca5831f06eb"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 5074

	namespace BaseCombatEntity {

		// Offsets
		constexpr const static size_t skeletonProperties = 0x1c0;
		constexpr const static size_t baseProtection = 0x1c8;
		constexpr const static size_t lifestate = 0x234;
		constexpr const static size_t markAttackerHostile = 0x23a;
		constexpr const static size_t _health = 0x23c;
		constexpr const static size_t _maxHealth = 0x240;
		constexpr const static size_t lastNotifyFrame = 0x24c;
	}

#define SkeletonProperties_TypeDefinitionIndex 3035

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 3033

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t name = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 6073

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 6072

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%237ac44afdcdd3ab4728730a92244c60b33ff535
#define DamageTypeList_ClassName "%237ac44afdcdd3ab4728730a92244c60b33ff535"
#define DamageTypeList_ClassNameShort "%237ac44afdcdd3ab4728730a92244c60b33ff535"
#define DamageTypeList_TypeDefinitionIndex 825

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 530

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 3982

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x40;
		constexpr const static size_t iconSprite = 0x50;
		constexpr const static size_t category = 0x58;
		constexpr const static size_t stackable = 0x70;
		constexpr const static size_t rarity = 0x88;
		constexpr const static size_t ItemModWearable = 0x150;
	}

#define RecoilProperties_TypeDefinitionIndex 4716

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 6821

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 5229

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x238;
		constexpr const static size_t repeatDelay = 0x23c;
		constexpr const static size_t animationDelay = 0x240;
		constexpr const static size_t noHeadshots = 0x28e;
		constexpr const static size_t nextAttackTime = 0x290;
		constexpr const static size_t timeSinceDeploy = 0x2a8;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x39ed400;
		constexpr const static size_t StartAttackCooldown = 0x39ea8e0;
	}

#define BaseProjectile_TypeDefinitionIndex 6825

	namespace BaseProjectile {

		// Offsets
		constexpr const static size_t projectileVelocityScale = 0x2dc;
		constexpr const static size_t automatic = 0x2e0;
		constexpr const static size_t reloadTime = 0x320;
		constexpr const static size_t primaryMagazine = 0x328;
		constexpr const static size_t fractionalReload = 0x330;
		constexpr const static size_t aimSway = 0x344;
		constexpr const static size_t aimSwaySpeed = 0x348;
		constexpr const static size_t recoil = 0x350;
		constexpr const static size_t aimconeCurve = 0x358;
		constexpr const static size_t aimCone = 0x360;
		constexpr const static size_t hipAimCone = 0x364;
		constexpr const static size_t noAimingWhileCycling = 0x37d;
		constexpr const static size_t isBurstWeapon = 0x382;
		constexpr const static size_t cachedModHash = 0x3b4;
		constexpr const static size_t sightAimConeScale = 0x3b8;
		constexpr const static size_t sightAimConeOffset = 0x3bc;
		constexpr const static size_t hipAimConeScale = 0x3c0;
		constexpr const static size_t hipAimConeOffset = 0x3c4;

		// Functions
		constexpr const static size_t LaunchProjectile = 0x4a8ced0;
		constexpr const static size_t LaunchProjectileClientSide = 0x4ab77c0;
		constexpr const static size_t ScaleRepeatDelay = 0x4a9dff0;
		constexpr const static size_t GetAimCone = 0x4a96910;
		constexpr const static size_t GetAimCone_vtableoff = 0x3c48;
		constexpr const static size_t UpdateAmmoDisplay = 0x4a8abe0;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3a98;
	}

#define BaseLauncher_TypeDefinitionIndex 2408

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 4601

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%d54c95bc61fb8d642f2476db565e2fc5821e9bdd
#define HitTest_ClassName "%d54c95bc61fb8d642f2476db565e2fc5821e9bdd"
#define HitTest_ClassNameShort "%d54c95bc61fb8d642f2476db565e2fc5821e9bdd"
#define HitTest_TypeDefinitionIndex 4932

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x5c;
		constexpr const static size_t AttackRay = 0x60;
		constexpr const static size_t RayHit = 0x80;
		constexpr const static size_t damageProperties = 0x38;
		constexpr const static size_t gameObject = 0x10;
		constexpr const static size_t collider = 0xb8;
		constexpr const static size_t ignoredTypes = 0xb0;
		constexpr const static size_t HitTransform = 0x78;
		constexpr const static size_t HitPart = 0x1c;
		constexpr const static size_t HitMaterial = 0x40;
		constexpr const static size_t DidHit = 0xcc;
		constexpr const static size_t MaxDistance = 0xac;
		constexpr const static size_t HitNormal = 0x50;
		constexpr const static size_t HitPoint = 0xc0;
		constexpr const static size_t HitEntity = 0x20;
		constexpr const static size_t ignoreEntity = 0x30;
	}

#define Projectile_TypeDefinitionIndex 2018

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
		constexpr const static size_t sourceProjectilePrefab = 0x1e0;
		constexpr const static size_t mod = 0x1d0;
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
		constexpr const static size_t CalculateEffectScale = 0x151c8d0;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x338;
		constexpr const static size_t SetEffectScale = 0x152b3e0;
		constexpr const static size_t UpdateVelocity = 0x1544600;
		constexpr const static size_t Retire = 0x1503de0;
		constexpr const static size_t DoHit = 0x1505470;
	}

	// obf name: ::%90fb2dccf107b35284f5a3ab6166d372def3fe0d
#define HitInfo_ClassName "%90fb2dccf107b35284f5a3ab6166d372def3fe0d"
#define HitInfo_ClassNameShort "%90fb2dccf107b35284f5a3ab6166d372def3fe0d"
#define HitInfo_TypeDefinitionIndex 2810

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0xe8;
		constexpr const static size_t damageTypes = 0xd0;

		// Functions
		constexpr const static size_t get_boneArea = 0x1f34ec0;
	}

	// obf name: ::%bdd687ce65bbe5af5eb8423edaba96cb78236a49
#define GameTrace_ClassName "%bdd687ce65bbe5af5eb8423edaba96cb78236a49"
#define GameTrace_ClassNameShort "%bdd687ce65bbe5af5eb8423edaba96cb78236a49"
#define GameTrace_TypeDefinitionIndex 1800

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x1250f20;
	}

#define BaseMelee_TypeDefinitionIndex 2387

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d0;
		constexpr const static size_t maxDistance = 0x2e8;
		constexpr const static size_t attackRadius = 0x2ec;
		constexpr const static size_t blockSprintOnAttack = 0x2f1;
		constexpr const static size_t gathering = 0x320;
		constexpr const static size_t canThrowAsProjectile = 0x329;

		// Functions
		constexpr const static size_t ProcessAttack = 0x197a9f0;
		constexpr const static size_t DoThrow = 0x1970bd0;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 2337

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x400;
		constexpr const static size_t strikeRecoil = 0x408;
		constexpr const static size_t _didSparkThisFrame = 0x410;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 2377

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x418;
		constexpr const static size_t stringBonusVelocity = 0x424;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x18e6cb0;
	}

	// obf name: ::%24bcc726eb36591b001016cae68ad7e7e1a5968e
#define ItemContainer_ClassName "%24bcc726eb36591b001016cae68ad7e7e1a5968e"
#define ItemContainer_ClassNameShort "%24bcc726eb36591b001016cae68ad7e7e1a5968e"
#define ItemContainer_TypeDefinitionIndex 1044

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x68;
		constexpr const static size_t itemList = 0x38;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x513fa60;
	}

#define PlayerLoot_TypeDefinitionIndex 4549

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 1285

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerMain = 0x30;
		constexpr const static size_t containerBelt = 0x58;
		constexpr const static size_t containerWear = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x52f1290;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 5325

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x3ae7c30;
		constexpr const static size_t get_rotation = 0x3af8600;
		constexpr const static size_t set_rotation = 0x3ae1f40;
		constexpr const static size_t HeadForward = 0x3ae9d50;
	}

	// obf name: ::%721c70f6ee0dd962dbe0f008ac4f185a650a5112
#define PlayerEyes_Static_ClassName "PlayerEyes/%721c70f6ee0dd962dbe0f008ac4f185a650a5112"
#define PlayerEyes_Static_ClassNameShort "%721c70f6ee0dd962dbe0f008ac4f185a650a5112"
#define PlayerEyes_Static_TypeDefinitionIndex 5324

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0xd0;
	}

	// obf name: ::%04ba682284111054cf2a6978ea368b69c3e63f70
#define PlayerBelt_ClassName "%04ba682284111054cf2a6978ea368b69c3e63f70"
#define PlayerBelt_ClassNameShort "%04ba682284111054cf2a6978ea368b69c3e63f70"
#define PlayerBelt_TypeDefinitionIndex 5280

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x3a6ddf0;
		constexpr const static size_t GetActiveItem = 0x3a6bdc0;
	}

	// obf name: ::%dae9228d279381653e8a7c9e1c1cdee4ad61a920
#define LocalPlayer_ClassName "%dae9228d279381653e8a7c9e1c1cdee4ad61a920"
#define LocalPlayer_ClassNameShort "%dae9228d279381653e8a7c9e1c1cdee4ad61a920"
#define LocalPlayer_TypeDefinitionIndex 1426

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x54562a0;
		constexpr const static size_t MoveItem = 0x543dac0;
		constexpr const static size_t get_Entity = 0x5452430;
	}

	// obf name: ::%24d67c78a142a5c3acf22f14ddcf5eed408eb599
#define LocalPlayer_Static_ClassName "%dae9228d279381653e8a7c9e1c1cdee4ad61a920/%24d67c78a142a5c3acf22f14ddcf5eed408eb599"
#define LocalPlayer_Static_ClassNameShort "%24d67c78a142a5c3acf22f14ddcf5eed408eb599"
#define LocalPlayer_Static_TypeDefinitionIndex 1425

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x90;
	}

	// obf name: ::%49ce359e65aaa55d5b8f054e1812bfba63701fa3
#define BasePlayer_Static_ClassName "BasePlayer/%49ce359e65aaa55d5b8f054e1812bfba63701fa3"
#define BasePlayer_Static_ClassNameShort "%49ce359e65aaa55d5b8f054e1812bfba63701fa3"
#define BasePlayer_Static_TypeDefinitionIndex 2552

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x1370;
	}

#define BasePlayer_TypeDefinitionIndex 2553

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x598;
		constexpr const static size_t input = 0x410;
		constexpr const static size_t movement = 0x298;
		constexpr const static size_t currentTeam = 0x460;
		constexpr const static size_t clActiveItem = 0x490;
		constexpr const static size_t modelState = 0x500;
		constexpr const static size_t playerFlags = 0x588;
		constexpr const static size_t eyes = 0x348;
		constexpr const static size_t playerRigidbody = 0x2e0;
		constexpr const static size_t userID = 0x5d0;
		constexpr const static size_t UserIDString = 0x5f0;
		constexpr const static size_t inventory = 0x528;
		constexpr const static size_t _displayName = 0x358;
		constexpr const static size_t _lookingAt = 0x288;
		constexpr const static size_t lastSentTickTime = 0x544;
		constexpr const static size_t lastSentTick = 0x320;
		constexpr const static size_t mounted = 0x4d0;
		constexpr const static size_t Belt = 0x2f8;
		constexpr const static size_t _lookingAtEntity = 0x260;
		constexpr const static size_t currentGesture = 0x5b8;
		constexpr const static size_t weaponMoveSpeedScale = 0x660;
		constexpr const static size_t clothingBlocksAiming = 0x664;
		constexpr const static size_t clothingMoveSpeedReduction = 0x668;
		constexpr const static size_t clothingWaterSpeedBonus = 0x66c;
		constexpr const static size_t equippingBlocked = 0x674;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x1b61e80;
		constexpr const static size_t Menu_AssistPlayer = 0x1bb51d0;
		constexpr const static size_t OnViewModeChanged = 0x1af8e50;
		constexpr const static size_t ChatMessage = 0x1af27a0;
		constexpr const static size_t IsOnGround = 0x1aa0d80;
		constexpr const static size_t GetSpeed = 0x1b2f1d0;
		constexpr const static size_t SendProjectileUpdate = 0x1b271c0;
		constexpr const static size_t SendProjectileAttack = 0x1ae1350;
		constexpr const static size_t CanBuild = 0x1aa2300;
		constexpr const static size_t GetMounted = 0x1ab1bf0;
		constexpr const static size_t GetHeldEntity = 0x1b5a4f0;
		constexpr const static size_t get_inventory = 0x1ab1910;
		constexpr const static size_t get_eyes = 0x1ba6f60;
		constexpr const static size_t SendClientTick = 0x1b77620;
		constexpr const static size_t ClientInput = 0x1b690f0;
		constexpr const static size_t ClientInput_vtableoff = 0x3a68;
		constexpr const static size_t MaxHealth = 0x1c124b0;
		constexpr const static size_t MaxHealth_vtableoff = 0x2da8;
		constexpr const static size_t OnAttacked = 0x1b6b130;
		constexpr const static size_t OnAttacked_vtableoff = 0x1438;
	}

#define ScientistNPC_TypeDefinitionIndex 6333

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 1330

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 5076

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 4340

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 2807

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 5051

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 3192

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x226c930;
		constexpr const static size_t BlockSprint = 0x2278810;
		constexpr const static size_t GroundCheck = 0x22a8320;
		constexpr const static size_t ClientInput = 0x22a3220;
		constexpr const static size_t ClientInput_vtableoff = 0x358;
		constexpr const static size_t DoFixedUpdate = 0x227aa70;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x2d8;
		constexpr const static size_t FrameUpdate = 0x22a5c60;
		constexpr const static size_t FrameUpdate_vtableoff = 0x178;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 4797

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x370;
		constexpr const static size_t cachedProtectedMinutes = 0x378;
	}

#define WorldItem_TypeDefinitionIndex 3267

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a0;
		constexpr const static size_t item = 0x1a8;
	}

#define HackableLockedCrate_TypeDefinitionIndex 1384

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x388;
		constexpr const static size_t hackSeconds = 0x398;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 6391

	namespace ProjectileWeaponMod {

		// Offsets
		constexpr const static size_t repeatDelay = 0x1c0;
		constexpr const static size_t projectileVelocity = 0x1cc;
		constexpr const static size_t projectileDamage = 0x1d8;
		constexpr const static size_t projectileDistance = 0x1e4;
		constexpr const static size_t aimsway = 0x1f0;
		constexpr const static size_t aimswaySpeed = 0x1fc;
		constexpr const static size_t recoil = 0x208;
		constexpr const static size_t sightAimCone = 0x214;
		constexpr const static size_t hipAimCone = 0x220;
	}

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 6387

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%0dae8e545294c734898c8c05d2126f734d521ae4
#define ConsoleSystem_ClassName "%0dae8e545294c734898c8c05d2126f734d521ae4"
#define ConsoleSystem_ClassNameShort "%0dae8e545294c734898c8c05d2126f734d521ae4"
#define ConsoleSystem_TypeDefinitionIndex -1

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x6423690;
	}

#define ConsoleSystem_Option_ClassName "%0dae8e545294c734898c8c05d2126f734d521ae4/%2d16223d85bc4e9bade1fbfafeb0e68d0802f032"
#define ConsoleSystem_Option_ClassNameShort "%2d16223d85bc4e9bade1fbfafeb0e68d0802f032"
#define ConsoleSystem_Command_ClassName "%0dae8e545294c734898c8c05d2126f734d521ae4/%cb2408388b3b989db42a2ace9ee1e75363e01bfa"
#define ConsoleSystem_Command_ClassNameShort "%cb2408388b3b989db42a2ace9ee1e75363e01bfa"
	// obf name: ::%3e965f9791f5bb1fb83521f693df06bfa236cbd7
#define ConsoleSystem_Index_Static_ClassName "%0dae8e545294c734898c8c05d2126f734d521ae4/%4293fd322a2a993962e5efeae45a1b23aa7db333.%3e965f9791f5bb1fb83521f693df06bfa236cbd7"
#define ConsoleSystem_Index_Static_ClassNameShort "%3e965f9791f5bb1fb83521f693df06bfa236cbd7"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex -1

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0xa8;
	}

	// obf name: ::%b13d65e04876c31baca9c1a2009203103201d163
#define ConsoleSystem_Arg_ClassName "%0dae8e545294c734898c8c05d2126f734d521ae4/%b13d65e04876c31baca9c1a2009203103201d163"
#define ConsoleSystem_Arg_ClassNameShort "%b13d65e04876c31baca9c1a2009203103201d163"
// obf name: ::%3bbd2bce447cf359b084528ba2b0f778f4a6e6da
#define Facepunch_Network_SteamNetworking_ClassName "%3bbd2bce447cf359b084528ba2b0f778f4a6e6da"
#define Facepunch_Network_SteamNetworking_ClassNameShort "%3bbd2bce447cf359b084528ba2b0f778f4a6e6da"
#define LootableCorpse_TypeDefinitionIndex 1497

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2a8;
		constexpr const static size_t _playerName = 0x2b8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 5540

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x278;
		constexpr const static size_t _playerName = 0x260;
	}

#define MainCamera_TypeDefinitionIndex 7

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x88;
		constexpr const static size_t mainCameraTransform = 0x28;

		// Functions
		constexpr const static size_t Update = 0xe569c0;
		constexpr const static size_t OnPreCull = 0xe57800;
		constexpr const static size_t Trace = 0xe60e70;
	}

#define CameraMan_TypeDefinitionIndex 5973

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%e69c58cc6d038b2f0eeb6e36ebc2f29a6877beb9
#define PlayerTick_ClassName "%e69c58cc6d038b2f0eeb6e36ebc2f29a6877beb9"
#define PlayerTick_ClassNameShort "%e69c58cc6d038b2f0eeb6e36ebc2f29a6877beb9"
#define PlayerTick_TypeDefinitionIndex 7365

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x48;
		constexpr const static size_t modelState = 0x40;
		constexpr const static size_t activeItem = 0x38;
		constexpr const static size_t parentID = 0x30;
		constexpr const static size_t position = 0x24;
		constexpr const static size_t eyePos = 0x18;
	}

	// obf name: ::%8efdb27de453c3fe6facd0d001d71d4be981f718
#define InputMessage_ClassName "%8efdb27de453c3fe6facd0d001d71d4be981f718"
#define InputMessage_ClassNameShort "%8efdb27de453c3fe6facd0d001d71d4be981f718"
#define InputMessage_TypeDefinitionIndex 7554

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x14;
		constexpr const static size_t aimAngles = 0x18;
		constexpr const static size_t mouseDelta = 0x28;
	}

	// obf name: ::%29aaaea41b278e8b1a27d896f74919dcc6414fcc
#define InputState_ClassName "%29aaaea41b278e8b1a27d896f74919dcc6414fcc"
#define InputState_ClassNameShort "%29aaaea41b278e8b1a27d896f74919dcc6414fcc"
#define InputState_TypeDefinitionIndex 440

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x20;
	}

#define PlayerInput_TypeDefinitionIndex 2436

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%f4af65ad4e36dcb1d47765de098f32c7b6902fb3
#define ModelState_ClassName "%f4af65ad4e36dcb1d47765de098f32c7b6902fb3"
#define ModelState_ClassNameShort "%f4af65ad4e36dcb1d47765de098f32c7b6902fb3"
#define ModelState_TypeDefinitionIndex 7266

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x54;
		constexpr const static size_t waterLevel = 0x78;
		constexpr const static size_t lookDir = 0x6c;
	}

	// obf name: ::%f9a122823de396ece656a8126b02b25b3914eaa4
#define Item_ClassName "%f9a122823de396ece656a8126b02b25b3914eaa4"
#define Item_ClassNameShort "%f9a122823de396ece656a8126b02b25b3914eaa4"
#define Item_TypeDefinitionIndex 2728

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x40;
		constexpr const static size_t uid = 0x28;
		constexpr const static size_t _condition = 0x20;
		constexpr const static size_t _maxCondition = 0x48;
		constexpr const static size_t amount = 0x24;
		constexpr const static size_t position = 0x98;
		constexpr const static size_t parent = 0x38;
		constexpr const static size_t contents = 0x70;
		constexpr const static size_t heldEntity = 0xa0;
		constexpr const static size_t worldEnt = 0xd8;

		// Functions
		constexpr const static size_t get_iconSprite = 0x1e5e620;
	}

	// obf name: ::%f5d1ca911f6c73b58d14a137e4227d839e363c91
#define WaterLevel_ClassName "%f5d1ca911f6c73b58d14a137e4227d839e363c91"
#define WaterLevel_ClassNameShort "%f5d1ca911f6c73b58d14a137e4227d839e363c91"
#define WaterLevel_TypeDefinitionIndex 4596

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x32aca30;
		constexpr const static size_t GetWaterLevel = 0x32aec00;
	}

	// obf name: ::%14995540122101da228dc3fe66bdc14b5c32c20a
#define ConVar_Graphics_Static_ClassName "%0acbe7ee85ad0a12ae31a9a8e26ce642329ddd55/%14995540122101da228dc3fe66bdc14b5c32c20a"
#define ConVar_Graphics_Static_ClassNameShort "%14995540122101da228dc3fe66bdc14b5c32c20a"
#define ConVar_Graphics_Static_TypeDefinitionIndex 1795

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x474;

		// Functions
		constexpr const static size_t _fov_getter = 0x2a76210;
		constexpr const static size_t _fov_setter = 0x2a71360;
	}

#define BaseFishingRod_TypeDefinitionIndex 6194

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x258;
		constexpr const static size_t currentBobber = 0x260;
		constexpr const static size_t MaxCastDistance = 0x27c;
		constexpr const static size_t BobberPreview = 0x288;
		constexpr const static size_t clientStrainAmountNormalised = 0x2c8;
		constexpr const static size_t strainGainMod = 0x2e8;
		constexpr const static size_t aimAnimationReady = 0x2e0;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x444d5d0;
		constexpr const static size_t EvaluateFishingPosition = 0x44591a0;
	}

#define FishingBobber_TypeDefinitionIndex 7097

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x278;
	}

#define GameManifest_TypeDefinitionIndex 2044

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x156ac80;
	}

	// obf name: ::%3ea5b21218063f4046c888f1609ff7d5deea6e60
#define GameManager_ClassName "%3ea5b21218063f4046c888f1609ff7d5deea6e60"
#define GameManager_ClassNameShort "%3ea5b21218063f4046c888f1609ff7d5deea6e60"
#define GameManager_TypeDefinitionIndex 4998

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x28;

		// Functions
		constexpr const static size_t CreatePrefab = 0x373a6f0;
	}

	// obf name: ::%388c0eb7bb2e35d3b931be2e6b55b9cee2bf0d15
#define GameManager_Static_ClassName "%3ea5b21218063f4046c888f1609ff7d5deea6e60/%388c0eb7bb2e35d3b931be2e6b55b9cee2bf0d15"
#define GameManager_Static_ClassNameShort "%388c0eb7bb2e35d3b931be2e6b55b9cee2bf0d15"
#define GameManager_Static_TypeDefinitionIndex 4997

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x20;
	}

	// obf name: ::%e191b5d449284a4dc14185ad7e04c3fd735e3ea0
#define PrefabPoolCollection_ClassName "%e191b5d449284a4dc14185ad7e04c3fd735e3ea0"
#define PrefabPoolCollection_ClassNameShort "%e191b5d449284a4dc14185ad7e04c3fd735e3ea0"
#define PrefabPoolCollection_TypeDefinitionIndex 3160

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%60ef65dac0e537007b8e0d58170d9843e3b6c026
#define PrefabPool_ClassName "%60ef65dac0e537007b8e0d58170d9843e3b6c026"
#define PrefabPool_ClassNameShort "%60ef65dac0e537007b8e0d58170d9843e3b6c026"
#define PrefabPool_TypeDefinitionIndex 3099

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x28;
	}

#define ItemModProjectile_TypeDefinitionIndex 1208

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

#define CraftingQueue_TypeDefinitionIndex 6350

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%16eb171129bd8811aff31e839af0e8c5b297f088
#define CraftingQueue_Static_ClassName "CraftingQueue/%16eb171129bd8811aff31e839af0e8c5b297f088"
#define CraftingQueue_Static_ClassNameShort "%16eb171129bd8811aff31e839af0e8c5b297f088"
#define CraftingQueue_Static_TypeDefinitionIndex 6349

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x30;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 115

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%d467701fc69383a965acac5294f51f68199c4013
#define Planner_Static_ClassName "Planner/%d467701fc69383a965acac5294f51f68199c4013"
#define Planner_Static_ClassNameShort "%d467701fc69383a965acac5294f51f68199c4013"
#define Planner_Static_TypeDefinitionIndex 4828

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0xf0;
	}

	// obf name: ::%0bc102853696e19dc9ece74d93a12fd645b51443
#define Planner_Guide_ClassName "Planner/%0bc102853696e19dc9ece74d93a12fd645b51443"
#define Planner_Guide_ClassNameShort "%0bc102853696e19dc9ece74d93a12fd645b51443"
#define Planner_Guide_TypeDefinitionIndex 4824

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x28;
	}

#define Planner_TypeDefinitionIndex 4829

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x280;
	}

#define Construction_TypeDefinitionIndex 4208

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x170;
	}

#define BuildingBlock_TypeDefinitionIndex 1021

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2f8;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 4011

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x218;
		constexpr const static size_t _punches = 0x1c0;
		constexpr const static size_t viewModel = 0x220;

		// Functions
		constexpr const static size_t OnDeploy = 0x2ccc110;
	}

	// obf name: ::%e02d92c08f7348bbcc6b39317d10c63f97392305
#define PunchEntry_ClassName "HeldEntity/%e02d92c08f7348bbcc6b39317d10c63f97392305"
#define PunchEntry_ClassNameShort "%e02d92c08f7348bbcc6b39317d10c63f97392305"
#define PunchEntry_TypeDefinitionIndex 4009

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x28;
		constexpr const static size_t startTime = 0x2c;
		constexpr const static size_t amountAdded = 0x10;
		constexpr const static size_t amount = 0x1c;
	}

#define IronSights_TypeDefinitionIndex 1422

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 1925

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 2888

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xe8;
		constexpr const static size_t model = 0x88;
		constexpr const static size_t lower = 0xa0;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x200cc40;
	}

#define ViewModel_TypeDefinitionIndex 6703

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x4960a30;
		constexpr const static size_t PlayString = 0x4961d40;
	}

#define MedicalTool_TypeDefinitionIndex 830

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f0;
	}

#define WaterBody_TypeDefinitionIndex 5299

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x58;
	}

	// obf name: ::%4fef67fe46d5174b15c0d35c3726e6c8fdecd4d1
#define WaterSystem_Static_ClassName "WaterSystem/%4fef67fe46d5174b15c0d35c3726e6c8fdecd4d1"
#define WaterSystem_Static_ClassNameShort "%4fef67fe46d5174b15c0d35c3726e6c8fdecd4d1"
#define WaterSystem_Static_TypeDefinitionIndex 6572

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x1b8;
	}

#define WaterSystem_TypeDefinitionIndex 6573

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x47c6270;
	}

#define TerrainMeta_TypeDefinitionIndex 3236

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x4a8;
		constexpr const static size_t HeightMap = 0xc8;
		constexpr const static size_t SplatMap = 0x510;
		constexpr const static size_t TopologyMap = 0x660;
		constexpr const static size_t Texturing = 0x5c8;
	}

#define TerrainCollision_TypeDefinitionIndex 4930

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x360e500;
	}

#define TerrainHeightMap_TypeDefinitionIndex 2356

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 5943

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 588

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%a33b5cd2c6a2988aa15225def2262dd7435177eb
#define World_Static_ClassName "%c04d64f3bd4d6444a677ee15191011803e77ff54/%a33b5cd2c6a2988aa15225def2262dd7435177eb"
#define World_Static_ClassNameShort "%a33b5cd2c6a2988aa15225def2262dd7435177eb"
#define World_Static_TypeDefinitionIndex 6661

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0xc8;
	}

#define ItemIcon_TypeDefinitionIndex 1963

	namespace ItemIcon {

		// Functions
		constexpr const static size_t TryToMove = 0x1453f50;
		constexpr const static size_t TryToMove_vtableoff = 0x348;
		constexpr const static size_t RunTimedAction = 0x1455ec0;
	}

	// obf name: ::%ff24610a22f725dd8f3788ab4f9dcc3a2935031c
#define ItemIcon_Static_ClassName "ItemIcon/%ff24610a22f725dd8f3788ab4f9dcc3a2935031c"
#define ItemIcon_Static_ClassNameShort "%ff24610a22f725dd8f3788ab4f9dcc3a2935031c"
#define ItemIcon_Static_TypeDefinitionIndex 1962

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x28;
	}

	// obf name: ::%17aac5530ef51678ba8e6f246b2cc6a3074a5a53
#define Effect_ClassName "%17aac5530ef51678ba8e6f246b2cc6a3074a5a53"
#define Effect_ClassNameShort "%17aac5530ef51678ba8e6f246b2cc6a3074a5a53"
#define Effect_TypeDefinitionIndex 1248

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0xa0;
		constexpr const static size_t worldPos = 0x90;
	}

	// obf name: ::%74af204d7bda6af478a5530695d6acc8ed075792
#define EffectNetwork_ClassName "%74af204d7bda6af478a5530695d6acc8ed075792"
#define EffectNetwork_ClassNameShort "%74af204d7bda6af478a5530695d6acc8ed075792"
#define EffectNetwork_TypeDefinitionIndex 1534

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%f0a00b288dfe4b015a8bce078d907e8ef4481d32
#define EffectNetwork_Static_ClassName "%74af204d7bda6af478a5530695d6acc8ed075792/%f0a00b288dfe4b015a8bce078d907e8ef4481d32"
#define EffectNetwork_Static_ClassNameShort "%f0a00b288dfe4b015a8bce078d907e8ef4481d32"
#define EffectNetwork_Static_TypeDefinitionIndex 1533

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x10;

		// Functions
		constexpr const static size_t cctor = 0xefb9d0;
	}

#define BuildingBlock_TypeDefinitionIndex 1021

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2e8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x50af4c0;
		constexpr const static size_t HasUpgradePrivilege = 0x50c5750;
		constexpr const static size_t CanAffordUpgrade = 0x50e1fa0;
	}

	// obf name: ::%dd7fe3d2fbb42db542db1041edf3826867fe0ebf
#define GameObjectEx_ClassName "%dd7fe3d2fbb42db542db1041edf3826867fe0ebf"
#define GameObjectEx_ClassNameShort "%dd7fe3d2fbb42db542db1041edf3826867fe0ebf"
#define GameObjectEx_TypeDefinitionIndex 774

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x4e909d0;
	}

#define UIDeathScreen_TypeDefinitionIndex 1833

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x13269c0;
	}

	// obf name: ::%d2c6a6483822e65b138992d477a39d0197fc7b37
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%d2c6a6483822e65b138992d477a39d0197fc7b37"
#define BaseScreenShake_Static_ClassNameShort "%d2c6a6483822e65b138992d477a39d0197fc7b37"
#define BaseScreenShake_Static_TypeDefinitionIndex 4622

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x30;
	}

#define FlashbangOverlay_TypeDefinitionIndex 5077

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%7fb2a517017aaf79855923c32cf5779d287bd285
#define StringPool_ClassName "%7fb2a517017aaf79855923c32cf5779d287bd285"
#define StringPool_ClassNameShort "%7fb2a517017aaf79855923c32cf5779d287bd285"
#define StringPool_TypeDefinitionIndex 1006

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x38;

		// Functions
		constexpr const static size_t Get = 0x50e9780;
	}

	// obf name: ::%ec88aaca64a700f6b479c8e20475be324578e546
#define Network_Networkable_ClassName "%ec88aaca64a700f6b479c8e20475be324578e546"
#define Network_Networkable_ClassNameShort "%ec88aaca64a700f6b479c8e20475be324578e546"
#define Network_Networkable_TypeDefinitionIndex 19071

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x38;
	}

	// obf name: ::%8cd8eb7062d954b8035b7811bb1bc285b69102a1
#define Network_Net_ClassName "%8cd8eb7062d954b8035b7811bb1bc285b69102a1"
#define Network_Net_ClassNameShort "%8cd8eb7062d954b8035b7811bb1bc285b69102a1"
#define Network_Net_TypeDefinitionIndex 8089

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x90;
	}

	// obf name: ::%e4f51630e2f6aa9ebc816e4d10ea51c1346d91a6
#define Network_Client_ClassName "%e4f51630e2f6aa9ebc816e4d10ea51c1346d91a6"
#define Network_Client_ClassNameShort "%e4f51630e2f6aa9ebc816e4d10ea51c1346d91a6"
#define Network_Client_TypeDefinitionIndex 19025

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0x110;
		constexpr const static size_t ConnectedPort = 0xe8;
		constexpr const static size_t ServerName = 0xf0;
		constexpr const static size_t ConnectedAddress = 0x118;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x64a3050;
		constexpr const static size_t DestroyNetworkable = 0x64a2650;
	}

	// obf name: ::%94590c01fe1f394c39b4a00b7edad38adac7fa30
#define Network_BaseNetwork_ClassName "%94590c01fe1f394c39b4a00b7edad38adac7fa30"
#define Network_BaseNetwork_ClassNameShort "%94590c01fe1f394c39b4a00b7edad38adac7fa30"
#define Network_BaseNetwork_TypeDefinitionIndex 19031

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x6492ef0;
	}

	// obf name: ::%8c0e7101910ea49ed5c07ba1cdd97767536738d1
#define Network_SendInfo_ClassName "%8c0e7101910ea49ed5c07ba1cdd97767536738d1"
#define Network_SendInfo_ClassNameShort "%8c0e7101910ea49ed5c07ba1cdd97767536738d1"
#define Network_SendInfo_TypeDefinitionIndex 19070

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%7735972bec1efd690e1c6bd7030cef12b8013257
#define Network_Message_ClassName "%7735972bec1efd690e1c6bd7030cef12b8013257"
#define Network_Message_ClassNameShort "%7735972bec1efd690e1c6bd7030cef12b8013257"
#define Network_Message_TypeDefinitionIndex 19077

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%a4ecda0a8829deda823c0a147c2aedc615dbb15d
#define Network_NetRead_ClassName "%a4ecda0a8829deda823c0a147c2aedc615dbb15d"
#define Network_NetRead_ClassNameShort "%a4ecda0a8829deda823c0a147c2aedc615dbb15d"
#define Network_NetRead_TypeDefinitionIndex 19065

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x38;
	}

	// obf name: ::%d122137b7f61a28a481ef380ecde9db7b86267d3
#define Network_NetWrite_ClassName "%d122137b7f61a28a481ef380ecde9db7b86267d3"
#define Network_NetWrite_ClassNameShort "%d122137b7f61a28a481ef380ecde9db7b86267d3"
#define Network_NetWrite_TypeDefinitionIndex 19049

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x40;

		// Functions
		constexpr const static size_t WriteByte = 0x64bac10;
		constexpr const static size_t String = 0x64be090;
		constexpr const static size_t Send = 0x64bad80;
	}

#define LootPanel_TypeDefinitionIndex 5050

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x3804af0;
	}

#define UIInventory_TypeDefinitionIndex 5884

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x413dec0;
	}

#define GrowableEntity_TypeDefinitionIndex 3835

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2b0;
		constexpr const static size_t State = 0x2c0;
	}

#define PlantProperties_TypeDefinitionIndex 3802

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 3801

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 20822

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 7897

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
		constexpr const static size_t get_Instance = 0x926cd0;
	}

	// obf name: ::%4f4a25a2c95f48d45277446d1db289849e6d8e55
#define TOD_Sky_Static_ClassName "TOD_Sky/%4f4a25a2c95f48d45277446d1db289849e6d8e55"
#define TOD_Sky_Static_ClassNameShort "%4f4a25a2c95f48d45277446d1db289849e6d8e55"
#define TOD_Sky_Static_TypeDefinitionIndex 7896

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0xa0;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 8022

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0x96c5e0;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9517

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9647

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8395

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
	}

#define TOD_StarParameters_TypeDefinitionIndex 9251

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 8050

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 7846

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 4213

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 1663

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 1632

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 3253

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

#define EnvironmentManager_TypeDefinitionIndex 2119

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x1642680;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%92b975167988226e75b7c92829ad5d43e8a28228/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex -1

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 5506

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 5507

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 6672

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

	// obf name: ::%c32d63f42c34e7e1184b08c360cb699530e70b84
#define ListHashSet_ClassName "%c32d63f42c34e7e1184b08c360cb699530e70b84<UIChat>"
#define ListHashSet_ClassNameShort "%c32d63f42c34e7e1184b08c360cb699530e70b84"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 1002

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x268;
		constexpr const static size_t weakspots = 0x3d8;
	}

#define Chainsaw_TypeDefinitionIndex 1669

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%a6f828421a25fde0b1951fc5e5471a8afb9384f5
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%a6f828421a25fde0b1951fc5e5471a8afb9384f5"
#define CameraUpdateHook_Static_ClassNameShort "%a6f828421a25fde0b1951fc5e5471a8afb9384f5"
#define CameraUpdateHook_Static_TypeDefinitionIndex 2526

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0xb0;
	}

#define SteamClientWrapper_TypeDefinitionIndex 5149

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x38dd510;
	}

	// obf name: ::%01a2b3340b8eb7f662cd376552b81444950f37ff
#define AimConeUtil_ClassName "%01a2b3340b8eb7f662cd376552b81444950f37ff"
#define AimConeUtil_ClassNameShort "%01a2b3340b8eb7f662cd376552b81444950f37ff"
#define AimConeUtil_TypeDefinitionIndex 6440

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x4697330;
	}

	// obf name: ::%871d868561b906f47448cdc3e781c1d3233a2487
#define Buttons_ConButton_ClassName "%f9b57ab44f5a6341011c113ca3108c30dcb6d883/%871d868561b906f47448cdc3e781c1d3233a2487"
#define Buttons_ConButton_ClassNameShort "%871d868561b906f47448cdc3e781c1d3233a2487"
#define Buttons_ConButton_TypeDefinitionIndex 367

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x14;
	}

	// obf name: ::%35a2b7d3b32c27d272b20065524cc1399cbe0cad
#define Buttons_Static_ClassName "%f9b57ab44f5a6341011c113ca3108c30dcb6d883/%35a2b7d3b32c27d272b20065524cc1399cbe0cad"
#define Buttons_Static_ClassNameShort "%35a2b7d3b32c27d272b20065524cc1399cbe0cad"
#define Buttons_Static_TypeDefinitionIndex 368

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0xf18;
		constexpr const static size_t Attack = 0x358;
		constexpr const static size_t Attack2 = 0x220;
		constexpr const static size_t Forward = 0x168;
		constexpr const static size_t Backward = 0xb68;
		constexpr const static size_t Right = 0x298;
		constexpr const static size_t Left = 0x308;
		constexpr const static size_t Sprint = 0xe38;

		// Functions
		constexpr const static size_t Pets_setter = 0x2a41cc0;
	}

#define PlayerModel_TypeDefinitionIndex 5177

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x288;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 110

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 548

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x284;
		constexpr const static size_t yawClamp = 0x28c;
		constexpr const static size_t canWieldItems = 0x294;
	}

#define ProgressBar_TypeDefinitionIndex 5185

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 4732

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x400;
		constexpr const static size_t wasAiming = 0x410;
	}

#define CrossbowWeapon_TypeDefinitionIndex 1403

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 5159

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%32db848a591bc2d7313aae9fb39fea030ebeeac9
#define ConVar_Admin_Static_ClassName "%e66e7319ab6a88028d4f788cf1c7d38b16ada9b3/%32db848a591bc2d7313aae9fb39fea030ebeeac9"
#define ConVar_Admin_Static_ClassNameShort "%32db848a591bc2d7313aae9fb39fea030ebeeac9"
#define ConVar_Admin_Static_TypeDefinitionIndex 3964

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x64;

		// Functions
		constexpr const static size_t admintime_getter = 0x2a3a9b0;
		constexpr const static size_t admintime_setter = 0x2a6f870;
	}

	// obf name: ::%d21083f08059bce641417f4948e7efbd4c3f2d95
#define ConVar_Player_Static_ClassName "%f27ba5a0a465ed05d90673cb274957d00dbee0ff/%d21083f08059bce641417f4948e7efbd4c3f2d95"
#define ConVar_Player_Static_ClassNameShort "%d21083f08059bce641417f4948e7efbd4c3f2d95"
#define ConVar_Player_Static_TypeDefinitionIndex 4028

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0xb0;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x2a7eeb0;
		constexpr const static size_t clientTickRate_setter = 0x2a60900;
	}

#define ColliderInfo_TypeDefinitionIndex 1777

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 2506

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x210;
		constexpr const static size_t HasAuth = 0x220;
		constexpr const static size_t HasGuestAuth = 0x221;
	}

#define AutoTurret_TypeDefinitionIndex 1653

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x3b0;
		constexpr const static size_t lastYaw = 0x3c0;
		constexpr const static size_t muzzlePos = 0x3e0;
		constexpr const static size_t gun_yaw = 0x3f8;
		constexpr const static size_t gun_pitch = 0x400;
		constexpr const static size_t sightRange = 0x408;

		// Functions
		constexpr const static size_t IsAuthed = 0x1059a50;
	}

#define Client_TypeDefinitionIndex 1761

	namespace Client {

		// Functions
		constexpr const static size_t OnNetworkMessage = 0x11afee0;
		constexpr const static size_t OnNetworkMessage_vtableoff = 0x1c8;
		constexpr const static size_t CreateOrUpdateEntity = 0x11d9190;
	}

#define BaseNetworkable_TypeDefinitionIndex 4618

	namespace BaseNetworkable {

		// Functions
		constexpr const static size_t Load = 0x32ec640;
		constexpr const static size_t Load_vtableoff = 0xad8;
	}

	// obf name: ::%1ecba1b46af2f98cbde9ff52f9af7a056a17a5cb
#define ItemManager_Static_ClassName "%f1ca891c9e81c372739320aaf4f7cd11c3363c72/%1ecba1b46af2f98cbde9ff52f9af7a056a17a5cb"
#define ItemManager_Static_ClassNameShort "%1ecba1b46af2f98cbde9ff52f9af7a056a17a5cb"
#define ItemManager_Static_TypeDefinitionIndex 3430

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x158;
		constexpr const static size_t itemDictionary = 0x80;
		constexpr const static size_t itemDictionaryByName = 0x150;
	}

	// obf name: ::%bb3bb92486331b0401cd761fd77fed4201bd9f34
#define ConVar_Server_Static_ClassName "%0dfdce9e8387409c7ca0ec5061cf8d1a9e384cac/%bb3bb92486331b0401cd761fd77fed4201bd9f34"
#define ConVar_Server_Static_ClassNameShort "%bb3bb92486331b0401cd761fd77fed4201bd9f34"
#define ConVar_Server_Static_TypeDefinitionIndex 257

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 5708

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x3fa7150;
	}

#define LoadingScreen_TypeDefinitionIndex 374

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 6325

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%b4f5f9f55f6f48306d923ce123c1b15fe7d6d232"
#define MapView_Static_ClassNameShort "%b4f5f9f55f6f48306d923ce123c1b15fe7d6d232"
#define MapView_TypeDefinitionIndex 1328

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x53468b0;
	}

	// obf name: ::%c3402e51b08dae0db26b69a14b47762844836ffa
#define GamePhysics_ClassName "%c3402e51b08dae0db26b69a14b47762844836ffa"
#define GamePhysics_ClassNameShort "%c3402e51b08dae0db26b69a14b47762844836ffa"
#define GamePhysics_TypeDefinitionIndex 4957

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x36405a0;
		constexpr const static size_t LineOfSightInternal = 0x3658020;
		constexpr const static size_t Verify = 0x366baa0;
	}

#define DDraw_TypeDefinitionIndex 3925

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x2bb4330;
		constexpr const static size_t Line = 0x2bc5f60;
	}

	// obf name: ::%312af8b77bcf54ce2c0b4da9ff6a0b512a6c4264
#define RaycastHitEx_ClassName "%312af8b77bcf54ce2c0b4da9ff6a0b512a6c4264"
#define RaycastHitEx_ClassNameShort "%312af8b77bcf54ce2c0b4da9ff6a0b512a6c4264"
#define RaycastHitEx_TypeDefinitionIndex 5635

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x3ec1c40;
	}

	// obf name: ::%036be52195633605aaff6e29be40bdfe9999e42e
#define OnParentDestroyingEx_ClassName "%036be52195633605aaff6e29be40bdfe9999e42e"
#define OnParentDestroyingEx_ClassNameShort "%036be52195633605aaff6e29be40bdfe9999e42e"
#define OnParentDestroyingEx_TypeDefinitionIndex 3557

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x26889b0;
	}

	// obf name: ::%b80889ee4139ae8ac2b854afa73afe35364b6d00
#define ConsoleNetwork_ClassName "%b80889ee4139ae8ac2b854afa73afe35364b6d00"
#define ConsoleNetwork_ClassNameShort "%b80889ee4139ae8ac2b854afa73afe35364b6d00"
#define ConsoleNetwork_TypeDefinitionIndex 6996

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x4d07280;
	}

#define ThrownWeapon_TypeDefinitionIndex 6354

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2d8;
	}

#define MapInterface_TypeDefinitionIndex 4013

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 6136

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 1328

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 2747

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2b0;
	}

#define PlayerCorpse_TypeDefinitionIndex 5094

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2e0;
	}

#define TimedExplosive_TypeDefinitionIndex 2648

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1ac;
	}

#define SmokeGrenade_TypeDefinitionIndex 772

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x250;
	}

#define GrenadeWeapon_TypeDefinitionIndex 1731

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f0;
	}

#define ViewmodelLower_TypeDefinitionIndex 6557

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%711a5f5546dffc01707aca5a0bf9f5ad62a297ca
#define ConVar_Client_Static_ClassName "%dbbd75e04173c6acf00ad007a3b26b4bafdb73f2/%711a5f5546dffc01707aca5a0bf9f5ad62a297ca"
#define ConVar_Client_Static_ClassNameShort "%711a5f5546dffc01707aca5a0bf9f5ad62a297ca"
#define ConVar_Client_Static_TypeDefinitionIndex 2202

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x4c4;
		constexpr const static size_t camspeed = 0x67c;
	}

#define SamSite_TypeDefinitionIndex 6284

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3a0;
		constexpr const static size_t Flag_TargetMode = 0x3dc;
	}

#define ServerProjectile_TypeDefinitionIndex 5167

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 3245

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 1155

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 5908

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 3193

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 144

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 3838

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x124;
	}

	// obf name: ::%0b7d82126c3287a50c61d9681102a6d9fa281e96
#define Facepunch_Network_Raknet_Client_ClassName "%0b7d82126c3287a50c61d9681102a6d9fa281e96"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%0b7d82126c3287a50c61d9681102a6d9fa281e96"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex -1

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x655a340;
		constexpr const static size_t IsConnected_vtableoff = 0x1d8;
	}

	// obf name: ::%c2a0f8986c4c94d7aa137ccbcefb88808e045066
#define EncryptedValue_ClassName "%c2a0f8986c4c94d7aa137ccbcefb88808e045066<System/Int32>"
#define EncryptedValue_ClassNameShort "%c2a0f8986c4c94d7aa137ccbcefb88808e045066"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%d714d19c68ac8d7daa1abeca4c2bcdc723ae0ab5
#define HiddenValue_ClassName "%d714d19c68ac8d7daa1abeca4c2bcdc723ae0ab5<BaseNetworkable/%ce43eb5300c8064b6297f5a6e29f3868c1e37d31>"
#define HiddenValue_ClassNameShort "%d714d19c68ac8d7daa1abeca4c2bcdc723ae0ab5"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 977

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x5076720;
	}

#define ItemModRFListener_TypeDefinitionIndex 1272

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x52dfa40;
	}

#define UIFogOverlay_TypeDefinitionIndex 3245

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x48;
	}

	// obf name: ::%1717babd60d6699fd3b9d26f4bc249a9d0432180
#define BufferStream_ClassName "%1717babd60d6699fd3b9d26f4bc249a9d0432180"
#define BufferStream_ClassNameShort "%1717babd60d6699fd3b9d26f4bc249a9d0432180"
#define BufferStream_TypeDefinitionIndex 7235

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x954d500;
	}

#define FreeableLootContainer_TypeDefinitionIndex 4848

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 2560

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 6886

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x4b51750;
	}

#define OutlineManager_TypeDefinitionIndex 1190

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%3a28760016d54392a2940bb7363d66ce4090359b
#define ProtoBuf_ProjectileShoot_ClassName "%3a28760016d54392a2940bb7363d66ce4090359b"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%3a28760016d54392a2940bb7363d66ce4090359b"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7316

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x10;
	}

	// obf name: ::%c9521283d018cc5ec959c8cf0d393aa5e51fab22
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%3a28760016d54392a2940bb7363d66ce4090359b/%c9521283d018cc5ec959c8cf0d393aa5e51fab22"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%c9521283d018cc5ec959c8cf0d393aa5e51fab22"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7315

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x18;
		constexpr const static size_t startPos = 0x2c;
		constexpr const static size_t startVel = 0x1c;
		constexpr const static size_t seed = 0x14;
	}

	// obf name: ::%453c2edf3f1c35ff274dde94974efa980c61fa0d
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%453c2edf3f1c35ff274dde94974efa980c61fa0d"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%453c2edf3f1c35ff274dde94974efa980c61fa0d"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7395

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t curPosition = 0x28;
		constexpr const static size_t curVelocity = 0x10;
		constexpr const static size_t travelTime = 0x24;
		constexpr const static size_t ShouldPool = 0x1c;

		// Functions
		constexpr const static size_t Dispose = 0x8a0b8d0;
	}

	// obf name: ::%fbd875878dec0e55023ba61dbdaa339be69f7ff7
#define ProtoBuf_PlayerProjectileAttack_ClassName "%fbd875878dec0e55023ba61dbdaa339be69f7ff7"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%fbd875878dec0e55023ba61dbdaa339be69f7ff7"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7253

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x28;
		constexpr const static size_t hitDistance = 0x10;
		constexpr const static size_t travelTime = 0x20;
		constexpr const static size_t playerAttack = 0x18;
	}

	// obf name: ::%79c9000078d7f0afe0b01eff9ab9c79b97098577
#define ProtoBuf_PlayerAttack_ClassName "%79c9000078d7f0afe0b01eff9ab9c79b97098577"
#define ProtoBuf_PlayerAttack_ClassNameShort "%79c9000078d7f0afe0b01eff9ab9c79b97098577"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7479

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t attack = 0x18;
		constexpr const static size_t projectileID = 0x20;
	}

	// obf name: ::%1ad6471f9edebe7b286cba79b959eed2b6a519af
#define ProtoBuf_Attack_ClassName "%1ad6471f9edebe7b286cba79b959eed2b6a519af"
#define ProtoBuf_Attack_ClassNameShort "%1ad6471f9edebe7b286cba79b959eed2b6a519af"
#define ProtoBuf_Attack_TypeDefinitionIndex 7179

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x68;
		constexpr const static size_t pointEnd = 0x20;
		constexpr const static size_t hitID = 0x10;
		constexpr const static size_t hitBone = 0x38;
		constexpr const static size_t hitNormalLocal = 0x58;
		constexpr const static size_t hitPositionLocal = 0x78;
		constexpr const static size_t hitNormalWorld = 0x4c;
		constexpr const static size_t hitPositionWorld = 0x2c;
		constexpr const static size_t hitPartID = 0x48;
		constexpr const static size_t hitMaterialID = 0x3c;
		constexpr const static size_t srcParentID = 0x18;
		constexpr const static size_t dstParentID = 0x40;
	}
}