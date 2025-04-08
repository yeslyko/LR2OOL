#pragma once
#include <stdint.h>
#include <safetyhook.hpp>

namespace dstflag {
	namespace offsets {
		const inline uintptr_t get_dst_flag = 0x40E790;
	}

	inline SafetyHookInline get_dst_flag_hook;

	bool GetDstFlag(void* game, unsigned dst);
	void Install();
}