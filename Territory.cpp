#include "Territory.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
