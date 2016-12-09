////////////////////////////////////////////////////////////////////////////////
//
// Birds1.cpp
//
// Class Inheritance Project
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
#include <string>

class Bird
{
public:
	Bird(const std::string& val) : name(val) {}
	const std::string& getName() { return name; }
	virtual bool canFly() { return false; }

protected:
	std::string name;
};

class Sparrow: public Bird 
{
public:
	Sparrow() : Bird("Sparrow") {}
	bool canFly() { return true; }

};

class Chicken: public Bird
{
public:
	Chicken() : Bird("Chicken") {}
	bool canFly() { return false; }
};

class Duck: public Bird
{
public:
	Duck() : Bird("Duck") {}
	bool canFly() { return false; }
};

class Goose: public Bird
{
public:
	Goose() :Bird("Goose") {}
	bool canFly() { return true; }
};

class Penguin: public Bird
{
public:
	Penguin() : Bird("Penguin") {}
	bool canFly() { return false; }
};



void research(Bird& birdy, bool expected)
{
	bool result = birdy.canFly();
	if( result == expected )
		std::cout << "Passed: ";
	else
		std::cout << "Failed: ";
	if (birdy.canFly()) 
		std::cout << birdy.getName() << " can fly" << std::endl;
	
	else
		std::cout << birdy.getName() << " cannot fly" << std::endl;
}

int main()
{
	Sparrow sparrow;
	Chicken chicken;
	Duck    duckie;
	Goose   goose;
	Penguin penguin;

	research(sparrow, true);
	research(chicken, false);
	research(duckie,  false);
	research(goose,   true);
	research(penguin, false);
	getchar();
	return 0;
}

