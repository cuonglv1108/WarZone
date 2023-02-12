#include "Player.h"

using namespace std;

    Player::Player() //default constructor
    {
        vector<string*> territories;
        vector<string*> hand;
        vector<Order*> orderList;
    }

    Player::Player(vector<string*> t, vector<string*> h, vector<Order*> o) //constructor with parameters
    {
        this->territories = t;
        this->hand = h;
        this->orderList = o;
    }

    Player::Player(const Player &p) //copy constructor
    {
        this->territories = p.territories;
        this->hand = p.hand;
        this->orderList = p.orderList;
    }

    void Player::toDefend() //returns list of territories to be defended
    {
        for (int i = 0; i < territories.size(); i++)
        {
            cout << *territories[i] << "";
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
            cout << *tAttack[i] << "";
        }
    }

    void Player::issueOrder(string order) //adds new order to the orderList
    {
        Order *o = new Order(order);
        orderList.push_back(o);
    }

    void Player::printOrderList() //for later display of orderList
    {
        vector<Order*>::iterator i = orderList.begin();
        for (i != orderList.end(); i++)
        {
            cout << (*i)->getResult() << " ";
        }
    }

