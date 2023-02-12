//============================================================================
// Name        : Deck.h
// Author      : Arsany Fahmy
// Version     :
// Copyright   : Your copyright notice
// Description : Comp 345 Ass 1
//============================================================================

#ifndef DECK.H
#define DECK.H
#include <iostream>
#include <vector>
#include "Card.h"


using namespace std;

/**
    Class containing the relevant information and methods for imported files
*/
class Deck
{
	private:

	    int totalNumCards;
		int numRemainingCards;
		std::vector<string> cardTypes;
		std::vector<Card> remainingCards;

		//Method which creates a deck of random card types
        void create();


	public:


		//Constructor
		Deck();
		Deck(int numCards);

		//Method that allows a player to draw a card at random from the cards remaining in the deck and place it in their hand of cards
		Card draw();



		//Method to show remaining cards
		void display();

		//Getters

		//Setters




};




#endif
