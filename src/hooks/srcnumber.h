#pragma once
#include <safetyhook.hpp>
#include "utils/statistics.h"
#include "features/greennumber.h"


namespace hooks::srcnumber {
    namespace offsets {
        const inline uintptr_t src_number = 0x4024D0;
        const inline uintptr_t random = 0xDC35C;
        const inline uintptr_t game_offset = 0xFF838;
        const inline uintptr_t hp_offset = 0x979C8;
    }

    /* data pointers */
    inline int* note_positions = reinterpret_cast<int*>(offsets::random);

    inline statistics::OnlineMean mean = statistics::OnlineMean();
    inline statistics::OnlineStandardDeviation stddev = statistics::OnlineStandardDeviation();

    inline SafetyHookInline src_number_hook;
    int SrcNumber(uintptr_t* data_ptr, int id);

    int inline GetWhole(double num);
    inline int GetDecimal(double num, size_t number_of_places);

    void Install();
    void Reset();
}