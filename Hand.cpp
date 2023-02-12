//============================================================================
// Name        : Hand.cpp
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#include <iostream>
#include <vector>
#include "Hand.h"


using namespace std;

Hand::Hand(): cards()
{
	numCards = 0;
}


void Hand::display()
{

	cout << "\nCards in Hand: " << endl;
	//Iterate over all cards
	for(int i = 0; i < numCards; i++)
	{
		cout << "Card #" << (i+1) << " ->";

		cout << cards[i].getAssignedType() << ",";

		cout << endl;
	}

}

void Hand::addCard(Card card)
{
	numCards++;
	cards.push_back(card);
}
