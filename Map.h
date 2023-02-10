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
		list<int> *mapGraph;


	public:


		//Constructor
		Map();
		Map(string fileName, int numTerritories, int numContinents);


		//Printing Methods
		void printContinents();
		void printTerritories();

		//Methods related to the graph representation of the map
		void initializeMap();
		void addAdjacentTerritoryBorder(int source_territory, int destination_territory);
		void printAdjacentTerritoryBorders();

		//Method to add a territory to the map
		void addContinent(Continent cont);

		//Method to add a territory to the map
		void addTerritory(Territory terr);





		//Getters
		string getFileName();
		int getNumOfTerritories();
		int getNumOfContinents();
		vector<Territory> getTerritories();

		//Setters
		void setFileName(string name);
		void setNumOfTerritories(int num);
		void setNumOfContinents(int num);
		void setTerritories(vector<Territory> terr);




};




#endif
