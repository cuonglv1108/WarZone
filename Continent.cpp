#include "Continent.h"
#include <iostream>
#include <vector>

using namespace std;


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
