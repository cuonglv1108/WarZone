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
	x_coordinate = -1;
	y_coordinate = -1;
}

Territory::Territory(int id, string name, int cont_id,  int x, int y)
{
	territory_id = id;
	territory_name = name;
	continent_id = cont_id;
	x_coordinate = x;
	y_coordinate = y;
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
int Territory::getX_coordinate()
{
	return x_coordinate;
}
int Territory::getY_coordinate()
{
	return y_coordinate;
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
void Territory::setX_coordinate(int x)
{
	x_coordinate = x;
}
void Territory::setY_coordinate(int y)
{
	x_coordinate = y;
}
