#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68e03a8e;
		constexpr const static size_t gc_handles = 0xd740420;
		constexpr const static size_t il2cpp_resolve_icall = 0x7b8ab0;
		constexpr const static size_t il2cpp_array_new = 0x7b8ad0;
		constexpr const static size_t il2cpp_assembly_get_image = 0x2ee40;
		constexpr const static size_t il2cpp_class_from_name = 0x7b8c40;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x7b8f50;
		constexpr const static size_t il2cpp_class_get_type = 0x7b8ff0;
		constexpr const static size_t il2cpp_domain_get = 0x7b9550;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x7b9570;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x7b9e30;
		constexpr const static size_t il2cpp_gchandle_new = 0x7b9de0;
		constexpr const static size_t il2cpp_gchandle_free = 0x7b9ed0;
		constexpr const static size_t il2cpp_method_get_name = 0x59d0;
		constexpr const static size_t il2cpp_object_new = 0x7ba580;
		constexpr const static size_t il2cpp_type_get_object = 0x7bad70;
	}

#define Object_TypeDefinitionIndex 16752

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xb013dc0;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16723

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

#define Component_TypeDefinitionIndex 16710

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16704

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 16787

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xb01f620;
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

#define Camera_TypeDefinitionIndex 16502

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16774

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

#define Material_TypeDefinitionIndex 16565

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16561

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xafd3570;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16564

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xafd72c0;
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16620

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

#define Renderer_TypeDefinitionIndex 16562

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16623

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16625

	namespace Texture2D {
		constexpr const static size_t ctor = 0xafed2f0;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define RenderTexture_TypeDefinitionIndex 16630

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xaff5fd0;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17100

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb039b30;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17076

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xb0339c0;
	}

#define ComputeBuffer_TypeDefinitionIndex 16765

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb017930;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xb017b80;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16569

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xafde180;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xafddee0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 21876

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xb05c150;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16542

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16653

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24464

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16539

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24342

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

#define Application_TypeDefinitionIndex 16485

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16651

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23313

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xb0a26f0;
		constexpr const static size_t RaycastNonAlloc = 0xb0a4dc0;
	}

#define BaseNetworkable_TypeDefinitionIndex 5054

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x28;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x50;
	}

	// obf name: ::%e522d2d11c781172e40c68e939d93901fdb06a1e
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%e522d2d11c781172e40c68e939d93901fdb06a1e"
#define BaseNetworkable_Static_ClassNameShort "%e522d2d11c781172e40c68e939d93901fdb06a1e"
#define BaseNetworkable_Static_TypeDefinitionIndex 5053

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x10;
	}

	// obf name: ::%76dd4ce8905483a83442144f9083c573aecfd0e3
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%76dd4ce8905483a83442144f9083c573aecfd0e3"
#define BaseNetworkable_EntityRealm_ClassNameShort "%76dd4ce8905483a83442144f9083c573aecfd0e3"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 5051

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x35ec950;
	}

	// obf name: ::%70628e380010e4dd01fa8d29c65a5af8d4852f25
#define System_ListDictionary_ClassName "%70628e380010e4dd01fa8d29c65a5af8d4852f25<%7d2f8d8a1d3bd6cc652d483ea26a5249dca3b33a,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%70628e380010e4dd01fa8d29c65a5af8d4852f25"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x20;

		// Functions
		constexpr const static size_t TryGetValue = 0x6f3e9d0;
		constexpr const static size_t TryGetValue_methodinfo = 0xd467dc0;
	}

	// obf name: ::%c2b547f259e1bdda7692f3152a2a179edc88c649
#define System_BufferList_ClassName "%c2b547f259e1bdda7692f3152a2a179edc88c649<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%c2b547f259e1bdda7692f3152a2a179edc88c649"
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
		constexpr const static size_t Instance = 0x8;
	}

#define Model_TypeDefinitionIndex 208

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 110

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0xa0;
		constexpr const static size_t positionLerp = 0x100;

		// Functions
		constexpr const static size_t ServerRPC = 0x50424c0;
		constexpr const static size_t FindBone = 0x503f480;
		constexpr const static size_t GetWorldVelocity = 0x5092050;
		constexpr const static size_t GetParentVelocity = 0x5066210;
	}

	// obf name: ::%835eab6fb84b0602b1a3617091480f46624daf9b
#define PositionLerp_ClassName "%835eab6fb84b0602b1a3617091480f46624daf9b"
#define PositionLerp_ClassNameShort "%835eab6fb84b0602b1a3617091480f46624daf9b"
#define PositionLerp_TypeDefinitionIndex 6588

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x18;
	}

	// obf name: ::%0bb796ba68beca5ee16341e0f15b8888eb152377
#define Interpolator_ClassName "%0bb796ba68beca5ee16341e0f15b8888eb152377<%eabdcb65e93a32818c29959a58bf6768d9695ab7>"
#define Interpolator_ClassNameShort "%0bb796ba68beca5ee16341e0f15b8888eb152377"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 559

	namespace BaseCombatEntity {

		// Offsets
		constexpr const static size_t skeletonProperties = 0x1c8;
		constexpr const static size_t baseProtection = 0x1d0;
		constexpr const static size_t lifestate = 0x23c;
		constexpr const static size_t markAttackerHostile = 0x242;
		constexpr const static size_t _health = 0x248;
		constexpr const static size_t _maxHealth = 0x24C;
		constexpr const static size_t lastNotifyFrame = 0x258;
	}

#define SkeletonProperties_TypeDefinitionIndex 1007

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 1005

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 6676

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 6675

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%9254a59f015a6be4cd4c703b3b74ca9dd5e5cd4e
#define DamageTypeList_ClassName "%9254a59f015a6be4cd4c703b3b74ca9dd5e5cd4e"
#define DamageTypeList_ClassNameShort "%9254a59f015a6be4cd4c703b3b74ca9dd5e5cd4e"
#define DamageTypeList_TypeDefinitionIndex 4410

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 6421

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 3811

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x40;
		constexpr const static size_t iconSprite = 0x50;
		constexpr const static size_t category = 0x58;
		constexpr const static size_t stackable = 0x70;
		constexpr const static size_t rarity = 0x88;
		constexpr const static size_t ItemModWearable = 0x140;
	}

#define RecoilProperties_TypeDefinitionIndex 4246

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 3704

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 5642

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x3b48880;
		constexpr const static size_t StartAttackCooldown = 0x3b470c0;
	}

#define BaseProjectile_TypeDefinitionIndex 3708

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
		constexpr const static size_t LaunchProjectile = 0x27c13c0;
		constexpr const static size_t LaunchProjectileClientSide = 0x27c1fe0;
		constexpr const static size_t ScaleRepeatDelay = 0x27c5e00;
		constexpr const static size_t GetAimCone = 0x27ed2c0;
		constexpr const static size_t GetAimCone_vtableoff = 0x41c8;
		constexpr const static size_t UpdateAmmoDisplay = 0x27e8fd0;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x4158;
	}

#define BaseLauncher_TypeDefinitionIndex 5304

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 4035

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%d426423130ba2df98e32f3fadb93985f0079df83
#define HitTest_ClassName "%d426423130ba2df98e32f3fadb93985f0079df83"
#define HitTest_ClassNameShort "%d426423130ba2df98e32f3fadb93985f0079df83"
#define HitTest_TypeDefinitionIndex 1766

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x40;
		constexpr const static size_t AttackRay = 0x1c;
		constexpr const static size_t RayHit = 0xb0;
		constexpr const static size_t damageProperties = 0x60;
		constexpr const static size_t gameObject = 0x10;
		constexpr const static size_t collider = 0x70;
		constexpr const static size_t ignoredTypes = 0x80;
		constexpr const static size_t HitTransform = 0x50;
		constexpr const static size_t HitPart = 0x44;
		constexpr const static size_t HitMaterial = 0x38;
		constexpr const static size_t DidHit = 0x18;
		constexpr const static size_t MaxDistance = 0xa0;
		constexpr const static size_t HitPoint = 0x8c;
		constexpr const static size_t HitNormal = 0xe0;
		constexpr const static size_t ignoreEntity = 0x98;
		constexpr const static size_t HitEntity = 0xa8;
	}

#define Projectile_TypeDefinitionIndex 6411

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
		constexpr const static size_t sourceProjectilePrefab = 0x110;
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
		constexpr const static size_t CalculateEffectScale = 0x43a4cd0;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x338;
		constexpr const static size_t SetEffectScale = 0x43981b0;
		constexpr const static size_t UpdateVelocity = 0x43b15a0;
		constexpr const static size_t Retire = 0x43ae800;
		constexpr const static size_t DoHit = 0x4388ba0;
	}

	// obf name: ::%a4d9540e2880400a8aa1c0f0aa65d0307757a414
#define HitInfo_ClassName "%a4d9540e2880400a8aa1c0f0aa65d0307757a414"
#define HitInfo_ClassNameShort "%a4d9540e2880400a8aa1c0f0aa65d0307757a414"
#define HitInfo_TypeDefinitionIndex 5998

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x60;
		constexpr const static size_t damageTypes = 0x98;

		// Functions
		constexpr const static size_t get_boneArea = 0x3feaa20;
	}

	// obf name: ::%ad1f9a7816f67e63ba0723bb2c7157dd926e4903
#define GameTrace_ClassName "%ad1f9a7816f67e63ba0723bb2c7157dd926e4903"
#define GameTrace_ClassNameShort "%ad1f9a7816f67e63ba0723bb2c7157dd926e4903"
#define GameTrace_TypeDefinitionIndex 1347

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x5564940;
	}

#define BaseMelee_TypeDefinitionIndex 3133

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x211ab50;
		constexpr const static size_t DoThrow = 0x2114cd0;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 2241

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x408;
		constexpr const static size_t strikeRecoil = 0x410;
		constexpr const static size_t _didSparkThisFrame = 0x418;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 3925

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x420;
		constexpr const static size_t stringBonusVelocity = 0x42c;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x2a41960;
	}

	// obf name: ::%5e6f40f20ef131bfe893ca510cc6250e2d80a010
#define ItemContainer_ClassName "%5e6f40f20ef131bfe893ca510cc6250e2d80a010"
#define ItemContainer_ClassNameShort "%5e6f40f20ef131bfe893ca510cc6250e2d80a010"
#define ItemContainer_TypeDefinitionIndex 1340

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x50;
		constexpr const static size_t itemList = 0x28;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x5530240;
	}

#define PlayerLoot_TypeDefinitionIndex 4469

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 276

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerWear = 0x30;
		constexpr const static size_t containerMain = 0x58;
		constexpr const static size_t containerBelt = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x1ac8400;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 1245

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x543bef0;
		constexpr const static size_t get_rotation = 0x541af70;
		constexpr const static size_t set_rotation = 0x5423700;
		constexpr const static size_t HeadForward = 0x5434ff0;
	}

	// obf name: ::%59ca0d9b212f454d841719ce46b99521ad5f6f61
#define PlayerEyes_Static_ClassName "PlayerEyes/%59ca0d9b212f454d841719ce46b99521ad5f6f61"
#define PlayerEyes_Static_ClassNameShort "%59ca0d9b212f454d841719ce46b99521ad5f6f61"
#define PlayerEyes_Static_TypeDefinitionIndex 1244

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x128;
	}

	// obf name: ::%7e1773333e455f14015c72526fe2e93297b6e4c5
#define PlayerBelt_ClassName "%7e1773333e455f14015c72526fe2e93297b6e4c5"
#define PlayerBelt_ClassNameShort "%7e1773333e455f14015c72526fe2e93297b6e4c5"
#define PlayerBelt_TypeDefinitionIndex 4403

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x2f93e20;
		constexpr const static size_t GetActiveItem = 0x2f9f0c0;
	}

	// obf name: ::%34dd6add376ee81dcd998a57ee5483eff4d77ee0
#define LocalPlayer_ClassName "%34dd6add376ee81dcd998a57ee5483eff4d77ee0"
#define LocalPlayer_ClassNameShort "%34dd6add376ee81dcd998a57ee5483eff4d77ee0"
#define LocalPlayer_TypeDefinitionIndex 5909

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x3eb78e0;
		constexpr const static size_t MoveItem = 0x3ec3f50;
		constexpr const static size_t get_Entity = 0x3ec84d0;
	}

	// obf name: ::%e08c5a611e3e0e8faebd073c8d7067c65de927de
#define LocalPlayer_Static_ClassName "%34dd6add376ee81dcd998a57ee5483eff4d77ee0/%e08c5a611e3e0e8faebd073c8d7067c65de927de"
#define LocalPlayer_Static_ClassNameShort "%e08c5a611e3e0e8faebd073c8d7067c65de927de"
#define LocalPlayer_Static_TypeDefinitionIndex 5908

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x58;
	}

	// obf name: ::%7e1765820a3d8f46ef9a5c01fac66653c287ce1d
#define BasePlayer_Static_ClassName "BasePlayer/%7e1765820a3d8f46ef9a5c01fac66653c287ce1d"
#define BasePlayer_Static_ClassNameShort "%7e1765820a3d8f46ef9a5c01fac66653c287ce1d"
#define BasePlayer_Static_TypeDefinitionIndex 7130

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x630;
	}

#define BasePlayer_TypeDefinitionIndex 7131

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x358;
		constexpr const static size_t input = 0x360;
		constexpr const static size_t movement = 0x278;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x2e8;
		constexpr const static size_t playerFlags = 0x598;
		constexpr const static size_t eyes = 0x368;
		constexpr const static size_t playerRigidbody = 0x538;
		constexpr const static size_t userID = 0x5e0;
		constexpr const static size_t UserIDString = 0x5b8;
		constexpr const static size_t inventory = 0x400;
		constexpr const static size_t _displayName = 0x298;
		constexpr const static size_t _lookingAt = 0x528;
		constexpr const static size_t lastSentTickTime = 0x554;
		constexpr const static size_t lastSentTick = 0x5a8;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x560;
		constexpr const static size_t _lookingAtEntity = 0x330;
		constexpr const static size_t currentGesture = 0x3e0;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x4db7550;
		constexpr const static size_t Menu_AssistPlayer = 0x4e0feb0;
		constexpr const static size_t OnViewModeChanged = 0x4dd93c0;
		constexpr const static size_t ChatMessage = 0x4d73c40;
		constexpr const static size_t IsOnGround = 0x4d25e80;
		constexpr const static size_t GetSpeed = 0x4d933e0;
		constexpr const static size_t SendProjectileUpdate = 0x4d1b7a0;
		constexpr const static size_t SendProjectileAttack = 0x4d47fd0;
		constexpr const static size_t CanBuild = 0x4e2c7d0;
		constexpr const static size_t GetMounted = 0x4e68be0;
		constexpr const static size_t GetHeldEntity = 0x4e325e0;
		constexpr const static size_t get_inventory = 0x4e9ee50;
		constexpr const static size_t get_eyes = 0x4d7a310;
		constexpr const static size_t SendClientTick = 0x4d7dce0;
		constexpr const static size_t ClientInput = 0x4dd2310;
		constexpr const static size_t ClientInput_vtableoff = 0x3b78;
		constexpr const static size_t MaxHealth = 0x4d45e70;
		constexpr const static size_t MaxHealth_vtableoff = 0x1968;
		constexpr const static size_t OnAttacked = 0x4d4ebc0;
		constexpr const static size_t OnAttacked_vtableoff = 0x10e8;
	}

#define ScientistNPC_TypeDefinitionIndex 5308

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 644

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 2966

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 4585

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 1133

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 3408

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 3542

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xd8;
		constexpr const static size_t ladder = 0xe8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x25cd940;
		constexpr const static size_t BlockSprint = 0x25c9d20;
		constexpr const static size_t GroundCheck = 0x25d2f70;
		constexpr const static size_t ClientInput = 0x25d2b10;
		constexpr const static size_t ClientInput_vtableoff = 0x378;
		constexpr const static size_t DoFixedUpdate = 0x25e6c20;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x2a8;
		constexpr const static size_t FrameUpdate = 0x25ce7a0;
		constexpr const static size_t FrameUpdate_vtableoff = 0x278;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 7055

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 2313

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 3528

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 506

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 502

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%41bdc7710b5dee637cca0fbbd1a5c79c5934a302
#define ConsoleSystem_ClassName "%41bdc7710b5dee637cca0fbbd1a5c79c5934a302"
#define ConsoleSystem_ClassNameShort "%41bdc7710b5dee637cca0fbbd1a5c79c5934a302"
#define ConsoleSystem_TypeDefinitionIndex 23294

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x657f360;
	}

	// obf name: ::%e29617790260bb6f5b96a081a2f8682bd27fb110
#define ConsoleSystem_Index_Static_ClassName "%41bdc7710b5dee637cca0fbbd1a5c79c5934a302/%db91132b050e9daa88ffa8573310466da9b21354.%e29617790260bb6f5b96a081a2f8682bd27fb110"
#define ConsoleSystem_Index_Static_ClassNameShort "%e29617790260bb6f5b96a081a2f8682bd27fb110"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23287

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x50;
	}

#define LootableCorpse_TypeDefinitionIndex 6535

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2c8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 5449

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 3472

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0xa8;
		constexpr const static size_t mainCameraTransform = 0x68;

		// Functions
		constexpr const static size_t Update = 0x24c1640;
		constexpr const static size_t OnPreCull = 0x24cb180;
		constexpr const static size_t Trace = 0x24bfea0;
	}

#define CameraMan_TypeDefinitionIndex 5526

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%6fca2d442636bb58ee0013ea831d5f2ac2bbc212
#define PlayerTick_ClassName "%6fca2d442636bb58ee0013ea831d5f2ac2bbc212"
#define PlayerTick_ClassNameShort "%6fca2d442636bb58ee0013ea831d5f2ac2bbc212"
#define PlayerTick_TypeDefinitionIndex 7469

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x30;
		constexpr const static size_t modelState = 0x48;
		constexpr const static size_t activeItem = 0x40;
		constexpr const static size_t parentID = 0x50;
		constexpr const static size_t intermediatePosition = 0x58;
		constexpr const static size_t position = 0x20;
		constexpr const static size_t eyePos = 0x10;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8e92e10;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8e8c230;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%5ad9ee59301170cbca64fefb6e481ab17e7ca5e6
#define InputMessage_ClassName "%5ad9ee59301170cbca64fefb6e481ab17e7ca5e6"
#define InputMessage_ClassNameShort "%5ad9ee59301170cbca64fefb6e481ab17e7ca5e6"
#define InputMessage_TypeDefinitionIndex 7155

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x2c;
		constexpr const static size_t aimAngles = 0x10;
		constexpr const static size_t mouseDelta = 0x20;
	}

	// obf name: ::%300f8b248445b02fbb9fcbc95e58b5d9d9dc54e7
#define InputState_ClassName "%300f8b248445b02fbb9fcbc95e58b5d9d9dc54e7"
#define InputState_ClassNameShort "%300f8b248445b02fbb9fcbc95e58b5d9d9dc54e7"
#define InputState_TypeDefinitionIndex 2754

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x20;
		constexpr const static size_t previous = 0x10;
	}

#define PlayerInput_TypeDefinitionIndex 5963

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%b998faa4232ddabc5a5d3ff21e09f34a31ffa8cc
#define ModelState_ClassName "%b998faa4232ddabc5a5d3ff21e09f34a31ffa8cc"
#define ModelState_ClassNameShort "%b998faa4232ddabc5a5d3ff21e09f34a31ffa8cc"
#define ModelState_TypeDefinitionIndex 7261

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x5c;
		constexpr const static size_t waterLevel = 0x2c;
		constexpr const static size_t lookDir = 0x10;
	}

	// obf name: ::%17ae84a600855ef5d40612576ee8300e1ca9f32f
#define Item_ClassName "%17ae84a600855ef5d40612576ee8300e1ca9f32f"
#define Item_ClassNameShort "%17ae84a600855ef5d40612576ee8300e1ca9f32f"
#define Item_TypeDefinitionIndex 5553

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x60;
		constexpr const static size_t uid = 0xa8;
		constexpr const static size_t _condition = 0x48;
		constexpr const static size_t _maxCondition = 0x70;
		constexpr const static size_t amount = 0x54;
		constexpr const static size_t position = 0xd0;
		constexpr const static size_t contents = 0xc0;
		constexpr const static size_t parent = 0xd8;
		constexpr const static size_t heldEntity = 0x80;
		constexpr const static size_t worldEnt = 0x90;

		// Functions
		constexpr const static size_t get_iconSprite = 0x3a821c0;
	}

	// obf name: ::%02577c8e584caab4cb6d60056f2b455e7f695d85
#define WaterLevel_ClassName "%02577c8e584caab4cb6d60056f2b455e7f695d85"
#define WaterLevel_ClassNameShort "%02577c8e584caab4cb6d60056f2b455e7f695d85"
#define WaterLevel_TypeDefinitionIndex 5766

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x3cdc190;
		constexpr const static size_t GetWaterLevel = 0x3cd8ff0;
	}

	// obf name: ::%8b4afd94966aeac3cb2dbeaa162dedddc8a875ff
#define ConVar_Graphics_Static_ClassName "%6e9df55c8998a9402e7b2eaee7e1de67e6acbd4c/%8b4afd94966aeac3cb2dbeaa162dedddc8a875ff"
#define ConVar_Graphics_Static_ClassNameShort "%8b4afd94966aeac3cb2dbeaa162dedddc8a875ff"
#define ConVar_Graphics_Static_TypeDefinitionIndex 4010

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x530;

		// Functions
		constexpr const static size_t _fov_getter = 0x48e7c30;
		constexpr const static size_t _fov_setter = 0x48dcb50;
	}

#define BaseFishingRod_TypeDefinitionIndex 6342

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
		constexpr const static size_t UpdateLineRenderer = 0x42e9330;
		constexpr const static size_t EvaluateFishingPosition = 0x42f11b0;
	}

#define FishingBobber_TypeDefinitionIndex 5945

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 3020

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x201a7d0;
	}

	// obf name: ::%0c29d75f8e9a83254709eb4cebf059a526a46837
#define GameManager_ClassName "%0c29d75f8e9a83254709eb4cebf059a526a46837"
#define GameManager_ClassNameShort "%0c29d75f8e9a83254709eb4cebf059a526a46837"
#define GameManager_TypeDefinitionIndex 782

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x20;

		// Functions
		constexpr const static size_t CreatePrefab = 0x4f615c0;
	}

	// obf name: ::%e7c81455f8b84baf7eec3c8c7e6f399d3e015858
#define GameManager_Static_ClassName "%0c29d75f8e9a83254709eb4cebf059a526a46837/%e7c81455f8b84baf7eec3c8c7e6f399d3e015858"
#define GameManager_Static_ClassNameShort "%e7c81455f8b84baf7eec3c8c7e6f399d3e015858"
#define GameManager_Static_TypeDefinitionIndex 781

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x18;
	}

	// obf name: ::%58f2c6c8d0ab5a6ef0d49b8325835fb1cb56aa6e
#define PrefabPoolCollection_ClassName "%58f2c6c8d0ab5a6ef0d49b8325835fb1cb56aa6e"
#define PrefabPoolCollection_ClassNameShort "%58f2c6c8d0ab5a6ef0d49b8325835fb1cb56aa6e"
#define PrefabPoolCollection_TypeDefinitionIndex 3158

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%a56a92cb17336bd686e2ee19a8c4f024f6f4fb72
#define PrefabPool_ClassName "%a56a92cb17336bd686e2ee19a8c4f024f6f4fb72"
#define PrefabPool_ClassNameShort "%a56a92cb17336bd686e2ee19a8c4f024f6f4fb72"
#define PrefabPool_TypeDefinitionIndex 6247

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x18;
	}

#define ItemModProjectile_TypeDefinitionIndex 2870

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

#define CraftingQueue_TypeDefinitionIndex 2804

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%a77114d2e182a686ededc4be2993356023428d73
#define CraftingQueue_Static_ClassName "CraftingQueue/%a77114d2e182a686ededc4be2993356023428d73"
#define CraftingQueue_Static_ClassNameShort "%a77114d2e182a686ededc4be2993356023428d73"
#define CraftingQueue_Static_TypeDefinitionIndex 2803

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x1a;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 4114

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%ff3331d0c6eee86914f1c5ebb43d741e8952113a
#define Planner_Static_ClassName "Planner/%ff3331d0c6eee86914f1c5ebb43d741e8952113a"
#define Planner_Static_ClassNameShort "%ff3331d0c6eee86914f1c5ebb43d741e8952113a"
#define Planner_Static_TypeDefinitionIndex 2067

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x1c0;
	}

	// obf name: ::%08a69aff1538128aead08e60460a11bc262808f4
#define Planner_Guide_ClassName "Planner/%08a69aff1538128aead08e60460a11bc262808f4"
#define Planner_Guide_ClassNameShort "%08a69aff1538128aead08e60460a11bc262808f4"
#define Planner_Guide_TypeDefinitionIndex 2063

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0xa0;
	}

#define Planner_TypeDefinitionIndex 2068

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x270;
	}

#define Construction_TypeDefinitionIndex 1683

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x130;
	}

#define BuildingBlock_TypeDefinitionIndex 1373

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x300;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 6489

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x447ddd0;
	}

	// obf name: ::%466306fb9a0545500ac7236267fde4efab57d56c
#define PunchEntry_ClassName "HeldEntity/%466306fb9a0545500ac7236267fde4efab57d56c"
#define PunchEntry_ClassNameShort "%466306fb9a0545500ac7236267fde4efab57d56c"
#define PunchEntry_TypeDefinitionIndex 6487

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x10;
		constexpr const static size_t startTime = 0x2c;
		constexpr const static size_t amountAdded = 0x14;
		constexpr const static size_t amount = 0x20;
	}

#define IronSights_TypeDefinitionIndex 2622

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 3463

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 381

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xe8;
		constexpr const static size_t model = 0xa8;
		constexpr const static size_t lower = 0x78;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x278f5e0;
	}

#define ViewModel_TypeDefinitionIndex 2282

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x178ba90;
		constexpr const static size_t PlayString = 0x178a3c0;
	}

#define MedicalTool_TypeDefinitionIndex 2114

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 6003

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x40;
	}

	// obf name: ::%b9cdf01fd46fa471afd390896b8eea9419b02ee0
#define WaterSystem_Static_ClassName "WaterSystem/%b9cdf01fd46fa471afd390896b8eea9419b02ee0"
#define WaterSystem_Static_ClassNameShort "%b9cdf01fd46fa471afd390896b8eea9419b02ee0"
#define WaterSystem_Static_TypeDefinitionIndex 2651

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x218;
	}

#define WaterSystem_TypeDefinitionIndex 2652

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x1bfc1c0;
	}

#define TerrainMeta_TypeDefinitionIndex 709

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x3f0;
		constexpr const static size_t HeightMap = 0x5c8;
		constexpr const static size_t SplatMap = 0x528;
		constexpr const static size_t TopologyMap = 0x98;
		constexpr const static size_t Texturing = 0x3a0;
	}

#define TerrainCollision_TypeDefinitionIndex 248

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x17ef150;
	}

#define TerrainHeightMap_TypeDefinitionIndex 3794

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 2195

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 4231

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%25b2f1f745926671e6f18467a72f9af337cfe3f9
#define World_Static_ClassName "%d039087275d2f697ae7dd3fdbd0b158fb16fded2/%25b2f1f745926671e6f18467a72f9af337cfe3f9"
#define World_Static_ClassNameShort "%25b2f1f745926671e6f18467a72f9af337cfe3f9"
#define World_Static_TypeDefinitionIndex 5918

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x4c;
	}

#define ItemIcon_TypeDefinitionIndex 1973

	namespace ItemIcon {

		// Functions
		constexpr const static size_t TryToMove = 0x1456250;
		constexpr const static size_t TryToMove_vtableoff = 0x4c8;
		constexpr const static size_t RunTimedAction = 0x1447490;
	}

	// obf name: ::%0b3de5eaa2f31a6feb4f39d08c3c46c47988259a
#define ItemIcon_Static_ClassName "ItemIcon/%0b3de5eaa2f31a6feb4f39d08c3c46c47988259a"
#define ItemIcon_Static_ClassNameShort "%0b3de5eaa2f31a6feb4f39d08c3c46c47988259a"
#define ItemIcon_Static_TypeDefinitionIndex 1972

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x10;
	}

	// obf name: ::%5bc917a7b8edddf892722075f31d65aec1969e39
#define Effect_ClassName "%5bc917a7b8edddf892722075f31d65aec1969e39"
#define Effect_ClassNameShort "%5bc917a7b8edddf892722075f31d65aec1969e39"
#define Effect_TypeDefinitionIndex 3779

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x70;
		constexpr const static size_t worldPos = 0x9c;
	}

	// obf name: ::%7162ea8e134adbacf26d768d3abc732b727eb8ff
#define EffectLibrary_ClassName "%7162ea8e134adbacf26d768d3abc732b727eb8ff"
#define EffectLibrary_ClassNameShort "%7162ea8e134adbacf26d768d3abc732b727eb8ff"
#define EffectLibrary_TypeDefinitionIndex 2301

	namespace EffectLibrary {

		// Functions
		constexpr const static size_t SetupEffect = 0x17ad950;
	}

	// obf name: ::%06f94687ae213c3280db9ee0246250337b6a5129
#define EffectNetwork_ClassName "%06f94687ae213c3280db9ee0246250337b6a5129"
#define EffectNetwork_ClassNameShort "%06f94687ae213c3280db9ee0246250337b6a5129"
#define EffectNetwork_TypeDefinitionIndex 5441

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%d22d8720f0209c66c745d38b74ea6920a6a46359
#define EffectNetwork_Static_ClassName "%06f94687ae213c3280db9ee0246250337b6a5129/%d22d8720f0209c66c745d38b74ea6920a6a46359"
#define EffectNetwork_Static_ClassNameShort "%d22d8720f0209c66c745d38b74ea6920a6a46359"
#define EffectNetwork_Static_TypeDefinitionIndex 5440

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x40;

		// Functions
		constexpr const static size_t cctor = 0x39504c0;
	}

#define BuildingBlock_TypeDefinitionIndex 1373

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x55d3d30;
		constexpr const static size_t HasUpgradePrivilege = 0x55b6540;
		constexpr const static size_t CanAffordUpgrade = 0x55d0570;
	}

	// obf name: ::%8870be84aaa0ed6e26f8cf262e063e14f56f50b9
#define GameObjectEx_ClassName "%8870be84aaa0ed6e26f8cf262e063e14f56f50b9"
#define GameObjectEx_ClassNameShort "%8870be84aaa0ed6e26f8cf262e063e14f56f50b9"
#define GameObjectEx_TypeDefinitionIndex 6437

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x4418d10;
	}

#define UIDeathScreen_TypeDefinitionIndex 1116

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x52d5690;
	}

	// obf name: ::%3103d4517e35bd5645382164bad60670253c15d2
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%3103d4517e35bd5645382164bad60670253c15d2"
#define BaseScreenShake_Static_ClassNameShort "%3103d4517e35bd5645382164bad60670253c15d2"
#define BaseScreenShake_Static_TypeDefinitionIndex 2643

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x68;
	}

#define FlashbangOverlay_TypeDefinitionIndex 3151

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t flashLength = 0x40;
	}

	// obf name: ::%32bac20dfe3759ca47f52c381ed11409f3b041e2
#define StringPool_ClassName "%32bac20dfe3759ca47f52c381ed11409f3b041e2"
#define StringPool_ClassNameShort "%32bac20dfe3759ca47f52c381ed11409f3b041e2"
#define StringPool_TypeDefinitionIndex 1829

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x90;

		// Functions
		constexpr const static size_t Get = 0x12b71e0;
	}

	// obf name: ::%6b3eb7e3eb772729a4f0114fdde9cfc3aa06eeb1
#define Network_Networkable_ClassName "%6b3eb7e3eb772729a4f0114fdde9cfc3aa06eeb1"
#define Network_Networkable_ClassNameShort "%6b3eb7e3eb772729a4f0114fdde9cfc3aa06eeb1"
#define Network_Networkable_TypeDefinitionIndex 19103

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x20;
	}

	// obf name: ::%23e5812b5b34f445b98d59bc263fb7d4498f0d6a
#define Network_Net_ClassName "%23e5812b5b34f445b98d59bc263fb7d4498f0d6a"
#define Network_Net_ClassNameShort "%23e5812b5b34f445b98d59bc263fb7d4498f0d6a"
#define Network_Net_TypeDefinitionIndex 8411

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x38;
	}

	// obf name: ::%7e83899e9760930ed3099743cbd4c42adaccfea6
#define Network_Client_ClassName "%7e83899e9760930ed3099743cbd4c42adaccfea6"
#define Network_Client_ClassNameShort "%7e83899e9760930ed3099743cbd4c42adaccfea6"
#define Network_Client_TypeDefinitionIndex 19116

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0x110;
		constexpr const static size_t ConnectedPort = 0xf8;
		constexpr const static size_t ConnectedAddress = 0xf0;
		constexpr const static size_t ServerName = 0x118;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x65fa090;
		constexpr const static size_t DestroyNetworkable = 0x65fa330;
	}

	// obf name: ::%d0d1c0dbe33da857b37f7af2f538257bf712c8b1
#define Network_BaseNetwork_ClassName "%d0d1c0dbe33da857b37f7af2f538257bf712c8b1"
#define Network_BaseNetwork_ClassNameShort "%d0d1c0dbe33da857b37f7af2f538257bf712c8b1"
#define Network_BaseNetwork_TypeDefinitionIndex 19168

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x665a3d0;
	}

	// obf name: ::%dca7f73852585420146ffa657a4be26d905ff30d
#define Network_SendInfo_ClassName "%dca7f73852585420146ffa657a4be26d905ff30d"
#define Network_SendInfo_ClassNameShort "%dca7f73852585420146ffa657a4be26d905ff30d"
#define Network_SendInfo_TypeDefinitionIndex 19129

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%2f07ad39aa31b1249fa241f6c9326cc699b1b8a0
#define Network_Message_ClassName "%2f07ad39aa31b1249fa241f6c9326cc699b1b8a0"
#define Network_Message_ClassNameShort "%2f07ad39aa31b1249fa241f6c9326cc699b1b8a0"
#define Network_Message_TypeDefinitionIndex 19163

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%6de7e17e2f897cab2c554b163bb45b3328b53ee5
#define Network_NetRead_ClassName "%6de7e17e2f897cab2c554b163bb45b3328b53ee5"
#define Network_NetRead_ClassNameShort "%6de7e17e2f897cab2c554b163bb45b3328b53ee5"
#define Network_NetRead_TypeDefinitionIndex 19121

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x30;
	}

	// obf name: ::%3a3ea68630f91ffa9087ef17051e4de6fb52e2b2
#define Network_NetWrite_ClassName "%3a3ea68630f91ffa9087ef17051e4de6fb52e2b2"
#define Network_NetWrite_ClassNameShort "%3a3ea68630f91ffa9087ef17051e4de6fb52e2b2"
#define Network_NetWrite_TypeDefinitionIndex 19158

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x48;

		// Functions
		constexpr const static size_t WriteByte = 0x66472b0;
		constexpr const static size_t String = 0x6643480;
		constexpr const static size_t Send = 0x6641380;
	}

#define LootPanel_TypeDefinitionIndex 4090

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x2c2f720;
	}

#define UIInventory_TypeDefinitionIndex 1163

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x536bdb0;
	}

#define GrowableEntity_TypeDefinitionIndex 620

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 6504

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 6503

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 20981

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 9090

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
		constexpr const static size_t get_Instance = 0xcb2390;
	}

	// obf name: ::%04aa6a6a57c3a0966305e84fed8d9022e3c20f76
#define TOD_Sky_Static_ClassName "TOD_Sky/%04aa6a6a57c3a0966305e84fed8d9022e3c20f76"
#define TOD_Sky_Static_ClassNameShort "%04aa6a6a57c3a0966305e84fed8d9022e3c20f76"
#define TOD_Sky_Static_TypeDefinitionIndex 9089

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0xa0;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 9468

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xdc1440;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9796

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 8652

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8020

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 8150

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 7940

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8415

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 837

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 4109

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 6284

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 194

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

#define EnvironmentManager_TypeDefinitionIndex 3111

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x20f2750;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%efd72e11505cad033af591eec8ad998dace740a9/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24076

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 7112

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 7113

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 30

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
		constexpr const static size_t InstanceList = 0x40;
	}

	// obf name: ::%50e1ea05e60aef53bb2381cbc4c0676616a0daa9
#define ListHashSet_ClassName "%50e1ea05e60aef53bb2381cbc4c0676616a0daa9<UIChat>"
#define ListHashSet_ClassNameShort "%50e1ea05e60aef53bb2381cbc4c0676616a0daa9"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 4800

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3e8;
	}

#define Chainsaw_TypeDefinitionIndex 5972

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%2b80169f7c87642249edbfa43e6e7950688de3d1
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%2b80169f7c87642249edbfa43e6e7950688de3d1"
#define CameraUpdateHook_Static_ClassNameShort "%2b80169f7c87642249edbfa43e6e7950688de3d1"
#define CameraUpdateHook_Static_TypeDefinitionIndex 6104

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x58;
	}

#define SteamClientWrapper_TypeDefinitionIndex 189

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x14eddb0;
	}

	// obf name: ::%ceda263dd056a21f0896133f2885a24331070064
#define AimConeUtil_ClassName "%ceda263dd056a21f0896133f2885a24331070064"
#define AimConeUtil_ClassNameShort "%ceda263dd056a21f0896133f2885a24331070064"
#define AimConeUtil_TypeDefinitionIndex 4391

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x2f854f0;
	}

	// obf name: ::%1a2a1d6676b5390c2b6c2c460e99b65f0f3caaea
#define Buttons_ConButton_ClassName "%b558c55bbdf7db93089f660d3fbbe8aa0bd92798/%1a2a1d6676b5390c2b6c2c460e99b65f0f3caaea"
#define Buttons_ConButton_ClassNameShort "%1a2a1d6676b5390c2b6c2c460e99b65f0f3caaea"
#define Buttons_ConButton_TypeDefinitionIndex 1160

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x14;
	}

	// obf name: ::%3923be92e5cc8df4dee91c4b105f341fbfaa90e2
#define Buttons_Static_ClassName "%b558c55bbdf7db93089f660d3fbbe8aa0bd92798/%3923be92e5cc8df4dee91c4b105f341fbfaa90e2"
#define Buttons_Static_ClassNameShort "%3923be92e5cc8df4dee91c4b105f341fbfaa90e2"
#define Buttons_Static_TypeDefinitionIndex 1161

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x880;
		constexpr const static size_t Attack = 0x2b0;
		constexpr const static size_t Attack2 = 0x3e8;
		constexpr const static size_t Forward = 0xc30;
		constexpr const static size_t Backward = 0x858;
		constexpr const static size_t Right = 0x468;
		constexpr const static size_t Left = 0x6a0;
		constexpr const static size_t Sprint = 0x660;

		// Functions
		constexpr const static size_t Pets_setter = 0x48d4430;
	}

#define PlayerModel_TypeDefinitionIndex 1593

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x278;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 2793

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 3374

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 1460

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t timeCounter = 0x2c;
	}

#define BowWeapon_TypeDefinitionIndex 3910

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x408;
		constexpr const static size_t wasAiming = 0x418;
	}

#define CrossbowWeapon_TypeDefinitionIndex 4108

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 3937

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%f22e6a7af30680dbdf02651493217e847b4fa5bf
#define ConVar_Admin_Static_ClassName "%1e89b31f2dcb06e5e8f27f203e5263b5df391b80/%f22e6a7af30680dbdf02651493217e847b4fa5bf"
#define ConVar_Admin_Static_ClassNameShort "%f22e6a7af30680dbdf02651493217e847b4fa5bf"
#define ConVar_Admin_Static_TypeDefinitionIndex 5323

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x1a0;

		// Functions
		constexpr const static size_t admintime_getter = 0x4904980;
		constexpr const static size_t admintime_setter = 0x48f5d00;
	}

	// obf name: ::%98a4f96d04084d4c48488f4d6a59fc1b340d622c
#define ConVar_Player_Static_ClassName "%b749aec5af799830fe58077d862a2bd520ab10b7/%98a4f96d04084d4c48488f4d6a59fc1b340d622c"
#define ConVar_Player_Static_ClassNameShort "%98a4f96d04084d4c48488f4d6a59fc1b340d622c"
#define ConVar_Player_Static_TypeDefinitionIndex 2365

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x188;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x48fd800;
		constexpr const static size_t clientTickRate_setter = 0x48daf30;
	}

#define ColliderInfo_TypeDefinitionIndex 5609

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 5101

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 2239

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x3c0;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x16e4be0;
	}

#define Client_TypeDefinitionIndex 7048

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x4c2a540;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%8ffc7a12bc73c39ce48f90a3bc869ac17726cd47
#define ItemManager_Static_ClassName "%df40aaca81c0c5c9c28ce15d1a7638158d12c247/%8ffc7a12bc73c39ce48f90a3bc869ac17726cd47"
#define ItemManager_Static_ClassNameShort "%8ffc7a12bc73c39ce48f90a3bc869ac17726cd47"
#define ItemManager_Static_TypeDefinitionIndex 2571

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x158;
		constexpr const static size_t itemDictionary = 0x1c8;
		constexpr const static size_t itemDictionaryByName = 0x108;
	}

	// obf name: ::%ca5809509766032e998848a8c2664befe6c653af
#define ConVar_Server_Static_ClassName "%f44adea2fb8dc923e07e54c531a4cbf761ac01a0/%ca5809509766032e998848a8c2664befe6c653af"
#define ConVar_Server_Static_ClassNameShort "%ca5809509766032e998848a8c2664befe6c653af"
#define ConVar_Server_Static_TypeDefinitionIndex 2425

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 6230

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x4225a70;
	}

#define LoadingScreen_TypeDefinitionIndex 3416

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 3470

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%89799e244cfc25b5ae97195995f0df459ec61290"
#define MapView_Static_ClassNameShort "%89799e244cfc25b5ae97195995f0df459ec61290"
#define MapView_TypeDefinitionIndex 3320

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x22c5740;
	}

	// obf name: ::%cd8130860aeeec4ac06ee338f6ea141f9ad99582
#define GamePhysics_Static_ClassName "%1e18bf4e3803e307d025b1f2671bc7612cabd3c5/%cd8130860aeeec4ac06ee338f6ea141f9ad99582"
#define GamePhysics_Static_ClassNameShort "%cd8130860aeeec4ac06ee338f6ea141f9ad99582"
#define GamePhysics_Static_TypeDefinitionIndex 5316

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x70;
	}

	// obf name: ::%1e18bf4e3803e307d025b1f2671bc7612cabd3c5
#define GamePhysics_ClassName "%1e18bf4e3803e307d025b1f2671bc7612cabd3c5"
#define GamePhysics_ClassNameShort "%1e18bf4e3803e307d025b1f2671bc7612cabd3c5"
#define GamePhysics_TypeDefinitionIndex 5317

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x3862190;
		constexpr const static size_t LineOfSightInternal = 0x385de80;
		constexpr const static size_t Verify = 0x386bc20;
	}

#define DDraw_TypeDefinitionIndex 4071

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x2bf7b30;
		constexpr const static size_t Line = 0x2bf57f0;
	}

	// obf name: ::%daca66aabfd84899ec98590862e0c9a9d7c908f3
#define RaycastHitEx_ClassName "%daca66aabfd84899ec98590862e0c9a9d7c908f3"
#define RaycastHitEx_ClassNameShort "%daca66aabfd84899ec98590862e0c9a9d7c908f3"
#define RaycastHitEx_TypeDefinitionIndex 6242

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x42546a0;
	}

	// obf name: ::%76efb3c76df12c024f6dbc04ebaec5fbc3932279
#define OnParentDestroyingEx_ClassName "%76efb3c76df12c024f6dbc04ebaec5fbc3932279"
#define OnParentDestroyingEx_ClassNameShort "%76efb3c76df12c024f6dbc04ebaec5fbc3932279"
#define OnParentDestroyingEx_TypeDefinitionIndex 3965

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x2ae3f50;
	}

	// obf name: ::%e6e8a64aeec785827178c1f1a6a4acc7c077c8c7
#define ConsoleNetwork_ClassName "%e6e8a64aeec785827178c1f1a6a4acc7c077c8c7"
#define ConsoleNetwork_ClassNameShort "%e6e8a64aeec785827178c1f1a6a4acc7c077c8c7"
#define ConsoleNetwork_TypeDefinitionIndex 5105

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x3644f50;
	}

#define ThrownWeapon_TypeDefinitionIndex 759

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 7015

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 5078

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 3320

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 2142

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 5001

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 2883

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 5520

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 5162

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 4014

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%253b3046de87b5cf83709eb226b82c09453c8420
#define ConVar_Client_Static_ClassName "%020d681302a9448a1397a31145e115efcb9ddffe/%253b3046de87b5cf83709eb226b82c09453c8420"
#define ConVar_Client_Static_ClassNameShort "%253b3046de87b5cf83709eb226b82c09453c8420"
#define ConVar_Client_Static_TypeDefinitionIndex 3461

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x5c4;
		constexpr const static size_t camspeed = 0x454;
	}

#define SamSite_TypeDefinitionIndex 3324

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 6311

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 1744

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 2472

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 2021

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 3128

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 6317

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 2984

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%a878f794e9303e59d367596f1c5f1155aac8c479
#define Facepunch_Network_Raknet_Client_ClassName "%a878f794e9303e59d367596f1c5f1155aac8c479"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%a878f794e9303e59d367596f1c5f1155aac8c479"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 22788

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x66a5c80;
		constexpr const static size_t IsConnected_vtableoff = 0x4a8;
	}

	// obf name: ::%7f0df6248381aebcd4a68147c6970df0993179b4
#define EncryptedValue_ClassName "%7f0df6248381aebcd4a68147c6970df0993179b4<System/Int32>"
#define EncryptedValue_ClassNameShort "%7f0df6248381aebcd4a68147c6970df0993179b4"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%a0b4ba2dba199c3edf19b9f13ef6b345077d465a
#define HiddenValue_ClassName "%a0b4ba2dba199c3edf19b9f13ef6b345077d465a<BaseNetworkable/%76dd4ce8905483a83442144f9083c573aecfd0e3>"
#define HiddenValue_ClassNameShort "%a0b4ba2dba199c3edf19b9f13ef6b345077d465a"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x20;
		constexpr const static size_t _hasValue = 0x10;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 509

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x3674910;
	}

#define ItemModRFListener_TypeDefinitionIndex 1546

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0xf6f9c0;
	}

#define UIFogOverlay_TypeDefinitionIndex 1744

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x48;
	}

	// obf name: ::%0bb30105b9af2ae02299743fe855e8ff1beb9076
#define BufferStream_ClassName "%0bb30105b9af2ae02299743fe855e8ff1beb9076"
#define BufferStream_ClassNameShort "%0bb30105b9af2ae02299743fe855e8ff1beb9076"
#define BufferStream_TypeDefinitionIndex 7335

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x98d37e0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 4704

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 3931

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 3083

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x2082dc0;
	}

#define OutlineManager_TypeDefinitionIndex 308

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%a47e343b1b0bc4db5e0998e4f41497b51848f795
#define ConsoleSystem_Command_ClassName "%41bdc7710b5dee637cca0fbbd1a5c79c5934a302/%a47e343b1b0bc4db5e0998e4f41497b51848f795"
#define ConsoleSystem_Command_ClassNameShort "%a47e343b1b0bc4db5e0998e4f41497b51848f795"
#define ConsoleSystem_Command_TypeDefinitionIndex 23279

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x48;
		constexpr const static size_t SetOveride = 0x20;
		constexpr const static size_t Call = 0x10;
	}

	// obf name: ::%327693278384845bef7022d05208a98fc26cecba
#define ConsoleSystem_Option_ClassName "%41bdc7710b5dee637cca0fbbd1a5c79c5934a302/%327693278384845bef7022d05208a98fc26cecba"
#define ConsoleSystem_Option_ClassNameShort "%327693278384845bef7022d05208a98fc26cecba"
#define ConsoleSystem_Option_TypeDefinitionIndex 23289

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%c5aa28d643d3edd8b35b63c137eb992ee4002fcf
#define ConsoleSystem_Arg_ClassName "%41bdc7710b5dee637cca0fbbd1a5c79c5934a302/%c5aa28d643d3edd8b35b63c137eb992ee4002fcf"
#define ConsoleSystem_Arg_ClassNameShort "%c5aa28d643d3edd8b35b63c137eb992ee4002fcf"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23277

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x48;
	}

	// obf name: ::%54a6166a22309d2a9a5a92d871db5f7d702a1394
#define ConsoleSystem_Index_Client_ClassName "%41bdc7710b5dee637cca0fbbd1a5c79c5934a302/%db91132b050e9daa88ffa8573310466da9b21354.%54a6166a22309d2a9a5a92d871db5f7d702a1394"
#define ConsoleSystem_Index_Client_ClassNameShort "%54a6166a22309d2a9a5a92d871db5f7d702a1394"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23285

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x6588a80;
	}

#define String_TypeDefinitionIndex 10202

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x8748310;
	}

	// obf name: ::%1e8e91b0832bf10d34a8a97d98386527656603c5
#define ProtoBuf_ProjectileShoot_ClassName "%1e8e91b0832bf10d34a8a97d98386527656603c5"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%1e8e91b0832bf10d34a8a97d98386527656603c5"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7447

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8da5d90;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8da5d70;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%95d72ac2e6e6eb25a37da74f0e2e5c83c2956d8f
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%1e8e91b0832bf10d34a8a97d98386527656603c5/%95d72ac2e6e6eb25a37da74f0e2e5c83c2956d8f"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%95d72ac2e6e6eb25a37da74f0e2e5c83c2956d8f"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7446

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x24;
		constexpr const static size_t startPos = 0x10;
		constexpr const static size_t startVel = 0x28;
		constexpr const static size_t seed = 0x1c;
	}

	// obf name: ::%fb7e22cf847108f215ce3fd0eabcd6cc8bf5533d
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%fb7e22cf847108f215ce3fd0eabcd6cc8bf5533d"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%fb7e22cf847108f215ce3fd0eabcd6cc8bf5533d"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7268

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x18;
		constexpr const static size_t curPosition = 0x1c;
		constexpr const static size_t curVelocity = 0x28;
		constexpr const static size_t travelTime = 0x14;
		constexpr const static size_t ShouldPool = 0x10;

		// Functions
		constexpr const static size_t Dispose = 0x9684720;
		constexpr const static size_t WriteToStreamDelta = 0x9685ac0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x967c820;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%4fa8de65ca51fbca5d719ce9e8eb291e1ff8ab57
#define ProtoBuf_PlayerProjectileAttack_ClassName "%4fa8de65ca51fbca5d719ce9e8eb291e1ff8ab57"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%4fa8de65ca51fbca5d719ce9e8eb291e1ff8ab57"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7417

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x10;
		constexpr const static size_t hitDistance = 0x1c;
		constexpr const static size_t travelTime = 0x20;
		constexpr const static size_t playerAttack = 0x28;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9b7def0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9b7d140;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%0b1eb388930534f8970b47bf8ced18779150b0f6
#define ProtoBuf_PlayerAttack_ClassName "%0b1eb388930534f8970b47bf8ced18779150b0f6"
#define ProtoBuf_PlayerAttack_ClassNameShort "%0b1eb388930534f8970b47bf8ced18779150b0f6"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7365

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x10;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%aa8c0b195de1be82048f760115af6f25904f88c9
#define ProtoBuf_Attack_ClassName "%aa8c0b195de1be82048f760115af6f25904f88c9"
#define ProtoBuf_Attack_ClassNameShort "%aa8c0b195de1be82048f760115af6f25904f88c9"
#define ProtoBuf_Attack_TypeDefinitionIndex 7537

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x38;
		constexpr const static size_t pointEnd = 0x14;
		constexpr const static size_t hitID = 0x30;
		constexpr const static size_t hitBone = 0x68;
		constexpr const static size_t hitNormalLocal = 0x50;
		constexpr const static size_t hitPositionLocal = 0x78;
		constexpr const static size_t hitNormalWorld = 0x5c;
		constexpr const static size_t hitPositionWorld = 0x6c;
		constexpr const static size_t hitPartID = 0x84;
		constexpr const static size_t hitMaterialID = 0x20;
		constexpr const static size_t srcParentID = 0x48;
		constexpr const static size_t dstParentID = 0x28;
	}


	// obf name: ::%58c303f6b590d32f408cee691a7e5d0529ee6bf0
#define EntityRef_ClassName "%58c303f6b590d32f408cee691a7e5d0529ee6bf0"
#define EntityRef_ClassNameShort "%58c303f6b590d32f408cee691a7e5d0529ee6bf0"
#define EntityRef_TypeDefinitionIndex 2370

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x18ab580;
	}
}