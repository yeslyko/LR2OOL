#pragma once
#include <stdint.h>

#define ciu const inline uintptr_t

namespace totaltime {
	ciu totaltimeptr = 0x0019F118;

	int GetHours();
	int GetMinutes();
	int GetSeconds();
}