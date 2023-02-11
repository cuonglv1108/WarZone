#ifndef WARZONE_PLAYER_H
#define WARZONE_PLAYER_H

#include <iostream>
#include <vector>

// #include "Territory.h"
// #include "Hand.h"
 #include "Order.h"

using namespace std;

class Player
{
    public:
        Player();
        Player(vector<string*> t, vector<string*> h, vector<Order*> o);
        Player(const Player&); //copy constructor
        void toDefend();
        void toAttack();
        vector<Order*> getOrderList();
        void issueOrder(string);
        void printOrderList();


    private:
        vector<string*> territories;
        vector<string*> hand;
        vector<Order*> orderList;

};


#endif //WARZONE_PLAYER_H
