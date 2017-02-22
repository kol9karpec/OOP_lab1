#include "TShowRoom.h"



TShowRoom::TShowRoom()
{
	this->title = new char[FIELD_SIZE];
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

TShowRoom & TShowRoom::setExhibits(TExhibit ** exhibits)
{
	for (int i = 0; i < this->count; i++)
	{
		//this->exhibits[i].
	}
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

TShowRoom::~TShowRoom()
{
	if (this->title != NULL) { delete(this->title); this->title = NULL; }
	for (int i = 0; i < this->count; i++)
		delete(this->exhibits[i]);
	delete(exhibits);
}
