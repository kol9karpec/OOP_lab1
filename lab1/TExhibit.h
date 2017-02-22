#pragma once

#include "TWorkOfArt.h"
#include "TFund.h"

enum TLocation {wall=0,table,ground};

class TExhibit
{
private:
	TWorkOfArt workOfArt;
	TFund fund;
	TLocation location;
	int price;
public:
	TExhibit(): location(wall) {};
	TExhibit(TWorkOfArt& workOfArt, TFund& fund,
		TLocation location, int price);
	TExhibit(TExhibit&);
	
	TWorkOfArt getWorkOfArt() { return this->workOfArt; }
	TFund getFund() { return this->fund; }
	TLocation getLocation() { return this->location; }
	int getPrice() { return this->price; }

	TExhibit& setWorkOfArt() {}

	char* print();




	~TExhibit();
};

