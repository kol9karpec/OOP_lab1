#pragma once

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>

#ifndef FIELD_SIZE_1
#define FIELD_SIZE_1 100
#endif

using namespace std;

class TWorkOfArt
{
private:
	char * title;
	int year;
	double width;
	double height;
	double length;
public:
	TWorkOfArt();
	TWorkOfArt(const char * title, int year, double length,
		double width, double height);
	TWorkOfArt(const TWorkOfArt&);

	char * getTitle() { return this->title; }
	int getYear() { return this->year; }
	double getWidth() { return this->width; }
	double getLength() { return this->length; }
	double getHeight() { return this->height; }

	TWorkOfArt& setTitle(const char * title);
	TWorkOfArt& setYear(int year) { this->year = year; return *this; }
	TWorkOfArt& setLength(double length) { this->length = length; return *this; }
	TWorkOfArt& setWidth(double width) { this->width = width; return *this; }
	TWorkOfArt& setHeight(double height) { this->height = height; return *this; }

	char* print();

	~TWorkOfArt();
};

