#ifndef WARZONE_PLAYER_H
#define WARZONE_PLAYER_H

#include <iostream>
#include <vector>

//#include "Territory.h"
#include "Card.h"
#include "Orders.h"

using namespace std;

    class Player //header class for Player of warzone containing the declaration of methods to be implemented in the source code as well as data members
    {
    public:

        Player();
        Player(vector<string*> t, vector<Card*> h, vector<Order*> o);
        Player(const Player& other);
        ~Player();
        Player& operator=(const Player& other);

        void toDefend();
        void toAttack();
        void issueOrder(string);
        void printOrderList();


    private:
        vector<string*> territories;
        vector<Card*> hand;
        vector<Order*> orderList;

    };


#endif //WARZONE_PLAYER_H

