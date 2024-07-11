 /*
	Student Name         : Jian Ira Olvido Farne
	UOWID                : 7433645
	Assignment           : 01
    File                 : Complete Code Version (31/7/2023)
*/

/*
	To compile (In Windows): 
		g++ 7433645_A1.cpp -std=c++11 -o 7433645_a1.exe
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

//Global Variables
int user_choice;
bool inputfile;
int x_mininum, x_maximum;
int y_mininum, y_maximum;
int xrange, yrange;
vector<string> uniqueCityID;

//Function Prototypes
vector<string> splitString (string input, string delimiter);
void displayMainMenu();
void promptToEnterOnly();
void readConfigFile(); 
void init2DArray (int col, int row);
void initCityArray (int noOfCity);
void insertCityID(string cityid);
void open_citylocation_file(string citylocation_file);
void open_cloudcover_file(string cloud_cover_file);
void open_pressure_file(string pressure_file);
void display_city_cloud_index_symbol_pressure_index_symbol(int user_choice);
char lmh_symbol(int value);
int rainchance(char acc, char ap);
void display_graphics(int probability);
void displaySummary();
void deallocateMemory(int col, int row);

//Struct for each location of the 2D map
struct map{
	string cityid;
	string cityname;
	int cloud;
	int cloud_index;
	char cloud_LMH_symbol;
	int pressure;
	int pressure_index;
	string pressure_LMH_symbol;
};
struct map **array2D = nullptr; //To Intialize struct map to be null pointer

//Struct which contains relevant infomation of a city 
struct citysummary{
	string cityid;
	string cityname;
	vector<int> x_cordinate;
	vector<int> y_cordinate;
	double avecloud;
	double avepressure; 
};
struct citysummary *citylocpointer = nullptr; //To intialize struct citysummary to be null pointer

int main(){
	inputfile = false;
	displayMainMenu();
	do{
		cout << "Please enter your choice: ";
		cin >> user_choice;
		switch (user_choice){
			case 1: 
				//Read and process a configuration file
            	readConfigFile();
				break;

			case 2:
				//Display city map
				cout << "Display city map" << endl;
				display_city_cloud_index_symbol_pressure_index_symbol(user_choice);
				promptToEnterOnly();		
				break;

			case 3:
				//Display cloud coverage map (cloudiness index)
				cout << "Display cloud coverage map (cloudiness index)" << endl;
				display_city_cloud_index_symbol_pressure_index_symbol(user_choice);
				promptToEnterOnly();
				break;

			case 4:
				//Display cloud coverage map (LMH symbols)
				cout << "Display cloud coverage map (LMH symbols)" << endl;
				display_city_cloud_index_symbol_pressure_index_symbol(user_choice);
				promptToEnterOnly();
				break;

			case 5:
				//Display atmospheric pressure map (pressure index)
				cout << "Display atmospheric pressure map (pressure index)" << endl;
				display_city_cloud_index_symbol_pressure_index_symbol(user_choice);
				promptToEnterOnly();
				break;

			case 6:
				//Display atmospheric pressure map (LMH symbols)
				cout << "Display atmospheric pressure map (LMH symbols)" << endl;
				display_city_cloud_index_symbol_pressure_index_symbol(user_choice);
				promptToEnterOnly();
				break;

			case 7:
				//Display weather forecast summary report
				displaySummary();
				promptToEnterOnly();
				break;

			case 8:
				//Quit
				deallocateMemory(x_maximum, y_maximum);
				cout << "----- Thank you for using the Weather Information Processing System -----" << endl;
				cout << "Exiting ..." << endl;
				exit(0);
				break;

			default:
				cin.clear();  //resets any error flags which may have been set
            	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This will clear buffer before taking new
            	cout << "Invalid input. Please try again!" << endl;
		}
		displayMainMenu();
	}
	while(user_choice > 0 || user_choice < 9);
	return 0;
}

/*
    splitString Method which takes in two strings input and delimiter.
    Loops the string input to find delimiter and splits. Then, stores into a vector string result
    Returns a vector string result
*/
vector<string> splitString (string input, string delimiter){
	size_t pos = 0;
	string token;
	vector<string> result;

	while ((pos = input.find(delimiter)) != string::npos){
    	token = input.substr(0, pos);
    	result.push_back (token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back(input);
	return result;
}

//To display the Main Menu
void displayMainMenu(){
	cout << setw(15) << left << "\nStudent ID"  << right << " : 7433645" << endl;
    cout << setw(14) << left << "Student Name" << right << " : Jian Ira Olvido Farne" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Welcome to Weather Information Processing System!" << endl;
    cout << "1)" << setw(5) << " " << "Read in and process a configuration file" << endl;
    cout << "2)" << setw(5) << " " << "Display city map" << endl;
    cout << "3)" << setw(5) << " " << "Display cloud coverage map (cloudiness index)" << endl;
    cout << "4)" << setw(5) << " " << "Display cloud coverage map (LMH symbols)" << endl;
    cout << "5)" << setw(5) << " " << "Display atmospheric pressure map (pressure index)" << endl;
    cout << "6)" << setw(5) << " " << "Display atmospheric pressure map (LMH symbols)" << endl;
    cout << "7)" << setw(5) << " " << "Show weather forecast summary report" << endl;
    cout << "8)" << setw(5) << " " << "Quit" << endl << endl;   
}

//To always prompt user to "Press <Enter> to go back to main menu ... ""
void promptToEnterOnly(){
    char enter_key = ' ';
    do { 
        cout << endl;
        cout << "Press <Enter> to go back to main menu ... ";
        cin.clear(); //resets any error flags which may have been set
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This will clear buffer before taking new
        enter_key = cin.get();
    } while (enter_key != '\n');
}

//To read the config.txt
void readConfigFile(){
    //Local Variables
    string config_file;
    string content;
    vector<string> city_cloud_pressure; //Vector to store filenames from config file
    ifstream readFile(config_file);

    cout << endl;
    cout << "[ Read in and process a configuration file ]" << endl;
    cout << "Please enter config filename : ";
	//when prompted, to tyype in 'config.txt'
    cin >> config_file;
    cout << endl;    

	//this will open the the config file and read the content of file in C-string format
    readFile.open(config_file.c_str());
	//To check if the file can be open to read 
    if (readFile.good()){
        while (getline(readFile, content)){
            //ignore comments and empty lines
            if (content[0] != '/' && content[1] != '/' && !content.empty()){
                //cout << content << endl; // To display output for debugging 
                //To find X Mininum and Maximum
                if (content.find("GridX_IdxRange") != string::npos){
                    vector<string> tokenStringVector = splitString (content, "="); //This will split the string of GridX_IdxRange=0-8 into GridX_IdxRange and 0-8
                    vector<string> tokenStringVector2 = splitString (tokenStringVector[1], "-"); //This will splits 0-8 into 0 and 8
                    //To store the values for x_mininum, x_maximum, xrange
					x_mininum = stoi(tokenStringVector2[0]);
                    x_maximum = stoi(tokenStringVector2[1]);
                    xrange = x_maximum - x_mininum + 1;

                    cout << "Reading in GridX_IdxRange : "<< x_mininum << "-" << x_maximum << " ... done!" << endl;

					//To removes all the elements from a vector container, thus making its size 0
                    tokenStringVector.clear();
                    tokenStringVector2.clear();
                }
               	//To find Y Mininum and Maximum
                else if (content.find("GridY_IdxRange") != string::npos){
                    vector<string> tokenStringVector = splitString (content, "="); //This will split the string of GridY_IdxRange=0-8 into GridY_IdxRange and 0-8
                    vector<string> tokenStringVector2 = splitString (tokenStringVector[1], "-"); //This will splits 0-8 into 0 and 8
                    //To store the values for y_mininum, y_maximum, yrange
					y_mininum = stoi(tokenStringVector2[0]);
                    y_maximum = stoi(tokenStringVector2[1]);
                    yrange = y_maximum - y_mininum + 1;

                    cout << "Reading in GridX_IdxRange : "<< y_mininum << "-" << y_maximum << " ... done!" << endl;

					//To removes all the elements from a vector container, thus making its size 0
                    tokenStringVector.clear();
                    tokenStringVector2.clear();
                }
                //To find other txt file
                else if(content.find(".txt") != string::npos){
                    city_cloud_pressure.push_back(content); 
                }
            }
        }
		readFile.close();
        cout << endl;
        cout << "Storing data from input file :" << endl;
        cout << city_cloud_pressure[0] << " ... done!" << endl;
        cout << city_cloud_pressure[1] << " ... done!" << endl;
        cout << city_cloud_pressure[2] << " ... done!" << endl;
        cout << endl;
        cout << "All records successfully stored. Going back to main menu ..." << endl;

        //To initalise the 2D Multi-Dimensional Array
        init2DArray (yrange, xrange);
        //To open all citylocation, cloudcover, pressure file
        open_citylocation_file(city_cloud_pressure[0]);
        open_cloudcover_file(city_cloud_pressure[1]);
		open_pressure_file(city_cloud_pressure[2]);

		inputfile = true; //To set to true once only after user enter filename
    }
    else{
        cout << "Error opening file" << endl;
    }   
    city_cloud_pressure.clear(); 
}

//To initiate 2d array
void init2DArray (int col, int row){
	array2D = new struct map * [row];
	for (int i = 0; i < row; i++){
        array2D[i] = new struct map [col];
    }
}

//To initiate array for each city range
void initCityArray (int noOfCity){
	citylocpointer = new struct citysummary [noOfCity];
	for (int i = 0; i < uniqueCityID.size(); i++){
		struct citysummary citysum = citylocpointer[i];
		citysum.cityid = uniqueCityID[i];
		for(int i = y_mininum; i <= y_maximum; i++){
			for(int j = x_mininum; j <= x_maximum; j++){
				struct map temp = array2D[j-x_mininum][i-y_mininum];
				if(citysum.cityid == temp.cityid){
					citysum.cityname = temp.cityname;
					citysum.x_cordinate.push_back(j);
					citysum.y_cordinate.push_back(i);
				}
			}
		}
		//Sort the data
		sort(citysum.x_cordinate.begin(), citysum.x_cordinate.end());
		sort(citysum.y_cordinate.begin(), citysum.y_cordinate.end());
		citylocpointer[i] = citysum;
	}
}

//To puts unique city id into a vector
void insertCityID(string cityid){
	if (find(uniqueCityID.begin(), uniqueCityID.end(), cityid) == uniqueCityID.end()){
        uniqueCityID.push_back(cityid);
    }	
}

//Opens and process citylocation.txt
void open_citylocation_file(string citylocation_file){
    //Local Variables
	int x, y;
	ifstream read_citylocation_file;
	read_citylocation_file.open(citylocation_file.c_str());
	//To check if the file is good and can be open to read 
	if (read_citylocation_file.good()){
		string content;
		while (getline(read_citylocation_file, content)){
			if (content.empty()){
                break;
            }
			//This will erase/elimate the [
			content.erase(0,1);
			//cout << content << endl; // To display output for debugging
			vector<string> tokenStringVector = splitString (content, ", ");
			x = stoi(tokenStringVector[0])-x_mininum;

			tokenStringVector = splitString (tokenStringVector[1], "]-");
			y = stoi(tokenStringVector[0])-y_mininum;

			struct map temp = array2D[x][y];

			tokenStringVector = splitString (tokenStringVector[1], "-");
			temp.cityid = tokenStringVector[0];
			temp.cityname = tokenStringVector[1];

			insertCityID(temp.cityid);

			array2D[x][y] = temp;
			tokenStringVector.clear();
		}
		initCityArray(uniqueCityID.size());
	}
    else{
        cout << "Error opening file" << endl;
    } 
	read_citylocation_file.close();
}

//Opens and process cloudcover.txt
void open_cloudcover_file(string cloud_cover_file){
    //Local Variables
	int x, y;
	ifstream read_cloudcover_file;
	read_cloudcover_file.open(cloud_cover_file.c_str());
	//To check if the file is good and can be open to read 
	if (read_cloudcover_file.good()){
		string content;
		while (getline(read_cloudcover_file, content)){
			if (content.empty()){
                break;
            }
			//This will erase/elimate the [
			content.erase(0,1);
			//cout << content << endl; // To display output for debugging
			vector<string> tokenStringVector = splitString (content, ", ");
			x = stoi(tokenStringVector[0])-x_mininum;

			tokenStringVector = splitString (tokenStringVector[1], "]-");
			y = stoi(tokenStringVector[0])-y_mininum;

			struct map temp = array2D[x][y];

			temp.cloud = stoi(tokenStringVector[1]);
			temp.cloud_index = (stoi(tokenStringVector[1])) / 10; //By dividing by 10, will get the cloud index value
			temp.cloud_LMH_symbol = lmh_symbol(stoi(tokenStringVector[1]));

			array2D[x][y] = temp;
			tokenStringVector.clear();
		}
	}
    else{
        cout << "Error opening file" << endl;
    }
	read_cloudcover_file.close();
}

//Opens and process pressure.txt 
void open_pressure_file(string pressure_file){
    //Local Variables
	int x, y;
	ifstream read_presuure_file;
	read_presuure_file.open(pressure_file.c_str());
	//To check if the file is good and can be open to read 
	if (read_presuure_file.good()){
		string content;
		while (getline(read_presuure_file, content)){
			if (content.empty()){
                break;
            }
			//This will erase/elimate the [
			content.erase(0,1);
			//cout << content << endl; // To display output for debugging
			vector<string> tokenStringVector = splitString (content, ", ");
			x = stoi(tokenStringVector[0])-x_mininum;

			tokenStringVector = splitString (tokenStringVector[1], "]-");
			y = stoi(tokenStringVector[0])-y_mininum;

			struct map temp = array2D[x][y];

			temp.pressure = stoi(tokenStringVector[1]);
			temp.pressure_index = (stoi(tokenStringVector[1])) / 10; //By dividing by 10, will get the pressure index value
			temp.pressure_LMH_symbol = lmh_symbol(stoi(tokenStringVector[1]));

			array2D[x][y] = temp;
			tokenStringVector.clear();
		}
	}
    else{
        cout << "Unable to open file" << endl;
    }
	read_presuure_file.close();
}

//Method to display city, cloudiness (index, LMH)pressure (index, LMH) accordingly on user choice input
void display_city_cloud_index_symbol_pressure_index_symbol(int user_choice){
	if (inputfile == false){
		cout << "You have not input any file!" << endl;
	}
	else{
		cout << "  ";
		//This will print out the "  #" top of the array map
		for(int i = 0; i < (xrange + 2); i++){
			cout << "  #";
		}
		cout << endl;
		//This will print out the "  #" left and right of the array map
		for(int i = y_maximum; i >= y_mininum; i--){
			if(i > 9){
				cout << i << "  #";
			}
			else{
				cout << i << "   #";
			}
			//Now it time to output the according to what user choice input has entered
			for(int j = x_mininum; j <= x_maximum; j++){
				struct map temp = array2D[j-x_mininum][i-y_mininum];
				//If user choice input 2, it will display the cityID accordingly
				if (user_choice == 2){
					if(temp.cityid != ""){
						cout << "  " << temp.cityid;
					}
					else{
						cout << "   ";
					}
				}
				//If user choice input 3, it will display the cloud_index accordingly
				else if(user_choice == 3){
					cout << "  " << temp.cloud_index;
				}
				//If user choice input 4, it will display the cloud_LMH_symbol accordingly
				else if (user_choice == 4){
					cout << "  " << temp.cloud_LMH_symbol;
				}
				//If user choice input 3, it will display the pressure_index accordingly
				else if (user_choice == 5){
					cout << "  " << temp.pressure_index;
				}
				//If user choice input 3, it will display the pressure_LMH_symbol accordingly
				else if (user_choice == 6){
					cout << "  " << temp.pressure_LMH_symbol;
				}
			}
			cout << "  #" << endl;
		}
		
		//This will print out the "  #" bottom of the array map
		cout << "  ";
		for(int i = 0; i < (xrange + 2); i++){
			cout << "  #";
		}
		cout << endl << "     ";
		for(int j = x_mininum; j <= x_maximum; j++){
			if (j > 9){
				cout << " " << j;
			}
			else{
				cout << "  " << j;
			}	
		}
		cout << endl;
	}
}

//Method which return LMH symbol based on the value
char lmh_symbol(int value){
    char symbol;
	if (value >= 0 && value < 35){
		symbol = 'L';
	}
	else if (value >= 35 && value < 65){
		symbol = 'M';
	}
	else if (value >= 65 && value < 100){
		symbol = 'H';
	}
    return symbol;
}

//Method to estimate the probability of rain based on Ave Cloud Cover (ACC) and  Ave Pressure Value (AP) 
int rainchance(char acc, char ap){
	int probability;

	if (ap == 'L' && acc == 'H'){
		probability = 90;
	}
	else if (ap == 'L' && acc == 'M'){
		probability = 80;
	}
	else if (ap == 'L' && acc == 'L'){
		probability = 70;
	}
	else if (ap == 'M' && acc == 'H'){
		probability = 60;
	}
	else if (ap == 'M' && acc == 'M'){
		probability = 50;
	}
	else if (ap == 'M' && acc == 'L'){
		probability = 40;
	}
	else if (ap == 'H' && acc == 'H'){
		probability = 30;
	}
    else if (ap == 'H' && acc == 'M'){
		probability = 20;
	}
    else if (ap == 'H' && acc == 'L'){
		probability = 10;
	}
	else{
		probability = 0;
	}
	return probability;
}

//Method to display ASCII graphics based on probability
void display_graphics(int probability){
	if (probability == 90){
		cout << "~~~~" << endl;
		cout << "~~~~~" << endl;
		cout << "\\\\\\\\\\" << endl << endl;
	}
	else if (probability == 80){
		cout << "~~~~" << endl;
		cout << "~~~~~" << endl;
		cout << " \\\\\\\\" << endl << endl;
	}
	else if (probability == 70){
		cout << "~~~~" << endl;
		cout << "~~~~~" << endl;
		cout << "  \\\\\\" << endl << endl;
	}
	else if (probability == 60){
		cout << "~~~~" << endl;
		cout << "~~~~~" << endl;
		cout << "   \\\\" << endl << endl;
	}
	else if (probability == 50){
		cout << "~~~~" << endl;
		cout << "~~~~~" << endl;
		cout << "    \\" << endl << endl;
	}
	else if (probability == 40){
		cout << "~~~~" << endl;
		cout << "~~~~~" << endl << endl;
	}
	else if (probability == 30){
		cout << "~~~" << endl;
		cout << "~~~~" << endl << endl;
	}
	else if (probability == 20){
		cout << "~~" << endl;
		cout << "~~~" << endl << endl;
	}
	else if (probability == 10){
		cout << "~" << endl;
		cout << "~~" << endl << endl;
	}
}

//Method to display summary of weather forecast report
void displaySummary(){
	if (inputfile == false){
		cout << "You have not input any file!" << endl;
	}
	else{
		cout << "\nWeather Forecast Summary Report" << endl;
		cout << "-------------------------------" << endl;
		for (int i = 0; i < uniqueCityID.size(); i++){
			struct citysummary citysum = citylocpointer[i];
			int starting_value_of_x, last_value_of_x;
			int starting_value_of_y, last_value_of_y;
			int cloudtotal = 0;
			int pressuretotal = 0;
			int counter = 0;
			//To initalise the starting value of X. 
			if (citysum.x_cordinate.front() == x_mininum){
				starting_value_of_x = x_mininum;
			}
			else{
				starting_value_of_x = citysum.x_cordinate.front() - 1;
			}
			//To initalise the last value of X. 
			if (citysum.x_cordinate.back() == x_maximum){
				last_value_of_x = x_maximum;
			}
			else{
				last_value_of_x = citysum.x_cordinate.back() + 1;
			}
			//To initalise the starting value of Y
			if (citysum.y_cordinate.front() == y_mininum){
				starting_value_of_y = y_mininum;
			}
			else{
				starting_value_of_y = citysum.y_cordinate.front() - 1;
			}
			//To initalise the last value of X. 
			if (citysum.y_cordinate.back() == y_maximum){
				last_value_of_y = y_maximum;
			}
			else{
				last_value_of_y = citysum.y_cordinate.back() + 1; 
			}

			for (int i = starting_value_of_y; i <= last_value_of_y; i++){
				for (int j = starting_value_of_x; j <= last_value_of_x; j++){
					struct map temp = array2D[j-x_mininum][i-y_mininum];
					cloudtotal += temp.cloud;
					pressuretotal += temp.pressure;
					counter++;
				}
			}
			citysum.avecloud = cloudtotal / double(counter);
			citysum.avepressure = pressuretotal / double(counter);
			double rainprobability = rainchance(lmh_symbol(citysum.avecloud), lmh_symbol(citysum.avepressure));
			cout << setw(10) << left << "City Name" << right << " : " <<  citysum.cityname << endl;
			cout << setw(10) << left << "City ID" << right << " : "  << citysum.cityid << endl;
			cout << setw(20) << left << "Ave. Cloud Cover" << left << "(ACC)" << " : "  << fixed << setprecision(2) << citysum.avecloud << " (" << lmh_symbol(citysum.avecloud) << ")" << endl;
			cout << setw(20) << left << "Ave. Pressure" << left << "(AP)" << " " << right << " : " << citysum.avepressure << " (" << lmh_symbol(citysum.avepressure) << ")" << endl;
			cout << setw(20) << left << "Probability of Rain" << left << "(%)" << "  " << right << " : " << fixed << setprecision(2) << rainprobability << endl;
			display_graphics(rainprobability);
			citylocpointer[i] = citysum;
		}
	}
}

//Method to deallocate memmory before exit
void deallocateMemory(int col, int row){
	if (col <= 0){
        return;
    }
	for (int i = 0; i < row; i++){
        delete [] array2D [i];
    }
	delete [] array2D;
	delete [] citylocpointer;
	uniqueCityID.clear(); //This will clear every element inside the vector
	uniqueCityID.shrink_to_fit(); //This will reduce its capacity to its original size which zero
}


