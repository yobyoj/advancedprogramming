/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#include "Point3D.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//Default Constructor
Point3D::Point3D(){

}

//Other Constructor
Point3D::Point3D(int x, int y, int z) : Point2D(x, y){
	this->z = z;
	setDistFrOrigin();
}

//To de-construct
Point3D::~Point3D(){
}

//Accessor Method
int Point3D::getZ() const{
	return z;
}

//Mutator Method
void Point3D::setZ(int z){
	this->z = z;
}

//To calculate distance from origin
void Point3D::setDistFrOrigin(){
	double x_value = (x - 0) * (x - 0);
	double y_value = (y - 0) * (y - 0);
	double z_value = (z - 0) * (z - 0);
	this->distFrOrigin = sqrt(x_value + y_value + z_value);
}

//Overloaded operator
bool operator ==(const Point3D &pt_1, const Point3D &pt_2){
	if (pt_1.getX() == pt_2.getX() && pt_1.getY() == pt_2.getY() && pt_1.getZ() == pt_2.getZ())
		return true;
	else{
		return false;
	}
}

//Overloaded operator
ostream & operator <<(ostream &out, const Point3D & pt){
	out << "[" << setw(4) << pt.x << ", " << setw(4) << pt.y << ", " << setw(4) << pt.z << "]   " << fixed << setprecision(3) << pt.distFrOrigin << endl;
	return out;
}

