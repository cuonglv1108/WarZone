
#include "LoggingObserver.h"
#include "Orders.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
	Order* myOrder = new Order();
	myOrder->execute();
	CommandProcessor *cp = new CommandProcessor();



	return 0;

}
