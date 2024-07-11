/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#ifndef CROSS_H
#define CROSS_H

#include "ShapeTwoD.h"
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Cross : public ShapeTwoD{
	private:
		int x[12]; 
		int y[12];

		int mininum_value_of_x, maximum_value_of_x;
		int mininum_value_of_y, maximum_value_of_y;

		//Stores coordinates of the cross
		int bottom_left_x, bottom_right_x;
		int left_bottom_y, left_top_y;
		int top_left_x, top_right_x;
		int right_top_y, right_bottom_y;
		int top_bottom_y, bottom_top_y;
		int left_right_x,right_left_x;
		
		double area;

		string getPointsOnPerimeter();
        string getPointsWithinShape();

	public:
		Cross(); //Deconstructors
        Cross(string name, bool containsWarpSpace);
        ~Cross(); 

		void setData(int *x, int *y) override;

		double computeArea() override;
		double getArea() override;
		void setArea() override;

		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		string toString() override;
};
#endif