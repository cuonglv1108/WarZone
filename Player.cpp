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

    ostream& operator <<(ostream& o, const Player::Player& p) //stream insertion operator
    {
        switch (p)
        {
            case Player::Player::toDefend:
                p << "toDefend";
                break;
            case Player::Player::toAttack:
                p << "toAttack";
                break;
            case Player::Player::issueOrder:
                p << "issueOrder";
                break;
            case Player::Player::printOrderList:
                p << "printOrderList";
                break;
        }
        return p;
    }

    Player::~Player() //destructor
    {
        delete territories;
        delete hand;
        delete orderList;
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

