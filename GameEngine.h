#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Map.h"
#include "Player.h"
#include "LoggingObserver.h"
using namespace std;

namespace GameEngine
{
	class GameEngine: ILoggable, Subject
	{
		public:
			//Define enum type that lists each possible game state, for readability
			enum class GameState { Start, MapLoaded, MapValidated, PlayersAdded, AssignReinforcement, IssueOrders, ExecuteOrders, Win };


			//constructor
			GameEngine();

			//copy constructor
			GameEngine(const GameEngine& other);

			//destructor
			~GameEngine();

			//assignment operator
			GameEngine& operator=(const GameEngine& other);

			//stream insertion operator
			friend ostream& operator <<(ostream& o, const GameState& g);

			//function that will be used to set what the user provided as input
			void setUserCommand(string a);

			//function that returns the current game state
			GameState getGameState();

			//function that will perform control flow logic to transition between states
			void checkCommand();

			//garbage cleaning function that deallocates the memory used to store the user input
			void cleanUserCommand();

			//overloaded to_string function so we can print the game state
			string to_string(GameState g);

			//Method that implements a command-based user interaction mechanism to start the game
			//by allowing the user to proceed with the game startup phase
			void startupPhase();

		private:
			string* usercommand;		//will store the command that is input
			GameState* currentgamestate;	//stores the current state of the game
			Map* map; //Stores the map of the game
			vector<Player*> players; //Stores the players participating in the game
			Deck* deck;

	};

}
