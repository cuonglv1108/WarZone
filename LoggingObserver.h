#ifndef LOGGINGOBSERVER_H_
#define LOGGINGOBSERVER_H_

#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

class ILoggable
{
	private:

	public:
		virtual void stringToLog(string s) = 0;
};



class Observer
{
	private:


	public:
		Observer();
		~Observer();
};

class Subject
{
	private:
		list<Observer*> *observers;

	public:
		virtual void Notify(string s);
		Subject();
		~Subject();
};


class LogObserver: Observer
{
	private:


	public:
		LogObserver();
		~LogObserver();
		static void update(string s);
};

//class Command: ILoggable, Subject
//{
//	private:
//		string stringsToLog;
//
//	public:
//		void saveEffect();
//		void stringToLog(string s);
//};
//
//class CommandProcessor: ILoggable, Subject
//{
//	private:
//		string stringsToLog;
//	public:
//		CommandProcessor();
//		void stringToLog(string s);
//
//};
#endif
