#pragma once
#include <stdint.h>
#include <safetyhook.hpp>


namespace liftfix {
	namespace offsets {
		const inline uintptr_t draw_ln_1 = 0x407A83;
		const inline uintptr_t adjust_y = 0x111F88;
	}

	inline SafetyHookMid draw_ln_hook;

	void hook_draw_ln(safetyhook::Context& ctx);
	void Install();
}