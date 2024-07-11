/*
    Student Name         : Jian Ira Olvido Farne
    UOWID                : 7433645
    Tutorial Class       : T01
    Asssignment          : 02
*/

/*
    To compile (In Windows): 
        g++ -std=c++17 ShapeTwoD.cpp Square.cpp Rectangle.cpp Cross.cpp Circle.cpp OtherFunctions.cpp 7433645_A2.cpp -o csci251_a2_windows.exe

    To Run:
    ./csci251_a2_windows.exe


    To compile (In Ubuntu): 
        g++ -std=c++17 ShapeTwoD.cpp Square.cpp Rectangle.cpp Cross.cpp Circle.cpp OtherFunctions.cpp 7433645_A2.cpp -o csci251_a2_ubuntu.exe
    
    To Run:
    ./csci251_a2_ubuntu.exe

*/

#include "ShapeTwoD.h"
#include "Circle.h"
#include "Cross.h"
#include "Rectangle.h"
#include "Square.h"
#include "OtherFunctions.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main(){
    int user_choice;
    displayMainMenu();
    do{
        cout << "Please enter your choice: ";
		cin >> user_choice;
        switch(user_choice){
            case 1: //Input data
                inputSensorData();
                break;
            
            case 2: //To compute area for All records
                computeAreaForAllRecords(); 		
                break;

            case 3: //To print out the Shapes report
                printShapesReport();
                break;

            case 4: //To sort out inputted data of shapes
                sortShapesData();
                break;

            case 5: //Quit
                safelyDeallocateMemory();
                cout << "Thank you for using this program" << endl;
                cout << "Exiting ..." << endl;
                exit(0);
                break;
            
            default: //Resets any error flags and clears buffer then becomes ready to take in the new one
				cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
            	cout << "Invalid input. Please try again!" << endl;
        }
        displayMainMenu();
    }
    while(user_choice > 0 || user_choice < 6);

    return 0;
}