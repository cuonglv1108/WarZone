#include "Player.h"
#include "Map.h"

using namespace std;

    Player::Player() //default constructor
    {
    	name = "No Name!";
    	reinforcementPool = -1;
        vector<Territory*> territories;
        vector<Card*> hand;
        vector<Order*> orderList;
    }

    Player::Player(string n) //constructor with parameters
	{
    	reinforcementPool = -1;
		this->name = n;
	}

    Player::Player(string n, int r, vector<Territory*> t, vector<Card*> h, vector<Order*> o) //constructor with parameters
    {
    	this->reinforcementPool = r;
    	this->name = n;
        this->territories = t;
        this->hand = h;
        this->orderList = o;
    }

    Player::Player(const Player& other) //copy constructor
    {
    	this->reinforcementPool = other.reinforcementPool;
    	this->name = other.name;
        this->territories = other.territories;
        this->hand = other.hand;
        this->orderList = other.orderList;
    }

    Player& Player::operator=(const Player &other) //assignment operator
    {
        if (this == &other)
        {
            return *this;
        }

        this->name = other.name;
        this->reinforcementPool = other.reinforcementPool;
        this->territories = other.territories;
        this->hand = other.hand;
        this->orderList = other.orderList;

        return *this;
    }

    Player::~Player() //destructor
    {
        territories.clear();
        hand.clear();
        orderList.clear();
    }

    vector<Territory *> Player::toDefend() //returns list of territories to be defended
    {
        for (int i = 0; i < territories.size(); i++)
        {
            cout << territories[i]->getTerritory_name() << endl;
        }
        return territories;
    }

    vector<Territory *> Player::toAttack() //returns arbitrary list of territories to be attacked
    {
        vector<Territory*> tAttack;
        Territory *dt1 = new Territory(3, "Belgium", 1, 0);
        Territory *dt2 = new Territory(4, "Norway", 1, 0);
        tAttack.push_back(dt1);
        tAttack.push_back(dt2);


        for (int i = 0; i < tAttack.size(); i++)
        {
            cout << tAttack[i] << "" << endl;
        }
        return tAttack;
    }

    void Player::issueOrder() //adds new order to the orderList
    {
        vector<Territory*> td = toDefend();
        vector<Territory*> ta = toAttack();
        Order *o = new Order();
        orderList.push_back(o);
    }

    void Player::printOrderList() //for later display of orderList
    {
        for (int i = 0; i < orderList.size(); i++)
        {
            cout << orderList[i] << "" << endl;
        }
    }

    void Player::printHand() //for later display of hand of cards
    {
        for (int i = 0; i < hand.size(); i++)
        {
            cout << hand[i]->getAssignedType() << "" << endl;
        }
    }

    void Player::printTerritories() //for later display of owned territories
        {
            for (int i = 0; i < territories.size(); i++)
            {
                cout << "Territory #" << (i+1) << ": " <<territories[i]->getTerritory_name() << endl;
            }
        }

    void Player::assignTerritory(Territory* t)
    {
    	territories.push_back(t);
    }

    void Player::updateReinforcementPool(int r)
    {
    	reinforcementPool = r;
    }

    vector<Card*> Player::getHand()
    {
    	return hand;
    }

    void Player::addCardToHand(Card* card)
    {
    	hand.push_back(card);
    }

    string Player::getName()
	{
		return name;
	}

    int Player::getArmies()
    {
        return reinforcementPool;
    }

    int Player::getNoTerritories() {

        int length;
        for (Territory *element: territories)
        {
            length++;
        }
        return length;
    }

    vector<Territory*> Player::getTerritories()
    {

        return territories;
    }

    vector<Order*> Player::getOrderList()
    {
        return orderList;
    }

