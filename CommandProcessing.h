#pragma once
#include "GameEngine.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <fstream>
using namespace std;


namespace CommandProcessing
{
	class Command: ILoggable, Subject
	{
		public:
			//constructors
			Command();
			Command(string name);
			Command(const Command& other);

			//destructor
			~Command();

			//assignment operator
			Command& operator=(const Command& other);
			//stream insertion operator
			friend ostream& operator <<(ostream& o, const Command& g);

			void saveEffect(string effect);
			string getEffect();
			string getTitle();


			void stringToLog(string s);

		private:
			string stringsToLog;
			string* commandname;
			string* commandeffect;
	};

	class CommandProcessor: ILoggable, Subject
	{
		public:
			//constructors
			CommandProcessor();
			CommandProcessor(const CommandProcessor& other);

			//destructor
			~CommandProcessor();

			//assignment operator
			class CommandProcessor& operator=(const CommandProcessor& other);
			//stream insertion operator
			friend ostream& operator <<(ostream& o, const CommandProcessor& g);

			virtual void getCommand();
			void setGameState(string a);


			void stringToLog(string s);

		protected:
			string userinput;
			void saveCommand(Command commandobj);
			void validate(string cgs, string ui, Command& commandobj);
			void displayInfo();	//utility function to display info on the current state
			void printList();	//utility function to print the command list
			string* currentgamestate;

		private:
			string stringsToLog;
			virtual void readCommand();
			void changeState(string s);
			list<Command> lc;
	};

	class FileLineReader
	{
	public:
		//constructors & destructor
		FileLineReader(string s);
		FileLineReader(const FileLineReader& other);
		~FileLineReader();

		//assignment operator
		class FileLineReader& operator=(const FileLineReader& other);
		//stream insertion operator
		friend ostream& operator <<(ostream& o, const FileLineReader& g);

		string readLineFromFile();	//function to read a line

	private:
		ifstream ifs;	//input file stream
		string* line;	//variable storing the current line
		string* filename;	//filename
	};

	class FileCommandProcessorAdapter : public CommandProcessor
	{
		public:
			//constructors & destructor
			FileCommandProcessorAdapter(string s);
			FileCommandProcessorAdapter(const FileCommandProcessorAdapter& other);
			~FileCommandProcessorAdapter();

			//assignment operator
			class FileCommandProcessorAdapter& operator=(const FileCommandProcessorAdapter& other);
			//stream insertion operator
			friend ostream& operator <<(ostream& o, const FileCommandProcessorAdapter& g);

			void getCommand();

		private:
			void readCommand();
			FileLineReader* flr;
	};


}
