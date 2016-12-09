// Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include "point.h"
#include "Triangle.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
class Tri : public triangle
{
public:
	float sA = 0;
	float sB = 0;
	float sC = 0;
	Tri(point A, point B, point C) :triangle(A, B, C) {}
	void angles() {//law of cosines
		aA = acos(((pow(sB, 2)) + (pow(sC, 2)) - (pow(sA, 2))) / (2 * sB * sC))*(180.0/PI);
		aB = acos(((pow(sA, 2)) + (pow(sC, 2)) - (pow(sB, 2))) / (2 * sA * sC))*(180.0 / PI);
		aC = 180 - (aA + aB);
	}
	float angleA() { return aA; }
	float angleB() { return aB; }
	float angleC() { return aC; }
	float area() { 
		float semi;
		//Heron's Formula
		semi = (sA + sB + sC) / 2;
		Area = sqrt(semi*(semi - sA)*(semi - sB)*(semi - sC));
		return Area;
	}
	void side() {//distance formula
		float xA = pA.getx();
		float yA = pA.gety();
		float xB = pB.getx();
		float yB = pB.gety();
		float xC = pC.getx();
		float yC = pC.gety();
		sA = sqrt(pow((xB - xC), 2) + pow((yB - yC), 2));
		sB = sqrt(pow((xA - xC), 2) + pow((yA - yC), 2));
		sC = sqrt(pow((xB - xA), 2) + pow((yB - yA), 2));
	}

};

int main()
{

	float x = 0, y = 0;
	point *ptr[3];
	for (int i = 0; i < 3; i++) {//ask for points
		std::cout << "Enter the x of point #"<<i+1<<'\n';
		scanf_s("%f", &x);
		std::cout << "Enter the y of the point"<<'\n';
		scanf_s("%f", &y);
		ptr[i] = new point(x,y);
	}
	//print out points
	std::cout << "The first point is " << "("<<ptr[0]->getx()<<", "<<ptr[0]->gety()<<")"<<'\n';
	std::cout << "The second point is " << "(" << ptr[1]->getx() << ", " << ptr[1]->gety() << ")" << '\n';
	std::cout << "The third point is " << "(" << ptr[2]->getx() << ", " << ptr[2]->gety() << ")" << '\n';
	Tri* Tria = new Tri(*ptr[0], *ptr[1], *ptr[2]);
	Tria->side();
	std::cout << "The area is " << Tria->area()<<'\n';
	Tria->angles();
	std::cout << "The angles of the triangle are " << Tria->angleA() << ", " << Tria->angleB() << ", and " << Tria->angleC() << '\n';
	getchar();
	getchar();
	return 0;
}
