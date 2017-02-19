#include "TFund.h"

TFund::TFund()
{
	this->title = new char[FIELD_SIZE];
	this->title = "";
	this->address = new char[FIELD_SIZE];
	this->address = "";
}

TFund::TFund(const char * title, const char * address)
{
	this->title = new char[FIELD_SIZE];
	this->title = "";
	this->address = new char[FIELD_SIZE];
	this->address = "";
	if (strlen(title) < FIELD_SIZE) cout << "Too long title!" << endl;
	else strcpy(this->title, title);
	if (strlen(address) < FIELD_SIZE) cout << "Too long size!" << endl;
	else strcpy(this->address, address);
}

TFund::TFund(const TFund & fund)
{
	this->title = new char[FIELD_SIZE];
	this->title = "";
	this->address = new char[FIELD_SIZE];
	this->address = "";
	strcpy(this->title,fund.title);
	strcpy(this->address,fund.address);	
}

TFund & TFund::setTitle(const char * title)
{
	if (strlen(title) < FIELD_SIZE) strcpy(this->title,title);
	else cout << "Too long title!" << endl;
	return *this;
}

TFund & TFund::setAddress(const char * address)
{
	if (strlen(address) < FIELD_SIZE) strcpy(this->address, address);
	else cout << "Too long address!" << endl;
	return *this;
}

char * TFund::print()
{
	string result;
	result.append(this->title);
	result.append("\t");
	result.append(this->address);
	char * res = new char[result.size()+1];
	strcpy(res, result.data());
	return res;
}


TFund::~TFund()
{
	if (this->title != nullptr) 
	{ 
		delete(this->title); 
		this->title = NULL;
	}
	if (this->address != nullptr)
	{
		delete(this->address);
		this->address = NULL;
	}
}
