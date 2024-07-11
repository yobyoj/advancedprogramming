/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#include "Line2D.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//Default Constructor
Line2D::Line2D(){

}

//Other Constructor
Line2D::Line2D(Point2D pt1, Point2D pt2){
	this->pt1 = pt1;
	this->pt2 = pt2;
	setLength();
}

//To de-construct
Line2D::~Line2D(){
}

//Accessor Method for PT1
Point2D Line2D::getPt1() const{
	return pt1;
}

//Mutator Method for PT1
void Line2D::setPt1(Point2D pt1){
	this->pt1 = pt1;
}

//Accessor Method for PT2
Point2D Line2D::getPt2() const{
	return pt2;
}

//Mutator Method for PT2
void Line2D::setPt2(Point2D pt2){
	this->pt2 = pt2;
}

//To calculate length
void Line2D::setLength(){
	double x_value = (pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX());
	double y_value = (pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY());
	this->length = sqrt(x_value + y_value);
}

double Line2D::getScalarValue() const{
	return length;
}

//Overloaded Operator
bool operator ==(const Line2D &pt_1, const Line2D &pt_2){
	if (pt_1.getPt1() == pt_2.getPt1() && pt_1.getPt2() == pt_2.getPt2())
		return true;
	else{
		return false;
	}
}

//Overloaded Operator
ostream & operator <<(ostream &out, const Line2D & line){
	out << "[" << setw(4) << line.getPt1().getX() << ", " << setw(4) << line.getPt1().getY() << "]   "
        << "[" << setw(4) << line.getPt2().getX() << ", " << setw(4) << line.getPt2().getY() << "]   "
        << fixed << setprecision(3) << line.length << endl;
	return out;
}