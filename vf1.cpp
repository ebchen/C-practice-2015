//
// vf1.cpp
//
// - Objective: Introduction to virtual function: syntax & role in poylymorphism 
// - Practice: Follow commented instruction and complete the program as cited
//
// To build:
// Mac or Linux: "g++ vf1.cpp -std=c++11 -o vf1", Run: ./vf1
// Windows Visual Studio Developer Command Prompt: "cl.exe vf1.cpp", Run: vf1.exe
//
#include <iostream>
#include <string>


//
// Question: change the definition of class Base so that this program prints out
// "Success".
// Optionally: before your change, what is the "sizeof(baObj)"?
//
class Base
{
public:
	virtual void func() { }
};


//////////////////////////////////////////////////////////////////////////
// Do NOT change any line below and make the display print out "Success"!
//////////////////////////////////////////////////////////////////////////

void run_test()
{
	Base    baObj;

	if( sizeof(baObj) != sizeof(void*) )
		std::cerr << __FUNCTION__ << "Failed!" << std::endl;
	else
		std::cout << __FUNCTION__ << "Success" << std::endl;
}

int main()
{
	run_test();
	return 0;
}
