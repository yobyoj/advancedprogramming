/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#include "Square.h"
#include <sstream>
#include <iomanip>

//Default Constructor
Square::Square(){
}

//Other Constructor
Square::Square(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){
}

//Deconstructor for the Instance
Square::~Square(){
}

//To set Data value of square
void Square::setData(int *x, int *y){
    bool check = false;
    int i = 1;

    //Sets mininum_value_of_x and maximum_value_of_x
    while (check == false) {
        if (x[0] == x[i]){
            i++;
        }
        else if (x[0] > x[i]){
            this->mininum_value_of_x = x[i];
            this->maximum_value_of_x = x[0];
            check = true;
        }
        else if (x[i] > x[0]){
            this->mininum_value_of_x = x[0];
            this->maximum_value_of_x = x[i];
            check = true;
        }
    }
    i = 1;
    check = false;
    //Sets mininum_value_of_y and maximum_value_y
    while (check == false) {
        if (y[0] == y[i]){
            i++;
        }
        else if (y[0] > y[i]){
            this->mininum_value_of_y = y[i];
            this->maximum_value_y = y[0];
            check = true;
        }
        else if (y[i] > y[0]){
            this->mininum_value_of_y = y[0];
            this->maximum_value_y = y[i];
            check = true;
        }
    }
    //To set length and breath respectively
    this->distance_of_x = maximum_value_of_x - mininum_value_of_x;
    this->distance_of_y = maximum_value_y - mininum_value_of_y; 
    //Assigns each x value to an array
    for (int i = 0; i < 4; i++){
    	this->x[i] = x[i];
    }
    //Assigns each y value to an array
    for (int i = 0; i < 4; i++){
    	this->y[i] = y[i];
    }
} 

//To compute its area
double Square::computeArea(){
    area = distance_of_x * distance_of_y;
	return area;
}

//Accessor method for area
double Square::getArea(){
	return area;
}

//Mutator Method for area 
void Square::setArea(){
    this->area = computeArea();
}

//To return true or false according to point within shape
bool Square::isPointInShape(int x, int y){
    //Parameter Checking: For Boundaries of Shape
    if (mininum_value_of_x < x && x < maximum_value_of_x && mininum_value_of_y < y && y < maximum_value_y){
		return true;
	}
    else{
        return false;
    }
}

//To return true or false according to point on perimeter
bool Square::isPointOnShape(int x, int y){ 
    if (x == mininum_value_of_x && y > mininum_value_of_y && y < maximum_value_y){
        return true;
    }
    else if (x > mininum_value_of_x && x < maximum_value_of_x && y == mininum_value_of_y){
        return true;
    }
    else if (x > mininum_value_of_x && x < maximum_value_of_x && y == maximum_value_y){
        return true;
    }
    else if (x == maximum_value_of_x && y > mininum_value_of_y && y < maximum_value_y){
        return true;
    }
    else{
        return false;
    }
}

//To print out the points on perimeter
string Square::getPointsOnPerimeter(){
    string output = "";
    for (int i = mininum_value_of_x; i <= maximum_value_of_x;i++){
		for (int j = mininum_value_of_y; j <= maximum_value_y; j++){
			if (isPointOnShape(i, j) == true){
				output += "(" + to_string(i) + ", " + to_string(j) + "), ";
            }
		}
	}
    if (output.empty()) {
        return "None!  ";
    }
    return output;
}

//To print out the points within shape
string Square::getPointsWithinShape(){
    string output = "";
    for (int i = mininum_value_of_x; i <= maximum_value_of_x;i++){
        for (int j = mininum_value_of_y; j <= maximum_value_y; j++){
            if(isPointInShape(i, j) == true){
                output += "(" + to_string(i) + ", " + to_string(j) + "), ";
            }
        }
    }
     if (output.empty()) {
        return "None!  ";
    }
    return output;
}

//toString Method
string Square::toString(){
	string output = "";
    //To output the area in 2 decimal places
    ostringstream area_output;
	area_output << fixed << setprecision(2) << getArea();

	output += ShapeTwoD::toString();
	output += "Area: " + area_output.str() + " units square\n";
    output += "Vertices:\n";

    //To print out the point of x and y accordingly
    for (int i = 0; i < 4; i++){
        output += "Point [" + to_string(i) + "]: (" + to_string(x[i]) + ", " + to_string(y[i]) + ")\n";
    }

    //To print the points on perimeter
	output += "\nPoints on perimeter: ";
	output += this->getPointsOnPerimeter();
    output.pop_back(); 
    output.pop_back(); 

    // To print points within shape
	output += "\n\nPoints within shape: ";
    output += this->getPointsWithinShape();
    output.pop_back(); 
    output.pop_back(); 
	output += "\n------------------------------------------------------------------------------------------------------------------------";
	
	return output;
}