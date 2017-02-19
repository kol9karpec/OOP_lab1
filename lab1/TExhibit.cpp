#include "TExhibit.h"

const char * locations[] = { "wall","table","ground" };

TExhibit::TExhibit(TExhibit& exhibit)
{
	this->workOfArt.setTitle(exhibit.workOfArt.getTitle());
	this->workOfArt.setYear(exhibit.workOfArt.getYear());
	this->workOfArt.setLength(exhibit.workOfArt.getLength());
	this->workOfArt.setWidth(exhibit.workOfArt.getWidth());
	this->workOfArt.setHeight(exhibit.workOfArt.getHeight());
	this->fund.setTitle(exhibit.fund.getTitle());
	this->fund.setAddress(exhibit.fund.getAddress());
	this->location = exhibit.location;
	this->price = exhibit.price;
}

TExhibit::TExhibit(TWorkOfArt & workOfArt, TFund & fund, TLocation location, int price)
{
	this->workOfArt.setTitle(workOfArt.getTitle());
	this->workOfArt.setYear(workOfArt.getYear());
	this->workOfArt.setLength(workOfArt.getLength());
	this->workOfArt.setWidth(workOfArt.getWidth());
	this->workOfArt.setHeight(workOfArt.getHeight());
	this->fund.setTitle(fund.getTitle());
	this->fund.setAddress(fund.getAddress());
	this->location = location;
	this->price = price;
}

char* TExhibit::print()
{
	char * buff = new char[256];
	string result;
	result.assign(workOfArt.print());
	result.assign("\t");
	result.assign(fund.print());
	result.assign("\t");
	result.assign(locations[location]);
	result.assign("\t");
	result.assign(_itoa(price,buff,10));
	delete buff;
	char * res = new char[result.size() + 1];
	strcpy(res, result.data());
	return res;
}

TExhibit::~TExhibit()
{
	workOfArt.~TWorkOfArt();
	fund.~TFund();
	location = wall;
	price = 0;
}
