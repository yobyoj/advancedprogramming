/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef UTILITY_H
#define UTILITY_H

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

using namespace std;

void promptToEnterOnly();
vector<string> splitString (string input, string delimiter);
vector <string> uniqueFileData(string filename_input);
void displayPoint2D();
void displayPoint3D();
void displayLine2D();
void displayLine3D();

#endif