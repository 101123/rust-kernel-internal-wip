#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68cf0e38;
		constexpr const static size_t gc_handles = 0xd519460;
		constexpr const static size_t il2cpp_resolve_icall = 0x799410;
		constexpr const static size_t il2cpp_array_new = 0x799430;
		constexpr const static size_t il2cpp_assembly_get_image = 0x75e40;
		constexpr const static size_t il2cpp_class_from_name = 0x7995a0;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x7998b0;
		constexpr const static size_t il2cpp_class_get_type = 0x799950;
		constexpr const static size_t il2cpp_domain_get = 0x799eb0;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x799ed0;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x79a790;
		constexpr const static size_t il2cpp_gchandle_new = 0x79a740;
		constexpr const static size_t il2cpp_gchandle_free = 0x79a830;
		constexpr const static size_t il2cpp_method_get_name = 0x5550;
		constexpr const static size_t il2cpp_object_new = 0x79aee0;
		constexpr const static size_t il2cpp_type_get_object = 0x79b6d0;
	}

#define Object_TypeDefinitionIndex 16566

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xae52f70;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16537

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

#define Component_TypeDefinitionIndex 16524

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16518

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 16601

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

#define Camera_TypeDefinitionIndex 16316

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16588

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

#define Material_TypeDefinitionIndex 16379

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16375

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xae130b0;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16378

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xae16980;
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16434

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

#define Renderer_TypeDefinitionIndex 16376

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16437

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16439

	namespace Texture2D {
		constexpr const static size_t ctor = 0xae2cb70;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define RenderTexture_TypeDefinitionIndex 16444

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xae357c0;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 16914

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae790d0;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 16890

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xae730b0;
	}

#define ComputeBuffer_TypeDefinitionIndex 16579

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae56b20;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xae56d70;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16383

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae1dbd0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xae1d900;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex -1

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xae9b760;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16356

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16467

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

#define Screen_TypeDefinitionIndex 16353

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

#define Application_TypeDefinitionIndex 16299

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define BaseNetworkable_TypeDefinitionIndex 7079

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x48;
		constexpr const static size_t parentEntity = 0x60;
		constexpr const static size_t children = 0x38;
	}

	// obf name: ::%b6e7495bc2868ce199b342d4aec0a2483c23de6e
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%b6e7495bc2868ce199b342d4aec0a2483c23de6e"
#define BaseNetworkable_Static_ClassNameShort "%b6e7495bc2868ce199b342d4aec0a2483c23de6e"
#define BaseNetworkable_Static_TypeDefinitionIndex 7078

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x40;
	}

	// obf name: ::%529ca09cc401518e65bdff87132172fc0a0461cc
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%529ca09cc401518e65bdff87132172fc0a0461cc"
#define BaseNetworkable_EntityRealm_ClassNameShort "%529ca09cc401518e65bdff87132172fc0a0461cc"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 7076

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x4daede0;
	}

	// obf name: ::%60c0f72648df0131780fe4931d5a96cccc2dca9c
#define System_ListDictionary_ClassName "%60c0f72648df0131780fe4931d5a96cccc2dca9c<%c7b9993f25c703706916fbd436af008e57e31b2f,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%60c0f72648df0131780fe4931d5a96cccc2dca9c"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x6d70bb0;
		constexpr const static size_t TryGetValue_methodinfo = 0xd1a5c28;
	}

	// obf name: ::%5528a7bdef1d203129afe2836fc9392ecbc4c24d
#define System_BufferList_ClassName "%5528a7bdef1d203129afe2836fc9392ecbc4c24d<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%5528a7bdef1d203129afe2836fc9392ecbc4c24d"
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

#define Model_TypeDefinitionIndex 406

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 3651

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa0;
		constexpr const static size_t model = 0xc8;
		constexpr const static size_t flags = 0xd0;
		constexpr const static size_t triggers = 0x98;
		constexpr const static size_t positionLerp = 0x130;

		// Functions
		constexpr const static size_t ServerRPC = 0x27b8df0;
		constexpr const static size_t FindBone = 0x27c1ef0;
		constexpr const static size_t GetWorldVelocity = 0x2785440;
		constexpr const static size_t GetParentVelocity = 0x27e4d10;
	}

	// obf name: ::%6cfad39752cdfaf3ae960f8b46d09cfb98f54652
#define PositionLerp_ClassName "%6cfad39752cdfaf3ae960f8b46d09cfb98f54652"
#define PositionLerp_ClassNameShort "%6cfad39752cdfaf3ae960f8b46d09cfb98f54652"
#define PositionLerp_TypeDefinitionIndex 6700

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x40;
	}

	// obf name: ::%a7ee91f2b82a2e5e08fade172c77558c7df92b78
#define Interpolator_ClassName "%a7ee91f2b82a2e5e08fade172c77558c7df92b78<%7e3d38bfbbae7480edd2b1f9c7a4e5b069649a58>"
#define Interpolator_ClassNameShort "%a7ee91f2b82a2e5e08fade172c77558c7df92b78"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 4711

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

#define SkeletonProperties_TypeDefinitionIndex 4468

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 4466

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t name = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 6824

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 6823

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%d5b6e6ec8f13ee83eebee9564c8620d0af721a6c
#define DamageTypeList_ClassName "%d5b6e6ec8f13ee83eebee9564c8620d0af721a6c"
#define DamageTypeList_ClassNameShort "%d5b6e6ec8f13ee83eebee9564c8620d0af721a6c"
#define DamageTypeList_TypeDefinitionIndex 4910

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 6115

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 3088

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x40;
		constexpr const static size_t iconSprite = 0x50;
		constexpr const static size_t category = 0x58;
		constexpr const static size_t stackable = 0x70;
		constexpr const static size_t rarity = 0x88;
		constexpr const static size_t ItemModWearable = 0x190;
	}

#define RecoilProperties_TypeDefinitionIndex 1424

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 6192

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 2442

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x238;
		constexpr const static size_t repeatDelay = 0x23c;
		constexpr const static size_t animationDelay = 0x240;
		constexpr const static size_t noHeadshots = 0x28e;
		constexpr const static size_t nextAttackTime = 0x290;
		constexpr const static size_t timeSinceDeploy = 0x2a8;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x1b81430;
		constexpr const static size_t StartAttackCooldown = 0x1b83050;
	}

#define BaseProjectile_TypeDefinitionIndex 6196

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
		constexpr const static size_t LaunchProjectile = 0x43424c0;
		constexpr const static size_t LaunchProjectileClientSide = 0x432c7b0;
		constexpr const static size_t ScaleRepeatDelay = 0x4348be0;
		constexpr const static size_t GetAimCone = 0x4353140;
		constexpr const static size_t GetAimCone_vtableoff = 0x4098;
		constexpr const static size_t UpdateAmmoDisplay = 0x4352e60;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x4068;
	}

#define BaseLauncher_TypeDefinitionIndex 1966

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 6964

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%05107c91fe236490ca18892226fd106dc9646a5d
#define HitTest_ClassName "%05107c91fe236490ca18892226fd106dc9646a5d"
#define HitTest_ClassNameShort "%05107c91fe236490ca18892226fd106dc9646a5d"
#define HitTest_TypeDefinitionIndex 1536

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x3c;
		constexpr const static size_t AttackRay = 0x20;
		constexpr const static size_t RayHit = 0xb0;
		constexpr const static size_t damageProperties = 0x60;
		constexpr const static size_t gameObject = 0x70;
		constexpr const static size_t collider = 0x48;
		constexpr const static size_t ignoredTypes = 0xa8;
		constexpr const static size_t HitTransform = 0x88;
		constexpr const static size_t HitPart = 0x94;
		constexpr const static size_t HitMaterial = 0x58;
		constexpr const static size_t DidHit = 0x80;
		constexpr const static size_t MaxDistance = 0x90;
		constexpr const static size_t HitNormal = 0x10;
		constexpr const static size_t HitPoint = 0x9c;
		constexpr const static size_t ignoreEntity = 0x40;
		constexpr const static size_t HitEntity = 0x78;
	}

#define Projectile_TypeDefinitionIndex 6595

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
		constexpr const static size_t mod = 0x110;
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
		constexpr const static size_t CalculateEffectScale = 0x4895bc0;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x228;
		constexpr const static size_t SetEffectScale = 0x48a9270;
		constexpr const static size_t UpdateVelocity = 0x48b8360;
		constexpr const static size_t Retire = 0x48ae980;
		constexpr const static size_t DoHit = 0x48c6c30;
	}

	// obf name: ::%adb36e1c8488f6fdb55fdc1d3f8b63550350d3fe
#define HitInfo_ClassName "%adb36e1c8488f6fdb55fdc1d3f8b63550350d3fe"
#define HitInfo_ClassNameShort "%adb36e1c8488f6fdb55fdc1d3f8b63550350d3fe"
#define HitInfo_TypeDefinitionIndex 2056

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0xc0;
		constexpr const static size_t damageTypes = 0x18;

		// Functions
		constexpr const static size_t get_boneArea = 0x16d7e70;
	}

	// obf name: ::%ae5584ab606b3d4e4ea79c683b3337ccb58e5d05
#define GameTrace_ClassName "%ae5584ab606b3d4e4ea79c683b3337ccb58e5d05"
#define GameTrace_ClassNameShort "%ae5584ab606b3d4e4ea79c683b3337ccb58e5d05"
#define GameTrace_TypeDefinitionIndex 1565

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x1071d10;
	}

#define BaseMelee_TypeDefinitionIndex 4728

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d0;
		constexpr const static size_t maxDistance = 0x2e8;
		constexpr const static size_t attackRadius = 0x2ec;
		constexpr const static size_t blockSprintOnAttack = 0x2f1;
		constexpr const static size_t gathering = 0x320;
		constexpr const static size_t canThrowAsProjectile = 0x329;

		// Functions
		constexpr const static size_t ProcessAttack = 0x343c840;
		constexpr const static size_t DoThrow = 0x3439430;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 2196

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x400;
		constexpr const static size_t strikeRecoil = 0x408;
		constexpr const static size_t _didSparkThisFrame = 0x410;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 4821

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x418;
		constexpr const static size_t stringBonusVelocity = 0x424;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x353fa10;
	}

	// obf name: ::%2dcd4541125433641c47be982420dd377ec5d107
#define ItemContainer_ClassName "%2dcd4541125433641c47be982420dd377ec5d107"
#define ItemContainer_ClassNameShort "%2dcd4541125433641c47be982420dd377ec5d107"
#define ItemContainer_TypeDefinitionIndex 5954

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x18;
		constexpr const static size_t itemList = 0x60;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x4138b50;
	}

#define PlayerLoot_TypeDefinitionIndex 6419

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 6392

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x58;
		constexpr const static size_t containerMain = 0x60;
		constexpr const static size_t containerWear = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x4675880;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 2986

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x21233d0;
		constexpr const static size_t get_rotation = 0x2111500;
		constexpr const static size_t set_rotation = 0x212efe0;
		constexpr const static size_t HeadForward = 0x212e080;
	}

	// obf name: ::%028568b2f82fc95dfc63a61e8fcad95eee9e20df
#define PlayerEyes_Static_ClassName "PlayerEyes/%028568b2f82fc95dfc63a61e8fcad95eee9e20df"
#define PlayerEyes_Static_ClassNameShort "%028568b2f82fc95dfc63a61e8fcad95eee9e20df"
#define PlayerEyes_Static_TypeDefinitionIndex 2985

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x14c;
	}

	// obf name: ::%62b1fd188609528d4f5ff1a2899190e06e154545
#define PlayerBelt_ClassName "%62b1fd188609528d4f5ff1a2899190e06e154545"
#define PlayerBelt_ClassNameShort "%62b1fd188609528d4f5ff1a2899190e06e154545"
#define PlayerBelt_TypeDefinitionIndex 1988

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x163d780;
		constexpr const static size_t GetActiveItem = 0x163fea0;
	}

	// obf name: ::%cd6dfa32e599f1e48f7d7982819dccdd1c1c366b
#define LocalPlayer_ClassName "%cd6dfa32e599f1e48f7d7982819dccdd1c1c366b"
#define LocalPlayer_ClassNameShort "%cd6dfa32e599f1e48f7d7982819dccdd1c1c366b"
#define LocalPlayer_TypeDefinitionIndex 5738

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x3f2bf40;
		constexpr const static size_t MoveItem = 0x3f31650;
		constexpr const static size_t get_Entity = 0x3f32530;
	}

	// obf name: ::%502b973b8411356b9614aacdb7caefb96f874c90
#define LocalPlayer_Static_ClassName "%cd6dfa32e599f1e48f7d7982819dccdd1c1c366b/%502b973b8411356b9614aacdb7caefb96f874c90"
#define LocalPlayer_Static_ClassNameShort "%502b973b8411356b9614aacdb7caefb96f874c90"
#define LocalPlayer_Static_TypeDefinitionIndex 5737

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x118;
	}

	// obf name: ::%fbbd223fa447b80c5a3f625e32f4f6feab377a8d
#define BasePlayer_Static_ClassName "BasePlayer/%fbbd223fa447b80c5a3f625e32f4f6feab377a8d"
#define BasePlayer_Static_ClassNameShort "%fbbd223fa447b80c5a3f625e32f4f6feab377a8d"
#define BasePlayer_Static_TypeDefinitionIndex 1598

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x938;
	}

#define BasePlayer_TypeDefinitionIndex 1599

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x518;
		constexpr const static size_t input = 0x288;
		constexpr const static size_t movement = 0x5f0;
		constexpr const static size_t currentTeam = 0x460;
		constexpr const static size_t clActiveItem = 0x490;
		constexpr const static size_t modelState = 0x4a8;
		constexpr const static size_t playerFlags = 0x588;
		constexpr const static size_t eyes = 0x310;
		constexpr const static size_t playerRigidbody = 0x348;
		constexpr const static size_t userID = 0x5d0;
		constexpr const static size_t UserIDString = 0x2c0;
		constexpr const static size_t inventory = 0x2f8;
		constexpr const static size_t _displayName = 0x5c0;
		constexpr const static size_t _lookingAt = 0x470;
		constexpr const static size_t lastSentTickTime = 0x544;
		constexpr const static size_t lastSentTick = 0x270;
		constexpr const static size_t mounted = 0x4d0;
		constexpr const static size_t Belt = 0x650;
		constexpr const static size_t _lookingAtEntity = 0x408;
		constexpr const static size_t currentGesture = 0x260;
		constexpr const static size_t weaponMoveSpeedScale = 0x660;
		constexpr const static size_t clothingBlocksAiming = 0x664;
		constexpr const static size_t clothingMoveSpeedReduction = 0x668;
		constexpr const static size_t clothingWaterSpeedBonus = 0x66c;
		constexpr const static size_t equippingBlocked = 0x674;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x113daf0;
		constexpr const static size_t Menu_AssistPlayer = 0x11781b0;
		constexpr const static size_t OnViewModeChanged = 0x1221340;
		constexpr const static size_t ChatMessage = 0x11bea60;
		constexpr const static size_t IsOnGround = 0x10b8e60;
		constexpr const static size_t GetSpeed = 0x11be0f0;
		constexpr const static size_t SendProjectileUpdate = 0x115a240;
		constexpr const static size_t SendProjectileAttack = 0x11181c0;
		constexpr const static size_t CanBuild = 0x10ee090;
		constexpr const static size_t GetMounted = 0x117e410;
		constexpr const static size_t GetHeldEntity = 0x114e9e0;
		constexpr const static size_t get_inventory = 0x124fac0;
		constexpr const static size_t get_eyes = 0x1111130;
		constexpr const static size_t SendClientTick = 0x116c360;
		constexpr const static size_t ClientInput = 0x1108670;
		constexpr const static size_t ClientInput_vtableoff = 0x3868;
		constexpr const static size_t MaxHealth = 0x114d240;
		constexpr const static size_t MaxHealth_vtableoff = 0x1ab8;
		constexpr const static size_t OnAttacked = 0x1250e60;
		constexpr const static size_t OnAttacked_vtableoff = 0x2318;
	}

#define ScientistNPC_TypeDefinitionIndex 5595

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 2653

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 3552

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 174

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 719

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 1561

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 379

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xd8;
		constexpr const static size_t ladder = 0xe8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x2b923d0;
		constexpr const static size_t BlockSprint = 0x2bbba90;
		constexpr const static size_t GroundCheck = 0x2b9b300;
		constexpr const static size_t ClientInput = 0x2bbee50;
		constexpr const static size_t ClientInput_vtableoff = 0x318;
		constexpr const static size_t DoFixedUpdate = 0x2b95450;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x358;
		constexpr const static size_t FrameUpdate = 0x2ba6220;
		constexpr const static size_t FrameUpdate_vtableoff = 0x378;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 314

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x370;
		constexpr const static size_t cachedProtectedMinutes = 0x378;
	}

#define WorldItem_TypeDefinitionIndex 2023

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a0;
		constexpr const static size_t item = 0x1a8;
	}

#define HackableLockedCrate_TypeDefinitionIndex 2375

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x388;
		constexpr const static size_t hackSeconds = 0x398;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 5849

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 5845

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%4048ac3574147e9f0f03ea1910d685d87838f871
#define ConsoleSystem_ClassName "%4048ac3574147e9f0f03ea1910d685d87838f871"
#define ConsoleSystem_ClassNameShort "%4048ac3574147e9f0f03ea1910d685d87838f871"
#define ConsoleSystem_TypeDefinitionIndex -1

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x63cd350;
	}

#define ConsoleSystem_Option_ClassName "%4048ac3574147e9f0f03ea1910d685d87838f871/%c57d40c98ef763d978cc2c32f4a1df6ce5b3334d"
#define ConsoleSystem_Option_ClassNameShort "%c57d40c98ef763d978cc2c32f4a1df6ce5b3334d"
#define ConsoleSystem_Command_ClassName "%4048ac3574147e9f0f03ea1910d685d87838f871/%74531d23f30bec0a098a76a2f5282e6b3d6b8937"
#define ConsoleSystem_Command_ClassNameShort "%74531d23f30bec0a098a76a2f5282e6b3d6b8937"
	// obf name: ::%638179457dd2571f2d1b466aa84d8f9f0124b817
#define ConsoleSystem_Index_Static_ClassName "%4048ac3574147e9f0f03ea1910d685d87838f871/%4104071d9762ecab3287da38f0567f994f923b7d.%638179457dd2571f2d1b466aa84d8f9f0124b817"
#define ConsoleSystem_Index_Static_ClassNameShort "%638179457dd2571f2d1b466aa84d8f9f0124b817"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex -1

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x60;
	}

	// obf name: ::%207418c3733352f7dadfcd31f9bc778fa36900be
#define ConsoleSystem_Arg_ClassName "%4048ac3574147e9f0f03ea1910d685d87838f871/%207418c3733352f7dadfcd31f9bc778fa36900be"
#define ConsoleSystem_Arg_ClassNameShort "%207418c3733352f7dadfcd31f9bc778fa36900be"
// obf name: ::%33811bce3c721b769ae34d61f0966614abfea9af
#define Facepunch_Network_SteamNetworking_ClassName "%33811bce3c721b769ae34d61f0966614abfea9af"
#define Facepunch_Network_SteamNetworking_ClassNameShort "%33811bce3c721b769ae34d61f0966614abfea9af"
#define LootableCorpse_TypeDefinitionIndex 2200

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2a8;
		constexpr const static size_t _playerName = 0x298;
	}

#define DroppedItemContainer_TypeDefinitionIndex 510

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x278;
		constexpr const static size_t _playerName = 0x260;
	}

#define MainCamera_TypeDefinitionIndex 3803

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x98;
		constexpr const static size_t mainCameraTransform = 0x70;

		// Functions
		constexpr const static size_t Update = 0x2964650;
		constexpr const static size_t OnPreCull = 0x295ad40;
		constexpr const static size_t Trace = 0x296b0b0;
	}

#define CameraMan_TypeDefinitionIndex 4497

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%2e159291b590c56a578b0388f8fee3b1e042bec8
#define PlayerTick_ClassName "%2e159291b590c56a578b0388f8fee3b1e042bec8"
#define PlayerTick_ClassNameShort "%2e159291b590c56a578b0388f8fee3b1e042bec8"
#define PlayerTick_TypeDefinitionIndex 7275

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x28;
		constexpr const static size_t modelState = 0x40;
		constexpr const static size_t activeItem = 0x20;
		constexpr const static size_t parentID = 0x18;
		constexpr const static size_t position = 0x30;
		constexpr const static size_t eyePos = 0x4c;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x95de350;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x95da5e0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%f8f2949a154d17f3fe62090b49e2d4db4121a59c
#define InputMessage_ClassName "%f8f2949a154d17f3fe62090b49e2d4db4121a59c"
#define InputMessage_ClassNameShort "%f8f2949a154d17f3fe62090b49e2d4db4121a59c"
#define InputMessage_TypeDefinitionIndex 7325

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x20;
		constexpr const static size_t aimAngles = 0x10;
		constexpr const static size_t mouseDelta = 0x24;
	}

	// obf name: ::%27c98032801fb98bfea412c7212c66e0ac8dace3
#define InputState_ClassName "%27c98032801fb98bfea412c7212c66e0ac8dace3"
#define InputState_ClassNameShort "%27c98032801fb98bfea412c7212c66e0ac8dace3"
#define InputState_TypeDefinitionIndex 1162

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x18;
	}

#define PlayerInput_TypeDefinitionIndex 2284

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%4f949e8e160c13887a405524ac863e80ffea6278
#define ModelState_ClassName "%4f949e8e160c13887a405524ac863e80ffea6278"
#define ModelState_ClassNameShort "%4f949e8e160c13887a405524ac863e80ffea6278"
#define ModelState_TypeDefinitionIndex 7261

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x7c;
		constexpr const static size_t waterLevel = 0x30;
		constexpr const static size_t lookDir = 0x70;
	}

	// obf name: ::%cb2bc7756023e792a2c636a40d9e152a2a99fe1a
#define Item_ClassName "%cb2bc7756023e792a2c636a40d9e152a2a99fe1a"
#define Item_ClassNameShort "%cb2bc7756023e792a2c636a40d9e152a2a99fe1a"
#define Item_TypeDefinitionIndex 2246

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x80;
		constexpr const static size_t uid = 0x90;
		constexpr const static size_t _maxCondition = 0x34;
		constexpr const static size_t _condition = 0x58;
		constexpr const static size_t amount = 0x54;
		constexpr const static size_t position = 0xb0;
		constexpr const static size_t contents = 0x20;
		constexpr const static size_t parent = 0xd0;
		constexpr const static size_t heldEntity = 0x70;
		constexpr const static size_t worldEnt = 0xb8;

		// Functions
		constexpr const static size_t get_iconSprite = 0x18a2530;
	}

	// obf name: ::%38cb6f4fb4776264e3559b9e9ba1e6f8a6e088db
#define WaterLevel_ClassName "%38cb6f4fb4776264e3559b9e9ba1e6f8a6e088db"
#define WaterLevel_ClassNameShort "%38cb6f4fb4776264e3559b9e9ba1e6f8a6e088db"
#define WaterLevel_TypeDefinitionIndex 6522

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x47d6810;
		constexpr const static size_t GetWaterLevel = 0x47c4bd0;
	}

	// obf name: ::%05eaa6af7e6c20856c9e2ba998bd72668107a513
#define ConVar_Graphics_Static_ClassName "%0a287ae77e098c4cef9cf8fc594be0ca6eae244e/%05eaa6af7e6c20856c9e2ba998bd72668107a513"
#define ConVar_Graphics_Static_ClassNameShort "%05eaa6af7e6c20856c9e2ba998bd72668107a513"
#define ConVar_Graphics_Static_TypeDefinitionIndex 5008

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x50;

		// Functions
		constexpr const static size_t _fov_getter = 0x4401430;
		constexpr const static size_t _fov_setter = 0x43e27a0;
	}

#define BaseFishingRod_TypeDefinitionIndex 2006

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x258;
		constexpr const static size_t currentBobber = 0x260;
		constexpr const static size_t MaxCastDistance = 0x27c;
		constexpr const static size_t BobberPreview = 0x288;
		constexpr const static size_t clientStrainAmountNormalised = 0x2c8;
		constexpr const static size_t strainGainMod = 0x2b8;
		constexpr const static size_t aimAnimationReady = 0x2e0;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x164a820;
		constexpr const static size_t EvaluateFishingPosition = 0x16480d0;
	}

#define FishingBobber_TypeDefinitionIndex 4806

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x278;
	}

#define GameManifest_TypeDefinitionIndex 419

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x3122200;
	}

	// obf name: ::%88b96af2bdb1dc0b02017ccc16577ec7de48a664
#define GameManager_ClassName "%88b96af2bdb1dc0b02017ccc16577ec7de48a664"
#define GameManager_ClassNameShort "%88b96af2bdb1dc0b02017ccc16577ec7de48a664"
#define GameManager_TypeDefinitionIndex 2576

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x10;

		// Functions
		constexpr const static size_t CreatePrefab = 0x1cccbe0;
	}

	// obf name: ::%0c6ac93a9559c70b07cf6fcb24bd20a9796a7f97
#define GameManager_Static_ClassName "%88b96af2bdb1dc0b02017ccc16577ec7de48a664/%0c6ac93a9559c70b07cf6fcb24bd20a9796a7f97"
#define GameManager_Static_ClassNameShort "%0c6ac93a9559c70b07cf6fcb24bd20a9796a7f97"
#define GameManager_Static_TypeDefinitionIndex 2575

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x28;
	}

	// obf name: ::%ca31ab2ded65341291ab79d81b78486f2805642c
#define PrefabPoolCollection_ClassName "%ca31ab2ded65341291ab79d81b78486f2805642c"
#define PrefabPoolCollection_ClassNameShort "%ca31ab2ded65341291ab79d81b78486f2805642c"
#define PrefabPoolCollection_TypeDefinitionIndex 2727

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x18;
	}

	// obf name: ::%dfe8d4b0be74331b980e11dea67e557156fcd9c5
#define PrefabPool_ClassName "%dfe8d4b0be74331b980e11dea67e557156fcd9c5"
#define PrefabPool_ClassNameShort "%dfe8d4b0be74331b980e11dea67e557156fcd9c5"
#define PrefabPool_TypeDefinitionIndex 4877

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x18;
	}

#define ItemModProjectile_TypeDefinitionIndex 2140

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

#define CraftingQueue_TypeDefinitionIndex 4173

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%7d3ce1ae94e94f7e4090b168d9c431c32e881a31
#define CraftingQueue_Static_ClassName "CraftingQueue/%7d3ce1ae94e94f7e4090b168d9c431c32e881a31"
#define CraftingQueue_Static_ClassNameShort "%7d3ce1ae94e94f7e4090b168d9c431c32e881a31"
#define CraftingQueue_Static_TypeDefinitionIndex 4172

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x68;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 2483

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%a0f747f9059eb2de17c36236cedf81db32b941de
#define Planner_Static_ClassName "Planner/%a0f747f9059eb2de17c36236cedf81db32b941de"
#define Planner_Static_ClassNameShort "%a0f747f9059eb2de17c36236cedf81db32b941de"
#define Planner_Static_TypeDefinitionIndex 4577

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0xf0;
	}

	// obf name: ::%8191f93de173d1eeccd373280a7934e39b292fdd
#define Planner_Guide_ClassName "Planner/%8191f93de173d1eeccd373280a7934e39b292fdd"
#define Planner_Guide_ClassNameShort "%8191f93de173d1eeccd373280a7934e39b292fdd"
#define Planner_Guide_TypeDefinitionIndex 4573

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x20;
	}

#define Planner_TypeDefinitionIndex 4578

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x280;
	}

#define Construction_TypeDefinitionIndex 3192

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x138;
	}

#define BuildingBlock_TypeDefinitionIndex 4082

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2a8;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 5461

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x218;
		constexpr const static size_t _punches = 0x1c0;
		constexpr const static size_t viewModel = 0x220;

		// Functions
		constexpr const static size_t OnDeploy = 0x3bf1790;
	}

	// obf name: ::%775806f7a1d89da8a3476e4d177ca428235710b7
#define PunchEntry_ClassName "HeldEntity/%775806f7a1d89da8a3476e4d177ca428235710b7"
#define PunchEntry_ClassNameShort "%775806f7a1d89da8a3476e4d177ca428235710b7"
#define PunchEntry_TypeDefinitionIndex 5459

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x10;
		constexpr const static size_t startTime = 0x14;
		constexpr const static size_t amountAdded = 0x18;
		constexpr const static size_t amount = 0x24;
	}

#define IronSights_TypeDefinitionIndex 4550

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 1710

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 1792

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xb0;
		constexpr const static size_t model = 0x88;
		constexpr const static size_t lower = 0xc8;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x1443890;
	}

#define ViewModel_TypeDefinitionIndex 6400

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x4692aa0;
		constexpr const static size_t PlayString = 0x4693f60;
	}

#define MedicalTool_TypeDefinitionIndex 3831

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f0;
	}

#define WaterBody_TypeDefinitionIndex 6914

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x58;
	}

	// obf name: ::%b66ab3052d8d20a4e2b5501b19153dcb73822498
#define WaterSystem_Static_ClassName "WaterSystem/%b66ab3052d8d20a4e2b5501b19153dcb73822498"
#define WaterSystem_Static_ClassNameShort "%b66ab3052d8d20a4e2b5501b19153dcb73822498"
#define WaterSystem_Static_TypeDefinitionIndex 3271

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x30;
	}

#define WaterSystem_TypeDefinitionIndex 3272

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x23af230;
	}

#define TerrainMeta_TypeDefinitionIndex 3286

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0xa0;
		constexpr const static size_t HeightMap = 0xe0;
		constexpr const static size_t SplatMap = 0x690;
		constexpr const static size_t TopologyMap = 0x730;
		constexpr const static size_t Texturing = 0x550;
	}

#define TerrainCollision_TypeDefinitionIndex 1581

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x1261f40;
	}

#define TerrainHeightMap_TypeDefinitionIndex 5451

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 936

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 3323

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%b3936c804400a310bd0a29adc45ea5cba1a10e65
#define World_Static_ClassName "%c6073e08f868471699429e7b24204ab1ce51a2f5/%b3936c804400a310bd0a29adc45ea5cba1a10e65"
#define World_Static_ClassNameShort "%b3936c804400a310bd0a29adc45ea5cba1a10e65"
#define World_Static_TypeDefinitionIndex 3507

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x274;
	}

#define ItemIcon_TypeDefinitionIndex 154

	namespace ItemIcon {

		// Functions
		constexpr const static size_t TryToMove = 0xfe0240;
		constexpr const static size_t TryToMove_vtableoff = 0x378;
		constexpr const static size_t RunTimedAction = 0xfe4390;
	}

	// obf name: ::%6a1eec9912640a6290a1442ee21aaef500f91042
#define ItemIcon_Static_ClassName "ItemIcon/%6a1eec9912640a6290a1442ee21aaef500f91042"
#define ItemIcon_Static_ClassNameShort "%6a1eec9912640a6290a1442ee21aaef500f91042"
#define ItemIcon_Static_TypeDefinitionIndex 153

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x28;
	}

	// obf name: ::%547c1153f47311a4f2a15063ff6f9feee12e651d
#define Effect_ClassName "%547c1153f47311a4f2a15063ff6f9feee12e651d"
#define Effect_ClassNameShort "%547c1153f47311a4f2a15063ff6f9feee12e651d"
#define Effect_TypeDefinitionIndex 2865

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x68;
		constexpr const static size_t worldPos = 0x94;
	}

	// obf name: ::%2996e8d28beacf93a83b097374094223e53b9e65
#define EffectNetwork_ClassName "%2996e8d28beacf93a83b097374094223e53b9e65"
#define EffectNetwork_ClassNameShort "%2996e8d28beacf93a83b097374094223e53b9e65"
#define EffectNetwork_TypeDefinitionIndex 249

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%706384ecbac2bc8aaa14af7ed857c05e2dd594d5
#define EffectNetwork_Static_ClassName "%2996e8d28beacf93a83b097374094223e53b9e65/%706384ecbac2bc8aaa14af7ed857c05e2dd594d5"
#define EffectNetwork_Static_ClassNameShort "%706384ecbac2bc8aaa14af7ed857c05e2dd594d5"
#define EffectNetwork_Static_TypeDefinitionIndex 248

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x18;

		// Functions
		constexpr const static size_t cctor = 0x1d5eca0;
	}

#define BuildingBlock_TypeDefinitionIndex 4082

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2e8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x2d2a700;
		constexpr const static size_t HasUpgradePrivilege = 0x2d3a550;
		constexpr const static size_t CanAffordUpgrade = 0x2d3ee10;
	}

	// obf name: ::%33478b02dbfbfeac89fb1bdd7e336df33bfb30e2
#define GameObjectEx_ClassName "%33478b02dbfbfeac89fb1bdd7e336df33bfb30e2"
#define GameObjectEx_ClassNameShort "%33478b02dbfbfeac89fb1bdd7e336df33bfb30e2"
#define GameObjectEx_TypeDefinitionIndex 2233

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x186c9f0;
	}

#define UIDeathScreen_TypeDefinitionIndex 2895

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x2022140;
	}

	// obf name: ::%2009c99560d765bcfad8e0e431cace92692d11df
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%2009c99560d765bcfad8e0e431cace92692d11df"
#define BaseScreenShake_Static_ClassNameShort "%2009c99560d765bcfad8e0e431cace92692d11df"
#define BaseScreenShake_Static_TypeDefinitionIndex 822

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x40;
	}

#define FlashbangOverlay_TypeDefinitionIndex 6520

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x30;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%c1b8397b5dc9f9ae8789835e2db65bc4ba79ac95
#define StringPool_ClassName "%c1b8397b5dc9f9ae8789835e2db65bc4ba79ac95"
#define StringPool_ClassNameShort "%c1b8397b5dc9f9ae8789835e2db65bc4ba79ac95"
#define StringPool_TypeDefinitionIndex 4020

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x68;

		// Functions
		constexpr const static size_t Get = 0x2c640b0;
	}

	// obf name: ::%1928f36dd94000f0eb71ebc6194fbe488213ae3d
#define Network_Networkable_ClassName "%1928f36dd94000f0eb71ebc6194fbe488213ae3d"
#define Network_Networkable_ClassNameShort "%1928f36dd94000f0eb71ebc6194fbe488213ae3d"
#define Network_Networkable_TypeDefinitionIndex 19083

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x48;
	}

	// obf name: ::%4723171c9eec450ed44712669200a408338d9bbf
#define Network_Net_ClassName "%4723171c9eec450ed44712669200a408338d9bbf"
#define Network_Net_ClassNameShort "%4723171c9eec450ed44712669200a408338d9bbf"
#define Network_Net_TypeDefinitionIndex 7933

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x0;
	}

	// obf name: ::%c73559872ca69517ed5bb87bb5108a78f938df82
#define Network_Client_ClassName "%c73559872ca69517ed5bb87bb5108a78f938df82"
#define Network_Client_ClassNameShort "%c73559872ca69517ed5bb87bb5108a78f938df82"
#define Network_Client_TypeDefinitionIndex 19051

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0x118;
		constexpr const static size_t ConnectedPort = 0xe0;
		constexpr const static size_t ServerName = 0xd8;
		constexpr const static size_t ConnectedAddress = 0xf8;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x64548e0;
		constexpr const static size_t DestroyNetworkable = 0x64554d0;
	}

	// obf name: ::%8692004f0d6b976b5393ddbb4eea8297bf22b50c
#define Network_BaseNetwork_ClassName "%8692004f0d6b976b5393ddbb4eea8297bf22b50c"
#define Network_BaseNetwork_ClassNameShort "%8692004f0d6b976b5393ddbb4eea8297bf22b50c"
#define Network_BaseNetwork_TypeDefinitionIndex 19055

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x6468ff0;
	}

	// obf name: ::%97378b1463266db7b98b6290cfdbad2693daba8b
#define Network_SendInfo_ClassName "%97378b1463266db7b98b6290cfdbad2693daba8b"
#define Network_SendInfo_ClassNameShort "%97378b1463266db7b98b6290cfdbad2693daba8b"
#define Network_SendInfo_TypeDefinitionIndex 19067

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%299a77e202f665614080ce71dcb8b5bf6fe04576
#define Network_Message_ClassName "%299a77e202f665614080ce71dcb8b5bf6fe04576"
#define Network_Message_ClassNameShort "%299a77e202f665614080ce71dcb8b5bf6fe04576"
#define Network_Message_TypeDefinitionIndex 19029

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%fb1a89add4653f0782dcf2d315488d52a9694e05
#define Network_NetRead_ClassName "%fb1a89add4653f0782dcf2d315488d52a9694e05"
#define Network_NetRead_ClassNameShort "%fb1a89add4653f0782dcf2d315488d52a9694e05"
#define Network_NetRead_TypeDefinitionIndex 19049

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x40;
	}

	// obf name: ::%3db7204607be66c228d20a1d472e565e7c9b671b
#define Network_NetWrite_ClassName "%3db7204607be66c228d20a1d472e565e7c9b671b"
#define Network_NetWrite_ClassNameShort "%3db7204607be66c228d20a1d472e565e7c9b671b"
#define Network_NetWrite_TypeDefinitionIndex 19066

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x48;

		// Functions
		constexpr const static size_t WriteByte = 0x6478ea0;
		constexpr const static size_t String = 0x64796c0;
		constexpr const static size_t Send = 0x64790e0;
	}

#define LootPanel_TypeDefinitionIndex 5940

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x4124b80;
	}

#define UIInventory_TypeDefinitionIndex 4602

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x32cb1a0;
	}

#define GrowableEntity_TypeDefinitionIndex 54

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2b0;
		constexpr const static size_t State = 0x2c0;
	}

#define PlantProperties_TypeDefinitionIndex 4790

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 4789

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 20902

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 7596

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
		constexpr const static size_t get_Instance = 0x8b1150;
	}

	// obf name: ::%44314d25792e8787c21d65e93e389cf95183a019
#define TOD_Sky_Static_ClassName "TOD_Sky/%44314d25792e8787c21d65e93e389cf95183a019"
#define TOD_Sky_Static_ClassNameShort "%44314d25792e8787c21d65e93e389cf95183a019"
#define TOD_Sky_Static_TypeDefinitionIndex 7595

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x88;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 8094

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0x9c57a0;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 8509

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9622

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8947

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
	}

#define TOD_StarParameters_TypeDefinitionIndex 7912

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 9325

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8713

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 4811

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 6096

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 798

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 6277

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

#define EnvironmentManager_TypeDefinitionIndex 6870

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x4b8eb60;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%ff2d12c9e683aafcc19c0fb7b95399cb01633296/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex -1

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 6161

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 6162

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 93

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

	// obf name: ::%d03fc91382e928ff3f2f2e81b2f62e6ce31e732c
#define ListHashSet_ClassName "%d03fc91382e928ff3f2f2e81b2f62e6ce31e732c<UIChat>"
#define ListHashSet_ClassNameShort "%d03fc91382e928ff3f2f2e81b2f62e6ce31e732c"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 4045

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x268;
		constexpr const static size_t weakspots = 0x3d0;
	}

#define Chainsaw_TypeDefinitionIndex 6775

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%10b4799399e509755da84b263085c67787acbd36
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%10b4799399e509755da84b263085c67787acbd36"
#define CameraUpdateHook_Static_ClassNameShort "%10b4799399e509755da84b263085c67787acbd36"
#define CameraUpdateHook_Static_TypeDefinitionIndex 6340

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x0;
	}

#define SteamClientWrapper_TypeDefinitionIndex 633

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x4b16a50;
	}

	// obf name: ::%ddf3d96c9ee60819a7c81b5a73388ea02565f88c
#define AimConeUtil_ClassName "%ddf3d96c9ee60819a7c81b5a73388ea02565f88c"
#define AimConeUtil_ClassNameShort "%ddf3d96c9ee60819a7c81b5a73388ea02565f88c"
#define AimConeUtil_TypeDefinitionIndex 2363

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x1b13700;
	}

	// obf name: ::%dc07af3dcbd3593b89f0c65160e5f8ea8a3ac853
#define Buttons_ConButton_ClassName "%a7992ba7dd9773945feca46718d3d3eeb43d9973/%dc07af3dcbd3593b89f0c65160e5f8ea8a3ac853"
#define Buttons_ConButton_ClassNameShort "%dc07af3dcbd3593b89f0c65160e5f8ea8a3ac853"
#define Buttons_ConButton_TypeDefinitionIndex 106

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%0f5edc9a95c747fca9b8b46515c023bbd494ecdc
#define Buttons_Static_ClassName "%a7992ba7dd9773945feca46718d3d3eeb43d9973/%0f5edc9a95c747fca9b8b46515c023bbd494ecdc"
#define Buttons_Static_ClassNameShort "%0f5edc9a95c747fca9b8b46515c023bbd494ecdc"
#define Buttons_Static_TypeDefinitionIndex 107

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x7b0;
		constexpr const static size_t Attack = 0x1a0;
		constexpr const static size_t Attack2 = 0x30;
		constexpr const static size_t Forward = 0x648;
		constexpr const static size_t Backward = 0xd50;
		constexpr const static size_t Right = 0x6b8;
		constexpr const static size_t Left = 0xb98;
		constexpr const static size_t Sprint = 0x728;

		// Functions
		constexpr const static size_t Pets_setter = 0x43ed330;
	}

#define PlayerModel_TypeDefinitionIndex 2319

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x2b8;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 3404

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 533

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x284;
		constexpr const static size_t yawClamp = 0x28c;
		constexpr const static size_t canWieldItems = 0x294;
	}

#define ProgressBar_TypeDefinitionIndex 1260

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 6786

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x400;
		constexpr const static size_t wasAiming = 0x410;
	}

#define CrossbowWeapon_TypeDefinitionIndex 4528

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 1046

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%1a83695bfa4dad084a50c5b098524ad32676a1e4
#define ConVar_Admin_Static_ClassName "%1166892ad6cca1dd031303281d2beebe517b52e9/%1a83695bfa4dad084a50c5b098524ad32676a1e4"
#define ConVar_Admin_Static_ClassNameShort "%1a83695bfa4dad084a50c5b098524ad32676a1e4"
#define ConVar_Admin_Static_TypeDefinitionIndex 5084

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0xac;

		// Functions
		constexpr const static size_t admintime_getter = 0x43e1a40;
		constexpr const static size_t admintime_setter = 0x441e8d0;
	}

	// obf name: ::%cb57db170b7475afc8dab9da3a2198a06fce6482
#define ConVar_Player_Static_ClassName "%c134482103c827dfaba369feacb3e9a315ef6ff5/%cb57db170b7475afc8dab9da3a2198a06fce6482"
#define ConVar_Player_Static_ClassNameShort "%cb57db170b7475afc8dab9da3a2198a06fce6482"
#define ConVar_Player_Static_TypeDefinitionIndex 6676

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x154;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x43fcbd0;
		constexpr const static size_t clientTickRate_setter = 0x44198c0;
	}

#define ColliderInfo_TypeDefinitionIndex 5358

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 6632

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x210;
		constexpr const static size_t HasAuth = 0x220;
		constexpr const static size_t HasGuestAuth = 0x221;
	}

#define AutoTurret_TypeDefinitionIndex 4460

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x3b0;
		constexpr const static size_t lastYaw = 0x3c0;
		constexpr const static size_t muzzlePos = 0x3e0;
		constexpr const static size_t gun_yaw = 0x3f8;
		constexpr const static size_t gun_pitch = 0x400;
		constexpr const static size_t sightRange = 0x408;

		// Functions
		constexpr const static size_t IsAuthed = 0x312a2b0;
	}

#define Client_TypeDefinitionIndex 24

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x1efe3e0;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

#define BaseNetworkable_TypeDefinitionIndex 7079

	namespace BaseNetworkable {

		// Functions
		constexpr const static size_t Load = 0x4da4b40;
		constexpr const static size_t Load_vtableoff = 0x428;
	}

	// obf name: ::%90f3a9f781c9e5aae1cdf2aa71dbccf8555fa62f
#define ItemManager_Static_ClassName "%6dceceddd24263a44d9f4cc5a2ee2e8ec7a7d7de/%90f3a9f781c9e5aae1cdf2aa71dbccf8555fa62f"
#define ItemManager_Static_ClassNameShort "%90f3a9f781c9e5aae1cdf2aa71dbccf8555fa62f"
#define ItemManager_Static_TypeDefinitionIndex 6448

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x80;
		constexpr const static size_t itemDictionary = 0x180;
		constexpr const static size_t itemDictionaryByName = 0x138;
	}

	// obf name: ::%b07fed1338f5b835cfafb4777d749d40a73a6842
#define ConVar_Server_Static_ClassName "%90dbe386f013d799d2e08793cdc98af556a321af/%b07fed1338f5b835cfafb4777d749d40a73a6842"
#define ConVar_Server_Static_ClassNameShort "%b07fed1338f5b835cfafb4777d749d40a73a6842"
#define ConVar_Server_Static_TypeDefinitionIndex 1348

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 4127

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x2d78990;
	}

#define LoadingScreen_TypeDefinitionIndex 6621

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 3454

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%999d99705b8b68e2ea186d43ba37820b77179e95"
#define MapView_Static_ClassNameShort "%999d99705b8b68e2ea186d43ba37820b77179e95"
#define MapView_TypeDefinitionIndex 4202

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x2e7d020;
	}

	// obf name: ::%60d2e3dab5e3a301b95383106f6cb56f38c712b4
#define GamePhysics_ClassName "%60d2e3dab5e3a301b95383106f6cb56f38c712b4"
#define GamePhysics_ClassNameShort "%60d2e3dab5e3a301b95383106f6cb56f38c712b4"
#define GamePhysics_TypeDefinitionIndex 260

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x1f09c00;
		constexpr const static size_t LineOfSightInternal = 0x1f190b0;
		constexpr const static size_t Verify = 0x1f1b000;
	}

#define DDraw_TypeDefinitionIndex 1413

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0xeccbb0;
		constexpr const static size_t Line = 0xeb1f90;
	}

	// obf name: ::%e9543b367d37b1ba6f68c404854722f9944911f6
#define RaycastHitEx_ClassName "%e9543b367d37b1ba6f68c404854722f9944911f6"
#define RaycastHitEx_ClassNameShort "%e9543b367d37b1ba6f68c404854722f9944911f6"
#define RaycastHitEx_TypeDefinitionIndex 122

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0xe8b480;
	}

	// obf name: ::%5a4844f640aa3d5dd282c50cba5954cf918bf743
#define OnParentDestroyingEx_ClassName "%5a4844f640aa3d5dd282c50cba5954cf918bf743"
#define OnParentDestroyingEx_ClassNameShort "%5a4844f640aa3d5dd282c50cba5954cf918bf743"
#define OnParentDestroyingEx_TypeDefinitionIndex 5825

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x4038ea0;
	}

	// obf name: ::%6c07f6ac695b761dd946cf059ce3349da854be43
#define ConsoleNetwork_ClassName "%6c07f6ac695b761dd946cf059ce3349da854be43"
#define ConsoleNetwork_ClassNameShort "%6c07f6ac695b761dd946cf059ce3349da854be43"
#define ConsoleNetwork_TypeDefinitionIndex 3579

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x2706130;
	}

#define ThrownWeapon_TypeDefinitionIndex 2408

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2d8;
	}

#define MapInterface_TypeDefinitionIndex 4211

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 4940

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 4202

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 3432

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2b0;
	}

#define PlayerCorpse_TypeDefinitionIndex 2570

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2e0;
	}

#define TimedExplosive_TypeDefinitionIndex 3292

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1ac;
	}

#define SmokeGrenade_TypeDefinitionIndex 2856

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x250;
	}

#define GrenadeWeapon_TypeDefinitionIndex 6104

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f0;
	}

#define ViewmodelLower_TypeDefinitionIndex 6210

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%dfbdf070f9346c677a8350647197c37f795ad05f
#define ConVar_Client_Static_ClassName "%0bdf86098ae7a3fc9a6ec2023f8fd8ea00ee87d8/%dfbdf070f9346c677a8350647197c37f795ad05f"
#define ConVar_Client_Static_ClassNameShort "%dfbdf070f9346c677a8350647197c37f795ad05f"
#define ConVar_Client_Static_TypeDefinitionIndex 2628

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x394;
		constexpr const static size_t camspeed = 0x784;
	}

#define SamSite_TypeDefinitionIndex 2446

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3a0;
		constexpr const static size_t Flag_TargetMode = 0x3dc;
	}

#define ServerProjectile_TypeDefinitionIndex 570

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 5648

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 3932

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 3341

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 6876

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 6737

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 1371

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x124;
	}

	// obf name: ::%cbf3fbd0f612e2c23e3987a945c29b458dd52f54
#define Facepunch_Network_Raknet_Client_ClassName "%cbf3fbd0f612e2c23e3987a945c29b458dd52f54"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%cbf3fbd0f612e2c23e3987a945c29b458dd52f54"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex -1

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x64fb060;
		constexpr const static size_t IsConnected_vtableoff = 0x358;
	}

	// obf name: ::%f0a22721fc72b0d5588d951f8a6c7b8367d47bcd
#define EncryptedValue_ClassName "%f0a22721fc72b0d5588d951f8a6c7b8367d47bcd<System/Int32>"
#define EncryptedValue_ClassNameShort "%f0a22721fc72b0d5588d951f8a6c7b8367d47bcd"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%5fbe261186dfd206d0ef97e3e565de5d791ad974
#define HiddenValue_ClassName "%5fbe261186dfd206d0ef97e3e565de5d791ad974<BaseNetworkable/%529ca09cc401518e65bdff87132172fc0a0461cc>"
#define HiddenValue_ClassNameShort "%5fbe261186dfd206d0ef97e3e565de5d791ad974"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x20;
		constexpr const static size_t _hasValue = 0x10;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 2981

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x2145af0;
	}

#define ItemModRFListener_TypeDefinitionIndex 4594

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x32af790;
	}

#define UIFogOverlay_TypeDefinitionIndex 5648

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
	}

	// obf name: ::%456dd36d3508aa080e34cae0a6a7bfc6d894c3f3
#define BufferStream_ClassName "%456dd36d3508aa080e34cae0a6a7bfc6d894c3f3"
#define BufferStream_ClassNameShort "%456dd36d3508aa080e34cae0a6a7bfc6d894c3f3"
#define BufferStream_TypeDefinitionIndex 7117

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x9507a40;
	}

#define FreeableLootContainer_TypeDefinitionIndex 3079

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 6179

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 6684

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x4a02d80;
	}

#define OutlineManager_TypeDefinitionIndex 6942

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%4373d14dee1b2d51aa36143642c60b756ce166d8
#define ProtoBuf_ProjectileShoot_ClassName "%4373d14dee1b2d51aa36143642c60b756ce166d8"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%4373d14dee1b2d51aa36143642c60b756ce166d8"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7247

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x94c4a60;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x94c5200;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%d1c91a6a776a896d6814c8faa3829ec726a967c5
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%4373d14dee1b2d51aa36143642c60b756ce166d8/%d1c91a6a776a896d6814c8faa3829ec726a967c5"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%d1c91a6a776a896d6814c8faa3829ec726a967c5"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7246

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t startPos = 0x28;
		constexpr const static size_t startVel = 0x1c;
		constexpr const static size_t seed = 0x10;
	}

	// obf name: ::%63ddba1f28ea74c126fd285b81fe3f756471e1ab
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%63ddba1f28ea74c126fd285b81fe3f756471e1ab"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%63ddba1f28ea74c126fd285b81fe3f756471e1ab"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7416

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t curPosition = 0x1c;
		constexpr const static size_t curVelocity = 0x28;
		constexpr const static size_t travelTime = 0x34;
		constexpr const static size_t ShouldPool = 0x10;

		// Functions
		constexpr const static size_t Dispose = 0x8c2b040;
		constexpr const static size_t WriteToStreamDelta = 0x8c20eb0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8c201c0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%e87ab3cb0d457947879654bf19ca14954bef4bab
#define ProtoBuf_PlayerProjectileAttack_ClassName "%e87ab3cb0d457947879654bf19ca14954bef4bab"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%e87ab3cb0d457947879654bf19ca14954bef4bab"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7501

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x20;
		constexpr const static size_t hitDistance = 0x1c;
		constexpr const static size_t travelTime = 0x14;
		constexpr const static size_t playerAttack = 0x30;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8f6f930;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8f6fa70;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%11a73d899a13dd7c9ec6e389254d7db013aceb63
#define ProtoBuf_PlayerAttack_ClassName "%11a73d899a13dd7c9ec6e389254d7db013aceb63"
#define ProtoBuf_PlayerAttack_ClassNameShort "%11a73d899a13dd7c9ec6e389254d7db013aceb63"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7180

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x10;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%ff3fd84f48fcc5417859c7d9d33744e28734802a
#define ProtoBuf_Attack_ClassName "%ff3fd84f48fcc5417859c7d9d33744e28734802a"
#define ProtoBuf_Attack_ClassNameShort "%ff3fd84f48fcc5417859c7d9d33744e28734802a"
#define ProtoBuf_Attack_TypeDefinitionIndex 7200

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x5c;
		constexpr const static size_t pointEnd = 0x10;
		constexpr const static size_t hitID = 0x30;
		constexpr const static size_t hitBone = 0x78;
		constexpr const static size_t hitNormalLocal = 0x40;
		constexpr const static size_t hitPositionLocal = 0x4c;
		constexpr const static size_t hitNormalWorld = 0x1c;
		constexpr const static size_t hitPositionWorld = 0x68;
		constexpr const static size_t hitPartID = 0x3c;
		constexpr const static size_t hitMaterialID = 0x58;
		constexpr const static size_t srcParentID = 0x80;
		constexpr const static size_t dstParentID = 0x28;
	}
}