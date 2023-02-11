//============================================================================
// Name        : Territory.h
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#ifndef TERRITORY.H
#define TERRITORY.H
#include <iostream>
#include <list>
#include <vector>

using namespace std;


class Territory
{
	private:

		int territory_id;
		string territory_name;
		int continent_id;
		int numOfArmies;

	public:

		//Constructor
		Territory();
		Territory(int id, string name, int cont_id, int arm);


		//Getters
		int getTerritory_id();
		string getTerritory_name();
		int getContinent_id();
		int getNumOfArmies();
		Territory getNeighbors();

		//Setters
		void setTerritory_id(int id);
		void setTerritory_name(string name);
		void setContinent_id(int id);
		void setNumOfArmies(int arm);



};




#endif
