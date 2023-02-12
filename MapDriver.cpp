//============================================================================
// Name        : MapDriver.cpp
// Author      : Arsany Fahmy
// Version     :
// Copyright   :
// Description : Comp 345 Ass 1
//============================================================================


#include "Map.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


int main()
{
	// --------------------- Introduction ---------------------//
	cout << "Welcome to COMP 345 Assignment #1" << endl;

	//Storing name of file to pull data from:
	cout << "\nPlease enter the name of the file that you wish to load the map from:" << endl;
	string input_file_name;
	cin >> input_file_name;


	// --------------------- Loading Map  ---------------------//
	MapLoader loader(input_file_name);
	Map myMap = loader.loadMap();


	// --------------------- Displaying Map  ---------------------//
	myMap.printContinents();
	myMap.printAdjacentTerritoryGraph();
	myMap.printContinentGraph();



	return 0;

}
