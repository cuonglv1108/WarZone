#include "Player.h"

using namespace std;

    Player::Player() //default constructor
    {
        vector<string*> territories;
        vector<Card*> hand;
        vector<Order*> orderList;
    }

    Player::Player(vector<string*> t, vector<Card*> h, vector<Order*> o) //constructor with parameters
    {
        this->territories = t;
        this->hand = h;
        this->orderList = o;
    }

    Player::Player(const Player& other) //copy constructor
    {
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

    void Player::toDefend() //returns list of territories to be defended
    {
        for (int i = 0; i < territories.size(); i++)
        {
            cout << *territories[i] << "" << endl;
        }
    }

    void Player::toAttack() //returns arbitrary list of territories to be attacked
    {
        vector<string*> tAttack;
        string ta1 = "Belgium";
        string ta2 = "Norway";
        tAttack.push_back(&ta1);
        tAttack.push_back(&ta2);

        for (int i = 0; i < tAttack.size(); i++)
        {
            cout << *tAttack[i] << "" << endl;
        }
    }

    void Player::issueOrder() //adds new order to the orderList
    {
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
            cout << hand[i] << "" << endl;
        }
    }