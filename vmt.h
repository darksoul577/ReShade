#pragma once
#include "pch.h"

class VMT
{
public:
	uintptr_t* vmt;
	uintptr_t* original_vmt = nullptr;
	std::map<uintptr_t, size_t> map;
	size_t method_count = 0;

	inline bool validate(uintptr_t memory) {
		if (!memory || memory > 0x7fffffffffff) return false;
		MEMORY_BASIC_INFORMATION info; VirtualQuery(LPCVOID(memory), &info, sizeof(MEMORY_BASIC_INFORMATION));
		return info.AllocationProtect & PAGE_EXECUTE_WRITECOPY;
	};

	VMT(void* instance)
	{
		uintptr_t** interface = reinterpret_cast<uintptr_t**>(instance);
		original_vmt = *interface;

		while (validate(original_vmt[method_count]))
			method_count++;

		vmt = new uintptr_t[method_count + 1]();
		memcpy(vmt, &original_vmt[-1], sizeof(uintptr_t) * method_count);
	}

	template <typename func>
	void HookVMT(func ref, size_t index)
	{
		vmt[index + 1] = reinterpret_cast<uintptr_t>(ref);
		map[(uintptr_t)ref] = index;
	}

	template<typename Fn>
	auto GetOriginalMethod(Fn& ref, size_t index)
	{
		return reinterpret_cast<decltype(&ref)>(original_vmt[index]);
	}

	template<typename Fn>
	auto GetOriginalMethod(Fn& ref)
	{
		return GetOriginalMethod(ref, map[(uintptr_t)ref]);
	}

	void RevertVMT(void* instance)
	{
		uintptr_t** interface = reinterpret_cast<uintptr_t**>(instance);
		uint32_t _old;
		VirtualProtect(*interface, sizeof(uintptr_t), PAGE_READWRITE, (PDWORD)&_old);
		*interface = original_vmt;
		//VirtualProtect(*interface, sizeof(uintptr_t), oProc, (PDWORD)&_oProc);
	}

	void ApplyVMT(void* instance)  //the pointer to the vtable is replaced with a pointer to our VMT
	{
		uintptr_t** interface = reinterpret_cast<uintptr_t**>(instance);
		uint32_t _old;
		VirtualProtect(*interface, sizeof(uintptr_t), PAGE_READWRITE, (PDWORD)&_old);
		//auto guard = protect_guard{ interface, sizeof(uintptr_t), PAGE_READWRITE };
		*interface = &vmt[1];
		//VirtualProtect(*interface, sizeof(uintptr_t), oProc, (PDWORD)&_oProc);
	}
};