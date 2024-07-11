/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#include "ShapeTwoD.h"
#include "Circle.h"
#include "Cross.h"
#include "Rectangle.h"
#include "Square.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// GLOBAL VARIABLES
vector<ShapeTwoD*> twoDShapes;
vector<ShapeTwoD*> shapecalculated;

// FUNCTION PROTOTYPES
void proccessingOfShapes(string shape_name, bool containsWarpSpace);
void processCircleShape(string shape_name, bool containsWarpSpace);
void processSquare_Rectangle_Cross_Shapes(string shape_name, bool containsWarpSpace, int number_of_sides);

// To print and display the main menu
void displayMainMenu(){
    cout << setw(15) << left << "\nStudent ID"  << right << " : 7433645" << endl;
    cout << setw(14) << left << "Student Name" << right << " : Jian Ira O. Farne" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Welcome to Assn2 program!\n" << endl;
    cout << "1)" << setw(5) << " " << "Input sensor data" << endl;
    cout << "2)" << setw(5) << " " << "Compute area (for all records)" << endl;
    cout << "3)" << setw(5) << " " << "Print shapes report" << endl;
    cout << "4)" << setw(5) << " " << "Sort shape data" << endl;
    cout << "5)" << setw(5) << " " << "Quit" << endl << endl; 
}

// To input sensor data (shape_name and special type)
void inputSensorData(){
    // LOCAL VARIABLES
    bool containsWarpSpace;
    bool check = false;
    string shape_name, special_type;
    
    cout << "\n[Input Sensor Data]" << endl;
    //while loop make sure user enters correct sahpe name
    while (check == false){
		cout << "Please enter name of shape: ";
		cin >> shape_name;

        // This will transform all the given string of shape_name into lower case
        transform(shape_name.begin(), shape_name.end(), shape_name.begin(), ::tolower); 

		if(shape_name == "cross" || shape_name == "rectangle" || shape_name == "square" || shape_name == "circle"){
            check = true;
        }
		else{
            cout << "\t\tWRONG INPUT! Please enter Cross / Rectangle / Square / Circle" << endl;
        }	
	}
    check = false;
    //while loop make sure user enters correct special type
    while (check == false) {
        cout << "Please enter special type: ";
        cin >> special_type;

        // This will transform all the given string of special_type into lower case
        transform(special_type.begin(), special_type.end(), special_type.begin(), ::tolower); 

		if(special_type == "ws" || special_type == "ns"){
			check = true;
        }
		else{
            cout << "\t\tWRONG INPUT! Please enter WS, (Warp-space) or NS, (Normal-space)" << endl;
        }	
    }
    cout << endl;
    // To assign type as bool to variable containsWarpSpace
    if(special_type == "ws"){
        containsWarpSpace = true;
    }
	else{
        containsWarpSpace = false;
    }
    proccessingOfShapes(shape_name, containsWarpSpace);
    cout <<"Record successfully stored, Going back to main menu ..." << endl;
}

// To process shapes accordingly
void proccessingOfShapes(string shape_name, bool containsWarpSpace){
    if (shape_name == "circle"){
        processCircleShape(shape_name, containsWarpSpace);
    }
    else if (shape_name == "square"){
        int num_of_sides = 4;
        // To create new shape object and add to vector (twoDShapes)
        twoDShapes.push_back(new Square("Square", containsWarpSpace));
        processSquare_Rectangle_Cross_Shapes(shape_name, containsWarpSpace, num_of_sides);
    }
    else if (shape_name == "rectangle"){
        int num_of_sides = 4;
        // To create new shape object and add to vector (twoDShapes)
        twoDShapes.push_back(new Rectangle("Rectangle", containsWarpSpace));
        processSquare_Rectangle_Cross_Shapes(shape_name, containsWarpSpace, num_of_sides);
    }
    else if (shape_name == "cross"){
        int num_of_sides = 12;
        // To create new shape object and add to vector (twoDShapes)
        twoDShapes.push_back(new Cross("Cross", containsWarpSpace));
        processSquare_Rectangle_Cross_Shapes(shape_name, containsWarpSpace, num_of_sides);
    }
}

// This will process Circle shape
void processCircleShape(string shape_name, bool containsWarpSpace){
    // LOCAL VARIABLE FOR CIRCLE 
    int x, y, radius;
    bool checkNum = false;
    string x_input, y_input, radius_input;

    // To create new shape object and add to vector (twoDShapes)
    twoDShapes.push_back(new Circle("Circle", containsWarpSpace));
    
    // To ensure user only input numbers only for x-oridinate
    while(checkNum == false){
        cout << "Please enter x-oridinate of center: ";
	    cin >> x_input;
        /*
            If any character from value "x_input" is other than "-0123456789" until the end of the variable, 
            it will return “string::npos” which means "not matched"
        */
        if ((x_input.find_first_not_of("-0123456789") == string::npos) == true){
            checkNum = true;
        }
        else{
            cout << "\t\tWRONG INPUT! Please enter only interger (number)!" << endl;
        }
    }
    checkNum = false;
    // To ensure user only input numbers only for y-oridinate
    while(checkNum == false){
        cout << "Please enter y-oridinate of center: ";
	    cin >> y_input;
        /*
            If any character from value "y_input" is other than "-0123456789" until the end of the variable, 
            it will return “string::npos” which means "not matched"
        */
        if ((y_input.find_first_not_of("-0123456789") == string::npos) == true){
            checkNum = true;
        }
        else{
            cout << "\t\tWRONG INPUT! Please enter only interger (number)!" << endl;
        }
    }
    checkNum = false;
    // To ensure user only input numbers only for radius
    while(checkNum == false){
        cout << "Please enter radius (units): ";
	    cin >> radius_input;
        /*
            If any character from value "radius_input" is other than "-0123456789" until the end of the variable, 
            it will return “string::npos” which means "not matched"
        */
        if ((radius_input.find_first_not_of("-0123456789") == string::npos) == true){
            checkNum = true;
        }
        else{
            cout << "\t\tWRONG INPUT! Please enter only interger (number)!" << endl;
        }
    }
    // If both x, y  and radius is valid digit (numbers), then it will store as variable
    if (checkNum == true){
        x = stoi(x_input);
        y = stoi(y_input);
        radius = stoi(radius_input);
        twoDShapes[(twoDShapes.size()-1)]-> setData2(x, y, radius);
    } 
    cout << endl;
}

// This will process other shape (Square, Rectangle, Cross)
void processSquare_Rectangle_Cross_Shapes(string shape_name, bool containsWarpSpace, int number_of_sides){
    // LOCAL VARAIBLES FOR SQUARE
    int x_value[number_of_sides];
    int y_value[number_of_sides];
    int xy = 0;
    bool checkNum;
    string x_input, y_input;

    for (int i = 0; i < number_of_sides; i++){
        int x, y;
        bool okay;
        bool flag = true;
         
        //  To check if user enter any duplicate x-oridinate and y-ordinate
        do{
            checkNum = false;
            // To ensure user only input numbers only for x-oridinate
            while(checkNum == false){
                cout << "Please enter x-ordinate of pt." << i+1 << ": ";
                cin >> x_input;
                /*
                    If any character from value "x_input" is other than "-0123456789" until the end of the variable, 
                    it will return “string::npos” which means "not matched"
                */
                if ((x_input.find_first_not_of("-0123456789") == string::npos) == true){
                    checkNum = true;
                }
                else{
                    cout << "\t\tWRONG INPUT! Please enter only interger (number)!" << endl;
                }
            }
            checkNum = false;
            // To ensure user only input numbers only for y-oridinate
            while(checkNum == false){
                cout << "Please enter y-ordinate of pt." << i+1 << ": ";
                cin >> y_input;
                /*
                    If any character from value "y_input" is other than "-0123456789" until the end of the variable, 
                    it will return “string::npos” which means "not matched"
                */
                if ((y_input.find_first_not_of("-0123456789") == string::npos) == true){
                    checkNum = true;
                }
                else{
                    cout << "\t\tWRONG INPUT! Please enter only interger (number)!" << endl;
                }
            }
            // If both x and y is valid digit (numbers), then it will store as variable
            if (checkNum == true){
                x = stoi(x_input);
                y = stoi(y_input);
            }
            okay = true;
            // This will compare with all the x and y values that was previous entered
            for (int k = 0; k < number_of_sides; k++){
                // If duplicates found, user will have to re-enter that point again
                if(x == x_value[k] && y == y_value[k]){
                    cout << "\t\tYou have entered identical x-oridinate and y-ordinate, please enter again." << endl;
                    okay = false;
                }
            }
            if(okay == true){
                x_value[xy] = x;
			    y_value[xy] = y;
                xy += 1;
                twoDShapes[(twoDShapes.size()-1)]-> setData(x_value, y_value);
                flag = false;
            }
            cout << endl;
        }
        while(flag == true);
    }
}

// This method will computed the newly updated/entered of inputSensorData. 
void computeAreaForAllRecords(){
    for (int i = 0; i < twoDShapes.size(); i++){
        shapecalculated.push_back(twoDShapes[i]); // add to computed shape vector
        shapecalculated.back()->computeArea();    // computes the area of shape
    }
    cout << "Computation completed! (" << twoDShapes.size() << " records were updated)" << endl;
}

// This will prints the shapes report accordingly
void printShapesReport(){
    cout << "Total no. of records available = " << twoDShapes.size() << endl << endl;
    for (int i = 0; i < twoDShapes.size(); i++){
        cout << "Shape [" << i << "]" << endl;
        // To call overridden version of the toString()
        cout << twoDShapes[i]->toString() << endl; // print report for each shape that has been overriden
    }
}

// Function to sort in ascending order
bool sortAscending(ShapeTwoD *a, ShapeTwoD *b){
    return (a->getArea() < b->getArea());
}

// Function to sort in descending order
bool sortDescending(ShapeTwoD *a, ShapeTwoD *b){
    return (a->getArea() > b->getArea());
}

// Function to sort by type then descending order
bool sortByTypeThenDesc(ShapeTwoD *a, ShapeTwoD *b) {
    if(a->getContainsWarpSpace() != b->getContainsWarpSpace()){
        // "true" (WS) then "false" (NS)
        return (a->getContainsWarpSpace() > b->getContainsWarpSpace());
    }
    if (a->getArea() != b->getArea()) {
        // descending using >
        return (a->getArea() > b->getArea());
    }
    return false;
}

void sortShapesData(){
    string userinput;
	static int i = 0;

    //if no computed shapes
	if(shapecalculated.size() == 0){
        cout << "You have not input data" << endl;
    }
	else{
        //check if user inputs appropriate character
        while (userinput != "q"){
            cout << "Sort shape data" << endl;
        	cout << "\ta)\tSort by area (ascending)" << endl;
    		cout << "\tb)\tSort by area (descending)" << endl;
    		cout << "\tc)\tSort by special type and area" << endl << endl;
    		cout << "Please select sort option ('q' to go main menu): ";
    		cin >> userinput;

            // This will transform all the given string of userinput into lower case
            transform(userinput.begin(), userinput.end(), userinput.begin(), ::tolower);
            
            // If userinput == q; it will do nothing and return to the main menu
            if (userinput == "q"){

            }
            //sort ascending order
            else if (userinput == "a") {
                cout << "Sort by area (smallest to largest)" << endl << endl;
                sort(shapecalculated.begin(), shapecalculated.end(), sortAscending);
				for(int i = 0; i < shapecalculated.size(); i++){
				    cout << "Shape [" << i << "]" << endl;
					cout << shapecalculated[i]->toString() << endl; //print shapes report
				}
                userinput = "q";
            }
            //sort descending order
            else if (userinput == "b"){
                cout << "Sort by area (largest to smallest)" << endl << endl;
                sort(shapecalculated.begin(), shapecalculated.end(), sortDescending);
				for(int i = 0; i < shapecalculated.size(); i++){
				    cout << "Shape [" << i << "]" << endl;
					cout << shapecalculated[i]->toString() << endl; //print shapes report
				}
                userinput = "q";
            }
            //sort by type then descending order
            else if (userinput == "c"){
                cout << "Sort by special type (WS to NS) then area (largest to smallest)" << endl << endl;
                sort(shapecalculated.begin(), shapecalculated.end(), sortByTypeThenDesc);
				for(int i = 0; i < shapecalculated.size(); i++){
				    cout << "Shape [" << i << "]" << endl;
					cout << shapecalculated[i]->toString() << endl; //print shapes report
				}
                userinput = "q";
            }
            else{
                cin.clear();  // resets any error flags which may have been set
            	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This will clear buffer before taking new
                cout << "Please select an option." << endl << endl; 
            }
		}
	}
}

//clears the 2 vectors when program exits
void safelyDeallocateMemory(){
    twoDShapes.clear(); // This will clear every element inside the vector
    twoDShapes.shrink_to_fit(); // This will reduce its capacity to its original size which zero
    shapecalculated.clear(); // This will clear every element inside the vector
    shapecalculated.shrink_to_fit(); // This will reduce its capacity to its original size which zero
}