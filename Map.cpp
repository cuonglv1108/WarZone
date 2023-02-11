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

void Map::initializeAdjacentTerritoriesGraph()
{
	adjacentTerritories = new vector<Territory> [numOfTerritories+1];
}
void Map::initializeTerritoriesInContinentsGraph()
{
	territoriesInContinents = new vector<Territory> [numOfContinents+1];
}

void Map::addAdjacentTerritoryBorder(int source_territory_id, Territory destination_territory)
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


//void Map::traverse(int u, bool visited[])
//{
//   visited[u] = true; //mark v as visited
//   for(int v = 1; v < territoriesInContinents[u].size(); v++){
//         if(!visited[v])
//        	 traverse(v, visited);
//
//   }
//}
//
//bool Map::isConnected(){
//   bool *vis = new bool[numOfTerritories];
//   //for all vertex u as start point, check whether all nodes are visible or not
//   for(int u; u < numOfTerritories; u++){
//      for(int i = 0; i < numOfTerritories; i++)
//      vis[i] = false; //initialize as no node is visited
//      traverse(u, vis);
//      for(int i = 0; i < numOfTerritories; i++){
//         if(!vis[i]) //if there is a node, not visited by traversal, graph is not connected
//         return false;
//      }
//   }
//   return true;
//}
//
//
//bool Map::validate()
//{
//
//	return isConnected();
//
//
//
//}



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


