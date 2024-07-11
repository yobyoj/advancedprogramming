/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <limits>

#include "SubMenu.h"

using namespace std;
//Global Variables
extern string filter_criteria;
extern string sorting_criteria;
extern string sorting_order;

//To specify criteria
void filterOption(){
	string select_option;
	while (select_option.empty()){
		cout << "[Specifying filtering criteria (current: " << filter_criteria << ")]" << endl << endl;
		cout << "\ta)\tPoint2D records" << endl;
		cout << "\tb)\tPoint3D records" << endl;
		cout << "\tc)\tLine2D records" << endl;
		cout << "\td)\tLine3D records" << endl << endl;
		cout << "\tPlease enter your criteria (a-d): ";
		cin >> select_option;
		
        //To transform into lower case
        transform(select_option.begin(), select_option.end(), select_option.begin(), ::tolower); 

		if (select_option == "a"){
			filter_criteria = "Point2D";
            sorting_criteria = "X-ordinate";
        }
		else if (select_option == "b"){
			filter_criteria = "Point3D";
            sorting_criteria = "X-ordinate";
        }
		else if (select_option == "c"){
			filter_criteria = "Line2D";
            sorting_criteria = "Pt. 1";
        }
		else if (select_option == "d"){
			filter_criteria = "Line3D";
            sorting_criteria = "Pt. 1";
        }
		else{
			cout << "\tPlease enter a valid option." << endl << endl;
			select_option.clear();
		}
	}
	cout << "Filter criteria successfully set to '" << filter_criteria << "'!" << endl << endl;
}

//To specify criteria option
void sortingOption(){
	string select_option;
	while (select_option.empty()){
		cout << "[Specifying sorting criteria (current: " << sorting_criteria << ")]" << endl << endl;
		if (filter_criteria == "Point2D"){
			cout << "\ta)\tX-ordinate value" << endl;
			cout << "\tb)\tY-ordinate value" << endl;
			cout << "\tc)\tDist from origin" << endl << endl;
			cout << "\tPlease enter your criteria (a-c): ";
			cin >> select_option;
			
            //To transform into lower case
            transform(select_option.begin(), select_option.end(), select_option.begin(), ::tolower); 

			if (select_option == "a"){
				sorting_criteria = "X-ordinate";
            }
			else if (select_option == "b"){
				sorting_criteria = "Y-ordinate";
            }
			else if (select_option == "c"){
				sorting_criteria = "Dist. Fr Origin";
            }
			else{
				cout << "\tPlease enter a valid option." << endl << endl;
				select_option.clear();
			}
		}
	    else if (filter_criteria == "Point3D"){
			cout << "\ta)\tX-ordinate value" << endl;
			cout << "\tb)\tY-ordinate value" << endl;
			cout << "\tc)\tZ-ordinate value" << endl;
			cout << "\td)\tDist from origin" << endl << endl;
			cout << "\tPlease enter your criteria (a-d): ";
			cin >> select_option;
			
            //To transform into lower case
            transform(select_option.begin(), select_option.end(), select_option.begin(), ::tolower); 

			if (select_option == "a")
				sorting_criteria = "X-ordinate";
			else if (select_option == "b")
				sorting_criteria = "Y-ordinate";
			else if (select_option == "c")
				sorting_criteria = "Z-ordinate";
			else if (select_option == "d")
				sorting_criteria = "Dist. Fr Origin";
			else{
				cout << "\tPlease enter a valid option." << endl << endl;
				select_option.clear();
			}
		}
		else if (filter_criteria == "Line2D" || filter_criteria == "Line3D"){
			cout << "\ta)\tX and Y coordinate values of Pt. 1" << endl;
			cout << "\tb)\tX and Y coordinate values of Pt. 2" << endl;
			cout << "\tc)\tLength value" << endl << endl;
			cout << "\tPlease enter your criteria (a-c): ";
			cin >> select_option;
			
            //To transform into lower case
            transform(select_option.begin(), select_option.end(), select_option.begin(), ::tolower); 

			if (select_option == "a"){
				sorting_criteria = "Pt. 1";
			}
			else if (select_option == "b"){
				sorting_criteria = "Pt. 2";
			}
			else if (select_option == "c"){
				sorting_criteria = "Length";
			}
			else{
				cout << "\tPlease enter a valid option." << endl << endl;
				select_option.clear();
			}
		}
	}
	cout << "Sorting criteria successfully set to '" << sorting_criteria << "'!" << endl << endl;
}

//To specify order option
void sortOrder(){
	string select_option;
	while (select_option.empty()){
		cout << "[Specifying sorting order (current: " << sorting_order << ")]" << endl << endl;
		cout << "\ta)\tASC(Ascending order)" << endl;
		cout << "\tb)\tDSC(Descending order)" << endl << endl;
		cout << "\tPlease enter your criteria (a-b): ";
		cin >> select_option;
		
        //To transform into lower case
        transform(select_option.begin(), select_option.end(), select_option.begin(), ::tolower); 

		if (select_option == "a"){
			sorting_order = "ASC";
        }
		else if (select_option == "b"){
			sorting_order = "DSC";
        }
		else{
			cout << "\tPlease enter a valid option." << endl << endl;
			select_option.clear();
		}
	}
	cout << "Sorting order successfully set to '" << sorting_order << "'!" << endl << endl;
}