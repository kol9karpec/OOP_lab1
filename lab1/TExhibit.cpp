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

TExhibit & TExhibit::setWorkOfArt(TWorkOfArt & workOfArt)
{
	this->workOfArt.setTitle(workOfArt.getTitle());
	this->workOfArt.setYear(workOfArt.getYear());
	this->workOfArt.setHeight(workOfArt.getHeight());
	this->workOfArt.setWidth(workOfArt.getWidth());
	this->workOfArt.setLength(workOfArt.getLength());
	return *this;
}

TExhibit & TExhibit::setFund(TFund & fund)
{
	this->fund.setTitle(fund.getTitle());
	this->fund.setAddress(fund.getAddress());
	return *this;
}

TExhibit & TExhibit::setLocation(TLocation location)
{
	this->location = location;
	return *this;
}

TExhibit & TExhibit::setPrice(int price)
{
	this->price = price;
	return *this;
}

char* TExhibit::print()
{
	char * buff = new char[256];
	string result;
	result.append(workOfArt.print());
	result.append("\t");
	result.append(fund.print());
	result.append("\t");
	result.append(locations[location]);
	result.append("\t");
	result.append(_itoa(price,buff,10));
	delete(buff);
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
