#pragma once

#include "CEntityInstance.h"

#define EntityHandle unsigned int

class CGameEntitySystem {
public:
	virtual void n_0();
	virtual void BuildResourceManifest(); // 01
	virtual void n_2();
	virtual void n_3();
	virtual void n_4();
	virtual void n_5();
	virtual void n_6();
	virtual void AddRefKeyValues(); // 7
	virtual void ReleaseKeyValues(); // 8
	virtual void n_9();
	virtual void n_10();
	virtual void ClearEntityDatabase(); // 11
	virtual CEntityInstance* FindEntityProcedural();
	virtual CEntityInstance* OnEntityParentChanged(); //13
	virtual CEntityInstance* OnAddEntity(CGameEntitySystem*, CEntityInstance*, EntityHandle); // 14
	virtual CEntityInstance* OnRemoveEntity(CGameEntitySystem*, CEntityInstance*, EntityHandle); // 15
	virtual void n_16();
	virtual void SortEntities(); // 17
	virtual void n_18();
	virtual void n_19();
	virtual void n_20();
	virtual void n_21();
};