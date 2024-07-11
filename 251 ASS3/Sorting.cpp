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

#include "MyTemplates.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "Sorting.h"

using namespace std;

//Global Variables
extern vector<Point2D> uniquePoint2D;
extern vector<Point3D> uniquePoint3D;
extern vector<Line2D> uniqueLine2D;
extern vector<Line3D> uniqueLine3D;

//To sort Point2D to its sorting_criteria and sorting order
void sorting_point2D(string sorting_criteria, string sorting_order){
	//X-Ordinate & ASC
	if(sorting_criteria == "X-ordinate" && sorting_order == "ASC"){
		sort(uniquePoint2D.begin(), uniquePoint2D.end(), Point2D_SortByX_ASC());
	}
	//X-Ordinate & DSC
	else if (sorting_criteria == "X-ordinate" && sorting_order == "DSC"){
		sort(uniquePoint2D.begin(), uniquePoint2D.end(), Point2D_SortByX_DSC());
	}
	//Y-Ordinate & ASC
	else if(sorting_criteria == "Y-ordinate" && sorting_order == "ASC"){
		sort(uniquePoint2D.begin(), uniquePoint2D.end(), Point2D_SortByY_ASC());
	}
	//Y-Ordinate & DSC
	else if (sorting_criteria == "Y-ordinate" && sorting_order == "DSC"){
		sort(uniquePoint2D.begin(), uniquePoint2D.end(), Point2D_SortByY_DSC());
	}
	//DistFrOrigin & ASC
	else if(sorting_criteria == "Dist. Fr Origin" && sorting_order == "ASC"){
		sort(uniquePoint2D.begin(), uniquePoint2D.end(), Point2D_SortByDistFrOri_ASC());
	}
	//DistFrOrigin & DSC
	else if (sorting_criteria == "Dist. Fr Origin" && sorting_order == "DSC"){
		sort(uniquePoint2D.begin(), uniquePoint2D.end(), Point2D_SortByDistFrOri_DSC());
	}
}

//To sort Point3D to its sorting_criteria and sorting order
void sorting_point3D(string sorting_criteria, string sorting_order){
	//X-Ordinate & ASC
	if(sorting_criteria == "X-ordinate" && sorting_order == "ASC"){
		sort(uniquePoint3D.begin(), uniquePoint3D.end(), Point3D_SortByX_ASC());
	}
	//X-Ordinate & DSC
	else if (sorting_criteria == "X-ordinate" && sorting_order == "DSC"){
		sort(uniquePoint3D.begin(), uniquePoint3D.end(), Point3D_SortByX_DSC());
	}
	//Y-Ordinate & ASC
	else if(sorting_criteria == "Y-ordinate" && sorting_order == "ASC"){
		sort(uniquePoint3D.begin(), uniquePoint3D.end(), Point3D_SortByY_ASC());
	}
	//Y-Ordinate & DSC
	else if (sorting_criteria == "Y-ordinate" && sorting_order == "DSC"){
		sort(uniquePoint3D.begin(), uniquePoint3D.end(), Point3D_SortByY_DSC());
	}
	//Z-Ordinate & ASC
	else if(sorting_criteria == "Z-ordinate" && sorting_order == "ASC"){
		sort(uniquePoint3D.begin(), uniquePoint3D.end(), Point3D_SortByZ_ASC());
	}
	//Z-Ordinate & DSC
	else if (sorting_criteria == "Z-ordinate" && sorting_order == "DSC"){
		sort(uniquePoint3D.begin(), uniquePoint3D.end(), Point3D_SortByZ_DSC());
	}
	//DistFrOrigin & ASC
	else if(sorting_criteria == "Dist. Fr Origin" && sorting_order == "ASC"){
		sort(uniquePoint3D.begin(), uniquePoint3D.end(), Point3D_SortByDistFrOri_ASC());
	}
	//DistFrOrigin & DSC
	else if (sorting_criteria == "Dist. Fr Origin" && sorting_order == "DSC"){
		sort(uniquePoint3D.begin(), uniquePoint3D.end(), Point3D_SortByDistFrOri_DSC());
	}
}

//To sort Line2D to its sorting_criteria and sorting order
void sorting_Line2D(string sorting_criteria, string sorting_order){
	//Point 1 & ASC
	if(sorting_criteria == "Pt. 1" && sorting_order == "ASC"){
		sort(uniqueLine2D.begin(), uniqueLine2D.end(), SortByPt1_ASC());
	}
	//Point 1 & DSC
	else if(sorting_criteria == "Pt. 1" && sorting_order == "DSC"){
		sort(uniqueLine2D.begin(), uniqueLine2D.end(), SortByPt1_DSC());
	}
	//Point 2 & ASC
	else if(sorting_criteria == "Pt. 2" && sorting_order == "ASC"){
		sort(uniqueLine2D.begin(), uniqueLine2D.end(), SortByPt2_ASC());
	}
	//Point 2 & DSC
	else if(sorting_criteria == "Pt. 2" && sorting_order == "DSC"){
		sort(uniqueLine2D.begin(), uniqueLine2D.end(), SortByPt2_DSC());
	}
	//Length & ASC
	else if(sorting_criteria == "Length" && sorting_order == "ASC"){
		sort(uniqueLine2D.begin(), uniqueLine2D.end(), SortByLength_ASC());
	}
	//Length & DSC
	else if(sorting_criteria == "Length" && sorting_order == "DSC"){
		sort(uniqueLine2D.begin(), uniqueLine2D.end(), SortByLength_DSC());
	}
}

//To sort Line3D to its sorting_criteria and sorting order
void sorting_Line3D(string sorting_criteria, string sorting_order){
	//Point 1 & ASC
	if(sorting_criteria == "Pt. 1" && sorting_order == "ASC"){
		sort(uniqueLine3D.begin(), uniqueLine3D.end(), SortByPt1_ASC());
	}
	//Point 1 & DSC
	else if(sorting_criteria == "Pt. 1" && sorting_order == "DSC"){
		sort(uniqueLine3D.begin(), uniqueLine3D.end(), SortByPt1_DSC());
	}
	//Point 2 & ASC
	else if(sorting_criteria == "Pt. 2" && sorting_order == "ASC"){
		sort(uniqueLine3D.begin(), uniqueLine3D.end(), SortByPt2_ASC());
	}
	//Point 2 & DSC
	else if(sorting_criteria == "Pt. 2" && sorting_order == "DSC"){
		sort(uniqueLine3D.begin(), uniqueLine3D.end(), SortByPt2_DSC());
	}
	//Length & ASC
	else if(sorting_criteria == "Length" && sorting_order == "ASC"){
		sort(uniqueLine3D.begin(), uniqueLine3D.end(), SortByLength_ASC());
	}
	//Length & DSC
	else if(sorting_criteria == "Length" && sorting_order == "DSC"){
		sort(uniqueLine3D.begin(), uniqueLine3D.end(), SortByLength_DSC());
	}
}