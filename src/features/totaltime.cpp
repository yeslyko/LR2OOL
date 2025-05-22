#include "totaltime.h"

int totaltimenum = *(int*)(totaltime::totaltimeptr);

int totaltime::GetHours()
{
	int totalhours = totaltimenum / 3600;
	return totalhours;
}

int totaltime::GetMinutes()
{
	int totalminutes = totaltimenum / 60 % 60;
	return totalminutes;
}

int totaltime::GetSeconds()
{
	int totalseconds = totaltimenum % 60;
	return totalseconds;
}
