/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#include "Circle.h"
#include <sstream>
#include <iomanip>

//Default constructor
Circle::Circle(){
    
}

//Other constructor
Circle::Circle(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){

}

//Deconstructor for instances
Circle::~Circle(){

}

//Sets centre point & radius
void Circle::setData2(int x, int y, int radius){
    this->centre_value_of_x = x;
    this->centre_value_of_y = y;
    this->radius = radius;
}

//To compute circle area
double Circle::computeArea(){
	area = MATHS_PI * radius * radius;
	return area;
}

//Accessor method for area
double Circle::getArea(){
	return area;
}

//Mutator method for area
void Circle::setArea(){
    this->area = computeArea();
}

//To make sure the the points are in shape
bool Circle::isPointInShape(int x, int y){
    if ((pow(x, 2) + pow(y, 2)) < pow(radius, 2) && (pow(x, 2) + pow(y, 2)) != 0) { //Formula Checking
        if (x != centre_value_of_x && y != centre_value_of_y) {
            return true;
        }
    }
    return false;
} 

bool Circle::isPointOnShape(int x, int y){ //To calculate the distance of x and y from center respectively
	int distance_of_x = centre_value_of_x-x; 
    int distance_of_y = centre_value_of_y-y; 
    
	if (((distance_of_x * distance_of_x) + (distance_of_y * distance_of_y)) == (radius * radius)){ // Formula Checking
		return true;
	}
	return false;
}

string Circle::getPointsWithinShape(){ //To print out the points within shape
    string output = "";
    for (int x = (centre_value_of_x - radius); x < (centre_value_of_x + radius); x++) {
        for (int y  = (centre_value_of_y - radius); y < (centre_value_of_y + radius) ; y++) { //To make sure the the points are in shape
            if (isPointInShape((x - centre_value_of_x), (y - centre_value_of_y))) {
                output += "(" + to_string(x) + ", " + to_string(y) + "), ";
            }
        }
    }
    if (output.empty()) {
        return "None!  ";
    }
    return output;
}

// To print out the points on perimeter, N, S, E, and W respectively
string Circle::getPointsOnPerimeter(){
    string output = "";
    if (isPointOnShape(centre_value_of_x, (radius + centre_value_of_y))) {
        output += "(" + to_string(centre_value_of_x) += ", " + to_string(radius + centre_value_of_y) + "), ";
    }
    if (isPointOnShape((radius + centre_value_of_x), centre_value_of_y)) {
        output += "(" + to_string(radius + centre_value_of_x) += ", " + to_string(centre_value_of_y) + "), ";
    }
    if (isPointOnShape(centre_value_of_x, (centre_value_of_y - radius))) {
        output += "(" + to_string(centre_value_of_x) += ", " + to_string(centre_value_of_y - radius) + "), ";
    }
    if (isPointOnShape((centre_value_of_x - radius), centre_value_of_y)) {
        output += "(" + to_string(centre_value_of_x - radius) += ", " + to_string(centre_value_of_y) + "), ";
    }
    if (output.empty()) {
        return "None!  ";
    }
    return output;
}

//toString Method
string Circle::toString(){
	string output = "";
    ostringstream area_output;  //Outputs the area in 2 decimal
	area_output << fixed << setprecision(2) << getArea();

	output += ShapeTwoD::toString();
	output += "Area: " + area_output.str() + " units square\n";
    output += "Centre: (" + to_string(centre_value_of_x) + ", " + to_string(centre_value_of_y) + ")\n";
	output += "Radius: " + to_string(radius) + " units\n";
	
    //To print the points on perimeter
	output += "\nPoints on perimeter: ";
	output += this->getPointsOnPerimeter();
    output.pop_back(); 
    output.pop_back();

	output += "\n\nPoints within shape: ";
    output += this->getPointsWithinShape();
    output.pop_back(); 
	output.pop_back(); 

    output += "\n------------------------------------------------------------------------------------------------------------------------";
	
	return output;
}