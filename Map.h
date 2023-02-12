//============================================================================
// Name        : Map.h
// Author      : Arsany Fahmy
// Version     :
// Copyright   :
// Description : Comp 345 Ass 1
//============================================================================

#ifndef MAP.H
#define MAP.H
#include <iostream>
#include <vector>
#include <list>

using namespace std;



// ----------------------------------------- Continent Class -----------------------------------------//

/**
    Class containing the different Continent information
*/
class Continent
{
	private:

		string name;
		int id;
		string color;


	public:


		//Constructor
		Continent();
		Continent(string ContName, int cont_id, string col);


		//Getters
		string getName();
		int getId();
		string getColor();

		//Setters
		void setName(string n);
		void setId(int i );
		void setColor(string c);




};








// ----------------------------------------- Territory Class -----------------------------------------//

/**
    Class containing the different Territory information
*/
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







// ----------------------------------------- Map Class -----------------------------------------//

/**
    Class containing the relevant information and methods for imported files
*/
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







// ----------------------------------------- MapLoader Class -----------------------------------------//

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
