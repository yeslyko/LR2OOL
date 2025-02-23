#include "slider.h"
#include "features/greennumber.h"
#include <Windows.h>

int lift_number = 0;

__declspec(naked) int LiftSlider(void) {
	__asm {
		// need to preserve our registers before we call this function as it cobbles them
		push eax
		push ebx
		push ecx
		push edx
		push esi
	}

	lift_number = GreenNumber::GetLiftNumber();

	__asm {
		pop esi
		pop edx
		pop ecx
		pop ebx
		pop eax
	
		// calls SliderByTime() with our lfit
		mov ecx, [esp + 0x2C]
		push ebx
		lea edx, [esi + 0x1D58C]
		push edx
		mov edx, [ecx + 0x18A4]
		push offset lift_number
		push 1000
		push 0
		push edi
		add edx, ebp
		push edx
		push eax
		add ecx, 0x9AFC
		push ecx
		call slider::offsets::slider_by_time
		add esp, 0x24

		jmp slider::offsets::return_addr;
	}
}

void slider::Install()
{
	DWORD old_protect;

	VirtualProtect(reinterpret_cast<LPVOID>(offsets::switch_statement), 4, PAGE_EXECUTE_READWRITE, (PDWORD)&old_protect);
	*(uintptr_t*)offsets::switch_statement = (uintptr_t)LiftSlider;
	VirtualProtect(reinterpret_cast<LPVOID>(offsets::switch_statement), 4, PAGE_EXECUTE_READ, (PDWORD)&old_protect);

	VirtualProtect(reinterpret_cast<LPVOID>(offsets::cmp), 1, PAGE_EXECUTE_READWRITE, (PDWORD)&old_protect);
	*(int8_t*)offsets::cmp = 0x1A;
	VirtualProtect(reinterpret_cast<LPVOID>(offsets::cmp), 1, PAGE_EXECUTE_READ, (PDWORD)&old_protect);
}

void slider::Uninstall()
{
	/* since we are manually installing (not using safety hook) we can't rely on destructors to uninstall this */
	DWORD old_protect;

	VirtualProtect(reinterpret_cast<LPVOID>(offsets::cmp), 1, PAGE_EXECUTE_READWRITE, (PDWORD)&old_protect);
	*(int8_t*)offsets::cmp = 0x19;
	VirtualProtect(reinterpret_cast<LPVOID>(offsets::cmp), 1, PAGE_EXECUTE_READ, (PDWORD)&old_protect);
}