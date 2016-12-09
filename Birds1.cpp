////////////////////////////////////////////////////////////////////////////////
//
// Birds1.cpp
//
// Requirements are written as comments in this program. Follow the instructions
// and complete the program.
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
	// To-do: define function "canFly()" here
	// - "canFly()" is a virtual function
	// - "canFly()" should return "bool" type
	// - "canFly()" has no arguments
	// - Optionally but not required, give "canFly()"
	// a simple default implementation to return something...
	//

protected:
	std::string name;
};
//
// Requirements:
// - Complete the definition of the base class "Bird"
// - Complete the definitions of the derived classes:
//   "Sparrow", "Chicken", "Duck", "Goose", "Penguin"
// - More details can be found from the comments below
//



class Sparrow: public Bird // Hint: Need to finish class inheritance
{
public:
	// Hint: each derived class need a constructor like the following to
	// identify the name of such bird...
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


////////////////////////////////////////////////////////////////////////////////
//
// Please do NOT change the code below!
// When running the program, screen display will tell you if you have passed...
//
////////////////////////////////////////////////////////////////////////////////

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

