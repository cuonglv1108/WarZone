//============================================================================
// Name        : CardsDriver.cpp
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#include <iostream>
#include <vector>
#include "Deck.h"
#include "Hand.h"
#include <fstream>
#include <sstream>
using namespace std;


int main()
{
	// --------------------- Introduction ---------------------//
	cout << "Welcome to COMP 345 Assignment #1" << endl;


	// --------------------- Creating a deck ---------------------//
	Deck myDeck(10);

	//Displaying cards in deck
	myDeck.display();


	// --------------------- Creating a hand ---------------------//
	Hand myHand;

	//Drawing a card from deck
	myHand.addCard(myDeck.draw());

	//Displaying cards in hand
	myHand.display();


	return 0;

}
