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

#include "ProcessStoreLines.h"
#include "ProcessStorePoints.h"
#include "Line2D.h"
#include "Line3D.h"
#include "Utility.h"

using namespace std;
//To process all Line2D
vector<Line2D> processLine2D(vector<string> file_data){
	vector <string> tokenStringVector;

	vector <string> line2dx1; 
	vector <string> line2dy1;
	vector <string> line2dx2;
	vector <string> line2dy2;

	//To store Line2D objects
	vector<Line2D> line2DVec;

	//To store Line2D Point1 and Point2 respectively
	vector<Point2D> line2DPt1Vector; 
	vector<Point2D> line2DPt2Vector; 

	for (int i=0; i<file_data.size(); i++){
		tokenStringVector = splitString (file_data[i], ", ");
		if (tokenStringVector[0] == "Line2D"){
			line2dx1.push_back(tokenStringVector[1]);
			line2dy1.push_back(tokenStringVector[2]);
			line2dx2.push_back(tokenStringVector[3]);
			line2dy2.push_back(tokenStringVector[4]);
		}
	}
	
	//To remove brackets
	line2DPt1Vector = storePoint2D(line2dx1, line2dy1);
	line2DPt2Vector = storePoint2D(line2dx2, line2dy2);

	//To store into Line2D
	for (int i=0; i<line2DPt1Vector.size(); i++){
		line2DVec.push_back(Line2D(line2DPt1Vector[i], line2DPt2Vector[i]));
	}
	return line2DVec;
}

//To process all Line2D
vector<Line3D> processLine3D(vector<string> file_data){
	vector <string> tokenStringVector;

	vector <string> line3dx1; 
	vector <string> line3dy1;
	vector <string> line3dz1;
	vector <string> line3dx2;
	vector <string> line3dy2;
	vector <string> line3dz2;

	//To store Line3D objects
	vector<Line3D> line3DVector;

	//To store Line2D Point1 and Point2 respectively
	vector<Point3D> line3DPt1Vector; 
	vector<Point3D> line3DPt2Vector; 

	for (int i=0; i<file_data.size(); i++){
		tokenStringVector = splitString (file_data[i], ", ");
		if (tokenStringVector[0] == "Line3D"){
			line3dx1.push_back(tokenStringVector[1]);
			line3dy1.push_back(tokenStringVector[2]);
			line3dz1.push_back(tokenStringVector[3]);
			line3dx2.push_back(tokenStringVector[4]);
			line3dy2.push_back(tokenStringVector[5]);
			line3dz2.push_back(tokenStringVector[6]);
		}
	}
	
	//To remove brackets
	line3DPt1Vector = storePoint3D(line3dx1, line3dy1, line3dz1);
	line3DPt2Vector = storePoint3D(line3dx2, line3dy2, line3dz2);
	
	//To store into Line3D
	for (int i=0; i<line3DPt1Vector.size(); i++){
		line3DVector.push_back(Line3D(line3DPt1Vector[i], line3DPt2Vector[i]));
	}
	return line3DVector;
}