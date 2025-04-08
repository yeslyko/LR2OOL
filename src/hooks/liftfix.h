#pragma once
#include <stdint.h>
#include <safetyhook.hpp>


namespace liftfix {
	namespace offsets {
		const inline uintptr_t draw_ln_1 = 0x407A83;
		const inline uintptr_t adjust_y1 = 0x111F88;
		const inline uintptr_t adjust_y2 = 0x111F90;
	}

	inline SafetyHookMid draw_ln_hook;

	void DrawLN(safetyhook::Context& ctx);
	void Install();
}