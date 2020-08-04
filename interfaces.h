#pragma once

#include "pch.h"
#include "IVPanel.h"
#include "CGameEntitySystem.h"
#include "CParticleSystemMgr.h"
#include "vmt.h"

void* GetInterface(const char* dllname, const char* interfacename) {
	CreateInterfaceFn CreateInterface = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(GetModuleHandle(dllname), "CreateInterface"));

	int returnCode = 0;
	void* interface = CreateInterface(interfacename, &returnCode);

	return interface;
}

IVPanel* panel;
CParticleSystemMgr* particleMgr;
CGameEntitySystem* entity;
std::vector<CEntityInstance*> Heroes;

VMT* entityVMT;
VMT* panelVMT;
VMT* particleMgrVMT;
VMT* particleCollectionVMT;

void GetModules() {
	// First Tier
	panel = reinterpret_cast<IVPanel*>(GetInterface("vgui2.dll", "VGUI_Panel010"));
	particleMgr = reinterpret_cast<CParticleSystemMgr*>(GetInterface("particles.dll", "ParticleSystemMgr003"));

	// Second Tier
	//1801D2E58 dq offset sub_180034A40 //#STR: "CParticleSystemMgr::CreateParticleCollection( Handle ) (vfunc 17)
	//sub_180034A40 + 0x178 to get to sub_18001F310
	//Add 11 to get to lea rax, ? ? _7CParticleCollection@@6B@; const CParticleCollection::`vftable'
	//uintptr_t* vmt_slot_createParticles = *(uintptr_t**)particles + 17; //17th function in ParticleMgr vtable
	//uintptr_t funcCall = *vmt_slot_createParticles + 178; //

	auto client = GetInterface("client.dll", "Source2Client002");
	uintptr_t* vmt_slot = *(uintptr_t**)client + 25; //25th function in Source2Client vtable
	uintptr_t addr_start = *vmt_slot + 3; //stores the relative address portion of the mov rax, [rip + 0x2512059] instruction
	entity = *(CGameEntitySystem**)(addr_start + *(uint32_t*)(addr_start)+4); //pointer to CGameEntitySystem is at 2512059 + addr_start + 4
}