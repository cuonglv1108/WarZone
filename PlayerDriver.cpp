#include "Player.h"

int main()
{
    vector<string*> t1;
    string dt1 = "France";
    string dt2 = "Germany";
    t1.push_back(&dt1);
    t1.push_back(&dt2);

    vector<string*> h1;
    string c1 = "airlift";
    string c2 = "diplomacy";
    h1.push_back(&c1);
    h1.push_back(&c2);

    vector<Order*> o1;

    Player* p1 = new Player(t1, h1, o1);
    (*p1).issueOrder("deploy");
    (*p1).issueOrder("advance");
    (*p1).printOrderList();
    (*p1).toAttack();
    (*p1).toDefend();


}

