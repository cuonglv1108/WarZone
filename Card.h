//============================================================================
// Name        : Card.h
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#ifndef CARD.H
#define CARD.H
#include <iostream>
#include <vector>


using namespace std;

/**
    Class containing the relevant information and methods for imported files
*/
class Card
{
	private:

		string assignedType;


	public:


		//Constructor
		Card(string type);

		//copy constructor
		void copy(Card &c);

		//Method that enables a player to use it during game play by creating special orders. Once a card has been played, it is removed from the hand and put back into the deck.
		void play();

		//Getters
		string getAssignedType();



};




#endif
