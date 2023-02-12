#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace GameEngine
{
	class GameEngine
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

		private:
			string* usercommand;		//will store the command that is input
			GameState* currentgamestate;	//stores the current state of the game

	};

}