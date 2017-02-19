#include <iostream>
#include "TDate.h"

using namespace std;

int main(unsigned int argc, const char * argv[]) {
	TDate date;
	cout << date.print() << endl;




	date.~TDate();

	return 0;
}