#include "TWorkOfArt.h"



TWorkOfArt::TWorkOfArt() : year(0), width(0),
						height(0), length(0)
{
	this->title = new char[FIELD_SIZE_1];
	this->title = "";
}

TWorkOfArt::TWorkOfArt(const char * title, int year, double length,
	double width, double height) : year(year), width(width),
								height(height), length(length)
{
	this->title = new char[FIELD_SIZE_1];
	this->title = "";
	if (strlen(title) < FIELD_SIZE_1)	strcpy(this->title, title);
	else { cout << "Too long title!" << endl; }
}

TWorkOfArt::TWorkOfArt(const TWorkOfArt & workOfArt)
{
	strcpy(this->title, workOfArt.title);
	this->year = workOfArt.year;
	this->length = workOfArt.length;
	this->width = workOfArt.width;
	this->height = workOfArt.height;
}

TWorkOfArt& TWorkOfArt::setTitle(const char * title)
{
	if (strlen(title) < FIELD_SIZE_1)
		cout << "Too long title!" << endl;
	else strcpy(this->title, title);
	return *this;
}

char* TWorkOfArt::print()
{
	char * buff = new char[256];
	string result;
	result.append(this->title);
	result.append("\t");

	result.append(_itoa(this->year,buff,10));
	result.append("\t");

	ostringstream strs;
	strs << setprecision(2) << this->length;
	result.append(strs.str());
	result.append("\t");
	strs.clear();

	strs << setprecision(2) << this->width;
	result.append(strs.str());
	result.append("\t");
	strs.clear();

	strs << setprecision(2) << this->height;
	result.append(strs.str());
	result.append("\t");
	strs.clear();

	delete(buff);

	char * res = new char[result.size() + 1];
	strcpy(res, result.data());
	return res;
}


TWorkOfArt::~TWorkOfArt()
{
	if (this->title != NULL)
	{
		delete(this->title);
		this->title = NULL;
	}
	this->year = 0;
	this->width = 0;
	this->height = 0;
	this->length = 0;
}
