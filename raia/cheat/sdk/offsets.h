#pragma once

#include "offsets_manual.h"

namespace Offsets {
	namespace GameAssembly {
		constexpr const static size_t timestamp = 0x690c8e06;
		constexpr const static size_t gc_handles = 0xd460b50;
		constexpr const static size_t il2cpp_resolve_icall = 0x5afb80;
		constexpr const static size_t il2cpp_array_new = 0x5afba0;
		constexpr const static size_t il2cpp_assembly_get_image = 0x4b280;
		constexpr const static size_t il2cpp_class_from_name = 0x5afd10;
		constexpr const static size_t il2cpp_class_get_method_from_name = 0x5b0020;
		constexpr const static size_t il2cpp_class_get_type = 0x5b00c0;
		constexpr const static size_t il2cpp_domain_get = 0x5b0620;
		constexpr const static size_t il2cpp_domain_get_assemblies = 0x5b0640;
		constexpr const static size_t il2cpp_gchandle_get_target = 0x5b0f00;
		constexpr const static size_t il2cpp_gchandle_new = 0x5b0eb0;
		constexpr const static size_t il2cpp_gchandle_free = 0x5b0fa0;
		constexpr const static size_t il2cpp_method_get_name = 0x2d90;
		constexpr const static size_t il2cpp_object_new = 0x5b1650;
		constexpr const static size_t il2cpp_type_get_object = 0x5b1e40;
	}

#define Object_TypeDefinitionIndex 17063

	namespace Object {

		// Offsets
		constexpr const static size_t m_CachedPtr = 0x10;

		// Functions
		constexpr const static size_t GetInstanceID = 0xaec6460;
		constexpr const static size_t Destroy = 0x104400;
		constexpr const static size_t DestroyImmediate = 0x104590;
		constexpr const static size_t DontDestroyOnLoad = 0x104d10;
		constexpr const static size_t FindObjectFromInstanceID = 0x106b70;
		constexpr const static size_t GetName = 0x1064b0;
		constexpr const static size_t get_hideFlags = 0x104e50;
		constexpr const static size_t set_hideFlags = 0x104f80;
	}

#define GameObject_TypeDefinitionIndex 17034

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

#define Component_TypeDefinitionIndex 17021

	namespace Component {

		// Functions
		constexpr const static size_t get_gameObject = 0xf7b70;
		constexpr const static size_t get_transform = 0xf77d0;
	}

#define Behaviour_TypeDefinitionIndex 17015

	namespace Behaviour {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t set_enabled = 0xa1de0;
	}

#define Transform_TypeDefinitionIndex 17098

	namespace Transform {

		// Functions
		constexpr const static size_t get_eulerAngles = 0xaed1f80;
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

#define Camera_TypeDefinitionIndex 16813

	namespace Camera {

		// Functions
		constexpr const static size_t WorldToScreenPoint_Injected = 0x6f800;
		constexpr const static size_t GetAllCamerasCount = 0x72b30;
		constexpr const static size_t CopyFrom = 0x73ce0;
		constexpr const static size_t set_cullingMask = 0x67710;
		constexpr const static size_t set_clearFlags = 0x692c0;
		constexpr const static size_t set_backgroundColor_Injected = 0x69040;
		constexpr const static size_t set_targetTexture = 0x6d950;
		constexpr const static size_t Render = 0x73270;
		constexpr const static size_t RenderWithShader = 0x733b0;
	}

#define Time_TypeDefinitionIndex 17085

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

#define Material_TypeDefinitionIndex 16876

	namespace Material {

		// Functions
		constexpr const static size_t SetFloatImpl = 0xb6da0;
		constexpr const static size_t SetColorImpl_Injected = 0xb6ee0;
		constexpr const static size_t SetTextureImpl = 0xb7140;
		constexpr const static size_t CreateWithMaterial = 0xaf1c0;
		constexpr const static size_t CreateWithShader = 0xaf050;
		constexpr const static size_t SetBufferImpl = 0xb7490;
		constexpr const static size_t set_shader = 0xaf740;
		constexpr const static size_t get_shader = 0xaf5e0;
	}

#define MaterialPropertyBlock_TypeDefinitionIndex 16872

	namespace MaterialPropertyBlock {

		// Functions
		constexpr const static size_t ctor = 0xae86320;
		constexpr const static size_t SetFloatImpl = 0x9bed0;
		constexpr const static size_t SetTextureImpl = 0x9c1c0;
	}

#define Shader_TypeDefinitionIndex 16875

	namespace Shader {

		// Functions
		constexpr const static size_t Find = 0xae89920;
		constexpr const static size_t PropertyToID = 0xaa6a0;
		constexpr const static size_t GetPropertyCount = 0xaea30;
		constexpr const static size_t GetPropertyName = 0xad8f0;
		constexpr const static size_t GetPropertyType = 0xadb90;
	}

#define Mesh_TypeDefinitionIndex 16931

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

#define Renderer_TypeDefinitionIndex 16873

	namespace Renderer {

		// Functions
		constexpr const static size_t get_enabled = 0xa1cb0;
		constexpr const static size_t get_isVisible = 0xa1f20;
		constexpr const static size_t GetMaterial = 0x9ffe0;
		constexpr const static size_t GetMaterialArray = 0xa0470;
	}

#define Texture_TypeDefinitionIndex 16934

	namespace Texture {

		// Functions
		constexpr const static size_t set_filterMode = 0xda5e0;
		constexpr const static size_t GetNativeTexturePtr = 0xdab00;
	}

#define Texture2D_TypeDefinitionIndex 16936

	namespace Texture2D {

		// Functions
		constexpr const static size_t ctor = 0xae9fa60;
		constexpr const static size_t Internal_CreateImpl = 0xdc200;
		constexpr const static size_t GetRawImageDataSize = 0xde1e0;
		constexpr const static size_t GetWritableImageData = 0xde090;
		constexpr const static size_t ApplyImpl = 0xdc5e0;
	}

#define Sprite_TypeDefinitionIndex 17104

	namespace Sprite {

		// Functions
		constexpr const static size_t get_texture = 0x119300;
	}

#define RenderTexture_TypeDefinitionIndex 16941

	namespace RenderTexture {

		// Functions
		constexpr const static size_t GetTemporary = 0xaea86a0;
		constexpr const static size_t ReleaseTemporary = 0xe9390;
	}

#define CommandBuffer_TypeDefinitionIndex 17411

	namespace CommandBuffer {

		// Functions
		constexpr const static size_t ctor = 0xaeec860;
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

#define RenderTargetIdentifier_TypeDefinitionIndex 17387

	namespace RenderTargetIdentifier {

		// Functions
		constexpr const static size_t ctor = 0xaee6680;
	}

#define ComputeBuffer_TypeDefinitionIndex 17076

	namespace ComputeBuffer {

		// Functions
		constexpr const static size_t ctor = 0xaec9fc0;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Release = 0xaeca210;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define GraphicsBuffer_TypeDefinitionIndex 16880

	namespace GraphicsBuffer {

		// Functions
		constexpr const static size_t ctor = 0xae90b70;
		constexpr const static size_t get_count = 0x7c6b0;
		constexpr const static size_t Dispose = 0xae908d0;
		constexpr const static size_t InternalSetNativeData = 0xbb930;
	}

#define Event_TypeDefinitionIndex 22299

	namespace Event {

		// Functions
		constexpr const static size_t get_current = 0xaf0f0c0;
		constexpr const static size_t get_type = 0x23a320;
		constexpr const static size_t PopEvent = 0x23b060;
		constexpr const static size_t Internal_Use = 0x23ac60;
	}

#define Graphics_TypeDefinitionIndex 16853

	namespace Graphics {

		// Functions
		constexpr const static size_t Internal_BlitMaterial5 = 0x86e00;
		constexpr const static size_t ExecuteCommandBuffer = 0x89bb0;
	}

#define Matrix4x4_TypeDefinitionIndex 16964

	namespace Matrix4x4 {

		// Functions
		constexpr const static size_t Ortho_Injected = 0xef280;
	}

#define AssetBundle_TypeDefinitionIndex 24803

	namespace AssetBundle {

		// Functions
		constexpr const static size_t LoadFromMemory_Internal = 0x1cb490;
		constexpr const static size_t LoadFromFile_Internal = 0x1ca710;
		constexpr const static size_t LoadAsset_Internal = 0x1cc0c0;
		constexpr const static size_t Unload = 0x1cd090;
	}

#define Screen_TypeDefinitionIndex 16850

	namespace Screen {

		// Functions
		constexpr const static size_t get_width = 0x81630;
		constexpr const static size_t get_height = 0x81640;
	}

#define Input_TypeDefinitionIndex 24681

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

#define Application_TypeDefinitionIndex 16796

	namespace Application {

		// Functions
		constexpr const static size_t get_version = 0x5f350;
		constexpr const static size_t Quit = 0x5d790;
	}

#define Gradient_TypeDefinitionIndex 16962

	namespace Gradient {

		// Functions
		constexpr const static size_t SetKeys = 0xeee50;
	}

#define Physics_TypeDefinitionIndex 23654

	namespace Physics {

		// Functions
		constexpr const static size_t Raycast = 0xaf54fe0;
		constexpr const static size_t RaycastNonAlloc = 0xaf576b0;
		constexpr const static size_t CheckCapsule = 0xaf58ed0;
	}

#define Image_TypeDefinitionIndex 21234

	namespace Image {

		// Offsets
		constexpr const static size_t m_Sprite = 0xd0;
	}

#define GraphicsSettings_TypeDefinitionIndex 17409

	namespace GraphicsSettings {

		// Functions
		constexpr const static size_t get_INTERNAL_defaultRenderPipeline = 0x127f00;
	}

#define BaseNetworkable_TypeDefinitionIndex 3185

	namespace BaseNetworkable {

		// Offsets
		constexpr const static size_t prefabID = 0x30;
		constexpr const static size_t net = 0x58;
		constexpr const static size_t parentEntity = 0x68;
		constexpr const static size_t children = 0x38;
	}

	// obf name: ::%0d2f13489b8c198ad60aef2bb96c56b6d7bc43ba
#define BaseNetworkable_Static_ClassName "BaseNetworkable/%0d2f13489b8c198ad60aef2bb96c56b6d7bc43ba"
#define BaseNetworkable_Static_ClassNameShort "%0d2f13489b8c198ad60aef2bb96c56b6d7bc43ba"
#define BaseNetworkable_Static_TypeDefinitionIndex 3184

	namespace BaseNetworkable_Static {

		// Offsets
		constexpr const static size_t clientEntities = 0x18;
	}

	// obf name: ::%d9ecec75e6fdc88bff8469f874201142584e8926
#define BaseNetworkable_EntityRealm_ClassName "BaseNetworkable/%d9ecec75e6fdc88bff8469f874201142584e8926"
#define BaseNetworkable_EntityRealm_ClassNameShort "%d9ecec75e6fdc88bff8469f874201142584e8926"
#define BaseNetworkable_EntityRealm_TypeDefinitionIndex 3182

	namespace BaseNetworkable_EntityRealm {

		// Offsets
		constexpr const static size_t entityList = 0x10;

		// Functions
		constexpr const static size_t Find = 0x1e9b470;
	}

	// obf name: ::%77a6c313c0bb350d6f552eb32d402a28210bd60f
#define System_ListDictionary_ClassName "%77a6c313c0bb350d6f552eb32d402a28210bd60f<%1feedb6462dcd97b026fbd6f88fd603e96daf6b2,BaseNetworkable>"
#define System_ListDictionary_ClassNameShort "%77a6c313c0bb350d6f552eb32d402a28210bd60f"
#define System_ListDictionary_TypeDefinitionIndex -1

	namespace System_ListDictionary {

		// Offsets
		constexpr const static size_t vals = 0x10;

		// Functions
		constexpr const static size_t TryGetValue = 0x7462080;
		constexpr const static size_t TryGetValue_methodinfo = 0xd156880;
	}

	// obf name: ::%3cd331492ee766e6974c8ef41cca00817d3186db
#define System_BufferList_ClassName "%3cd331492ee766e6974c8ef41cca00817d3186db<BaseNetworkable>"
#define System_BufferList_ClassNameShort "%3cd331492ee766e6974c8ef41cca00817d3186db"
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

#define Model_TypeDefinitionIndex 3428

	namespace Model {

		// Offsets
		constexpr const static size_t rootBone = 0x28;
		constexpr const static size_t headBone = 0x30;
		constexpr const static size_t eyeBone = 0x38;
		constexpr const static size_t boneTransforms = 0x50;
	}

#define BaseEntity_TypeDefinitionIndex 6740

	namespace BaseEntity {

		// Offsets
		constexpr const static size_t bounds = 0xa8;
		constexpr const static size_t model = 0xd0;
		constexpr const static size_t flags = 0xd8;
		constexpr const static size_t triggers = 0xa0;
		constexpr const static size_t positionLerp = 0x160;

		// Functions
		constexpr const static size_t ServerRPC = 0x4625fb0;
		constexpr const static size_t FindBone = 0x4636e40;
		constexpr const static size_t GetWorldVelocity = 0x460f9d0;
		constexpr const static size_t GetParentVelocity = 0x467ba80;
	}

	// obf name: ::%92e9786a125ae9e48f2501ee7369b9fc50ec4923
#define PositionLerp_ClassName "%92e9786a125ae9e48f2501ee7369b9fc50ec4923"
#define PositionLerp_ClassNameShort "%92e9786a125ae9e48f2501ee7369b9fc50ec4923"
#define PositionLerp_TypeDefinitionIndex 3432

	namespace PositionLerp {

		// Offsets
		constexpr const static size_t interpolator = 0x28;
	}

	// obf name: ::%cc463bf1876bba17176e43360b223b7624a603cb
#define Interpolator_ClassName "%cc463bf1876bba17176e43360b223b7624a603cb<%92cf8081218e55f1dc6fb80b823ba435cd1333cf>"
#define Interpolator_ClassNameShort "%cc463bf1876bba17176e43360b223b7624a603cb"
#define Interpolator_TypeDefinitionIndex -1

	namespace Interpolator {

		// Offsets
		constexpr const static size_t list = 0x30;
		constexpr const static size_t last = 0x10;
	}

#define BaseCombatEntity_TypeDefinitionIndex 6699

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

#define SkeletonProperties_TypeDefinitionIndex 5501

	namespace SkeletonProperties {

		// Offsets
		constexpr const static size_t bones = 0x20;
		constexpr const static size_t quickLookup = 0x28;
	}

#define SkeletonProperties_BoneProperty_TypeDefinitionIndex 5499

	namespace SkeletonProperties_BoneProperty {

		// Offsets
		constexpr const static size_t boneName = 0x18;
		constexpr const static size_t area = 0x20;
	}

#define DamageProperties_TypeDefinitionIndex 3021

	namespace DamageProperties {

		// Offsets
		constexpr const static size_t fallback = 0x18;
		constexpr const static size_t bones = 0x20;
	}

#define DamageProperties_HitAreaProperty_TypeDefinitionIndex 3020

	namespace DamageProperties_HitAreaProperty {

		// Offsets
		constexpr const static size_t area = 0x10;
		constexpr const static size_t damage = 0x14;
	}

	// obf name: ::%2643c53fddb61a540ef2dcb5db39b2a0397fc762
#define DamageTypeList_ClassName "%2643c53fddb61a540ef2dcb5db39b2a0397fc762"
#define DamageTypeList_ClassNameShort "%2643c53fddb61a540ef2dcb5db39b2a0397fc762"
#define DamageTypeList_TypeDefinitionIndex 2832

	namespace DamageTypeList {

		// Offsets
		constexpr const static size_t types = 0x10;
	}

#define ProtectionProperties_TypeDefinitionIndex 4560

	namespace ProtectionProperties {

		// Offsets
		constexpr const static size_t amounts = 0x28;
	}

#define ItemDefinition_TypeDefinitionIndex 6041

	namespace ItemDefinition {

		// Offsets
		constexpr const static size_t itemid = 0x20;
		constexpr const static size_t shortname = 0x28;
		constexpr const static size_t displayName = 0x40;
		constexpr const static size_t iconSprite = 0x50;
		constexpr const static size_t category = 0x58;
		constexpr const static size_t stackable = 0x78;
		constexpr const static size_t rarity = 0x90;
		constexpr const static size_t condition = 0xb8;
		constexpr const static size_t ItemModWearable = 0x170;
	}

#define RecoilProperties_TypeDefinitionIndex 3779

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

#define BaseProjectile_Magazine_TypeDefinitionIndex 5950

	namespace BaseProjectile_Magazine {

		// Offsets
		constexpr const static size_t capacity = 0x18;
		constexpr const static size_t contents = 0x1c;
		constexpr const static size_t ammoType = 0x20;
	}

#define AttackEntity_TypeDefinitionIndex 300

	namespace AttackEntity {

		// Offsets
		constexpr const static size_t deployDelay = 0x240;
		constexpr const static size_t repeatDelay = 0x244;
		constexpr const static size_t animationDelay = 0x248;
		constexpr const static size_t noHeadshots = 0x296;
		constexpr const static size_t nextAttackTime = 0x298;
		constexpr const static size_t timeSinceDeploy = 0x2b0;

		// Functions
		constexpr const static size_t SpectatorNotifyTick = 0x1319470;
		constexpr const static size_t StartAttackCooldown = 0x1316b60;
	}

#define BaseProjectile_TypeDefinitionIndex 5955

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
		constexpr const static size_t isBurstWeapon = 0x38f;
		constexpr const static size_t cachedModHash = 0x3c0;
		constexpr const static size_t sightAimConeScale = 0x3c4;
		constexpr const static size_t sightAimConeOffset = 0x3c8;
		constexpr const static size_t hipAimConeScale = 0x3cc;
		constexpr const static size_t hipAimConeOffset = 0x3d0;

		// Functions
		constexpr const static size_t LaunchProjectile = 0x3dee900;
		constexpr const static size_t LaunchProjectileClientSide = 0x3e09d00;
		constexpr const static size_t ScaleRepeatDelay = 0x3e02320;
		constexpr const static size_t GetAimCone = 0x3de0e50;
		constexpr const static size_t GetAimCone_vtableoff = 0x3d98;
		constexpr const static size_t UpdateAmmoDisplay = 0x3ddabc0;
		constexpr const static size_t UpdateAmmoDisplay_vtableoff = 0x3c58;
	}

#define BaseLauncher_TypeDefinitionIndex 573

	namespace BaseLauncher {

		// Offsets
	}

#define SpinUpWeapon_TypeDefinitionIndex 5674

	namespace SpinUpWeapon {

		// Offsets
	}

	// obf name: ::%f220058f0e0d7e2eba4c4e10590592ecdbc5d56f
#define HitTest_ClassName "%f220058f0e0d7e2eba4c4e10590592ecdbc5d56f"
#define HitTest_ClassNameShort "%f220058f0e0d7e2eba4c4e10590592ecdbc5d56f"
#define HitTest_TypeDefinitionIndex 6316

	namespace HitTest {

		// Offsets
		constexpr const static size_t type = 0x44;
		constexpr const static size_t AttackRay = 0x10;
		constexpr const static size_t RayHit = 0x80;
		constexpr const static size_t damageProperties = 0xd0;
		constexpr const static size_t gameObject = 0x28;
		constexpr const static size_t collider = 0x58;
		constexpr const static size_t ignoredTypes = 0xc0;
		constexpr const static size_t HitTransform = 0x38;
		constexpr const static size_t HitPart = 0x30;
		constexpr const static size_t HitMaterial = 0xd8;
		constexpr const static size_t DidHit = 0x40;
		constexpr const static size_t MaxDistance = 0xe0;
		constexpr const static size_t HitPoint = 0x48;
		constexpr const static size_t HitNormal = 0xac;
		constexpr const static size_t ignoreEntity = 0x60;
		constexpr const static size_t HitEntity = 0x70;
	}

#define Projectile_TypeDefinitionIndex 4570

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
		constexpr const static size_t sourceProjectilePrefab = 0x108;
		constexpr const static size_t mod = 0x110;
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
		constexpr const static size_t CalculateEffectScale = 0x2defae0;
		constexpr const static size_t CalculateEffectScale_vtableoff = 0x388;
		constexpr const static size_t SetEffectScale = 0x2df78f0;
		constexpr const static size_t UpdateVelocity = 0x2e01d30;
		constexpr const static size_t Retire = 0x2dec6e0;
		constexpr const static size_t DoHit = 0x2e011f0;
	}

	// obf name: ::%9241ecdd61d259f3911ffe7364edb59167e648c7
#define HitInfo_ClassName "%9241ecdd61d259f3911ffe7364edb59167e648c7"
#define HitInfo_ClassNameShort "%9241ecdd61d259f3911ffe7364edb59167e648c7"
#define HitInfo_TypeDefinitionIndex 4481

	namespace HitInfo {

		// Offsets
		constexpr const static size_t damageProperties = 0x90;
		constexpr const static size_t damageTypes = 0xe0;

		// Functions
		constexpr const static size_t get_boneArea = 0x2c60bc0;
	}

	// obf name: ::%e911d029814eaf04111bbc8ab2a23d90a17a4330
#define GameTrace_ClassName "%e911d029814eaf04111bbc8ab2a23d90a17a4330"
#define GameTrace_ClassNameShort "%e911d029814eaf04111bbc8ab2a23d90a17a4330"
#define GameTrace_TypeDefinitionIndex 4239

	namespace GameTrace {

		// Functions
		constexpr const static size_t Trace = 0x29961f0;
	}

#define BaseMelee_TypeDefinitionIndex 988

	namespace BaseMelee {

		// Offsets
		constexpr const static size_t damageProperties = 0x2d8;
		constexpr const static size_t maxDistance = 0x2f0;
		constexpr const static size_t attackRadius = 0x2f4;
		constexpr const static size_t blockSprintOnAttack = 0x2f9;
		constexpr const static size_t gathering = 0x328;
		constexpr const static size_t canThrowAsProjectile = 0x331;

		// Functions
		constexpr const static size_t ProcessAttack = 0x4e9b440;
		constexpr const static size_t DoThrow = 0x4e9da40;
	}

#define FlintStrikeWeapon_TypeDefinitionIndex 4036

	namespace FlintStrikeWeapon {

		// Offsets
		constexpr const static size_t successFraction = 0x410;
		constexpr const static size_t strikeRecoil = 0x418;
		constexpr const static size_t _didSparkThisFrame = 0x420;
	}

#define CompoundBowWeapon_TypeDefinitionIndex 3402

	namespace CompoundBowWeapon {

		// Offsets
		constexpr const static size_t stringHoldDurationMax = 0x428;
		constexpr const static size_t stringBonusVelocity = 0x434;

		// Functions
		constexpr const static size_t GetStringBonusScale = 0x20d6c20;
	}

	// obf name: ::%eab9fb024541d13b8813dc018ce328a3f44d0ddf
#define ItemContainer_ClassName "%eab9fb024541d13b8813dc018ce328a3f44d0ddf"
#define ItemContainer_ClassNameShort "%eab9fb024541d13b8813dc018ce328a3f44d0ddf"
#define ItemContainer_TypeDefinitionIndex 4216

	namespace ItemContainer {

		// Offsets
		constexpr const static size_t uid = 0x48;
		constexpr const static size_t itemList = 0x18;

		// Functions
		constexpr const static size_t FindItemsByItemID = 0x0;
		constexpr const static size_t GetSlot = 0x2924c30;
	}

#define PlayerLoot_TypeDefinitionIndex 5539

	namespace PlayerLoot {

		// Offsets
		constexpr const static size_t containers = 0x38;
	}

#define PlayerInventory_TypeDefinitionIndex 2945

	namespace PlayerInventory {

		// Offsets
		constexpr const static size_t containerBelt = 0x38;
		constexpr const static size_t containerMain = 0x58;
		constexpr const static size_t containerWear = 0x60;
		constexpr const static size_t loot = 0x48;

		// Functions
		constexpr const static size_t Initialize = 0x1bae9c0;
		constexpr const static size_t FindItemsByItemID = 0x0;
	}

#define PlayerEyes_TypeDefinitionIndex 6393

	namespace PlayerEyes {

		// Offsets
		constexpr const static size_t viewOffset = 0x40;
		constexpr const static size_t bodyRotation = 0x50;

		// Functions
		constexpr const static size_t get_position = 0x42b8210;
		constexpr const static size_t get_rotation = 0x42b64a0;
		constexpr const static size_t set_rotation = 0x42c9800;
		constexpr const static size_t HeadForward = 0x42b9e40;
	}

	// obf name: ::%a6ffaeedf99bf1b3ff2afeb20144c28521123d15
#define PlayerEyes_Static_ClassName "PlayerEyes/%a6ffaeedf99bf1b3ff2afeb20144c28521123d15"
#define PlayerEyes_Static_ClassNameShort "%a6ffaeedf99bf1b3ff2afeb20144c28521123d15"
#define PlayerEyes_Static_TypeDefinitionIndex 6392

	namespace PlayerEyes_Static {

		// Offsets
		constexpr const static size_t EyeOffset = 0x98;
	}

	// obf name: ::%cd99d656c1439525be0c1d26b5bdaca779dc89a8
#define PlayerBelt_ClassName "%cd99d656c1439525be0c1d26b5bdaca779dc89a8"
#define PlayerBelt_ClassNameShort "%cd99d656c1439525be0c1d26b5bdaca779dc89a8"
#define PlayerBelt_TypeDefinitionIndex 1463

	namespace PlayerBelt {

		// Functions
		constexpr const static size_t ChangeSelect = 0x53f2910;
		constexpr const static size_t GetActiveItem = 0x53ead20;
	}

	// obf name: ::%60a78a5196145b8f428f3ae0cd6e3243d8c81950
#define LocalPlayer_ClassName "%60a78a5196145b8f428f3ae0cd6e3243d8c81950"
#define LocalPlayer_ClassNameShort "%60a78a5196145b8f428f3ae0cd6e3243d8c81950"
#define LocalPlayer_TypeDefinitionIndex 4395

	namespace LocalPlayer {

		// Functions
		constexpr const static size_t ItemCommand = 0x2b60b40;
		constexpr const static size_t MoveItem = 0x2b628e0;
		constexpr const static size_t get_Entity = 0x2b6a660;
	}

	// obf name: ::%fb270332829d7f1dbb48d0e7cc51bbfd06e37398
#define LocalPlayer_Static_ClassName "%60a78a5196145b8f428f3ae0cd6e3243d8c81950/%fb270332829d7f1dbb48d0e7cc51bbfd06e37398"
#define LocalPlayer_Static_ClassNameShort "%fb270332829d7f1dbb48d0e7cc51bbfd06e37398"
#define LocalPlayer_Static_TypeDefinitionIndex 4394

	namespace LocalPlayer_Static {

		// Offsets
		constexpr const static size_t Entity = 0x10;
	}

	// obf name: ::%200b899cad08504cadfa2228b82d47deee5ba2b8
#define BasePlayer_Static_ClassName "BasePlayer/%200b899cad08504cadfa2228b82d47deee5ba2b8"
#define BasePlayer_Static_ClassNameShort "%200b899cad08504cadfa2228b82d47deee5ba2b8"
#define BasePlayer_Static_TypeDefinitionIndex 6825

	namespace BasePlayer_Static {

		// Offsets
		constexpr const static size_t visiblePlayerList = 0x598;
	}

#define BasePlayer_TypeDefinitionIndex 6826

	namespace BasePlayer {

		// Offsets
		constexpr const static size_t playerModel = 0x320;
		constexpr const static size_t input = 0x420;
		constexpr const static size_t movement = 0x2a8;
		constexpr const static size_t currentTeam = 0x470;
		constexpr const static size_t clActiveItem = 0x4a0;
		constexpr const static size_t modelState = 0x670;
		constexpr const static size_t playerFlags = 0x5a8;
		constexpr const static size_t eyes = 0x358;
		constexpr const static size_t playerRigidbody = 0x338;
		constexpr const static size_t userID = 0x5f0;
		constexpr const static size_t UserIDString = 0x5e0;
		constexpr const static size_t inventory = 0x610;
		constexpr const static size_t _displayName = 0x2e8;
		constexpr const static size_t _lookingAt = 0x2a0;
		constexpr const static size_t lastSentTickTime = 0x564;
		constexpr const static size_t lastSentTick = 0x5e8;
		constexpr const static size_t mounted = 0x4e0;
		constexpr const static size_t Belt = 0x400;
		constexpr const static size_t _lookingAtEntity = 0x450;
		constexpr const static size_t currentGesture = 0x570;
		constexpr const static size_t weaponMoveSpeedScale = 0x680;
		constexpr const static size_t clothingBlocksAiming = 0x684;
		constexpr const static size_t clothingMoveSpeedReduction = 0x688;
		constexpr const static size_t clothingWaterSpeedBonus = 0x68c;
		constexpr const static size_t equippingBlocked = 0x694;

		// Functions
		constexpr const static size_t ClientUpdateLocalPlayer = 0x483e5a0;
		constexpr const static size_t Menu_AssistPlayer = 0x486c560;
		constexpr const static size_t OnViewModeChanged = 0x481ff20;
		constexpr const static size_t ChatMessage = 0x48010b0;
		constexpr const static size_t IsOnGround = 0x4727290;
		constexpr const static size_t GetSpeed = 0x4778bf0;
		constexpr const static size_t SendProjectileUpdate = 0x47c3e00;
		constexpr const static size_t CanBuild = 0x4865320;
		constexpr const static size_t GetMounted = 0x47a14e0;
		constexpr const static size_t GetHeldEntity = 0x472ba00;
		constexpr const static size_t get_inventory = 0x486f090;
		constexpr const static size_t get_eyes = 0x472bd70;
		constexpr const static size_t SendClientTick = 0x47bd140;
		constexpr const static size_t ClientInput = 0x474a420;
		constexpr const static size_t ClientInput_vtableoff = 0x39b8;
		constexpr const static size_t MaxHealth = 0x4876d20;
		constexpr const static size_t MaxHealth_vtableoff = 0x24d8;
		constexpr const static size_t OnAttacked = 0x47cb560;
		constexpr const static size_t OnAttacked_vtableoff = 0x1ff8;
		constexpr const static size_t get_idealViewMode = 0x4886e40;
	}

#define ScientistNPC_TypeDefinitionIndex 2594

	namespace ScientistNPC {

		// Offsets
	}

#define TunnelDweller_TypeDefinitionIndex 2799

	namespace TunnelDweller {

		// Offsets
	}

#define UnderwaterDweller_TypeDefinitionIndex 5060

	namespace UnderwaterDweller {

		// Offsets
	}

#define ScarecrowNPC_TypeDefinitionIndex 1607

	namespace ScarecrowNPC {

		// Offsets
	}

#define GingerbreadNPC_TypeDefinitionIndex 6802

	namespace GingerbreadNPC {

		// Offsets
	}

#define BaseMovement_TypeDefinitionIndex 1857

	namespace BaseMovement {

		// Offsets
		constexpr const static size_t adminCheat = 0x20;
		constexpr const static size_t Owner = 0x28;
	}

#define PlayerWalkMovement_TypeDefinitionIndex 2340

	namespace PlayerWalkMovement {

		// Offsets
		constexpr const static size_t capsule = 0xd8;
		constexpr const static size_t ladder = 0xe8;
		constexpr const static size_t modify = 0x1b8;

		// Functions
		constexpr const static size_t BlockJump = 0x14c4520;
		constexpr const static size_t BlockSprint = 0x14c8b40;
		constexpr const static size_t GroundCheck = 0x14e90e0;
		constexpr const static size_t ClientInput = 0x14e2410;
		constexpr const static size_t ClientInput_vtableoff = 0x358;
		constexpr const static size_t DoFixedUpdate = 0x14dcd40;
		constexpr const static size_t DoFixedUpdate_vtableoff = 0x408;
		constexpr const static size_t FrameUpdate = 0x14daeb0;
		constexpr const static size_t FrameUpdate_vtableoff = 0x3e8;
		constexpr const static size_t TeleportTo = 0x14c95d0;
		constexpr const static size_t TeleportTo_vtableoff = 0x1b8;
	}

#define BuildingPrivlidge_TypeDefinitionIndex 7069

	namespace BuildingPrivlidge {

		// Offsets
		constexpr const static size_t allowedConstructionItems = 0x380;
		constexpr const static size_t cachedProtectedMinutes = 0x388;
	}

#define WorldItem_TypeDefinitionIndex 1311

	namespace WorldItem {

		// Offsets
		constexpr const static size_t allowPickup = 0x1a8;
		constexpr const static size_t item = 0x1b0;
	}

#define HackableLockedCrate_TypeDefinitionIndex 1687

	namespace HackableLockedCrate {

		// Offsets
		constexpr const static size_t timerText = 0x398;
		constexpr const static size_t hackSeconds = 0x3a8;
	}

#define ProjectileWeaponMod_TypeDefinitionIndex 6018

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

#define ProjectileWeaponMod_Modifier_TypeDefinitionIndex 6014

	namespace ProjectileWeaponMod_Modifier {
		constexpr const static size_t enabled = 0x0;
		constexpr const static size_t scalar = 0x4;
		constexpr const static size_t offset = 0x8;
	}

	// obf name: ::%9bddd09c917ef022d57c4e25d7d8a96c739e2741
#define ConsoleSystem_ClassName "%9bddd09c917ef022d57c4e25d7d8a96c739e2741"
#define ConsoleSystem_ClassNameShort "%9bddd09c917ef022d57c4e25d7d8a96c739e2741"
#define ConsoleSystem_TypeDefinitionIndex 23632

	namespace ConsoleSystem {

		// Functions
		constexpr const static size_t Run = 0x631bf80;
	}

	// obf name: ::%8f4bebd000feef338ff5cdfa073372b0774fde07
#define ConsoleSystem_Index_Static_ClassName "%9bddd09c917ef022d57c4e25d7d8a96c739e2741/%30d8808650a2acb64505db5986a447636ce4ceeb.%8f4bebd000feef338ff5cdfa073372b0774fde07"
#define ConsoleSystem_Index_Static_ClassNameShort "%8f4bebd000feef338ff5cdfa073372b0774fde07"
#define ConsoleSystem_Index_Static_TypeDefinitionIndex 23625

	namespace ConsoleSystem_Index_Static {

		// Offsets
		constexpr const static size_t All = 0xa0;
	}

#define LootableCorpse_TypeDefinitionIndex 6539

	namespace LootableCorpse {

		// Offsets
		constexpr const static size_t playerSteamID = 0x2b8;
		constexpr const static size_t _playerName = 0x2a8;
	}

#define DroppedItemContainer_TypeDefinitionIndex 6111

	namespace DroppedItemContainer {

		// Offsets
		constexpr const static size_t playerSteamID = 0x288;
		constexpr const static size_t _playerName = 0x270;
	}

#define MainCamera_TypeDefinitionIndex 1523

	namespace MainCamera {

		// Offsets 
		constexpr const static size_t mainCamera = 0x50;
		constexpr const static size_t mainCameraTransform = 0x40;

		// Functions
		constexpr const static size_t Update = 0xbdf800;
		constexpr const static size_t OnPreCull = 0xbde780;
		constexpr const static size_t Trace = 0xbd5520;
	}

#define CameraMan_TypeDefinitionIndex 6221

	namespace CameraMan {

		// Offsets
	}

	// obf name: ::%fc336f6a8546ac883613fed70f88d5f8ef9a8351
#define PlayerTick_ClassName "%fc336f6a8546ac883613fed70f88d5f8ef9a8351"
#define PlayerTick_ClassNameShort "%fc336f6a8546ac883613fed70f88d5f8ef9a8351"
#define PlayerTick_TypeDefinitionIndex 7340

	namespace PlayerTick {

		// Offsets
		constexpr const static size_t inputState = 0x50;
		constexpr const static size_t modelState = 0x30;
		constexpr const static size_t activeItem = 0x18;
		constexpr const static size_t parentID = 0x48;
		constexpr const static size_t position = 0x38;
		constexpr const static size_t eyePos = 0x24;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x9404f30;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x9408980;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%5d2ff4c79aeab53fbdc233bdcbbe020ef39bcc9c
#define InputMessage_ClassName "%5d2ff4c79aeab53fbdc233bdcbbe020ef39bcc9c"
#define InputMessage_ClassNameShort "%5d2ff4c79aeab53fbdc233bdcbbe020ef39bcc9c"
#define InputMessage_TypeDefinitionIndex 7690

	namespace InputMessage {

		// Offsets
		constexpr const static size_t buttons = 0x20;
		constexpr const static size_t aimAngles = 0x10;
		constexpr const static size_t mouseDelta = 0x28;
	}

	// obf name: ::%18b4398e7f21d7dd59766776040b3b6af02a6c43
#define InputState_ClassName "%18b4398e7f21d7dd59766776040b3b6af02a6c43"
#define InputState_ClassNameShort "%18b4398e7f21d7dd59766776040b3b6af02a6c43"
#define InputState_TypeDefinitionIndex 3434

	namespace InputState {

		// Offsets
		constexpr const static size_t current = 0x10;
		constexpr const static size_t previous = 0x20;
	}

#define PlayerInput_TypeDefinitionIndex 5547

	namespace PlayerInput {

		// Offsets
		constexpr const static size_t state = 0x28;
		constexpr const static size_t bodyAngles = 0x44;
	}

	// obf name: ::%b78e256e3d0964ff4fc59ef5e7b1f917d1c99c19
#define ModelState_ClassName "%b78e256e3d0964ff4fc59ef5e7b1f917d1c99c19"
#define ModelState_ClassNameShort "%b78e256e3d0964ff4fc59ef5e7b1f917d1c99c19"
#define ModelState_TypeDefinitionIndex 7510

	namespace ModelState {

		// Offsets
		constexpr const static size_t flags = 0x14;
		constexpr const static size_t waterLevel = 0x78;
		constexpr const static size_t lookDir = 0x24;
	}

	// obf name: ::%2b877cbf46b99cfe4ed18b900a4c4a0e3a119b37
#define Item_ClassName "%2b877cbf46b99cfe4ed18b900a4c4a0e3a119b37"
#define Item_ClassNameShort "%2b877cbf46b99cfe4ed18b900a4c4a0e3a119b37"
#define Item_TypeDefinitionIndex 2605

	namespace Item {

		// Offsets
		constexpr const static size_t info = 0xb8;
		constexpr const static size_t uid = 0xe8;
		constexpr const static size_t _maxCondition = 0x10;
		constexpr const static size_t _condition = 0x3c;
		constexpr const static size_t amount = 0x60;
		constexpr const static size_t position = 0xac;
		constexpr const static size_t parent = 0x40;
		constexpr const static size_t contents = 0x50;
		constexpr const static size_t heldEntity = 0x68;
		constexpr const static size_t worldEnt = 0xd0;

		// Functions
		constexpr const static size_t get_iconSprite = 0x1782b90;
	}

	// obf name: ::%0b45b3f6cd98760e859d19fd83b394ab3739737e
#define WaterLevel_ClassName "%0b45b3f6cd98760e859d19fd83b394ab3739737e"
#define WaterLevel_ClassNameShort "%0b45b3f6cd98760e859d19fd83b394ab3739737e"
#define WaterLevel_TypeDefinitionIndex 7160

	namespace WaterLevel {

		// Functions
		constexpr const static size_t Test = 0x4c08ee0;
		constexpr const static size_t GetWaterLevel = 0x4c09590;
	}

	// obf name: ::%c853937f3a18f0b2d34159ee2d722d70a3c3d9d7
#define ConVar_Graphics_Static_ClassName "%0646527779726e473771bdd8103bbecbb3ba3ef9/%c853937f3a18f0b2d34159ee2d722d70a3c3d9d7"
#define ConVar_Graphics_Static_ClassNameShort "%c853937f3a18f0b2d34159ee2d722d70a3c3d9d7"
#define ConVar_Graphics_Static_TypeDefinitionIndex 3326

	namespace ConVar_Graphics_Static {

		// Offsets
		constexpr const static size_t _fov = 0x588;

		// Functions
		constexpr const static size_t _fov_getter = 0x33529e0;
		constexpr const static size_t _fov_setter = 0x33688b0;
	}

#define BaseFishingRod_TypeDefinitionIndex 6637

	namespace BaseFishingRod {

		// Offsets
		constexpr const static size_t CurrentState = 0x260;
		constexpr const static size_t currentBobber = 0x268;
		constexpr const static size_t MaxCastDistance = 0x284;
		constexpr const static size_t BobberPreview = 0x290;
		constexpr const static size_t clientStrainAmountNormalised = 0x2d0;
		constexpr const static size_t strainGainMod = 0x2c0;
		constexpr const static size_t aimAnimationReady = 0x2e8;

		// Functions
		constexpr const static size_t UpdateLineRenderer = 0x451bff0;
		constexpr const static size_t EvaluateFishingPosition = 0x4529940;
	}

#define FishingBobber_TypeDefinitionIndex 5893

	namespace FishingBobber {

		// Offsets
		constexpr const static size_t bobberRoot = 0x288;
	}

#define GameManifest_TypeDefinitionIndex 1190

	namespace GameManifest {

		// Functions
		constexpr const static size_t GUIDToObject = 0x50658e0;
	}

	// obf name: ::%371be4def52032e424a2a8260014950f46e69dd4
#define GameManager_ClassName "%371be4def52032e424a2a8260014950f46e69dd4"
#define GameManager_ClassNameShort "%371be4def52032e424a2a8260014950f46e69dd4"
#define GameManager_TypeDefinitionIndex 6207

	namespace GameManager {

		// Offsets
		constexpr const static size_t pool = 0x28;

		// Functions
		constexpr const static size_t CreatePrefab = 0x4125870;
	}

	// obf name: ::%425052dee78f4c54f6b4215a18a0a613fc3c82ad
#define GameManager_Static_ClassName "%371be4def52032e424a2a8260014950f46e69dd4/%425052dee78f4c54f6b4215a18a0a613fc3c82ad"
#define GameManager_Static_ClassNameShort "%425052dee78f4c54f6b4215a18a0a613fc3c82ad"
#define GameManager_Static_TypeDefinitionIndex 6206

	namespace GameManager_Static {

		// Offsets
		constexpr const static size_t client = 0x8;
	}

	// obf name: ::%e971f270cfa29f56ac6ad13fdd6e253ad91291f5
#define PrefabPoolCollection_ClassName "%e971f270cfa29f56ac6ad13fdd6e253ad91291f5"
#define PrefabPoolCollection_ClassNameShort "%e971f270cfa29f56ac6ad13fdd6e253ad91291f5"
#define PrefabPoolCollection_TypeDefinitionIndex 288

	namespace PrefabPoolCollection {

		// Offsets
		constexpr const static size_t storage = 0x18;
	}

	// obf name: ::%87d35c6ef0e4a44d9fd6a921182bd68523a626e8
#define PrefabPool_ClassName "%87d35c6ef0e4a44d9fd6a921182bd68523a626e8"
#define PrefabPool_ClassNameShort "%87d35c6ef0e4a44d9fd6a921182bd68523a626e8"
#define PrefabPool_TypeDefinitionIndex 3896

	namespace PrefabPool {

		// Offsets
		constexpr const static size_t stack = 0x18;
	}

#define ItemModProjectile_TypeDefinitionIndex 3

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

#define CraftingQueue_TypeDefinitionIndex 10

	namespace CraftingQueue {

		// Offsets
		constexpr const static size_t icons = 0x30;
	}

	// obf name: ::%02ff4c7d07cecbdf04d68831fb77e5a8723112d2
#define CraftingQueue_Static_ClassName "CraftingQueue/%02ff4c7d07cecbdf04d68831fb77e5a8723112d2"
#define CraftingQueue_Static_ClassNameShort "%02ff4c7d07cecbdf04d68831fb77e5a8723112d2"
#define CraftingQueue_Static_TypeDefinitionIndex 9

	namespace CraftingQueue_Static {

		// Offsets
		constexpr const static size_t isCrafting = 0x18;
	}

#define CraftingQueueIcon_TypeDefinitionIndex 2058

	namespace CraftingQueueIcon {

		// Offsets
		constexpr const static size_t endTime = 0x4c;
		constexpr const static size_t item = 0x60;
	}

	// obf name: ::%40e68248cfee5694c2831e0343f4f4b0825bea40
#define Planner_Static_ClassName "Planner/%40e68248cfee5694c2831e0343f4f4b0825bea40"
#define Planner_Static_ClassNameShort "%40e68248cfee5694c2831e0343f4f4b0825bea40"
#define Planner_Static_TypeDefinitionIndex 4225

	namespace Planner_Static {

		// Offsets
		constexpr const static size_t guide = 0x128;
	}

	// obf name: ::%b875cf24ea112f6f1bb8e8bd7887b7f345120095
#define Planner_Guide_ClassName "Planner/%b875cf24ea112f6f1bb8e8bd7887b7f345120095"
#define Planner_Guide_ClassNameShort "%b875cf24ea112f6f1bb8e8bd7887b7f345120095"
#define Planner_Guide_TypeDefinitionIndex 4221

	namespace Planner_Guide {

		// Offsets
		constexpr const static size_t lastPlacement = 0x88;
	}

#define Planner_TypeDefinitionIndex 4226

	namespace Planner {

		// Offsets
		constexpr const static size_t _currentConstruction = 0x270;
	}

#define Construction_TypeDefinitionIndex 5318

	namespace Construction {

		// Offsets
		constexpr const static size_t holdToPlaceDuration = 0xfc;
		constexpr const static size_t grades = 0x148;
	}

#define BuildingBlock_TypeDefinitionIndex 2365

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t blockDefinition = 0x300;
	}

	// obf name: ::HeldEntity
#define HeldEntity_ClassName "HeldEntity"
#define HeldEntity_ClassNameShort "HeldEntity"
#define HeldEntity_TypeDefinitionIndex 5672

	namespace HeldEntity {

		// Offsets
		constexpr const static size_t ownerItemUID = 0x220;
		constexpr const static size_t _punches = 0x1c8;
		constexpr const static size_t viewModel = 0x228;

		// Functions
		constexpr const static size_t OnDeploy = 0x3b1c8e0;
	}

	// obf name: ::%dfd1b8af2161dd92cc6d6e52e7fac55d311aab5c
#define PunchEntry_ClassName "HeldEntity/%dfd1b8af2161dd92cc6d6e52e7fac55d311aab5c"
#define PunchEntry_ClassNameShort "%dfd1b8af2161dd92cc6d6e52e7fac55d311aab5c"
#define PunchEntry_TypeDefinitionIndex 5670

	namespace PunchEntry {

		// Offsets
		constexpr const static size_t startTime = 0x1c;
		constexpr const static size_t duration = 0x2c;
		constexpr const static size_t amountAdded = 0x10;
		constexpr const static size_t amount = 0x20;
	}

#define IronSights_TypeDefinitionIndex 1450

	namespace IronSights {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t ironsightsOverride = 0x68;
	}

#define IronSightOverride_TypeDefinitionIndex 1007

	namespace IronSightOverride {

		// Offsets
		constexpr const static size_t zoomFactor = 0x2c;
		constexpr const static size_t fovBias = 0x30;
	}

#define BaseViewModel_TypeDefinitionIndex 6298

	namespace BaseViewModel {

		// Offsets
		constexpr const static size_t useViewModelCamera = 0x40;
		constexpr const static size_t ironSights = 0xd0;
		constexpr const static size_t model = 0xc8;
		constexpr const static size_t lower = 0xb0;

		// Functions
		constexpr const static size_t get_ActiveModel = 0x41fd1a0;
	}

#define ViewModel_TypeDefinitionIndex 2254

	namespace ViewModel {

		// Offsets
		constexpr const static size_t instance = 0x28;

		// Functions
		constexpr const static size_t PlayInt = 0x13cb8f0;
		constexpr const static size_t PlayString = 0x13c8380;
	}

#define MedicalTool_TypeDefinitionIndex 5486

	namespace MedicalTool {

		// Offsets
		constexpr const static size_t resetTime = 0x2f8;
	}

#define WaterBody_TypeDefinitionIndex 2333

	namespace WaterBody {

		// Offsets
		constexpr const static size_t meshFilter = 0x58;
	}

	// obf name: ::%7b89b416fe3e7f4dde90f31a4dba6f0a791e7936
#define WaterSystem_Static_ClassName "WaterSystem/%7b89b416fe3e7f4dde90f31a4dba6f0a791e7936"
#define WaterSystem_Static_ClassNameShort "%7b89b416fe3e7f4dde90f31a4dba6f0a791e7936"
#define WaterSystem_Static_TypeDefinitionIndex 359

	namespace WaterSystem_Static {

		// Offsets
		constexpr const static size_t Ocean = 0x78;
	}

#define WaterSystem_TypeDefinitionIndex 360

	namespace WaterSystem {

		// Functions
		constexpr const static size_t get_Ocean = 0x18fb750;
	}

#define TerrainMeta_TypeDefinitionIndex 4521

	namespace TerrainMeta {

		// Offsets
		constexpr const static size_t Position = 0x18;
		constexpr const static size_t Size = 0x24;
		constexpr const static size_t OneOverSize = 0x30;
		constexpr const static size_t Collision = 0x730;
		constexpr const static size_t HeightMap = 0x618;
		constexpr const static size_t SplatMap = 0x480;
		constexpr const static size_t TopologyMap = 0x588;
		constexpr const static size_t Texturing = 0x648;
	}

#define TerrainCollision_TypeDefinitionIndex 3254

	namespace TerrainCollision {

		// Functions
		constexpr const static size_t GetIgnore = 0x1f2e950;
	}

#define TerrainHeightMap_TypeDefinitionIndex 4971

	namespace TerrainHeightMap {

		// Offsets
		constexpr const static size_t normY = 0x70;
	}

#define TerrainSplatMap_TypeDefinitionIndex 3498

	namespace TerrainSplatMap {

		// Offsets
		constexpr const static size_t num = 0x74;
	}

#define TerrainTexturing_TypeDefinitionIndex 4007

	namespace TerrainTexturing {

		// Offsets
		constexpr const static size_t shoreMapSize = 0x8c;
		constexpr const static size_t terrainSize = 0x88;
		constexpr const static size_t shoreDistanceScale = 0x90;
		constexpr const static size_t shoreVectors = 0xa8;
	}

	// obf name: ::%be722b4a4cb7b55c973b0141129f07bc20fc3dca
#define World_Static_ClassName "%e2dbd0a98562dc6ad0b5d2ba2687cae46cb8a4bd/%be722b4a4cb7b55c973b0141129f07bc20fc3dca"
#define World_Static_ClassNameShort "%be722b4a4cb7b55c973b0141129f07bc20fc3dca"
#define World_Static_TypeDefinitionIndex 5227

	namespace World_Static {

		// Offsets
		constexpr const static size_t _size = 0x1a0;
	}

#define ItemIcon_TypeDefinitionIndex 693

	namespace ItemIcon {

		// Offsets
		constexpr const static size_t backgroundImage = 0xe8;

		// Functions
		constexpr const static size_t TryToMove = 0x3fbb4d0;
		constexpr const static size_t TryToMove_vtableoff = 0x4e8;
		constexpr const static size_t RunTimedAction = 0x3fb12b0;
	}

	// obf name: ::%008c81de059d6f82a6fe4d5f5476a97d27855eb3
#define ItemIcon_Static_ClassName "ItemIcon/%008c81de059d6f82a6fe4d5f5476a97d27855eb3"
#define ItemIcon_Static_ClassNameShort "%008c81de059d6f82a6fe4d5f5476a97d27855eb3"
#define ItemIcon_Static_TypeDefinitionIndex 692

	namespace ItemIcon_Static {

		// Offsets
		constexpr const static size_t containerLootStartTimes = 0x28;
	}

	// obf name: ::%0ae272adb3841f1c0648dd5357e1b0a6cf77ccdf
#define EffectData_ClassName "%0ae272adb3841f1c0648dd5357e1b0a6cf77ccdf"
#define EffectData_ClassNameShort "%0ae272adb3841f1c0648dd5357e1b0a6cf77ccdf"
#define EffectData_TypeDefinitionIndex 7687

	namespace EffectData {

		// Offsets
		constexpr const static size_t source = 0x40;
	}

	// obf name: ::%5b4c8bf2981f3d9ce441901fa217187016a33b1d
#define Effect_ClassName "%5b4c8bf2981f3d9ce441901fa217187016a33b1d"
#define Effect_ClassNameShort "%5b4c8bf2981f3d9ce441901fa217187016a33b1d"
#define Effect_TypeDefinitionIndex 1502

	namespace Effect {

		// Offsets
		constexpr const static size_t pooledString = 0x80;
		constexpr const static size_t worldPos = 0x94;
	}

	// obf name: ::%463b7172b003ac37c1ec2507c5926aaaae2ebce1
#define EffectLibrary_ClassName "%463b7172b003ac37c1ec2507c5926aaaae2ebce1"
#define EffectLibrary_ClassNameShort "%463b7172b003ac37c1ec2507c5926aaaae2ebce1"
#define EffectLibrary_TypeDefinitionIndex 3107

	namespace EffectLibrary {
		constexpr const static size_t SetupEffect = 0x1d85d70;
	}

	// obf name: ::%820c9ea524757d66f075e44dbd3722e004fba64c
#define EffectNetwork_ClassName "%820c9ea524757d66f075e44dbd3722e004fba64c"
#define EffectNetwork_ClassNameShort "%820c9ea524757d66f075e44dbd3722e004fba64c"
#define EffectNetwork_TypeDefinitionIndex 6072

	namespace EffectNetwork {

		// Functions
	}

	// obf name: ::%10f8eb6f3b89e656ab09af3677110186de3fd5f0
#define EffectNetwork_Static_ClassName "%820c9ea524757d66f075e44dbd3722e004fba64c/%10f8eb6f3b89e656ab09af3677110186de3fd5f0"
#define EffectNetwork_Static_ClassNameShort "%10f8eb6f3b89e656ab09af3677110186de3fd5f0"
#define EffectNetwork_Static_TypeDefinitionIndex 6071

	namespace EffectNetwork_Static {

		// Offsets
		constexpr const static size_t effect = 0x30;

		// Functions
		constexpr const static size_t cctor = 0x3f36120;
	}

#define BuildingBlock_TypeDefinitionIndex 2365

	namespace BuildingBlock {

		// Offsets
		constexpr const static size_t grade = 0x2f8;

		// Functions
		constexpr const static size_t GetBuildMenu = 0x1512950;
		constexpr const static size_t HasUpgradePrivilege = 0x1507ae0;
		constexpr const static size_t CanAffordUpgrade = 0x151f790;
	}

	// obf name: ::%196470c737d2e0eb34dacb029c4f6f62dedd0824
#define GameObjectEx_ClassName "%196470c737d2e0eb34dacb029c4f6f62dedd0824"
#define GameObjectEx_ClassNameShort "%196470c737d2e0eb34dacb029c4f6f62dedd0824"
#define GameObjectEx_TypeDefinitionIndex 4137

	namespace GameObjectEx {

		// Functions
		constexpr const static size_t ToBaseEntity = 0x2846e60;
	}

#define UIDeathScreen_TypeDefinitionIndex 436

	namespace UIDeathScreen {

		// Functions
		constexpr const static size_t SetVisible = 0x226e1c0;
	}

	// obf name: ::%e2c69b63a4e61606317b258d74e2867b47bf65a6
#define BaseScreenShake_Static_ClassName "BaseScreenShake/%e2c69b63a4e61606317b258d74e2867b47bf65a6"
#define BaseScreenShake_Static_ClassNameShort "%e2c69b63a4e61606317b258d74e2867b47bf65a6"
#define BaseScreenShake_Static_TypeDefinitionIndex 5182

	namespace BaseScreenShake_Static {

		// Offsets
		constexpr const static size_t list = 0x70;
	}

#define FlashbangOverlay_TypeDefinitionIndex 3711

	namespace FlashbangOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x28;
		constexpr const static size_t flashLength = 0x48;
	}

	// obf name: ::%7f8341da715cd7c6f5c733ac9ae385d055603507
#define StringPool_ClassName "%7f8341da715cd7c6f5c733ac9ae385d055603507"
#define StringPool_ClassNameShort "%7f8341da715cd7c6f5c733ac9ae385d055603507"
#define StringPool_TypeDefinitionIndex 6440

	namespace StringPool {

		// Offsets
		constexpr const static size_t toNumber = 0x80;

		// Functions
		constexpr const static size_t Get = 0x43b2eb0;
	}

	// obf name: ::%b6ca81d1076666b517dbc95d55a198e21e83e3b3
#define Network_Networkable_ClassName "%b6ca81d1076666b517dbc95d55a198e21e83e3b3"
#define Network_Networkable_ClassNameShort "%b6ca81d1076666b517dbc95d55a198e21e83e3b3"
#define Network_Networkable_TypeDefinitionIndex 18793

	namespace Network_Networkable {

		// Offsets
		constexpr const static size_t ID = 0x58;
	}

	// obf name: ::%3d72405de91e16be3f1ab18bdbdb3b3c672551d3
#define Network_Net_ClassName "%3d72405de91e16be3f1ab18bdbdb3b3c672551d3"
#define Network_Net_ClassNameShort "%3d72405de91e16be3f1ab18bdbdb3b3c672551d3"
#define Network_Net_TypeDefinitionIndex 9948

	namespace Network_Net {

		// Offsets
		constexpr const static size_t cl = 0x78;
	}

	// obf name: ::%fa76c9ae698df7b18cb3b759c9a342125180a18c
#define Network_Client_ClassName "%fa76c9ae698df7b18cb3b759c9a342125180a18c"
#define Network_Client_ClassNameShort "%fa76c9ae698df7b18cb3b759c9a342125180a18c"
#define Network_Client_TypeDefinitionIndex 18748

	namespace Network_Client {

		// Offsets
		constexpr const static size_t Connection = 0xf8;
		constexpr const static size_t ConnectedPort = 0xdc;
		constexpr const static size_t ConnectedAddress = 0xe0;
		constexpr const static size_t ServerName = 0x100;

		// Offsets
		constexpr const static size_t CreateNetworkable = 0x63877f0;
		constexpr const static size_t DestroyNetworkable = 0x63875f0;
	}

	// obf name: ::%fad0aaa8170143bf289205836c632c9998cf412d
#define Network_BaseNetwork_ClassName "%fad0aaa8170143bf289205836c632c9998cf412d"
#define Network_BaseNetwork_ClassNameShort "%fad0aaa8170143bf289205836c632c9998cf412d"
#define Network_BaseNetwork_TypeDefinitionIndex 18791

	namespace Network_BaseNetwork {

		// Functions
		constexpr const static size_t StartWrite = 0x63d8ce0;
	}

	// obf name: ::%df63b0588316330774ef6e84fd428e0f1b26f7c3
#define Network_SendInfo_ClassName "%df63b0588316330774ef6e84fd428e0f1b26f7c3"
#define Network_SendInfo_ClassNameShort "%df63b0588316330774ef6e84fd428e0f1b26f7c3"
#define Network_SendInfo_TypeDefinitionIndex 18812

	namespace Network_SendInfo {

		// Offsets
		constexpr const static size_t method = 0x0;
		constexpr const static size_t channel = 0x4;
		constexpr const static size_t priority = 0x8;
		constexpr const static size_t connections = 0x10;
		constexpr const static size_t connection = 0x18;
	}

	// obf name: ::%907a6f0d4ec6ff97c7bddf0499a0ff72357ff3c9
#define Network_Message_ClassName "%907a6f0d4ec6ff97c7bddf0499a0ff72357ff3c9"
#define Network_Message_ClassNameShort "%907a6f0d4ec6ff97c7bddf0499a0ff72357ff3c9"
#define Network_Message_TypeDefinitionIndex 18742

	namespace Network_Message {

		// Offsets
		constexpr const static size_t type = 0x20;
		constexpr const static size_t read = 0x18;
	}

	// obf name: ::%ad73a64135d37f039f819b18451de41f29cd1bb5
#define Network_NetRead_ClassName "%ad73a64135d37f039f819b18451de41f29cd1bb5"
#define Network_NetRead_ClassNameShort "%ad73a64135d37f039f819b18451de41f29cd1bb5"
#define Network_NetRead_TypeDefinitionIndex 18798

	namespace Network_NetRead {

		// Offsets
		constexpr const static size_t stream = 0x48;
	}

	// obf name: ::%0686b6fbde83690e0c0cd8d6de4b23997d0079b7
#define Network_NetWrite_ClassName "%0686b6fbde83690e0c0cd8d6de4b23997d0079b7"
#define Network_NetWrite_ClassNameShort "%0686b6fbde83690e0c0cd8d6de4b23997d0079b7"
#define Network_NetWrite_TypeDefinitionIndex 18774

	namespace Network_NetWrite {

		// Offsets
		constexpr const static size_t stream = 0x38;

		// Functions
		constexpr const static size_t WriteByte = 0x63b3340;
		constexpr const static size_t String = 0x63b1f40;
		constexpr const static size_t Send = 0x63aaeb0;
	}

#define LootPanel_TypeDefinitionIndex 5876

	namespace LootPanel {

		// Functions
		constexpr const static size_t get_Container_00 = 0x3d2b480;
	}

#define UIInventory_TypeDefinitionIndex 3110

	namespace UIInventory {

		// Functions
		constexpr const static size_t Close = 0x1d927e0;
	}

#define GrowableEntity_TypeDefinitionIndex 5232

	namespace GrowableEntity {

		// Offsets
		constexpr const static size_t Properties = 0x2c0;
		constexpr const static size_t State = 0x2d0;
	}

#define PlantProperties_TypeDefinitionIndex 6449

	namespace PlantProperties {

		// Offsets
		constexpr const static size_t stages = 0x28;
	}

#define PlantProperties_Stage_TypeDefinitionIndex 6448

	namespace PlantProperties_Stage {

		// Offsets
		constexpr const static size_t resources = 0xc;
	}

#define Text_TypeDefinitionIndex 21305

	namespace Text {

		// Offsets
		constexpr const static size_t m_Text = 0xd8;
	}

#define TOD_Sky_TypeDefinitionIndex 9377

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
		constexpr const static size_t get_Instance = 0x914b80;
	}

	// obf name: ::%2cb27bea7a7c02bd1fbc73517f5f763ecb99ccb7
#define TOD_Sky_Static_ClassName "TOD_Sky/%2cb27bea7a7c02bd1fbc73517f5f763ecb99ccb7"
#define TOD_Sky_Static_ClassNameShort "%2cb27bea7a7c02bd1fbc73517f5f763ecb99ccb7"
#define TOD_Sky_Static_TypeDefinitionIndex 9376

	namespace TOD_Sky_Static {

		// Offsets
		constexpr const static size_t instances = 0xb8;
	}

#define TOD_CycleParameters_TypeDefinitionIndex 9344

	namespace TOD_CycleParameters {

		// Functions
		constexpr const static size_t get_DateTime = 0x8f9140;
	}

#define TOD_AtmosphereParameters_TypeDefinitionIndex 9528

	namespace TOD_AtmosphereParameters {

		// Offsets
		constexpr const static size_t RayleighMultiplier = 0x10;
	}

#define TOD_DayParameters_TypeDefinitionIndex 8072

	namespace TOD_DayParameters {

		// Offsets
		constexpr const static size_t SkyColor = 0x28;
	}

#define TOD_NightParameters_TypeDefinitionIndex 9195

	namespace TOD_NightParameters {

		// Offsets
		constexpr const static size_t MoonColor = 0x10;
		constexpr const static size_t CloudColor = 0x38;
		constexpr const static size_t AmbientColor = 0x48;
		constexpr const static size_t AmbientMultiplier = 0x5c;
	}

#define TOD_StarParameters_TypeDefinitionIndex 7841

	namespace TOD_StarParameters {

		// Offsets
		constexpr const static size_t Size = 0x10;
		constexpr const static size_t Brightness = 0x14;
	}

#define TOD_CloudParameters_TypeDefinitionIndex 9239

	namespace TOD_CloudParameters {

		// Offsets
		constexpr const static size_t Brightness = 0x30;
	}

#define TOD_AmbientParameters_TypeDefinitionIndex 10081

	namespace TOD_AmbientParameters {

		// Offsets
		constexpr const static size_t Saturation = 0x14;
	}

#define UIHUD_TypeDefinitionIndex 670

	namespace UIHUD {

		// Offsets
		constexpr const static size_t Hunger = 0x28;
	}

#define HudElement_TypeDefinitionIndex 375

	namespace HudElement {

		// Offsets
		constexpr const static size_t lastValue = 0x30;
	}

#define UIBelt_TypeDefinitionIndex 5782

	namespace UIBelt {

		// Offsets
		constexpr const static size_t ItemIcons = 0x20;
	}

#define ItemModCompostable_TypeDefinitionIndex 726

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

#define EnvironmentManager_TypeDefinitionIndex 6994

	namespace EnvironmentManager {

		// Functions
		constexpr const static size_t Get = 0x4a5cb80;
	}

	// obf name: ::Phrase
#define Translate_Phrase_ClassName "%18a8c660af1ec6c41fcec673035c15378b0b3f46/Phrase"
#define Translate_Phrase_ClassNameShort "Phrase"
#define Translate_Phrase_TypeDefinitionIndex 24408

	namespace Translate_Phrase {

		// Offsets
		constexpr const static size_t legacyEnglish = 0x20;
	}

#define ResourceDispenser_GatherPropertyEntry_TypeDefinitionIndex 5275

	namespace ResourceDispenser_GatherPropertyEntry {

		// Offsets
		constexpr const static size_t gatherDamage = 0x10;
		constexpr const static size_t destroyFraction = 0x14;
		constexpr const static size_t conditionLost = 0x18;
	}

#define ResourceDispenser_GatherProperties_TypeDefinitionIndex 5276

	namespace ResourceDispenser_GatherProperties {

		// Offsets
		constexpr const static size_t Tree = 0x10;
		constexpr const static size_t Ore = 0x18;
		constexpr const static size_t Flesh = 0x20;
	}

#define UIChat_TypeDefinitionIndex 3257

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
		constexpr const static size_t InstanceList = 0x8;
	}

	// obf name: ::%d2e1e5a0fdf7c0d93f0ee56c2c56ace12281a61e
#define ListHashSet_ClassName "%d2e1e5a0fdf7c0d93f0ee56c2c56ace12281a61e<UIChat>"
#define ListHashSet_ClassNameShort "%d2e1e5a0fdf7c0d93f0ee56c2c56ace12281a61e"
#define ListHashSet_TypeDefinitionIndex -1

	namespace ListHashSet {

		// Offsets
		constexpr const static size_t vals = 0x10;
	}

#define PatrolHelicopter_TypeDefinitionIndex 2072

	namespace PatrolHelicopter {

		// Offsets
		constexpr const static size_t mainRotor = 0x278;
		constexpr const static size_t weakspots = 0x3e8;
	}

#define Chainsaw_TypeDefinitionIndex 222

	namespace Chainsaw {

		// Offsets
		constexpr const static size_t ammo = 0x38c;
	}

	// obf name: ::%374a12459a1fbdddf99f09a0685d80c45405566d
#define CameraUpdateHook_Static_ClassName "CameraUpdateHook/%374a12459a1fbdddf99f09a0685d80c45405566d"
#define CameraUpdateHook_Static_ClassNameShort "%374a12459a1fbdddf99f09a0685d80c45405566d"
#define CameraUpdateHook_Static_TypeDefinitionIndex 1128

	namespace CameraUpdateHook_Static {

		// Offsets
		constexpr const static size_t action = 0x0;
	}

#define SteamClientWrapper_TypeDefinitionIndex 2091

	namespace SteamClientWrapper {

		// Functions
		constexpr const static size_t GetAvatarTexture = 0x1203400;
	}

	// obf name: ::%590ef2f33f567adc0e0eb348e6ed7cd171c6b180
#define AimConeUtil_ClassName "%590ef2f33f567adc0e0eb348e6ed7cd171c6b180"
#define AimConeUtil_ClassNameShort "%590ef2f33f567adc0e0eb348e6ed7cd171c6b180"
#define AimConeUtil_TypeDefinitionIndex 3129

	namespace AimConeUtil {

		// Functions
		constexpr const static size_t GetModifiedAimConeDirection = 0x1de8f80;
	}

	// obf name: ::%8183cb494eb5d669fd1f8a25020094023eec8b02
#define Buttons_ConButton_ClassName "%64bbc2511c53c88a1a968c60a89dc6c5bdebb19b/%8183cb494eb5d669fd1f8a25020094023eec8b02"
#define Buttons_ConButton_ClassNameShort "%8183cb494eb5d669fd1f8a25020094023eec8b02"
#define Buttons_ConButton_TypeDefinitionIndex 5541

	namespace Buttons_ConButton {

		// Offsets
		constexpr const static size_t IsDown = 0x14;
	}

	// obf name: ::%2ae099320fdca10aa37b32fa50ba1529f173b3a0
#define Buttons_Static_ClassName "%64bbc2511c53c88a1a968c60a89dc6c5bdebb19b/%2ae099320fdca10aa37b32fa50ba1529f173b3a0"
#define Buttons_Static_ClassNameShort "%2ae099320fdca10aa37b32fa50ba1529f173b3a0"
#define Buttons_Static_TypeDefinitionIndex 5542

	namespace Buttons_Static {

		// Offsets
		constexpr const static size_t Pets = 0xfb0;
		constexpr const static size_t Attack = 0x7b0;
		constexpr const static size_t Attack2 = 0x978;
		constexpr const static size_t Forward = 0x1d8;
		constexpr const static size_t Backward = 0xb38;
		constexpr const static size_t Right = 0xfb8;
		constexpr const static size_t Left = 0xeb0;
		constexpr const static size_t Sprint = 0x958;
		constexpr const static size_t Use = 0xb58;

		// Functions
		constexpr const static size_t Pets_setter = 0x33625b0;
	}

#define PlayerModel_TypeDefinitionIndex 1330

	namespace PlayerModel {

		// Offsets
		constexpr const static size_t _multiMesh = 0x158;
		constexpr const static size_t position = 0x1e8;
		constexpr const static size_t newVelocity = 0x20c;
	}

#define SkinnedMultiMesh_TypeDefinitionIndex 6536

	namespace SkinnedMultiMesh {

		// Offsets
		constexpr const static size_t Renderers = 0x40;
	}

#define BaseMountable_TypeDefinitionIndex 2795

	namespace BaseMountable {

		// Offsets
		constexpr const static size_t pitchClamp = 0x294;
		constexpr const static size_t yawClamp = 0x29c;
		constexpr const static size_t canWieldItems = 0x2a4;
	}

#define ProgressBar_TypeDefinitionIndex 329

	namespace ProgressBar {

		// Offsets
		constexpr const static size_t Instance = 0x20;
		constexpr const static size_t timeCounter = 0x34;
	}

#define BowWeapon_TypeDefinitionIndex 3800

	namespace BowWeapon {

		// Offsets
		constexpr const static size_t attackReady = 0x410;
		constexpr const static size_t wasAiming = 0x420;
	}

#define CrossbowWeapon_TypeDefinitionIndex 4429

	namespace CrossbowWeapon {

		// Offsets
	}

#define MiniCrossbow_TypeDefinitionIndex 5610

	namespace MiniCrossbow {

		// Offsets
	}

	// obf name: ::%2d96db3226b9a643e7c7c48e234c0c1c2e647384
#define ConVar_Admin_Static_ClassName "%28e534c1c78da477070f13b2d9014604900a0da6/%2d96db3226b9a643e7c7c48e234c0c1c2e647384"
#define ConVar_Admin_Static_ClassNameShort "%2d96db3226b9a643e7c7c48e234c0c1c2e647384"
#define ConVar_Admin_Static_TypeDefinitionIndex 115

	namespace ConVar_Admin_Static {

		// Offsets
		constexpr const static size_t admintime = 0xac;

		// Functions
		constexpr const static size_t admintime_getter = 0x3373ef0;
		constexpr const static size_t admintime_setter = 0x33597b0;
	}

	// obf name: ::%3aa3171a6ec7bd6e988994faac37c25fee7b588a
#define ConVar_Player_Static_ClassName "%770eda7092150579771c0e099ab4dd2ae5303bc6/%3aa3171a6ec7bd6e988994faac37c25fee7b588a"
#define ConVar_Player_Static_ClassNameShort "%3aa3171a6ec7bd6e988994faac37c25fee7b588a"
#define ConVar_Player_Static_TypeDefinitionIndex 6701

	namespace ConVar_Player_Static {

		// Offsets
		constexpr const static size_t clientTickInterval = 0x100;

		// Functions
		constexpr const static size_t clientTickRate_getter = 0x336b8c0;
		constexpr const static size_t clientTickRate_setter = 0x335a120;
	}

#define ColliderInfo_TypeDefinitionIndex 1482

	namespace ColliderInfo {

		// Offsets
		constexpr const static size_t flags = 0x20;
	}

#define CodeLock_TypeDefinitionIndex 383

	namespace CodeLock {

		// Offsets
		constexpr const static size_t hasCode = 0x218;
		constexpr const static size_t HasAuth = 0x228;
		constexpr const static size_t HasGuestAuth = 0x229;
	}

#define AutoTurret_TypeDefinitionIndex 1320

	namespace AutoTurret {

		// Offsets
		constexpr const static size_t authorizedPlayers = 0x0;
		constexpr const static size_t lastYaw = 0x3d0;
		constexpr const static size_t muzzlePos = 0x3f0;
		constexpr const static size_t gun_yaw = 0x408;
		constexpr const static size_t gun_pitch = 0x410;
		constexpr const static size_t sightRange = 0x418;

		// Functions
		constexpr const static size_t IsAuthed = 0x0;
	}

#define Client_TypeDefinitionIndex 620

	namespace Client {

		// Functions
		constexpr const static size_t OnClientDisconnected = 0x3587c10;
		constexpr const static size_t OnClientDisconnected_vtableoff = 0x1b8;
	}

	// obf name: ::%8fc8c8fbcbacd35d759f2e8c21200afeaedadd90
#define ItemManager_Static_ClassName "%62b1dbd591fbf7f0994b7fb4c1da46f403472a05/%8fc8c8fbcbacd35d759f2e8c21200afeaedadd90"
#define ItemManager_Static_ClassNameShort "%8fc8c8fbcbacd35d759f2e8c21200afeaedadd90"
#define ItemManager_Static_TypeDefinitionIndex 3387

	namespace ItemManager_Static {

		// Offsets
		constexpr const static size_t itemList = 0x30;
		constexpr const static size_t itemDictionary = 0x68;
		constexpr const static size_t itemDictionaryByName = 0x50;
	}

	// obf name: ::%4264139c5e0198bce69d99dd6a210234b77b0d03
#define ConVar_Server_Static_ClassName "%f5482ebddc26fd0a84841d330b2db1b867fe0378/%4264139c5e0198bce69d99dd6a210234b77b0d03"
#define ConVar_Server_Static_ClassNameShort "%4264139c5e0198bce69d99dd6a210234b77b0d03"
#define ConVar_Server_Static_TypeDefinitionIndex 4806

	namespace ConVar_Server_Static {

		// Offsets
	}

#define ServerAdminUGCEntry_TypeDefinitionIndex 5540

	namespace ServerAdminUGCEntry {

		// Functions
		constexpr const static size_t ReceivedDataFromServer = 0x39ad910;
	}

#define LoadingScreen_TypeDefinitionIndex 3492

	namespace LoadingScreen {

		// Offsets
		constexpr const static size_t panel = 0x30;
	}

#define MixerSnapshotManager_TypeDefinitionIndex 3672

	namespace MixerSnapshotManager {

		// Offsets
		constexpr const static size_t defaultSnapshot = 0x20;
		constexpr const static size_t loadingSnapshot = 0x30;
	}

#define MapView_Static_ClassName "MapView/%a73749184a7d6260b334a8732d1ec27ebc3c51f4"
#define MapView_Static_ClassNameShort "%a73749184a7d6260b334a8732d1ec27ebc3c51f4"
#define MapView_TypeDefinitionIndex 1742

	namespace MapView {

		// Functions
		constexpr const static size_t WorldPosToImagePos = 0xe1e670;
	}

	// obf name: ::%84e7a8764aef2ee6e2e7ed8367595909f495eebb
#define GamePhysics_Static_ClassName "%1296eaf3b33f7e73f5d186ad1240bc086627a2e8/%84e7a8764aef2ee6e2e7ed8367595909f495eebb"
#define GamePhysics_Static_ClassNameShort "%84e7a8764aef2ee6e2e7ed8367595909f495eebb"
#define GamePhysics_Static_TypeDefinitionIndex 2843

	namespace GamePhysics_Static {

		// Offsets
		constexpr const static size_t hitBuffer = 0x28;
	}

	// obf name: ::%1296eaf3b33f7e73f5d186ad1240bc086627a2e8
#define GamePhysics_ClassName "%1296eaf3b33f7e73f5d186ad1240bc086627a2e8"
#define GamePhysics_ClassNameShort "%1296eaf3b33f7e73f5d186ad1240bc086627a2e8"
#define GamePhysics_TypeDefinitionIndex 2844

	namespace GamePhysics {

		// Functions
		constexpr const static size_t Trace = 0x1a358b0;
		constexpr const static size_t LineOfSightInternal = 0x1a48a50;
		constexpr const static size_t Verify = 0x1a5f300;
	}

#define InstancedDebugDraw_TypeDefinitionIndex 5017

	namespace InstancedDebugDraw {

		// Functions
		constexpr const static size_t AddInstance = 0x3316b30;
	}

	// obf name: ::%500caeb7ba0adc9605950411780d4bbbc2fe4b96
#define RaycastHitEx_ClassName "%500caeb7ba0adc9605950411780d4bbbc2fe4b96"
#define RaycastHitEx_ClassNameShort "%500caeb7ba0adc9605950411780d4bbbc2fe4b96"
#define RaycastHitEx_TypeDefinitionIndex 3656

	namespace RaycastHitEx {

		// Functions
		constexpr const static size_t GetEntity = 0x2326ee0;
	}

	// obf name: ::%b57ca90c76e43f211af98b6c9a536eed63bf88e9
#define OnParentDestroyingEx_ClassName "%b57ca90c76e43f211af98b6c9a536eed63bf88e9"
#define OnParentDestroyingEx_ClassNameShort "%b57ca90c76e43f211af98b6c9a536eed63bf88e9"
#define OnParentDestroyingEx_TypeDefinitionIndex 2677

	namespace OnParentDestroyingEx {

		// Functions
		constexpr const static size_t BroadcastOnParentDestroying = 0x1885150;
	}

	// obf name: ::%21cca7d0b254f61e92adf1b65db84575493a04ed
#define ConsoleNetwork_ClassName "%21cca7d0b254f61e92adf1b65db84575493a04ed"
#define ConsoleNetwork_ClassNameShort "%21cca7d0b254f61e92adf1b65db84575493a04ed"
#define ConsoleNetwork_TypeDefinitionIndex 5271

	namespace ConsoleNetwork {

		// Functions
		constexpr const static size_t ClientRunOnServer = 0x3718cc0;
	}

#define ThrownWeapon_TypeDefinitionIndex 7207

	namespace ThrownWeapon {

		// Offsets
		constexpr const static size_t maxThrowVelocity = 0x2e0;
	}

#define MapInterface_TypeDefinitionIndex 6899

	namespace MapInterface {

		// Offsets
		constexpr const static size_t scrollRectZoom = 0x30;
	}

#define ScrollRectZoom_TypeDefinitionIndex 5248

	namespace ScrollRectZoom {

		// Offsets
		constexpr const static size_t zoom = 0x28;
	}

#define MapView_TypeDefinitionIndex 1742

	namespace MapView {

		// Offsets
		constexpr const static size_t scrollRect = 0x40;
	}

#define StorageContainer_TypeDefinitionIndex 5891

	namespace StorageContainer {

		// Offsets
		constexpr const static size_t inventorySlots = 0x2c0;
	}

#define PlayerCorpse_TypeDefinitionIndex 2674

	namespace PlayerCorpse {

		// Offsets
		constexpr const static size_t clientClothing = 0x2f0;
	}

#define TimedExplosive_TypeDefinitionIndex 3044

	namespace TimedExplosive {

		// Offsets
		constexpr const static size_t explosionRadius = 0x1b4;
	}

#define SmokeGrenade_TypeDefinitionIndex 2339

	namespace SmokeGrenade {

		// Offsets
		constexpr const static size_t smokeEffectInstance = 0x258;
	}

#define GrenadeWeapon_TypeDefinitionIndex 5311

	namespace GrenadeWeapon {

		// Offsets
		constexpr const static size_t drop = 0x2f8;
	}

#define ViewmodelLower_TypeDefinitionIndex 1030

	namespace ViewmodelLower {

		// Offsets
		constexpr const static size_t lowerOnSprint = 0x20;
		constexpr const static size_t lowerWhenCantAttack = 0x21;
		constexpr const static size_t shouldLower = 0x28;
		constexpr const static size_t rotateAngle = 0x2c;
	}

	// obf name: ::%5106aeba6cd45ff17bc4419dd25f618312bd38ca
#define ConVar_Client_Static_ClassName "%a11fcbb40a5af1a74680f4cb99f9e23ef1e3e910/%5106aeba6cd45ff17bc4419dd25f618312bd38ca"
#define ConVar_Client_Static_ClassNameShort "%5106aeba6cd45ff17bc4419dd25f618312bd38ca"
#define ConVar_Client_Static_TypeDefinitionIndex 4926

	namespace ConVar_Client_Static {

		// Offsets
		constexpr const static size_t camlerp = 0x77c;
		constexpr const static size_t camspeed = 0x6b0;
	}

#define SamSite_TypeDefinitionIndex 3860

	namespace SamSite {

		// Offsets
		constexpr const static size_t staticRespawn = 0x3b0;
		constexpr const static size_t Flag_TargetMode = 0x3ec;
	}

#define ServerProjectile_TypeDefinitionIndex 1582

	namespace ServerProjectile {

		// Offsets
		constexpr const static size_t drag = 0x34;
		constexpr const static size_t gravityModifier = 0x38;
		constexpr const static size_t speed = 0x3c;
		constexpr const static size_t radius = 0x5c;
	}

#define UIFogOverlay_TypeDefinitionIndex 3276

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t group = 0x28;
	}

#define FoliageGrid_TypeDefinitionIndex 4518

	namespace FoliageGrid {

		// Offsets
		constexpr const static size_t CellSize = 0x28;
	}

#define ItemModWearable_TypeDefinitionIndex 2890

	namespace ItemModWearable {

		// Offsets
		constexpr const static size_t movementProperties = 0x48;
	}

#define ClothingMovementProperties_TypeDefinitionIndex 1711

	namespace ClothingMovementProperties {

		// Offsets
		constexpr const static size_t speedReduction = 0x18;
	}

#define GestureConfig_TypeDefinitionIndex 4622

	namespace GestureConfig {

		// Offsets
		constexpr const static size_t actionType = 0x90;
	}

#define RCMenu_TypeDefinitionIndex 655

	namespace RCMenu {

		// Offsets
		constexpr const static size_t autoTurretFogDistance = 0x134;
	}

	// obf name: ::%79a1b01698d8635bfa5afca0972876de7c0a1c33
#define Facepunch_Network_Raknet_Client_ClassName "%79a1b01698d8635bfa5afca0972876de7c0a1c33"
#define Facepunch_Network_Raknet_Client_ClassNameShort "%79a1b01698d8635bfa5afca0972876de7c0a1c33"
#define Facepunch_Network_Raknet_Client_TypeDefinitionIndex 23131

	namespace Facepunch_Network_Raknet_Client {

		// Functions
		constexpr const static size_t IsConnected = 0x6442850;
		constexpr const static size_t IsConnected_vtableoff = 0x408;
	}

	// obf name: ::%44eaac6ee59ec21e384dca4391995746a3e52902
#define EncryptedValue_ClassName "%44eaac6ee59ec21e384dca4391995746a3e52902<System/Int32>"
#define EncryptedValue_ClassNameShort "%44eaac6ee59ec21e384dca4391995746a3e52902"
#define EncryptedValue_TypeDefinitionIndex -1

	namespace EncryptedValue {

		// Offsets
		constexpr const static size_t _value = 0x0;
		constexpr const static size_t _padding = 0x10;
	}

	// obf name: ::%f1e8700a32ee5f38e2dc459d950e59f463894226
#define HiddenValue_ClassName "%f1e8700a32ee5f38e2dc459d950e59f463894226<BaseNetworkable/%d9ecec75e6fdc88bff8469f874201142584e8926>"
#define HiddenValue_ClassNameShort "%f1e8700a32ee5f38e2dc459d950e59f463894226"
#define HiddenValue_TypeDefinitionIndex -1

	namespace HiddenValue {

		// Offsets
		constexpr const static size_t _handle = 0x18;
		constexpr const static size_t _accessCount = 0x10;
		constexpr const static size_t _hasValue = 0x14;
	}

#define SimplePrivilege___c__DisplayClass3_0_TypeDefinitionIndex -1

	namespace SimplePrivilege___c__DisplayClass3_0 {

		// Functions
		constexpr const static size_t IsAuthed = 0x0;
	}

#define ItemModRFListener_TypeDefinitionIndex 4124

	namespace ItemModRFListener {

		// Functions
		constexpr const static size_t ConfigureClicked = 0x281bd10;
	}

#define UIFogOverlay_TypeDefinitionIndex 3276

	namespace UIFogOverlay {

		// Offsets
		constexpr const static size_t Instance = 0x18;
	}

	// obf name: ::%af1530cad7d55ea8486cf6d828aa479e303b40fd
#define BufferStream_ClassName "%af1530cad7d55ea8486cf6d828aa479e303b40fd"
#define BufferStream_ClassNameShort "%af1530cad7d55ea8486cf6d828aa479e303b40fd"
#define BufferStream_TypeDefinitionIndex 7412

	namespace BufferStream {

		// Offsets
		constexpr const static size_t _buffer = 0x10;

		// Functions
		constexpr const static size_t EnsureCapacity = 0x96a91d0;
	}

#define FreeableLootContainer_TypeDefinitionIndex 2406

	namespace FreeableLootContainer {

		// Offsets
	}

#define BlowPipeWeapon_TypeDefinitionIndex 2601

	namespace BlowPipeWeapon {

		// Offsets
	}

#define AttackHelicopterRockets_TypeDefinitionIndex 6417

	namespace AttackHelicopterRockets {

		// Functions
		constexpr const static size_t GetProjectedHitPos = 0x435d0a0;
	}

#define OutlineManager_TypeDefinitionIndex 7174

	namespace OutlineManager {

		// Offsets
	}

	// obf name: ::%a5a183006246336a99cd167a391364043d1bf841
#define ConsoleSystem_Command_ClassName "%9bddd09c917ef022d57c4e25d7d8a96c739e2741/%a5a183006246336a99cd167a391364043d1bf841"
#define ConsoleSystem_Command_ClassNameShort "%a5a183006246336a99cd167a391364043d1bf841"
#define ConsoleSystem_Command_TypeDefinitionIndex 23617

	namespace ConsoleSystem_Command {

		// Offsets
		constexpr const static size_t GetOveride = 0x68;
		constexpr const static size_t SetOveride = 0x88;
		constexpr const static size_t Call = 0x70;
	}

	// obf name: ::%0c83da0abaac26f40d6b3d6962c979a1ae650b61
#define ConsoleSystem_Option_ClassName "%9bddd09c917ef022d57c4e25d7d8a96c739e2741/%0c83da0abaac26f40d6b3d6962c979a1ae650b61"
#define ConsoleSystem_Option_ClassNameShort "%0c83da0abaac26f40d6b3d6962c979a1ae650b61"
#define ConsoleSystem_Option_TypeDefinitionIndex 23627

	namespace ConsoleSystem_Option {

		// Offsets
	}

	// obf name: ::%9531c3f75cb5bb7a3d559379ac37c837744326cf
#define ConsoleSystem_Arg_ClassName "%9bddd09c917ef022d57c4e25d7d8a96c739e2741/%9531c3f75cb5bb7a3d559379ac37c837744326cf"
#define ConsoleSystem_Arg_ClassNameShort "%9531c3f75cb5bb7a3d559379ac37c837744326cf"
#define ConsoleSystem_Arg_TypeDefinitionIndex 23615

	namespace ConsoleSystem_Arg {

		// Offsets
		constexpr const static size_t Option = 0x40;
	}

	// obf name: ::%44bcacbf0f6aa0809d43dfc0f5f19b1eefc8e760
#define ConsoleSystem_Index_Client_ClassName "%9bddd09c917ef022d57c4e25d7d8a96c739e2741/%30d8808650a2acb64505db5986a447636ce4ceeb.%44bcacbf0f6aa0809d43dfc0f5f19b1eefc8e760"
#define ConsoleSystem_Index_Client_ClassNameShort "%44bcacbf0f6aa0809d43dfc0f5f19b1eefc8e760"
#define ConsoleSystem_Index_Client_TypeDefinitionIndex 23623

	namespace ConsoleSystem_Index_Client {

		// Functions
		constexpr const static size_t Find = 0x6322870;
	}

#define String_TypeDefinitionIndex 10495

	namespace String {

		// Offsets
		constexpr const static size_t FastAllocateString = 0x84b6d40;
	}

	// obf name: ::%7dca343fa49f55397b6942f22d51df3920bc644e
#define EntityRef_ClassName "%7dca343fa49f55397b6942f22d51df3920bc644e"
#define EntityRef_ClassNameShort "%7dca343fa49f55397b6942f22d51df3920bc644e"
#define EntityRef_TypeDefinitionIndex 2713

	namespace EntityRef {

		// Offsets
		constexpr const static size_t Get = 0x18bdf00;
	}

#define ConVar_Debugging_TypeDefinitionIndex -1

	namespace ConVar_Debugging {

		// Functions
		constexpr const static size_t debugcamera = 0x3379750;
		constexpr const static size_t noclip = 0x2d7c200;
	}

#define CursorManager_TypeDefinitionIndex 7127

	namespace CursorManager {

		// Offsets
	}

	// obf name: ::%f3984b25b0ed752bbf58a1645b26f2fc8e144720
#define ProtoBuf_ProjectileShoot_ClassName "%f3984b25b0ed752bbf58a1645b26f2fc8e144720"
#define ProtoBuf_ProjectileShoot_ClassNameShort "%f3984b25b0ed752bbf58a1645b26f2fc8e144720"
#define ProtoBuf_ProjectileShoot_TypeDefinitionIndex 7242

	namespace ProtoBuf_ProjectileShoot {

		// Offsets
		constexpr const static size_t projectiles = 0x18;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x88c1580;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x88c4ef0;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%d3740e93660486df274ff9bb29106e5056b43725
#define ProtoBuf_ProjectileShoot_Projectile_ClassName "%f3984b25b0ed752bbf58a1645b26f2fc8e144720/%d3740e93660486df274ff9bb29106e5056b43725"
#define ProtoBuf_ProjectileShoot_Projectile_ClassNameShort "%d3740e93660486df274ff9bb29106e5056b43725"
#define ProtoBuf_ProjectileShoot_Projectile_TypeDefinitionIndex 7241

	namespace ProtoBuf_ProjectileShoot_Projectile {

		// Offsets
		constexpr const static size_t projectileID = 0x18;
		constexpr const static size_t startPos = 0x20;
		constexpr const static size_t startVel = 0x2c;
		constexpr const static size_t seed = 0x10;
	}

	// obf name: ::%0c8c567eea549c2f8db093d28076044f391624eb
#define ProtoBuf_PlayerProjectileUpdate_ClassName "%0c8c567eea549c2f8db093d28076044f391624eb"
#define ProtoBuf_PlayerProjectileUpdate_ClassNameShort "%0c8c567eea549c2f8db093d28076044f391624eb"
#define ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex 7648

	namespace ProtoBuf_PlayerProjectileUpdate {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t curPosition = 0x2c;
		constexpr const static size_t curVelocity = 0x14;
		constexpr const static size_t travelTime = 0x28;
		constexpr const static size_t ShouldPool = 0x10;

		// Functions
		constexpr const static size_t Dispose = 0x8f83710;
		constexpr const static size_t WriteToStreamDelta = 0x8f8c310;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8f87150;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%bfc1d0f6d97db2ff8769a1b0ebd73766cbe3f0ee
#define ProtoBuf_PlayerProjectileAttack_ClassName "%bfc1d0f6d97db2ff8769a1b0ebd73766cbe3f0ee"
#define ProtoBuf_PlayerProjectileAttack_ClassNameShort "%bfc1d0f6d97db2ff8769a1b0ebd73766cbe3f0ee"
#define ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex 7627

	namespace ProtoBuf_PlayerProjectileAttack {

		// Offsets
		constexpr const static size_t hitVelocity = 0x18;
		constexpr const static size_t hitDistance = 0x24;
		constexpr const static size_t travelTime = 0x10;
		constexpr const static size_t playerAttack = 0x28;

		// Functions
		constexpr const static size_t WriteToStreamDelta = 0x8eb6e00;
		constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1b8;
		constexpr const static size_t WriteToStream = 0x8eb4d10;
		constexpr const static size_t WriteToStream_vtableoff = 0x1e8;
	}

	// obf name: ::%fa4092d8efba18467269a02e3c8057ed22dfcda0
#define ProtoBuf_PlayerAttack_ClassName "%fa4092d8efba18467269a02e3c8057ed22dfcda0"
#define ProtoBuf_PlayerAttack_ClassNameShort "%fa4092d8efba18467269a02e3c8057ed22dfcda0"
#define ProtoBuf_PlayerAttack_TypeDefinitionIndex 7341

	namespace ProtoBuf_PlayerAttack {

		// Offsets
		constexpr const static size_t projectileID = 0x20;
		constexpr const static size_t attack = 0x18;
	}

	// obf name: ::%59cb0bc6ebfb8aff46509b7d8b0123f9a4471b39
#define ProtoBuf_Attack_ClassName "%59cb0bc6ebfb8aff46509b7d8b0123f9a4471b39"
#define ProtoBuf_Attack_ClassNameShort "%59cb0bc6ebfb8aff46509b7d8b0123f9a4471b39"
#define ProtoBuf_Attack_TypeDefinitionIndex 7536

	namespace ProtoBuf_Attack {

		// Offsets
		constexpr const static size_t pointStart = 0x40;
		constexpr const static size_t pointEnd = 0x74;
		constexpr const static size_t hitID = 0x38;
		constexpr const static size_t hitBone = 0x58;
		constexpr const static size_t hitNormalLocal = 0x4c;
		constexpr const static size_t hitPositionLocal = 0x24;
		constexpr const static size_t hitNormalWorld = 0x5c;
		constexpr const static size_t hitPositionWorld = 0x68;
		constexpr const static size_t hitPartID = 0x80;
		constexpr const static size_t hitMaterialID = 0x14;
		constexpr const static size_t srcParentID = 0x30;
		constexpr const static size_t dstParentID = 0x18;
	}
}