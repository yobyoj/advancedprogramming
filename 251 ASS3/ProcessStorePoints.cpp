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

#include "ProcessStorePoints.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Utility.h"

using namespace std;

//To process all Point2D
vector<Point2D> processPoint2D(vector<string> file_data){
	vector <string> tokenStringVector;
	vector <string> point2d_x; 
	vector <string> point2d_y;

	//To Store Point2D objects
	vector <Point2D> point2DVec;

	for (int i=0; i<file_data.size(); i++){
		tokenStringVector = splitString (file_data[i], ", ");
		if (tokenStringVector[0] == "Point2D"){
			point2d_x.push_back(tokenStringVector[1]);
			point2d_y.push_back(tokenStringVector[2]);
		} 
	}
	point2DVec = storePoint2D(point2d_x, point2d_y);
	return point2DVec;
}

//To store all Point2D
vector<Point2D> storePoint2D(vector <string> point2d_x, vector <string> point2d_y){
	//To store Point2D objects
	vector<Point2D> point2DVec;

	//To remove brackets
	for (int i=0; i<point2d_x.size(); i++){
		size_t openBracket = point2d_x[i].find("[");
		size_t closeBracket = point2d_y[i].find("]");
		string x_value = point2d_x[i].substr(openBracket +1);
		string y_value = point2d_y[i].substr(0, closeBracket);

        // To store values of Point 2D
		int x = stoi(x_value);
		int y = stoi(y_value);
		point2DVec.push_back(Point2D(x,y));
	}
	return point2DVec;
}


//To process all Point3D
vector<Point3D> processPoint3D(vector<string> file_data){
	vector <string> tokenStringVector;
	vector <string> point3d_x;
	vector <string> point3d_y;
	vector <string> point3d_z;

	//To store Point3D objects
	vector<Point3D> point3DVec;

	for (int i=0; i<file_data.size(); i++){
		tokenStringVector = splitString (file_data[i], ", ");
		
		if (tokenStringVector[0] == "Point3D"){
			point3d_x.push_back(tokenStringVector[1]);
			point3d_y.push_back(tokenStringVector[2]);
			point3d_z.push_back(tokenStringVector[3]);
		}
	}
	point3DVec = storePoint3D(point3d_x, point3d_y, point3d_z);
	return point3DVec;
}

//To stores all Point3D
vector<Point3D> storePoint3D(vector <string> point3d_x, vector <string> point3d_y, vector <string> point3d_z){
	//To store Point3D objects
	vector<Point3D> point3DVector;

	//To remove brackets
	for (int i=0; i<point3d_x.size(); i++){
		size_t openBracket = point3d_x[i].find("[");
		size_t closeBracket = point3d_z[i].find("]");
		string x_value = point3d_x[i].substr(openBracket +1);
		string y_value = point3d_y[i].substr(0);
		string z_value = point3d_z[i].substr(0, closeBracket);

		//To store values of Point 3D
		int x = stoi(x_value);
		int y = stoi(y_value);
		int z = stoi(z_value);
		point3DVector.push_back(Point3D(x,y,z));
	}
	return point3DVector;
}