//============================================================================
// Name        : Hand.h
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#ifndef HAND.H
#define HAND.H
#include <iostream>
#include <vector>
#include "Card.h"


using namespace std;

/**
    Class containing a finite collection of Warzone cards
*/
class Hand
{
	private:

		std::vector<Card> cards;
		int numCards;


	public:

		//Constructor
		Hand();

		//Method to show hand cards
		void display();

		//Adding a card to hand when player draws a card form deck
		void addCard(Card card);

};




#endif
