#include "GameEngine.h"
#include <string>
using namespace std;


namespace GameEngine
{
	//default constructor
	GameEngine::GameEngine()
	{
		usercommand = NULL;
		currentgamestate = new GameState();
		*currentgamestate = GameState::Start; //initialize game to Start state
	}

	//copy constructor
	GameEngine::GameEngine(const GameEngine& other)
	{
		//initialize, then copy
		usercommand = NULL;
		*usercommand = *other.usercommand;

		//initialize, then copy
		currentgamestate = new GameState();
		*currentgamestate = *other.currentgamestate;
	}

	GameEngine& GameEngine::operator=(const GameEngine& other)
	{
		if (this == &other)
		{
			return *this;
		}

		//initialize, then copy
		usercommand = NULL;
		*usercommand = *other.usercommand;

		//initialize, then copy
		currentgamestate = new GameState();
		*currentgamestate = *other.currentgamestate;

		return *this;
	}
	
	ostream& operator <<(ostream& o, const GameEngine::GameState& g)
	{
		switch (g)
		{
		case GameEngine::GameState::Start:
			o << "Start";
			break;
		case GameEngine::GameState::MapLoaded:
			o << "MapLoaded";
			break;
		case GameEngine::GameState::MapValidated:
			o << "MapValidated";
			break;
		case GameEngine::GameState::PlayersAdded:
			o << "PlayersAdded";
			break;
		case GameEngine::GameState::AssignReinforcement:
			o << "AssignReinforcement";
			break;
		case GameEngine::GameState::IssueOrders:
			o << "IssueOrders";
			break;
		case GameEngine::GameState::ExecuteOrders:
			o << "ExecuteOrders";
			break;
		case GameEngine::GameState::Win:
			o << "Win";
			break;
		}
		return o;
	}

	//destructor
	GameEngine::~GameEngine()
	{
		delete usercommand;
		delete currentgamestate;
	}

	void GameEngine::setUserCommand(string a)
	{
		usercommand = new string(a);
	}

	GameEngine::GameState GameEngine::getGameState()
	{
		return *currentgamestate;
	}

	void GameEngine::checkCommand()
	{
		switch (*currentgamestate)
		{
			case GameState::Start:
				if (*usercommand == "loadmap")
				{
					*currentgamestate = GameState::MapLoaded;
				}
				else
				{
					cout << "Invaild command." << endl;
				}
				break;
			case GameState::MapLoaded:
				if (*usercommand == "loadmap")
				{
					*currentgamestate = GameState::MapLoaded;
				}
				else if (*usercommand == "validatemap")
				{
					*currentgamestate = GameState::MapValidated;
				}
				else
				{
					cout << "Invaild command." << endl;
				}
				break;
			case GameState::MapValidated:
				if (*usercommand == "addplayer")
				{
					*currentgamestate = GameState::PlayersAdded;
				}
				else
				{
					cout << "Invaild command." << endl;
				}
				break;
			case GameState::PlayersAdded:
				if (*usercommand == "addplayer")
				{
					*currentgamestate = GameState::PlayersAdded;
				}
				else if (*usercommand == "assigncountries")
				{
					*currentgamestate = GameState::AssignReinforcement;
				}
				else
				{
					cout << "Invaild command." << endl;
				}
				break;
			case GameState::AssignReinforcement:
				if (*usercommand == "issueorder")
				{
					*currentgamestate = GameState::IssueOrders;
				}
				else
				{
					cout << "Invaild command." << endl;
				}
				break;
			case GameState::IssueOrders:
				if (*usercommand == "issueorder")
				{
					*currentgamestate = GameState::IssueOrders;
				}
				else if (*usercommand == "endissueorders")
				{
					*currentgamestate = GameState::ExecuteOrders;
				}
				else
				{
					cout << "Invaild command." << endl;
				}
				break;
			case GameState::ExecuteOrders:
				if (*usercommand == "execorder")
				{
					*currentgamestate = GameState::ExecuteOrders;
				}
				else if (*usercommand == "endexecorders")
				{
					*currentgamestate = GameState::AssignReinforcement;
				}
				else if (*usercommand == "win")
				{
					*currentgamestate = GameState::Win;
				}
				else
				{
					cout << "Invaild command." << endl;
				}
				break;
			case GameState::Win:
				if (*usercommand == "play")
				{
					*currentgamestate = GameState::Start;
				}
				else if (*usercommand == "end")
				{
					exit(0);
				}
				else
				{
					cout << "Invaild command." << endl;
				}
				break;
		}
	}

	void GameEngine::cleanUserCommand()
	{
		delete usercommand;
		usercommand = NULL;
	}

}