/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#include "Cross.h"
#include <vector>
#include <sstream>
#include <iomanip>

//Default constructor
Cross::Cross(){
    
}

//Other Construtor
Cross::Cross(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){

}

//Deconstructor for instance
Cross::~Cross(){
}

void Cross::setData(int *x, int *y){
    //Vector temporarily stores the values 
    vector<int> temp_mininum_value_of_x;
    vector<int> temp_maximum_value_of_x;
    vector<int> temp_mininum_value_of_y;
    vector<int> temp_maximum_value_of_y;
    //assigns x-value to the array
    for (int i = 0; i < 12; i++){
    	this->x[i] = x[i];
    }
    //assigns y-value to the array
    for (int i = 0; i < 4; i++){
    	this->y[i] = y[i];
    }
    mininum_value_of_x = x[0];
    maximum_value_of_x = x[0];
    mininum_value_of_y = y[0];
    maximum_value_of_y = y[0];

    //To find x coord for R AND L points
    for(int i = 0; i < 12; i++) {
        if(x[i] < mininum_value_of_x){
            mininum_value_of_x = x[i];
        }
        else if(x[i] > maximum_value_of_x){
            maximum_value_of_x = x[i];
        }
    }
    //To find y coord of TOP and BOTTOM points 
    for(int i = 0; i < 12; i++){
        if(y[i] < mininum_value_of_y){
            mininum_value_of_y = y[i];
        }
        else if(y[i] > maximum_value_of_y){
            maximum_value_of_y = y[i];
        }
    }

    for (int i = 0; i < 12; i++){
        if (x[i] == mininum_value_of_x){
            temp_mininum_value_of_x.push_back(y[i]);
        }
        else if (x[i] == maximum_value_of_x)
            temp_maximum_value_of_x.push_back(y[i]);
        if (y[i] == mininum_value_of_y)
            temp_mininum_value_of_y.push_back(x[i]);
        else if (y[i] == maximum_value_of_y)
            temp_maximum_value_of_y.push_back(x[i]);
    } 

    if (temp_mininum_value_of_x[0] < temp_mininum_value_of_x[1]){
        left_bottom_y = temp_mininum_value_of_x[0];
        left_top_y = temp_mininum_value_of_x[1];
    }
    else{
        left_bottom_y = temp_mininum_value_of_x[1];
        left_top_y = temp_mininum_value_of_x[0];
    }

    if (temp_maximum_value_of_x[0] < temp_maximum_value_of_x[1]){
        right_bottom_y = temp_maximum_value_of_x[0];
        right_top_y = temp_maximum_value_of_x[1];
    }
    else{
        right_bottom_y = temp_maximum_value_of_x[1];
        right_top_y = temp_maximum_value_of_x[0];
    }

    if (temp_mininum_value_of_y[0] < temp_mininum_value_of_y[1]){
        bottom_left_x = temp_mininum_value_of_y[0];
        bottom_right_x = temp_mininum_value_of_y[1];
    }
    else {
        bottom_left_x = temp_mininum_value_of_y[1];
        bottom_right_x = temp_mininum_value_of_y[0];
    }

    if (temp_maximum_value_of_y[0] < temp_maximum_value_of_y[1]){
        top_left_x = temp_maximum_value_of_y[0];
        top_right_x = temp_maximum_value_of_y[1];
    }
    else {
        top_left_x = temp_maximum_value_of_y[1];
        top_right_x = temp_maximum_value_of_y[0];
    }

    //memory became such a headache for me but this lines of code helped
    temp_mininum_value_of_x.clear(); 
    temp_maximum_value_of_x.clear();
    temp_mininum_value_of_y.clear();
    temp_maximum_value_of_y.clear();
    
    //Since crosses can be miscontrued, dividing them into shapes like rectangles and squares, LIMIT SET = 5 //FINAL EDIT: should be 5
    if (left_top_y > right_top_y){
        top_bottom_y = left_top_y;
    }
    else{
        top_bottom_y = right_top_y;
    }

    if (left_bottom_y < right_bottom_y){
        bottom_top_y = left_bottom_y;
    }
    else{
        bottom_top_y = right_bottom_y;
    }
    
    if (top_left_x < bottom_left_x){
        left_right_x = top_left_x;
    }
    else{
        left_right_x = bottom_left_x;
    }
        
    if (top_right_x > bottom_right_x){
        right_left_x = top_right_x;
    }
    else{
        right_left_x = bottom_right_x;
    }
}

//To compute its area 
double Cross::computeArea(){

    //Subdivided the area so I can just add them all later
    double top_area_A = (maximum_value_of_y - top_bottom_y) * (top_right_x - top_left_x);
    double bottom_area_B = (bottom_top_y - mininum_value_of_y) * (bottom_right_x - bottom_left_x);
    double left_area_C = (left_right_x - mininum_value_of_x) * (left_top_y - left_bottom_y);
    double right_area_D = (maximum_value_of_x - right_left_x) * (right_top_y - right_bottom_y);
    double middle_area_E = (right_left_x - left_right_x) * (top_bottom_y - bottom_top_y);
    area = top_area_A +  bottom_area_B + left_area_C + right_area_D + middle_area_E;
	return area;
}

//Accessor method
double Cross::getArea(){
	return area;
}

//Mutator method
void Cross::setArea(){
    this->area = computeArea();
}

//Parameter Checking, to check if it is in the boundaries
bool Cross::isPointInShape(int x, int y) {
    if (mininum_value_of_x < x && x <= left_right_x){
		if (left_bottom_y < y && y < left_top_y){
            return true;
        }
	}
    else if (top_bottom_y <= y && y < maximum_value_of_y){
		if (top_left_x < x && x < top_right_x){
            return true;
        }
	}
    else if (right_left_x <= x && x < maximum_value_of_x){
		if (right_bottom_y < y && y < right_top_y){
            return true;
        }
	}
    else if (mininum_value_of_y < y && y <= bottom_top_y){
		if (bottom_left_x < x && x < bottom_right_x){
            return true;
        }
	}
    else if (bottom_top_y <= y && y <= top_bottom_y){
		if (left_right_x <= x && x <= right_left_x){
            return true;
        }
	}
	return false;
}

//Parameter Checking = 12 lines, FINAL EDIT: 12 LINES
bool Cross::isPointOnShape(int x, int y) {
	if (x == mininum_value_of_x){
        if (left_bottom_y < y && y < left_top_y){
            return true;
        }
    }
    if (x == maximum_value_of_x){
        if (right_bottom_y < y && y < right_top_y){
            return true;
        }
    }
    if (x == top_left_x){
        if (left_top_y < y && y < maximum_value_of_y){
            return true;
        }
    }
    if (x == top_right_x){
        if (right_top_y < y && y < maximum_value_of_y){
            return true;
        }
    }
    if (x == bottom_left_x){
        if (mininum_value_of_y < y && y < left_bottom_y){
            return true;
        }
    }
    if (x == bottom_right_x){
        if (mininum_value_of_y < y && y < right_bottom_y){
            return true;
        }
    }
    if (y == maximum_value_of_y){
        if (top_left_x < x && x < top_right_x){
            return true;
        }
    }
    if (y == mininum_value_of_y){
        if (bottom_left_x < x && x < bottom_right_x){
            return true;
        }
    }
    if (y == left_top_y){
        if (mininum_value_of_x < x && x < top_left_x){
            return true;
        }
    }
    if (y == left_bottom_y){
        if (mininum_value_of_x < x && x < bottom_left_x){
            return true;
        }
    }
    if (y == right_top_y){
        if (top_right_x < x && x < maximum_value_of_x){
            return true;
        }
    }
    if (y == right_bottom_y){
        if (bottom_right_x < x && x < maximum_value_of_x){
            return true;
        }
    }
    return false;
}

//Prints out the points on Perimeter
string Cross::getPointsOnPerimeter(){
    string output = "";
    for (int i = mininum_value_of_x; i <= maximum_value_of_x; i++){
		for (int j = mininum_value_of_y; j <= maximum_value_of_y; j++){
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

//Prints out the points within Shape
string Cross::getPointsWithinShape(){
    string output = "";
    for (int i = mininum_value_of_x; i <= maximum_value_of_x;i++){
        for (int j = mininum_value_of_y; j <= maximum_value_of_y; j++){
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
string Cross::toString(){
    string output = "";
    //Outputs area in 2 decimal places, FINAL EDIT: 2
    ostringstream area_output;
	area_output << fixed << setprecision(2) << getArea();

	output += ShapeTwoD::toString();
	output += "Area: " + area_output.str() + " units square\n";
    output += "Vertices:\n";

    //Prints out the point of x and y accordingly
    output += "Point [0]: (" + to_string(bottom_left_x) + ", " + to_string(mininum_value_of_y) + ")\n";
    output += "Point [1]: (" + to_string(bottom_right_x) + ", " + to_string(mininum_value_of_y) + ")\n";
    output += "Point [2]: (" + to_string(bottom_right_x) + ", " + to_string(right_bottom_y) + ")\n";
    output += "Point [3]: (" + to_string(maximum_value_of_x) + ", " + to_string(right_bottom_y) + ")\n";
    output += "Point [4]: (" + to_string(maximum_value_of_x) + ", " + to_string(right_top_y) + ")\n";
    output += "Point [5]: (" + to_string(top_right_x) + ", " + to_string(right_top_y) + ")\n";
    output += "Point [6]: (" + to_string(top_right_x) + ", " + to_string(maximum_value_of_y) + ")\n";
    output += "Point [7]: (" + to_string(top_left_x) + ", " + to_string(maximum_value_of_y) + ")\n";
    output += "Point [8]: (" + to_string(top_left_x) + ", " + to_string(left_top_y) + ")\n";
    output += "Point [9]: (" + to_string(mininum_value_of_x) + ", " + to_string(left_top_y) + ")\n";
    output += "Point [10]: (" + to_string(mininum_value_of_x) + ", " + to_string(left_bottom_y) + ")\n";
    output += "Point [11]: (" + to_string(bottom_left_x) + ", " + to_string(left_bottom_y) + ")\n";
	
    //Prints the points on perimeter
	output += "\nPoints on perimeter: ";
	output += this->getPointsOnPerimeter();
    output.pop_back(); 
    output.pop_back(); 
	
	//Prints the points within the shape
	output += "\n\nPoints within shape: ";
    output += this->getPointsWithinShape();
    output.pop_back(); 
    output.pop_back(); 
    
    output += "\n------------------------------------------------------------------------------------------------------------------------";
	
	return output;
}