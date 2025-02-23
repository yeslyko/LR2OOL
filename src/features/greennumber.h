#pragma once
#include <stdint.h>

#define ciu const inline uintptr_t

namespace GreenNumber {
	namespace Offsets {
		ciu skin_struct = 0x108358;
		ciu draw_ptr = 0x89CC;
		ciu y = 0x4;
		ciu h = 0xC;

		ciu hispeed = 0xFF838;
		ciu cover = 0xFF858;
		ciu basespeed = 0xFF8D0;

		ciu adjust_y = 0x111F88;
		ciu adjust_h = 0x111F80;

		ciu max_bpm = 0x19F520;
		ciu min_bpm = 0x19F528;

		ciu current_bpm = 0x197188;

		ciu hs_fix = 0xFF880;
	}

	double GetGreenNumber();
	double GetWhiteNumber();
	double GetLiftNumber();
}

#undef ciu