// PascalsTriangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
int n;

long factorial(int n) {
	if (n == 0 || n == 1)
		return 1;
	else {
		long fact = 1;
		for (int i = 1; i <= n; ++i)
			fact = fact*i;
		return fact;
	}
}
int main()
{
	cout << "This app will calculate and display a Pascal Triangle" << endl;
	cout << "Please enter an integer" << endl;
	while (scanf_s("%d", &n) != 1) {
		cout << "please enter a valid integer\n" << endl;
		scanf_s("%d", &n);
		getchar();
	}

	for (int r = 0; r != n+1; ++r) 
	{
		for (int x = 0; x != r + 1; ++x)
		{
			cout << factorial(r) / (factorial(x)*factorial(r - x)) << " ";
		}
		cout << endl;
	
	}
	getchar();
	getchar();
    return 0;
}

