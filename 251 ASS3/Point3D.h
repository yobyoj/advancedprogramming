/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef POINT_3D
#define POINT_3D

#include "Point2D.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

class Point3D : public Point2D{
	friend bool operator ==(const Point3D &pt_1, const Point3D &pt_2);
	friend ostream & operator <<(ostream &out, const Point3D & pt);

	protected:
		int z;
		void setDistFrOrigin() override;

	public:
		Point3D();
		Point3D(int x, int y, int z);
		~Point3D();

		int getZ() const;
		void setZ(int z);
};
#endif