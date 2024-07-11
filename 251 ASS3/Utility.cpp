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

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "Utility.h"

using namespace std;

//Global Variable
extern vector<Point2D> uniquePoint2D;
extern vector<Point3D> uniquePoint3D;
extern vector<Line2D> uniqueLine2D;
extern vector<Line3D> uniqueLine3D;

//To always prompt user to enter
void promptToEnterOnly(){
    char enter_key = ' ';
    do {
        cout << endl;
        cout << "Press <Enter> to go back to main menu ...";
        cin.clear();  //To reset error flgs 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To clear buffer before taking new
        enter_key = cin.get();
    } while (enter_key != '\n');
}

vector<string> splitString (string input, string delimiter){ //A method to return a vector string result
	size_t pos = 0;
	string token;
	vector<string> result;

	while ((pos = input.find(delimiter)) != string::npos){
    	token = input.substr(0, pos);
    	result.push_back (token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back (input);
	return result;
}

//To read the filename_input and remove duplicate values
vector <string> uniqueFileData(string filename_input){
	ifstream readFile (filename_input);
	string content;
	 
	//To store content from file into vector string 
	vector<string> file_data;
	if (readFile.good()){
		while (getline(readFile,content)){
			file_data.push_back(content);
		}
	}
	else{
        cout << "Error opening file" << endl;
    }   
	readFile.close();

	//To sort data
	sort(file_data.begin(), file_data.end());
	
	//To remove duplicates
	file_data.erase(unique(file_data.begin(), file_data.end()), file_data.end());
	
	return file_data;
}

//To display Point2D
void displayPoint2D(){
	cout << setw(5) << " X" << setw(6) << " Y" << setw(4) << " " << setw(14)<< "Dist Fr Origin" << endl;
	cout << "- - - - - - - - - - - - - - - - - - -" << endl;
	//To prevent a copy from being made
    for (auto &value_point2d : uniquePoint2D){
        cout << value_point2d;
    }
}

//To display Point3D
void displayPoint3D(){
	cout << setw(5) << "X" << setw(6) << " Y" << setw(6) << " Z" << setw(18) << "Dist Fr Origin" << endl;
	cout << "- - - - - - - - - - - - - - - - - - -" << endl;
	//To prevent a copy from being made
	for (auto &value_point3d : uniquePoint3D){
        cout << value_point3d;
    }
}

//To display Line2D
void displayLine2D(){
	cout << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(2) << " " << setw(7) << "P2-X" << setw(6) << "P2-Y" << setw(10) << "Length" << endl;
	cout << "- - - - - - - - - - - - - - - - - - -" << endl;
	//To prevent a copy from being made
	for (auto &value_line2d : uniqueLine2D){
        cout << value_line2d;
    }
}

//To display Line2D
void displayLine3D(){
	cout << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z" << setw(4) << " " << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z" << setw(10) << "Length" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	//To prevent a copy from being made
	for (auto &value_line3d : uniqueLine3D){
        cout << value_line3d;
    }
}