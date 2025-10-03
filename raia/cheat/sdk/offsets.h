#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68de8139;
		constexpr const static size_t gc_handles = 0xd754d50;
		constexpr const static size_t il2cpp_resolve_icall = 0x7a8d70;
		constexpr const static size_t il2cpp_array_new = 0x7a8d90;
		constexpr const static size_t il2cpp_assembly_get_image = 0x691d0;
		constexpr const static size_t il2cpp_class_from_name = 0x7a8f00;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x7a9210;
		constexpr const static size_t il2cpp_class_get_type = 0x7a92b0;
		constexpr const static size_t il2cpp_domain_get = 0x7a9810;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x7a9830;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x7aa0f0;
		constexpr const static size_t il2cpp_gchandle_new = 0x7aa0a0;
		constexpr const static size_t il2cpp_gchandle_free = 0x7aa190;
		constexpr const static size_t il2cpp_method_get_name = 0x33e0;
		constexpr const static size_t il2cpp_object_new = 0x7aa840;
		constexpr const static size_t il2cpp_type_get_object = 0x7ab030;
	}

#define Object_TypeDefinitionIndex 16755

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xb019350;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 16726

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

#define Component_TypeDefinitionIndex 16713

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 16707

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 16790

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xb024df0;
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

#define Camera_TypeDefinitionIndex 16505

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
	}

#define Time_TypeDefinitionIndex 16777

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

#define Material_TypeDefinitionIndex 16568

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

#define MaterialPropertyBlock_TypeDefinitionIndex 16564

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xafd8ae0;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16567

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xafdc6f0;
		constexpr const static size_t PropertyToID = 0xaa6a0;
	}

#define Mesh_TypeDefinitionIndex 16623

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

#define Renderer_TypeDefinitionIndex 16565

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16626

	namespace Texture {
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16628

	namespace Texture2D {
		constexpr const static size_t ctor = 0xaff2950;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define RenderTexture_TypeDefinitionIndex 16633

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xaffb5a0;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17103

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb03f5d0;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17079

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xb039420;
	}

#define ComputeBuffer_TypeDefinitionIndex 16768

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb01cef0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xb01d140;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16572

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xafe3900;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xafe3630;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 21832

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xb061e50;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16545

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16656

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24451

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16542

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24343

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

#define Application_TypeDefinitionIndex 16488

	namespace Application {

		// Functions
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16654

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23316

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xb0a7f20;
		constexpr const static size_t RaycastNonAlloc = 0xb0aa5f0;
	}

#define BaseNetworkable_TypeDefinitionIndex 5279

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x58;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x50;
	}

	// obf name: ::%bc74b08b0e5090af04d78fa38c132dbba8b96ed1
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%bc74b08b0e5090af04d78fa38c132dbba8b96ed1"
#define BaseNetworkable_Static_ClassNameShort "%bc74b08b0e5090af04d78fa38c132dbba8b96ed1"
#define BaseNetworkable_Static_TypeDefinitionIndex 5278

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x8;
	}

	// obf name: ::%ef487e9377e0ef8b8c79d7cc6bb5efa52b82f5c8
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%ef487e9377e0ef8b8c79d7cc6bb5efa52b82f5c8"
#define BaseNetworkable_EntityRealm_ClassNameShort "%ef487e9377e0ef8b8c79d7cc6bb5efa52b82f5c8"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 5276

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x39729f0;
	}

	// obf name: ::%1a05729e7681ac7a1cae0cc86fa535520609228f
#define System_ListDictionary_ClassName "%1a05729e7681ac7a1cae0cc86fa535520609228f<%ef8c22720d47e290351755f21129084f82f820d6,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%1a05729e7681ac7a1cae0cc86fa535520609228f"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x6f0bc60;
		constexpr const static size_t TryGetValue_methodinfo = 0xd4828e0;
	}

	// obf name: ::%94e92f8954d39eb488aec9ce41f0e92a9ec8f596
#define System_BufferList_ClassName "%94e92f8954d39eb488aec9ce41f0e92a9ec8f596<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%94e92f8954d39eb488aec9ce41f0e92a9ec8f596"
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

#define Model_TypeDefinitionIndex 2689

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 5203

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0xa0;
		constexpr const static size_t positionLerp = 0x88;

		// Functions
		constexpr const static size_t ServerRPC = 0x389a680;
		constexpr const static size_t FindBone = 0x383b410;
		constexpr const static size_t GetWorldVelocity = 0x384de20;
		constexpr const static size_t GetParentVelocity = 0x38718b0;
	}

	// obf name: ::%5efdfaeb6455eab11b3825b51f047d508311a477
#define PositionLerp_ClassName "%5efdfaeb6455eab11b3825b51f047d508311a477"
#define PositionLerp_ClassNameShort "%5efdfaeb6455eab11b3825b51f047d508311a477"
#define PositionLerp_TypeDefinitionIndex 4204

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x38;
	}

	// obf name: ::%2eb51b5a626d47302877588d973a3d0dc5c1c0c7
#define Interpolator_ClassName "%2eb51b5a626d47302877588d973a3d0dc5c1c0c7<%4feff666739d75eadf65fd93b0e39ffe26b1f02a>"
#define Interpolator_ClassNameShort "%2eb51b5a626d47302877588d973a3d0dc5c1c0c7"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 3015

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

#define SkeletonProperties_TypeDefinitionIndex 7003

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 7001

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t name = 0x0;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 579

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 578

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%aa3a23b22e3880e509e57b107435268366abda40
#define DamageTypeList_ClassName "%aa3a23b22e3880e509e57b107435268366abda40"
#define DamageTypeList_ClassNameShort "%aa3a23b22e3880e509e57b107435268366abda40"
#define DamageTypeList_TypeDefinitionIndex 6983

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 3384

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 2287

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

#define RecoilProperties_TypeDefinitionIndex 610

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 2644

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 381

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x26ddeb0;
		constexpr const static size_t StartAttackCooldown = 0x0;
	}

#define BaseProjectile_TypeDefinitionIndex 2648

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
		constexpr const static size_t LaunchProjectile = 0x1b13f40;
		constexpr const static size_t LaunchProjectileClientSide = 0x1b0b3c0;
		constexpr const static size_t ScaleRepeatDelay = 0x1b12530;
		constexpr const static size_t GetAimCone = 0x1b15500;
		constexpr const static size_t GetAimCone_vtableoff = 0x3c78;
		constexpr const static size_t UpdateAmmoDisplay = 0x1b24320;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3e88;
	}

#define BaseLauncher_TypeDefinitionIndex 4797

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 4674

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%8bb62d5cbaee56524347adb94db03005cb784359
#define HitTest_ClassName "%8bb62d5cbaee56524347adb94db03005cb784359"
#define HitTest_ClassNameShort "%8bb62d5cbaee56524347adb94db03005cb784359"
#define HitTest_TypeDefinitionIndex 139

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0xd0;
		constexpr const static size_t AttackRay = 0x70;
		constexpr const static size_t RayHit = 0x88;
		constexpr const static size_t damageProperties = 0x58;
		constexpr const static size_t gameObject = 0xb8;
		constexpr const static size_t collider = 0x50;
		constexpr const static size_t ignoredTypes = 0x20;
		constexpr const static size_t HitTransform = 0x60;
		constexpr const static size_t HitPart = 0x10;
		constexpr const static size_t HitMaterial = 0x18;
		constexpr const static size_t DidHit = 0xc9;
		constexpr const static size_t MaxDistance = 0x3c;
		constexpr const static size_t HitPoint = 0x2c;
		constexpr const static size_t HitNormal = 0x40;
		constexpr const static size_t ignoreEntity = 0x68;
		constexpr const static size_t HitEntity = 0xc0;
	}

#define Projectile_TypeDefinitionIndex 6742

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
		constexpr const static size_t sourceProjectilePrefab = 0x110;
		constexpr const static size_t mod = 0x1e0;
		constexpr const static size_t hitTest = 0x1d0;
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
		constexpr const static size_t CalculateEffectScale = 0x49ac260;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x238;
		constexpr const static size_t SetEffectScale = 0x49e6be0;
		constexpr const static size_t UpdateVelocity = 0x49d2a20;
		constexpr const static size_t Retire = 0x49a67a0;
		constexpr const static size_t DoHit = 0x49dbb20;
	}

	// obf name: ::%995e1c1da65357a51954807850cb6fc1adad88b9
#define HitInfo_ClassName "%995e1c1da65357a51954807850cb6fc1adad88b9"
#define HitInfo_ClassNameShort "%995e1c1da65357a51954807850cb6fc1adad88b9"
#define HitInfo_TypeDefinitionIndex 2590

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x78;
		constexpr const static size_t damageTypes = 0x60;

		// Functions
		constexpr const static size_t get_boneArea = 0x19a6440;
	}

	// obf name: ::%62db76e524da6ab0402530bfd6a8248a29ae3007
#define GameTrace_ClassName "%62db76e524da6ab0402530bfd6a8248a29ae3007"
#define GameTrace_ClassNameShort "%62db76e524da6ab0402530bfd6a8248a29ae3007"
#define GameTrace_TypeDefinitionIndex 4513

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x316c700;
	}

#define BaseMelee_TypeDefinitionIndex 5633

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x3d68cb0;
		constexpr const static size_t DoThrow = 0x3d65030;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 885

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x408;
		constexpr const static size_t strikeRecoil = 0x410;
		constexpr const static size_t _didSparkThisFrame = 0x418;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 3551

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x420;
		constexpr const static size_t stringBonusVelocity = 0x42c;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x25ca150;
	}

	// obf name: ::%3f5b22bd1571766755ab3da3b2e7a73082623ae1
#define ItemContainer_ClassName "%3f5b22bd1571766755ab3da3b2e7a73082623ae1"
#define ItemContainer_ClassNameShort "%3f5b22bd1571766755ab3da3b2e7a73082623ae1"
#define ItemContainer_TypeDefinitionIndex 1149

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x58;
		constexpr const static size_t itemList = 0x68;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x5232010;
	}

#define PlayerLoot_TypeDefinitionIndex 1900

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 3888

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerMain = 0x30;
		constexpr const static size_t containerWear = 0x58;
		constexpr const static size_t containerBelt = 0x60;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x2910b90;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 6348

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x4581900;
		constexpr const static size_t get_rotation = 0x4586ed0;
		constexpr const static size_t set_rotation = 0x4572c00;
		constexpr const static size_t HeadForward = 0x4565800;
	}

	// obf name: ::%a9b68afd21d8dd1ac1a558a26db56ed5080a3af9
#define PlayerEyes_Static_ClassName "PlayerEyes/%a9b68afd21d8dd1ac1a558a26db56ed5080a3af9"
#define PlayerEyes_Static_ClassNameShort "%a9b68afd21d8dd1ac1a558a26db56ed5080a3af9"
#define PlayerEyes_Static_TypeDefinitionIndex 6347

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x134;
	}

	// obf name: ::%a117f8db0b88ad9a21e85c5d9643d0368d2341cb
#define PlayerBelt_ClassName "%a117f8db0b88ad9a21e85c5d9643d0368d2341cb"
#define PlayerBelt_ClassNameShort "%a117f8db0b88ad9a21e85c5d9643d0368d2341cb"
#define PlayerBelt_TypeDefinitionIndex 1952

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x137e560;
		constexpr const static size_t GetActiveItem = 0x13713a0;
	}

	// obf name: ::%5b6953a1fad1b7b859a9b95c61c6c31631ed3532
#define LocalPlayer_ClassName "%5b6953a1fad1b7b859a9b95c61c6c31631ed3532"
#define LocalPlayer_ClassNameShort "%5b6953a1fad1b7b859a9b95c61c6c31631ed3532"
#define LocalPlayer_TypeDefinitionIndex 6112

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x42dc710;
		constexpr const static size_t MoveItem = 0x42d2200;
		constexpr const static size_t get_Entity = 0x42d6dc0;
	}

	// obf name: ::%6a500ceacd163a4c558b839607e8ccfbb1c2e2d5
#define LocalPlayer_Static_ClassName "%5b6953a1fad1b7b859a9b95c61c6c31631ed3532/%6a500ceacd163a4c558b839607e8ccfbb1c2e2d5"
#define LocalPlayer_Static_ClassNameShort "%6a500ceacd163a4c558b839607e8ccfbb1c2e2d5"
#define LocalPlayer_Static_TypeDefinitionIndex 6111

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x1d8;
	}

	// obf name: ::%cde1f5d191c7307ba08114cc45275afa1d720b9c
#define BasePlayer_Static_ClassName "BasePlayer/%cde1f5d191c7307ba08114cc45275afa1d720b9c"
#define BasePlayer_Static_ClassNameShort "%cde1f5d191c7307ba08114cc45275afa1d720b9c"
#define BasePlayer_Static_TypeDefinitionIndex 3295

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x1480;
	}

#define BasePlayer_TypeDefinitionIndex 3296

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x2e8;
		constexpr const static size_t input = 0x278;
		constexpr const static size_t movement = 0x510;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x298;
		constexpr const static size_t playerFlags = 0x598;
		constexpr const static size_t eyes = 0x338;
		constexpr const static size_t playerRigidbody = 0x5a0;
		constexpr const static size_t userID = 0x5e0;
		constexpr const static size_t UserIDString = 0x400;
		constexpr const static size_t inventory = 0x2e0;
		constexpr const static size_t _displayName = 0x6a0;
		constexpr const static size_t _lookingAt = 0x2b8;
		constexpr const static size_t lastSentTickTime = 0x554;
		constexpr const static size_t lastSentTick = 0x350;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x270;
		constexpr const static size_t _lookingAtEntity = 0x5b8;
		constexpr const static size_t currentGesture = 0x2a8;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x22bb9f0;
		constexpr const static size_t Menu_AssistPlayer = 0x2241b40;
		constexpr const static size_t OnViewModeChanged = 0x21a8430;
		constexpr const static size_t ChatMessage = 0x21d9df0;
		constexpr const static size_t IsOnGround = 0x218b610;
		constexpr const static size_t GetSpeed = 0x21b4830;
		constexpr const static size_t SendProjectileUpdate = 0x2300170;
		constexpr const static size_t SendProjectileAttack = 0x22f3c90;
		constexpr const static size_t CanBuild = 0x21edd60;
		constexpr const static size_t GetMounted = 0x2294420;
		constexpr const static size_t GetHeldEntity = 0x2205f60;
		constexpr const static size_t get_inventory = 0x21cd500;
		constexpr const static size_t get_eyes = 0x22919f0;
		constexpr const static size_t SendClientTick = 0x22da2b0;
		constexpr const static size_t ClientInput = 0x228f940;
		constexpr const static size_t ClientInput_vtableoff = 0x3bb8;
		constexpr const static size_t MaxHealth = 0x22499c0;
		constexpr const static size_t MaxHealth_vtableoff = 0xdd8;
		constexpr const static size_t OnAttacked = 0x22260c0;
		constexpr const static size_t OnAttacked_vtableoff = 0x2208;
	}

#define ScientistNPC_TypeDefinitionIndex 6526

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 2539

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 5707

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 5667

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 612

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 1280

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 6627

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x48408e0;
		constexpr const static size_t BlockSprint = 0x4857650;
		constexpr const static size_t GroundCheck = 0x4842f00;
		constexpr const static size_t ClientInput = 0x486e0d0;
		constexpr const static size_t ClientInput_vtableoff = 0x428;
		constexpr const static size_t DoFixedUpdate = 0x484ebe0;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x1d8;
		constexpr const static size_t FrameUpdate = 0x4842400;
		constexpr const static size_t FrameUpdate_vtableoff = 0x3d8;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 6858

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 705

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 6865

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 5050

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 5046

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%a77673d8b40718b81b5a22912ed94d5219a3fc97
#define ConsoleSystem_ClassName "%a77673d8b40718b81b5a22912ed94d5219a3fc97"
#define ConsoleSystem_ClassNameShort "%a77673d8b40718b81b5a22912ed94d5219a3fc97"
#define ConsoleSystem_TypeDefinitionIndex 23296

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x65701b0;
	}

	// obf name: ::%e95e15a43d13b818b28dc399d511df60502335a0
#define ConsoleSystem_Index_Static_ClassName "%a77673d8b40718b81b5a22912ed94d5219a3fc97/%189c9178af2ded50f7d169a630422344bf11fac0.%e95e15a43d13b818b28dc399d511df60502335a0"
#define ConsoleSystem_Index_Static_ClassNameShort "%e95e15a43d13b818b28dc399d511df60502335a0"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23289

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x98;
	}

#define LootableCorpse_TypeDefinitionIndex 2869

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2c8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 6990

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 3403

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x10;
		constexpr const static size_t mainCameraTransform = 0x78;

		// Functions
		constexpr const static size_t Update = 0x248da40;
		constexpr const static size_t OnPreCull = 0x2498f70;
		constexpr const static size_t Trace = 0x2499660;
	}

#define CameraMan_TypeDefinitionIndex 2586

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%a1f3997bd5fcd0f443df654726d3c6083818a6da
#define PlayerTick_ClassName "%a1f3997bd5fcd0f443df654726d3c6083818a6da"
#define PlayerTick_ClassNameShort "%a1f3997bd5fcd0f443df654726d3c6083818a6da"
#define PlayerTick_TypeDefinitionIndex 7498

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x18;
		constexpr const static size_t modelState = 0x48;
		constexpr const static size_t activeItem = 0x10;
		constexpr const static size_t parentID = 0x60;
		constexpr const static size_t intermediatePosition = 0x30;
		constexpr const static size_t position = 0x50;
		constexpr const static size_t eyePos = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8f39240;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8f429a0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%05d1deb2092a68dd383610b9709965efa36fef55
#define InputMessage_ClassName "%05d1deb2092a68dd383610b9709965efa36fef55"
#define InputMessage_ClassNameShort "%05d1deb2092a68dd383610b9709965efa36fef55"
#define InputMessage_TypeDefinitionIndex 7413

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x30;
		constexpr const static size_t mouseDelta = 0x10;
		constexpr const static size_t aimAngles = 0x20;
	}

	// obf name: ::%6af35f1d99dbe24725b80654d88115ba3ec8d05d
#define InputState_ClassName "%6af35f1d99dbe24725b80654d88115ba3ec8d05d"
#define InputState_ClassNameShort "%6af35f1d99dbe24725b80654d88115ba3ec8d05d"
#define InputState_TypeDefinitionIndex 2668

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x20;
		constexpr const static size_t previous = 0x18;
	}

#define PlayerInput_TypeDefinitionIndex 5583

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%a86c3db516500cb5a9e3878468858fcc0018fbdb
#define ModelState_ClassName "%a86c3db516500cb5a9e3878468858fcc0018fbdb"
#define ModelState_ClassNameShort "%a86c3db516500cb5a9e3878468858fcc0018fbdb"
#define ModelState_TypeDefinitionIndex 7591

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x60;
		constexpr const static size_t waterLevel = 0x48;
		constexpr const static size_t lookDir = 0x50;
	}

	// obf name: ::%1494b489255d0422ddbd62eb5b65bc2f200e1111
#define Item_ClassName "%1494b489255d0422ddbd62eb5b65bc2f200e1111"
#define Item_ClassNameShort "%1494b489255d0422ddbd62eb5b65bc2f200e1111"
#define Item_TypeDefinitionIndex 2605

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x60;
		constexpr const static size_t uid = 0xa0;
		constexpr const static size_t _condition = 0x70;
		constexpr const static size_t _maxCondition = 0x94;
		constexpr const static size_t amount = 0x78;
		constexpr const static size_t position = 0xa8;
		constexpr const static size_t contents = 0x58;
		constexpr const static size_t parent = 0xd8;
		constexpr const static size_t heldEntity = 0x28;
		constexpr const static size_t worldEnt = 0x80;

		// Functions
		constexpr const static size_t get_iconSprite = 0x1a0d4a0;
	}

	// obf name: ::%7d4bf453a9a4058d801cbe9fe8df4c9e0a0449dd
#define WaterLevel_ClassName "%7d4bf453a9a4058d801cbe9fe8df4c9e0a0449dd"
#define WaterLevel_ClassNameShort "%7d4bf453a9a4058d801cbe9fe8df4c9e0a0449dd"
#define WaterLevel_TypeDefinitionIndex 939

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x5035b00;
		constexpr const static size_t GetWaterLevel = 0x5022a40;
	}

	// obf name: ::%8bfd0ad23b65ff387e1add95eddc8e010493bf7f
#define ConVar_Graphics_Static_ClassName "%d77b5032fdf94185a8aced901eab83c9a60f908a/%8bfd0ad23b65ff387e1add95eddc8e010493bf7f"
#define ConVar_Graphics_Static_ClassNameShort "%8bfd0ad23b65ff387e1add95eddc8e010493bf7f"
#define ConVar_Graphics_Static_TypeDefinitionIndex 5110

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x3a8;

		// Functions
		constexpr const static size_t _fov_getter = 0x2f502b0;
		constexpr const static size_t _fov_setter = 0x2f49880;
	}

#define BaseFishingRod_TypeDefinitionIndex 278

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x260;
		constexpr const static size_t currentBobber = 0x268;
		constexpr const static size_t MaxCastDistance = 0x284;
		constexpr const static size_t BobberPreview = 0x290;
		constexpr const static size_t clientStrainAmountNormalised = 0x2d0;
		constexpr const static size_t strainGainMod = 0x2f0;
		constexpr const static size_t aimAnimationReady = 0x2e8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x1793eb0;
		constexpr const static size_t EvaluateFishingPosition = 0x17a8960;
	}

#define FishingBobber_TypeDefinitionIndex 5369

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 6482

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x46c9940;
	}

	// obf name: ::%86ed926e52034847e4722da29acd4e7113f05c41
#define GameManager_ClassName "%86ed926e52034847e4722da29acd4e7113f05c41"
#define GameManager_ClassNameShort "%86ed926e52034847e4722da29acd4e7113f05c41"
#define GameManager_TypeDefinitionIndex 4399

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x10;

		// Functions
		constexpr const static size_t CreatePrefab = 0x306ad40;
	}

	// obf name: ::%7be32eeaa79773098ffce259de3635362ec07327
#define GameManager_Static_ClassName "%86ed926e52034847e4722da29acd4e7113f05c41/%7be32eeaa79773098ffce259de3635362ec07327"
#define GameManager_Static_ClassNameShort "%7be32eeaa79773098ffce259de3635362ec07327"
#define GameManager_Static_TypeDefinitionIndex 4398

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x28;
	}

	// obf name: ::%f102306d5f59c23032a11ee760048f804dff3f3e
#define PrefabPoolCollection_ClassName "%f102306d5f59c23032a11ee760048f804dff3f3e"
#define PrefabPoolCollection_ClassNameShort "%f102306d5f59c23032a11ee760048f804dff3f3e"
#define PrefabPoolCollection_TypeDefinitionIndex 2864

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x18;
	}

	// obf name: ::%437a9c8876cb9e4398211824b23fbde52af96a0c
#define PrefabPool_ClassName "%437a9c8876cb9e4398211824b23fbde52af96a0c"
#define PrefabPool_ClassNameShort "%437a9c8876cb9e4398211824b23fbde52af96a0c"
#define PrefabPool_TypeDefinitionIndex 3645

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x18;
	}

#define ItemModProjectile_TypeDefinitionIndex 6626

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

#define CraftingQueue_TypeDefinitionIndex 3860

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%bf9cb2b806716e3072a54d94e9bf5c6a7b96887b
#define CraftingQueue_Static_ClassName "CraftingQueue/%bf9cb2b806716e3072a54d94e9bf5c6a7b96887b"
#define CraftingQueue_Static_ClassNameShort "%bf9cb2b806716e3072a54d94e9bf5c6a7b96887b"
#define CraftingQueue_Static_TypeDefinitionIndex 3859

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x59;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 1449

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%1355a180ab6dcb8a4c9313f40644850a3803f293
#define Planner_Static_ClassName "Planner/%1355a180ab6dcb8a4c9313f40644850a3803f293"
#define Planner_Static_ClassNameShort "%1355a180ab6dcb8a4c9313f40644850a3803f293"
#define Planner_Static_TypeDefinitionIndex 5502

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x188;
	}

	// obf name: ::%9b88df305382fe95fd458e402c2d8144c85c9548
#define Planner_Guide_ClassName "Planner/%9b88df305382fe95fd458e402c2d8144c85c9548"
#define Planner_Guide_ClassNameShort "%9b88df305382fe95fd458e402c2d8144c85c9548"
#define Planner_Guide_TypeDefinitionIndex 5498

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x88;
	}

#define Planner_TypeDefinitionIndex 5503

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x288;
	}

#define Construction_TypeDefinitionIndex 6094

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x180;
	}

#define BuildingBlock_TypeDefinitionIndex 1808

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x310;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 3780

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x280e120;
	}

	// obf name: ::%1d231e174b6ed10cd41ca3ba23a7fac04953bd60
#define PunchEntry_ClassName "HeldEntity/%1d231e174b6ed10cd41ca3ba23a7fac04953bd60"
#define PunchEntry_ClassNameShort "%1d231e174b6ed10cd41ca3ba23a7fac04953bd60"
#define PunchEntry_TypeDefinitionIndex 3778

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x10;
		constexpr const static size_t startTime = 0x14;
		constexpr const static size_t amountAdded = 0x18;
		constexpr const static size_t amount = 0x24;
	}

#define IronSights_TypeDefinitionIndex 1321

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 4045

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 5461

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xc8;
		constexpr const static size_t model = 0x78;
		constexpr const static size_t lower = 0x80;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x3b1c380;
	}

#define ViewModel_TypeDefinitionIndex 5080

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x36faf00;
		constexpr const static size_t PlayString = 0x36fda90;
	}

#define MedicalTool_TypeDefinitionIndex 2181

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 6312

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x40;
	}

	// obf name: ::%501973e45a9addf9968917c31ea7deb6f3bbbee6
#define WaterSystem_Static_ClassName "WaterSystem/%501973e45a9addf9968917c31ea7deb6f3bbbee6"
#define WaterSystem_Static_ClassNameShort "%501973e45a9addf9968917c31ea7deb6f3bbbee6"
#define WaterSystem_Static_TypeDefinitionIndex 1700

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x120;
	}

#define WaterSystem_TypeDefinitionIndex 1701

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x1066410;
	}

#define TerrainMeta_TypeDefinitionIndex 6219

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x470;
		constexpr const static size_t HeightMap = 0x108;
		constexpr const static size_t SplatMap = 0x158;
		constexpr const static size_t TopologyMap = 0x690;
		constexpr const static size_t Texturing = 0x688;
	}

#define TerrainCollision_TypeDefinitionIndex 4060

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x2afd9a0;
	}

#define TerrainHeightMap_TypeDefinitionIndex 1129

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 7060

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 3415

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%c9947e5aa5085952027d6e0cf1d96aafcff3dbab
#define World_Static_ClassName "%459dd9d6b9b232c61480217f90ce8484018b38b3/%c9947e5aa5085952027d6e0cf1d96aafcff3dbab"
#define World_Static_ClassNameShort "%c9947e5aa5085952027d6e0cf1d96aafcff3dbab"
#define World_Static_TypeDefinitionIndex 5964

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x58;
	}

#define ItemIcon_TypeDefinitionIndex 3907

	namespace ItemIcon {

		// Functions
		constexpr const static size_t TryToMove = 0x29463d0;
		constexpr const static size_t TryToMove_vtableoff = 0x448;
		constexpr const static size_t RunTimedAction = 0x2949820;
	}

	// obf name: ::%cc9f2e26a0b72c190e559f351b0ad4e648f79662
#define ItemIcon_Static_ClassName "ItemIcon/%cc9f2e26a0b72c190e559f351b0ad4e648f79662"
#define ItemIcon_Static_ClassNameShort "%cc9f2e26a0b72c190e559f351b0ad4e648f79662"
#define ItemIcon_Static_TypeDefinitionIndex 3906

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x28;
	}

	// obf name: ::%789238ed4161cca56894468d7653a134f33aa52f
#define Effect_ClassName "%789238ed4161cca56894468d7653a134f33aa52f"
#define Effect_ClassNameShort "%789238ed4161cca56894468d7653a134f33aa52f"
#define Effect_TypeDefinitionIndex 670

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0xa0;
		constexpr const static size_t worldPos = 0x70;
	}

	// obf name: ::%b34acde6ebe7cd2ddd6e6796692fdbd06f565a33
#define EffectNetwork_ClassName "%b34acde6ebe7cd2ddd6e6796692fdbd06f565a33"
#define EffectNetwork_ClassNameShort "%b34acde6ebe7cd2ddd6e6796692fdbd06f565a33"
#define EffectNetwork_TypeDefinitionIndex 3173

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%003c9f095ad49c34334bae49866d7eb3e724c8ee
#define EffectNetwork_Static_ClassName "%b34acde6ebe7cd2ddd6e6796692fdbd06f565a33/%003c9f095ad49c34334bae49866d7eb3e724c8ee"
#define EffectNetwork_Static_ClassNameShort "%003c9f095ad49c34334bae49866d7eb3e724c8ee"
#define EffectNetwork_Static_TypeDefinitionIndex 3172

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x38;

		// Functions
		constexpr const static size_t cctor = 0x20aba40;
	}

#define BuildingBlock_TypeDefinitionIndex 1808

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x11ae9b0;
		constexpr const static size_t HasUpgradePrivilege = 0x11d3c80;
		constexpr const static size_t CanAffordUpgrade = 0x11e63f0;
	}

	// obf name: ::%965ee6e7737e5723fe167eefb30535689357fe29
#define GameObjectEx_ClassName "%965ee6e7737e5723fe167eefb30535689357fe29"
#define GameObjectEx_ClassNameShort "%965ee6e7737e5723fe167eefb30535689357fe29"
#define GameObjectEx_TypeDefinitionIndex 4269

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x2dd4fb0;
	}

#define UIDeathScreen_TypeDefinitionIndex 2710

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x1bbf6b0;
	}

	// obf name: ::%7ca5e690c177d824e04a027643b02bc217f0b8d4
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%7ca5e690c177d824e04a027643b02bc217f0b8d4"
#define BaseScreenShake_Static_ClassNameShort "%7ca5e690c177d824e04a027643b02bc217f0b8d4"
#define BaseScreenShake_Static_TypeDefinitionIndex 6416

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x28;
	}

#define FlashbangOverlay_TypeDefinitionIndex 4724

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%b36a1a45bcfedb99fc9da172adc8e5ecd1ed0fd1
#define StringPool_ClassName "%b36a1a45bcfedb99fc9da172adc8e5ecd1ed0fd1"
#define StringPool_ClassNameShort "%b36a1a45bcfedb99fc9da172adc8e5ecd1ed0fd1"
#define StringPool_TypeDefinitionIndex 241

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x30;

		// Functions
		constexpr const static size_t Get = 0x161d070;
	}

	// obf name: ::%5e48a935b953dd05925652dea1d32a1ad48912c2
#define Network_Networkable_ClassName "%5e48a935b953dd05925652dea1d32a1ad48912c2"
#define Network_Networkable_ClassNameShort "%5e48a935b953dd05925652dea1d32a1ad48912c2"
#define Network_Networkable_TypeDefinitionIndex 19121

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x48;
	}

	// obf name: ::%ebd370c7906860683a74185775955054411ea4dc
#define Network_Net_ClassName "%ebd370c7906860683a74185775955054411ea4dc"
#define Network_Net_ClassNameShort "%ebd370c7906860683a74185775955054411ea4dc"
#define Network_Net_TypeDefinitionIndex 8748

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x20;
	}

	// obf name: ::%3e171f619ba212eda28650813012f63f56609c2a
#define Network_Client_ClassName "%3e171f619ba212eda28650813012f63f56609c2a"
#define Network_Client_ClassNameShort "%3e171f619ba212eda28650813012f63f56609c2a"
#define Network_Client_TypeDefinitionIndex 19158

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0x108;
		constexpr const static size_t ConnectedPort = 0xd8;
		constexpr const static size_t ConnectedAddress = 0xe0;
		constexpr const static size_t ServerName = 0xe8;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x6623230;
		constexpr const static size_t DestroyNetworkable = 0x6624040;
	}

	// obf name: ::%421a235ddde7f48277ab9058ac846847625b553c
#define Network_BaseNetwork_ClassName "%421a235ddde7f48277ab9058ac846847625b553c"
#define Network_BaseNetwork_ClassNameShort "%421a235ddde7f48277ab9058ac846847625b553c"
#define Network_BaseNetwork_TypeDefinitionIndex 19165

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x66366c0;
	}

	// obf name: ::%53a7f3a4b1d842f94c13feac131a69d36d0339e6
#define Network_SendInfo_ClassName "%53a7f3a4b1d842f94c13feac131a69d36d0339e6"
#define Network_SendInfo_ClassNameShort "%53a7f3a4b1d842f94c13feac131a69d36d0339e6"
#define Network_SendInfo_TypeDefinitionIndex 19130

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%9dba5a09219d5c06b925e9f719b63a615453a23e
#define Network_Message_ClassName "%9dba5a09219d5c06b925e9f719b63a615453a23e"
#define Network_Message_ClassNameShort "%9dba5a09219d5c06b925e9f719b63a615453a23e"
#define Network_Message_TypeDefinitionIndex 19136

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x20;
		constexpr const static size_t read = 0x18;
	}

	// obf name: ::%2e3e3f78c903254f0ab7d8196df69cb467e6e528
#define Network_NetRead_ClassName "%2e3e3f78c903254f0ab7d8196df69cb467e6e528"
#define Network_NetRead_ClassNameShort "%2e3e3f78c903254f0ab7d8196df69cb467e6e528"
#define Network_NetRead_TypeDefinitionIndex 19105

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x48;
	}

	// obf name: ::%d0d94d605a165192f6fa14950937db57e4c8c372
#define Network_NetWrite_ClassName "%d0d94d605a165192f6fa14950937db57e4c8c372"
#define Network_NetWrite_ClassNameShort "%d0d94d605a165192f6fa14950937db57e4c8c372"
#define Network_NetWrite_TypeDefinitionIndex 19142

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x50;

		// Functions
		constexpr const static size_t WriteByte = 0x66141b0;
		constexpr const static size_t String = 0x660cdb0;
		constexpr const static size_t Send = 0x66127e0;
	}

#define LootPanel_TypeDefinitionIndex 4363

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x2ec9b10;
	}

#define UIInventory_TypeDefinitionIndex 1875

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x127ba40;
	}

#define GrowableEntity_TypeDefinitionIndex 3586

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 5652

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 5651

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 20898

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 7836

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
		constexpr const static size_t get_Instance = 0xd97500;
	}

	// obf name: ::%36c18dc48113eb6fe10eea824a9b9e75751b5d17
#define TOD_Sky_Static_ClassName "TOD_Sky/%36c18dc48113eb6fe10eea824a9b9e75751b5d17"
#define TOD_Sky_Static_ClassNameShort "%36c18dc48113eb6fe10eea824a9b9e75751b5d17"
#define TOD_Sky_Static_TypeDefinitionIndex 7835

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x50;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 8351

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xa3b920;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9399

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 7991

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 9250

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 9406

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 9467

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 8622

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 1035

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 3571

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 189

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 3687

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

#define EnvironmentManager_TypeDefinitionIndex 6730

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x4a02040;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%123e626dd88babb54acec3a1bfd2bee31eabeb9f/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24076

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 1229

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 1230

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 709

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

	// obf name: ::%2b008485418d28ec263a30e9a55595f7a0143092
#define ListHashSet_ClassName "%2b008485418d28ec263a30e9a55595f7a0143092<UIChat>"
#define ListHashSet_ClassNameShort "%2b008485418d28ec263a30e9a55595f7a0143092"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 6946

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3f0;
	}

#define Chainsaw_TypeDefinitionIndex 1974

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%399c2565899f570bec8be8aaba6bbf7683faab4f
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%399c2565899f570bec8be8aaba6bbf7683faab4f"
#define CameraUpdateHook_Static_ClassNameShort "%399c2565899f570bec8be8aaba6bbf7683faab4f"
#define CameraUpdateHook_Static_TypeDefinitionIndex 4508

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x40;
	}

#define SteamClientWrapper_TypeDefinitionIndex 574

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x3d8e590;
	}

	// obf name: ::%8075a9012288b820a469055915377859f65e9b05
#define AimConeUtil_ClassName "%8075a9012288b820a469055915377859f65e9b05"
#define AimConeUtil_ClassNameShort "%8075a9012288b820a469055915377859f65e9b05"
#define AimConeUtil_TypeDefinitionIndex 6611

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x48806f0;
	}

	// obf name: ::%0085e3a7f44767c8024a6cbd88aff2b7cf9e0aad
#define Buttons_ConButton_ClassName "%92641d26e3e5293d4a554175e564e67bdff2381d/%0085e3a7f44767c8024a6cbd88aff2b7cf9e0aad"
#define Buttons_ConButton_ClassNameShort "%0085e3a7f44767c8024a6cbd88aff2b7cf9e0aad"
#define Buttons_ConButton_TypeDefinitionIndex 1062

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%7b19cfe1d5bf189ef7bdf3e06c0051e5029a97b9
#define Buttons_Static_ClassName "%92641d26e3e5293d4a554175e564e67bdff2381d/%7b19cfe1d5bf189ef7bdf3e06c0051e5029a97b9"
#define Buttons_Static_ClassNameShort "%7b19cfe1d5bf189ef7bdf3e06c0051e5029a97b9"
#define Buttons_Static_TypeDefinitionIndex 1063

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0xd08;
		constexpr const static size_t Attack = 0xc20;
		constexpr const static size_t Attack2 = 0xf80;
		constexpr const static size_t Forward = 0xb40;
		constexpr const static size_t Backward = 0x308;
		constexpr const static size_t Right = 0x208;
		constexpr const static size_t Left = 0xcf0;
		constexpr const static size_t Sprint = 0xd8;

		// Functions
		constexpr const static size_t Pets_setter = 0x2f24300;
	}

#define PlayerModel_TypeDefinitionIndex 4787

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x288;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 3981

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x40;
	}

#define BaseMountable_TypeDefinitionIndex 863

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 2808

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x48;
		constexpr const static size_t timeCounter = 0x24;
	}

#define BowWeapon_TypeDefinitionIndex 4776

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x408;
		constexpr const static size_t wasAiming = 0x418;
	}

#define CrossbowWeapon_TypeDefinitionIndex 585

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 6639

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%6d7ac8a4f1f8b7eec2a07c7307bec2d3381dcd78
#define ConVar_Admin_Static_ClassName "%090ef44d3c59e4b66bbd8f7dcd184ad97eb19889/%6d7ac8a4f1f8b7eec2a07c7307bec2d3381dcd78"
#define ConVar_Admin_Static_ClassNameShort "%6d7ac8a4f1f8b7eec2a07c7307bec2d3381dcd78"
#define ConVar_Admin_Static_TypeDefinitionIndex 2580

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0xfc;

		// Functions
		constexpr const static size_t admintime_getter = 0x2f1bd00;
		constexpr const static size_t admintime_setter = 0x2f49f10;
	}

	// obf name: ::%9d5ac067e99f0155e8d629968f959da46bc8e1b6
#define ConVar_Player_Static_ClassName "%bd26db270893145cba27f6b3f7868c308c9755f6/%9d5ac067e99f0155e8d629968f959da46bc8e1b6"
#define ConVar_Player_Static_ClassNameShort "%9d5ac067e99f0155e8d629968f959da46bc8e1b6"
#define ConVar_Player_Static_TypeDefinitionIndex 5313

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x154;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x2f07cf0;
		constexpr const static size_t clientTickRate_setter = 0x2f2cae0;
	}

#define ColliderInfo_TypeDefinitionIndex 3502

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 3321

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 4861

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x338;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x3503010;
	}

#define Client_TypeDefinitionIndex 3967

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x29f9a60;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%2a48067f326aeb8910d87e97be7e6697f15bdac7
#define ItemManager_Static_ClassName "%228397508196532eef47c0f61d95045dd276ba6f/%2a48067f326aeb8910d87e97be7e6697f15bdac7"
#define ItemManager_Static_ClassNameShort "%2a48067f326aeb8910d87e97be7e6697f15bdac7"
#define ItemManager_Static_TypeDefinitionIndex 2380

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x1b8;
		constexpr const static size_t itemDictionary = 0x20;
		constexpr const static size_t itemDictionaryByName = 0x1c8;
	}

	// obf name: ::%08f69e1377920a61ff185e5da1e09102981cb688
#define ConVar_Server_Static_ClassName "%b52f0090fb21503f2d8ce664342d643f106074b0/%08f69e1377920a61ff185e5da1e09102981cb688"
#define ConVar_Server_Static_ClassNameShort "%08f69e1377920a61ff185e5da1e09102981cb688"
#define ConVar_Server_Static_TypeDefinitionIndex 5123

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 1906

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x12ddae0;
	}

#define LoadingScreen_TypeDefinitionIndex 2082

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 4920

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%25b2e4152007f1bb54caf6aa3c8403668c30637b"
#define MapView_Static_ClassNameShort "%25b2e4152007f1bb54caf6aa3c8403668c30637b"
#define MapView_TypeDefinitionIndex 2976

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x1e94710;
	}

	// obf name: ::%3cc1149988e0606f92ebf37baebab4b6abf0e59e
#define GamePhysics_Static_ClassName "%3ef497c06f4757c748fe9735ab8a936d382d0948/%3cc1149988e0606f92ebf37baebab4b6abf0e59e"
#define GamePhysics_Static_ClassNameShort "%3cc1149988e0606f92ebf37baebab4b6abf0e59e"
#define GamePhysics_Static_TypeDefinitionIndex 1235

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x40;
	}

	// obf name: ::%3ef497c06f4757c748fe9735ab8a936d382d0948
#define GamePhysics_ClassName "%3ef497c06f4757c748fe9735ab8a936d382d0948"
#define GamePhysics_ClassNameShort "%3ef497c06f4757c748fe9735ab8a936d382d0948"
#define GamePhysics_TypeDefinitionIndex 1236

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x5391ae0;
		constexpr const static size_t LineOfSightInternal = 0x53b35b0;
		constexpr const static size_t Verify = 0x53942d0;
	}

#define DDraw_TypeDefinitionIndex 567

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x3a35be0;
		constexpr const static size_t Line = 0x3a3c5b0;
	}

	// obf name: ::%65e1d7606bcc4acd1bb6dd7a9cb9a0df8fcd0d4e
#define RaycastHitEx_ClassName "%65e1d7606bcc4acd1bb6dd7a9cb9a0df8fcd0d4e"
#define RaycastHitEx_ClassNameShort "%65e1d7606bcc4acd1bb6dd7a9cb9a0df8fcd0d4e"
#define RaycastHitEx_TypeDefinitionIndex 3197

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x20cde00;
	}

	// obf name: ::%67b748963316e219ce0ddde310b85aede156b0cd
#define OnParentDestroyingEx_ClassName "%67b748963316e219ce0ddde310b85aede156b0cd"
#define OnParentDestroyingEx_ClassNameShort "%67b748963316e219ce0ddde310b85aede156b0cd"
#define OnParentDestroyingEx_TypeDefinitionIndex 3431

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x24b24d0;
	}

	// obf name: ::%b3dc6765f687b8c5e5835a563469a1e720f01455
#define ConsoleNetwork_ClassName "%b3dc6765f687b8c5e5835a563469a1e720f01455"
#define ConsoleNetwork_ClassNameShort "%b3dc6765f687b8c5e5835a563469a1e720f01455"
#define ConsoleNetwork_TypeDefinitionIndex 3680

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x274d9b0;
	}

#define ThrownWeapon_TypeDefinitionIndex 4258

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 4164

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 4641

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 2976

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 2479

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 4489

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 1914

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 5940

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 6161

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 5148

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%3faf8d4c798c6e25d330cb084a8b4f115b05fb6e
#define ConVar_Client_Static_ClassName "%de9b685c5b423fcb051a04a3730850ab7dd6960e/%3faf8d4c798c6e25d330cb084a8b4f115b05fb6e"
#define ConVar_Client_Static_ClassNameShort "%3faf8d4c798c6e25d330cb084a8b4f115b05fb6e"
#define ConVar_Client_Static_TypeDefinitionIndex 5165

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x7f0;
		constexpr const static size_t camspeed = 0x88c;
	}

#define SamSite_TypeDefinitionIndex 2352

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 6522

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 1943

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 1404

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 797

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 1645

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 815

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 363

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%54cb20e5819cd3a2bec322ac5ae4b2418f37b5a9
#define Facepunch_Network_Raknet_Client_ClassName "%54cb20e5819cd3a2bec322ac5ae4b2418f37b5a9"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%54cb20e5819cd3a2bec322ac5ae4b2418f37b5a9"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 22608

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x66b04b0;
		constexpr const static size_t IsConnected_vtableoff = 0x318;
	}

	// obf name: ::%3b0f63048d6f3865f7f33dc0a8e7f7dccf0edd41
#define EncryptedValue_ClassName "%3b0f63048d6f3865f7f33dc0a8e7f7dccf0edd41<System/Int32>"
#define EncryptedValue_ClassNameShort "%3b0f63048d6f3865f7f33dc0a8e7f7dccf0edd41"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%9aaeb31208eb3bbf3e6c49308ac60ca55e99e8fb
#define HiddenValue_ClassName "%9aaeb31208eb3bbf3e6c49308ac60ca55e99e8fb<BaseNetworkable/%ef487e9377e0ef8b8c79d7cc6bb5efa52b82f5c8>"
#define HiddenValue_ClassNameShort "%9aaeb31208eb3bbf3e6c49308ac60ca55e99e8fb"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 4050

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x2aefd00;
	}

#define ItemModRFListener_TypeDefinitionIndex 6140

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x43027a0;
	}

#define UIFogOverlay_TypeDefinitionIndex 1943

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x10;
	}

	// obf name: ::%b6c99fe1b575bb0eb7d6b87394939dbe6f66f175
#define BufferStream_ClassName "%b6c99fe1b575bb0eb7d6b87394939dbe6f66f175"
#define BufferStream_ClassNameShort "%b6c99fe1b575bb0eb7d6b87394939dbe6f66f175"
#define BufferStream_TypeDefinitionIndex 7463

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x8de4c00;
	}

#define FreeableLootContainer_TypeDefinitionIndex 3901

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 1162

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 1085

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x5196010;
	}

#define OutlineManager_TypeDefinitionIndex 5565

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%d0f0fbd099f6f076dede7eaecc89587eda179c8c
#define ConsoleSystem_Command_ClassName "%a77673d8b40718b81b5a22912ed94d5219a3fc97/%d0f0fbd099f6f076dede7eaecc89587eda179c8c"
#define ConsoleSystem_Command_ClassNameShort "%d0f0fbd099f6f076dede7eaecc89587eda179c8c"
#define ConsoleSystem_Command_TypeDefinitionIndex 23281

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x18;
		constexpr const static size_t SetOveride = 0x48;
		constexpr const static size_t Call = 0x40;
	}

	// obf name: ::%1e27ee77b60fdfa890950c5c2bfd03f670c9da46
#define ConsoleSystem_Option_ClassName "%a77673d8b40718b81b5a22912ed94d5219a3fc97/%1e27ee77b60fdfa890950c5c2bfd03f670c9da46"
#define ConsoleSystem_Option_ClassNameShort "%1e27ee77b60fdfa890950c5c2bfd03f670c9da46"
#define ConsoleSystem_Option_TypeDefinitionIndex 23291

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%96dc10cc09085298824f4b884ab29b57ed008879
#define ConsoleSystem_Arg_ClassName "%a77673d8b40718b81b5a22912ed94d5219a3fc97/%96dc10cc09085298824f4b884ab29b57ed008879"
#define ConsoleSystem_Arg_ClassNameShort "%96dc10cc09085298824f4b884ab29b57ed008879"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23279

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x38;
	}

	// obf name: ::%7e16f1403c7b383708aa19380852a3456fe9da64
#define ConsoleSystem_Index_Client_ClassName "%a77673d8b40718b81b5a22912ed94d5219a3fc97/%189c9178af2ded50f7d169a630422344bf11fac0.%7e16f1403c7b383708aa19380852a3456fe9da64"
#define ConsoleSystem_Index_Client_ClassNameShort "%7e16f1403c7b383708aa19380852a3456fe9da64"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23287

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x657cbe0;
	}

#define String_TypeDefinitionIndex 10203

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x8739190;
	}

	// obf name: ::%0652a723f107d3366618b08aac0c354c13059f56
#define ProtoBuf_ProjectileShoot_ClassName "%0652a723f107d3366618b08aac0c354c13059f56"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%0652a723f107d3366618b08aac0c354c13059f56"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7500

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8f5d560;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8f5cad0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%367a8bdf0fe032c518d439131c4eaebf4acd3324
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%0652a723f107d3366618b08aac0c354c13059f56/%367a8bdf0fe032c518d439131c4eaebf4acd3324"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%367a8bdf0fe032c518d439131c4eaebf4acd3324"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7499

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t startPos = 0x28;
		constexpr const static size_t startVel = 0x14;
		constexpr const static size_t seed = 0x10;
	}

	// obf name: ::%b6febdfbf71bf29a6c3f377ef84d8e1977b94b1a
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%b6febdfbf71bf29a6c3f377ef84d8e1977b94b1a"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%b6febdfbf71bf29a6c3f377ef84d8e1977b94b1a"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7469

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x2c;
		constexpr const static size_t curPosition = 0x20;
		constexpr const static size_t curVelocity = 0x10;
		constexpr const static size_t travelTime = 0x30;
		constexpr const static size_t ShouldPool = 0x1c;

		// Functions
		constexpr const static size_t Dispose = 0x8e39fa0;
		constexpr const static size_t WriteToStreamDelta = 0x8e36a70;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8e34050;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%d98e47f3bf9927b7cbfc48528f14172ca2b2f80c
#define ProtoBuf_PlayerProjectileAttack_ClassName "%d98e47f3bf9927b7cbfc48528f14172ca2b2f80c"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%d98e47f3bf9927b7cbfc48528f14172ca2b2f80c"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7339

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x1c;
		constexpr const static size_t hitDistance = 0x10;
		constexpr const static size_t travelTime = 0x14;
		constexpr const static size_t playerAttack = 0x28;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x982ca00;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x982e3f0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%7ca62c038c6b4e42ee1bda0ec3047748e5c24d95
#define ProtoBuf_PlayerAttack_ClassName "%7ca62c038c6b4e42ee1bda0ec3047748e5c24d95"
#define ProtoBuf_PlayerAttack_ClassNameShort "%7ca62c038c6b4e42ee1bda0ec3047748e5c24d95"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7430

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t attack = 0x18;
		constexpr const static size_t projectileID = 0x24;
	}

	// obf name: ::%655f702ce8eea1c9f4a8f703ad60c3b81c076846
#define ProtoBuf_Attack_ClassName "%655f702ce8eea1c9f4a8f703ad60c3b81c076846"
#define ProtoBuf_Attack_ClassNameShort "%655f702ce8eea1c9f4a8f703ad60c3b81c076846"
#define ProtoBuf_Attack_TypeDefinitionIndex 7182

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x20;
		constexpr const static size_t pointEnd = 0x2c;
		constexpr const static size_t hitID = 0x78;
		constexpr const static size_t hitBone = 0x38;
		constexpr const static size_t hitNormalLocal = 0x3c;
		constexpr const static size_t hitPositionLocal = 0x68;
		constexpr const static size_t hitNormalWorld = 0x50;
		constexpr const static size_t hitPositionWorld = 0x10;
		constexpr const static size_t hitPartID = 0x88;
		constexpr const static size_t hitMaterialID = 0x80;
		constexpr const static size_t srcParentID = 0x60;
		constexpr const static size_t dstParentID = 0x48;
	}
}