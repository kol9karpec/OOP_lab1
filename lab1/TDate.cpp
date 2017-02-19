#include "TDate.h"

TDate::TDate()
{
	time_t curTime = time(0);
	tm *ltm = localtime(&curTime);
	this->day = ltm->tm_mday;
	this->month = 1 + ltm->tm_mon;
	this->year = 1900 + ltm->tm_year;
}

TDate::TDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

TDate::TDate(const TDate & date)
{
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

char* TDate::print()
{
	char * buff = new char[255];
	string result = "";
	result.append((day > 10) ? "":"0");
	result.append(_itoa(this->day,buff,10));
	result.append(".");
	result.append((month > 10) ? "" : "0");
	result.append(_itoa(this->month, buff, 10));
	result.append(".");
	int modYear = this->year % 100;
	result.append((modYear > 10) ? "" : "0");
	result.append(_itoa(modYear, buff, 10));	
	delete(buff);
	char * res = new char[result.size() + 1];
	strcpy(res, result.data());
	return res;
}

TDate::~TDate()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}
