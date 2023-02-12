//============================================================================
// Name        : MapLoader.h
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#ifndef MAPLOADER.H
#define MAPLOADER.H
#include <iostream>
#include <vector>
#include <list>
#include "Map.h"

using namespace std;


/**
    Class responsible for loading the map component from input files (.map) having the proper format
*/
class MapLoader
{
	private:

		Map map;
		string mapFileName;


	public:


		//Constructor
		MapLoader();
		MapLoader(string fileName);


		//Method responsible for loading the map from text.file
		Map loadMap();


		//Getters
		string getFileName();


		//Setters
		void setFileName(string name);


};




#endif
