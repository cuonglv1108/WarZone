#include "Player.h"

using namespace std;

    Player::Player()
    {
        vector<string*> territories;
        vector<string*> hand;
        vector<string*> orderList;
    }

    Player::Player(vector<string*> t, vector<string*> h, vector<string*> o)
    {
        this->territories = t;
        this->hand = h;
        this->orderList = o;
    }

    Player::Player(const Player& p)
    {
        this->territories = p.territories;
        this->hand = p.hand;
        this->orderList = p.orderList;
    }

    void Player::toDefend()
    {
        for (int i = 0; i < territories.size(); i++)
        {
            cout << *territories[i] << "";
        }
    }

    void Player::toAttack()
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

    vector<Order*> Player::getOrderList()
    {

        return orderList;
    }

    void Player::issueOrder(string order)
    {
        Order *o = new Order(order);

        orderList.push_back(o);
    }

    void Player::printOrderList()
    {
        vector<Order*>::iterator it = orderList.begin();
        for (; it != orderList.end(); it++)
        {
            cout << (*it)->getResult() << " ";
        }
        cout << endl;
    }

