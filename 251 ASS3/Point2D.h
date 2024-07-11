/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef POINT_2D
#define POINT_2D

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point2D{
	friend bool operator ==(const Point2D &pt_1, const Point2D &pt_2);
	friend ostream & operator <<(ostream &out, const Point2D & pt);
	
	protected:
		int x;
		int y;
		double distFrOrigin;
		virtual void setDistFrOrigin();	
	public:
		Point2D();
		Point2D(int x, int y);
		~Point2D();
		
		int getX() const;
		void setX(int x);
		int getY() const;
		void setY(int y);
		double getScalarValue() const;
};
#endif