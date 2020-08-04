#pragma once
#include "interfaces.h"

// CGameEntitySystem
CEntityInstance* OnRemoveEntity(CGameEntitySystem*, CEntityInstance*, EntityHandle);
CEntityInstance* OnAddEntity(CGameEntitySystem*, CEntityInstance*, EntityHandle);

// panel
void PaintTraverse(IVPanel*, IVGuiPaintSurface*, VPANEL, bool, bool);

// ParticleSystemMgr
void* CreateParticleCollection(CParticleSystemMgr* thisptr, CWeakHandle_InfoForResourceTypeIParticleSystemDefinition* info, void* unk, IParticleSystemQuery* query, bool bUnk, float fUnk, int iUnk);

// CParticleCollection
void SetRenderingEnabled(void*, bool);

CEntityInstance* OnAddEntity(CGameEntitySystem* ecx, CEntityInstance* ptr, EntityHandle index)
{
	auto ret = entityVMT->GetOriginalMethod(OnAddEntity)(ecx, ptr, index);
	const char* typeName = ptr->SchemaDynamicBinding()->bindingName;

	if (strstr(typeName, "DOTA_Unit_Hero")) {

		auto alreadyExists = false;
		for (auto hero : Heroes)
		{
			if (typeName == hero->SchemaDynamicBinding()->bindingName) //prevent adding illusions by checking for duplicates
			{
				alreadyExists = true;
				break;
			}
		}

		if (!alreadyExists)
		{
			Heroes.push_back(ptr);
			//printf("Adding %s\n", typeName);
		}
	}

	return ret;
}

CEntityInstance* OnRemoveEntity(CGameEntitySystem* ecx, CEntityInstance* ptr, EntityHandle index)
{
	const char* typeName = ptr->SchemaDynamicBinding()->bindingName;

	if (strstr(typeName, "DOTA_Unit_Hero")) {
		for (size_t i = Heroes.size(); i-- > 0; ) {
			if (Heroes[i] == ptr) {
				Heroes.erase(Heroes.begin() + i);
				//	printf("Removing %s\n", typeName);
				break;
			}
		}
	}

	return entityVMT->GetOriginalMethod(OnRemoveEntity)(ecx, ptr, index);
}

void* CreateParticleCollection(CParticleSystemMgr* thisptr, CWeakHandle_InfoForResourceTypeIParticleSystemDefinition* info, void* unk, IParticleSystemQuery* query, bool bUnk, float fUnk, int iUnk)
{
	void* particleCollection = particleMgrVMT->GetOriginalMethod(CreateParticleCollection)(thisptr, info, unk, query, bUnk, fUnk, iUnk);

	//check if we have a vtable
	if (particleCollectionVMT)  //we've already created a vtable
	{
		//change pointer in particles to point to our updated vtable
		particleCollectionVMT->ApplyVMT(particleCollection);
	}
	else {   //no vtable, so create one
		particleCollectionVMT = new VMT(particleCollection);
		particleCollectionVMT->HookVMT(SetRenderingEnabled, 88);
		particleCollectionVMT->ApplyVMT(particleCollection);
	}

	return particleCollection;
}

void PaintTraverse(IVPanel* ecx, IVGuiPaintSurface* surface, VPANEL vpanel, bool force_repaint, bool allow_force)
{
	panelVMT->GetOriginalMethod(PaintTraverse)(ecx, surface, vpanel, force_repaint, allow_force);

	for (auto hero : Heroes)
	{
		if (hero->CanBeSeenByTeam(DOTA_TEAM_RADIANT) && hero->CanBeSeenByTeam(DOTA_TEAM_DIRE))
			hero->DrawEntityDebugOverlays(ABSBOX);
	}
}

void SetRenderingEnabled(void* thisptr, bool state)
{
	particleCollectionVMT->GetOriginalMethod(SetRenderingEnabled)(thisptr, true);
}
