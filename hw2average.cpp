//
// Linux or Mac OS X (g++)
// To build: g++ hw2average.cpp -std=c++11 -o hw2average
// To run: ./hw2average
//
// Microsoft Visual Studio
// - Create a solution and a Console project. Then add this file as an item of the project.
// - You can also try to run the following in a Visual Studio Developer Command Prompt:
// cl.exe hw2average.cpp
// A file called "hw2average.exe" will be generated.
//
// Questions can be found in the definition of the class Complex
//
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

class Complex
{
public:
	Complex(double val1 = 0.0, double val2 = 0.0)
	{
		re = val1;
		im = val2;
	}

	//
	// Overloading comparison operators
	//

	bool operator==(const Complex& rhs)
	{
		return isEqualDbl(re,rhs.re) && isEqualDbl(im,rhs.im);
	}

	bool operator!=(const Complex& rhs)
	{
		return !isEqualDbl(re,rhs.re) || !isEqualDbl(im,rhs.im);
	}

	////////////////////////////////////////////////////////////////////////////////
	//
	// To-Do: Complete your solution below...
	//

	// Overloading addition operator
	// Adding real and imaginery separately
	Complex operator+(const Complex& rhs)
	{
		return Complex(re + rhs.re, im + rhs.im);
	}

	// Overloading division operator
	// Divide real and imaginery both with the same integer denominator
	Complex operator/(int rhs)
	{
		return Complex(re / rhs, im / rhs);
	}

	//
	// To-Do: Complete your solution above...
	//
	////////////////////////////////////////////////////////////////////////////////

	double re; // real;
	double im; // imaginery;

	// Helper function member to compare double values:
	// it depends on the precision desired.
	bool isEqualDbl(double a, double b) const
	{
		static const double EPSILON = 0.000001;
		return a > b ? (a - b) <= EPSILON : (b - a) <= EPSILON;
	}
};

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Complex& ref)
{
	os << '(' << ref.re << ',' << ref.im << ')';
	return os;
}

// Helper function in template to check results
template<typename T>
inline void check(T a, T b)
{
	if( a == b )
		std::cout << "Success" << std::endl;
	else
		std::cout << "Failed: Result=" << a << ", Expected=" << b << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//
// We have not introduced 'template' but you can always study by yourself!
//
////////////////////////////////////////////////////////////////////////////////

template<typename T>
T calc_average(const std::vector<T>& nums)
{
	T total(0);
	for(int n = 0; n < nums.size(); ++n)
	{
		total = total + nums[n];
	}
	return total / nums.size();
}

int main()
{
	std::vector<int> numsInt { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto avgInt = calc_average(numsInt);
	check(avgInt, 5);

	std::vector<double> numsDbl { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
	auto avgDbl = calc_average(numsDbl);
	check(avgDbl, 5.5);

	////////////////////////////////////////////////////////////////////////////////
	//
	// How can I do the same average calculation like the above?
	//
	////////////////////////////////////////////////////////////////////////////////

	std::vector<Complex> nums2 = {
		Complex(1.0,-1.0), Complex(2.0,-2.0), Complex(3.0,-3.0),
		Complex(4.0,-4.0), Complex(5.0,-5.0), Complex(6.0,-6.0),
		Complex(7.0,-7.0), Complex(8.0,-8.0), Complex(9.0,-9.0),
		Complex(10.0,-10.0) };
	auto avg2 = calc_average(nums2);
	check( avg2, Complex(5.5,-5.5) );
	getchar();
	return 0;
}
