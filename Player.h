#ifndef WARZONE_PLAYER_H
#define WARZONE_PLAYER_H

#include <iostream>
#include <vector>

#include "Map.h"
#include "Orders.h"
#include "Card.h"

using namespace std;

    class Player //header class for Player of warzone containing the declaration of methods to be implemented in the source code as well as data members
    {
    public:

        Player();
        Player(string n, int r,vector<Territory*> t, vector<Card*> h, vector<Order*> o);
        Player(string n);
        Player(const Player& other);
        ~Player();
        Player& operator=(const Player& other);

        vector<Territory *> toDefend();
        vector<Territory *> toAttack();
        void issueOrder();
        void printOrderList();
        void printHand();
        void printTerritories();
        void assignTerritory(Territory* t);
        void updateReinforcementPool(int r);
        vector<Card*> getHand();
        void addCardToHand(Card* card);
        string getName();
        int getArmies();
        int getNoTerritories();
        vector<Territory*> getTerritories();
        vector<Order*> getOrderList();


    private:
        string name;
        int reinforcementPool;
        vector<Territory*> territories;
        vector<Card*> hand;
        vector<Order*> orderList;

    };


#endif //WARZONE_PLAYER_H

