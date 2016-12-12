#pragma once

class point
{
	private:
		float x, y;

	public:
		point() { x = 0.0; y = 0.0; }
		point(float xIn, float yIn)
		{
			x = xIn;
			y = yIn;
		}

		void set(float xIn, float yIn)
		{
			x = xIn;
			y = yIn;
		}

		float getx() { return x; }
		float gety() { return y; }
		void getXY(float* xOut, float* yOut)
		{
 			*xOut = x;
			*yOut = y;
		}

		point& operator =(const point& rhs)
		{
			x = rhs.x;
			y = rhs.y;
			return *this;
		}

		~point() {}
};