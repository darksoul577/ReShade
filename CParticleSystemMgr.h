#pragma once

#include "IAppSystem.h"

struct ParticleFilterType_t;
struct ParticleFunctionType_t;

struct ParticleFullRenderData_Scalar_View;

class CParticleVisibilityData;
class IParticleSnapshot;
class IParticleSystemQuery;
class ISceneWorld;
class CParticleSystemDefinition;

struct InfoStruct
{
    const char* name;
    //....
};
struct WeakHandleContents_InfoForResourceTypeIParticleSystemDefinition
{
    CParticleSystemDefinition* systemDefinition;
    InfoStruct* info;
    char _pad[0x200];
};

struct CWeakHandle_InfoForResourceTypeIParticleSystemDefinition
{
    WeakHandleContents_InfoForResourceTypeIParticleSystemDefinition* contents;
};

class CParticleSystemMgr : IAppSystem
{
public:
    virtual void SetFallbackParameters(float, float, float, float); // 11
    virtual void SetSystemLevel(int, int);
    virtual void SetLowViolence(bool status);
    virtual bool IsLowViolence();
    virtual void* FindParticleSystem(const char*, bool);
    virtual void* GetParticleSystemDefinitionBinding();
    virtual void* CreateParticleCollection_Handle(CWeakHandle_InfoForResourceTypeIParticleSystemDefinition* info, void*, IParticleSystemQuery*, bool, float, int); //17
    virtual void* CreateParticleCollection(const char*, void*, IParticleSystemQuery*, bool, float, int); // 18
    virtual void DestroyParticleCollection(void*); //19
    virtual void sub_135CC0();
    virtual void sub_135CC0_2();
    virtual void sub_135CD0();
    virtual const char* GetParticleFieldName(ParticleFilterType_t);
    virtual int  GetParticleOperatorCount(ParticleFunctionType_t);
    virtual void* GetParticleOperator(ParticleFunctionType_t, int);
    virtual void SetLastSimulationTime(float time);
    virtual float GetLastSimulationTime();
    virtual void SetLastSimulationDuration(float duration);
    virtual float GetLastSimulationDuration();
    virtual void DumpParticleList(const char*);
    virtual void CreateParticleSceneObject(const char*, ISceneWorld*, IParticleSystemQuery*, float, int);
    virtual void CreateParticleSceneObject2(void* CWeakHandle_InfoForResourceTypeIParticleSystemDefinition, ISceneWorld*, IParticleSystemQuery*, float, int);
    virtual void CreateParticleSceneObject3(void*, ISceneWorld*, bool);
    virtual void GenerateExtendedSortedIndexList();
    virtual int ParticleRandomInt(void*, int min, int max);
    virtual float ParticleRandomFloat(void*, float min, float max);
    virtual const char* GetParticleAttributeName(int);
    virtual void sub_135B00();
    virtual void sub_1362F0();
    virtual void sub_135AB0();
    virtual void sub_1183B0();
    virtual void sub_135B20();
    virtual IParticleSnapshot CreateParticleSnapshot();
    virtual void DestroyParticleSnapshot(IParticleSnapshot*);
    virtual void sub_135A80();
    virtual void sub_135A90();
    virtual void sub_135D60();
};