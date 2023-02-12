//============================================================================
// Name        : Card.cpp
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#include <iostream>
#include <vector>
#include "Card.h"


using namespace std;

Card::Card(string type)
{
	assignedType = type;
}


void Card::copy(Card &c)
{
	assignedType = c.assignedType;
}

string Card::getAssignedType()
{
	return assignedType;
}

void play()
{
	//To be implemented
}
