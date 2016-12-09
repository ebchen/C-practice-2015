//
//Overloading Operators Project
//
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

//
// 
// 

class Complex
{
public:
	Complex(double val1 = 0.0, double val2 = 0.0)
	{
		re = val1;
		im = val2;
	}

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

	bool isEqualDbl(double a, double b) const
	{
		static const double EPSILON = 0.000001;
		return a > b ? (a - b) <= EPSILON : (b - a) <= EPSILON;
	}
};

std::ostream& operator<<(std::ostream& os, const Complex& ref)
{
	os << '(' << ref.re << ',' << ref.im << ')';
	return os;
}

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
