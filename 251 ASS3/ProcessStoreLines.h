/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef PROCESS_STORE_LINES
#define PROCESS_STORE_LINES

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <limits>

#include "ProcessStorePoints.h"
#include "Line2D.h"
#include "Line3D.h"
#include "Utility.h"

using namespace std;
//To process Line2D
vector<Line2D> processLine2D(vector<string> file_data);

//To process Line3D
vector<Line3D> processLine3D(vector<string> file_data);
#endif