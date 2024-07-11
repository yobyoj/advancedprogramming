/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef LINE_2D
#define LINE_2D

#include "Point2D.h" 

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Line2D{
	friend bool operator ==(const Line2D &pt_1, const Line2D &pt_2);
	friend ostream & operator <<(ostream &out, const Line2D &line);
	
	private:
		Point2D pt1; //Line 2D has a Point2D
		Point2D pt2; //Line 2D has a Point2D

	protected:
		double length;
		virtual void setLength();
		
	public:
		Line2D();
		Line2D(Point2D pt1, Point2D pt2);
		~Line2D();

		Point2D getPt1() const;
		void setPt1(Point2D pt1);
		Point2D getPt2() const;
		void setPt2(Point2D pt2);
		double getScalarValue() const;
};
#endif