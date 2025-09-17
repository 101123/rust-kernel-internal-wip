#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68c91777;
		constexpr const static size_t gc_handles = 0xd554a60;
		constexpr const static size_t il2cpp_resolve_icall = 0x79e1a0;
		constexpr const static size_t il2cpp_array_new = 0x79e1c0;
		constexpr const static size_t il2cpp_assembly_get_image = 0x5ece0;
		constexpr const static size_t il2cpp_class_from_name = 0x79e330;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x79e640;
		constexpr const static size_t il2cpp_class_get_type = 0x79e6e0;
		constexpr const static size_t il2cpp_domain_get = 0x79ec40;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x79ec60;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x79f520;
		constexpr const static size_t il2cpp_gchandle_new = 0x79f4d0;
		constexpr const static size_t il2cpp_gchandle_free = 0x79f5c0;
		constexpr const static size_t il2cpp_method_get_name = 0x2d50;
		constexpr const static size_t il2cpp_object_new = 0x79fc70;
		constexpr const static size_t il2cpp_type_get_object = 0x7a0460;
	}

#define Object_TypeDefinitionIndex 16568

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16539

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

#define Component_TypeDefinitionIndex 16526

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16520

	namespace Behaviour {

		// Functions
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 16603

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

#define Camera_TypeDefinitionIndex 16318

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16590

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

#define Material_TypeDefinitionIndex 16381

	namespace Material {

		// Functions
		constexpr const static size_t SetFloatImpl = 0xb6da0;
		constexpr const static size_t SetColorImpl_Injected = 0xb6ee0;
		constexpr const static size_t SetTextureImpl = 0xb7140;
		constexpr const static size_t CreateWithMaterial = 0xaf1c0;
		constexpr const static size_t CreateWithShader = 0xaf050;
		constexpr const static size_t SetBufferImpl = 0xb7490;
	}

#define MaterialPropertyBlock_TypeDefinitionIndex 16377

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xae4ce00;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16380

	namespace Shader {

		// Functions
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16436

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

#define Renderer_TypeDefinitionIndex 16378

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
	}

#define Texture_TypeDefinitionIndex 16439

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16441

	namespace Texture2D {
		constexpr const static size_t ctor = 0xae664b0;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define RenderTexture_TypeDefinitionIndex 16446

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xae6f140;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 16916

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xaeb23a0;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 16892

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xaeac480;
	}

#define ComputeBuffer_TypeDefinitionIndex 16581

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae90380;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xae905d0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16385

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae576e0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xae57410;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex -1

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xaed4b40;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16358

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16469

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

#define Screen_TypeDefinitionIndex 16355

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

#define Application_TypeDefinitionIndex 16301

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define BaseNetworkable_TypeDefinitionIndex 3450

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x28;
		constexpr const static size_t parentEntity = 0x60;
		constexpr const static size_t children = 0x38;
	}

	// obf name: ::%75fdce6437b220b1cc5e6b5a3096cac11faefe45
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%75fdce6437b220b1cc5e6b5a3096cac11faefe45"
#define BaseNetworkable_Static_ClassNameShort "%75fdce6437b220b1cc5e6b5a3096cac11faefe45"
#define BaseNetworkable_Static_TypeDefinitionIndex 3449

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x20;
	}

	// obf name: ::%24df6edff5300de8c9e1ef397575acb183b52a4c
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%24df6edff5300de8c9e1ef397575acb183b52a4c"
#define BaseNetworkable_EntityRealm_ClassNameShort "%24df6edff5300de8c9e1ef397575acb183b52a4c"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 3447

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x24c86a0;
	}

	// obf name: ::%7243de763bec2c0a3f18e486e3e0e5c7e88fef59
#define System_ListDictionary_ClassName "%7243de763bec2c0a3f18e486e3e0e5c7e88fef59<%f205b2c1226621aeac74adbd0b139c72f320e16e,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%7243de763bec2c0a3f18e486e3e0e5c7e88fef59"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x20;

		// Functions
		constexpr const static size_t TryGetValue = 0x757a180;
		constexpr const static size_t TryGetValue_methodinfo = 0xd1f8830;
	}

	// obf name: ::%344ab3470306380ab6a1a2e8142e6f902c306170
#define System_BufferList_ClassName "%344ab3470306380ab6a1a2e8142e6f902c306170<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%344ab3470306380ab6a1a2e8142e6f902c306170"
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

#define Model_TypeDefinitionIndex 3333

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 2713

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa0;
		constexpr const static size_t model = 0xc8;
		constexpr const static size_t flags = 0xd0;
		constexpr const static size_t triggers = 0x140;
		constexpr const static size_t positionLerp = 0x160;

		// Functions
		constexpr const static size_t ServerRPC = 0x1d199d0;
		constexpr const static size_t FindBone = 0x1ced0d0;
		constexpr const static size_t GetWorldVelocity = 0x1d074d0;
		constexpr const static size_t GetParentVelocity = 0x1d074d0;
	}

	// obf name: ::%d96ef02dd785084fc0255a0df079c516fcb7f7ea
#define PositionLerp_ClassName "%d96ef02dd785084fc0255a0df079c516fcb7f7ea"
#define PositionLerp_ClassNameShort "%d96ef02dd785084fc0255a0df079c516fcb7f7ea"
#define PositionLerp_TypeDefinitionIndex 5147

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x28;
	}

	// obf name: ::%fd525f3efeb426782835f642639fb23eddd1d9a2
#define Interpolator_ClassName "%fd525f3efeb426782835f642639fb23eddd1d9a2<%fccceb66556f1a269ff2f6b50690b2975b3511b8>"
#define Interpolator_ClassNameShort "%fd525f3efeb426782835f642639fb23eddd1d9a2"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 3692

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

#define SkeletonProperties_TypeDefinitionIndex 4309

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 4307

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t name = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 1850

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 1849

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%a8bd20f5d74a7dc1f9be462652d2ba4d55b6c106
#define DamageTypeList_ClassName "%a8bd20f5d74a7dc1f9be462652d2ba4d55b6c106"
#define DamageTypeList_ClassNameShort "%a8bd20f5d74a7dc1f9be462652d2ba4d55b6c106"
#define DamageTypeList_TypeDefinitionIndex 6730

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 3420

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 5682

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

#define RecoilProperties_TypeDefinitionIndex 3122

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 5318

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 6164

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x238;
		constexpr const static size_t repeatDelay = 0x23c;
		constexpr const static size_t animationDelay = 0x240;
		constexpr const static size_t noHeadshots = 0x28e;
		constexpr const static size_t nextAttackTime = 0x290;
		constexpr const static size_t timeSinceDeploy = 0x2a8;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x43b6fe0;
		constexpr const static size_t StartAttackCooldown = 0x43b8d60;
	}

#define BaseProjectile_TypeDefinitionIndex 5322

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
		constexpr const static size_t LaunchProjectile = 0x3ad1b00;
		constexpr const static size_t LaunchProjectileClientSide = 0x3ab7c20;
		constexpr const static size_t ScaleRepeatDelay = 0x3ab46a0;
		constexpr const static size_t GetAimCone = 0x3ab5fe0;
		constexpr const static size_t GetAimCone_vtableoff = 0x3b48;
		constexpr const static size_t UpdateAmmoDisplay = 0x3ac6e80;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3dc8;
	}

#define BaseLauncher_TypeDefinitionIndex 2628

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 926

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%5ea09302831dfe4534e5513e7b948680b9cd8e5b
#define HitTest_ClassName "%5ea09302831dfe4534e5513e7b948680b9cd8e5b"
#define HitTest_ClassNameShort "%5ea09302831dfe4534e5513e7b948680b9cd8e5b"
#define HitTest_TypeDefinitionIndex 6699

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0xa4;
		constexpr const static size_t AttackRay = 0x84;
		constexpr const static size_t RayHit = 0xb4;
		constexpr const static size_t damageProperties = 0x48;
		constexpr const static size_t gameObject = 0x38;
		constexpr const static size_t collider = 0x30;
		constexpr const static size_t ignoredTypes = 0x68;
		constexpr const static size_t HitTransform = 0x78;
		constexpr const static size_t HitPart = 0x9c;
		constexpr const static size_t HitMaterial = 0x20;
		constexpr const static size_t DidHit = 0xa0;
		constexpr const static size_t MaxDistance = 0xe4;
		constexpr const static size_t HitNormal = 0x10;
		constexpr const static size_t HitPoint = 0x50;
		constexpr const static size_t ignoreEntity = 0x60;
		constexpr const static size_t HitEntity = 0xa8;
	}

#define Projectile_TypeDefinitionIndex 4649

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
		constexpr const static size_t sourceProjectilePrefab = 0x1e0;
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
		constexpr const static size_t CalculateEffectScale = 0x33c4390;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x3d8;
		constexpr const static size_t SetEffectScale = 0x33ad1a0;
		constexpr const static size_t UpdateVelocity = 0x33961c0;
		constexpr const static size_t Retire = 0x338cc80;
		constexpr const static size_t DoHit = 0x33c67d0;
	}

	// obf name: ::%4f84be99e455a10053d38b1949997cf516c58982
#define HitInfo_ClassName "%4f84be99e455a10053d38b1949997cf516c58982"
#define HitInfo_ClassNameShort "%4f84be99e455a10053d38b1949997cf516c58982"
#define HitInfo_TypeDefinitionIndex 677

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x10;
		constexpr const static size_t damageTypes = 0x38;

		// Functions
		constexpr const static size_t get_boneArea = 0x4e8c550;
	}

	// obf name: ::%2d4d0e5b2e89f1c8ae601421e447b34dbc1c9a63
#define GameTrace_ClassName "%2d4d0e5b2e89f1c8ae601421e447b34dbc1c9a63"
#define GameTrace_ClassNameShort "%2d4d0e5b2e89f1c8ae601421e447b34dbc1c9a63"
#define GameTrace_TypeDefinitionIndex 1764

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x12f09a0;
	}

#define BaseMelee_TypeDefinitionIndex 6920

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d0;
		constexpr const static size_t maxDistance = 0x2e8;
		constexpr const static size_t attackRadius = 0x2ec;
		constexpr const static size_t blockSprintOnAttack = 0x2f1;
		constexpr const static size_t gathering = 0x320;
		constexpr const static size_t canThrowAsProjectile = 0x329;

		// Functions
		constexpr const static size_t ProcessAttack = 0x4b0f040;
		constexpr const static size_t DoThrow = 0x4affa80;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 4863

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x400;
		constexpr const static size_t strikeRecoil = 0x408;
		constexpr const static size_t _didSparkThisFrame = 0x410;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 566

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x418;
		constexpr const static size_t stringBonusVelocity = 0x424;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x45b7530;
	}

	// obf name: ::%8efd5f258d55fcba0b643e133fccc3f022645257
#define ItemContainer_ClassName "%8efd5f258d55fcba0b643e133fccc3f022645257"
#define ItemContainer_ClassNameShort "%8efd5f258d55fcba0b643e133fccc3f022645257"
#define ItemContainer_TypeDefinitionIndex 2191

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x50;
		constexpr const static size_t itemList = 0x18;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x17d72e0;
	}

#define PlayerLoot_TypeDefinitionIndex 1283

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 3863

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x28;
		constexpr const static size_t containerWear = 0x30;
		constexpr const static size_t containerMain = 0x60;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x2a7bf80;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 3275

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x230a970;
		constexpr const static size_t get_rotation = 0x22f1f40;
		constexpr const static size_t set_rotation = 0x22f8c80;
		constexpr const static size_t HeadForward = 0x22ee500;
	}

	// obf name: ::%11b76e26f58efeb7c367593d931565092262b8aa
#define PlayerEyes_Static_ClassName "PlayerEyes/%11b76e26f58efeb7c367593d931565092262b8aa"
#define PlayerEyes_Static_ClassNameShort "%11b76e26f58efeb7c367593d931565092262b8aa"
#define PlayerEyes_Static_TypeDefinitionIndex 3274

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x50;
	}

	// obf name: ::%1fbb51dc4225bf0e991629c27649852c5dc1ecbf
#define PlayerBelt_ClassName "%1fbb51dc4225bf0e991629c27649852c5dc1ecbf"
#define PlayerBelt_ClassNameShort "%1fbb51dc4225bf0e991629c27649852c5dc1ecbf"
#define PlayerBelt_TypeDefinitionIndex 5648

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x3f18170;
		constexpr const static size_t GetActiveItem = 0x3f17c50;
	}

	// obf name: ::%eb23c4956be5188d9cf6e6cca273d3689ad3aa13
#define LocalPlayer_ClassName "%eb23c4956be5188d9cf6e6cca273d3689ad3aa13"
#define LocalPlayer_ClassNameShort "%eb23c4956be5188d9cf6e6cca273d3689ad3aa13"
#define LocalPlayer_TypeDefinitionIndex 2452

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x1ab7550;
		constexpr const static size_t MoveItem = 0x1ac1250;
		constexpr const static size_t get_Entity = 0x1ab96f0;
	}

	// obf name: ::%0c79d4949f0490f92e94fae9607ebe22f1f4c676
#define LocalPlayer_Static_ClassName "%eb23c4956be5188d9cf6e6cca273d3689ad3aa13/%0c79d4949f0490f92e94fae9607ebe22f1f4c676"
#define LocalPlayer_Static_ClassNameShort "%0c79d4949f0490f92e94fae9607ebe22f1f4c676"
#define LocalPlayer_Static_TypeDefinitionIndex 2451

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0xf8;
	}

	// obf name: ::%cbe72cad4217945bfef7cf15bcb10a5919227844
#define BasePlayer_Static_ClassName "BasePlayer/%cbe72cad4217945bfef7cf15bcb10a5919227844"
#define BasePlayer_Static_ClassNameShort "%cbe72cad4217945bfef7cf15bcb10a5919227844"
#define BasePlayer_Static_TypeDefinitionIndex 3509

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0xb48;
	}

#define BasePlayer_TypeDefinitionIndex 3510

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x5b0;
		constexpr const static size_t input = 0x4c8;
		constexpr const static size_t movement = 0x598;
		constexpr const static size_t currentTeam = 0x460;
		constexpr const static size_t clActiveItem = 0x490;
		constexpr const static size_t modelState = 0x270;
		constexpr const static size_t playerFlags = 0x588;
		constexpr const static size_t eyes = 0x358;
		constexpr const static size_t playerRigidbody = 0x280;
		constexpr const static size_t userID = 0x5d0;
		constexpr const static size_t UserIDString = 0x410;
		constexpr const static size_t inventory = 0x298;
		constexpr const static size_t _displayName = 0x550;
		constexpr const static size_t _lookingAt = 0x268;
		constexpr const static size_t lastSentTickTime = 0x544;
		constexpr const static size_t lastSentTick = 0x4a8;
		constexpr const static size_t mounted = 0x4d0;
		constexpr const static size_t Belt = 0x590;
		constexpr const static size_t _lookingAtEntity = 0x518;
		constexpr const static size_t currentGesture = 0x468;
		constexpr const static size_t weaponMoveSpeedScale = 0x660;
		constexpr const static size_t clothingBlocksAiming = 0x664;
		constexpr const static size_t clothingMoveSpeedReduction = 0x668;
		constexpr const static size_t clothingWaterSpeedBonus = 0x66c;
		constexpr const static size_t equippingBlocked = 0x674;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x25f2a80;
		constexpr const static size_t Menu_AssistPlayer = 0x2578c90;
		constexpr const static size_t OnViewModeChanged = 0x258bf60;
		constexpr const static size_t ChatMessage = 0x2578ce0;
		constexpr const static size_t IsOnGround = 0x2536680;
		constexpr const static size_t GetSpeed = 0x260bae0;
		constexpr const static size_t SendProjectileUpdate = 0x2651650;
		constexpr const static size_t SendProjectileAttack = 0x2625cd0;
		constexpr const static size_t CanBuild = 0x25bbbc0;
		constexpr const static size_t GetMounted = 0x25d4a50;
		constexpr const static size_t GetHeldEntity = 0x26c0e40;
		constexpr const static size_t get_inventory = 0x2642780;
		constexpr const static size_t get_eyes = 0x26669f0;
		constexpr const static size_t SendClientTick = 0x262b2b0;
		constexpr const static size_t ClientInput = 0x26932f0;
		constexpr const static size_t ClientInput_vtableoff = 0x3c08;
		constexpr const static size_t MaxHealth = 0x2643ca0;
		constexpr const static size_t MaxHealth_vtableoff = 0x1918;
		constexpr const static size_t OnAttacked = 0x2653480;
		constexpr const static size_t OnAttacked_vtableoff = 0x15b8;
	}

#define ScientistNPC_TypeDefinitionIndex 6905

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 4112

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 6298

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 5600

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 1770

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 3995

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 3528

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x26f10b0;
		constexpr const static size_t BlockSprint = 0x26e4a50;
		constexpr const static size_t GroundCheck = 0x2704690;
		constexpr const static size_t ClientInput = 0x26efa50;
		constexpr const static size_t ClientInput_vtableoff = 0x198;
		constexpr const static size_t DoFixedUpdate = 0x26df220;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x1e8;
		constexpr const static size_t FrameUpdate = 0x26d4a00;
		constexpr const static size_t FrameUpdate_vtableoff = 0x308;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 2214

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x370;
		constexpr const static size_t cachedProtectedMinutes = 0x378;
	}

#define WorldItem_TypeDefinitionIndex 962

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a0;
		constexpr const static size_t item = 0x1a8;
	}

#define HackableLockedCrate_TypeDefinitionIndex 1920

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x388;
		constexpr const static size_t hackSeconds = 0x398;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 3682

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 3678

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%7028f7e92106e5004a5ec0c09b82422f2b8bdcf6
#define ConsoleSystem_ClassName "%7028f7e92106e5004a5ec0c09b82422f2b8bdcf6"
#define ConsoleSystem_ClassNameShort "%7028f7e92106e5004a5ec0c09b82422f2b8bdcf6"
#define ConsoleSystem_TypeDefinitionIndex -1

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x6400b50;
	}

#define ConsoleSystem_Option_ClassName "%7028f7e92106e5004a5ec0c09b82422f2b8bdcf6/%9fbbd135b18e7e2572ee376f4d15403d1bf8f172"
#define ConsoleSystem_Option_ClassNameShort "%9fbbd135b18e7e2572ee376f4d15403d1bf8f172"
#define ConsoleSystem_Command_ClassName "%7028f7e92106e5004a5ec0c09b82422f2b8bdcf6/%3c781d7bea11fdbf49e4c4ca994558a6a178afde"
#define ConsoleSystem_Command_ClassNameShort "%3c781d7bea11fdbf49e4c4ca994558a6a178afde"
	// obf name: ::%0fcc48d115dde1631b521c836fe5f7c1fb061ba7
#define ConsoleSystem_Index_Static_ClassName "%7028f7e92106e5004a5ec0c09b82422f2b8bdcf6/%ce663a6c8814a0b852204db4d0977e93dbb4c7ce.%0fcc48d115dde1631b521c836fe5f7c1fb061ba7"
#define ConsoleSystem_Index_Static_ClassNameShort "%0fcc48d115dde1631b521c836fe5f7c1fb061ba7"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex -1

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0xa8;
	}

	// obf name: ::%961d246f87244b64be3ad2c0e36be51e2416319d
#define ConsoleSystem_Arg_ClassName "%7028f7e92106e5004a5ec0c09b82422f2b8bdcf6/%961d246f87244b64be3ad2c0e36be51e2416319d"
#define ConsoleSystem_Arg_ClassNameShort "%961d246f87244b64be3ad2c0e36be51e2416319d"
// obf name: ::%a9c5ee2abcd6f08e32b4147f870acaff5449096d
#define Facepunch_Network_SteamNetworking_ClassName "%a9c5ee2abcd6f08e32b4147f870acaff5449096d"
#define Facepunch_Network_SteamNetworking_ClassNameShort "%a9c5ee2abcd6f08e32b4147f870acaff5449096d"
#define LootableCorpse_TypeDefinitionIndex 1916

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2a8;
		constexpr const static size_t _playerName = 0x2b8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 2464

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x278;
		constexpr const static size_t _playerName = 0x260;
	}

#define MainCamera_TypeDefinitionIndex 3342

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x58;
		constexpr const static size_t mainCameraTransform = 0x80;

		// Functions
		constexpr const static size_t Update = 0x241f280;
		constexpr const static size_t OnPreCull = 0x24129d0;
		constexpr const static size_t Trace = 0x2418c10;
	}

#define CameraMan_TypeDefinitionIndex 420

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%fc2d1edd845030596e48f9e0a2ae9315f76b2319
#define PlayerTick_ClassName "%fc2d1edd845030596e48f9e0a2ae9315f76b2319"
#define PlayerTick_ClassNameShort "%fc2d1edd845030596e48f9e0a2ae9315f76b2319"
#define PlayerTick_TypeDefinitionIndex 7159

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x48;
		constexpr const static size_t modelState = 0x50;
		constexpr const static size_t activeItem = 0x40;
		constexpr const static size_t parentID = 0x18;
		constexpr const static size_t position = 0x30;
		constexpr const static size_t eyePos = 0x20;
	}

	// obf name: ::%d4efc4f2360cb2cd3ead44dac57711e474e3650b
#define InputMessage_ClassName "%d4efc4f2360cb2cd3ead44dac57711e474e3650b"
#define InputMessage_ClassNameShort "%d4efc4f2360cb2cd3ead44dac57711e474e3650b"
#define InputMessage_TypeDefinitionIndex 7468

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x20;
		constexpr const static size_t mouseDelta = 0x14;
		constexpr const static size_t aimAngles = 0x28;
	}

	// obf name: ::%a0aac063dccc14ca3a4828e36b5757b056cb4fca
#define InputState_ClassName "%a0aac063dccc14ca3a4828e36b5757b056cb4fca"
#define InputState_ClassNameShort "%a0aac063dccc14ca3a4828e36b5757b056cb4fca"
#define InputState_TypeDefinitionIndex 1935

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x20;
	}

#define PlayerInput_TypeDefinitionIndex 3008

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%02191887ca257705f6168cad42d92f026f2f7c02
#define ModelState_ClassName "%02191887ca257705f6168cad42d92f026f2f7c02"
#define ModelState_ClassNameShort "%02191887ca257705f6168cad42d92f026f2f7c02"
#define ModelState_TypeDefinitionIndex 7556

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x78;
		constexpr const static size_t waterLevel = 0x70;
		constexpr const static size_t lookDir = 0x64;
	}

	// obf name: ::%23bde69462673c8dc65f0b2e6fa13d31237b5f9d
#define Item_ClassName "%23bde69462673c8dc65f0b2e6fa13d31237b5f9d"
#define Item_ClassNameShort "%23bde69462673c8dc65f0b2e6fa13d31237b5f9d"
#define Item_TypeDefinitionIndex 1501

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0xb8;
		constexpr const static size_t uid = 0x60;
		constexpr const static size_t _maxCondition = 0x90;
		constexpr const static size_t _condition = 0xb0;
		constexpr const static size_t position = 0x24;
		constexpr const static size_t amount = 0x88;
		constexpr const static size_t contents = 0x28;
		constexpr const static size_t parent = 0xc0;
		constexpr const static size_t worldEnt = 0x30;
		constexpr const static size_t heldEntity = 0x70;

		// Functions
		constexpr const static size_t get_iconSprite = 0x10b3f40;
	}

	// obf name: ::%dc8735d992318edaf7021b2b0ad5ed34fb9bab10
#define WaterLevel_ClassName "%dc8735d992318edaf7021b2b0ad5ed34fb9bab10"
#define WaterLevel_ClassNameShort "%dc8735d992318edaf7021b2b0ad5ed34fb9bab10"
#define WaterLevel_TypeDefinitionIndex 3908

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x2b6b210;
		constexpr const static size_t GetWaterLevel = 0x2b54b30;
	}

	// obf name: ::%faf9b008a6d32f51a33f1b5de067433f9ac341c6
#define ConVar_Graphics_Static_ClassName "%6592e069f04fccfbd645bbf84f9382674b37af84/%faf9b008a6d32f51a33f1b5de067433f9ac341c6"
#define ConVar_Graphics_Static_ClassNameShort "%faf9b008a6d32f51a33f1b5de067433f9ac341c6"
#define ConVar_Graphics_Static_TypeDefinitionIndex 1291

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x1dc;

		// Functions
		constexpr const static size_t _fov_getter = 0x4b5a6e0;
		constexpr const static size_t _fov_setter = 0x4b293a0;
	}

#define BaseFishingRod_TypeDefinitionIndex 283

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x258;
		constexpr const static size_t currentBobber = 0x260;
		constexpr const static size_t MaxCastDistance = 0x27c;
		constexpr const static size_t BobberPreview = 0x288;
		constexpr const static size_t clientStrainAmountNormalised = 0x2c8;
		constexpr const static size_t strainGainMod = 0x2c0;
		constexpr const static size_t aimAnimationReady = 0x2e0;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x23c5200;
		constexpr const static size_t EvaluateFishingPosition = 0x23beae0;
	}

#define FishingBobber_TypeDefinitionIndex 2611

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x278;
	}

#define GameManifest_TypeDefinitionIndex 5976

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x4258810;
	}

	// obf name: ::%d1b18d8b3f794c695cebce166c3de287ba8761fd
#define GameManager_ClassName "%d1b18d8b3f794c695cebce166c3de287ba8761fd"
#define GameManager_ClassNameShort "%d1b18d8b3f794c695cebce166c3de287ba8761fd"
#define GameManager_TypeDefinitionIndex 5413

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x10;

		// Functions
		constexpr const static size_t CreatePrefab = 0x3c19270;
	}

	// obf name: ::%dfb68ae9b43ebecb327d9e6981696e4b4348d922
#define GameManager_Static_ClassName "%d1b18d8b3f794c695cebce166c3de287ba8761fd/%dfb68ae9b43ebecb327d9e6981696e4b4348d922"
#define GameManager_Static_ClassNameShort "%dfb68ae9b43ebecb327d9e6981696e4b4348d922"
#define GameManager_Static_TypeDefinitionIndex 5412

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x8;
	}

	// obf name: ::%ac3d8b98291ad6b9822d4237e69b313c40360137
#define PrefabPoolCollection_ClassName "%ac3d8b98291ad6b9822d4237e69b313c40360137"
#define PrefabPoolCollection_ClassNameShort "%ac3d8b98291ad6b9822d4237e69b313c40360137"
#define PrefabPoolCollection_TypeDefinitionIndex 28

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x18;
	}

	// obf name: ::%ab3ca04702f2515c4b0bc486dfc10b2adb5c7b2d
#define PrefabPool_ClassName "%ab3ca04702f2515c4b0bc486dfc10b2adb5c7b2d"
#define PrefabPool_ClassNameShort "%ab3ca04702f2515c4b0bc486dfc10b2adb5c7b2d"
#define PrefabPool_TypeDefinitionIndex 2728

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x10;
	}

#define ItemModProjectile_TypeDefinitionIndex 6504

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

#define CraftingQueue_TypeDefinitionIndex 3063

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%dcd6a5c94cee595ee9227aa5e2b3b9e0c77048f2
#define CraftingQueue_Static_ClassName "CraftingQueue/%dcd6a5c94cee595ee9227aa5e2b3b9e0c77048f2"
#define CraftingQueue_Static_ClassNameShort "%dcd6a5c94cee595ee9227aa5e2b3b9e0c77048f2"
#define CraftingQueue_Static_TypeDefinitionIndex 3062

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x70;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 92

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%4979aa90fa7e8ce80cbc76d496f354fc5083f2f2
#define Planner_Static_ClassName "Planner/%4979aa90fa7e8ce80cbc76d496f354fc5083f2f2"
#define Planner_Static_ClassNameShort "%4979aa90fa7e8ce80cbc76d496f354fc5083f2f2"
#define Planner_Static_TypeDefinitionIndex 4434

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x178;
	}

	// obf name: ::%d7670c50ace17310d4431406e1f91c5d170d4222
#define Planner_Guide_ClassName "Planner/%d7670c50ace17310d4431406e1f91c5d170d4222"
#define Planner_Guide_ClassNameShort "%d7670c50ace17310d4431406e1f91c5d170d4222"
#define Planner_Guide_TypeDefinitionIndex 4430

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x98;
	}

#define Planner_TypeDefinitionIndex 4435

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x280;
	}

#define Construction_TypeDefinitionIndex 3225

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x180;
	}

#define BuildingBlock_TypeDefinitionIndex 6635

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2f0;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 5366

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x218;
		constexpr const static size_t _punches = 0x1c0;
		constexpr const static size_t viewModel = 0x220;

		// Functions
		constexpr const static size_t OnDeploy = 0x3b7ee70;
	}

	// obf name: ::%d7df33fcab6612f9f4b43d15989e5efd37b13c0a
#define PunchEntry_ClassName "HeldEntity/%d7df33fcab6612f9f4b43d15989e5efd37b13c0a"
#define PunchEntry_ClassNameShort "%d7df33fcab6612f9f4b43d15989e5efd37b13c0a"
#define PunchEntry_TypeDefinitionIndex 5364

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x1c;
		constexpr const static size_t duration = 0x2c;
		constexpr const static size_t amountAdded = 0x10;
		constexpr const static size_t amount = 0x20;
	}

#define IronSights_TypeDefinitionIndex 3743

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 6018

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 2617

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xb8;
		constexpr const static size_t model = 0x98;
		constexpr const static size_t lower = 0xa0;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x1c6ef10;
	}

#define ViewModel_TypeDefinitionIndex 644

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x4cc5800;
		constexpr const static size_t PlayString = 0x4cc4ea0;
	}

#define MedicalTool_TypeDefinitionIndex 271

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f0;
	}

#define WaterBody_TypeDefinitionIndex 3574

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x68;
	}

	// obf name: ::%e40c22428e888d938d8eaec55f972e85eefe097c
#define WaterSystem_Static_ClassName "WaterSystem/%e40c22428e888d938d8eaec55f972e85eefe097c"
#define WaterSystem_Static_ClassNameShort "%e40c22428e888d938d8eaec55f972e85eefe097c"
#define WaterSystem_Static_TypeDefinitionIndex 2061

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0xd0;
	}

#define WaterSystem_TypeDefinitionIndex 2062

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x1613520;
	}

#define TerrainMeta_TypeDefinitionIndex 5390

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x620;
		constexpr const static size_t HeightMap = 0x3c0;
		constexpr const static size_t SplatMap = 0x410;
		constexpr const static size_t TopologyMap = 0x518;
		constexpr const static size_t Texturing = 0x4b0;
	}

#define TerrainCollision_TypeDefinitionIndex 4925

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x3650ff0;
	}

#define TerrainHeightMap_TypeDefinitionIndex 5878

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 1680

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 1933

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%05e9e54f80912c3a6936809be2fbb3b9c14c6e9f
#define World_Static_ClassName "%35ac8265ee40c73da4b8a7d0a7796a8ed6dbd505/%05e9e54f80912c3a6936809be2fbb3b9c14c6e9f"
#define World_Static_ClassNameShort "%05e9e54f80912c3a6936809be2fbb3b9c14c6e9f"
#define World_Static_TypeDefinitionIndex 2512

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x278;
	}

#define ItemIcon_TypeDefinitionIndex 3307

	namespace ItemIcon {

		// Functions
		constexpr const static size_t SetTimedLootAction = 0x2370710;
	}

	// obf name: ::%e82bf82e0a4fbcd054a19aa229c3355a08de326e
#define ItemIcon_Static_ClassName "ItemIcon/%e82bf82e0a4fbcd054a19aa229c3355a08de326e"
#define ItemIcon_Static_ClassNameShort "%e82bf82e0a4fbcd054a19aa229c3355a08de326e"
#define ItemIcon_Static_TypeDefinitionIndex 3306

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x8;
	}

	// obf name: ::%e81f793b2e72fd471d0f07355036cc68f9ff7843
#define Effect_ClassName "%e81f793b2e72fd471d0f07355036cc68f9ff7843"
#define Effect_ClassNameShort "%e81f793b2e72fd471d0f07355036cc68f9ff7843"
#define Effect_TypeDefinitionIndex 4100

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0xb0;
		constexpr const static size_t worldPos = 0xa0;
	}

	// obf name: ::%e241b1753c46c6a16beef388248270b7b16e5f56
#define EffectNetwork_ClassName "%e241b1753c46c6a16beef388248270b7b16e5f56"
#define EffectNetwork_ClassNameShort "%e241b1753c46c6a16beef388248270b7b16e5f56"
#define EffectNetwork_TypeDefinitionIndex 5149

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%cca9687e091a78e1187adb89db7ef99ae362e645
#define EffectNetwork_Static_ClassName "%e241b1753c46c6a16beef388248270b7b16e5f56/%cca9687e091a78e1187adb89db7ef99ae362e645"
#define EffectNetwork_Static_ClassNameShort "%cca9687e091a78e1187adb89db7ef99ae362e645"
#define EffectNetwork_Static_TypeDefinitionIndex 5148

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x8;

		// Functions
		constexpr const static size_t cctor = 0x389f960;
	}

#define BuildingBlock_TypeDefinitionIndex 6635

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2e8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x4839d80;
		constexpr const static size_t HasUpgradePrivilege = 0x48458a0;
		constexpr const static size_t CanAffordUpgrade = 0x48576c0;
	}

	// obf name: ::%494db82323e722bdb6b7d7259056a238aba7f099
#define GameObjectEx_ClassName "%494db82323e722bdb6b7d7259056a238aba7f099"
#define GameObjectEx_ClassNameShort "%494db82323e722bdb6b7d7259056a238aba7f099"
#define GameObjectEx_TypeDefinitionIndex 1871

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x13e12d0;
	}

#define UIDeathScreen_TypeDefinitionIndex 5221

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x396a440;
	}

	// obf name: ::%047e52867d393c962230b4e7019cfe86ecebbe12
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%047e52867d393c962230b4e7019cfe86ecebbe12"
#define BaseScreenShake_Static_ClassNameShort "%047e52867d393c962230b4e7019cfe86ecebbe12"
#define BaseScreenShake_Static_TypeDefinitionIndex 6882

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x8;
	}

#define FlashbangOverlay_TypeDefinitionIndex 4065

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x38;
		constexpr const static size_t flashLength = 0x40;
	}

	// obf name: ::%40dd39c88401d023616fa4bdff2da5abbfe07f3b
#define StringPool_ClassName "%40dd39c88401d023616fa4bdff2da5abbfe07f3b"
#define StringPool_ClassNameShort "%40dd39c88401d023616fa4bdff2da5abbfe07f3b"
#define StringPool_TypeDefinitionIndex 5512

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x70;

		// Functions
		constexpr const static size_t Get = 0x3d1ba60;
	}

	// obf name: ::%ee98de9318fe4440b6fad8f6ef2131b1d8abf615
#define Network_Networkable_ClassName "%ee98de9318fe4440b6fad8f6ef2131b1d8abf615"
#define Network_Networkable_ClassNameShort "%ee98de9318fe4440b6fad8f6ef2131b1d8abf615"
#define Network_Networkable_TypeDefinitionIndex 18369

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x28;
	}

	// obf name: ::%1d613e300459be4549b76916d04a07eddfd0604e
#define Network_Net_ClassName "%1d613e300459be4549b76916d04a07eddfd0604e"
#define Network_Net_ClassNameShort "%1d613e300459be4549b76916d04a07eddfd0604e"
#define Network_Net_TypeDefinitionIndex 7693

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x28;
	}

	// obf name: ::%b3f0c94970d140766796960fdef79c23ec4e71c4
#define Network_Client_ClassName "%b3f0c94970d140766796960fdef79c23ec4e71c4"
#define Network_Client_ClassNameShort "%b3f0c94970d140766796960fdef79c23ec4e71c4"
#define Network_Client_TypeDefinitionIndex 18380

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0x110;
		constexpr const static size_t ConnectedPort = 0x100;
		constexpr const static size_t ConnectedAddress = 0xd8;
		constexpr const static size_t ServerName = 0xe8;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x64998a0;
		constexpr const static size_t DestroyNetworkable = 0x649a950;
	}

	// obf name: ::%001b6b0b81cab7a6523b0abc3e40867c8c6b56dc
#define Network_BaseNetwork_ClassName "%001b6b0b81cab7a6523b0abc3e40867c8c6b56dc"
#define Network_BaseNetwork_ClassNameShort "%001b6b0b81cab7a6523b0abc3e40867c8c6b56dc"
#define Network_BaseNetwork_TypeDefinitionIndex 18420

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x64c8060;
	}

	// obf name: ::%8e00bab26eb7803874544ca6255f775b49fb393d
#define Network_SendInfo_ClassName "%8e00bab26eb7803874544ca6255f775b49fb393d"
#define Network_SendInfo_ClassNameShort "%8e00bab26eb7803874544ca6255f775b49fb393d"
#define Network_SendInfo_TypeDefinitionIndex 18381

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%68bbe2b5ef761edef45348d7aaa8de9c7b786f1f
#define Network_Message_ClassName "%68bbe2b5ef761edef45348d7aaa8de9c7b786f1f"
#define Network_Message_ClassNameShort "%68bbe2b5ef761edef45348d7aaa8de9c7b786f1f"
#define Network_Message_TypeDefinitionIndex 18417

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%e32f3bbe7d723f441133b9228dc7a2fb74fa9d3a
#define Network_NetRead_ClassName "%e32f3bbe7d723f441133b9228dc7a2fb74fa9d3a"
#define Network_NetRead_ClassNameShort "%e32f3bbe7d723f441133b9228dc7a2fb74fa9d3a"
#define Network_NetRead_TypeDefinitionIndex 18408

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x38;
	}

	// obf name: ::%1867602bcb5969974cb5d0bc51df06780940c147
#define Network_NetWrite_ClassName "%1867602bcb5969974cb5d0bc51df06780940c147"
#define Network_NetWrite_ClassNameShort "%1867602bcb5969974cb5d0bc51df06780940c147"
#define Network_NetWrite_TypeDefinitionIndex 18422

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x38;

		// Functions
		constexpr const static size_t WriteByte = 0x64e7620;
		constexpr const static size_t String = 0x64e52a0;
		constexpr const static size_t Send = 0x64e3be0;
	}

#define LootPanel_TypeDefinitionIndex 247

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x1f23410;
	}

#define UIInventory_TypeDefinitionIndex 2850

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x1ecbd40;
	}

#define GrowableEntity_TypeDefinitionIndex 1245

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2b0;
		constexpr const static size_t State = 0x2c0;
	}

#define PlantProperties_TypeDefinitionIndex 1507

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 1506

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 20907

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 8727

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
		constexpr const static size_t get_Instance = 0xb98960;
	}

	// obf name: ::%60bc2f11e5e64fc3bb06598547418f93670f6f39
#define TOD_Sky_Static_ClassName "TOD_Sky/%60bc2f11e5e64fc3bb06598547418f93670f6f39"
#define TOD_Sky_Static_ClassNameShort "%60bc2f11e5e64fc3bb06598547418f93670f6f39"
#define TOD_Sky_Static_TypeDefinitionIndex 8726

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x80;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 7861

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0x8ed150;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 8298

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 7922

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8562

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
	}

#define TOD_StarParameters_TypeDefinitionIndex 9275

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 7710

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 9014

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 3315

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 5345

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 2602

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 6066

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

#define EnvironmentManager_TypeDefinitionIndex 2888

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x1f0ec30;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%86b5b454124ce2fe0bcd615c2942b14ca80638a6/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex -1

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 10

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 11

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 4473

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

	// obf name: ::%95da7a3885004d757857ca688ec3a84ebece1178
#define ListHashSet_ClassName "%95da7a3885004d757857ca688ec3a84ebece1178<UIChat>"
#define ListHashSet_ClassNameShort "%95da7a3885004d757857ca688ec3a84ebece1178"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 4185

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x268;
		constexpr const static size_t weakspots = 0x3e0;
	}

#define Chainsaw_TypeDefinitionIndex 257

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%90e615c400896573fba86ebd6428ff497184dcd8
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%90e615c400896573fba86ebd6428ff497184dcd8"
#define CameraUpdateHook_Static_ClassNameShort "%90e615c400896573fba86ebd6428ff497184dcd8"
#define CameraUpdateHook_Static_TypeDefinitionIndex 4263

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x20;
	}

#define SteamClientWrapper_TypeDefinitionIndex 284

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x2505620;
	}

	// obf name: ::%44f33e4339cef23019b9f7a847416926c0b43c10
#define AimConeUtil_ClassName "%44f33e4339cef23019b9f7a847416926c0b43c10"
#define AimConeUtil_ClassNameShort "%44f33e4339cef23019b9f7a847416926c0b43c10"
#define AimConeUtil_TypeDefinitionIndex 4373

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x30e5db0;
	}

	// obf name: ::%20d19189c5f9b07c9df1c0905ef4ce042a220a2f
#define Buttons_ConButton_ClassName "%60fa9fa0b3b8f939208be68b00048afd50e24a83/%20d19189c5f9b07c9df1c0905ef4ce042a220a2f"
#define Buttons_ConButton_ClassNameShort "%20d19189c5f9b07c9df1c0905ef4ce042a220a2f"
#define Buttons_ConButton_TypeDefinitionIndex 3009

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%5d77bd667e41a7f6a7f79ac3617d57d9c7088285
#define Buttons_Static_ClassName "%60fa9fa0b3b8f939208be68b00048afd50e24a83/%5d77bd667e41a7f6a7f79ac3617d57d9c7088285"
#define Buttons_Static_ClassNameShort "%5d77bd667e41a7f6a7f79ac3617d57d9c7088285"
#define Buttons_Static_TypeDefinitionIndex 3010

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0xa08;
		constexpr const static size_t Attack = 0x890;
		constexpr const static size_t Attack2 = 0x4f8;
		constexpr const static size_t Forward = 0xc18;
		constexpr const static size_t Backward = 0x678;
		constexpr const static size_t Right = 0xa98;
		constexpr const static size_t Left = 0xa8;
		constexpr const static size_t Sprint = 0x7a8;

		// Functions
		constexpr const static size_t Pets_setter = 0x4b350a0;
	}

#define PlayerModel_TypeDefinitionIndex 515

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x270;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 4324

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x58;
	}

#define BaseMountable_TypeDefinitionIndex 1440

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x284;
		constexpr const static size_t yawClamp = 0x28c;
		constexpr const static size_t canWieldItems = 0x294;
	}

#define ProgressBar_TypeDefinitionIndex 5890

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t timeCounter = 0x2c;
	}

#define BowWeapon_TypeDefinitionIndex 6881

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x400;
		constexpr const static size_t wasAiming = 0x410;
	}

#define CrossbowWeapon_TypeDefinitionIndex 3076

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 1997

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%51583cc51f69c3607002880c0ca9a9a450164d99
#define ConVar_Admin_Static_ClassName "%b74a0e56687a0da39a5d24e5d9929bc022bd64c3/%51583cc51f69c3607002880c0ca9a9a450164d99"
#define ConVar_Admin_Static_ClassNameShort "%51583cc51f69c3607002880c0ca9a9a450164d99"
#define ConVar_Admin_Static_TypeDefinitionIndex 7031

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x24;

		// Functions
		constexpr const static size_t admintime_getter = 0x4b11370;
		constexpr const static size_t admintime_setter = 0x4b44be0;
	}

	// obf name: ::%191b4e9849ad56476b3aeab570a482bf25303ef2
#define ConVar_Player_Static_ClassName "%4f8523991d885a3e16f559def6b469d99dbde304/%191b4e9849ad56476b3aeab570a482bf25303ef2"
#define ConVar_Player_Static_ClassNameShort "%191b4e9849ad56476b3aeab570a482bf25303ef2"
#define ConVar_Player_Static_TypeDefinitionIndex 6025

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x30;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x4b38040;
		constexpr const static size_t clientTickRate_setter = 0x4b37d20;
	}

#define ColliderInfo_TypeDefinitionIndex 813

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 3032

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x210;
		constexpr const static size_t HasAuth = 0x220;
		constexpr const static size_t HasGuestAuth = 0x221;
	}

#define AutoTurret_TypeDefinitionIndex 4170

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x330;
		constexpr const static size_t lastYaw = 0x3c0;
		constexpr const static size_t muzzlePos = 0x3e0;
		constexpr const static size_t gun_yaw = 0x3f8;
		constexpr const static size_t gun_pitch = 0x400;
		constexpr const static size_t sightRange = 0x408;

		// Functions
		constexpr const static size_t IsAuthed = 0x2e04790;
	}

#define Client_TypeDefinitionIndex 5699

	namespace Client {

		// Functions
		constexpr const static size_t OnNetworkMessage = 0x3fb84b0;
		constexpr const static size_t OnNetworkMessage_vtableoff = 0x1c8;
		constexpr const static size_t CreateOrUpdateEntity = 0x3fa0b00;
	}

#define BaseNetworkable_TypeDefinitionIndex 3450

	namespace BaseNetworkable {

		// Functions
		constexpr const static size_t Load = 0x24c5bc0;
		constexpr const static size_t Load_vtableoff = 0xa68;
	}

	// obf name: ::%ee72b1d9cce95bdfb75a1f7e18b8962955da01ec
#define ItemManager_Static_ClassName "%85e54a0d7fb11fefc678b2ea85db2cc75bfeca28/%ee72b1d9cce95bdfb75a1f7e18b8962955da01ec"
#define ItemManager_Static_ClassNameShort "%ee72b1d9cce95bdfb75a1f7e18b8962955da01ec"
#define ItemManager_Static_TypeDefinitionIndex 4015

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x20;
		constexpr const static size_t itemDictionary = 0x138;
		constexpr const static size_t itemDictionaryByName = 0x198;
	}

	// obf name: ::%253dd96499ee88c1d144dd8d82533d645d291592
#define ConVar_Server_Static_ClassName "%2ea6531cd1479a374bf2ec237d308c6e63660c35/%253dd96499ee88c1d144dd8d82533d645d291592"
#define ConVar_Server_Static_ClassNameShort "%253dd96499ee88c1d144dd8d82533d645d291592"
#define ConVar_Server_Static_TypeDefinitionIndex 1301

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 5052

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x37bd950;
	}

#define LoadingScreen_TypeDefinitionIndex 1728

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 850

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%30c0cf3a748f340ce1c27680121e2cfa839cfef9"
#define MapView_Static_ClassNameShort "%30c0cf3a748f340ce1c27680121e2cfa839cfef9"
#define MapView_TypeDefinitionIndex 5381

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x3b9cbd0;
	}

	// obf name: ::%f5b70af000017d88d9103bff3f3f8e0056f556e4
#define GamePhysics_ClassName "%f5b70af000017d88d9103bff3f3f8e0056f556e4"
#define GamePhysics_ClassNameShort "%f5b70af000017d88d9103bff3f3f8e0056f556e4"
#define GamePhysics_TypeDefinitionIndex 3177

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x2211cf0;
		constexpr const static size_t LineOfSightInternal = 0x2218180;
		constexpr const static size_t Verify = 0x2207930;
	}

#define DDraw_TypeDefinitionIndex 6841

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x4a69ac0;
		constexpr const static size_t Line = 0x4a627d0;
	}

	// obf name: ::%a9a3b6bc629a47be86034ee85171660c5951b900
#define RaycastHitEx_ClassName "%a9a3b6bc629a47be86034ee85171660c5951b900"
#define RaycastHitEx_ClassNameShort "%a9a3b6bc629a47be86034ee85171660c5951b900"
#define RaycastHitEx_TypeDefinitionIndex 5804

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x40c97d0;
	}

	// obf name: ::%7dfe409d0f83c68aa5d79381e1fd4fbb7186ddf8
#define OnParentDestroyingEx_ClassName "%7dfe409d0f83c68aa5d79381e1fd4fbb7186ddf8"
#define OnParentDestroyingEx_ClassNameShort "%7dfe409d0f83c68aa5d79381e1fd4fbb7186ddf8"
#define OnParentDestroyingEx_TypeDefinitionIndex 6286

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x44ec770;
	}

	// obf name: ::%f44412fd772847da5c034a1a7537843c298b0d60
#define ConsoleNetwork_ClassName "%f44412fd772847da5c034a1a7537843c298b0d60"
#define ConsoleNetwork_ClassNameShort "%f44412fd772847da5c034a1a7537843c298b0d60"
#define ConsoleNetwork_TypeDefinitionIndex 3919

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x2b7e440;
	}

#define ThrownWeapon_TypeDefinitionIndex 1747

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2d8;
	}

#define MapInterface_TypeDefinitionIndex 3901

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 5025

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 5381

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 2099

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2b0;
	}

#define PlayerCorpse_TypeDefinitionIndex 2130

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2e0;
	}

#define TimedExplosive_TypeDefinitionIndex 3846

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1ac;
	}

#define SmokeGrenade_TypeDefinitionIndex 6572

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x250;
	}

#define GrenadeWeapon_TypeDefinitionIndex 113

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f0;
	}

#define ViewmodelLower_TypeDefinitionIndex 1587

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%0cf5ac8dcb22144c25e40afaf9bc6dfb599ac82a
#define ConVar_Client_Static_ClassName "%6a21e67d77f82bf68f1ed893c482ad75a82f80a6/%0cf5ac8dcb22144c25e40afaf9bc6dfb599ac82a"
#define ConVar_Client_Static_ClassNameShort "%0cf5ac8dcb22144c25e40afaf9bc6dfb599ac82a"
#define ConVar_Client_Static_TypeDefinitionIndex 61

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0xec;
		constexpr const static size_t camspeed = 0x420;
	}

#define SamSite_TypeDefinitionIndex 6728

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3a0;
		constexpr const static size_t Flag_TargetMode = 0x3dc;
	}

#define ServerProjectile_TypeDefinitionIndex 199

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 3606

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 6952

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 2082

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 2049

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 3161

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 3757

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x124;
	}

	// obf name: ::%5b0254d3a7626868bc8529c15229ac755234e613
#define Facepunch_Network_Raknet_Client_ClassName "%5b0254d3a7626868bc8529c15229ac755234e613"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%5b0254d3a7626868bc8529c15229ac755234e613"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex -1

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x6540d20;
		constexpr const static size_t IsConnected_vtableoff = 0x1e8;
	}

	// obf name: ::%0c6fd38803d361bc231d888aa75651552ada4fb6
#define EncryptedValue_ClassName "%0c6fd38803d361bc231d888aa75651552ada4fb6<System/Int32>"
#define EncryptedValue_ClassNameShort "%0c6fd38803d361bc231d888aa75651552ada4fb6"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%763a4a985e8cc17e14af5e12a22d1bbffbb3ad5f
#define HiddenValue_ClassName "%763a4a985e8cc17e14af5e12a22d1bbffbb3ad5f<BaseNetworkable/%24df6edff5300de8c9e1ef397575acb183b52a4c>"
#define HiddenValue_ClassNameShort "%763a4a985e8cc17e14af5e12a22d1bbffbb3ad5f"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 5927

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x420ffb0;
	}

#define ItemModRFListener_TypeDefinitionIndex 698

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x4ea72d0;
	}

#define UIFogOverlay_TypeDefinitionIndex 3606

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x30;
	}

	// obf name: ::%9ab0d4f7d090aceeb68836c08dde4bb616e00e09
#define BufferStream_ClassName "%9ab0d4f7d090aceeb68836c08dde4bb616e00e09"
#define BufferStream_ClassNameShort "%9ab0d4f7d090aceeb68836c08dde4bb616e00e09"
#define BufferStream_TypeDefinitionIndex 7194

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x93c7820;
	}

#define FreeableLootContainer_TypeDefinitionIndex 5607

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 2660

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 1034

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x5193ba0;
	}

#define OutlineManager_TypeDefinitionIndex 3997

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%04ecd9583a8a76b910dfddcfa2fb32d648f84044
#define ProtoBuf_ProjectileShoot_ClassName "%04ecd9583a8a76b910dfddcfa2fb32d648f84044"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%04ecd9583a8a76b910dfddcfa2fb32d648f84044"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7152

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;
	}

	// obf name: ::%9a7d35d42422c92a0cab26b6dd9f9fb67bdfe66e
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%04ecd9583a8a76b910dfddcfa2fb32d648f84044/%9a7d35d42422c92a0cab26b6dd9f9fb67bdfe66e"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%9a7d35d42422c92a0cab26b6dd9f9fb67bdfe66e"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7151

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x34;
		constexpr const static size_t startPos = 0x18;
		constexpr const static size_t startVel = 0x24;
		constexpr const static size_t seed = 0x10;
	}

	// obf name: ::%8944864c2b58ac8f75f5312e6a8a1fc532eddcfe
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%8944864c2b58ac8f75f5312e6a8a1fc532eddcfe"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%8944864c2b58ac8f75f5312e6a8a1fc532eddcfe"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7105

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x18;
		constexpr const static size_t curPosition = 0x1c;
		constexpr const static size_t curVelocity = 0x2c;
		constexpr const static size_t travelTime = 0x10;
		constexpr const static size_t ShouldPool = 0x14;

		// Functions
		constexpr const static size_t Dispose = 0x8976b40;
	}

	// obf name: ::%9260addaec1eb8b7d0560381359096e3c2c30cfa
#define ProtoBuf_PlayerProjectileAttack_ClassName "%9260addaec1eb8b7d0560381359096e3c2c30cfa"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%9260addaec1eb8b7d0560381359096e3c2c30cfa"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7312

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x1c;
		constexpr const static size_t hitDistance = 0x10;
		constexpr const static size_t travelTime = 0x18;
		constexpr const static size_t playerAttack = 0x28;
	}

	// obf name: ::%6f375795cd885af8bd068bc1f763fa09ac5d3c6a
#define ProtoBuf_PlayerAttack_ClassName "%6f375795cd885af8bd068bc1f763fa09ac5d3c6a"
#define ProtoBuf_PlayerAttack_ClassNameShort "%6f375795cd885af8bd068bc1f763fa09ac5d3c6a"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7458

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%38d07f40ddf7e8a58ad11a28a2b52bfff0ef6d21
#define ProtoBuf_Attack_ClassName "%38d07f40ddf7e8a58ad11a28a2b52bfff0ef6d21"
#define ProtoBuf_Attack_ClassNameShort "%38d07f40ddf7e8a58ad11a28a2b52bfff0ef6d21"
#define ProtoBuf_Attack_TypeDefinitionIndex 7459

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x60;
		constexpr const static size_t pointEnd = 0x20;
		constexpr const static size_t hitID = 0x78;
		constexpr const static size_t hitBone = 0x84;
		constexpr const static size_t hitNormalLocal = 0x50;
		constexpr const static size_t hitPositionLocal = 0x38;
		constexpr const static size_t hitNormalWorld = 0x10;
		constexpr const static size_t hitPositionWorld = 0x6c;
		constexpr const static size_t hitPartID = 0x1c;
		constexpr const static size_t hitMaterialID = 0x80;
		constexpr const static size_t srcParentID = 0x30;
		constexpr const static size_t dstParentID = 0x48;
	}
}