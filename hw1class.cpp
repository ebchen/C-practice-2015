//
// Linux or Mac OS X (g++)
// To build: g++ hw1class.cpp -std=c++11 -o hw1class
// To run: ./hw1class
//
// Microsoft Visual Studio
// - Create a solution and a Console project. Then add this file as an item of the project.
// - You can also try to run the following in a Visual Studio Developer Command Prompt:
// cl.exe hw1class.cpp
// A file called "hw1class.exe" will be generated.
//
// Questions can be found in the definition of the class Complex
//
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

//
// Encapsulation is in the object-oriented world to express the idea
// that combines the data and its behavior into one functional program
// unit: class, in C++.
//
// An object is an instance of a class. A class can have many objects of its
// kind and each is an independent instance.
//
// As stated in the idea of encapsulation, a class has two key components:
// - data members;
// - function members.
// in C++. A data member sometimes is referred as "property", while a
// function member is referred as "method".
// 

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

	bool operator !=(const Complex& rhs)
	{
		return !isEqualDbl(re,rhs.re) || !isEqualDbl(im,rhs.im);
	}

	// Overloading addition operator
	// Adding real and imaginery separately
	Complex operator+(const Complex& rhs)
	{
		return Complex(re + rhs.re, im + rhs.im); // Notice the implementation is different from the sample in the class!
	}

	// Overloading subtraction opeator
	// Subtracting real and imaginery separately
	Complex operator-(const Complex& rhs)
	{
		return Complex(re - rhs.re, im - rhs.im);
	}

	// Overloading multiplication opeator
	// Multiplying real and imaginery separately
	Complex operator*(const Complex& rhs)
	{
	
		return Complex(re * rhs.re, im * rhs.im);
	}

	// Overloading division opeator
	// Dividing real and imaginery separately
	Complex operator/(const Complex& rhs)
	{
		return Complex(re / rhs.re, im / rhs.im);
	}

	//
	// Implement definition of overloading the operator- (minus)
	// so the program will work as expected
	//

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

int main()
{
	Complex cm1 { 1.0, 2.0 };
	Complex cm2 { 3.0, 4.0 };

	Complex cm3 = cm1 + cm2;
	check(cm3, Complex { 4.0, 6.0 });

	Complex cm4 = cm1 - cm2;
	check(cm4, Complex { -2.0, -2.0 });

	Complex cm5 = cm1 * cm2;
	check(cm5, Complex { 3.0, 8.0 });

	Complex cm6 = cm1 / cm2;
	check(cm6, Complex { 0.333333, 0.5 });
	getchar();
	return 0;
}
