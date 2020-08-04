// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "interfaces.h"
#include "proxy.h"

DWORD WINAPI Thread(HMODULE hModule)
{
    //Create Console
    GetModules();
   
    entityVMT = new VMT(entity); //loads CGameEntitySystem VMT into vmt.entity
    entityVMT->HookVMT(OnAddEntity, 14);
    entityVMT->HookVMT(OnRemoveEntity, 15);
    entityVMT->ApplyVMT(entity);
    
    panelVMT = new VMT(panel); //loads IVPanel VMT into vmt.panel
    panelVMT->HookVMT(PaintTraverse, 55);
    panelVMT->ApplyVMT(panel);

    particleMgrVMT = new VMT(particleMgr);
    particleMgrVMT->HookVMT(CreateParticleCollection, 17);
    particleMgrVMT->ApplyVMT(particleMgr);

    return true; //added a return type
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved) {

    if (reason == DLL_PROCESS_ATTACH)
        CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, hModule, 0, 0));
    return TRUE;
}

