#pragma once
#include "point.h"

class triangle
{
	protected:
		point pA, pB, pC;
		float aA, aB, aC, Area;

	public:
		triangle(point A, point B, point C) 
		{
			pA = A;
			pB = B;
			pC = C;
		}

		virtual float angleA() = 0;
		virtual float angleB() = 0;
		virtual float angleC() = 0;
		virtual float area() = 0;
};