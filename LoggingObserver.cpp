#include "LoggingObserver.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


//// -------------------------------------------- Command --------------------------------------------  //
//void Command::stringToLog(string s)
//{
//	stringsToLog = s;
//}
//
//
//// -------------------------------------------- Command Processor --------------------------------------------  //
//CommandProcessor::CommandProcessor()
//{
//
//}
//
//
//void CommandProcessor::stringToLog(string s)
//{
//	stringsToLog = s;
//}




// -------------------------------------------- Observer --------------------------------------------  //
Observer::Observer()
{

}

Observer::~Observer()
{

}




// -------------------------------------------- Log Observer --------------------------------------------  //
LogObserver::LogObserver()
{

}

LogObserver::~LogObserver()
{

}

void LogObserver::update(string s)
{
	cout << "Updating file..." << endl;
	//Creating file stream
	ofstream myFile;
	myFile.open("GameLog.txt", ofstream::app);

//	For ever string that needs to be logged:
//	for(int i = 0; i < stringsToLog.size(); i++)
//	{
//		myFile << stringsToLog[i] << endl;
//	}

	myFile << s << endl;

}





// -------------------------------------------- Subject --------------------------------------------  //
Subject::Subject()
{
	observers = new list<Observer*>;
}
Subject::~Subject()
{
	delete observers;
}

void Subject::Notify(string s)
{
//	cout << "Notifying..." << endl;
//	list <Observer*>::iterator i = observers->begin();
//	for(; i!= observers->end(); i++)
//	{
//		(*i)->update();
//	}

	LogObserver::update(s);


}






