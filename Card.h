//============================================================================
// Name        : Card.h
// Author      : Arsany Fahmy
// Version     :
// Copyright   :
// Description : Comp 345 Ass 1
//============================================================================

#ifndef CARD.H
#define CARD.H
#include <iostream>
#include <vector>


using namespace std;



// ----------------------------------------- Card Class -----------------------------------------//

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

		//copy
		void copy(Card &c);

		//Method that enables a player to use it during game play by creating special orders. Once a card has been played, it is removed from the hand and put back into the deck.
		void play();

		//Getters
		string getAssignedType();



};






// ----------------------------------------- Deck Class -----------------------------------------//

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

		//copy
		void copy(Deck &d);

		//Method that allows a player to draw a card at random from the cards remaining in the deck and place it in their hand of cards
		Card draw();

		//Method to show remaining cards
		void display();


};





// ----------------------------------------- Hand Class -----------------------------------------//

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

		//copy
		void copy(Hand &h);

		//Method to show hand cards
		void display();

		//Adding a card to hand when player draws a card form deck
		void addCard(Card card);

};



#endif
