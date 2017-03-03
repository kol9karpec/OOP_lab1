#include "TShowRoom.h"



TShowRoom::TShowRoom()
{
	this->title = new char[FIELD_SIZE];
	strcpy(this->title,"");
	this->exhibits = new TExhibit*[MAX_EXHIBITS];
	this->count = 0;
}

TShowRoom::TShowRoom(const char * title, TExhibit ** exhibits, 
					int count)
{
	this->title = new char[FIELD_SIZE];
	this->exhibits = new TExhibit*[MAX_EXHIBITS];
	strcpy(this->title, title);
	for (int i = 0; i < count; i++)
		this->exhibits[i] = new TExhibit(*(exhibits[i]));
	this->count = count;
}

TShowRoom::TShowRoom(TShowRoom & showRoom)
{
	this->title = new char[FIELD_SIZE];
	this->exhibits = new TExhibit*[MAX_EXHIBITS];
	for (int i = 0; i < showRoom.count; i++)
		this->exhibits[i] = new TExhibit(*(showRoom.exhibits[i]));
	this->count = showRoom.count;
}


TShowRoom & TShowRoom::setTitle(const char * title)
{
	strcpy(this->title, title);
	return *this;
}

TShowRoom & TShowRoom::setExhibits(TExhibit ** exhibits, int count)
{
	this->count = count;
	for (int i = 0; i < this->count; i++)
	{
		this->exhibits[i]->setWorkOfArt(exhibits[i]->getWorkOfArt());
		this->exhibits[i]->setFund(exhibits[i]->getFund());
		this->exhibits[i]->setLocation(exhibits[i]->getLocation());
		this->exhibits[i]->setPrice(exhibits[i]->getPrice());
	}
	return *this;
}

TShowRoom & TShowRoom::addExhibit(TExhibit & exhibit)
{
	this->exhibits[this->count] = new TExhibit(exhibit);
	this->count++;
	return *this;
}

char * TShowRoom::print()
{
	string result;
	result.append(this->title);
	result.append("\n");
	for (int i = 0; i < this->count; i++)
	{
		result.append(exhibits[i]->print());
		result.append("\n");
	}

	char * res = new char[result.size() + 1];
	strcpy(res, result.data());
	return res;
}

char * TShowRoom::shortPrint()
{
	string result;
	result.append(this->title);
	int minYear=2018,maxYear=0;
	for (int i = 0; i < count; i++)
	{
		int curYear = (exhibits[i]->getWorkOfArt).getYear();
		if (curYear < minYear) minYear = curYear;
		if (curYear > maxYear) maxYear = curYear;
	}
	char * buff = new char[256];
	result.append("\t");
	result.append(_itoa(minYear,buff,10));
	result.append(" - ");
	result.append(_itoa(minYear, buff, 10));

	char * charRes = new char[result.size() + 1];
	strcpy(charRes, result.data());
	delete[] buff;
	buff = NULL;
	return charRes;
}

TShowRoom::~TShowRoom()
{
	if (this->title != NULL) { delete(this->title); this->title = NULL; }
	for (int i = 0; i < this->count; i++)
		delete(this->exhibits[i]);
	delete(exhibits);
}
