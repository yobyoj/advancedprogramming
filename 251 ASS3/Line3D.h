/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef LINE_3D
#define LINE_3D

#include "Line2D.h" //Parent class
#include "Point3D.h" //To use Point3D class

using namespace std;

class Line3D : public Line2D{
	friend bool operator ==(const Line3D &pt_1, const Line3D &pt_2);
	friend ostream & operator <<(ostream &out, const Line3D &line);

	private:
		Point3D pt1; //Line 3D has a Point3D
		Point3D pt2; //Line 3D has a Point3D

	protected:
		void setLength() override;

	public:
		Line3D();
		Line3D(Point3D pt1, Point3D pt2);
		~Line3D();

		Point3D getPt1() const;
		void setPt1(Point3D pt1);
		Point3D getPt2() const;
		void setPt2(Point3D pt2);
};
#endif