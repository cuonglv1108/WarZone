//============================================================================
// Name        : Map.h
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#ifndef MAP.H
#define MAP.H
#include <iostream>
#include <vector>
#include <list>
#include "Territory.h"
#include "Continent.h"

using namespace std;


class Map
{
	private:

		string mapFileName;
		int numOfTerritories;
		int numOfContinents;
		std::vector<Territory> territories;
		std::vector<Continent> continents;
		std::vector<Territory> *adjacentTerritories;
		std::vector<Territory> *territoriesInContinents;


	public:


		//Constructor
		Map();
		Map(string fileName, int numTerritories, int numContinents);


		//Printing Methods
		void printContinents();
		void printTerritories();

		//Methods related to the graph representation of the map
		void initializeAdjacentTerritoriesGraph();
		void initializeTerritoriesInContinentsGraph();
		void addAdjacentTerritoryBorder(int source_territory_id, Territory destination_territory, int destination_position);
		void addTerritoryToContinent(int source_continent_id, Territory terr);
		void printAdjacentTerritoryGraph();
		void printContinentGraph();

		//Method to add a continent to the map
		void addContinent(Continent cont);

		//Method to add a territory to the map
		void addTerritory(Territory terr);

		//Method to perform three validations
		bool validate();




		//Getters
		string getFileName();
		int getNumOfTerritories();
		int getNumOfContinents();
		vector<Territory> getTerritories();
		vector<Continent> getContinents();

		//Setters
		void setFileName(string name);
		void setNumOfTerritories(int num);
		void setNumOfContinents(int num);
		void setTerritories(vector<Territory> terr);
		void setContinents(vector<Continent> cont);




};




#endif
