#include <math.h>
#include "srcnumber.h"

int hooks::srcnumber::SrcNumber(uintptr_t* data_ptr, int id)
{
    int pgreat_count_in_game = src_number_hook.call<int>(data_ptr, 110);
    int great_count_in_game  = src_number_hook.call<int>(data_ptr, 111);
    int good_count_in_game   = src_number_hook.call<int>(data_ptr, 112);
    int bad_count_in_game    = src_number_hook.call<int>(data_ptr, 113);
    int poor_count_in_game   = src_number_hook.call<int>(data_ptr, 114);

    int sum = pgreat_count_in_game + great_count_in_game + good_count_in_game + bad_count_in_game + poor_count_in_game;
    if (!sum) sum = 1; // to prevent dbz

    double pgreat_ratio = (double) pgreat_count_in_game / great_count_in_game;
    double great_ratio  = (double) great_count_in_game / good_count_in_game;

    double pgreat_percent = (double) pgreat_count_in_game / sum * 100.0;
    double great_percent  = (double) great_count_in_game / sum * 100.0;
    double good_percent   = (double) good_count_in_game / sum * 100.0;
    double bad_percent    = (double) bad_count_in_game / sum * 100.0;
    double poor_percent   = (double) poor_count_in_game / sum * 100.0;


    switch (id) {
    case 295: // current random
    {
        uint32_t current_random = 0;

        int* note_positions = reinterpret_cast<int*>(offsets::random);
        for (int i = 0; i < 7; i++) {
            current_random += (i + 1) * pow(10, 7 - note_positions[i]);
        }

        return current_random;
        break;
    }
    case 296: // whole part of mean
        return GetWhole(mean.GetMean());
        break;
    case 297: // decimal part of mean
        return GetDecimal(mean.GetMean());
        break;
    case 298: // whole part of stddev
        return GetWhole(stddev.GetPopulationStandardDeviation());
        break;
    case 299: // decimal part of stddev
        return GetDecimal(stddev.GetPopulationStandardDeviation());
        break;
    case 302: // green number
        return GetWhole(GreenNumber::GetGreenNumber());
        break;
    case 303: // white number
        return GetWhole(GreenNumber::GetWhiteNumber());
        break;
    case 304: // min green number
    case 305: // max green number
        break;
    case 400: // whole part of pgreat ratio
        return GetWhole(pgreat_ratio);
        break;
    case 401: // decimal part of pgreat ratio
        return GetDecimal(pgreat_ratio);
        break;
    case 402: // whole part of great ratio
        return GetWhole(great_ratio);
        break;
    case 403: // decimal part of great ratio
        return GetDecimal(great_ratio);
        break;
    case 404: // whole percentage of pgreats
        return GetWhole(pgreat_percent);
        break;
    case 405: // decimal percentage of pgreats
        return GetDecimal(pgreat_percent);
        break;
    case 406: // whole percentage of greats
        return GetWhole(great_percent);
        break;
    case 407: // decimal percentage of greats
        return GetDecimal(great_percent);
        break;
    case 408: // whole percentage of goods
        return GetWhole(good_percent);
        break;
    case 409: // decimal percentage of goods
        return GetDecimal(good_percent);
        break;
    case 410: // whole percentage of bads
        return GetWhole(bad_percent);
        break;
    case 411: // decimal percentage of bads
        return GetDecimal(bad_percent);
        break;
    case 412: // whole percentage of poors
        return GetWhole(poor_percent);
        break;
    case 413: // decimal percentage of poors
        return GetDecimal(poor_percent);
        break;
    case 414: // decimal part of green number
        return GetDecimal(GreenNumber::GetGreenNumber());
        break;
    case 415: // decimal part of white number
        return GetDecimal(GreenNumber::GetWhiteNumber());
        break;
    case 416: // whole part of lift number
        return GetWhole(GreenNumber::GetLiftNumber());
        break;
    case 417: // decimal part of lift number
        return GetDecimal(GreenNumber::GetLiftNumber());
        break;
    default:
        return src_number_hook.call<int>(data_ptr, id);
        break;
    }
    return 0;
}

inline int hooks::srcnumber::GetWhole(double num)
{
    return static_cast<int>(num);
}

inline int hooks::srcnumber::GetDecimal(double num)
{
    return abs(static_cast<int>(100 * (num - static_cast<int>(num))));
}

void hooks::srcnumber::Install()
{
    src_number_hook = safetyhook::create_inline(reinterpret_cast<void*>(offsets::src_number), reinterpret_cast<void*>(SrcNumber));
}

void hooks::srcnumber::Reset()
{
    mean = statistics::OnlineMean();
    stddev = statistics::OnlineStandardDeviation();
}
