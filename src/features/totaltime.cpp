#include "totaltime.h"

int totaltimenum = *(int*)(totaltime::totaltimeptr);

int totaltime::GetHours()
{
	int totalhours = (int)(totaltimenum / 3600);
	return totalhours;
}

int totaltime::GetMinutes()
{
	int totalminutes = (int)(totaltimenum / 60 % 60);
	return totalminutes;
}

int totaltime::GetSeconds()
{
	int totalseconds = (int)(totaltimenum % 60);
	return totalseconds;
}
