/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

#ifndef SHAPE_TWOD_H
#define SHAPE_TWOD_H

#include <string>

using namespace std;

class ShapeTwoD{
	protected:
		string name;
		bool containsWarpSpace;

	public:
		ShapeTwoD();
        ShapeTwoD(string name, bool containsWarpSpace);
        ~ShapeTwoD(); //Deconstructor
		
		string getName();
		void setName(string name);

		bool getContainsWarpSpace();
		void setContainsWarpSpace(bool containsWarpSpace);	

		virtual double computeArea();
		virtual double getArea();
		virtual void setArea() = 0;

		virtual void setData(int[], int[]){}; //For Square, Rectangle, Cross Shape
		virtual void setData2(int x, int y, int radius){}; //For circle shape
		virtual bool isPointInShape(int x, int y);
		virtual bool isPointOnShape(int x, int y);
		
		virtual string toString();
};
#endif