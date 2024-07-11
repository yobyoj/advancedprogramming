/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

#include "ShapeTwoD.h"
#include "Circle.h"
#include "Cross.h"
#include "Rectangle.h"
#include "Square.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

//Function Prototypes
//Displays the Main Menu
void displayMainMenu();

//Inputs the data
void inputSensorData();

//Computes area
void computeAreaForAllRecords();

//Prints shape reports
void printShapesReport();

//Sorts Ascending
bool sortAscending(ShapeTwoD *a, ShapeTwoD *b);

//Sorts Descending
bool sortDescending(ShapeTwoD *a, ShapeTwoD *b);

//Sorts by Type
bool sortByTypeThenDesc(ShapeTwoD *a, ShapeTwoD *b);

//Prints output after Sorting
void sortShapesData();

//Deallocates Memory
void safelyDeallocateMemory();

#endif