#pragma once
#include <stdint.h>

namespace slider {
	namespace offsets {
		const uintptr_t inline switch_statement = 0x413F64;
		const uintptr_t inline cmp = 0x4135AD;
		const uintptr_t return_addr = 0x413EC8;
		const uintptr_t slider_by_time = 0x49c0e0;
	}

	void Install();
	void Uninstall();
}