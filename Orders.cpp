#include "Orders.h"

Order::Order()
{
	//Order(const Order& O);//copy constructor
	//Order& operator = (const Order &O);//assignment construtor
}

Order::~Order()
{
}

//validate the orders
void Order::validate()
{
	cout << "validate if the order is valid" << endl;
	valid = true;
}

//excute the orders
void Order::execute()
{
	if (valid) {
		cout << "executes the action..." << endl;
	}

	//Sending command to log file
	Subject::Notify("Command: Execute Order");
}

//set type id
void Order::set_type_id(int num)
{
	type_id = num;
}

//get type
string Order::get_type()
{
	return vec_type1.at(type_id);
}

void Order::stringToLog(string s)
{
	stringsToLog = s;
}


// push an order into Orderlist
void OrderList::set_order_list(Order* an_order)
{
	vec_order_list.push_back(an_order); //add an order

	//Sending command to log file
	Subject::Notify("Command: Add Order(" + an_order->get_type() + ")");
}

vector<Order*>* OrderList::get_order_list()
{
	return &vec_order_list;
}

// delete order method
void OrderList::delete_order(Order* oneOrder)
{
	for (int i = 0; i < vec_order_list.size(); i++) {
		if (oneOrder->get_type() == vec_order_list.at(i)->get_type()) {
			cout << "  deleting the order: " << oneOrder->get_type() << endl;
			vec_order_list.erase(vec_order_list.begin() + i);
			
			return;
		}
	}
}

//move order method
void OrderList::move(int position, int new_position)
{
	if (position >= 0 && position < vec_order_list.size() && new_position >= 0 && new_position < vec_order_list.size())
	{
		vec_order_list.insert(vec_order_list.begin() + new_position, vec_order_list.at(position));
		vec_order_list.erase(vec_order_list.begin() + position);
	}
	else if (new_position == vec_order_list.size()  )
	{
		vec_order_list.push_back(vec_order_list.at(position));
		vec_order_list.erase(vec_order_list.begin() + position);
	}
	else {
		cout << "\n not valid position, try again" << endl;
	}
}

void OrderList::stringToLog(string s)
{
	stringsToLog = s;
}

Deploy::Deploy()
{
	cout << "deploy is creating..." << endl;
	set_type_id(0);
}

Deploy::~Deploy()
{
}

string* Deploy::get_type()
{
	return &type1;
}

//setting  different kinds of orders
Advance::Advance()
{
	cout << "advance is creating..." << endl;
	set_type_id(1);
}

Advance::~Advance()
{
}

Bomb::Bomb()
{
	cout << "bomb is creating..." << endl;
	set_type_id(2);
}

Bomb::~Bomb()
{
}

Blockade::Blockade()
{
	cout << "blockade is creating..." << endl;
	set_type_id(3);
}

Blockade::~Blockade()
{
}

Airlift::Airlift()
{
	cout << "airlift is creating..." << endl;
	set_type_id(4);
}

Airlift::~Airlift()
{
}

Negotiate::Negotiate()
{
	cout << "negotiate is creating..." << endl;
	set_type_id(5);
}

Negotiate::~Negotiate()
{
}
