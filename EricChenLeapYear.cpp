
//Determines if a year is a leap year.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
int main()
{
	int year;
	char conti;
	bool cont = true;
	while (cont) {
		printf("Please enter an integer year. (all years in AD, if BCE put a negative sign and then the numerical year)\n");


		while (scanf_s("%d", &year) != 1) {
			cout << "please enter a valid year\n" << endl;
			scanf_s("%d", &year);
			getchar();
		}
		try {
			if (year % 4 == 0 && year % 100 != 0) {
				printf("This year is a leap year");
				getchar();
				getchar();
			}
			else if (year % 4 == 0 && year % 400 == 0) {
				printf("This year is a leap year");
				getchar();
				getchar();
			}
			else {
				printf("This year is not a leap year");
				getchar();
				getchar();
			}

		}

		catch (std::runtime_error) {
			cout << "Please enter a valid year" << endl;
		}
		cout << "\n Do you want to continue? Y or N\n" << endl;
		cin >> conti;
		if (conti == 'n' || conti == 'N') {
			cont = false;
		}
	}
	return 0;
	
}
