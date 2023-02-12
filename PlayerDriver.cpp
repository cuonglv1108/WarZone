#include "Player.h"

int main() //main method of driver to display functionality of Player being implemented
{
    //Arbitrary list of territories being added (to display toDefend method functionality)
    vector<string*> t1;
    string dt1 = "France";
    string dt2 = "Germany";
    t1.push_back(&dt1);
    t1.push_back(&dt2);

    //Arbitrary list of cards being added to the hand
    vector<string*> h1;
    string c1 = "airlift";
    string c2 = "diplomacy";
    h1.push_back(&c1);
    h1.push_back(&c2);

    //Creation of orderList to add arbitrary orders
    vector<Order*> o1;

    Player* p1 = new Player(t1, h1, o1); //Creation of new Player using aforementioned parameters
    (*p1).issueOrder("deploy");
    (*p1).issueOrder("advance");
    (*p1).printOrderList(); //displaying current orderList
    (*p1).toAttack(); //displaying arbitrary list of territories to attack
    (*p1).toDefend(); //displaying arbitrary list of territories to attack


}

