/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#include "Line3D.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//Default Constructor
Line3D::Line3D(){

}

//Other Constructor
Line3D::Line3D(Point3D pt1, Point3D pt2){
	this->pt1 = pt1;
	this->pt2 = pt2;
	setLength();
}

//To de-construct
Line3D::~Line3D(){
}

//Accessor Method for PT1
Point3D Line3D::getPt1() const{
	return pt1;
}

//Mutator Method for PT1
void Line3D::setPt1(Point3D pt1){
	this->pt1 = pt1;
}

//Accessor Method for PT2
Point3D Line3D::getPt2() const{
	return pt2;
}

//Mutator Method for PT2
void Line3D::setPt2(Point3D pt2){
	this->pt2 = pt2;
}

//To calculate length
void Line3D::setLength(){
	double x_value = (pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX());
	double y_value = (pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY());
	double z_value = (pt1.getZ() - pt2.getZ()) * (pt1.getZ() - pt2.getZ());
	this->length = sqrt(x_value + y_value + z_value);
}

//Overloaded Operator
bool operator ==(const Line3D &pt_1, const Line3D &pt_2){
	if (pt_1.getPt1() == pt_2.getPt1() && pt_1.getPt2() == pt_2.getPt2())
		return true;
	else{
		return false;
	}
}

//Overloaded Operator
ostream & operator <<(ostream &out, const Line3D & line){
	out << "[" << setw(4) << line.getPt1().getX() << ", " << setw(4) << line.getPt1().getY() << ", " << setw(4) << line.getPt1().getZ() << "]   "
		<< "[" << setw(4) << line.getPt2().getX() << ", " << setw(4) << line.getPt2().getY() << ", " << setw(4) << line.getPt2().getZ() << "]   "
		<< fixed << setprecision(3) << line.length << endl;
	return out;
}