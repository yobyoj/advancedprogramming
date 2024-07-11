/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#include "ShapeTwoD.h"

//Default Constructor
ShapeTwoD::ShapeTwoD(){
}

//Other Constructor
ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace){	
	this->name = name;
	this->containsWarpSpace = containsWarpSpace;
}

//Deconstructor for Instance
ShapeTwoD::~ShapeTwoD(){
}

//Accessor method for area
string ShapeTwoD::getName(){
	return name;
}

//Mutator method for name
void ShapeTwoD::setName(string name){
	this->name = name;
}

//Accessor method for containsWarpSpace 
bool ShapeTwoD::getContainsWarpSpace(){
	return containsWarpSpace;
}

//Mutator method for containsWrapSpace
void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
	this->containsWarpSpace = containsWarpSpace;
}

double ShapeTwoD::computeArea(){
	return 1.0;
}

double ShapeTwoD::getArea(){
	return 1.0;
}

bool ShapeTwoD::isPointInShape(int x, int y){
    return false;
}

bool ShapeTwoD::isPointOnShape(int x, int y){
    return false;
}

//toString Method
string ShapeTwoD::toString(){
    string wrapSpace_Or_NormalSpace, output;
	if(containsWarpSpace == true){
		wrapSpace_Or_NormalSpace = "WS";
	}
	else{
		wrapSpace_Or_NormalSpace = "NS";
	}
	
	output = "Name : " + getName() +"\n";
    output += "Special Type : " + wrapSpace_Or_NormalSpace + "\n";
	return output;
}