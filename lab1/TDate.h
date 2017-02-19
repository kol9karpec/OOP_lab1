#pragma once

#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;

class TDate
{
private:
	int day;
	int month;
	int year;
public:
	TDate();
	TDate(int day, int month, int year);
	TDate(const TDate&);

	int getDay() { return this->day; }
	int getMonth() { return this->month; }
	int getYear() { return this->year; }

	TDate& setDay(int day) { this->day = day; return *this; }
	TDate& setMonth(int month) { this->month = month; return *this; }
	TDate& setYear(int year) { this->year = year; return *this; }

	char* print();



	~TDate();
};

