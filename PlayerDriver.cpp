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
    vector<Card*> h1;
    Card *c1 = new Card("Airlift");
    Card *c2 = new Card("Diplomacy");
    h1.push_back(c1);
    h1.push_back(c2);

    //Creation of orderList to add arbitrary orders
    vector<Order*> o1;

    Player* p1 = new Player("player", 5, t1, h1, o1); //Creation of new Player using aforementioned parameters
    (*p1).issueOrder();
    (*p1).issueOrder();

    cout << "Current order list: " << endl;
    (*p1).printOrderList(); //displaying current orderList
    cout << endl;

    cout << "List of territories to defend: " << endl;
    (*p1).toDefend(); //displaying arbitrary list of territories to defend
    cout << endl;

    cout << "List of territories to attack: " << endl;
    (*p1).toAttack(); //displaying arbitrary list of territories to attack
    cout << endl;

    cout << "Current hand of cards: " << endl;
    (*p1).printHand(); //displaying current hand of cards
    cout << endl;
}

