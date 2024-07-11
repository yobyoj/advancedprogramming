/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

/*
    To compile (In Windows): 
		g++ -std=c++17 Line2D.cpp Line3D.cpp Point2D.cpp Point3D.cpp Utility.cpp ProcessStorePoints.cpp ProcessStoreLines.cpp SubMenu.cpp Sorting.cpp FileOutput.cpp 7433645_A3.cpp -o csci251_a3_windows.exe

	To compile (In Ubuntu): 
		g++ -std=c++17 Line2D.cpp Line3D.cpp Point2D.cpp Point3D.cpp Utility.cpp ProcessStorePoints.cpp ProcessStoreLines.cpp SubMenu.cpp Sorting.cpp FileOutput.cpp 7433645_A3.cpp -o csci251_a3_ubuntu.exe
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <limits>

#include "MyTemplates.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

#include "Utility.h"
#include "ProcessStorePoints.h"
#include "ProcessStoreLines.h"
#include "SubMenu.h"
#include "Sorting.h"
#include "FileOutput.h"

using namespace std;

//Global Variables
string filter_criteria;
string sorting_criteria;
string sorting_order;
bool inputfile;

vector<Point2D> uniquePoint2D;
vector<Point3D> uniquePoint3D;
vector<Line2D> uniqueLine2D;
vector<Line3D> uniqueLine3D;

//Function Prototypes
void displayMainMenu();
void readData();
void viewData();
void safelyDeallocateMemory();

int main(){
    filter_criteria = "Point2D"; 
	sorting_criteria = "X-ordinate"; 
	sorting_order = "ASC"; 
    inputfile = false;
    int user_choice;

	displayMainMenu();
	do{
        cout << "Please enter your choice: ";
		cin >> user_choice;
        switch(user_choice){
            case 1:
				//To read data
            	readData();
				break;
			
			case 2:
				//To specifiy filtering
            	filterOption();
				break;
			
			case 3:
				//To specifiy sorting 
            	sortingOption();
				break;
			
			case 4:
				//To specifiy ordering
            	sortOrder();
				break;
			
			case 5:
				//To view data
            	viewData();
				break;
			
			case 6:
				//To store data
				writingToFile();
				break;
			case 7:
				//Quit
				safelyDeallocateMemory();
				cout << "Thank you for using this program" << endl;
				cout << "Exiting ..." << endl;
				exit(0);
				break;
				
			default:
				cin.clear();  //To reset any error flags which may have been set
            	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To clear buffer
            	cout << "Invalid input. Please try again!" << endl;
		}
		displayMainMenu();
	}
	while(user_choice > 0 || user_choice < 8);
	return 0;
}

//To print and display the main menu
void displayMainMenu(){
    cout << setw(15) << left << "\nStudent ID"  << right << " : 7433645" << endl;
    cout << setw(14) << left << "Student Name" << right << " : Jian Ira Olvido Farne" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Welcome to Assn3 program!\n" << endl;
    cout << "1)" << setw(5) << " " << "Read in data" << endl;
    cout << "2)" << setw(5) << " " << "Specify filtering criteria (current : " << filter_criteria << ")" << endl;
    cout << "3)" << setw(5) << " " << "Specify sorting criteria (current:  " << sorting_criteria << ")" << endl;
    cout << "4)" << setw(5) << " " << "Specify sorting order (current: " << sorting_order << ")" << endl;
    cout << "5)" << setw(5) << " " << "View data" << endl;
    cout << "6)" << setw(5) << " " << "Store data" << endl;
    cout << "7)" << setw(5) << " " << "Quit" << endl << endl;
}

//To read data
void readData(){
	//Local Variables
    string filename_input;
    
    //To store Point2D, Point3D, line2D, line3D 
	vector<Point2D> point2DVec;
	vector<Point3D> point3DVec;
	vector<Line2D> line2DVec;
	vector<Line3D> line3DVec;
    
	cout << "\nPlease enter filename: ";
	cin >> filename_input;
	cout << endl;

	//To store unique data from the filename
	vector <string> uniqueData;
	uniqueData = uniqueFileData(filename_input);
		
	//To process Point2D, Point3D, Line2D and Line 3D 
	point2DVec = processPoint2D(uniqueData);
    point3DVec = processPoint3D(uniqueData);
	line2DVec = processLine2D(uniqueData);
	line3DVec = processLine3D(uniqueData);

	//To store all processes
	uniquePoint2D = point2DVec;
	uniquePoint3D = point3DVec;
	uniqueLine2D = line2DVec;
	uniqueLine3D = line3DVec;
    
    inputfile = true; //To set to true after user enter filename
    cout << uniqueData.size() << " records read in successfully!" << endl << endl;
	cout << "Going back to main menu ... " << endl; 
}

void viewData(){
	if (inputfile == false){
		cout << "You have not input any file!" << endl;
	}
	else{
		cout << "\n[ View data ... ]" << endl;
		cout << "Filtering criteria: " << filter_criteria << endl;
		cout << "Sorting criteria: " << sorting_criteria << endl;
		cout << "Sorting order: " << sorting_order << endl << endl;

		//If filter_criteria = Point2D
		if (filter_criteria == "Point2D"){
			//To call sorting_point2D function which sort accordingly
			sorting_point2D(sorting_criteria, sorting_order);
			//To display Point2D
			displayPoint2D();
		}
		//else if filter_criteria = Point3D
		else if (filter_criteria == "Point3D"){
			//To call sorting_point3D function which sort accordingly
			sorting_point3D(sorting_criteria, sorting_order);
			//To display Point3D
			displayPoint3D();
		}
		//else if filter_criteria = Line2D
		else if (filter_criteria == "Line2D"){
			//To call sorting_Line2D function which sort accordingly
			sorting_Line2D(sorting_criteria, sorting_order);
			//To display Line2D
			displayLine2D();
		}
		//else if filter_criteria = Line3D
		else if (filter_criteria == "Line3D"){
			//To call sorting_Line2D function which sort accordingly
			sorting_Line3D(sorting_criteria, sorting_order);
			//To display Line3D
			displayLine3D();
		}
		promptToEnterOnly();
	} 
}

//To prevent any memory leak
void safelyDeallocateMemory(){
	uniquePoint2D.clear(); //To clear every element - Point2D
	uniquePoint2D.shrink_to_fit(); //To reduce its capacity to zero

	uniquePoint3D.clear(); //To clear every element - Point3D
	uniquePoint3D.shrink_to_fit(); //To reduce its capacity to zero

	uniqueLine2D.clear(); //To clear every element - Line2D
	uniqueLine2D.shrink_to_fit(); //To reduce its capacity to zero

	uniqueLine3D.clear(); //To clear every element - Line3D
	uniqueLine3D.shrink_to_fit(); //To reduce its capacity to zero
}