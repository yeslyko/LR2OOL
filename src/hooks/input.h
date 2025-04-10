#pragma once
#include <cstdint>
#include <safetyhook.hpp>

namespace input {
	struct {
		const uintptr_t get_mouse_input = 0x5392C0;
	} offsets;

	inline SafetyHookInline get_mouse_input_hook;
	uint8_t GetMouseInput();
	void Install();
};

