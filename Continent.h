#ifndef CONTINENT.H
#define CONTINENT.H
#include <iostream>
#include <vector>
#include <list>

using namespace std;


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




#endif
