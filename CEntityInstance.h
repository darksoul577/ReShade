#pragma once

struct SchemaClassBinding {
	SchemaClassBinding* parent; // I THINK
	const char* bindingName; // ex: C_World
	const char* dllName; // ex: libclient.so
	const char* libName; // ex: client
};

enum OverlayFlags_t : unsigned long long
{
	BBOX = (1 << 2), //4
	ABSBOX = (1 << 5),//32
	RBOX = (1 << 6), //64
	ENTITYBOUNDS = (1 << 7), //128 - Looks like it depends on a byte being set in the class.
	ENTITYATTACHMENTS = (3 << 8), //BYTE1(flags) & 3
	ENTITYJOINTINFO = 0x40000,
	ENTITYSKELETON = (24 << 8), //BYTE1(flags) & 24 // kinda slow.
	ENTITYHITBOXES = (192 << 8), //BYTE1(flags) & 192
	BUDDHA = 0x40000000,
	ENTITYVIEWOFFSET = 0x800000000
};

enum DOTATeam_t : int {
	DOTA_TEAM_INVALID = -1,
	DOTA_TEAM_FIRST = 2,
	DOTA_TEAM_RADIANT = 2, //Radiant team.
	DOTA_TEAM_DIRE = 3, 	//Dire team.
	DOTA_TEAM_NEUTRALS = 4, //Neutral.
	DOTA_TEAM_NOTEAM = 5,
	DOTA_TEAM_CUSTOM_1 = 6,
	DOTA_TEAM_CUSTOM_MIN = 6,
	DOTA_TEAM_CUSTOM_2 = 7,
	DOTA_TEAM_CUSTOM_3 = 8,
	DOTA_TEAM_CUSTOM_COUNT = 8,
	DOTA_TEAM_CUSTOM_4 = 9,
	DOTA_TEAM_CUSTOM_5 = 10,
	DOTA_TEAM_CUSTOM_6 = 11,
	DOTA_TEAM_CUSTOM_7 = 12,
	DOTA_TEAM_CUSTOM_8 = 13,
	DOTA_TEAM_CUSTOM_MAX = 13,
	DOTA_TEAM_COUNT = 14
};

class CEntityInstance
{
public:
	virtual SchemaClassBinding* SchemaDynamicBinding(); // 0 <---- VERIFIED
	virtual void Destroy(); // 
	virtual int GetRefEHandle();
	virtual int GetScriptDesc();
	virtual void Connect(); // 
	virtual void Precache();
	virtual void AddedToEntityDatabase();
	virtual void Spawn();
	virtual void PostDataUpdate();
	virtual void Activate();
	virtual void UpdateOnRemove();
	virtual void OnSetDormant();
	virtual void PreDataUpdate();
	virtual void DrawEntityDebugOverlays(OverlayFlags_t flags); // 13 <---- VERIFIED 
	virtual void Save();
	virtual void Restore();
	virtual void OnSave();
	virtual void OnRestore();
	virtual void ObjectCaps();
	virtual void RequiredEdictIndex();
	virtual void NetworkStateChanged();
	virtual void NetworkStateChanged2();
	virtual void pad_unk_lwss_ads(); // 22  #STR: "%d:%s::%s %s"
	virtual void AddChangeAccessorPath();
	virtual void ReloadPrivateScripts(); // 24, #STR: "%s executing script: %s\n"
	virtual void pad_unk_obc_like(); // 25

	//C_BaseEntity
	virtual void* GetPredDescMap(); // 26, 
	virtual void* GetCollideable(); // 27, 
	virtual void GetPredictionCopyable(); // 28, 
	virtual void YouForgotToImplementOrDeclareClientClass(); // 29, 
	virtual void* GetClientClass(); // 30, 
	virtual void SpawnShared(); // 31, 
	virtual void PopulatePoseParameters(); // 32, 
	virtual void PreFirstNetworkUpdate(); // 33, 
	virtual void GetBaseModelEntity(); // 34, 
	virtual void GetBaseAnimating(); // 35, 
	virtual void n_36(); // 36, 
	virtual void n_37(); // 37, 
	virtual void Classify(); // 38, 
	virtual void ModifyEconParticles(); // 39, 
	virtual void ShouldSavePhysics(); // 40, 
	virtual void GetShadowDrawMaterial(); // 41, 
	virtual bool IsAbleToHaveFireEffect(); // 42, 
	virtual bool IsSelectable(); // 43, 
	virtual bool ReceivesMouseoverButNotSelection(); // 44, 
	virtual float GetRingRadius(); // 45, 
	virtual void UpdateFlexControllers(); // 46, 
	virtual void SetupWeights(); // 47, 
	virtual void GetVectors(); // 48, 
	virtual void WorldAlignMins(); // 49, 
	virtual void WorldAlignMaxs(); // 50, 
	virtual void WorldSpaceCenter(); // 51, 
	virtual void ComputeWorldSpaceSurroundingBox(); // 52, 
	virtual void UpdateTransmitState(); // 53, 
	virtual void ValidateModelIndex(); // 54, 
	virtual void AsParticleEHandle(); // 55, 
	virtual void OnNewParticleEffect(); // 56, 
	virtual void OnParticleEffectDeleted(); // 57, 
	virtual void PredCopy_SetHeapSize(); // 58, 
	virtual void PredCopy_GetStructBase(); // 59, 
	virtual void PredCopy_GetOffsetType(); // 60, 
	virtual void PredCopy_SetCommand(); // 61, 
	virtual void PredCopy_GetCommand(); // 62, 
	virtual void PredCopy_Alloc(); // 63, 
	virtual void PredCopy_Tell(); // 64, 
	virtual void PredCopy_GetHeaderBlock(); // 65, 
	virtual void GetMouth(); // 66, 
	virtual void GetSoundSpatialization(); // 67, 
	virtual void LookupAttachment(); // 68, 
	virtual void GetAttachment(); // 69, 
	virtual void InvalidateAttachments(); // 70, 
	virtual void OnBoneTransformsChanged(); // 71, 
	virtual void ChangeTeam(); // 72, 
	virtual bool InSameTeam(); // 73, 
	virtual bool InLocalTeam(); // 74, 
	virtual void DrawDebugTextOverlays(); // 75
	virtual bool IsValidIDTarget(); // 76, 
	virtual const char* GetIDString(); // 77, 
	virtual bool IsPotentiallyUsable(); // 78, 
	virtual const char* GetUseString(); // 79, 
	virtual void IsAbleToGlow(); // 80, 
	virtual void GetUseType(); // 81, 
	virtual void* GetGlowEntity(); // 82, 
	virtual void IsSaveNonNetworkable(); // 83, 
	virtual void UpdateVisibility(); // 84, 
	virtual void ShouldDraw(); // 85, 
	virtual void Simulate(); // 86, 
	virtual void FrameSimulate(); // 87, 
	virtual void n_88(); // 88, 
	virtual void OnDataChanged(); // 89, 
	virtual void OnPreDataChanged(); // 90, 
	virtual void ShouldTransmit(); // 91, 
	virtual void GetClientVehicle(); // 92, 
	virtual void OverrideAlphaModulation(); // 93, 
	virtual void OverrideShadowAlphaModulation(); // 94, 
	virtual void ComputeClientSideReplacementModel(); // 95, 
	virtual void Interpolate(); // 96, 
	virtual void CreateLightEffects(); // 97, 
	virtual void Clear(); // 98, 
	virtual void GetTextureAnimationStartTime(); // 99, 
	virtual void TextureAnimationWrapped(); // 100, 
	virtual void ShadowCastType(); // 101, 
	virtual void ShouldReceiveProjectedTextures(); // 102, 
	virtual void AddDecal(); // 103, 
	virtual void OnTakeDamage(); // 104, 
	virtual void TakeDamage(); // 105, 
	virtual void n_106(); // 106, 
	virtual void n_107(); // 107,  
	virtual void GetPredictionOwner(); // 112, 
	virtual void n_113(); // 113, 
	virtual void InitPredictable(); // 114, 
	virtual void SetPredictable(bool); // 115, 
	virtual void DecalTrace(); // 116, 
	virtual void ImpactTrace(); // 117, 
	virtual bool ShouldPredict(); // 118, 
	virtual void PreRender(); // 119, 
	virtual const char* CBE_PlayerName(); // 120, 
	virtual void GetUsePriority(); // 121, 
	virtual void EstimateAbsVelocity(); // 122, 
	virtual void CanBePoweredUp(); // 123, 
	virtual void AttemptToPowerup(); // 124, 
	virtual void IsCurrentlyTouching(); // 125, 
	virtual void ClientThink(); // 126, 
	virtual void GetThinkHandle(); // 127, 
	virtual void SetThinkHandle(); // 128, 
	virtual void SetNextClientThink(); // 129, 
	virtual void PhysicsSimulate(); // 130, 
	virtual void SimulateThinkInterval(); // 131, 
	virtual void PhysicsSolidMaskForEntity(); // 132, 
	virtual void* ClothGetEntityInstanceSettings(); // 133, 
	virtual void NotifySystemEvent(); // 134, 
	virtual void SUB_Remove(); // 135, 
	virtual void ExtraSceneObjectUpdater(); // 136, 
	virtual void FireBullets(); // 137, RagdollImpact
	virtual void DoImpactEffect(); // 138, 
	virtual void MakeTracer(); // 139, 
	virtual void GetTracerAttachment(); // 140, 
	virtual void GetTracerType(); // 141, 
	virtual void GetBeamTraceFilter(); // 142, 
	virtual void DispatchTraceAttack(); // 143, 
	virtual void TraceAttack(); // 144, 
	virtual void n_145(); // 145, 
	virtual bool ShouldDrawWaterImpacts(); // 146, 
	virtual bool ShouldDrawUnderwaterBulletBubbles(); // 147, 
	virtual void HandleShotImpactingWater(); // 148, STR: gunshotsplash
	virtual void BloodColor(); 
	virtual void n_150(); 
	virtual bool IsPlayer();  
	virtual bool IsHMDAvatar();
	virtual void n_153(); 
	virtual bool IsBaseCombatCharacter();
	virtual void* MyCombatCharacterPointer();
	virtual void* MyCombatCharacterPointer2();
	virtual bool IsBaseCombatWeapon();
	virtual void* MyCombatWeaponPointer();
	virtual bool IsBaseObject();
	virtual bool IsBaseTrain();
	virtual bool IsNextBot();
	virtual void* MyInfectedPointer();
	virtual void* MyInfectedRagdollPointer();
	virtual bool IsSprite();
	virtual int GetMaxHealth();
	virtual void SetHealth(int);
	virtual int GetHealth();
	virtual int GetActualHealth();
	virtual void ModifyOrAppendCriteria();
	virtual void WantSpawnCallOnPreData();
	virtual void* EyePosition();
	virtual void EyeAngles();
	virtual void LocalEyeAngles();
	virtual void EarPosition();
	virtual void GetFriction();
	virtual void GetViewOffset();
	virtual void GetSmoothedVelocity();
	virtual void GetVelocity();
	virtual void IsMoving();
	virtual void OnGroundChanged(); 
	virtual void GetGroundVelocityToApply();
	virtual void GetAttackDamageScale();
	virtual void InternalSetEffects();
	virtual void GetS1Skin();
	virtual void BoneMergeFastCullBloat();
	virtual void GetAimEntOrigin();
	virtual void SetupBones();
	virtual void AddRagdollToFadeQueue();
	virtual void OnLeftClick();
	virtual void OnRightClick(); 
	virtual void OnCursorEntered();
	virtual void OnCursorExited();
	virtual void GetSelection();
	virtual void GenericSelectionGetClickValidBehaviors();
	virtual void PerformCustomPhysics();
	virtual void sub_2BAEE50();
	virtual void* GetRenderOrigin();
	virtual void GetRenderAngles();
	virtual void GetObserverCamOrigin();
	virtual void RenderableToWorldTransform(); 
	virtual void DrawModel();

	//C_BaseModelEntity
	virtual void OnNewModel(); // 
	virtual void GetColorModulation(); // 
	virtual void GetGlobalFadeScale(); // 
	virtual void DamageDecal(); //  #STR: "ManhackCut", "BulletProof"
	virtual void SetViewOffset(); // 
	virtual bool CanBeSeenByTeam(DOTATeam_t team); //  203
	virtual void IsPartOfFOWSystem(); 
};
