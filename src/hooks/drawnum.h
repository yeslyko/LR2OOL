#pragma once
#include <stdint.h>
#include <safetyhook.hpp>

namespace drawnum {
	namespace offsets {
		const inline uintptr_t draw_num = 0x49e060;
		const inline uintptr_t adjust_y = 0x111F88;
	}

	inline SafetyHookInline draw_hook;
	int hook_draw(void* drb, int src[17], int dst[11], void* T, int number, int x, int y);

	void Install();
}