#include "GameEngine.h"
#include "Map.h"
#include "Player.h"
#include "CommandProcessing.h"
#include "Card.h"
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
using namespace std;


namespace GameEngine
{
	//default constructor
	GameEngine::GameEngine()
	{
		deck = new Deck(50);
		map = new Map();
		usercommand = NULL;
		currentgamestate = new GameState();
		*currentgamestate = GameState::Start; //initialize game to Start state
		//Sending command to log file
		Subject::Notify("Current Game State: Start");
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

		//initialize, then copy
		map = new Map();
		*map = *other.map;

		//initialize, then copy
		deck = new Deck();
		*deck = *other.deck;

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

		//initialize, then copy
		map = new Map();
		*map = *other.map;

		//initialize, then copy
		deck = new Deck();
		*deck = *other.deck;

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
		delete map;
		delete deck;
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
					//Sending command to log file
					Subject::Notify("Current Game State: MapLoaded");
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
					//Sending command to log file
					Subject::Notify("Current Game State: MapLoaded");
				}
				else if (*usercommand == "validatemap")
				{
					*currentgamestate = GameState::MapValidated;
					//Sending command to log file
					Subject::Notify("Current Game State: MapValidated");
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
					//Sending command to log file
					Subject::Notify("Current Game State: PlayersAdded");
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
					//Sending command to log file
					Subject::Notify("Current Game State: PlayersAdded");
				}
				else if (*usercommand == "assigncountries")
				{
					*currentgamestate = GameState::AssignReinforcement;
					//Sending command to log file
					Subject::Notify("Current Game State: ReinforcementAssigned");
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
					//Sending command to log file
					Subject::Notify("Current Game State: OrderIssued");
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
					//Sending command to log file
					Subject::Notify("Current Game State: OrderIssued");
				}
				else if (*usercommand == "endissueorders")
				{
					*currentgamestate = GameState::ExecuteOrders;
					//Sending command to log file
					Subject::Notify("Current Game State: OrderExecuted");
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
					//Sending command to log file
					Subject::Notify("Current Game State: OrderExecuted");
				}
				else if (*usercommand == "endexecorders")
				{
					*currentgamestate = GameState::AssignReinforcement;
					//Sending command to log file
					Subject::Notify("Current Game State: ReinforcementAssigned");
				}
				else if (*usercommand == "win")
				{
					*currentgamestate = GameState::Win;
					//Sending command to log file
					Subject::Notify("Current Game State: Win!");
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
					//Sending command to log file
					Subject::Notify("Current Game State: Start");
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

	void GameEngine::startupPhase()
	{
		// ---------------------------------------- LoadMap ---------------------------------------- //
		if(*usercommand == "loadmap")
		{
			//Retrieving all the available maps to load
			string path = "./";
			string* files = new string[5];
			int count = 0;
			for (const auto & entry : __fs::filesystem::directory_iterator(path))
			{
				string temp = entry.path();
				if (temp.substr(temp.size() - 3) == "map")
				{
					temp = entry.path();
					files[count] = temp.substr(2);
					count++;
				}
			}

			//Displaying all the available maps
			int count2 = 0;
			cout << "Please choose which map to load: (Type the name)" << endl;
			for(int i = 0; i < count; i++)
			{
				cout << count2+1 << ": " << files[count2] << endl;
				count2++;
			}

			//Storing name of file to pull data from:
			string input_file_name;
			cin >> input_file_name;


			//Loading Map
			MapLoader loader(input_file_name);
			Map temp = loader.loadMap();
			map->copy(temp);

		}

		// ---------------------------------------- validateMap ---------------------------------------- //
		if(*usercommand == "validatemap")
		{
			//Validating Map
			map->validate();
		}


		// ---------------------------------------- AddPlayer ---------------------------------------- //
		if(*usercommand == "addplayer")
		{
			//Adding players
			cout << "Please select how many players you would like to add (2-6): ";
			int numPlayers = -1;
			do
			{
				cin >> numPlayers;
				cout << numPlayers;

				if((numPlayers > 6) || (numPlayers < 2))
				{
					cout << "\nPlease try again, number of players must be between 2 and 6!" << endl;
					numPlayers = -1;
				}
			}
			while(numPlayers == -1);


			for (int i = 0; i < numPlayers; i ++)
			{
				cout << "\nPlease enter name of Player # " << (i+1) << ": ";
				string name;
				cin >> name;
				Player *temp2 = new Player(name);
				players.push_back(temp2);
			}
		}



		// ---------------------------------------- GameStart ---------------------------------------- //
		//Distributing territories to players
		if(*usercommand == "gamestart")
		{
			cout << map->getNumOfTerritories() << endl;
			//Iterate through all territories
			for (int i = 0; i < map->getNumOfTerritories(); i++)
			{
				//Iterate through all players
				for(int y = 0; y < players.size(); y++)
				{
					Territory *temp = new Territory();
					temp->copy(map->getTerritories()[i]);
					players[y]->assignTerritory(temp);
					i++;

				}
				i--;

			}


//			//To display territories of each player (testing)
//			for(int y = 0; y < players.size(); y++)
//			{
//				cout << "Player: " << players[y]->getName() << endl;
//				players[y]->printTerritories();
//			}


			//Giving 50 armies to the players
			for(int y = 0; y < players.size(); y++)
			{
				players[y]->updateReinforcementPool(50);
			}

			//Making players draw two cards from the deck
			for(int y = 0; y < players.size(); y++)
			{
				string cardType = deck->draw().getAssignedType();
				Card *temp5 = new Card(cardType);
				players[y]->addCardToHand(temp5);

				cardType = deck->draw().getAssignedType();
				temp5 = new Card(cardType);
				players[y]->addCardToHand(temp5);

			}

			//Switching the game to the play phase

//			//To test if everything is good!
//			for(int y = 0; y < players.size(); y++)
//			{
//				cout << "\nplayer: " << players[y]->getName() << endl;
//				players[y]->printHand();
//			}
//			deck->display();
		}



	}

    void GameEngine::reinforcementPhase()
    {

        // ---------------------------------------- AssignReinforcement ---------------------------------------- //

        if(*usercommand == "assigncountries")
        {
            vector<Continent> c = map->getContinents(); //retrieve continents list for user selected map
            for (int i = 0; i < c.size() ; i++)
            {
                int cid = c[i].getId();
                int count; //amount of territories for a continent
                vector<Territory> t = map->getTerritories(); //retrieve territories list for user selected map
                for (int j = 0; j < t.size(); j++)
                {
                    if (t[j].getContinent_id() == cid) // territory's continent matches given continent in iteration then increment its amount of territories
                    {
                        count++;
                    }
                }
                for (int y = 0; y < players.size(); y++) //iterate through players
                {
                    vector<Territory *> t = players[y]->getTerritories(); //list of player's owned territories
                    int pcount; //amount of territories owned by player for a continent
                    for (int i = 0; i < t.size(); i++)  //iterate through players owned territories
                    {
                        if (t[i]->getContinent_id() == cid)  //territory is in current continent then increment its count
                            pcount++;
                    }
                    if (pcount >= count) //player controls all of continent's territories then add bonus value to formula computing how many armies to add to their pool
                    {
                        int a = floor((players[y]->getNoTerritories()) / 3);
                        players[y]->updateReinforcementPool((players[y]->getArmies()) + a + 6);
                    }
                    else
                    { //otherwise, proceed with regular formula: no of territories owned divided by 3, rounded down
                        int a = floor((players[y]->getNoTerritories()) / 3);
                        players[y]->updateReinforcementPool((players[y]->getArmies()) + a);
                    }
                }
            }
        }
    }

    void GameEngine::issueOrdersPhase()
    {
        // ---------------------------------------- IssueOrders ---------------------------------------- //
        if(*usercommand == "issueorder")
        {
            //iterate through players and have them issue orders to add to their orderlist
            for (int y = 0; y < players.size(); y++) {
                players[y]->issueOrder();
            }
        }
    }

    void GameEngine::executeOrdersPhase()
    {
        // ---------------------------------------- ExecuteOrders ---------------------------------------- //
        if(*usercommand == "execorder")
        {
            //iterate through players and retrieve that player's orderlist and execute its orders
            for (int y = 0; y < players.size(); y++) {
                vector<Order *> ol = players[y]->getOrderList();
                for (int i = 0; i < ol.size(); ++i) {
                    Order o = *ol[i];
                    o.execute();
                }
            }
        }
    }

    //game play loop once the game has started
    void GameEngine::mainGameloop()
    {
        int total = map->getNumOfTerritories();
        //iterate through players
        for(int y = 0; y < players.size(); y++)
        {
            int t = players[y]->getNoTerritories();
            if (t <= 0) //if player has no territories owned then they are eliminated from the game
            {
                players[y]->~Player();
            }
            if (t >= total) //if player owns all territories then the game is won and over
            {
                cout << "Game Over. " << players[y]->getName() << " has won." << endl;
                return;
            }
        }
        //otherwise there is no reason to break from game and loop will follow the three main phases
        reinforcementPhase();
        issueOrdersPhase();
        executeOrdersPhase();
    }

	void GameEngine::stringToLog(string s)
	{
		stringsToLog = s;
	}

}
