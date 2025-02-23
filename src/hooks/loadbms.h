#pragma once
#include <stdint.h>
#include <safetyhook.hpp>

namespace loadbms {
	namespace offsets {
		const uintptr_t reset = 0x4B0690;
		const uintptr_t sum = 0x4B32AD; /* no need for count when it is *always* called with sum */
	}

	/* TODO: implement median scroll */

	inline int count;
	inline double sum;

	inline SafetyHookMid reset_hook;
	inline SafetyHookMid sum_hook;

	void Install();
}