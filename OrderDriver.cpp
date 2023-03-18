#include "Orders.h"

using namespace std;

int main()
{
	cout << "test for OrderDriver...\n" << endl;
	OrderList OrderList;
	Deploy aDeploy;
	Advance anadvance;
	Bomb abomb;
	Blockade ablockade;
	Airlift anairlift;
	Negotiate anegotiate;

	//set order list for all
	OrderList.set_order_list(&aDeploy);
	OrderList.set_order_list(&anadvance);
	OrderList.set_order_list(&abomb);
	OrderList.set_order_list(&ablockade);
	OrderList.set_order_list(&anairlift);
	OrderList.set_order_list(&anegotiate);


	//print orderlist
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < OrderList.get_order_list()->size(); i++) {
		cout <<"  "<< OrderList.get_order_list()->at(i)->get_type() << endl;
	}

	//delete an order
	OrderList.delete_order(&aDeploy);

	//print orderlist
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < OrderList.get_order_list()->size(); i++) {
		cout << "  " << OrderList.get_order_list()->at(i)->get_type() << endl;
	}

	//move an order
	OrderList.move(0,4);

	//OrderList.move(0, 5);
	OrderList.move(0, 8);//invalid

	//print orderlist
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < OrderList.get_order_list()->size(); i++) {
		cout << "  " << OrderList.get_order_list()->at(i)->get_type() << endl;
	}

}
