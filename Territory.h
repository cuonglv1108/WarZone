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
		int x_coordinate;
		int y_coordinate;

	public:

		//Constructor
		Territory();
		Territory(int id, string name, int cont_id, int x, int y);


		//Getters
		int getTerritory_id();
		string getTerritory_name();
		int getContinent_id();
		int getX_coordinate();
		int getY_coordinate();
		Territory getNeighbors();

		//Setters
		void setTerritory_id(int id);
		void setTerritory_name(string name);
		void setContinent_id(int id);
		void setX_coordinate(int x);
		void setY_coordinate(int y);


};




#endif
