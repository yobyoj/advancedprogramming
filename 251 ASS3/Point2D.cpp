/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#include "Point2D.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Default Constructor
Point2D::Point2D(){

}

//Other Constructor
Point2D::Point2D(int x, int y){
	this->x = x;
	this->y = y;
	setDistFrOrigin();
}

//To de-construct
Point2D::~Point2D(){
}

//Accessor Method
int Point2D::getX() const{
	return x;
}

//Mutator Method
void Point2D::setX(int x){
	this->x = x;
}

//Accessor Method
int Point2D::getY() const{
	return y;
}

//Mutator Method
void Point2D::setY(int y){
	this->y = y;
}

//To calculate distance from origin
void Point2D::setDistFrOrigin(){
	double x_value = (x - 0) * (x - 0);
	double y_value = (y - 0) * (y - 0);
	double distance = sqrt(x_value + y_value);
	this->distFrOrigin = distance;
}

double Point2D::getScalarValue() const{
	return distFrOrigin;
}

//Overloaded operator 
bool operator ==(const Point2D &pt_1, const Point2D &pt_2){
	if (pt_1.x == pt_2.x && pt_1.y == pt_2.y){
		return true;
	}
	else{
		return false;
	}
}

//Overloaded operator
ostream & operator <<(ostream &out, const Point2D & pt){
	out << "[" << setw(4) << pt.x << ", " << setw(4) << pt.y << "]   " << fixed << setprecision(3) << pt.distFrOrigin << endl;
	return out;
}