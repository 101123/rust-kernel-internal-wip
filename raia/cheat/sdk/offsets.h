#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68f1ea22;
		constexpr const static size_t gc_handles = 0xd271040;
		constexpr const static size_t il2cpp_resolve_icall = 0x5b7290;
		constexpr const static size_t il2cpp_array_new = 0x5b72b0;
		constexpr const static size_t il2cpp_assembly_get_image = 0x3cd10;
		constexpr const static size_t il2cpp_class_from_name = 0x5b7420;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x5b7730;
		constexpr const static size_t il2cpp_class_get_type = 0x5b77d0;
		constexpr const static size_t il2cpp_domain_get = 0x5b7d30;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x5b7d50;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x5b8610;
		constexpr const static size_t il2cpp_gchandle_new = 0x5b85c0;
		constexpr const static size_t il2cpp_gchandle_free = 0x5b86b0;
		constexpr const static size_t il2cpp_method_get_name = 0x3150;
		constexpr const static size_t il2cpp_object_new = 0x5b8d60;
		constexpr const static size_t il2cpp_type_get_object = 0x5b9550;
	}

#define Object_TypeDefinitionIndex 16955

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xacfc4c0;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16926

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

#define Component_TypeDefinitionIndex 16913

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16907

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 16990

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xad08080;
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

#define Camera_TypeDefinitionIndex 16705

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16977

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

#define Material_TypeDefinitionIndex 16768

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16764

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xacbbe90;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16767

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xacbfb50;
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16823

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

#define Renderer_TypeDefinitionIndex 16765

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16826

	namespace Texture {

		// Functions
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16828

	namespace Texture2D {

		// Functions
		constexpr const static size_t ctor = 0xacd5aa0;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define Sprite_TypeDefinitionIndex 16996

	namespace Sprite {

		// Functions
		constexpr const static size_t get_texture = 0x119300;
	}

#define RenderTexture_TypeDefinitionIndex 16833

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xacde720;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17303

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xad228f0;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17279

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xad1c740;
	}

#define ComputeBuffer_TypeDefinitionIndex 16968

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xacfffb0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xad00200;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16772

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xacc6a90;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xacc67c0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 22028

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xad451a0;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16745

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16856

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24667

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16742

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24545

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

#define Application_TypeDefinitionIndex 16688

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16854

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23517

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xad8b240;
		constexpr const static size_t RaycastNonAlloc = 0xad8d910;
	}

#define Image_TypeDefinitionIndex 21111

	namespace Image {

		// Offsets
		constexpr const static size_t m_Sprite = 0xd0;
	}

#define BaseNetworkable_TypeDefinitionIndex 4715

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x78;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x28;
	}

	// obf name: ::%d4431719d1211d9ffcf210c83f94e672f8d9359b
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%d4431719d1211d9ffcf210c83f94e672f8d9359b"
#define BaseNetworkable_Static_ClassNameShort "%d4431719d1211d9ffcf210c83f94e672f8d9359b"
#define BaseNetworkable_Static_TypeDefinitionIndex 4714

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x20;
	}

	// obf name: ::%ebc7e0167fe72d2c7b05a3a0315f3b873d72c7c9
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%ebc7e0167fe72d2c7b05a3a0315f3b873d72c7c9"
#define BaseNetworkable_EntityRealm_ClassNameShort "%ebc7e0167fe72d2c7b05a3a0315f3b873d72c7c9"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 4712

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x2f32300;
	}

	// obf name: ::%e9a62292ee4dcb81a71d8c2a6a839e626b676260
#define System_ListDictionary_ClassName "%e9a62292ee4dcb81a71d8c2a6a839e626b676260<%930cff9439b14175c439704f93e69ed8b316f855,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%e9a62292ee4dcb81a71d8c2a6a839e626b676260"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x10;

		// Functions
		constexpr const static size_t TryGetValue = 0x7aab9f0;
		constexpr const static size_t TryGetValue_methodinfo = 0xcf0afd0;
	}

	// obf name: ::%abe61e66aa1fc38fff3b5c175e1f619ac9f73d31
#define System_BufferList_ClassName "%abe61e66aa1fc38fff3b5c175e1f619ac9f73d31<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%abe61e66aa1fc38fff3b5c175e1f619ac9f73d31"
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
		constexpr const static size_t Instance = 0x18;
	}

#define Model_TypeDefinitionIndex 1243

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t eyeBone = 0x38;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 5799

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0x118;
		constexpr const static size_t positionLerp = 0x158;

		// Functions
		constexpr const static size_t ServerRPC = 0x3b7bed0;
		constexpr const static size_t FindBone = 0x3b3d480;
		constexpr const static size_t GetWorldVelocity = 0x3b7e4e0;
		constexpr const static size_t GetParentVelocity = 0x3b2ee90;
	}

	// obf name: ::%8b020aa191cad505d3f332e6d6dba0890ea0a82a
#define PositionLerp_ClassName "%8b020aa191cad505d3f332e6d6dba0890ea0a82a"
#define PositionLerp_ClassNameShort "%8b020aa191cad505d3f332e6d6dba0890ea0a82a"
#define PositionLerp_TypeDefinitionIndex 4888

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x38;
	}

	// obf name: ::%39e7505dee14349db62a10b19c31e31d390cf2c9
#define Interpolator_ClassName "%39e7505dee14349db62a10b19c31e31d390cf2c9<%74d42144e79b9668714df4a332170c58ede1d456>"
#define Interpolator_ClassNameShort "%39e7505dee14349db62a10b19c31e31d390cf2c9"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 7104

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

#define SkeletonProperties_TypeDefinitionIndex 659

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 657

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 857

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 856

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%5380be5c83be061e1f94cc674663a0de2082550c
#define DamageTypeList_ClassName "%5380be5c83be061e1f94cc674663a0de2082550c"
#define DamageTypeList_ClassNameShort "%5380be5c83be061e1f94cc674663a0de2082550c"
#define DamageTypeList_TypeDefinitionIndex 5541

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 6367

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 244

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x40;
		constexpr const static size_t iconSprite = 0x50;
		constexpr const static size_t category = 0x58;
		constexpr const static size_t stackable = 0x70;
		constexpr const static size_t rarity = 0x88;
		constexpr const static size_t condition = 0xb0;
		constexpr const static size_t ItemModWearable = 0x168;
	}

#define RecoilProperties_TypeDefinitionIndex 2110

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 4321

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 345

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x1f85f10;
		constexpr const static size_t StartAttackCooldown = 0x1f85100;
	}

#define BaseProjectile_TypeDefinitionIndex 4325

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
		constexpr const static size_t LaunchProjectile = 0x29dce00;
		constexpr const static size_t LaunchProjectileClientSide = 0x29ea020;
		constexpr const static size_t ScaleRepeatDelay = 0x29fa330;
		constexpr const static size_t GetAimCone = 0x29d1d00;
		constexpr const static size_t GetAimCone_vtableoff = 0x3d78;
		constexpr const static size_t UpdateAmmoDisplay = 0x29e20a0;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3ee8;
	}

#define BaseLauncher_TypeDefinitionIndex 3090

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 471

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%0d387e4acb7fe13e9ee728a0eb52b5c0021b323e
#define HitTest_ClassName "%0d387e4acb7fe13e9ee728a0eb52b5c0021b323e"
#define HitTest_ClassNameShort "%0d387e4acb7fe13e9ee728a0eb52b5c0021b323e"
#define HitTest_TypeDefinitionIndex 986

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x20;
		constexpr const static size_t AttackRay = 0x48;
		constexpr const static size_t RayHit = 0x94;
		constexpr const static size_t damageProperties = 0x78;
		constexpr const static size_t gameObject = 0x60;
		constexpr const static size_t collider = 0xc8;
		constexpr const static size_t ignoredTypes = 0x68;
		constexpr const static size_t HitTransform = 0x40;
		constexpr const static size_t HitPart = 0xc0;
		constexpr const static size_t HitMaterial = 0xd0;
		constexpr const static size_t DidHit = 0x80;
		constexpr const static size_t MaxDistance = 0x90;
		constexpr const static size_t HitNormal = 0x14;
		constexpr const static size_t HitPoint = 0x30;
		constexpr const static size_t ignoreEntity = 0x28;
		constexpr const static size_t HitEntity = 0x88;
	}

#define Projectile_TypeDefinitionIndex 6592

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
		constexpr const static size_t sourceProjectilePrefab = 0x108;
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
		constexpr const static size_t CalculateEffectScale = 0x4434fb0;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x448;
		constexpr const static size_t SetEffectScale = 0x4436c20;
		constexpr const static size_t UpdateVelocity = 0x43fae10;
		constexpr const static size_t Retire = 0x4434230;
		constexpr const static size_t DoHit = 0x4419860;
	}

	// obf name: ::%044c977ff085f75ef72561757e906578158eec44
#define HitInfo_ClassName "%044c977ff085f75ef72561757e906578158eec44"
#define HitInfo_ClassNameShort "%044c977ff085f75ef72561757e906578158eec44"
#define HitInfo_TypeDefinitionIndex 4680

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x40;
		constexpr const static size_t damageTypes = 0x38;

		// Functions
		constexpr const static size_t get_boneArea = 0x2eb1bb0;
	}

	// obf name: ::%ddd56f17fe29677724d344905761dac10a04dfda
#define GameTrace_ClassName "%ddd56f17fe29677724d344905761dac10a04dfda"
#define GameTrace_ClassNameShort "%ddd56f17fe29677724d344905761dac10a04dfda"
#define GameTrace_TypeDefinitionIndex 3570

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x2091f60;
	}

#define BaseMelee_TypeDefinitionIndex 6140

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x3f3d010;
		constexpr const static size_t DoThrow = 0x3f428e0;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 6474

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x408;
		constexpr const static size_t strikeRecoil = 0x410;
		constexpr const static size_t _didSparkThisFrame = 0x418;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 4020

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x420;
		constexpr const static size_t stringBonusVelocity = 0x42c;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x25f0b00;
	}

	// obf name: ::%0bdde7430882aef819cde6f4036c087265553b64
#define ItemContainer_ClassName "%0bdde7430882aef819cde6f4036c087265553b64"
#define ItemContainer_ClassNameShort "%0bdde7430882aef819cde6f4036c087265553b64"
#define ItemContainer_TypeDefinitionIndex 5121

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x70;
		constexpr const static size_t itemList = 0x68;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x33f8fb0;
	}

#define PlayerLoot_TypeDefinitionIndex 3263

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 1970

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerMain = 0x30;
		constexpr const static size_t containerBelt = 0x58;
		constexpr const static size_t containerWear = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x1097260;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 1845

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0xf41650;
		constexpr const static size_t get_rotation = 0xf34a70;
		constexpr const static size_t set_rotation = 0xf5b1a0;
		constexpr const static size_t HeadForward = 0xf393e0;
	}

	// obf name: ::%c8242a1b5e6e036b8fd939d4c23487f774805fb6
#define PlayerEyes_Static_ClassName "PlayerEyes/%c8242a1b5e6e036b8fd939d4c23487f774805fb6"
#define PlayerEyes_Static_ClassNameShort "%c8242a1b5e6e036b8fd939d4c23487f774805fb6"
#define PlayerEyes_Static_TypeDefinitionIndex 1844

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x90;
	}

	// obf name: ::%1873d96d7ca3ea24af9584a407e666d9791714cb
#define PlayerBelt_ClassName "%1873d96d7ca3ea24af9584a407e666d9791714cb"
#define PlayerBelt_ClassNameShort "%1873d96d7ca3ea24af9584a407e666d9791714cb"
#define PlayerBelt_TypeDefinitionIndex 3253

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x1d7f380;
		constexpr const static size_t GetActiveItem = 0x1d82450;
	}

	// obf name: ::%14c804135a6c3a43bcd42f7c8474d381ad82374d
#define LocalPlayer_ClassName "%14c804135a6c3a43bcd42f7c8474d381ad82374d"
#define LocalPlayer_ClassNameShort "%14c804135a6c3a43bcd42f7c8474d381ad82374d"
#define LocalPlayer_TypeDefinitionIndex 3898

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x248daf0;
		constexpr const static size_t MoveItem = 0x2498760;
		constexpr const static size_t get_Entity = 0x2497320;
	}

	// obf name: ::%1aa9e3817eb28257c59b4a51c5a4219d65abf14a
#define LocalPlayer_Static_ClassName "%14c804135a6c3a43bcd42f7c8474d381ad82374d/%1aa9e3817eb28257c59b4a51c5a4219d65abf14a"
#define LocalPlayer_Static_ClassNameShort "%1aa9e3817eb28257c59b4a51c5a4219d65abf14a"
#define LocalPlayer_Static_TypeDefinitionIndex 3897

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x18;
	}

	// obf name: ::%399edbd6b36f24fde838f945dc8afb8a0d707e73
#define BasePlayer_Static_ClassName "BasePlayer/%399edbd6b36f24fde838f945dc8afb8a0d707e73"
#define BasePlayer_Static_ClassNameShort "%399edbd6b36f24fde838f945dc8afb8a0d707e73"
#define BasePlayer_Static_TypeDefinitionIndex 6927

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0xd18;
	}

#define BasePlayer_TypeDefinitionIndex 6928

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x280;
		constexpr const static size_t input = 0x600;
		constexpr const static size_t movement = 0x360;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x408;
		constexpr const static size_t playerFlags = 0x598;
		constexpr const static size_t eyes = 0x318;
		constexpr const static size_t playerRigidbody = 0x420;
		constexpr const static size_t userID = 0x5e0;
		constexpr const static size_t UserIDString = 0x328;
		constexpr const static size_t inventory = 0x450;
		constexpr const static size_t _displayName = 0x5b0;
		constexpr const static size_t _lookingAt = 0x5a0;
		constexpr const static size_t lastSentTickTime = 0x554;
		constexpr const static size_t lastSentTick = 0x480;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x3e0;
		constexpr const static size_t _lookingAtEntity = 0x3c0;
		constexpr const static size_t currentGesture = 0x2a8;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x48a3640;
		constexpr const static size_t Menu_AssistPlayer = 0x4991720;
		constexpr const static size_t OnViewModeChanged = 0x4849210;
		constexpr const static size_t ChatMessage = 0x48ebaf0;
		constexpr const static size_t IsOnGround = 0x4847650;
		constexpr const static size_t GetSpeed = 0x49083b0;
		constexpr const static size_t SendProjectileUpdate = 0x4954b10;
		constexpr const static size_t SendProjectileAttack = 0x0;
		constexpr const static size_t CanBuild = 0x48db440;
		constexpr const static size_t GetMounted = 0x49dabd0;
		constexpr const static size_t GetHeldEntity = 0x4899cd0;
		constexpr const static size_t get_inventory = 0x498b230;
		constexpr const static size_t get_eyes = 0x498d130;
		constexpr const static size_t SendClientTick = 0x48913d0;
		constexpr const static size_t ClientInput = 0x4985e70;
		constexpr const static size_t ClientInput_vtableoff = 0x3c48;
		constexpr const static size_t MaxHealth = 0x484ed30;
		constexpr const static size_t MaxHealth_vtableoff = 0x2348;
		constexpr const static size_t OnAttacked = 0x493dbb0;
		constexpr const static size_t OnAttacked_vtableoff = 0xe08;
		constexpr const static size_t get_idealViewMode = 0x4985ab0;
	}

#define ScientistNPC_TypeDefinitionIndex 6535

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 4034

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 3201

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 1290

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 3040

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 5933

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 2654

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x176f090;
		constexpr const static size_t BlockSprint = 0x1764f60;
		constexpr const static size_t GroundCheck = 0x176a970;
		constexpr const static size_t ClientInput = 0x173bc80;
		constexpr const static size_t ClientInput_vtableoff = 0x3a8;
		constexpr const static size_t DoFixedUpdate = 0x173f670;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x218;
		constexpr const static size_t FrameUpdate = 0x175cd80;
		constexpr const static size_t FrameUpdate_vtableoff = 0x388;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 3937

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 285

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 349

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 4061

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 4057

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%73fdd0faf2e462b8348890bac4bf213614324114
#define ConsoleSystem_ClassName "%73fdd0faf2e462b8348890bac4bf213614324114"
#define ConsoleSystem_ClassNameShort "%73fdd0faf2e462b8348890bac4bf213614324114"
#define ConsoleSystem_TypeDefinitionIndex 23482

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x6258750;
	}

	// obf name: ::%dbfa9c5713ef1fb6cfd8f134ccdb8bc79667fd47
#define ConsoleSystem_Index_Static_ClassName "%73fdd0faf2e462b8348890bac4bf213614324114/%43717f359845ce8089f905b105e673810f541023.%dbfa9c5713ef1fb6cfd8f134ccdb8bc79667fd47"
#define ConsoleSystem_Index_Static_ClassNameShort "%dbfa9c5713ef1fb6cfd8f134ccdb8bc79667fd47"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23475

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0xb8;
	}

#define LootableCorpse_TypeDefinitionIndex 5099

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2c8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 5248

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 4600

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x58;
		constexpr const static size_t mainCameraTransform = 0x10;

		// Functions
		constexpr const static size_t Update = 0x2e1d8a0;
		constexpr const static size_t OnPreCull = 0x2e0dcc0;
		constexpr const static size_t Trace = 0x2e1e8d0;
	}

#define CameraMan_TypeDefinitionIndex 976

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%aae2660f997f07ad1b171eeb31f624031df09953
#define PlayerTick_ClassName "%aae2660f997f07ad1b171eeb31f624031df09953"
#define PlayerTick_ClassNameShort "%aae2660f997f07ad1b171eeb31f624031df09953"
#define PlayerTick_TypeDefinitionIndex 7506

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x20;
		constexpr const static size_t modelState = 0x28;
		constexpr const static size_t activeItem = 0x50;
		constexpr const static size_t parentID = 0x40;
		constexpr const static size_t intermediatePosition = 0x10;
		constexpr const static size_t position = 0x34;
		constexpr const static size_t eyePos = 0x58;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8bcafb0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8bc86c0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%84d87dd09eeefad1203681b07de12c98473acde6
#define InputMessage_ClassName "%84d87dd09eeefad1203681b07de12c98473acde6"
#define InputMessage_ClassNameShort "%84d87dd09eeefad1203681b07de12c98473acde6"
#define InputMessage_TypeDefinitionIndex 7295

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x14;
		constexpr const static size_t aimAngles = 0x18;
		constexpr const static size_t mouseDelta = 0x28;
	}

	// obf name: ::%6966464e524b612bcacd633deeac7a418f8a7585
#define InputState_ClassName "%6966464e524b612bcacd633deeac7a418f8a7585"
#define InputState_ClassNameShort "%6966464e524b612bcacd633deeac7a418f8a7585"
#define InputState_TypeDefinitionIndex 3219

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x20;
		constexpr const static size_t previous = 0x10;
	}

#define PlayerInput_TypeDefinitionIndex 6631

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%f638ea25ecf80d7786ed60e6ab408c88b10b91d0
#define ModelState_ClassName "%f638ea25ecf80d7786ed60e6ab408c88b10b91d0"
#define ModelState_ClassNameShort "%f638ea25ecf80d7786ed60e6ab408c88b10b91d0"
#define ModelState_TypeDefinitionIndex 7364

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x10;
		constexpr const static size_t waterLevel = 0x34;
		constexpr const static size_t lookDir = 0x64;
	}

	// obf name: ::%8dffeb3dd72f717469b47cb0302d8c6b9feae829
#define Item_ClassName "%8dffeb3dd72f717469b47cb0302d8c6b9feae829"
#define Item_ClassNameShort "%8dffeb3dd72f717469b47cb0302d8c6b9feae829"
#define Item_TypeDefinitionIndex 4476

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x38;
		constexpr const static size_t uid = 0x58;
		constexpr const static size_t _condition = 0x7c;
		constexpr const static size_t _maxCondition = 0xc0;
		constexpr const static size_t amount = 0x98;
		constexpr const static size_t position = 0xd0;
		constexpr const static size_t contents = 0x60;
		constexpr const static size_t parent = 0xa0;
		constexpr const static size_t heldEntity = 0x20;
		constexpr const static size_t worldEnt = 0xb0;

		// Functions
		constexpr const static size_t get_iconSprite = 0x2b863b0;
	}

	// obf name: ::%bf05859c8d6735c72c3805e73483ed21181db07d
#define WaterLevel_ClassName "%bf05859c8d6735c72c3805e73483ed21181db07d"
#define WaterLevel_ClassNameShort "%bf05859c8d6735c72c3805e73483ed21181db07d"
#define WaterLevel_TypeDefinitionIndex 2559

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x1637ff0;
		constexpr const static size_t GetWaterLevel = 0x165d080;
	}

	// obf name: ::%6e39c5b30697cd133a2bdda8b73d6b0fda6e3cf6
#define ConVar_Graphics_Static_ClassName "%7d230e5f1b958f8b797218132e84f84b748bea6f/%6e39c5b30697cd133a2bdda8b73d6b0fda6e3cf6"
#define ConVar_Graphics_Static_ClassNameShort "%6e39c5b30697cd133a2bdda8b73d6b0fda6e3cf6"
#define ConVar_Graphics_Static_TypeDefinitionIndex 6043

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x3e8;

		// Functions
		constexpr const static size_t _fov_getter = 0x2b15f50;
		constexpr const static size_t _fov_setter = 0x2b29c50;
	}

#define BaseFishingRod_TypeDefinitionIndex 2251

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
		constexpr const static size_t UpdateLineRenderer = 0x133d180;
		constexpr const static size_t EvaluateFishingPosition = 0x135a940;
	}

#define FishingBobber_TypeDefinitionIndex 1638

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 4120

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x26cf9c0;
	}

	// obf name: ::%48f068a414c70adab451c5e4f02c11c1fddf53f0
#define GameManager_ClassName "%48f068a414c70adab451c5e4f02c11c1fddf53f0"
#define GameManager_ClassNameShort "%48f068a414c70adab451c5e4f02c11c1fddf53f0"
#define GameManager_TypeDefinitionIndex 5904

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x28;

		// Functions
		constexpr const static size_t CreatePrefab = 0x3d0a030;
	}

	// obf name: ::%895bb3ffd5812f3f376874d606e6fa351d71c489
#define GameManager_Static_ClassName "%48f068a414c70adab451c5e4f02c11c1fddf53f0/%895bb3ffd5812f3f376874d606e6fa351d71c489"
#define GameManager_Static_ClassNameShort "%895bb3ffd5812f3f376874d606e6fa351d71c489"
#define GameManager_Static_TypeDefinitionIndex 5903

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x20;
	}

	// obf name: ::%0688896f0268b6e0653b2d35d9560f1d9ddb57da
#define PrefabPoolCollection_ClassName "%0688896f0268b6e0653b2d35d9560f1d9ddb57da"
#define PrefabPoolCollection_ClassNameShort "%0688896f0268b6e0653b2d35d9560f1d9ddb57da"
#define PrefabPoolCollection_TypeDefinitionIndex 3550

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%a05ce5348787ecdc26576aeeb988e66c66939f79
#define PrefabPool_ClassName "%a05ce5348787ecdc26576aeeb988e66c66939f79"
#define PrefabPool_ClassNameShort "%a05ce5348787ecdc26576aeeb988e66c66939f79"
#define PrefabPool_TypeDefinitionIndex 2131

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x18;
	}

#define ItemModProjectile_TypeDefinitionIndex 1016

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

#define CraftingQueue_TypeDefinitionIndex 5909

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%305940a91faf2464b5c05e4250008970e6dc6995
#define CraftingQueue_Static_ClassName "CraftingQueue/%305940a91faf2464b5c05e4250008970e6dc6995"
#define CraftingQueue_Static_ClassNameShort "%305940a91faf2464b5c05e4250008970e6dc6995"
#define CraftingQueue_Static_TypeDefinitionIndex 5908

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x58;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 3812

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%593c4a78aa6507c28d00ba8f991a6d6421d8c3a3
#define Planner_Static_ClassName "Planner/%593c4a78aa6507c28d00ba8f991a6d6421d8c3a3"
#define Planner_Static_ClassNameShort "%593c4a78aa6507c28d00ba8f991a6d6421d8c3a3"
#define Planner_Static_TypeDefinitionIndex 2692

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x130;
	}

	// obf name: ::%83326c5fc449718af13ac33167290dcd67d49e42
#define Planner_Guide_ClassName "Planner/%83326c5fc449718af13ac33167290dcd67d49e42"
#define Planner_Guide_ClassNameShort "%83326c5fc449718af13ac33167290dcd67d49e42"
#define Planner_Guide_TypeDefinitionIndex 2688

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x90;
	}

#define Planner_TypeDefinitionIndex 2693

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x288;
	}

#define Construction_TypeDefinitionIndex 128

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x170;
	}

#define BuildingBlock_TypeDefinitionIndex 3126

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x310;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 6403

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x425c9c0;
	}

	// obf name: ::%a683457d8d9cfd91545513be25983389af59d76a
#define PunchEntry_ClassName "HeldEntity/%a683457d8d9cfd91545513be25983389af59d76a"
#define PunchEntry_ClassNameShort "%a683457d8d9cfd91545513be25983389af59d76a"
#define PunchEntry_TypeDefinitionIndex 6401

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x28;
		constexpr const static size_t startTime = 0x2c;
		constexpr const static size_t amountAdded = 0x10;
		constexpr const static size_t amount = 0x1c;
	}

#define IronSights_TypeDefinitionIndex 5853

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 1966

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 3760

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xb8;
		constexpr const static size_t model = 0xe0;
		constexpr const static size_t lower = 0x80;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x22a27c0;
	}

#define ViewModel_TypeDefinitionIndex 2049

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x1187f90;
		constexpr const static size_t PlayString = 0x1188310;
	}

#define MedicalTool_TypeDefinitionIndex 5394

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 159

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x68;
	}

	// obf name: ::%d6cd89958a4c4ebec56ed81457b24170ce806e08
#define WaterSystem_Static_ClassName "WaterSystem/%d6cd89958a4c4ebec56ed81457b24170ce806e08"
#define WaterSystem_Static_ClassNameShort "%d6cd89958a4c4ebec56ed81457b24170ce806e08"
#define WaterSystem_Static_TypeDefinitionIndex 4497

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x190;
	}

#define WaterSystem_TypeDefinitionIndex 4498

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x2bc2400;
	}

#define TerrainMeta_TypeDefinitionIndex 3485

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x3f0;
		constexpr const static size_t HeightMap = 0x178;
		constexpr const static size_t SplatMap = 0x3e0;
		constexpr const static size_t TopologyMap = 0x140;
		constexpr const static size_t Texturing = 0x588;
	}

#define TerrainCollision_TypeDefinitionIndex 6059

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x3e990d0;
	}

#define TerrainHeightMap_TypeDefinitionIndex 7042

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 3992

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 4196

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%20b63aedcbf26806d96f40da768141952e3832c6
#define World_Static_ClassName "%b2dcd2d1c6a2e3e084f792020b76c026e13a8443/%20b63aedcbf26806d96f40da768141952e3832c6"
#define World_Static_ClassNameShort "%20b63aedcbf26806d96f40da768141952e3832c6"
#define World_Static_TypeDefinitionIndex 4984

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x68;
	}

#define ItemIcon_TypeDefinitionIndex 4554

	namespace ItemIcon {

		// Offsets
		constexpr const static size_t backgroundImage = 0xe8;

		// Functions
		constexpr const static size_t TryToMove = 0x2cb27a0;
		constexpr const static size_t TryToMove_vtableoff = 0x468;
		constexpr const static size_t RunTimedAction = 0x2cb2160;
	}

	// obf name: ::%5922687890d05735d118ab696218a94e8ae75ed0
#define ItemIcon_Static_ClassName "ItemIcon/%5922687890d05735d118ab696218a94e8ae75ed0"
#define ItemIcon_Static_ClassNameShort "%5922687890d05735d118ab696218a94e8ae75ed0"
#define ItemIcon_Static_TypeDefinitionIndex 4553

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x10;
	}

	// obf name: ::%dab7a757b7bb6f9816671fcdaf1bf8748b796c01
#define Effect_ClassName "%dab7a757b7bb6f9816671fcdaf1bf8748b796c01"
#define Effect_ClassNameShort "%dab7a757b7bb6f9816671fcdaf1bf8748b796c01"
#define Effect_TypeDefinitionIndex 1502

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x98;
		constexpr const static size_t worldPos = 0xa4;
	}

	// obf name: ::%ce050258f59363283d3ff313baddcffe6c4563ac
#define EffectLibrary_ClassName "%ce050258f59363283d3ff313baddcffe6c4563ac"
#define EffectLibrary_ClassNameShort "%ce050258f59363283d3ff313baddcffe6c4563ac"
#define EffectLibrary_TypeDefinitionIndex 1260

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x51b0f10;
	}

	// obf name: ::%7d23954603db362f7d8790f894867051ce8b6b2b
#define EffectNetwork_ClassName "%7d23954603db362f7d8790f894867051ce8b6b2b"
#define EffectNetwork_ClassNameShort "%7d23954603db362f7d8790f894867051ce8b6b2b"
#define EffectNetwork_TypeDefinitionIndex 4484

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%f5c89e76d710a052111355fc94d8e9a4d86ddcfe
#define EffectNetwork_Static_ClassName "%7d23954603db362f7d8790f894867051ce8b6b2b/%f5c89e76d710a052111355fc94d8e9a4d86ddcfe"
#define EffectNetwork_Static_ClassNameShort "%f5c89e76d710a052111355fc94d8e9a4d86ddcfe"
#define EffectNetwork_Static_TypeDefinitionIndex 4483

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x10;

		// Functions
		constexpr const static size_t cctor = 0x2c43e50;
	}

#define BuildingBlock_TypeDefinitionIndex 3126

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x1c338a0;
		constexpr const static size_t HasUpgradePrivilege = 0x1c1fa40;
		constexpr const static size_t CanAffordUpgrade = 0x1c38c90;
	}

	// obf name: ::%e604a5bc16baa1892fb68e161d284a936104e30a
#define GameObjectEx_ClassName "%e604a5bc16baa1892fb68e161d284a936104e30a"
#define GameObjectEx_ClassNameShort "%e604a5bc16baa1892fb68e161d284a936104e30a"
#define GameObjectEx_TypeDefinitionIndex 6196

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x3fcb340;
	}

#define UIDeathScreen_TypeDefinitionIndex 6003

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x3de3220;
	}

	// obf name: ::%cf644fe2f774a7480eedf4aa5ffbc6341639e662
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%cf644fe2f774a7480eedf4aa5ffbc6341639e662"
#define BaseScreenShake_Static_ClassNameShort "%cf644fe2f774a7480eedf4aa5ffbc6341639e662"
#define BaseScreenShake_Static_TypeDefinitionIndex 2100

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x98;
	}

#define FlashbangOverlay_TypeDefinitionIndex 1960

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x8;
		constexpr const static size_t flashLength = 0x40;
	}

	// obf name: ::%d106a85493d31663ab5eea702f27c0a8660765fd
#define StringPool_ClassName "%d106a85493d31663ab5eea702f27c0a8660765fd"
#define StringPool_ClassNameShort "%d106a85493d31663ab5eea702f27c0a8660765fd"
#define StringPool_TypeDefinitionIndex 6469

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x68;

		// Functions
		constexpr const static size_t Get = 0x42d3800;
	}

	// obf name: ::%daefd3d12547e4b0c2215620244cf5347393053a
#define Network_Networkable_ClassName "%daefd3d12547e4b0c2215620244cf5347393053a"
#define Network_Networkable_ClassNameShort "%daefd3d12547e4b0c2215620244cf5347393053a"
#define Network_Networkable_TypeDefinitionIndex 19308

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x50;
	}

	// obf name: ::%834a223713be1a80647f529067d97a4d826cca2a
#define Network_Net_ClassName "%834a223713be1a80647f529067d97a4d826cca2a"
#define Network_Net_ClassNameShort "%834a223713be1a80647f529067d97a4d826cca2a"
#define Network_Net_TypeDefinitionIndex 9477

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x38;
	}

	// obf name: ::%a8eb5cc0bcb0be194a44dc3c069d9714b27070f0
#define Network_Client_ClassName "%a8eb5cc0bcb0be194a44dc3c069d9714b27070f0"
#define Network_Client_ClassNameShort "%a8eb5cc0bcb0be194a44dc3c069d9714b27070f0"
#define Network_Client_TypeDefinitionIndex 19301

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0x108;
		constexpr const static size_t ConnectedPort = 0x100;
		constexpr const static size_t ServerName = 0xe0;
		constexpr const static size_t ConnectedAddress = 0xe8;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x62e4470;
		constexpr const static size_t DestroyNetworkable = 0x62e40f0;
	}

	// obf name: ::%b45407721cdd3220c178e63562183e0200cc956c
#define Network_BaseNetwork_ClassName "%b45407721cdd3220c178e63562183e0200cc956c"
#define Network_BaseNetwork_ClassNameShort "%b45407721cdd3220c178e63562183e0200cc956c"
#define Network_BaseNetwork_TypeDefinitionIndex 19307

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x62d95c0;
	}

	// obf name: ::%6744c2ca1a5adde4d3cde3ca4dd29f9bfd2ff370
#define Network_SendInfo_ClassName "%6744c2ca1a5adde4d3cde3ca4dd29f9bfd2ff370"
#define Network_SendInfo_ClassNameShort "%6744c2ca1a5adde4d3cde3ca4dd29f9bfd2ff370"
#define Network_SendInfo_TypeDefinitionIndex 19352

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%e42f632238227bf5184e92c688aaa556d98c5195
#define Network_Message_ClassName "%e42f632238227bf5184e92c688aaa556d98c5195"
#define Network_Message_ClassNameShort "%e42f632238227bf5184e92c688aaa556d98c5195"
#define Network_Message_TypeDefinitionIndex 19318

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x20;
		constexpr const static size_t read = 0x18;
	}

	// obf name: ::%7e141f7e0a48b7870d14115743ff11f3656184e6
#define Network_NetRead_ClassName "%7e141f7e0a48b7870d14115743ff11f3656184e6"
#define Network_NetRead_ClassNameShort "%7e141f7e0a48b7870d14115743ff11f3656184e6"
#define Network_NetRead_TypeDefinitionIndex 19320

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x40;
	}

	// obf name: ::%6daccf096e66e898cdc126fe4e631842c3703897
#define Network_NetWrite_ClassName "%6daccf096e66e898cdc126fe4e631842c3703897"
#define Network_NetWrite_ClassNameShort "%6daccf096e66e898cdc126fe4e631842c3703897"
#define Network_NetWrite_TypeDefinitionIndex 19315

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x48;

		// Functions
		constexpr const static size_t WriteByte = 0x6301730;
		constexpr const static size_t String = 0x6306c80;
		constexpr const static size_t Send = 0x62fc9a0;
	}

#define LootPanel_TypeDefinitionIndex 2979

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x1ac01f0;
	}

#define UIInventory_TypeDefinitionIndex 2464

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x15bae50;
	}

#define GrowableEntity_TypeDefinitionIndex 5123

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 5578

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 5577

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 21182

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 9078

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
		constexpr const static size_t get_Instance = 0x8d9630;
	}

	// obf name: ::%4b4851d6983dddda1f196f0db00bbdacb03c4c11
#define TOD_Sky_Static_ClassName "TOD_Sky/%4b4851d6983dddda1f196f0db00bbdacb03c4c11"
#define TOD_Sky_Static_ClassNameShort "%4b4851d6983dddda1f196f0db00bbdacb03c4c11"
#define TOD_Sky_Static_TypeDefinitionIndex 9077

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x50;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 9866

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xa91db0;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9250

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9770

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8867

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 8558

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 7698

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8039

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 4183

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 3848

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 5171

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 4506

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

#define EnvironmentManager_TypeDefinitionIndex 3942

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x257e820;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%c677b06cea77d5640cd87306c32a615cbf112f30/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24278

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 1020

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 1021

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 2275

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

	// obf name: ::%7d2be281a434077ccc4148f0db020fc8ff004aeb
#define ListHashSet_ClassName "%7d2be281a434077ccc4148f0db020fc8ff004aeb<UIChat>"
#define ListHashSet_ClassNameShort "%7d2be281a434077ccc4148f0db020fc8ff004aeb"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 4216

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3e8;
	}

#define Chainsaw_TypeDefinitionIndex 782

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%14f2e800bd8286a2d64d5ef73c731c60043760d7
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%14f2e800bd8286a2d64d5ef73c731c60043760d7"
#define CameraUpdateHook_Static_ClassNameShort "%14f2e800bd8286a2d64d5ef73c731c60043760d7"
#define CameraUpdateHook_Static_TypeDefinitionIndex 5582

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x90;
	}

#define SteamClientWrapper_TypeDefinitionIndex 1957

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x10a16f0;
	}

	// obf name: ::%8635ebec9ca816c062fe2f915ceca18d1dc3f1a4
#define AimConeUtil_ClassName "%8635ebec9ca816c062fe2f915ceca18d1dc3f1a4"
#define AimConeUtil_ClassNameShort "%8635ebec9ca816c062fe2f915ceca18d1dc3f1a4"
#define AimConeUtil_TypeDefinitionIndex 610

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x3ecbac0;
	}

	// obf name: ::%469d6ccba10074f93275f55eb7449a685d26e0ca
#define Buttons_ConButton_ClassName "%28cd55cddb4bbd7bf305ed6388dceb0d82495162/%469d6ccba10074f93275f55eb7449a685d26e0ca"
#define Buttons_ConButton_ClassNameShort "%469d6ccba10074f93275f55eb7449a685d26e0ca"
#define Buttons_ConButton_TypeDefinitionIndex 2240

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%f75f15810532d2ea84d9893ac3167060bfff1d24
#define Buttons_Static_ClassName "%28cd55cddb4bbd7bf305ed6388dceb0d82495162/%f75f15810532d2ea84d9893ac3167060bfff1d24"
#define Buttons_Static_ClassNameShort "%f75f15810532d2ea84d9893ac3167060bfff1d24"
#define Buttons_Static_TypeDefinitionIndex 2241

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x610;
		constexpr const static size_t Attack = 0x30;
		constexpr const static size_t Attack2 = 0x2d8;
		constexpr const static size_t Forward = 0x7b8;
		constexpr const static size_t Backward = 0x468;
		constexpr const static size_t Right = 0xcb8;
		constexpr const static size_t Left = 0x940;
		constexpr const static size_t Sprint = 0x28;
		constexpr const static size_t Use = 0xbe8;

		// Functions
		constexpr const static size_t Pets_setter = 0x2b12c50;
	}

#define PlayerModel_TypeDefinitionIndex 4300

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x1e0;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 4720

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 3276

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 3052

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 1692

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x408;
		constexpr const static size_t wasAiming = 0x418;
	}

#define CrossbowWeapon_TypeDefinitionIndex 6041

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 7015

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%af3848dab25e952c2f0a7f7c6f9d404f22247116
#define ConVar_Admin_Static_ClassName "%2538015573c0f5348f9f57f4750761666ec4e9f2/%af3848dab25e952c2f0a7f7c6f9d404f22247116"
#define ConVar_Admin_Static_ClassNameShort "%af3848dab25e952c2f0a7f7c6f9d404f22247116"
#define ConVar_Admin_Static_TypeDefinitionIndex 4752

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0xdc;

		// Functions
		constexpr const static size_t admintime_getter = 0x2b0ac90;
		constexpr const static size_t admintime_setter = 0x2b3ea20;
	}

	// obf name: ::%9576488e3de4a2a71426543c39b55454efa4fe38
#define ConVar_Player_Static_ClassName "%ec2c87dd2116016c8f620e9e358e888c12c98e52/%9576488e3de4a2a71426543c39b55454efa4fe38"
#define ConVar_Player_Static_ClassNameShort "%9576488e3de4a2a71426543c39b55454efa4fe38"
#define ConVar_Player_Static_TypeDefinitionIndex 1311

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x94;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x2b3a600;
		constexpr const static size_t clientTickRate_setter = 0x2b30180;
	}

#define ColliderInfo_TypeDefinitionIndex 3399

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 6904

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 4736

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x378;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x2f683e0;
	}

#define Client_TypeDefinitionIndex 6619

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x4490f70;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%d8da6c05ecf28b4aec9ed90aa0fe149450f5f4c7
#define ItemManager_Static_ClassName "%463c0606aa6cbfb39eb84e088e77334bef0daacd/%d8da6c05ecf28b4aec9ed90aa0fe149450f5f4c7"
#define ItemManager_Static_ClassNameShort "%d8da6c05ecf28b4aec9ed90aa0fe149450f5f4c7"
#define ItemManager_Static_TypeDefinitionIndex 4037

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0xb0;
		constexpr const static size_t itemDictionary = 0x208;
		constexpr const static size_t itemDictionaryByName = 0x248;
	}

	// obf name: ::%b7f04eb126b3571dc9db37f8a41d46a4c33c921d
#define ConVar_Server_Static_ClassName "%e572e4546cc882c5ecd6bd10679365dbb55c1b7c/%b7f04eb126b3571dc9db37f8a41d46a4c33c921d"
#define ConVar_Server_Static_ClassNameShort "%b7f04eb126b3571dc9db37f8a41d46a4c33c921d"
#define ConVar_Server_Static_TypeDefinitionIndex 1641

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 2184

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x12a99a0;
	}

#define LoadingScreen_TypeDefinitionIndex 6258

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 1100

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%5c64472bb9176bca849a1639a06d8002da957c34"
#define MapView_Static_ClassNameShort "%5c64472bb9176bca849a1639a06d8002da957c34"
#define MapView_TypeDefinitionIndex 1169

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x5059f30;
	}

	// obf name: ::%60cbd7f5cf219b766c0e7355a18c961ee0cb9d7b
#define GamePhysics_Static_ClassName "%83a28e326946faac738dd3afe113b184eaada685/%60cbd7f5cf219b766c0e7355a18c961ee0cb9d7b"
#define GamePhysics_Static_ClassNameShort "%60cbd7f5cf219b766c0e7355a18c961ee0cb9d7b"
#define GamePhysics_Static_TypeDefinitionIndex 1127

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x48;
	}

	// obf name: ::%83a28e326946faac738dd3afe113b184eaada685
#define GamePhysics_ClassName "%83a28e326946faac738dd3afe113b184eaada685"
#define GamePhysics_ClassNameShort "%83a28e326946faac738dd3afe113b184eaada685"
#define GamePhysics_TypeDefinitionIndex 1128

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x4f8bc30;
		constexpr const static size_t LineOfSightInternal = 0x4f7ef30;
		constexpr const static size_t Verify = 0x4f8dfc0;
	}

#define InstancedDebugDraw_TypeDefinitionIndex 2405

	namespace InstancedDebugDraw {

		// Functions
		constexpr const static size_t AddInstance = 0x14eae90;
	}

	// obf name: ::%840c5dff56c788bfc7d249e9ce0d2956bffc0b6e
#define RaycastHitEx_ClassName "%840c5dff56c788bfc7d249e9ce0d2956bffc0b6e"
#define RaycastHitEx_ClassNameShort "%840c5dff56c788bfc7d249e9ce0d2956bffc0b6e"
#define RaycastHitEx_TypeDefinitionIndex 5410

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x376b950;
	}

	// obf name: ::%05c7b94af22e2d08239b7f25b994924d6604bf59
#define OnParentDestroyingEx_ClassName "%05c7b94af22e2d08239b7f25b994924d6604bf59"
#define OnParentDestroyingEx_ClassNameShort "%05c7b94af22e2d08239b7f25b994924d6604bf59"
#define OnParentDestroyingEx_TypeDefinitionIndex 7124

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x4beae60;
	}

	// obf name: ::%b0eaee4d0910e798727dba6b736a2502756ad72a
#define ConsoleNetwork_ClassName "%b0eaee4d0910e798727dba6b736a2502756ad72a"
#define ConsoleNetwork_ClassNameShort "%b0eaee4d0910e798727dba6b736a2502756ad72a"
#define ConsoleNetwork_TypeDefinitionIndex 4126

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x26e20d0;
	}

#define ThrownWeapon_TypeDefinitionIndex 2735

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 6030

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 6115

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 1169

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 7075

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 4071

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 5377

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 6062

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 6807

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 5101

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%c0bf4da53c2c627dac870a69baee1c9ae32ba265
#define ConVar_Client_Static_ClassName "%9a68162997c7ff89e6724859d6db92d60c2cf6cd/%c0bf4da53c2c627dac870a69baee1c9ae32ba265"
#define ConVar_Client_Static_ClassNameShort "%c0bf4da53c2c627dac870a69baee1c9ae32ba265"
#define ConVar_Client_Static_TypeDefinitionIndex 1564

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x580;
		constexpr const static size_t camspeed = 0x1ec;
	}

#define SamSite_TypeDefinitionIndex 1559

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 2067

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 6453

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 44

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 6542

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 2563

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 3069

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 2947

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%3289cb6f47a8435079ace15ebf8aa7c92882d11e
#define Facepunch_Network_Raknet_Client_ClassName "%3289cb6f47a8435079ace15ebf8aa7c92882d11e"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%3289cb6f47a8435079ace15ebf8aa7c92882d11e"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 22999

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x6381420;
		constexpr const static size_t IsConnected_vtableoff = 0x228;
	}

	// obf name: ::%29e62b933bf9bf2e2f361d8be08e79d934dac3f5
#define EncryptedValue_ClassName "%29e62b933bf9bf2e2f361d8be08e79d934dac3f5<System/Int32>"
#define EncryptedValue_ClassNameShort "%29e62b933bf9bf2e2f361d8be08e79d934dac3f5"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%6ed69be2ff6e7eb8dcffa08d4b6a4d305e5dab54
#define HiddenValue_ClassName "%6ed69be2ff6e7eb8dcffa08d4b6a4d305e5dab54<BaseNetworkable/%ebc7e0167fe72d2c7b05a3a0315f3b873d72c7c9>"
#define HiddenValue_ClassNameShort "%6ed69be2ff6e7eb8dcffa08d4b6a4d305e5dab54"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 2592

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x16d50c0;
	}

#define ItemModRFListener_TypeDefinitionIndex 3766

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x22ae890;
	}

#define UIFogOverlay_TypeDefinitionIndex 6453

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x30;
	}

	// obf name: ::%3be8b04813a5b237a85df9e46208ccf3acf4953b
#define BufferStream_ClassName "%3be8b04813a5b237a85df9e46208ccf3acf4953b"
#define BufferStream_ClassNameShort "%3be8b04813a5b237a85df9e46208ccf3acf4953b"
#define BufferStream_TypeDefinitionIndex 7356

	namespace BufferStream {

		// Offsets
		constexpr const static size_t _buffer = 0x10;

		// Functions
		constexpr const static size_t EnsureCapacity = 0x96c8db0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 2303

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 1426

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 392

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x224ac40;
	}

#define OutlineManager_TypeDefinitionIndex 362

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%5ade3b8d35afe64d037dac48e9fc938299c33dcc
#define ConsoleSystem_Command_ClassName "%73fdd0faf2e462b8348890bac4bf213614324114/%5ade3b8d35afe64d037dac48e9fc938299c33dcc"
#define ConsoleSystem_Command_ClassNameShort "%5ade3b8d35afe64d037dac48e9fc938299c33dcc"
#define ConsoleSystem_Command_TypeDefinitionIndex 23467

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x88;
		constexpr const static size_t SetOveride = 0x38;
		constexpr const static size_t Call = 0x78;
	}

	// obf name: ::%e636e59c98a0f64eac3145695dade9bf27dccb39
#define ConsoleSystem_Option_ClassName "%73fdd0faf2e462b8348890bac4bf213614324114/%e636e59c98a0f64eac3145695dade9bf27dccb39"
#define ConsoleSystem_Option_ClassNameShort "%e636e59c98a0f64eac3145695dade9bf27dccb39"
#define ConsoleSystem_Option_TypeDefinitionIndex 23477

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%177d09ae1ad6b14346472b41f4c47f593bc1b03a
#define ConsoleSystem_Arg_ClassName "%73fdd0faf2e462b8348890bac4bf213614324114/%177d09ae1ad6b14346472b41f4c47f593bc1b03a"
#define ConsoleSystem_Arg_ClassNameShort "%177d09ae1ad6b14346472b41f4c47f593bc1b03a"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23465

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x20;
	}

	// obf name: ::%210e51dfed1d15d721c064e255eb849bcedfe058
#define ConsoleSystem_Index_Client_ClassName "%73fdd0faf2e462b8348890bac4bf213614324114/%43717f359845ce8089f905b105e673810f541023.%210e51dfed1d15d721c064e255eb849bcedfe058"
#define ConsoleSystem_Index_Client_ClassNameShort "%210e51dfed1d15d721c064e255eb849bcedfe058"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23473

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x6261280;
	}

#define String_TypeDefinitionIndex 10402

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x83e86e0;
	}

	// obf name: ::%56e3ae0330017533f072509d2aa7439edbe603ee
#define EntityRef_ClassName "%56e3ae0330017533f072509d2aa7439edbe603ee"
#define EntityRef_ClassNameShort "%56e3ae0330017533f072509d2aa7439edbe603ee"
#define EntityRef_TypeDefinitionIndex 4315

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x2a0e9a0;
	}

#define ConVar_Debugging_TypeDefinitionIndex 24843

	namespace ConVar_Debugging {

		// Functions
		constexpr const static size_t debugcamera = 0x2b32a60;
		constexpr const static size_t noclip = 0x2b3b940;
	}

	// obf name: ::%427abdb7208abd5a918a8ebbf9ce61b39486d359
#define ProtoBuf_ProjectileShoot_ClassName "%427abdb7208abd5a918a8ebbf9ce61b39486d359"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%427abdb7208abd5a918a8ebbf9ce61b39486d359"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7581

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8e85840;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8e7bcf0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%b7ae6873e05bbde09ca09bbcf9430e7c8c487324
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%427abdb7208abd5a918a8ebbf9ce61b39486d359/%b7ae6873e05bbde09ca09bbcf9430e7c8c487324"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%b7ae6873e05bbde09ca09bbcf9430e7c8c487324"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7580

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x28;
		constexpr const static size_t startPos = 0x2c;
		constexpr const static size_t startVel = 0x10;
		constexpr const static size_t seed = 0x20;
	}

	// obf name: ::%490e09601eb84f91e32e4a440867e5ae27a84612
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%490e09601eb84f91e32e4a440867e5ae27a84612"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%490e09601eb84f91e32e4a440867e5ae27a84612"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7338

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x34;
		constexpr const static size_t curPosition = 0x20;
		constexpr const static size_t curVelocity = 0x10;
		constexpr const static size_t travelTime = 0x30;
		constexpr const static size_t ShouldPool = 0x1c;

		// Functions
		constexpr const static size_t Dispose = 0x9614420;
		constexpr const static size_t WriteToStreamDelta = 0x9615db0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9618690;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%83e97274290d16ab069f5cb475340447edbd7581
#define ProtoBuf_PlayerProjectileAttack_ClassName "%83e97274290d16ab069f5cb475340447edbd7581"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%83e97274290d16ab069f5cb475340447edbd7581"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7442

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x10;
		constexpr const static size_t hitDistance = 0x2c;
		constexpr const static size_t travelTime = 0x1c;
		constexpr const static size_t playerAttack = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x895b960;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x895b940;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%8c63a50eee29be30e878340602d5d85d0dd47fbf
#define ProtoBuf_PlayerAttack_ClassName "%8c63a50eee29be30e878340602d5d85d0dd47fbf"
#define ProtoBuf_PlayerAttack_ClassNameShort "%8c63a50eee29be30e878340602d5d85d0dd47fbf"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7382

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x10;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%f4d25135ea7371dd5b9985d1b43fb9c6a831c616
#define ProtoBuf_Attack_ClassName "%f4d25135ea7371dd5b9985d1b43fb9c6a831c616"
#define ProtoBuf_Attack_ClassNameShort "%f4d25135ea7371dd5b9985d1b43fb9c6a831c616"
#define ProtoBuf_Attack_TypeDefinitionIndex 7570

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x14;
		constexpr const static size_t pointEnd = 0x7c;
		constexpr const static size_t hitID = 0x30;
		constexpr const static size_t hitBone = 0x68;
		constexpr const static size_t hitNormalLocal = 0x6c;
		constexpr const static size_t hitPositionLocal = 0x20;
		constexpr const static size_t hitNormalWorld = 0x48;
		constexpr const static size_t hitPositionWorld = 0x54;
		constexpr const static size_t hitPartID = 0x38;
		constexpr const static size_t hitMaterialID = 0x10;
		constexpr const static size_t srcParentID = 0x40;
		constexpr const static size_t dstParentID = 0x60;
	}
}