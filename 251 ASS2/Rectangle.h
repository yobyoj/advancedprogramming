/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeTwoD.h"
#include <sstream>
#include <iomanip>

using namespace std;

class Rectangle : public ShapeTwoD{
	private:
		int mininum_value_of_x, maximum_value_of_x;
		int mininum_value_of_y, maximum_value_y;
		int distance_of_x, distance_of_y;
		int x[4];
		int y[4];
		double area;

		string getPointsOnPerimeter();
        string getPointsWithinShape();

	public:
		Rectangle();
        Rectangle(string name, bool containsWarpSpace);
        ~Rectangle(); //Deconstructor

		void setData(int *x, int *y) override;
		
		double computeArea() override;
		double getArea() override;
		void setArea() override;

		bool isPointInShape(int x, int y) override;
		bool isPointOnShape(int x, int y) override;
		string toString() override;
};
#endif