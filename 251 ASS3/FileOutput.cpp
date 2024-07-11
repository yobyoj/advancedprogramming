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

#include "FileOutput.h"
#include "Sorting.h"

using namespace std;
//Global Variables
extern string filter_criteria;
extern string sorting_criteria;
extern string sorting_order;
extern bool inputfile;
extern vector<Point2D> uniquePoint2D;
extern vector<Point3D> uniquePoint3D;
extern vector<Line2D> uniqueLine2D;
extern vector<Line3D> uniqueLine3D;

//To store and write data
void writingToFile(){
	if (inputfile == false){
		cout << "You have not input any file!" << endl;
	}
	else{
		string write_filename;
		cout << "Please enter filename: ";
		cin >> write_filename;
		ofstream my_file(write_filename.c_str());

		//Output error = creating
		if (!my_file){
			cout << "Error creating " << write_filename << ". Try again. " << endl;
		}
		else{
			//If filter_criteria = Point2D
			if (filter_criteria == "Point2D"){
				//To call sorting_point2D function which sort accordingly
				sorting_point2D(sorting_criteria, sorting_order);

				//To print the header
				my_file << setw(5) << " X" << setw(6) << " Y" << setw(4) << " " << setw(14)<< "Dist Fr Origin" << endl;
				my_file << "- - - - - - - - - - - - - - - - - - -" << endl;
				//To prevent a copy from being made
				for (auto &value_point2d : uniquePoint2D){
					my_file << value_point2d;
				}
				cout << uniquePoint2D.size() << " records output successfully!" << endl << endl;
			}
			//else if filter_criteria is Point3D
			else if (filter_criteria == "Point3D"){
				//To call sorting_point3D function which sort accordingly
				sorting_point3D(sorting_criteria, sorting_order);

				//To print the header
				my_file << setw(5) << "X" << setw(6) << " Y" << setw(6) << " Z" << setw(18) << "Dist Fr Origin" << endl;
				my_file << "- - - - - - - - - - - - - - - - - - -" << endl;
				//To prevent a copy from being made
				for (auto &value_point3d : uniquePoint3D){
					my_file << value_point3d;
				}
				cout << uniquePoint3D.size() << " records output successfully!" << endl << endl;
			}
			//else if filter_criteria is Line2D
			else if (filter_criteria == "Line2D"){
				//To call sorting_Line2D function which sort accordingly
				sorting_Line2D(sorting_criteria, sorting_order);

				//To print the header
				my_file << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(2) << " " << setw(7) << "P2-X" << setw(6) << "P2-Y" << setw(10) << "Length" << endl;
				my_file << "- - - - - - - - - - - - - - - - - - -" << endl;
				//To prevent a copy from being made
				for (auto &value_line2d : uniqueLine2D){
					my_file << value_line2d;
				}
				cout << uniqueLine2D.size() << " records output successfully!" << endl << endl;
			}
			//else if filter_criteria is Line3D
			else if (filter_criteria == "Line3D"){
				//To call sorting_Line2D function which sort accordingly
				sorting_Line3D(sorting_criteria, sorting_order);

				//To print the header
				my_file << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z" << setw(4) << " " << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z" << setw(10) << "Length" << endl;
				my_file << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
				//To prevent a copy from being made
				for (auto &value_line3d : uniqueLine3D){
					my_file << value_line3d;
				}
				cout << uniqueLine3D.size() << " records output successfully!" << endl << endl;
			}
		}
		//To close my_file Stream
		my_file.close();
		cout << "Going back to main menu ..." << endl;
	}
}