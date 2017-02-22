#include <iostream>
#include "TDate.h"
#include "TExhibit.h"

using namespace std;

int main(unsigned int argc, const char * argv[]) {
	cout << "TDate: " << endl;
	TDate dateDef;
	cout << "Default constructor: "<<dateDef.print() << endl;
	int day, month, year;
	cout << "Enter day: "; cin >> day;
	cout << "Enter month: "; cin >> month;
	cout << "Enter year: "; cin >> year;
	TDate dateInp(day,month,year);
	cout << "User constructor: " << dateInp.print() << endl;
	TDate dateCopy(dateDef);
	cout << "Copy constructor: " << dateCopy.print() << endl;

	cout << "TFund: " << endl;
	TFund fundDef;
	cout << "Default constructor: " << fundDef.print() << endl;
	char * title, *address;
	title = new char[256];
	address = new char[256];
	cout << "Enter title: "; cin >> title;
	cout << "Enter address: "; cin >> address;
	TFund fundInp(title,address);
	cout << "User constructor: " << fundInp.print() << endl;
	TFund fundCopy(fundDef);
	cout << "Copy constructor: " << fundCopy.print() << endl;
	delete(title); delete(address);


	cout << "TWorkOfArt: " << endl;
	TWorkOfArt workOfArtDef;
	cout << "Default constructor: " << workOfArtDef.print() << endl;
	title = new char[256];
	cout << "Enter title: "; cin >> title;
	double width, height, length;
	cout << "Enter year: "; cin >> year;
	cout << "Enter width: "; cin >> width;
	cout << "Enter height: "; cin >> height;
	cout << "Enter length: "; cin >> length;
	TWorkOfArt workOfArtInp(title,year,length,width,height);
	cout << "User constructor: " << workOfArtInp.print() << endl;
	TWorkOfArt workOfArtCopy(workOfArtDef);
	cout << "Copy constructor: " << workOfArtCopy.print() << endl;
	return 0;
}