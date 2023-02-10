#include "Map.h"
#include <iostream>
#include <vector>

using namespace std;

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

void Map::initializeMap()
{
	mapGraph = new list<int>[numOfTerritories+1];
}

void Map::addAdjacentTerritoryBorder(int source_territory, int destination_territory)
{
	mapGraph[source_territory].push_back(destination_territory);
}

void Map::printAdjacentTerritoryBorders()
{
	cout << "\nGraph: " << endl;
	//Iterate over all vertices
	for(int i = 1; i < numOfTerritories+1; i++)
	{
		cout << "Node " << i << "->";
		for(int neighbor: mapGraph[i])
		{
			cout << neighbor << ",";
		}
		cout << endl;
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


