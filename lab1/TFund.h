#pragma once

#define FIELD_SIZE 100

#include <cstring>
#include <iostream>
#include <cstring>

using namespace std;

class TFund
{
private:
	char * title;
	char * address;
public:
	TFund();
	TFund(const char * title, const char * address);
	TFund(const TFund&);

	char * getTitle() { return this->title; }
	char * getAddress() { return this->address; }

	TFund& setTitle(const char * title);
	TFund& setAddress(const char * address);

	char * print();




	~TFund();
};

