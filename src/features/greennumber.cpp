#include "greennumber.h"
#include "hooks/loadbms.h"

using namespace GreenNumber;

uintptr_t draw_ptr;
float line_y;
float line_h;

int adjust_y;
int adjust_h;

int cover;
int basespeed;

double max_bpm;
double min_bpm;
double avg_bpm;

double current_bpm;

int hs_fix;
int hispeed;

inline double GreenNumberFormula(double hispeed) {
	return ((2173.f / 725.f) * 10000.f)* ((line_h + line_y + adjust_h + adjust_y) / (hispeed * basespeed))* (1 - (cover / 100.f));
}

/* this is mega retarded, but it works for now. refactor needed! */
void GreenNumber::UpdateVariables()
{
	draw_ptr = *(uintptr_t*)(Offsets::skin_struct + Offsets::draw_ptr_p1);
	line_y = *(float*)(draw_ptr + Offsets::y);
	line_h = *(float*)(draw_ptr + Offsets::h);

	adjust_y = *(int*)(Offsets::adjust_y1);
	adjust_h = *(int*)(Offsets::adjust_h);

	cover = *(int*)(Offsets::cover) * (line_y / (line_y + adjust_y));
	basespeed = *(int*)(Offsets::basespeed);

	max_bpm = *(double*)(Offsets::max_bpm);
	min_bpm = *(double*)(Offsets::min_bpm);
	avg_bpm = loadbms::sum / loadbms::count;

	current_bpm = *(double*)(Offsets::current_bpm);

	hs_fix = *(int*)(Offsets::hs_fix);

	hispeed = *(int*)(Offsets::hispeed);
}

double GreenNumber::GetGreenNumber()
{
	UpdateVariables();

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

	double green_number = GreenNumberFormula(hispeed);

	return green_number;
}

double GreenNumber::GetMinGreenNumber()
{
	UpdateVariables();

	auto hispeed = *(int*)(Offsets::hispeed);

	switch (hs_fix) {
	case 1:
		hispeed *= (min_bpm / max_bpm);
		break;
	case 2:
		hispeed *= (min_bpm / min_bpm);
		break;
	case 3:
		hispeed *= (min_bpm / avg_bpm);
		break;
	}

	double green_number = GreenNumberFormula(hispeed);

	return green_number;
}

double GreenNumber::GetMaxGreenNumber()
{
	UpdateVariables();

	auto hispeed = *(int*)(Offsets::hispeed);

	switch (hs_fix) {
	case 1:
		hispeed *= (max_bpm / max_bpm);
		break;
	case 2:
		hispeed *= (max_bpm / min_bpm);
		break;
	case 3:
		hispeed *= (max_bpm / avg_bpm);
		break;
	}

	double green_number = GreenNumberFormula(hispeed);

	return green_number;
}

double GreenNumber::GetWhiteNumber()
{
	auto cover = *(int*)(Offsets::cover);
	return cover * 10;
}

double GreenNumber::GetLiftNumberP1()
{
	uintptr_t draw_ptr = *(uintptr_t*)(Offsets::skin_struct + Offsets::draw_ptr_p1);
	auto line_y = *(float*)(draw_ptr + Offsets::y);
	auto adjust_y = *(int*)(Offsets::adjust_y1);

	auto lift = (-1 * adjust_y) / line_y;

	return lift * 1000;
}

double GreenNumber::GetLiftNumberP2()
{
	uintptr_t draw_ptr = *(uintptr_t*)(Offsets::skin_struct + Offsets::draw_ptr_p2);
	auto line_y = *(float*)(draw_ptr + Offsets::y);
	auto adjust_y = *(int*)(Offsets::adjust_y2);

	auto lift = (-1 * adjust_y) / line_y;

	return lift * 1000;
}