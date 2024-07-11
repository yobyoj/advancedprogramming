/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 03
*/

#ifndef SORTING_H
#define SORTING_H

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

using namespace std;
//To sort Point2D
void sorting_point2D(string sorting_criteria, string sorting_order);

//To sort Point3D
void sorting_point3D(string sorting_criteria, string sorting_order);

//To sort Line2D
void sorting_Line2D(string sorting_criteria, string sorting_order);

//To sort Line3D
void sorting_Line3D(string sorting_criteria, string sorting_order);
#endif