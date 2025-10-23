#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68fa78ca;
		constexpr const static size_t gc_handles = 0xd34fb50;
		constexpr const static size_t il2cpp_resolve_icall = 0x5b5ad0;
		constexpr const static size_t il2cpp_array_new = 0x5b5af0;
		constexpr const static size_t il2cpp_assembly_get_image = 0x29ed0;
		constexpr const static size_t il2cpp_class_from_name = 0x5b5c60;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x5b5f70;
		constexpr const static size_t il2cpp_class_get_type = 0x5b6010;
		constexpr const static size_t il2cpp_domain_get = 0x5b6570;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x5b6590;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x5b6e50;
		constexpr const static size_t il2cpp_gchandle_new = 0x5b6e00;
		constexpr const static size_t il2cpp_gchandle_free = 0x5b6ef0;
		constexpr const static size_t il2cpp_method_get_name = 0x3be0;
		constexpr const static size_t il2cpp_object_new = 0x5b75a0;
		constexpr const static size_t il2cpp_type_get_object = 0x5b7d90;
	}

#define Object_TypeDefinitionIndex 16969

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xadd5d50;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16940

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

#define Component_TypeDefinitionIndex 16927

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16921

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 17004

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xade1800;
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

#define Camera_TypeDefinitionIndex 16719

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16991

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

#define Material_TypeDefinitionIndex 16782

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16778

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xad95990;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16781

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xad99200;
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16837

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

#define Renderer_TypeDefinitionIndex 16779

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16840

	namespace Texture {

		// Functions
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16842

	namespace Texture2D {

		// Functions
		constexpr const static size_t ctor = 0xadaf1f0;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define Sprite_TypeDefinitionIndex 17010

	namespace Sprite {

		// Functions
		constexpr const static size_t get_texture = 0x119300;
	}

#define RenderTexture_TypeDefinitionIndex 16847

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xadb7ed0;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17317

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xadfbd00;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17293

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xadf5bf0;
	}

#define ComputeBuffer_TypeDefinitionIndex 16982

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xadd9900;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xadd9b50;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16786

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xada02b0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xad9ffe0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 22073

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xae1e270;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16759

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16870

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24690

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16756

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24568

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

#define Application_TypeDefinitionIndex 16702

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16868

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23505

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xae63d10;
		constexpr const static size_t RaycastNonAlloc = 0xae663e0;
	}

#define Image_TypeDefinitionIndex 21131

	namespace Image {

		// Offsets
		constexpr const static size_t m_Sprite = 0xd0;
	}

#define BaseNetworkable_TypeDefinitionIndex 5811

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x78;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x28;
	}

	// obf name: ::%5945b83ad0705930f77126c1ca1d3aa183c8a4ba
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%5945b83ad0705930f77126c1ca1d3aa183c8a4ba"
#define BaseNetworkable_Static_ClassNameShort "%5945b83ad0705930f77126c1ca1d3aa183c8a4ba"
#define BaseNetworkable_Static_TypeDefinitionIndex 5810

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x28;
	}

	// obf name: ::%c5276a9185ef78de4d17eebf43657775f9ca3541
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%c5276a9185ef78de4d17eebf43657775f9ca3541"
#define BaseNetworkable_EntityRealm_ClassNameShort "%c5276a9185ef78de4d17eebf43657775f9ca3541"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 5808

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x3f12ee0;
	}

	// obf name: ::%7be3e44ce9143590be2ab118c9dc0f7884faf34d
#define System_ListDictionary_ClassName "%7be3e44ce9143590be2ab118c9dc0f7884faf34d<%9b74b74562b7ffaf4be66ed10eccddc147215de8,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%7be3e44ce9143590be2ab118c9dc0f7884faf34d"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x73dbb50;
		constexpr const static size_t TryGetValue_methodinfo = 0xd060238;
	}

	// obf name: ::%b997da34082d446acf1cfa5179b58014ead9c402
#define System_BufferList_ClassName "%b997da34082d446acf1cfa5179b58014ead9c402<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%b997da34082d446acf1cfa5179b58014ead9c402"
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

#define Model_TypeDefinitionIndex 2768

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t eyeBone = 0x38;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 3251

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0xe8;
		constexpr const static size_t positionLerp = 0x100;

		// Functions
		constexpr const static size_t ServerRPC = 0x1f9c8b0;
		constexpr const static size_t FindBone = 0x1f38e70;
		constexpr const static size_t GetWorldVelocity = 0x1f2fbe0;
		constexpr const static size_t GetParentVelocity = 0x1f384a0;
	}

	// obf name: ::%64b64a81622aff08811b5081501f8eb7233467bc
#define PositionLerp_ClassName "%64b64a81622aff08811b5081501f8eb7233467bc"
#define PositionLerp_ClassNameShort "%64b64a81622aff08811b5081501f8eb7233467bc"
#define PositionLerp_TypeDefinitionIndex 5521

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x28;
	}

	// obf name: ::%e9a7b25f808f7b2e5f8326a9718e3d94dafb3e6d
#define Interpolator_ClassName "%e9a7b25f808f7b2e5f8326a9718e3d94dafb3e6d<%7b1a2226ec09504d97dfe1b9c8829587a1444e49>"
#define Interpolator_ClassNameShort "%e9a7b25f808f7b2e5f8326a9718e3d94dafb3e6d"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 3892

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

#define SkeletonProperties_TypeDefinitionIndex 3931

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 3929

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 5661

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 5660

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%1acc63582f1145e9cb72eda42e275e8bc7575f3b
#define DamageTypeList_ClassName "%1acc63582f1145e9cb72eda42e275e8bc7575f3b"
#define DamageTypeList_ClassNameShort "%1acc63582f1145e9cb72eda42e275e8bc7575f3b"
#define DamageTypeList_TypeDefinitionIndex 3875

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 6952

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 5796

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
		constexpr const static size_t ItemModWearable = 0x150;
	}

#define RecoilProperties_TypeDefinitionIndex 3119

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 4608

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 3699

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x2637190;
		constexpr const static size_t StartAttackCooldown = 0x2637b10;
	}

#define BaseProjectile_TypeDefinitionIndex 4612

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
		constexpr const static size_t LaunchProjectile = 0x2fcd550;
		constexpr const static size_t LaunchProjectileClientSide = 0x2fe5e60;
		constexpr const static size_t ScaleRepeatDelay = 0x2ff5800;
		constexpr const static size_t GetAimCone = 0x2feb320;
		constexpr const static size_t GetAimCone_vtableoff = 0x3f88;
		constexpr const static size_t UpdateAmmoDisplay = 0x2fdba30;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3d88;
	}

#define BaseLauncher_TypeDefinitionIndex 868

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 5078

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%b452391567a47fdf01b2e4bc365b7734ae8248a3
#define HitTest_ClassName "%b452391567a47fdf01b2e4bc365b7734ae8248a3"
#define HitTest_ClassNameShort "%b452391567a47fdf01b2e4bc365b7734ae8248a3"
#define HitTest_TypeDefinitionIndex 982

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0xa8;
		constexpr const static size_t AttackRay = 0x50;
		constexpr const static size_t RayHit = 0x6c;
		constexpr const static size_t damageProperties = 0x20;
		constexpr const static size_t gameObject = 0xc8;
		constexpr const static size_t collider = 0xb0;
		constexpr const static size_t ignoredTypes = 0x30;
		constexpr const static size_t HitTransform = 0x38;
		constexpr const static size_t HitPart = 0x40;
		constexpr const static size_t HitMaterial = 0xd8;
		constexpr const static size_t DidHit = 0x68;
		constexpr const static size_t MaxDistance = 0x1c;
		constexpr const static size_t HitNormal = 0x9c;
		constexpr const static size_t HitPoint = 0xb8;
		constexpr const static size_t ignoreEntity = 0x10;
		constexpr const static size_t HitEntity = 0x48;
	}

#define Projectile_TypeDefinitionIndex 7124

	namespace Projectile {

		// Offsets
		constexpr const static size_t initialVelocity = 0x28;
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t thickness = 0x3c;
		constexpr const static size_t initialDistance = 0x44;
		constexpr const static size_t swimScale = 0xf0;
		constexpr const static size_t swimSpeed = 0xfc;
		constexpr const static size_t owner = 0x1e0;
		constexpr const static size_t sourceProjectilePrefab = 0x1d0;
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
		constexpr const static size_t CalculateEffectScale = 0x4c3bb50;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x2a8;
		constexpr const static size_t SetEffectScale = 0x4c4c620;
		constexpr const static size_t UpdateVelocity = 0x4c1a400;
		constexpr const static size_t Retire = 0x4c16aa0;
		constexpr const static size_t DoHit = 0x4c4b1b0;
	}

	// obf name: ::%e87e37850c2930ccc811018d5d069da412a2af76
#define HitInfo_ClassName "%e87e37850c2930ccc811018d5d069da412a2af76"
#define HitInfo_ClassNameShort "%e87e37850c2930ccc811018d5d069da412a2af76"
#define HitInfo_TypeDefinitionIndex 3081

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x18;
		constexpr const static size_t damageTypes = 0x50;

		// Functions
		constexpr const static size_t get_boneArea = 0x1dc39b0;
	}

	// obf name: ::%66a280ba26b6774432ad634e54b816bf0e868706
#define GameTrace_ClassName "%66a280ba26b6774432ad634e54b816bf0e868706"
#define GameTrace_ClassNameShort "%66a280ba26b6774432ad634e54b816bf0e868706"
#define GameTrace_TypeDefinitionIndex 6283

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x431ff00;
	}

#define BaseMelee_TypeDefinitionIndex 5685

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x3d8c8b0;
		constexpr const static size_t DoThrow = 0x3d8f5c0;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 5291

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x408;
		constexpr const static size_t strikeRecoil = 0x410;
		constexpr const static size_t _didSparkThisFrame = 0x418;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 6024

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x420;
		constexpr const static size_t stringBonusVelocity = 0x42c;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x40d3f60;
	}

	// obf name: ::%a6b83e56e4a42189a89809c4673f6bc1235722b5
#define ItemContainer_ClassName "%a6b83e56e4a42189a89809c4673f6bc1235722b5"
#define ItemContainer_ClassNameShort "%a6b83e56e4a42189a89809c4673f6bc1235722b5"
#define ItemContainer_TypeDefinitionIndex 4267

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x40;
		constexpr const static size_t itemList = 0x28;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x2c431d0;
	}

#define PlayerLoot_TypeDefinitionIndex 2175

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 2927

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerWear = 0x28;
		constexpr const static size_t containerMain = 0x30;
		constexpr const static size_t containerBelt = 0x60;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x1c53e70;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 2850

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x1b56410;
		constexpr const static size_t get_rotation = 0x1b4b660;
		constexpr const static size_t set_rotation = 0x1b57060;
		constexpr const static size_t HeadForward = 0x1b49740;
	}

	// obf name: ::%45d06ea7ecd15480c6752858632984833ae779c8
#define PlayerEyes_Static_ClassName "PlayerEyes/%45d06ea7ecd15480c6752858632984833ae779c8"
#define PlayerEyes_Static_ClassNameShort "%45d06ea7ecd15480c6752858632984833ae779c8"
#define PlayerEyes_Static_TypeDefinitionIndex 2849

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x70;
	}

	// obf name: ::%17816896d4be908ce03b0df77e69772a6a302492
#define PlayerBelt_ClassName "%17816896d4be908ce03b0df77e69772a6a302492"
#define PlayerBelt_ClassNameShort "%17816896d4be908ce03b0df77e69772a6a302492"
#define PlayerBelt_TypeDefinitionIndex 2608

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x19465c0;
		constexpr const static size_t GetActiveItem = 0x193cc10;
	}

	// obf name: ::%0e2940049f3492b599384492222c2dc56987ff51
#define LocalPlayer_ClassName "%0e2940049f3492b599384492222c2dc56987ff51"
#define LocalPlayer_ClassNameShort "%0e2940049f3492b599384492222c2dc56987ff51"
#define LocalPlayer_TypeDefinitionIndex 3383

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x214a4d0;
		constexpr const static size_t MoveItem = 0x2142240;
		constexpr const static size_t get_Entity = 0x213d630;
	}

	// obf name: ::%2f1d7c7242ec85bb17f3251f85e8a19004d43a57
#define LocalPlayer_Static_ClassName "%0e2940049f3492b599384492222c2dc56987ff51/%2f1d7c7242ec85bb17f3251f85e8a19004d43a57"
#define LocalPlayer_Static_ClassNameShort "%2f1d7c7242ec85bb17f3251f85e8a19004d43a57"
#define LocalPlayer_Static_TypeDefinitionIndex 3382

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x190;
	}

	// obf name: ::%a2e6a8ba75b2e2e3e8158ca16b81e98c3171d2d6
#define BasePlayer_Static_ClassName "BasePlayer/%a2e6a8ba75b2e2e3e8158ca16b81e98c3171d2d6"
#define BasePlayer_Static_ClassNameShort "%a2e6a8ba75b2e2e3e8158ca16b81e98c3171d2d6"
#define BasePlayer_Static_TypeDefinitionIndex 4904

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x9e0;
	}

#define BasePlayer_TypeDefinitionIndex 4905

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x5c8;
		constexpr const static size_t input = 0x5f0;
		constexpr const static size_t movement = 0x4b0;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x318;
		constexpr const static size_t playerFlags = 0x598;
		constexpr const static size_t eyes = 0x400;
		constexpr const static size_t playerRigidbody = 0x2a8;
		constexpr const static size_t userID = 0x5e0;
		constexpr const static size_t UserIDString = 0x568;
		constexpr const static size_t inventory = 0x288;
		constexpr const static size_t _displayName = 0x418;
		constexpr const static size_t _lookingAt = 0x280;
		constexpr const static size_t lastSentTickTime = 0x554;
		constexpr const static size_t lastSentTick = 0x2d0;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x308;
		constexpr const static size_t _lookingAtEntity = 0x3c0;
		constexpr const static size_t currentGesture = 0x428;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x3379c90;
		constexpr const static size_t Menu_AssistPlayer = 0x33e1760;
		constexpr const static size_t OnViewModeChanged = 0x32b1f50;
		constexpr const static size_t ChatMessage = 0x33630d0;
		constexpr const static size_t IsOnGround = 0x32963e0;
		constexpr const static size_t GetSpeed = 0x33dbc40;
		constexpr const static size_t SendProjectileUpdate = 0x33c4070;
		constexpr const static size_t SendProjectileAttack = 0x33c69d0;
		constexpr const static size_t CanBuild = 0x33f7120;
		constexpr const static size_t GetMounted = 0x33b8e80;
		constexpr const static size_t GetHeldEntity = 0x32fe890;
		constexpr const static size_t get_inventory = 0x333bb10;
		constexpr const static size_t get_eyes = 0x33d8b50;
		constexpr const static size_t SendClientTick = 0x33f1360;
		constexpr const static size_t ClientInput = 0x328f180;
		constexpr const static size_t ClientInput_vtableoff = 0x37f8;
		constexpr const static size_t MaxHealth = 0x33c6d60;
		constexpr const static size_t MaxHealth_vtableoff = 0x20b8;
		constexpr const static size_t OnAttacked = 0x3376570;
		constexpr const static size_t OnAttacked_vtableoff = 0x1d48;
		constexpr const static size_t get_idealViewMode = 0x33f8200;
	}

#define ScientistNPC_TypeDefinitionIndex 5955

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 1288

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 6510

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 2877

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 6798

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 6239

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 1441

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xd8;
		constexpr const static size_t ladder = 0xe8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0xc97280;
		constexpr const static size_t BlockSprint = 0xc81d80;
		constexpr const static size_t GroundCheck = 0xc5a9e0;
		constexpr const static size_t ClientInput = 0xc60770;
		constexpr const static size_t ClientInput_vtableoff = 0x278;
		constexpr const static size_t DoFixedUpdate = 0xc85130;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x318;
		constexpr const static size_t FrameUpdate = 0xc6e5f0;
		constexpr const static size_t FrameUpdate_vtableoff = 0x438;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 3290

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 5598

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 7114

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 2160

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 2156

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%400afccf86fa711bf4e286fbcdc7043c88ac84ac
#define ConsoleSystem_ClassName "%400afccf86fa711bf4e286fbcdc7043c88ac84ac"
#define ConsoleSystem_ClassNameShort "%400afccf86fa711bf4e286fbcdc7043c88ac84ac"
#define ConsoleSystem_TypeDefinitionIndex 23572

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x6293140;
	}

	// obf name: ::%1714997812b1e3c291a631f86ca2f514386830f5
#define ConsoleSystem_Index_Static_ClassName "%400afccf86fa711bf4e286fbcdc7043c88ac84ac/%006d2ce8d72e801809a31e606e01e858be431ce0.%1714997812b1e3c291a631f86ca2f514386830f5"
#define ConsoleSystem_Index_Static_ClassNameShort "%1714997812b1e3c291a631f86ca2f514386830f5"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23565

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0xc8;
	}

#define LootableCorpse_TypeDefinitionIndex 4152

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2a8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 3739

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 4044

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x40;
		constexpr const static size_t mainCameraTransform = 0xd0;

		// Functions
		constexpr const static size_t Update = 0x297ce00;
		constexpr const static size_t OnPreCull = 0x297e620;
		constexpr const static size_t Trace = 0x297fd90;
	}

#define CameraMan_TypeDefinitionIndex 3658

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%ca7f513eca25d679c74f8e7476b7689d69cc34e2
#define PlayerTick_ClassName "%ca7f513eca25d679c74f8e7476b7689d69cc34e2"
#define PlayerTick_ClassNameShort "%ca7f513eca25d679c74f8e7476b7689d69cc34e2"
#define PlayerTick_TypeDefinitionIndex 7263

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x18;
		constexpr const static size_t modelState = 0x50;
		constexpr const static size_t activeItem = 0x60;
		constexpr const static size_t parentID = 0x30;
		constexpr const static size_t intermediatePosition = 0x44;
		constexpr const static size_t position = 0x38;
		constexpr const static size_t eyePos = 0x24;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x926e4c0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x926a5f0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%f17041669b93625b3bedaacef3f3f52e67ef7c00
#define InputMessage_ClassName "%f17041669b93625b3bedaacef3f3f52e67ef7c00"
#define InputMessage_ClassNameShort "%f17041669b93625b3bedaacef3f3f52e67ef7c00"
#define InputMessage_TypeDefinitionIndex 7587

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x2c;
		constexpr const static size_t mouseDelta = 0x10;
		constexpr const static size_t aimAngles = 0x20;
	}

	// obf name: ::%00c8bfd9bcef94f117d8c7a9771ccb6d0eedb045
#define InputState_ClassName "%00c8bfd9bcef94f117d8c7a9771ccb6d0eedb045"
#define InputState_ClassNameShort "%00c8bfd9bcef94f117d8c7a9771ccb6d0eedb045"
#define InputState_TypeDefinitionIndex 32

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x18;
	}

#define PlayerInput_TypeDefinitionIndex 2343

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%4a4cabc4eaa94e61fc80e9201af00b248e159377
#define ModelState_ClassName "%4a4cabc4eaa94e61fc80e9201af00b248e159377"
#define ModelState_ClassNameShort "%4a4cabc4eaa94e61fc80e9201af00b248e159377"
#define ModelState_TypeDefinitionIndex 7545

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x1c;
		constexpr const static size_t waterLevel = 0x70;
		constexpr const static size_t lookDir = 0x4c;
	}

	// obf name: ::%f41437215eaafa14858ca037e4450e8fd1a822db
#define Item_ClassName "%f41437215eaafa14858ca037e4450e8fd1a822db"
#define Item_ClassNameShort "%f41437215eaafa14858ca037e4450e8fd1a822db"
#define Item_TypeDefinitionIndex 6902

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0xd8;
		constexpr const static size_t uid = 0x78;
		constexpr const static size_t _condition = 0x18;
		constexpr const static size_t _maxCondition = 0xc0;
		constexpr const static size_t position = 0x44;
		constexpr const static size_t amount = 0xa8;
		constexpr const static size_t contents = 0x20;
		constexpr const static size_t parent = 0x68;
		constexpr const static size_t heldEntity = 0x28;
		constexpr const static size_t worldEnt = 0xb0;

		// Functions
		constexpr const static size_t get_iconSprite = 0x4994140;
	}

	// obf name: ::%fbda1a03b0c9f4df34ee1ada5ac21b115cf058bb
#define WaterLevel_ClassName "%fbda1a03b0c9f4df34ee1ada5ac21b115cf058bb"
#define WaterLevel_ClassNameShort "%fbda1a03b0c9f4df34ee1ada5ac21b115cf058bb"
#define WaterLevel_TypeDefinitionIndex 525

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x364bb40;
		constexpr const static size_t GetWaterLevel = 0x3673d60;
	}

	// obf name: ::%b2fbc83bf41b63f44e2d47bf2304da808792878d
#define ConVar_Graphics_Static_ClassName "%64a6079de1baa89c3e84ac09e182c383ea16af26/%b2fbc83bf41b63f44e2d47bf2304da808792878d"
#define ConVar_Graphics_Static_ClassNameShort "%b2fbc83bf41b63f44e2d47bf2304da808792878d"
#define ConVar_Graphics_Static_TypeDefinitionIndex 725

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x308;

		// Functions
		constexpr const static size_t _fov_getter = 0x22cefe0;
		constexpr const static size_t _fov_setter = 0x22c1bc0;
	}

#define BaseFishingRod_TypeDefinitionIndex 3190

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
		constexpr const static size_t UpdateLineRenderer = 0x1e8b140;
		constexpr const static size_t EvaluateFishingPosition = 0x1e9a180;
	}

#define FishingBobber_TypeDefinitionIndex 4224

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 5445

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x3a600a0;
	}

	// obf name: ::%69ae19f306532c95bd1c34f9e9a02233194a2b35
#define GameManager_ClassName "%69ae19f306532c95bd1c34f9e9a02233194a2b35"
#define GameManager_ClassNameShort "%69ae19f306532c95bd1c34f9e9a02233194a2b35"
#define GameManager_TypeDefinitionIndex 6349

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x10;

		// Functions
		constexpr const static size_t CreatePrefab = 0x43ebec0;
	}

	// obf name: ::%280bd345ff3cc0fd44bb974bb069506c150c5343
#define GameManager_Static_ClassName "%69ae19f306532c95bd1c34f9e9a02233194a2b35/%280bd345ff3cc0fd44bb974bb069506c150c5343"
#define GameManager_Static_ClassNameShort "%280bd345ff3cc0fd44bb974bb069506c150c5343"
#define GameManager_Static_TypeDefinitionIndex 6348

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x18;
	}

	// obf name: ::%c1fb43219f8bd9d1bf70b167482c112ebfe35d37
#define PrefabPoolCollection_ClassName "%c1fb43219f8bd9d1bf70b167482c112ebfe35d37"
#define PrefabPoolCollection_ClassNameShort "%c1fb43219f8bd9d1bf70b167482c112ebfe35d37"
#define PrefabPoolCollection_TypeDefinitionIndex 3284

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x18;
	}

	// obf name: ::%014e4120cd067c58faa525fd0f7cdbbc4d5a1c55
#define PrefabPool_ClassName "%014e4120cd067c58faa525fd0f7cdbbc4d5a1c55"
#define PrefabPool_ClassNameShort "%014e4120cd067c58faa525fd0f7cdbbc4d5a1c55"
#define PrefabPool_TypeDefinitionIndex 2310

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x20;
	}

#define ItemModProjectile_TypeDefinitionIndex 2389

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

#define CraftingQueue_TypeDefinitionIndex 2580

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%98bba726d2f390213a0ec86d41fc81effa70b3f6
#define CraftingQueue_Static_ClassName "CraftingQueue/%98bba726d2f390213a0ec86d41fc81effa70b3f6"
#define CraftingQueue_Static_ClassNameShort "%98bba726d2f390213a0ec86d41fc81effa70b3f6"
#define CraftingQueue_Static_TypeDefinitionIndex 2579

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x33;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 5872

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%e9755f3d95c62a05e49552e0d0fd6842ee257ae8
#define Planner_Static_ClassName "Planner/%e9755f3d95c62a05e49552e0d0fd6842ee257ae8"
#define Planner_Static_ClassNameShort "%e9755f3d95c62a05e49552e0d0fd6842ee257ae8"
#define Planner_Static_TypeDefinitionIndex 393

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x160;
	}

	// obf name: ::%6c541e889a03158c77281d752d6a22e320e3c345
#define Planner_Guide_ClassName "Planner/%6c541e889a03158c77281d752d6a22e320e3c345"
#define Planner_Guide_ClassNameShort "%6c541e889a03158c77281d752d6a22e320e3c345"
#define Planner_Guide_TypeDefinitionIndex 389

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x38;
	}

#define Planner_TypeDefinitionIndex 394

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x268;
	}

#define Construction_TypeDefinitionIndex 2615

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x148;
	}

#define BuildingBlock_TypeDefinitionIndex 1412

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x300;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 2247

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x157f620;
	}

	// obf name: ::%5122898cb24bebc61b7fda19abf3dd74d8157ca2
#define PunchEntry_ClassName "HeldEntity/%5122898cb24bebc61b7fda19abf3dd74d8157ca2"
#define PunchEntry_ClassNameShort "%5122898cb24bebc61b7fda19abf3dd74d8157ca2"
#define PunchEntry_TypeDefinitionIndex 2245

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x10;
		constexpr const static size_t duration = 0x2c;
		constexpr const static size_t amount = 0x14;
		constexpr const static size_t amountAdded = 0x20;
	}

#define IronSights_TypeDefinitionIndex 3686

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 6063

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 4434

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xb8;
		constexpr const static size_t model = 0x98;
		constexpr const static size_t lower = 0xa8;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x2e4fcb0;
	}

#define ViewModel_TypeDefinitionIndex 6425

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x44a76a0;
		constexpr const static size_t PlayString = 0x44a51a0;
	}

#define MedicalTool_TypeDefinitionIndex 2581

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 6415

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x68;
	}

	// obf name: ::%f5134b48b376f6a4706bf59eb0e1a607d0c0e74e
#define WaterSystem_Static_ClassName "WaterSystem/%f5134b48b376f6a4706bf59eb0e1a607d0c0e74e"
#define WaterSystem_Static_ClassNameShort "%f5134b48b376f6a4706bf59eb0e1a607d0c0e74e"
#define WaterSystem_Static_TypeDefinitionIndex 1952

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x198;
	}

#define WaterSystem_TypeDefinitionIndex 1953

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x11ed1c0;
	}

#define TerrainMeta_TypeDefinitionIndex 6570

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x508;
		constexpr const static size_t HeightMap = 0x3f8;
		constexpr const static size_t SplatMap = 0x478;
		constexpr const static size_t TopologyMap = 0x788;
		constexpr const static size_t Texturing = 0x480;
	}

#define TerrainCollision_TypeDefinitionIndex 5920

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x3ffed90;
	}

#define TerrainHeightMap_TypeDefinitionIndex 3160

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 781

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 5250

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%94a49f666b260a94c14408ae82fc0665124341d2
#define World_Static_ClassName "%9c5b617464be7af41d1a43d3e90c1b222331444f/%94a49f666b260a94c14408ae82fc0665124341d2"
#define World_Static_ClassNameShort "%94a49f666b260a94c14408ae82fc0665124341d2"
#define World_Static_TypeDefinitionIndex 3573

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x3c;
	}

#define ItemIcon_TypeDefinitionIndex 4354

	namespace ItemIcon {

		// Offsets
		constexpr const static size_t backgroundImage = 0xe8;

		// Functions
		constexpr const static size_t TryToMove = 0x2d2f8d0;
		constexpr const static size_t TryToMove_vtableoff = 0x3a8;
		constexpr const static size_t RunTimedAction = 0x2d48c20;
	}

	// obf name: ::%bc2331c4db59f8f26f5c16e08626d9dc15665592
#define ItemIcon_Static_ClassName "ItemIcon/%bc2331c4db59f8f26f5c16e08626d9dc15665592"
#define ItemIcon_Static_ClassNameShort "%bc2331c4db59f8f26f5c16e08626d9dc15665592"
#define ItemIcon_Static_TypeDefinitionIndex 4353

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x8;
	}

	// obf name: ::%65d3a6390635eb09e9c2239ea120d6ed2c8daee4
#define Effect_ClassName "%65d3a6390635eb09e9c2239ea120d6ed2c8daee4"
#define Effect_ClassNameShort "%65d3a6390635eb09e9c2239ea120d6ed2c8daee4"
#define Effect_TypeDefinitionIndex 1843

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0xa0;
		constexpr const static size_t worldPos = 0x88;
	}

	// obf name: ::%e47ed019d5df9c9fefa85fe12ec6d5388621baf3
#define EffectLibrary_ClassName "%e47ed019d5df9c9fefa85fe12ec6d5388621baf3"
#define EffectLibrary_ClassNameShort "%e47ed019d5df9c9fefa85fe12ec6d5388621baf3"
#define EffectLibrary_TypeDefinitionIndex 2049

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x135fa10;
	}

	// obf name: ::%e6faeed71d4ee0a39e3ea899c574085def1546e5
#define EffectNetwork_ClassName "%e6faeed71d4ee0a39e3ea899c574085def1546e5"
#define EffectNetwork_ClassNameShort "%e6faeed71d4ee0a39e3ea899c574085def1546e5"
#define EffectNetwork_TypeDefinitionIndex 659

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%44a0d3239049fcd46d8b2a05ad8c6b398bda2994
#define EffectNetwork_Static_ClassName "%e6faeed71d4ee0a39e3ea899c574085def1546e5/%44a0d3239049fcd46d8b2a05ad8c6b398bda2994"
#define EffectNetwork_Static_ClassNameShort "%44a0d3239049fcd46d8b2a05ad8c6b398bda2994"
#define EffectNetwork_Static_TypeDefinitionIndex 658

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x20;

		// Functions
		constexpr const static size_t cctor = 0x4bf6240;
	}

#define BuildingBlock_TypeDefinitionIndex 1412

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0xbe9710;
		constexpr const static size_t HasUpgradePrivilege = 0xbcb050;
		constexpr const static size_t CanAffordUpgrade = 0xbf1dc0;
	}

	// obf name: ::%93f1dc2751bfd03735e0bacfdc8055b9b8216eb0
#define GameObjectEx_ClassName "%93f1dc2751bfd03735e0bacfdc8055b9b8216eb0"
#define GameObjectEx_ClassNameShort "%93f1dc2751bfd03735e0bacfdc8055b9b8216eb0"
#define GameObjectEx_TypeDefinitionIndex 6864

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x493ee30;
	}

#define UIDeathScreen_TypeDefinitionIndex 5204

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x37d9fa0;
	}

	// obf name: ::%606779a66d35f3a98160f7f5e1b81d32d37ef0a2
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%606779a66d35f3a98160f7f5e1b81d32d37ef0a2"
#define BaseScreenShake_Static_ClassNameShort "%606779a66d35f3a98160f7f5e1b81d32d37ef0a2"
#define BaseScreenShake_Static_TypeDefinitionIndex 1311

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0xa0;
	}

#define FlashbangOverlay_TypeDefinitionIndex 5604

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%22a497480b6eafdaaa75b33c1443b9d526571b3f
#define StringPool_ClassName "%22a497480b6eafdaaa75b33c1443b9d526571b3f"
#define StringPool_ClassNameShort "%22a497480b6eafdaaa75b33c1443b9d526571b3f"
#define StringPool_TypeDefinitionIndex 4997

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x80;

		// Functions
		constexpr const static size_t Get = 0x35c01d0;
	}

	// obf name: ::%7f49119f0c3a42b68a870c349f02a41540ef389c
#define Network_Networkable_ClassName "%7f49119f0c3a42b68a870c349f02a41540ef389c"
#define Network_Networkable_ClassNameShort "%7f49119f0c3a42b68a870c349f02a41540ef389c"
#define Network_Networkable_TypeDefinitionIndex 19386

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x18;
	}

	// obf name: ::%cbd6e3e9d2dd9bd536bcb8274546b8ecf2385bd0
#define Network_Net_ClassName "%cbd6e3e9d2dd9bd536bcb8274546b8ecf2385bd0"
#define Network_Net_ClassNameShort "%cbd6e3e9d2dd9bd536bcb8274546b8ecf2385bd0"
#define Network_Net_TypeDefinitionIndex 8306

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x38;
	}

	// obf name: ::%f9bb90fa9eb1a48cffe1a8201edd7ee99eb43550
#define Network_Client_ClassName "%f9bb90fa9eb1a48cffe1a8201edd7ee99eb43550"
#define Network_Client_ClassNameShort "%f9bb90fa9eb1a48cffe1a8201edd7ee99eb43550"
#define Network_Client_TypeDefinitionIndex 19341

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf8;
		constexpr const static size_t ConnectedPort = 0x118;
		constexpr const static size_t ConnectedAddress = 0xf0;
		constexpr const static size_t ServerName = 0x100;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x6328880;
		constexpr const static size_t DestroyNetworkable = 0x6328650;
	}

	// obf name: ::%0ca75a3cd4ccebccdbf485120559c457df708f43
#define Network_BaseNetwork_ClassName "%0ca75a3cd4ccebccdbf485120559c457df708f43"
#define Network_BaseNetwork_ClassNameShort "%0ca75a3cd4ccebccdbf485120559c457df708f43"
#define Network_BaseNetwork_TypeDefinitionIndex 19323

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x630c810;
	}

	// obf name: ::%8ae41d358a5ccd67c43c8533155734346a42450d
#define Network_SendInfo_ClassName "%8ae41d358a5ccd67c43c8533155734346a42450d"
#define Network_SendInfo_ClassNameShort "%8ae41d358a5ccd67c43c8533155734346a42450d"
#define Network_SendInfo_TypeDefinitionIndex 19320

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%f5ecb3c208ec3e73bbdf2e0939c61c3d8ae69cc5
#define Network_Message_ClassName "%f5ecb3c208ec3e73bbdf2e0939c61c3d8ae69cc5"
#define Network_Message_ClassNameShort "%f5ecb3c208ec3e73bbdf2e0939c61c3d8ae69cc5"
#define Network_Message_TypeDefinitionIndex 19371

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x18;
		constexpr const static size_t read = 0x10;
	}

	// obf name: ::%0397e1ab942a786572a11878f966468cb66bda09
#define Network_NetRead_ClassName "%0397e1ab942a786572a11878f966468cb66bda09"
#define Network_NetRead_ClassNameShort "%0397e1ab942a786572a11878f966468cb66bda09"
#define Network_NetRead_TypeDefinitionIndex 19325

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x38;
	}

	// obf name: ::%7d91e17148606f0f19c05d2c16cf771201ca9a8a
#define Network_NetWrite_ClassName "%7d91e17148606f0f19c05d2c16cf771201ca9a8a"
#define Network_NetWrite_ClassNameShort "%7d91e17148606f0f19c05d2c16cf771201ca9a8a"
#define Network_NetWrite_TypeDefinitionIndex 19382

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x28;

		// Functions
		constexpr const static size_t WriteByte = 0x635baa0;
		constexpr const static size_t String = 0x635a620;
		constexpr const static size_t Send = 0x635d180;
	}

#define LootPanel_TypeDefinitionIndex 1905

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x11992e0;
	}

#define UIInventory_TypeDefinitionIndex 3728

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x268cd50;
	}

#define GrowableEntity_TypeDefinitionIndex 6311

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 4926

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 4925

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 21202

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 8492

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
		constexpr const static size_t get_Instance = 0x7af810;
	}

	// obf name: ::%6e13fe05a97559be7ab3e31e242324f75baece38
#define TOD_Sky_Static_ClassName "TOD_Sky/%6e13fe05a97559be7ab3e31e242324f75baece38"
#define TOD_Sky_Static_ClassNameShort "%6e13fe05a97559be7ab3e31e242324f75baece38"
#define TOD_Sky_Static_TypeDefinitionIndex 8491

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x48;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 8285

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0x70aea0;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9152

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 8425

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 8907

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 9248

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 8582

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8480

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 6853

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 5967

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 1070

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 2388

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

#define EnvironmentManager_TypeDefinitionIndex 5034

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x3676ab0;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%b9b8384d71cc6cfc390bccbb9ee61425a28dddd3/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24315

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 2893

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 2894

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 5949

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

	// obf name: ::%585d15bfb223b4603a24d6cc45b07e0888943157
#define ListHashSet_ClassName "%585d15bfb223b4603a24d6cc45b07e0888943157<UIChat>"
#define ListHashSet_ClassNameShort "%585d15bfb223b4603a24d6cc45b07e0888943157"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 2028

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3f0;
	}

#define Chainsaw_TypeDefinitionIndex 2369

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x38c;
	}

	// obf name: ::%85ccddc2693a902efd1098830b41d4474387dac0
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%85ccddc2693a902efd1098830b41d4474387dac0"
#define CameraUpdateHook_Static_ClassNameShort "%85ccddc2693a902efd1098830b41d4474387dac0"
#define CameraUpdateHook_Static_TypeDefinitionIndex 3550

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x8;
	}

#define SteamClientWrapper_TypeDefinitionIndex 1846

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x1110cd0;
	}

	// obf name: ::%a220079b9635ef9c117e145dc52f243e4e1b0056
#define AimConeUtil_ClassName "%a220079b9635ef9c117e145dc52f243e4e1b0056"
#define AimConeUtil_ClassNameShort "%a220079b9635ef9c117e145dc52f243e4e1b0056"
#define AimConeUtil_TypeDefinitionIndex 3144

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x1e55230;
	}

	// obf name: ::%d0fc3c47fbb7e7b99d2426e62fb8eb603f1c3c64
#define Buttons_ConButton_ClassName "%8035a51ab765cfb8edd27b66e9298c191b134b46/%d0fc3c47fbb7e7b99d2426e62fb8eb603f1c3c64"
#define Buttons_ConButton_ClassNameShort "%d0fc3c47fbb7e7b99d2426e62fb8eb603f1c3c64"
#define Buttons_ConButton_TypeDefinitionIndex 2705

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%1f7b94f6bf5c9cf6bd6d42a425a34ad81a3fab45
#define Buttons_Static_ClassName "%8035a51ab765cfb8edd27b66e9298c191b134b46/%1f7b94f6bf5c9cf6bd6d42a425a34ad81a3fab45"
#define Buttons_Static_ClassNameShort "%1f7b94f6bf5c9cf6bd6d42a425a34ad81a3fab45"
#define Buttons_Static_TypeDefinitionIndex 2706

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x568;
		constexpr const static size_t Attack = 0x6a0;
		constexpr const static size_t Attack2 = 0x7a8;
		constexpr const static size_t Forward = 0x7e8;
		constexpr const static size_t Backward = 0xf28;
		constexpr const static size_t Right = 0xfe0;
		constexpr const static size_t Left = 0x398;
		constexpr const static size_t Sprint = 0x5d0;
		constexpr const static size_t Use = 0x7e0;

		// Functions
		constexpr const static size_t Pets_setter = 0x22e41e0;
	}

#define PlayerModel_TypeDefinitionIndex 6645

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x2d0;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 6485

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x40;
	}

#define BaseMountable_TypeDefinitionIndex 4222

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 5776

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x30;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 4676

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x408;
		constexpr const static size_t wasAiming = 0x418;
	}

#define CrossbowWeapon_TypeDefinitionIndex 685

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 1271

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%9997c86308b5d5c98f97163c41855ce0911d30bf
#define ConVar_Admin_Static_ClassName "%4edaaed9cdb746b3a2b965d36de9e175740cf637/%9997c86308b5d5c98f97163c41855ce0911d30bf"
#define ConVar_Admin_Static_ClassNameShort "%9997c86308b5d5c98f97163c41855ce0911d30bf"
#define ConVar_Admin_Static_TypeDefinitionIndex 4856

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0x38;

		// Functions
		constexpr const static size_t admintime_getter = 0x229e460;
		constexpr const static size_t admintime_setter = 0x22bcc20;
	}

	// obf name: ::%0174fe70ab3c9d64a4e02840f2fce42027b27d47
#define ConVar_Player_Static_ClassName "%9ccc7043c9a32dd4a03c9e561f437ae0c7de6d6d/%0174fe70ab3c9d64a4e02840f2fce42027b27d47"
#define ConVar_Player_Static_ClassNameShort "%0174fe70ab3c9d64a4e02840f2fce42027b27d47"
#define ConVar_Player_Static_TypeDefinitionIndex 4054

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0xbc;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x22cf8b0;
		constexpr const static size_t clientTickRate_setter = 0x22ae6d0;
	}

#define ColliderInfo_TypeDefinitionIndex 5867

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 3848

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 5254

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x3b8;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x3864080;
	}

#define Client_TypeDefinitionIndex 1471

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0xd41270;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%9d76e3220b6064260088ea8d804e7556fab618f8
#define ItemManager_Static_ClassName "%4dbe244b6f84f895601ccceae6c56fa6c2af1d18/%9d76e3220b6064260088ea8d804e7556fab618f8"
#define ItemManager_Static_ClassNameShort "%9d76e3220b6064260088ea8d804e7556fab618f8"
#define ItemManager_Static_TypeDefinitionIndex 4382

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x1b0;
		constexpr const static size_t itemDictionary = 0x198;
		constexpr const static size_t itemDictionaryByName = 0x1a8;
	}

	// obf name: ::%3a17a49a1586a0652e472c7ea03e5a8677681670
#define ConVar_Server_Static_ClassName "%f4dddd1b60f595be6ce7efbb530b14feecab0d18/%3a17a49a1586a0652e472c7ea03e5a8677681670"
#define ConVar_Server_Static_ClassNameShort "%3a17a49a1586a0652e472c7ea03e5a8677681670"
#define ConVar_Server_Static_TypeDefinitionIndex 793

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 622

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x4701ba0;
	}

#define LoadingScreen_TypeDefinitionIndex 457

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 2435

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%fd8b56622292955a4f660601335cdd509e671415"
#define MapView_Static_ClassNameShort "%fd8b56622292955a4f660601335cdd509e671415"
#define MapView_TypeDefinitionIndex 4830

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x321d410;
	}

	// obf name: ::%f67d7e15b74d6d8a2d72122bcb231c8009876bc8
#define GamePhysics_Static_ClassName "%a862cf5fd5e6bbf36560021a8194d2972e48c226/%f67d7e15b74d6d8a2d72122bcb231c8009876bc8"
#define GamePhysics_Static_ClassNameShort "%f67d7e15b74d6d8a2d72122bcb231c8009876bc8"
#define GamePhysics_Static_TypeDefinitionIndex 5391

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x8;
	}

	// obf name: ::%a862cf5fd5e6bbf36560021a8194d2972e48c226
#define GamePhysics_ClassName "%a862cf5fd5e6bbf36560021a8194d2972e48c226"
#define GamePhysics_ClassNameShort "%a862cf5fd5e6bbf36560021a8194d2972e48c226"
#define GamePhysics_TypeDefinitionIndex 5392

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x39c9220;
		constexpr const static size_t LineOfSightInternal = 0x39eeb90;
		constexpr const static size_t Verify = 0x39cbcf0;
	}

#define InstancedDebugDraw_TypeDefinitionIndex 5769

	namespace InstancedDebugDraw {

		// Functions
		constexpr const static size_t AddInstance = 0x3eb09d0;
	}

	// obf name: ::%69a745a23b9086d108ade6cbb9ffafe45c5543f2
#define RaycastHitEx_ClassName "%69a745a23b9086d108ade6cbb9ffafe45c5543f2"
#define RaycastHitEx_ClassNameShort "%69a745a23b9086d108ade6cbb9ffafe45c5543f2"
#define RaycastHitEx_TypeDefinitionIndex 4558

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x2f54400;
	}

	// obf name: ::%3bc6f928969b250c1c4854dba12ef8878558e49e
#define OnParentDestroyingEx_ClassName "%3bc6f928969b250c1c4854dba12ef8878558e49e"
#define OnParentDestroyingEx_ClassNameShort "%3bc6f928969b250c1c4854dba12ef8878558e49e"
#define OnParentDestroyingEx_TypeDefinitionIndex 259

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x1a8fc40;
	}

	// obf name: ::%1e19bede0c6ee7870b839a032c7a35aea818927c
#define ConsoleNetwork_ClassName "%1e19bede0c6ee7870b839a032c7a35aea818927c"
#define ConsoleNetwork_ClassNameShort "%1e19bede0c6ee7870b839a032c7a35aea818927c"
#define ConsoleNetwork_TypeDefinitionIndex 7065

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x4b74920;
	}

#define ThrownWeapon_TypeDefinitionIndex 6832

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 4392

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 985

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 4830

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 3910

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 2999

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 1336

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 2131

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 6959

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 2717

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%31e8bffa6860629594c091b1dfa28a2518294baf
#define ConVar_Client_Static_ClassName "%a2d6d7be82a92f34ac8b145f35239dab43d50c1e/%31e8bffa6860629594c091b1dfa28a2518294baf"
#define ConVar_Client_Static_ClassNameShort "%31e8bffa6860629594c091b1dfa28a2518294baf"
#define ConVar_Client_Static_TypeDefinitionIndex 3281

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x840;
		constexpr const static size_t camspeed = 0x478;
	}

#define SamSite_TypeDefinitionIndex 6951

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 731

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 2793

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 4411

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 1993

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 19

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 2687

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 5589

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%7b7b31efc18b33db934935eda373f1631b1d3630
#define Facepunch_Network_Raknet_Client_ClassName "%7b7b31efc18b33db934935eda373f1631b1d3630"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%7b7b31efc18b33db934935eda373f1631b1d3630"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 23017

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x63b6740;
		constexpr const static size_t IsConnected_vtableoff = 0x398;
	}

	// obf name: ::%4506ab79d92a860314c31d1e7f2ccfd8a88b378a
#define EncryptedValue_ClassName "%4506ab79d92a860314c31d1e7f2ccfd8a88b378a<System/Int32>"
#define EncryptedValue_ClassNameShort "%4506ab79d92a860314c31d1e7f2ccfd8a88b378a"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%6e8c63650211bbeaca0006fe2aa9e831cc85df9b
#define HiddenValue_ClassName "%6e8c63650211bbeaca0006fe2aa9e831cc85df9b<BaseNetworkable/%c5276a9185ef78de4d17eebf43657775f9ca3541>"
#define HiddenValue_ClassNameShort "%6e8c63650211bbeaca0006fe2aa9e831cc85df9b"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x20;
		constexpr const static size_t _hasValue = 0x10;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 3469

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x22630c0;
	}

#define ItemModRFListener_TypeDefinitionIndex 3957

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x28daf70;
	}

#define UIFogOverlay_TypeDefinitionIndex 2793

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
	}

	// obf name: ::%cf22f72ffb093032e5effcca48b7327ff2f81fbc
#define BufferStream_ClassName "%cf22f72ffb093032e5effcca48b7327ff2f81fbc"
#define BufferStream_ClassNameShort "%cf22f72ffb093032e5effcca48b7327ff2f81fbc"
#define BufferStream_TypeDefinitionIndex 7438

	namespace BufferStream {

		// Offsets
		constexpr const static size_t _buffer = 0x18;

		// Functions
		constexpr const static size_t EnsureCapacity = 0x98f47b0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 2656

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 3898

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 4057

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x29a7ad0;
	}

#define OutlineManager_TypeDefinitionIndex 4157

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%cf0e682d2b5af6ce31ffec2797235c57a849d7db
#define ConsoleSystem_Command_ClassName "%400afccf86fa711bf4e286fbcdc7043c88ac84ac/%cf0e682d2b5af6ce31ffec2797235c57a849d7db"
#define ConsoleSystem_Command_ClassNameShort "%cf0e682d2b5af6ce31ffec2797235c57a849d7db"
#define ConsoleSystem_Command_TypeDefinitionIndex 23557

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x20;
		constexpr const static size_t SetOveride = 0x70;
		constexpr const static size_t Call = 0x60;
	}

	// obf name: ::%5e9c312f80bd8d0408b6a088bdbcf64a201f6746
#define ConsoleSystem_Option_ClassName "%400afccf86fa711bf4e286fbcdc7043c88ac84ac/%5e9c312f80bd8d0408b6a088bdbcf64a201f6746"
#define ConsoleSystem_Option_ClassNameShort "%5e9c312f80bd8d0408b6a088bdbcf64a201f6746"
#define ConsoleSystem_Option_TypeDefinitionIndex 23567

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%3cedc70f30b982f1ec42157dee9315ab578b5415
#define ConsoleSystem_Arg_ClassName "%400afccf86fa711bf4e286fbcdc7043c88ac84ac/%3cedc70f30b982f1ec42157dee9315ab578b5415"
#define ConsoleSystem_Arg_ClassNameShort "%3cedc70f30b982f1ec42157dee9315ab578b5415"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23555

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x48;
	}

	// obf name: ::%69500d5dc77fb835d385811645e1c16338511c68
#define ConsoleSystem_Index_Client_ClassName "%400afccf86fa711bf4e286fbcdc7043c88ac84ac/%006d2ce8d72e801809a31e606e01e858be431ce0.%69500d5dc77fb835d385811645e1c16338511c68"
#define ConsoleSystem_Index_Client_ClassNameShort "%69500d5dc77fb835d385811645e1c16338511c68"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23563

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x629ba20;
	}

#define String_TypeDefinitionIndex 10410

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x842edb0;
	}

	// obf name: ::%895e7ce160c1bdcfd6c01c28c9834751dfde63f0
#define EntityRef_ClassName "%895e7ce160c1bdcfd6c01c28c9834751dfde63f0"
#define EntityRef_ClassNameShort "%895e7ce160c1bdcfd6c01c28c9834751dfde63f0"
#define EntityRef_TypeDefinitionIndex 347

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x21b86a0;
	}

#define ConVar_Debugging_TypeDefinitionIndex 24871

	namespace ConVar_Debugging {

		// Functions
		constexpr const static size_t debugcamera = 0x22da330;
		constexpr const static size_t noclip = 0x22c9ad0;
	}

#define CursorManager_TypeDefinitionIndex 7131

	namespace CursorManager {

		// Offsets
	}

	// obf name: ::%b1a57eec6b0c296f07b7305d672c64d0740393dd
#define ProtoBuf_ProjectileShoot_ClassName "%b1a57eec6b0c296f07b7305d672c64d0740393dd"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%b1a57eec6b0c296f07b7305d672c64d0740393dd"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7231

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9144f90;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9147ce0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%6c7b2dc718374c8f052b4376812eecd96b17d1e2
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%b1a57eec6b0c296f07b7305d672c64d0740393dd/%6c7b2dc718374c8f052b4376812eecd96b17d1e2"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%6c7b2dc718374c8f052b4376812eecd96b17d1e2"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7230

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t startPos = 0x10;
		constexpr const static size_t startVel = 0x24;
		constexpr const static size_t seed = 0x30;
	}

	// obf name: ::%bd125ab7b26928406a18ad263694c9251201ae22
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%bd125ab7b26928406a18ad263694c9251201ae22"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%bd125ab7b26928406a18ad263694c9251201ae22"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7159

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x14;
		constexpr const static size_t curPosition = 0x28;
		constexpr const static size_t curVelocity = 0x1c;
		constexpr const static size_t travelTime = 0x10;
		constexpr const static size_t ShouldPool = 0x19;

		// Functions
		constexpr const static size_t Dispose = 0x8819410;
		constexpr const static size_t WriteToStreamDelta = 0x8818650;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8817450;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%7bfcadcfd70f83688376989658075f02ded02105
#define ProtoBuf_PlayerProjectileAttack_ClassName "%7bfcadcfd70f83688376989658075f02ded02105"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%7bfcadcfd70f83688376989658075f02ded02105"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7536

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x24;
		constexpr const static size_t hitDistance = 0x14;
		constexpr const static size_t travelTime = 0x30;
		constexpr const static size_t playerAttack = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8b79350;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8b6f410;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%81243de342eaa2f3c0345d5d446b3db449b0e950
#define ProtoBuf_PlayerAttack_ClassName "%81243de342eaa2f3c0345d5d446b3db449b0e950"
#define ProtoBuf_PlayerAttack_ClassNameShort "%81243de342eaa2f3c0345d5d446b3db449b0e950"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7220

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x24;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%aa561138a168ac74a0e4758e0cd646fd047f0ec9
#define ProtoBuf_Attack_ClassName "%aa561138a168ac74a0e4758e0cd646fd047f0ec9"
#define ProtoBuf_Attack_ClassNameShort "%aa561138a168ac74a0e4758e0cd646fd047f0ec9"
#define ProtoBuf_Attack_TypeDefinitionIndex 7425

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x28;
		constexpr const static size_t pointEnd = 0x4c;
		constexpr const static size_t hitID = 0x78;
		constexpr const static size_t hitBone = 0x14;
		constexpr const static size_t hitNormalLocal = 0x40;
		constexpr const static size_t hitPositionLocal = 0x18;
		constexpr const static size_t hitNormalWorld = 0x68;
		constexpr const static size_t hitPositionWorld = 0x80;
		constexpr const static size_t hitPartID = 0x24;
		constexpr const static size_t hitMaterialID = 0x64;
		constexpr const static size_t srcParentID = 0x58;
		constexpr const static size_t dstParentID = 0x38;
	}
}