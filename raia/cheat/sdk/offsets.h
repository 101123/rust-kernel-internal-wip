#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x68e14895;
		constexpr const static size_t gc_handles = 0xd826c00;
		constexpr const static size_t il2cpp_resolve_icall = 0x7ae530;
		constexpr const static size_t il2cpp_array_new = 0x7ae550;
		constexpr const static size_t il2cpp_assembly_get_image = 0x17220;
		constexpr const static size_t il2cpp_class_from_name = 0x7ae6c0;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x7ae9d0;
		constexpr const static size_t il2cpp_class_get_type = 0x7aea70;
		constexpr const static size_t il2cpp_domain_get = 0x7aefd0;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x7aeff0;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x7af8b0;
		constexpr const static size_t il2cpp_gchandle_new = 0x7af860;
		constexpr const static size_t il2cpp_gchandle_free = 0x7af950;
		constexpr const static size_t il2cpp_method_get_name = 0x2d90;
		constexpr const static size_t il2cpp_object_new = 0x7b0000;
		constexpr const static size_t il2cpp_type_get_object = 0x7b07f0;
	}

#define Object_TypeDefinitionIndex 16755

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xb0f02b0;
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
		constexpr const static size_t get_eulerAngles = 0xb0fbea0;
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
		constexpr const static size_t ctor = 0xb0b01c0;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16567

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xb0b3f20;
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
		constexpr const static size_t ctor = 0xb0c99f0;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define RenderTexture_TypeDefinitionIndex 16633

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xb0d2670;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17103

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb116270;
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
		constexpr const static size_t ctor = 0xb1100d0;
	}

#define ComputeBuffer_TypeDefinitionIndex 16768

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb0f3e60;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xb0f40b0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16572

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xb0bacd0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xb0baa00;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 21858

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xb138ad0;
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

#define AssetBundle_TypeDefinitionIndex 24468

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

#define Physics_TypeDefinitionIndex 23319

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xb17e1b0;
		constexpr const static size_t RaycastNonAlloc = 0xb180880;
	}

#define BaseNetworkable_TypeDefinitionIndex 4690

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x28;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x38;
	}

	// obf name: ::%322ee7b9bd8bd25c38015e8cd7189bde207d346b
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%322ee7b9bd8bd25c38015e8cd7189bde207d346b"
#define BaseNetworkable_Static_ClassNameShort "%322ee7b9bd8bd25c38015e8cd7189bde207d346b"
#define BaseNetworkable_Static_TypeDefinitionIndex 4689

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x38;
	}

	// obf name: ::%0002eeb2d61933eabb395cb5df21eb33519bef29
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%0002eeb2d61933eabb395cb5df21eb33519bef29"
#define BaseNetworkable_EntityRealm_ClassNameShort "%0002eeb2d61933eabb395cb5df21eb33519bef29"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 4687

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x306eec0;
	}

	// obf name: ::%22c77dc462352bd0f976b14b1f400881250e88cc
#define System_ListDictionary_ClassName "%22c77dc462352bd0f976b14b1f400881250e88cc<%a1808f2fb5dea217c3471dc0464a00dfbbf28a36,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%22c77dc462352bd0f976b14b1f400881250e88cc"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x18;

		// Functions
		constexpr const static size_t TryGetValue = 0x6ee8de0;
		constexpr const static size_t TryGetValue_methodinfo = 0xd567380;
	}

	// obf name: ::%f73ece50ddc7225cd4b52fc7024aac94793bfb19
#define System_BufferList_ClassName "%f73ece50ddc7225cd4b52fc7024aac94793bfb19<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%f73ece50ddc7225cd4b52fc7024aac94793bfb19"
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

#define Model_TypeDefinitionIndex 1856

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 5295

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0x90;
		constexpr const static size_t positionLerp = 0x130;

		// Functions
		constexpr const static size_t ServerRPC = 0x37fd0c0;
		constexpr const static size_t FindBone = 0x37d0b80;
		constexpr const static size_t GetWorldVelocity = 0x37ef060;
		constexpr const static size_t GetParentVelocity = 0x3820050;
	}

	// obf name: ::%7f1684913fb30630cbc9f0376a9aa4dc34cb10e0
#define PositionLerp_ClassName "%7f1684913fb30630cbc9f0376a9aa4dc34cb10e0"
#define PositionLerp_ClassNameShort "%7f1684913fb30630cbc9f0376a9aa4dc34cb10e0"
#define PositionLerp_TypeDefinitionIndex 4842

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x40;
	}

	// obf name: ::%9c2112063b3599a0001b3c1324d6e632736bdeaf
#define Interpolator_ClassName "%9c2112063b3599a0001b3c1324d6e632736bdeaf<%87c3dd62cd9846ed4fe816c785100c97c72b5dfc>"
#define Interpolator_ClassNameShort "%9c2112063b3599a0001b3c1324d6e632736bdeaf"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 5659

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

#define SkeletonProperties_TypeDefinitionIndex 2026

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 2024

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 4732

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 4731

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%04334699de9e8f1fa87f4e9be50c30dad01cc674
#define DamageTypeList_ClassName "%04334699de9e8f1fa87f4e9be50c30dad01cc674"
#define DamageTypeList_ClassNameShort "%04334699de9e8f1fa87f4e9be50c30dad01cc674"
#define DamageTypeList_TypeDefinitionIndex 4152

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 2657

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 2336

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

#define RecoilProperties_TypeDefinitionIndex 1635

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 5790

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 3986

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x2a163b0;
		constexpr const static size_t StartAttackCooldown = 0x2a16650;
	}

#define BaseProjectile_TypeDefinitionIndex 5794

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
		constexpr const static size_t LaunchProjectile = 0x3e47cd0;
		constexpr const static size_t LaunchProjectileClientSide = 0x3e39c00;
		constexpr const static size_t ScaleRepeatDelay = 0x3e29ce0;
		constexpr const static size_t GetAimCone = 0x3e535b0;
		constexpr const static size_t GetAimCone_vtableoff = 0x3f98;
		constexpr const static size_t UpdateAmmoDisplay = 0x3e47610;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3e48;
	}

#define BaseLauncher_TypeDefinitionIndex 6298

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 1156

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%375a1d4252e2c2ed4818ba64b934e1c362266866
#define HitTest_ClassName "%375a1d4252e2c2ed4818ba64b934e1c362266866"
#define HitTest_ClassNameShort "%375a1d4252e2c2ed4818ba64b934e1c362266866"
#define HitTest_TypeDefinitionIndex 1730

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x10;
		constexpr const static size_t AttackRay = 0x88;
		constexpr const static size_t RayHit = 0x48;
		constexpr const static size_t damageProperties = 0xc8;
		constexpr const static size_t gameObject = 0x80;
		constexpr const static size_t collider = 0x30;
		constexpr const static size_t ignoredTypes = 0xa8;
		constexpr const static size_t HitTransform = 0xd0;
		constexpr const static size_t HitPart = 0x18;
		constexpr const static size_t HitMaterial = 0x20;
		constexpr const static size_t DidHit = 0x44;
		constexpr const static size_t MaxDistance = 0x40;
		constexpr const static size_t HitPoint = 0x74;
		constexpr const static size_t HitNormal = 0xbc;
		constexpr const static size_t ignoreEntity = 0x38;
		constexpr const static size_t HitEntity = 0xb0;
	}

#define Projectile_TypeDefinitionIndex 4499

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
		constexpr const static size_t sourceProjectilePrefab = 0x108;
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
		constexpr const static size_t CalculateEffectScale = 0x2ec7040;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x3e8;
		constexpr const static size_t SetEffectScale = 0x2ebf6d0;
		constexpr const static size_t UpdateVelocity = 0x2ed0180;
		constexpr const static size_t Retire = 0x2ea9c10;
		constexpr const static size_t DoHit = 0x2e8ad90;
	}

	// obf name: ::%cc0d05925e988396ce5c7061709146bcce4cd796
#define HitInfo_ClassName "%cc0d05925e988396ce5c7061709146bcce4cd796"
#define HitInfo_ClassNameShort "%cc0d05925e988396ce5c7061709146bcce4cd796"
#define HitInfo_TypeDefinitionIndex 1367

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0xa8;
		constexpr const static size_t damageTypes = 0x60;

		// Functions
		constexpr const static size_t get_boneArea = 0x5614150;
	}

	// obf name: ::%75c39f95fe4f3dc2b13cedcdcb37a0265ad1bc48
#define GameTrace_ClassName "%75c39f95fe4f3dc2b13cedcdcb37a0265ad1bc48"
#define GameTrace_ClassNameShort "%75c39f95fe4f3dc2b13cedcdcb37a0265ad1bc48"
#define GameTrace_TypeDefinitionIndex 140

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x5500cc0;
	}

#define BaseMelee_TypeDefinitionIndex 4559

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x2f4d080;
		constexpr const static size_t DoThrow = 0x2f4e100;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 6747

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x408;
		constexpr const static size_t strikeRecoil = 0x410;
		constexpr const static size_t _didSparkThisFrame = 0x418;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 5735

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x420;
		constexpr const static size_t stringBonusVelocity = 0x42c;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x3ddc950;
	}

	// obf name: ::%36d7e123b092675af728cd2085f7270c23d6b062
#define ItemContainer_ClassName "%36d7e123b092675af728cd2085f7270c23d6b062"
#define ItemContainer_ClassNameShort "%36d7e123b092675af728cd2085f7270c23d6b062"
#define ItemContainer_TypeDefinitionIndex 2036

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x10;
		constexpr const static size_t itemList = 0x70;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x146fb40;
	}

#define PlayerLoot_TypeDefinitionIndex 818

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 6845

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerWear = 0x30;
		constexpr const static size_t containerMain = 0x38;
		constexpr const static size_t containerBelt = 0x78;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x4be9830;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 4491

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x2e88100;
		constexpr const static size_t get_rotation = 0x2e7ea20;
		constexpr const static size_t set_rotation = 0x2e8a450;
		constexpr const static size_t HeadForward = 0x2e74040;
	}

	// obf name: ::%bbe2fb88f74ae9647bb3a3973da37c01d297c955
#define PlayerEyes_Static_ClassName "PlayerEyes/%bbe2fb88f74ae9647bb3a3973da37c01d297c955"
#define PlayerEyes_Static_ClassNameShort "%bbe2fb88f74ae9647bb3a3973da37c01d297c955"
#define PlayerEyes_Static_TypeDefinitionIndex 4490

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x10;
	}

	// obf name: ::%0b9a157fb7749e20d4f91f86bc1a6c403f0387e5
#define PlayerBelt_ClassName "%0b9a157fb7749e20d4f91f86bc1a6c403f0387e5"
#define PlayerBelt_ClassNameShort "%0b9a157fb7749e20d4f91f86bc1a6c403f0387e5"
#define PlayerBelt_TypeDefinitionIndex 4600

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x2fc6d30;
		constexpr const static size_t GetActiveItem = 0x2fc72e0;
	}

	// obf name: ::%a1eedbff52323e5e6f11f2ec3b6d7c59786cb22b
#define LocalPlayer_ClassName "%a1eedbff52323e5e6f11f2ec3b6d7c59786cb22b"
#define LocalPlayer_ClassNameShort "%a1eedbff52323e5e6f11f2ec3b6d7c59786cb22b"
#define LocalPlayer_TypeDefinitionIndex 6760

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x4ae0430;
		constexpr const static size_t MoveItem = 0x4ae1870;
		constexpr const static size_t get_Entity = 0x4adf840;
	}

	// obf name: ::%9ae4b25b7b44af0b53e7d69047831550e465d052
#define LocalPlayer_Static_ClassName "%a1eedbff52323e5e6f11f2ec3b6d7c59786cb22b/%9ae4b25b7b44af0b53e7d69047831550e465d052"
#define LocalPlayer_Static_ClassNameShort "%9ae4b25b7b44af0b53e7d69047831550e465d052"
#define LocalPlayer_Static_TypeDefinitionIndex 6759

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0xe8;
	}

	// obf name: ::%ab3f19d091680a10470108fbeba4bf51f04e95d0
#define BasePlayer_Static_ClassName "BasePlayer/%ab3f19d091680a10470108fbeba4bf51f04e95d0"
#define BasePlayer_Static_ClassNameShort "%ab3f19d091680a10470108fbeba4bf51f04e95d0"
#define BasePlayer_Static_TypeDefinitionIndex 5822

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x4b8;
	}

#define BasePlayer_TypeDefinitionIndex 5823

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x4b8;
		constexpr const static size_t input = 0x400;
		constexpr const static size_t movement = 0x3c0;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x338;
		constexpr const static size_t playerFlags = 0x598;
		constexpr const static size_t eyes = 0x600;
		constexpr const static size_t playerRigidbody = 0x5f0;
		constexpr const static size_t userID = 0x5e0;
		constexpr const static size_t UserIDString = 0x5d0;
		constexpr const static size_t inventory = 0x5a0;
		constexpr const static size_t _displayName = 0x2b0;
		constexpr const static size_t _lookingAt = 0x298;
		constexpr const static size_t lastSentTickTime = 0x554;
		constexpr const static size_t lastSentTick = 0x478;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x458;
		constexpr const static size_t _lookingAtEntity = 0x350;
		constexpr const static size_t currentGesture = 0x5b8;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x3ee4b20;
		constexpr const static size_t Menu_AssistPlayer = 0x3ef9c90;
		constexpr const static size_t OnViewModeChanged = 0x3e83470;
		constexpr const static size_t ChatMessage = 0x3e9de90;
		constexpr const static size_t IsOnGround = 0x3e817c0;
		constexpr const static size_t GetSpeed = 0x3f73ac0;
		constexpr const static size_t SendProjectileUpdate = 0x3f82300;
		constexpr const static size_t SendProjectileAttack = 0x3f3a700;
		constexpr const static size_t CanBuild = 0x3f36ce0;
		constexpr const static size_t GetMounted = 0x3f73380;
		constexpr const static size_t GetHeldEntity = 0x3f6e5d0;
		constexpr const static size_t get_inventory = 0x3eeeec0;
		constexpr const static size_t get_eyes = 0x3f191e0;
		constexpr const static size_t SendClientTick = 0x3ec47e0;
		constexpr const static size_t ClientInput = 0x3ec8e40;
		constexpr const static size_t ClientInput_vtableoff = 0x38e8;
		constexpr const static size_t MaxHealth = 0x3eb4bc0;
		constexpr const static size_t MaxHealth_vtableoff = 0x18e8;
		constexpr const static size_t OnAttacked = 0x3fc50c0;
		constexpr const static size_t OnAttacked_vtableoff = 0x2b28;
	}

#define ScientistNPC_TypeDefinitionIndex 6573

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 7099

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 1281

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 2205

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 5104

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 2393

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 5450

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xf0;
		constexpr const static size_t ladder = 0xd8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x39bf900;
		constexpr const static size_t BlockSprint = 0x39e51a0;
		constexpr const static size_t GroundCheck = 0x39bac90;
		constexpr const static size_t ClientInput = 0x39efc40;
		constexpr const static size_t ClientInput_vtableoff = 0x3a8;
		constexpr const static size_t DoFixedUpdate = 0x39d9120;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x338;
		constexpr const static size_t FrameUpdate = 0x39d3d50;
		constexpr const static size_t FrameUpdate_vtableoff = 0x228;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 4425

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 314

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 3616

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 3386

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 3382

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%f9433d5e3fc696b7fd59377c0ab5b47de7e88ae6
#define ConsoleSystem_ClassName "%f9433d5e3fc696b7fd59377c0ab5b47de7e88ae6"
#define ConsoleSystem_ClassNameShort "%f9433d5e3fc696b7fd59377c0ab5b47de7e88ae6"
#define ConsoleSystem_TypeDefinitionIndex 23288

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x6560810;
	}

	// obf name: ::%938307b8371625205286bb0dece48e015c3b0824
#define ConsoleSystem_Index_Static_ClassName "%f9433d5e3fc696b7fd59377c0ab5b47de7e88ae6/%72924173af0c6cba446d644fe422a49ced3bc7aa.%938307b8371625205286bb0dece48e015c3b0824"
#define ConsoleSystem_Index_Static_ClassNameShort "%938307b8371625205286bb0dece48e015c3b0824"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23281

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0x70;
	}

#define LootableCorpse_TypeDefinitionIndex 415

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2a8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 5883

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 3078

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x98;
		constexpr const static size_t mainCameraTransform = 0x80;

		// Functions
		constexpr const static size_t Update = 0x1fb0340;
		constexpr const static size_t OnPreCull = 0x1fb1e10;
		constexpr const static size_t Trace = 0x1fbafa0;
	}

#define CameraMan_TypeDefinitionIndex 2598

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%566deef721befd19d0b1aca89a7899971449960d
#define PlayerTick_ClassName "%566deef721befd19d0b1aca89a7899971449960d"
#define PlayerTick_ClassNameShort "%566deef721befd19d0b1aca89a7899971449960d"
#define PlayerTick_TypeDefinitionIndex 7442

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x48;
		constexpr const static size_t modelState = 0x40;
		constexpr const static size_t activeItem = 0x10;
		constexpr const static size_t parentID = 0x18;
		constexpr const static size_t intermediatePosition = 0x58;
		constexpr const static size_t position = 0x20;
		constexpr const static size_t eyePos = 0x2c;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8b8f8b0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8b8f890;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%5906d1e45a0731bc0ebd1cdb0bb070d8a6b1c33a
#define InputMessage_ClassName "%5906d1e45a0731bc0ebd1cdb0bb070d8a6b1c33a"
#define InputMessage_ClassNameShort "%5906d1e45a0731bc0ebd1cdb0bb070d8a6b1c33a"
#define InputMessage_TypeDefinitionIndex 7474

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x20;
		constexpr const static size_t mouseDelta = 0x14;
		constexpr const static size_t aimAngles = 0x24;
	}

	// obf name: ::%7e25d9e1fd50b67629581dae3bde71886b22ed8f
#define InputState_ClassName "%7e25d9e1fd50b67629581dae3bde71886b22ed8f"
#define InputState_ClassNameShort "%7e25d9e1fd50b67629581dae3bde71886b22ed8f"
#define InputState_TypeDefinitionIndex 5226

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x20;
		constexpr const static size_t previous = 0x18;
	}

#define PlayerInput_TypeDefinitionIndex 6103

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%863c53e7c8b0f4c0ad5d00c79712ae963d9582a5
#define ModelState_ClassName "%863c53e7c8b0f4c0ad5d00c79712ae963d9582a5"
#define ModelState_ClassNameShort "%863c53e7c8b0f4c0ad5d00c79712ae963d9582a5"
#define ModelState_TypeDefinitionIndex 7527

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x78;
		constexpr const static size_t waterLevel = 0x7c;
		constexpr const static size_t lookDir = 0x20;
	}

	// obf name: ::%9819accb72414d87e4af9bc04b89245d7102c467
#define Item_ClassName "%9819accb72414d87e4af9bc04b89245d7102c467"
#define Item_ClassNameShort "%9819accb72414d87e4af9bc04b89245d7102c467"
#define Item_TypeDefinitionIndex 3205

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0x28;
		constexpr const static size_t uid = 0xd0;
		constexpr const static size_t _maxCondition = 0x90;
		constexpr const static size_t _condition = 0xe0;
		constexpr const static size_t amount = 0x68;
		constexpr const static size_t position = 0x9c;
		constexpr const static size_t contents = 0x48;
		constexpr const static size_t parent = 0xc0;
		constexpr const static size_t worldEnt = 0x30;
		constexpr const static size_t heldEntity = 0x80;

		// Functions
		constexpr const static size_t get_iconSprite = 0x20d9e90;
	}

	// obf name: ::%ced9cd63761e396c77180769e551c5ac2de349f6
#define WaterLevel_ClassName "%ced9cd63761e396c77180769e551c5ac2de349f6"
#define WaterLevel_ClassNameShort "%ced9cd63761e396c77180769e551c5ac2de349f6"
#define WaterLevel_TypeDefinitionIndex 183

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x14b9900;
		constexpr const static size_t GetWaterLevel = 0x149f9b0;
	}

	// obf name: ::%dac880420105b6db7bdcd20fb3a34c3d1603f845
#define ConVar_Graphics_Static_ClassName "%c26ade9fe63c415583ecc0c1c5da4beae9eebea9/%dac880420105b6db7bdcd20fb3a34c3d1603f845"
#define ConVar_Graphics_Static_ClassNameShort "%dac880420105b6db7bdcd20fb3a34c3d1603f845"
#define ConVar_Graphics_Static_TypeDefinitionIndex 4916

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x53c;

		// Functions
		constexpr const static size_t _fov_getter = 0x3100f70;
		constexpr const static size_t _fov_setter = 0x30f55d0;
	}

#define BaseFishingRod_TypeDefinitionIndex 5186

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
		constexpr const static size_t UpdateLineRenderer = 0x36c3650;
		constexpr const static size_t EvaluateFishingPosition = 0x36ce840;
	}

#define FishingBobber_TypeDefinitionIndex 3655

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 3529

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x250ab20;
	}

	// obf name: ::%d375126c5e2a1ae28a201b351dee4ded2f2b838e
#define GameManager_ClassName "%d375126c5e2a1ae28a201b351dee4ded2f2b838e"
#define GameManager_ClassNameShort "%d375126c5e2a1ae28a201b351dee4ded2f2b838e"
#define GameManager_TypeDefinitionIndex 3664

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x18;

		// Functions
		constexpr const static size_t CreatePrefab = 0x2710f40;
	}

	// obf name: ::%44cf5fb75ee3823a0bbdcff6adae90b605aa2cd4
#define GameManager_Static_ClassName "%d375126c5e2a1ae28a201b351dee4ded2f2b838e/%44cf5fb75ee3823a0bbdcff6adae90b605aa2cd4"
#define GameManager_Static_ClassNameShort "%44cf5fb75ee3823a0bbdcff6adae90b605aa2cd4"
#define GameManager_Static_TypeDefinitionIndex 3663

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x40;
	}

	// obf name: ::%c62625a8b26baa959b64a5afa58dd543feb1b0a9
#define PrefabPoolCollection_ClassName "%c62625a8b26baa959b64a5afa58dd543feb1b0a9"
#define PrefabPoolCollection_ClassNameShort "%c62625a8b26baa959b64a5afa58dd543feb1b0a9"
#define PrefabPoolCollection_TypeDefinitionIndex 342

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x10;
	}

	// obf name: ::%9bfe6b4556950154f1bf4e071bd8743c192fe032
#define PrefabPool_ClassName "%9bfe6b4556950154f1bf4e071bd8743c192fe032"
#define PrefabPool_ClassNameShort "%9bfe6b4556950154f1bf4e071bd8743c192fe032"
#define PrefabPool_TypeDefinitionIndex 4646

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x28;
	}

#define ItemModProjectile_TypeDefinitionIndex 3179

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

#define CraftingQueue_TypeDefinitionIndex 3324

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%55bbc443a8aa934b66f50b1ad3b51896a7e7c181
#define CraftingQueue_Static_ClassName "CraftingQueue/%55bbc443a8aa934b66f50b1ad3b51896a7e7c181"
#define CraftingQueue_Static_ClassNameShort "%55bbc443a8aa934b66f50b1ad3b51896a7e7c181"
#define CraftingQueue_Static_TypeDefinitionIndex 3323

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x40;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 2091

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%95567974f4fbc237ca7ca67c38c16dfcaf83f236
#define Planner_Static_ClassName "Planner/%95567974f4fbc237ca7ca67c38c16dfcaf83f236"
#define Planner_Static_ClassNameShort "%95567974f4fbc237ca7ca67c38c16dfcaf83f236"
#define Planner_Static_TypeDefinitionIndex 5323

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x188;
	}

	// obf name: ::%af62ce94e1b24f97d0cdb8e5420bee6bf02ddea0
#define Planner_Guide_ClassName "Planner/%af62ce94e1b24f97d0cdb8e5420bee6bf02ddea0"
#define Planner_Guide_ClassNameShort "%af62ce94e1b24f97d0cdb8e5420bee6bf02ddea0"
#define Planner_Guide_TypeDefinitionIndex 5319

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x60;
	}

#define Planner_TypeDefinitionIndex 5324

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x270;
	}

#define Construction_TypeDefinitionIndex 627

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x140;
	}

#define BuildingBlock_TypeDefinitionIndex 528

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x2c0;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 3566

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x2593970;
	}

	// obf name: ::%343afed6b89f4f5b0b9334edd8a977806cb8a932
#define PunchEntry_ClassName "HeldEntity/%343afed6b89f4f5b0b9334edd8a977806cb8a932"
#define PunchEntry_ClassNameShort "%343afed6b89f4f5b0b9334edd8a977806cb8a932"
#define PunchEntry_TypeDefinitionIndex 3564

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t duration = 0x28;
		constexpr const static size_t startTime = 0x2c;
		constexpr const static size_t amountAdded = 0x10;
		constexpr const static size_t amount = 0x1c;
	}

#define IronSights_TypeDefinitionIndex 5671

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 3658

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 5397

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xd0;
		constexpr const static size_t model = 0x80;
		constexpr const static size_t lower = 0xa8;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x39438a0;
	}

#define ViewModel_TypeDefinitionIndex 3558

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x2587070;
		constexpr const static size_t PlayString = 0x25868b0;
	}

#define MedicalTool_TypeDefinitionIndex 2587

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 5488

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x68;
	}

	// obf name: ::%ea53bb066ae4750c69cf2bafe1447ae1967d95d2
#define WaterSystem_Static_ClassName "WaterSystem/%ea53bb066ae4750c69cf2bafe1447ae1967d95d2"
#define WaterSystem_Static_ClassNameShort "%ea53bb066ae4750c69cf2bafe1447ae1967d95d2"
#define WaterSystem_Static_TypeDefinitionIndex 1519

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x190;
	}

#define WaterSystem_TypeDefinitionIndex 1520

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0xf6e8e0;
	}

#define TerrainMeta_TypeDefinitionIndex 758

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x90;
		constexpr const static size_t HeightMap = 0x408;
		constexpr const static size_t SplatMap = 0x6c8;
		constexpr const static size_t TopologyMap = 0x740;
		constexpr const static size_t Texturing = 0x458;
	}

#define TerrainCollision_TypeDefinitionIndex 4086

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x2aecd50;
	}

#define TerrainHeightMap_TypeDefinitionIndex 3963

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 5375

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 884

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%33877b94dc6b1a6aa4c19ed51b71049f334a18e5
#define World_Static_ClassName "%428bbddf5342e65a14e8a6ae1a6e08413e2eae17/%33877b94dc6b1a6aa4c19ed51b71049f334a18e5"
#define World_Static_ClassNameShort "%33877b94dc6b1a6aa4c19ed51b71049f334a18e5"
#define World_Static_TypeDefinitionIndex 5159

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x84;
	}

#define ItemIcon_TypeDefinitionIndex 2562

	namespace ItemIcon {

		// Functions
		constexpr const static size_t TryToMove = 0x1a2a960;
		constexpr const static size_t TryToMove_vtableoff = 0x3a8;
		constexpr const static size_t RunTimedAction = 0x1a38f10;
	}

	// obf name: ::%09a6ff1c62d9e985728b755018954145e233b3ff
#define ItemIcon_Static_ClassName "ItemIcon/%09a6ff1c62d9e985728b755018954145e233b3ff"
#define ItemIcon_Static_ClassNameShort "%09a6ff1c62d9e985728b755018954145e233b3ff"
#define ItemIcon_Static_TypeDefinitionIndex 2561

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x38;
	}

	// obf name: ::%40109567c73f313907809a163956ebb8a0c2385a
#define Effect_ClassName "%40109567c73f313907809a163956ebb8a0c2385a"
#define Effect_ClassNameShort "%40109567c73f313907809a163956ebb8a0c2385a"
#define Effect_TypeDefinitionIndex 233

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x70;
		constexpr const static size_t worldPos = 0x58;
	}

	// obf name: ::%c30f1c5c7eed4757709c4b27ced3651f49067266
#define EffectLibrary_ClassName "%c30f1c5c7eed4757709c4b27ced3651f49067266"
#define EffectLibrary_ClassNameShort "%c30f1c5c7eed4757709c4b27ced3651f49067266"
#define EffectLibrary_TypeDefinitionIndex 2072

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x154af00;
	}

	// obf name: ::%a0f0c1b209643d1d5a542a9809f35916c1ef2f3a
#define EffectNetwork_ClassName "%a0f0c1b209643d1d5a542a9809f35916c1ef2f3a"
#define EffectNetwork_ClassNameShort "%a0f0c1b209643d1d5a542a9809f35916c1ef2f3a"
#define EffectNetwork_TypeDefinitionIndex 5256

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%fc447d9eead5ae38836d5dd1cfb10caf8f8301fb
#define EffectNetwork_Static_ClassName "%a0f0c1b209643d1d5a542a9809f35916c1ef2f3a/%fc447d9eead5ae38836d5dd1cfb10caf8f8301fb"
#define EffectNetwork_Static_ClassNameShort "%fc447d9eead5ae38836d5dd1cfb10caf8f8301fb"
#define EffectNetwork_Static_TypeDefinitionIndex 5255

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x28;

		// Functions
		constexpr const static size_t cctor = 0x377cc20;
	}

#define BuildingBlock_TypeDefinitionIndex 528

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x3b2f5e0;
		constexpr const static size_t HasUpgradePrivilege = 0x3b3d730;
		constexpr const static size_t CanAffordUpgrade = 0x3b400d0;
	}

	// obf name: ::%cbf49fc74daccf31f3afff8698b147e7a6bae432
#define GameObjectEx_ClassName "%cbf49fc74daccf31f3afff8698b147e7a6bae432"
#define GameObjectEx_ClassNameShort "%cbf49fc74daccf31f3afff8698b147e7a6bae432"
#define GameObjectEx_TypeDefinitionIndex 4606

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x2fd8e20;
	}

#define UIDeathScreen_TypeDefinitionIndex 6861

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x4c26180;
	}

	// obf name: ::%4d00c7c55ea599ced05da8c28a2cf049d9c551f6
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%4d00c7c55ea599ced05da8c28a2cf049d9c551f6"
#define BaseScreenShake_Static_ClassNameShort "%4d00c7c55ea599ced05da8c28a2cf049d9c551f6"
#define BaseScreenShake_Static_TypeDefinitionIndex 2894

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0xe0;
	}

#define FlashbangOverlay_TypeDefinitionIndex 6721

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x8;
		constexpr const static size_t flashLength = 0x40;
	}

	// obf name: ::%5dcc8a4850bfffe3177a457693684e957bdd7fcf
#define StringPool_ClassName "%5dcc8a4850bfffe3177a457693684e957bdd7fcf"
#define StringPool_ClassNameShort "%5dcc8a4850bfffe3177a457693684e957bdd7fcf"
#define StringPool_TypeDefinitionIndex 2031

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x10;

		// Functions
		constexpr const static size_t Get = 0x14e6bd0;
	}

	// obf name: ::%87136cd4758d4d9d7b83f9cf1cbffbb0612849a8
#define Network_Networkable_ClassName "%87136cd4758d4d9d7b83f9cf1cbffbb0612849a8"
#define Network_Networkable_ClassNameShort "%87136cd4758d4d9d7b83f9cf1cbffbb0612849a8"
#define Network_Networkable_TypeDefinitionIndex 19113

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x40;
	}

	// obf name: ::%36bea7d213d6021a3639561bc46b14a6eb977160
#define Network_Net_ClassName "%36bea7d213d6021a3639561bc46b14a6eb977160"
#define Network_Net_ClassNameShort "%36bea7d213d6021a3639561bc46b14a6eb977160"
#define Network_Net_TypeDefinitionIndex 8348

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x68;
	}

	// obf name: ::%1dada362a286f96cdb18fbc52c841e002e9c297d
#define Network_Client_ClassName "%1dada362a286f96cdb18fbc52c841e002e9c297d"
#define Network_Client_ClassNameShort "%1dada362a286f96cdb18fbc52c841e002e9c297d"
#define Network_Client_TypeDefinitionIndex 19147

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf8;
		constexpr const static size_t ConnectedPort = 0xf0;
		constexpr const static size_t ConnectedAddress = 0x108;
		constexpr const static size_t ServerName = 0x118;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x6629440;
		constexpr const static size_t DestroyNetworkable = 0x6628890;
	}

	// obf name: ::%63ab77c2a7a4c4ddc28249e256cd5b420766f594
#define Network_BaseNetwork_ClassName "%63ab77c2a7a4c4ddc28249e256cd5b420766f594"
#define Network_BaseNetwork_ClassNameShort "%63ab77c2a7a4c4ddc28249e256cd5b420766f594"
#define Network_BaseNetwork_TypeDefinitionIndex 19110

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x65dd1e0;
	}

	// obf name: ::%bfd8be22c19b6af2523ba8f1269f707692c93820
#define Network_SendInfo_ClassName "%bfd8be22c19b6af2523ba8f1269f707692c93820"
#define Network_SendInfo_ClassNameShort "%bfd8be22c19b6af2523ba8f1269f707692c93820"
#define Network_SendInfo_TypeDefinitionIndex 19107

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%200e586bd98fa6e705c88a76162db5827c017c3d
#define Network_Message_ClassName "%200e586bd98fa6e705c88a76162db5827c017c3d"
#define Network_Message_ClassNameShort "%200e586bd98fa6e705c88a76162db5827c017c3d"
#define Network_Message_TypeDefinitionIndex 19128

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x20;
		constexpr const static size_t read = 0x18;
	}

	// obf name: ::%11eee7ca43b2338f6c7cbfd9a3fa4c22d1f94f94
#define Network_NetRead_ClassName "%11eee7ca43b2338f6c7cbfd9a3fa4c22d1f94f94"
#define Network_NetRead_ClassNameShort "%11eee7ca43b2338f6c7cbfd9a3fa4c22d1f94f94"
#define Network_NetRead_TypeDefinitionIndex 19165

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x48;
	}

	// obf name: ::%d59093d976af397ba070b16e63b4c2f90ae48d2d
#define Network_NetWrite_ClassName "%d59093d976af397ba070b16e63b4c2f90ae48d2d"
#define Network_NetWrite_ClassNameShort "%d59093d976af397ba070b16e63b4c2f90ae48d2d"
#define Network_NetWrite_TypeDefinitionIndex 19141

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x30;

		// Functions
		constexpr const static size_t WriteByte = 0x661e390;
		constexpr const static size_t String = 0x66202d0;
		constexpr const static size_t Send = 0x6624580;
	}

#define LootPanel_TypeDefinitionIndex 751

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x4fa9770;
	}

#define UIInventory_TypeDefinitionIndex 3416

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x24257b0;
	}

#define GrowableEntity_TypeDefinitionIndex 739

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 4080

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 4079

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 20986

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 7851

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
		constexpr const static size_t get_Instance = 0xd6dd40;
	}

	// obf name: ::%04086b32262206f453c36861c64176bda803acc1
#define TOD_Sky_Static_ClassName "TOD_Sky/%04086b32262206f453c36861c64176bda803acc1"
#define TOD_Sky_Static_ClassNameShort "%04086b32262206f453c36861c64176bda803acc1"
#define TOD_Sky_Static_TypeDefinitionIndex 7850

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0x78;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 7726

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0xab0f80;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 8860

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 9570

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 9759

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 8565

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 7771

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 7859

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 5866

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 2881

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 4561

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 5349

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

#define EnvironmentManager_TypeDefinitionIndex 773

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x4ff36d0;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%735a05baa3e42b0976d8057c71b5ba09f572be39/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24044

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 2208

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 2209

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 2104

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
		constexpr const static size_t InstanceList = 0x38;
	}

	// obf name: ::%97e0566bc74b8392d891dd0749a85699c2ff6ffc
#define ListHashSet_ClassName "%97e0566bc74b8392d891dd0749a85699c2ff6ffc<UIChat>"
#define ListHashSet_ClassNameShort "%97e0566bc74b8392d891dd0749a85699c2ff6ffc"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x18;
	}

#define PatrolHelicopter_TypeDefinitionIndex 5670

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3e8;
	}

#define Chainsaw_TypeDefinitionIndex 179

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x37c;
	}

	// obf name: ::%1ff126d65a8ced40923e9d380a6764ec008725f5
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%1ff126d65a8ced40923e9d380a6764ec008725f5"
#define CameraUpdateHook_Static_ClassNameShort "%1ff126d65a8ced40923e9d380a6764ec008725f5"
#define CameraUpdateHook_Static_TypeDefinitionIndex 4895

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x10;
	}

#define SteamClientWrapper_TypeDefinitionIndex 106

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x53380c0;
	}

	// obf name: ::%6502298fbe01ec88cca17d92483c19a2a18b1c5c
#define AimConeUtil_ClassName "%6502298fbe01ec88cca17d92483c19a2a18b1c5c"
#define AimConeUtil_ClassNameShort "%6502298fbe01ec88cca17d92483c19a2a18b1c5c"
#define AimConeUtil_TypeDefinitionIndex 5533

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x3ac36b0;
	}

	// obf name: ::%2858383dc197d5c9b7b3104f1068f76fbed62744
#define Buttons_ConButton_ClassName "%710a8a9c4f23b10e5cfdd3c079b3440a7078c302/%2858383dc197d5c9b7b3104f1068f76fbed62744"
#define Buttons_ConButton_ClassNameShort "%2858383dc197d5c9b7b3104f1068f76fbed62744"
#define Buttons_ConButton_TypeDefinitionIndex 6127

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x18;
	}

	// obf name: ::%017aeabbfef7d916dbb58f81b8a641ddbc0fb2dd
#define Buttons_Static_ClassName "%710a8a9c4f23b10e5cfdd3c079b3440a7078c302/%017aeabbfef7d916dbb58f81b8a641ddbc0fb2dd"
#define Buttons_Static_ClassNameShort "%017aeabbfef7d916dbb58f81b8a641ddbc0fb2dd"
#define Buttons_Static_TypeDefinitionIndex 6128

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0x60;
		constexpr const static size_t Attack = 0xee0;
		constexpr const static size_t Attack2 = 0x268;
		constexpr const static size_t Forward = 0x2d8;
		constexpr const static size_t Backward = 0x960;
		constexpr const static size_t Right = 0x90;
		constexpr const static size_t Left = 0xf70;
		constexpr const static size_t Sprint = 0xc80;

		// Functions
		constexpr const static size_t Pets_setter = 0x3108d80;
	}

#define PlayerModel_TypeDefinitionIndex 1122

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x278;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 339

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x40;
	}

#define BaseMountable_TypeDefinitionIndex 4126

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 2498

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x0;
		constexpr const static size_t timeCounter = 0x2c;
	}

#define BowWeapon_TypeDefinitionIndex 2691

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x408;
		constexpr const static size_t wasAiming = 0x418;
	}

#define CrossbowWeapon_TypeDefinitionIndex 6941

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 6008

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%ef3996b71bbbecd430b7d1debf8063360cf22711
#define ConVar_Admin_Static_ClassName "%a69d98dc5d4cbe86218acea600ab0924fb38b338/%ef3996b71bbbecd430b7d1debf8063360cf22711"
#define ConVar_Admin_Static_ClassNameShort "%ef3996b71bbbecd430b7d1debf8063360cf22711"
#define ConVar_Admin_Static_TypeDefinitionIndex 6290

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0xb4;

		// Functions
		constexpr const static size_t admintime_getter = 0x3102fd0;
		constexpr const static size_t admintime_setter = 0x31075b0;
	}

	// obf name: ::%90d5736c865e00523af47b248cd14134e34d2503
#define ConVar_Player_Static_ClassName "%fd315e02ce42cccab174c65ed98825db53cf8779/%90d5736c865e00523af47b248cd14134e34d2503"
#define ConVar_Player_Static_ClassNameShort "%90d5736c865e00523af47b248cd14134e34d2503"
#define ConVar_Player_Static_TypeDefinitionIndex 3453

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x184;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x30e82d0;
		constexpr const static size_t clientTickRate_setter = 0x30e7390;
	}

#define ColliderInfo_TypeDefinitionIndex 1795

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 637

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 578

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x370;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x4244540;
	}

#define Client_TypeDefinitionIndex 5968

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x41c76c0;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%d0652da2635ea5970f30ffc1438a3b2dfc42fdc5
#define ItemManager_Static_ClassName "%cc190de3f512b4f45ddc5f793abe2e485a0d2baa/%d0652da2635ea5970f30ffc1438a3b2dfc42fdc5"
#define ItemManager_Static_ClassNameShort "%d0652da2635ea5970f30ffc1438a3b2dfc42fdc5"
#define ItemManager_Static_TypeDefinitionIndex 4487

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x10;
		constexpr const static size_t itemDictionary = 0x48;
		constexpr const static size_t itemDictionaryByName = 0x1f8;
	}

	// obf name: ::%90a1182d92ff37638090a5d216bff9b168c84928
#define ConVar_Server_Static_ClassName "%ec2f284948dc0b566c3ef4a6d72f7f6ed28abad3/%90a1182d92ff37638090a5d216bff9b168c84928"
#define ConVar_Server_Static_ClassNameShort "%90a1182d92ff37638090a5d216bff9b168c84928"
#define ConVar_Server_Static_TypeDefinitionIndex 6026

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 4191

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x2c008d0;
	}

#define LoadingScreen_TypeDefinitionIndex 5924

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x28;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 2446

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%b99ed40c8da55f878b8ee2ca2069ff313acea07b"
#define MapView_Static_ClassNameShort "%b99ed40c8da55f878b8ee2ca2069ff313acea07b"
#define MapView_TypeDefinitionIndex 3420

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0x23a6490;
	}

	// obf name: ::%953865e654f97be99f806a3e08ee7855b5a39910
#define GamePhysics_Static_ClassName "%e0399ef130d08cd0c9d3691ac8ffeeef8bfbe06c/%953865e654f97be99f806a3e08ee7855b5a39910"
#define GamePhysics_Static_ClassNameShort "%953865e654f97be99f806a3e08ee7855b5a39910"
#define GamePhysics_Static_TypeDefinitionIndex 6673

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x10;
	}

	// obf name: ::%e0399ef130d08cd0c9d3691ac8ffeeef8bfbe06c
#define GamePhysics_ClassName "%e0399ef130d08cd0c9d3691ac8ffeeef8bfbe06c"
#define GamePhysics_ClassNameShort "%e0399ef130d08cd0c9d3691ac8ffeeef8bfbe06c"
#define GamePhysics_TypeDefinitionIndex 6674

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x4a27570;
		constexpr const static size_t LineOfSightInternal = 0x49f8ef0;
		constexpr const static size_t Verify = 0x4a035e0;
	}

#define DDraw_TypeDefinitionIndex 45

	namespace DDraw {

		// Functions
		constexpr const static size_t Sphere = 0x1d5b100;
		constexpr const static size_t Line = 0x1d56f50;
	}

	// obf name: ::%940725a7cab919ac542f91379d6f3799100a7913
#define RaycastHitEx_ClassName "%940725a7cab919ac542f91379d6f3799100a7913"
#define RaycastHitEx_ClassNameShort "%940725a7cab919ac542f91379d6f3799100a7913"
#define RaycastHitEx_TypeDefinitionIndex 9

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0xe5d7b0;
	}

	// obf name: ::%362e27f533ed5180d7a3a6a44b1061a2b347ad25
#define OnParentDestroyingEx_ClassName "%362e27f533ed5180d7a3a6a44b1061a2b347ad25"
#define OnParentDestroyingEx_ClassNameShort "%362e27f533ed5180d7a3a6a44b1061a2b347ad25"
#define OnParentDestroyingEx_TypeDefinitionIndex 467

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x36598c0;
	}

	// obf name: ::%4c11abdbd766af85fa2405b000325bb010392069
#define ConsoleNetwork_ClassName "%4c11abdbd766af85fa2405b000325bb010392069"
#define ConsoleNetwork_ClassNameShort "%4c11abdbd766af85fa2405b000325bb010392069"
#define ConsoleNetwork_TypeDefinitionIndex 4633

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x300f5b0;
	}

#define ThrownWeapon_TypeDefinitionIndex 5622

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 5164

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 5661

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 3420

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 3488

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 3431

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 1717

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 4493

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 5627

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 1188

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%2f07ef73e99d45be6ec865fa6f9c86aa23430a69
#define ConVar_Client_Static_ClassName "%8e43a6b07aa195557da5c1a4574894f86c86a2db/%2f07ef73e99d45be6ec865fa6f9c86aa23430a69"
#define ConVar_Client_Static_ClassNameShort "%2f07ef73e99d45be6ec865fa6f9c86aa23430a69"
#define ConVar_Client_Static_TypeDefinitionIndex 3426

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x504;
		constexpr const static size_t camspeed = 0x164;
	}

#define SamSite_TypeDefinitionIndex 5303

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 494

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 81

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x20;
	}

#define FoliageGrid_TypeDefinitionIndex 6374

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 1488

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 979

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 7108

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 2982

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%e7925fde62e86093b5a8e578ecd35a0f1f02a942
#define Facepunch_Network_Raknet_Client_ClassName "%e7925fde62e86093b5a8e578ecd35a0f1f02a942"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%e7925fde62e86093b5a8e578ecd35a0f1f02a942"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 22783

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x667ffe0;
		constexpr const static size_t IsConnected_vtableoff = 0x3d8;
	}

	// obf name: ::%0541fea8ee90f47c90854d240321fc381ea45cf5
#define EncryptedValue_ClassName "%0541fea8ee90f47c90854d240321fc381ea45cf5<System/Int32>"
#define EncryptedValue_ClassNameShort "%0541fea8ee90f47c90854d240321fc381ea45cf5"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%a053e0bfb04404b1d0d58304526510cb3b1f38a0
#define HiddenValue_ClassName "%a053e0bfb04404b1d0d58304526510cb3b1f38a0<BaseNetworkable/%0002eeb2d61933eabb395cb5df21eb33519bef29>"
#define HiddenValue_ClassNameShort "%a053e0bfb04404b1d0d58304526510cb3b1f38a0"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex 2355

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x1849100;
	}

#define ItemModRFListener_TypeDefinitionIndex 5804

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x3e798a0;
	}

#define UIFogOverlay_TypeDefinitionIndex 81

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x28;
	}

	// obf name: ::%c6c27d04b621be0b6b879dda6fb7f3eb6582af69
#define BufferStream_ClassName "%c6c27d04b621be0b6b879dda6fb7f3eb6582af69"
#define BufferStream_ClassNameShort "%c6c27d04b621be0b6b879dda6fb7f3eb6582af69"
#define BufferStream_TypeDefinitionIndex 7195

	namespace BufferStream {

		// Functions
		constexpr const static size_t EnsureCapacity = 0x91ecd20;
	}

#define FreeableLootContainer_TypeDefinitionIndex 7046

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 1551

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 4226

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x2c796d0;
	}

#define OutlineManager_TypeDefinitionIndex 3343

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%aa7e508a88d1a370fb908bf1c2b0dd4cc5f1fb83
#define ConsoleSystem_Command_ClassName "%f9433d5e3fc696b7fd59377c0ab5b47de7e88ae6/%aa7e508a88d1a370fb908bf1c2b0dd4cc5f1fb83"
#define ConsoleSystem_Command_ClassNameShort "%aa7e508a88d1a370fb908bf1c2b0dd4cc5f1fb83"
#define ConsoleSystem_Command_TypeDefinitionIndex 23273

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x68;
		constexpr const static size_t SetOveride = 0x20;
		constexpr const static size_t Call = 0x28;
	}

	// obf name: ::%d3019976d88be6621b3378fc35fc4a4afd7d43a4
#define ConsoleSystem_Option_ClassName "%f9433d5e3fc696b7fd59377c0ab5b47de7e88ae6/%d3019976d88be6621b3378fc35fc4a4afd7d43a4"
#define ConsoleSystem_Option_ClassNameShort "%d3019976d88be6621b3378fc35fc4a4afd7d43a4"
#define ConsoleSystem_Option_TypeDefinitionIndex 23283

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%c3c89576fa22f0392184d992d8a8210bf3920527
#define ConsoleSystem_Arg_ClassName "%f9433d5e3fc696b7fd59377c0ab5b47de7e88ae6/%c3c89576fa22f0392184d992d8a8210bf3920527"
#define ConsoleSystem_Arg_ClassNameShort "%c3c89576fa22f0392184d992d8a8210bf3920527"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23271

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x28;
	}

	// obf name: ::%6c715152330f8a6a93675d928e33860b88478031
#define ConsoleSystem_Index_Client_ClassName "%f9433d5e3fc696b7fd59377c0ab5b47de7e88ae6/%72924173af0c6cba446d644fe422a49ced3bc7aa.%6c715152330f8a6a93675d928e33860b88478031"
#define ConsoleSystem_Index_Client_ClassNameShort "%6c715152330f8a6a93675d928e33860b88478031"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23279

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x6569780;
	}

#define String_TypeDefinitionIndex 10203

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x8737520;
	}

	// obf name: ::%dee5f1c0ddf073be782de3b213cedde642740f18
#define EntityRef_ClassName "%dee5f1c0ddf073be782de3b213cedde642740f18"
#define EntityRef_ClassNameShort "%dee5f1c0ddf073be782de3b213cedde642740f18"
#define EntityRef_TypeDefinitionIndex 610

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x499a300;
	}

	// obf name: ::%fdceccafd6eb8c00942e419cdf18d4fe7fc292aa
#define ProtoBuf_ProjectileShoot_ClassName "%fdceccafd6eb8c00942e419cdf18d4fe7fc292aa"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%fdceccafd6eb8c00942e419cdf18d4fe7fc292aa"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7366

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9a3dc00;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9a3ead0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%c1e36e5c39c3364c676374a6cdae46f82d8eb4d8
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%fdceccafd6eb8c00942e419cdf18d4fe7fc292aa/%c1e36e5c39c3364c676374a6cdae46f82d8eb4d8"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%c1e36e5c39c3364c676374a6cdae46f82d8eb4d8"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7365

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x1c;
		constexpr const static size_t startPos = 0x24;
		constexpr const static size_t startVel = 0x10;
		constexpr const static size_t seed = 0x30;
	}

	// obf name: ::%17a13a45d1784a23f9da109937c0567ec05a6b67
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%17a13a45d1784a23f9da109937c0567ec05a6b67"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%17a13a45d1784a23f9da109937c0567ec05a6b67"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7613

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x2c;
		constexpr const static size_t curPosition = 0x20;
		constexpr const static size_t curVelocity = 0x10;
		constexpr const static size_t travelTime = 0x30;
		constexpr const static size_t ShouldPool = 0x1c;

		// Functions
		constexpr const static size_t Dispose = 0x9232430;
		constexpr const static size_t WriteToStreamDelta = 0x92309d0;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9232360;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%ae7f2e2f76e4d0aff5a96b8f65ea67868f0f9298
#define ProtoBuf_PlayerProjectileAttack_ClassName "%ae7f2e2f76e4d0aff5a96b8f65ea67868f0f9298"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%ae7f2e2f76e4d0aff5a96b8f65ea67868f0f9298"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7477

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x2c;
		constexpr const static size_t hitDistance = 0x28;
		constexpr const static size_t travelTime = 0x14;
		constexpr const static size_t playerAttack = 0x20;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8cc3730;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8cc1920;
		constexpr const static size_t WriteToStream_vtableoff = 0x1d8;
	}

	// obf name: ::%664411392a2565602a95eec88e01009f9b3946ad
#define ProtoBuf_PlayerAttack_ClassName "%664411392a2565602a95eec88e01009f9b3946ad"
#define ProtoBuf_PlayerAttack_ClassNameShort "%664411392a2565602a95eec88e01009f9b3946ad"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7441

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%fa3fadd847b4fc75e6e2380af9d1ffe29039fdb8
#define ProtoBuf_Attack_ClassName "%fa3fadd847b4fc75e6e2380af9d1ffe29039fdb8"
#define ProtoBuf_Attack_ClassNameShort "%fa3fadd847b4fc75e6e2380af9d1ffe29039fdb8"
#define ProtoBuf_Attack_TypeDefinitionIndex 7291

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x58;
		constexpr const static size_t pointEnd = 0x1c;
		constexpr const static size_t hitID = 0x40;
		constexpr const static size_t hitBone = 0x64;
		constexpr const static size_t hitNormalLocal = 0x78;
		constexpr const static size_t hitPositionLocal = 0x48;
		constexpr const static size_t hitNormalWorld = 0x28;
		constexpr const static size_t hitPositionWorld = 0x6c;
		constexpr const static size_t hitPartID = 0x68;
		constexpr const static size_t hitMaterialID = 0x84;
		constexpr const static size_t srcParentID = 0x38;
		constexpr const static size_t dstParentID = 0x10;
	}
}