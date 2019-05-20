#pragma once
#ifndef EXTRA_FUNCTION_H
#define EXTRA_FUNCTION_H
#include <iostream> 

struct  date
{
	int day;
	int mounth;
	int year;
};

struct times
{
	int hour;
	int minute;
	int secund;
};

class time
{
	times start_time;
	times end_time;

	date start_date;
	date end_date;
public:
	time(times start_time, times end_time ,date start_date, date end_date);
	void set(times start_time, times end_time, date start_date, date end_date);
	void get(times &start_time, times &end_time, date &start_date, date &end_date);
};




#endif
