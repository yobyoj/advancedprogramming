/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/


#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeTwoD.h"
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std; 

class Circle : public ShapeTwoD{
	private:
		int centre_value_of_x;
		int centre_value_of_y;
		int radius;
		const double MATHS_PI = 3.141592;
		double area;

		string getPointsWithinShape();
		string getPointsOnPerimeter();
		
	public:
		Circle();
		Circle(string name, bool containsWarpSpace);
		~Circle();//deconstructor

		void setData2(int x, int y, int radius) override;
		
		double computeArea() override;
		double getArea() override;
		void setArea() override;

		bool isPointInShape(int x, int y) override;
		bool isPointOnShape(int x, int y) override;
		string toString() override;
};
#endif