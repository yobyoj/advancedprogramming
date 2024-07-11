/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef PROCESS_STORE_POINTS
#define PROCESS_STORE_POINTS

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <limits>

#include "Point2D.h"
#include "Point3D.h"
#include "Utility.h"

using namespace std;
//To process Point2D
vector<Point2D> processPoint2D(vector<string> file_data);

//To store Point3D
vector<Point2D> storePoint2D(vector <string> point2d_x, vector <string> point2d_y);

//To process Point3D
vector<Point3D> processPoint3D(vector<string> file_data);

//To store Point3D
vector<Point3D> storePoint3D(vector <string> point3d_x, vector <string> point3d_y, vector <string> point3d_z);

#endif