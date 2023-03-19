#pragma once 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "LoggingObserver.h"
using namespace std;

// COMP 345S - ASSIGNMENT 1
// NAME: LE VIET CUONG, STUDENT ID: 40151142
// : Orders are created by the player during their turn and placed into the player’s list of orders. By default, each order is placed 
//	in the list sequentially

class Order: ILoggable, Subject
{
public :
	Order();
	~Order();
	//Order(const Order& O);//copy constructor
	
	//check of the oder is valid 
	void validate();
	//execute method 
	void execute();
	
	//set type of the subclass
	void set_type_id(int num);
	string get_type();

	void stringToLog(string s);

private :
	string stringsToLog;
	bool valid;
	vector<string> vec_type1 = { "deploy", "advance", "bomb", "blockade", "airlift", "negotiate" };
	int type_id;
};

class Deploy : public Order 
{

public:
	Deploy();
	~Deploy();
	string* get_type();

private:
	string type1 = { "deploy" };
};

class Advance : public Order {
public:
	Advance();
	~Advance();

private:
};

class Bomb : public Order 
{
public:
	Bomb();
	~Bomb();

private:
};

class Blockade : public Order
{
public:
	Blockade();
	~Blockade();
private:
};

class Airlift : public Order
{
public:
	Airlift();
	~Airlift();
private:
};

class Negotiate : public Order
{
public:
	Negotiate();
	~Negotiate();

private:
};

class OrderList: ILoggable, Subject
{
public:
	void set_order_list(Order* an_order);
	vector<Order*>* get_order_list();
	
	//delete an order
	void delete_order(Order* oneOrder);
	
	//move the orders
	void move(int position, int new_position);

	void stringToLog(string s);

private:
	string stringsToLog;
	vector<Order*> vec_order_list; //store the orders put in
};
