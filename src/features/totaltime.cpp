#include "totaltime.h"

int totaltime::GetHours()
{
	int totaltimenum = *(int*)(totaltime::totaltimeptr);

	int totalhours = (int)(totaltimenum / 3600);
	return totalhours;
}

int totaltime::GetMinutes()
{
	int totaltimenum = *(int*)(totaltime::totaltimeptr);

	int totalminutes = (int)(totaltimenum / 60 % 60);
	return totalminutes;
}

int totaltime::GetSeconds()
{
	int totaltimenum = *(int*)(totaltime::totaltimeptr);

	int totalseconds = (int)(totaltimenum % 60);
	return totalseconds;
}
