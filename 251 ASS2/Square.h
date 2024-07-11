/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeTwoD.h"
#include <sstream>
#include <iomanip>

using namespace std;

class Square : public ShapeTwoD{
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
		Square();
        Square(string name, bool containsWarpSpace);
        ~Square(); //Deconstructor

		void setData(int *x, int *y) override;
		double computeArea() override;
		double getArea() override;
		void setArea() override;

		bool isPointInShape(int x, int y) override;
		bool isPointOnShape(int x, int y) override;
		string toString() override;
};
#endif