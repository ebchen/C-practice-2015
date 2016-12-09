//
// vf3.cpp
//
// - Objective: Understand "static binding" and "dynamic binding"
//
#include <iostream>
#include <string>

//
// Task#1: Modify class Derived so that class Derived is inherited from class Base;
// Task#2: Modify class Sibling so that class Sibling is inherited from class Base;
// Task#3: Modify all classes and function run_test signature so that the code compiles and
// prints out in the following sequence:
//
// Base
// Derived
// Sibling
//

class Base
{
public:
	virtual std::string name() const { return "Base"; }
};

class Derived : public Base
{
public:
	std::string name() const { return "Derived"; }
};

class Sibling : public Base
{
public:
	std::string name() const { return "Sibling"; }
};

void run_test(Base& obj)
//////////////////////////////////////////////////////////////////////////
// Do NOT change any line below and make the display as requested
//////////////////////////////////////////////////////////////////////////
{
	std::cout << obj.name() << std::endl;
}

int main()
{
	Base base;
	Derived derived;
	Sibling sibling;

	run_test(base);
	run_test(derived);
	run_test(sibling);
	getchar();
	return 0;
}

