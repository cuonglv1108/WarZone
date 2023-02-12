//============================================================================
// Name        : Map.cpp
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



// ----------------------------------------- Continent Class -----------------------------------------//

Continent::Continent()
{
	name = "NoName";
	id = -1;
	color = "NoColor";
}
Continent::Continent(string ContName, int cont_id, string col)
{
	name = ContName;
	id = cont_id;
	color = col;
}


//Getters
string Continent::getName()
{
	return name;
}
int Continent::getId()
{
	return id;
}
string Continent::getColor()
{
	return color;
}

//Setters
void Continent::setName(string n)
{
	name = n;
}
void Continent::setId(int i )
{
	id = i;
}
void Continent::setColor(string c)
{
	color = c;
}








// ----------------------------------------- Territory Class -----------------------------------------//


Territory::Territory()
{
	territory_id = -1;
	territory_name = "null";
	continent_id = -1;
	numOfArmies = -1;
}

Territory::Territory(int id, string name, int cont_id,  int arm)
{
	territory_id = id;
	territory_name = name;
	continent_id = cont_id;
	numOfArmies = arm;
}

//Getters
int Territory::getTerritory_id()
{
	return territory_id;
}

string Territory::getTerritory_name()
{
	return territory_name;
}
int Territory::getContinent_id()
{
	return continent_id;
}
int Territory::getNumOfArmies()
{
	return numOfArmies;
}


//Setters
void Territory::setTerritory_id(int id)
{
	territory_id = id;
}

void Territory::setTerritory_name(string name)
{
	territory_name = name;
}
void Territory::setContinent_id(int id)
{
	continent_id = id;
}
void Territory::setNumOfArmies(int arm)
{
	numOfArmies = arm;
}





// ----------------------------------------- Map Class -----------------------------------------//
Map::Map(): territories(), continents()
{
	mapFileName = "null";
	numOfTerritories = -1;
	numOfContinents = -1;
}

Map::Map(string fileName, int numTerritories, int numContinents): territories(), continents()
{
	mapFileName = fileName;
	numOfTerritories = numTerritories;
	numOfContinents = numContinents;
}

void Map::addContinent(Continent cont)
{
	numOfContinents++;
	continents.push_back(cont);
}

void Map::addTerritory(Territory terr)
{
	numOfTerritories++;
	territories.push_back(terr);
}

void Map::printContinents()
{
	std::vector<Continent>::iterator it;
	cout << "\nStored Continents: [" << numOfContinents << "]" << endl;
	int count = 1;
	for (it = continents.begin(); it != continents.end(); ++it)
	{
		cout << "Continent #" << (count) << ":" << endl;
		cout << "Name: " << it->getName() << endl;
		cout << "ID: " << it->getId() << endl;
		cout << "Color: " << it->getColor() << endl;
		cout << "\n";
		count++;
	}
}

void Map::printTerritories()
{
	std::vector<Territory>::iterator it;
	cout << "\nStored Territories: [" << numOfTerritories << "]" << endl;
	int count = 1;
	for (it = territories.begin(); it != territories.end(); ++it)
	{
		cout << "Territory #" << (count) << ":" << endl;
		cout << "ID: " << it->getTerritory_id() << endl;
		cout << "Name: " << it->getTerritory_name() << endl;
		cout << "Continent_id: " << it->getContinent_id() << endl;
		cout << "\n";
		count++;
	}
}

void Map::initializeAdjacentTerritoriesGraph()
{
	adjacentTerritories = new vector<Territory> [numOfTerritories+1];
}
void Map::initializeTerritoriesInContinentsGraph()
{
	territoriesInContinents = new vector<Territory> [numOfContinents+1];
}

void Map::addAdjacentTerritoryBorder(int source_territory_id, Territory destination_territory, int destination_position)
{
	adjacentTerritories[source_territory_id].push_back(destination_territory);
}

void Map::addTerritoryToContinent(int source_continent_id, Territory terr)
{
	territoriesInContinents[source_continent_id].push_back(terr);
}

void Map::printAdjacentTerritoryGraph()
{
	cout << "\nGraph of adjacent territories: " << endl;
	//Iterate over all vertices
	for(int i = 1; i < numOfTerritories+1; i++)
	{
		cout << "Territory_id " << i << "->";
		for(Territory neighbor: adjacentTerritories[i])
		{
			cout << neighbor.getTerritory_name() << ",";
		}
		cout << endl;
	}

}

void Map::printContinentGraph()
{
	cout << "\nGraph of continents: " << endl;
	//Iterate over all vertices
	for(int i = 1; i < numOfContinents+1; i++)
	{
		cout << "Continent_id " << i << "->";
		for(Territory terr: territoriesInContinents[i])
		{
			cout << terr.getTerritory_name() << ",";
		}
		cout << endl;
	}
}




bool Map::validate()
{

	// Validating if 1) the map is a connected graph
	if(1)
	{
		cout << "\nGraph is not connected!" << endl;
		return 0;
	}

	// Validating if 2) continents are connected subgraphs
	if(1)
	{
		cout << "\Continents are not connected!" << endl;
		return 0;
	}

	// Validating if 3) each country belongs to one and only one continent.
	if(1)
	{
		cout << "\Each country doensn't belong to one and only one continent!" << endl;
		return 0;
	}
}



//Getters
string Map::getFileName()
{
	return mapFileName;
}
int Map::getNumOfTerritories()
{
	return numOfTerritories;
}
int Map::getNumOfContinents()
{
	return numOfContinents;
}
vector<Territory> Map::getTerritories()
{
	return territories;
}
vector<Continent> Map::getContinents()
{
	return continents;
}

//Setters
void Map::setFileName(string name)
{
	mapFileName = name;
}
void Map::setNumOfTerritories(int num)
{
	numOfTerritories = num;
}
void Map::setNumOfContinents(int num)
{
	numOfContinents = num;
}
void Map::setTerritories(vector<Territory> terr)
{
	territories = terr;
}
void Map::setContinents(vector<Continent> cont)
{
	continents = cont;
}








// ----------------------------------------- MapLoader Class -----------------------------------------//

MapLoader::MapLoader(): map()
{
	mapFileName = "null";
}

MapLoader::MapLoader(string fileName): map()
{
	mapFileName = fileName;
}


Map MapLoader::loadMap()
{

	// --------------------- Checking if file exists ---------------------//
	ifstream myFile;
	myFile.open(mapFileName);
	if (myFile.good() == 0)
	{
		//Returning Failure
		cout << "\nMap failed to load! Please make sure that file exists" << endl;
		return map;
	}

	//temp variable to store the context of each line in file:
	string temp;

	//temp variable to count how many countries and continents;
	int count = 0;

	//If input file is open and valid:
	if (myFile.is_open())
	{
		//endloop variable to end the while loop when all the countries have been stored
		bool endLoop = false;

		//While text file still lines and the countries data have not yet been reached
		while(getline(myFile, temp) && endLoop == false)
		{


			// --------------------- Storing territories  ---------------------//

			//When [continents] headline is met --> *** store continents ***
			if (temp.find("[continents]") != std::string::npos)
			{
				//resetting count
				count = 0;

				//Storing data of continents
				while(getline(myFile, temp) && endLoop == false)
				{
					//skip one more line if there is a note (line starting with ';')
					if(temp.substr(0, 1) == ";")
						getline(myFile, temp);

					//Stop the loop when no more continents (empty line)
					if(temp.size() == 1)
					{
						endLoop = true;
					}
					else
					{
						//counting how many continents
						count++;

						//Storing the 3 words separated by white spaces from temp into a tokens vector
						//Continents format:
						//EX:   Scandinavia       5           #fff780
						//        [name]   [continent_id]    [color]
						string buf;
						stringstream ss(temp);
						vector<string> tokens;

						//while there is more tokens
						while (ss >> buf)
						{
							tokens.push_back(buf);
						}

						//Storing the different tokens (continents info) inside the Map class
						Continent continent;
						continent.setName(tokens[0]);
						continent.setId(stoi(tokens[1]));
						continent.setColor(tokens[2]);

						map.addContinent(continent);
					}
				}

				//Storing number of continents
				map.setNumOfContinents(count);

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}




			// --------------------- Storing Continents  ---------------------//

			//When [countries] headline is met --> *** store countries ***
			if (temp.find("[countries]") != std::string::npos)
			{
				//resetting count
				count = 0;

				//Initializing the continents graph
				map.initializeTerritoriesInContinentsGraph();

				//Storing data of countries
				while(getline(myFile, temp) && endLoop == false)
				{
					//skip one more line if there is a note (line starting with ';')
					if(temp.substr(0, 1) == ";")
						getline(myFile, temp);

					//Stop the loop when no more countries (empty line)
					if(temp.size() == 1)
					{
						endLoop = true;
					}
					else
					{
						//counting how many continents
						count++;

						//Storing the 5 words separated by white spaces from temp into a tokens vector
						//Countries format:
						//EX:   1   Reykjavik       1          27        30
						//    [id]   [name]   [continent_id] [x_coor] [y_coor]
						string buf;
						stringstream ss(temp);
						vector<string> tokens;

						//while there is more tokens
						while (ss >> buf)
						{
							tokens.push_back(buf);
						}

						//Storing the different tokens (countries info) inside the Map class
						Territory territory;
						territory.setTerritory_id(stoi(tokens[0]));
						territory.setTerritory_name(tokens[1]);
						territory.setContinent_id(stoi(tokens[2]));

						map.addTerritory(territory);

						//storing the continent of territory
						int cont_id = stoi(tokens[2]);
						map.addTerritoryToContinent(cont_id, territory);
					}
				}
				//Storing number of territories
				map.setNumOfTerritories(count);

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}




			// --------------------- Storing Borders  ---------------------//

			//When [borders] headline is met --> *** store borders info ***
			if (temp.find("[borders]") != std::string::npos)
			{
				//resetting count
				count = 0;

				//Initializing the adjacent territories graph
				map.initializeAdjacentTerritoriesGraph();

				//Storing data of borders
				while(getline(myFile, temp) && endLoop == false)
				{
					//resetting count
					count = 0;

					//skip one more line if there is a note (line starting with ';')
					if(temp.substr(0, 1) == ";")
						getline(myFile, temp);

					//Stop the loop when no more borders (empty line)
					if(temp.size() == 1)
					{
						endLoop = true;
					}
					else
					{
						//Storing the shared borders from each line
						//Borders format:
						//EX:   10                     8   9   11
						//     [country_id]   [...other countries_id that have border]
						string buf;
						stringstream ss(temp);
						vector<string> tokens;

						//while there is more tokens
						while (ss >> buf)
						{
							tokens.push_back(buf);
						}

						//Finding the right matching territory that we are adding a border to
						int territory_id = stoi(tokens[0]);

						//Storing the different tokens (Borders info) inside the Map class
						for(int y = 1; y < tokens.size(); y++)
						{
							int destination_territory = stoi(tokens[y]) - 1;
							map.addAdjacentTerritoryBorder(territory_id, map.getTerritories()[destination_territory], y);
						}
					}
				}

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}
		}
	}

	//Returning success
	cout << "\nMap successfully loaded!" << endl;
	return map;
}


//Getters
string MapLoader::getFileName()
{
	return mapFileName;
}



//Setters
void MapLoader::setFileName(string name)
{
	mapFileName = name;
}

