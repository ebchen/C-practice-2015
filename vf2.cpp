//
// vf2.cpp
//
// - Objective: Understand "static binding" and "dynamic binding"
//
#include <iostream>
#include <string>

//
// Tasks: modify the code so that when running the program, with the following constraints:
// - do not change class names and their inheritance relation
// - make as least change as possible
// - when running the program, it must display the following on the screen:
// 1
// 2
// 3
// -1
// -1
// -1
//

class Base
{
public:
	Base() : _id(0) {}

	int id() { return _id; }
	virtual void inc() { ++_id; }
	virtual void dec() { _id -= 2; }

protected:
	int _id;
};

class Derived : public Base
{
public:
	void inc() { _id += 2; }
	void dec() { _id -= 3; }
};

class Sibling : public Base
{
public:
	void inc() { _id += 3; }
	void dec() { _id -= 4; }
};

//////////////////////////////////////////////////////////////////////////
// Do NOT change any line below and make the display as requested
//////////////////////////////////////////////////////////////////////////

void run_test1(Base& obj)
{
	obj.inc();
	std::cout << obj.id() << std::endl;
}

void run_test2(Base* obj)
{
	obj->dec();
	std::cout << obj->id() << std::endl;
}

int main()
{
	Base base;
	Derived derived;
	Sibling sibling;

	run_test1(base);
	run_test1(derived);
	run_test1(sibling);

	run_test2(&base);
	run_test2(&derived);
	run_test2(&sibling);

	getchar();
	return 0;
}

