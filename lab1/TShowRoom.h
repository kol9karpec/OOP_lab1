#pragma once

#define MAX_EXHIBITS 100

#include "TExhibit.h"

class TShowRoom
{
private:
	char * title;
	TExhibit ** exhibits;
	int count;
public:
	TShowRoom();
	TShowRoom(const char * title, TExhibit ** exhibits, int count);
	TShowRoom(TShowRoom&);

	char * getTitle() { return this->title; }
	TExhibit ** getExhibits() { return this->exhibits; }
	int getCount() { return this->count; }

	TShowRoom& setTitle(const char* title);
	TShowRoom& setExhibits(TExhibit ** exhibits);
	TShowRoom& setCount(int count);

	char * print();



	~TShowRoom();
};

