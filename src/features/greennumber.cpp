#include "greennumber.h"
#include "hooks/loadbms.h"

double GreenNumber::GetGreenNumber()
{
	uintptr_t draw_ptr = *(uintptr_t*)(Offsets::skin_struct + Offsets::draw_ptr);
	auto line_y =  *(float*)(draw_ptr + Offsets::y);
	auto line_h = *(float*)(draw_ptr + Offsets::h);

	auto adjust_y = *(int*)(Offsets::adjust_y);
	auto adjust_h = *(int*)(Offsets::adjust_h);

	auto hispeed = *(int*)(Offsets::hispeed);
	auto cover = *(int*)(Offsets::cover) * (line_y / (line_y + adjust_y));
	auto basespeed = *(int*)(Offsets::basespeed);

	double max_bpm = *(double*)(Offsets::max_bpm);
	double min_bpm = *(double*)(Offsets::min_bpm);
	double avg_bpm = loadbms::sum / loadbms::count;

	double current_bpm = *(double*)(Offsets::current_bpm);

	auto hs_fix = *(int*)(Offsets::hs_fix);

	switch (hs_fix) {
	case 1:
		hispeed *= (current_bpm / max_bpm);
		break;
	case 2:
		hispeed *= (current_bpm / min_bpm);
		break;
	case 3:
		hispeed *= (current_bpm / avg_bpm);
		break;
	}

	double green_number = ((2173.f / 725.f) * 10000.f) * ((line_h + line_y + adjust_h + adjust_y) / (hispeed * basespeed)) * (1 - (cover / 100.f));

	return green_number;
}

double GreenNumber::GetWhiteNumber()
{
	auto cover = *(int*)(Offsets::cover);
	return cover * 10;
}

double GreenNumber::GetLiftNumber()
{
	uintptr_t draw_ptr = *(uintptr_t*)(Offsets::skin_struct + Offsets::draw_ptr);
	auto line_y = *(float*)(draw_ptr + Offsets::y);
	auto adjust_y = *(int*)(Offsets::adjust_y);

	auto lift = (-1 * adjust_y) / line_y;

	return lift * 1000;
}