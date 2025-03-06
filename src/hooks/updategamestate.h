#pragma once
#include <safetyhook.hpp>

namespace hooks::updategamestate {
	namespace offsets {
		const inline uintptr_t change_gamestate = 0x431BB9;
	};
	/* todo: fill this out with other values */
	enum class GAMESTATE {
		select = 0,
		decide = 1,
		playing = 2,
		result = 3
	};

	inline GAMESTATE gamestate = GAMESTATE::select;

	inline SafetyHookMid gamestate_hook;

	void Install();
}