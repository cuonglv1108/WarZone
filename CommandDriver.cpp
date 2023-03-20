
#include "LoggingObserver.h"
#include "GameEngine.h"
#include "CommandProcessing.h"
#include "Orders.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using namespace CommandProcessing;


int main()
{
	//Testing Order Logging
	Order* myOrder = new Order();
	myOrder->set_type_id(0);
	myOrder->execute();
	myOrder->set_type_id(1);
	myOrder->execute();
	myOrder->set_type_id(2);
	myOrder->execute();
	myOrder->set_type_id(3);
	myOrder->execute();

//	//Testing OrderList
	OrderList* myOrderList = new OrderList();
	myOrderList->set_order_list(myOrder);


	//Testing GameEngine
//	string userinput;
//	GameEngine::GameEngine ge;
//	while (true)
//		{
//			cout << "Current Game State: " << ge.getGameState() << "." << endl;
//			cin >> userinput;
//			ge.setUserCommand(userinput);
//			ge.checkCommand();
//			//ge.cleanUserCommand();
//			//ge.startupPhase();
//
//			//GameEngine::GameEngine::cleanUserCommand();
//		}


//	//Testing Command
	Command *myCommand = new Command();
	myCommand->saveEffect("Test Effect");




	return 0;

}
