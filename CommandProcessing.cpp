#include "CommandProcessing.h"


using namespace CommandProcessing;


//======================Command=======================
//Constructors
Command::Command()
{
	commandname = new string("Empty");
	//set effect as empty until validate method is called
	commandeffect = new string("Empty");
}

//Parameters:
//name: The name to initialize the command with
Command::Command(string name)
{
	//set name to passed parameter
	commandname = new string(name);
	//set effect as empty until validate method is called
	commandeffect = new string("Empty");
}

//copy constructor
Command::Command(const Command& other)
{
	this->commandname = new string(*(other.commandname));
	this->commandeffect = new string(*(other.commandeffect));
}


//destructor
Command::~Command()
{
	delete commandname;
	delete commandeffect;
}


//Operators
//assignment operator
Command& Command::operator=(const Command& other)
{
	if (this == &other)
	{
		return *this;
	}

	Command c(other);
	return c;
}

//stream insertion operator
ostream& operator <<(ostream& o, Command& g)
{
	o << g.getTitle();
	return o;
}


//Function Definitions

//Parameters:
//effect: Effect of the command to be stored in the Command object
void Command::saveEffect(string effect)
{
	//delete previous value, then store new one
	delete commandeffect;
	commandeffect = new string(effect);

	//Sending command to log file
	Subject::Notify("Command: Save Effect(" + effect + ")");
}

string Command::getEffect()
{
	return *commandeffect;
}

string Command::getTitle()
{
	return *commandname;
}

void Command::stringToLog(string s)
{
	stringsToLog = s;
}

//==================CommandProcessor==================
//Constructors
CommandProcessor::CommandProcessor()
{
	//initialize current game state to Start
	currentgamestate = new string("start");

}

//copy constructor
CommandProcessor::CommandProcessor(const CommandProcessor& other)
{
	//copy game state from other object
	this->currentgamestate = new string(*(other.currentgamestate));
}


CommandProcessor::~CommandProcessor()
{
	delete currentgamestate;
}



//Operators
// assignment operator
CommandProcessor& CommandProcessor::operator=(const CommandProcessor& other)
{
	if (this == &other)
	{
		return *this;
	}

	CommandProcessor c(other);
	return c;
}

//stream insertion operator
ostream& operator <<(ostream& o, CommandProcessor& g)
{
	o << "Command Processor";	//not sure what else the command process could really return...
	return o;
}




//Function Definitions
void CommandProcessor::getCommand()
{
	CommandProcessor::displayInfo();
	//read command from console
	CommandProcessor::readCommand();

	//create new command object and initialize it with the user input
	Command c(userinput);

	CommandProcessor::validate(*currentgamestate, userinput, c);
	CommandProcessor::saveCommand(c);
}

void CommandProcessor::readCommand()
{
	//cin >> userinput;	//get user input and store it
	//We use getline so that spaces can be stored as well (for filenames, etc.)
	getline(cin, userinput);

}



void CommandProcessor::saveCommand(Command commandobj)
{
	lc.push_back(commandobj);
	cout << lc.back().getEffect() << endl << endl;
	if (commandobj.getEffect() == "Exiting program..." && *currentgamestate == "exit")
	{
		//printList();		//For debugging to make sure elements are properly saved to the list
		exit(0);
	}
}


//Parameters:
//s: State to change to
void CommandProcessor::changeState(string s)
{
	//delete old value and replace with new one
	delete currentgamestate;
	currentgamestate = new string(s);
}

//Parameters:
//cgs: String representing the current game state
//ui:  String representing the user input
void CommandProcessor::validate(string cgs, string ui, Command& commandobj)
{
	//manual commands

	if (ui.substr(0, 8) == "loadmap " && (cgs == "start" || cgs == "maploaded"))
	{
		changeState("maploaded");
		commandobj.saveEffect("Transitioned to MapLoaded state");
	}

	else if (ui == "validatemap" && cgs == "maploaded")
	{
		changeState("mapvalidated");
		commandobj.saveEffect("Transitioned to MapValidated state");
	}

	else if (ui.substr(0, 10) == "addplayer " && (cgs == "mapvalidated" || cgs == "playersadded"))
	{
		changeState("playersadded");
		commandobj.saveEffect("Transitioned to PlayersAdded state");
	}

	else if (ui == "gamestart" && cgs == "playersadded")
	{
		changeState("assignreinforcement");
		commandobj.saveEffect("Transitioned to AssignReinforcement state");
	}

	else if (ui == "replay" && cgs == "win")
	{
		changeState("start");
		commandobj.saveEffect("Transitioned to Start state");
	}

	else if (ui == "quit" && cgs == "win")
	{
		changeState("exit");
		commandobj.saveEffect("Exiting program...");
	}

	//game-triggered commands

	else if (ui == "issueorder" && (cgs == "assignreinforcement" || cgs == "issueorders"))
	{
		changeState("issueorders");
		commandobj.saveEffect("Transitioned to IssueOrders state");
	}

	else if (ui == "issueordersend" && cgs == "issueorders" )
	{
		changeState("executeorders");
		commandobj.saveEffect("Transitioned to ExecuteOrders state");
	}

	else if (ui == "execorder" && cgs == "executeorders")
	{
		changeState("executeorders");
		commandobj.saveEffect("Transitioned to ExecuteOrders state");
	}

	else if (ui == "endexecorders" && cgs == "executeorders")
	{
		changeState("assignreinforcement");
		commandobj.saveEffect("Transitioned to AssignReinforcement state");
	}

	else if (ui == "win" && cgs == "executeorders")
	{
		changeState("win");
		commandobj.saveEffect("Transitioned to Win state");
	}

	//Error
	else
	{
		commandobj.saveEffect("Invalid command for current state; no transition.");
	}


}

//Parameters:
//a: New game state
void CommandProcessor::setGameState(string a)
{
	//delete previous string stored to avoid memory leaks, then replace it with the new game state
	delete currentgamestate;
	currentgamestate = new string(a);
}


//Utility function to display the current state and valid commands
void CommandProcessor::displayInfo()
{
	cout << "Current state: " << *currentgamestate << endl;
	cout << "Available commands: ";

	if (*currentgamestate == "start")
	{
		cout << "loadmap <filename>" << endl;
	}
	
	else if (*currentgamestate == "maploaded")
	{
		cout << "loadmap <filename>, validatemap" << endl;
	}

	else if (*currentgamestate == "mapvalidated")
	{
		cout << "addplayer <playername>" << endl;
	}

	else if (*currentgamestate == "playersadded")
	{
		cout << "addplayer <playername>, gamestart" << endl;
	}

	else if (*currentgamestate == "assignreinforcement")
	{
		cout << "issueorder" << endl;
	}

	else if (*currentgamestate == "issueorders")
	{
		cout << "issueorder, issueordersend" << endl;
	}

	else if (*currentgamestate == "executeorders")
	{
		cout << "execorder, endexecorders, win" << endl;
	}

	else if (*currentgamestate == "win")
	{
		cout << "replay, quit" << endl;
	}

}

//Utility function to print the command list
void CommandProcessor::printList()
{
	for (auto i : lc)
	{
		cout << "Title: " << i.getTitle() << endl;
		cout << "Effect: " << i.getEffect() << endl << endl;
	}
}


void CommandProcessor::stringToLog(string s)
{
	stringsToLog = s;
}




//===================FileLineReader===================
//Constructors
FileLineReader::FileLineReader(string s)
{
	filename = new string(s);
	ifs.open(*filename);
	line = new string("");	//placeholder value so later calls of delete are safe
}

FileLineReader::FileLineReader(const FileLineReader& other)
{
	ifs.open(*(other.filename));	//get file to open from other instance
	this->line = new string(*(other.line));
}

//Destructor
FileLineReader::~FileLineReader()
{
	ifs.close();	//close stream
	delete line;	//delete line variable
}




//Operators
// assignment operator
FileLineReader& FileLineReader::operator=(const FileLineReader& other)
{
	if (this == &other)
	{
		return *this;
	}

	FileLineReader c(other);
	return c;
}

//stream insertion operator
ostream& operator <<(ostream& o, FileLineReader& g)
{
	o << "File Line Reader";	//not sure what else the file line reader could really return...
	return o;
}



//Functions
string FileLineReader::readLineFromFile()
{
	//read a line and store it in the line variable
	getline(ifs, *line);
	return *line;
}





//=============FileCommandProcessorAdapter============
//Constructors
FileCommandProcessorAdapter::FileCommandProcessorAdapter(string s)
{
	flr = new FileLineReader(s);
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(const FileCommandProcessorAdapter& other)
{
	this->flr = new FileLineReader(*(other.flr));
}

//Destructor
FileCommandProcessorAdapter::~FileCommandProcessorAdapter()
{
	delete flr;
}





//Operators
// assignment operator
FileCommandProcessorAdapter& FileCommandProcessorAdapter::operator=(const FileCommandProcessorAdapter& other)
{
	if (this == &other)
	{
		return *this;
	}

	FileCommandProcessorAdapter c(other);
	return c;
}

//stream insertion operator
ostream& operator <<(ostream& o, FileCommandProcessorAdapter& g)
{
	o << "File Command Processor Adapter";	//not sure what else the file line reader could really return...
	return o;
}






//Functions
void FileCommandProcessorAdapter::readCommand()
{
	userinput = flr->readLineFromFile();
}

void FileCommandProcessorAdapter::getCommand()
{
	CommandProcessor::displayInfo();
	//read command from console
	FileCommandProcessorAdapter::readCommand();

	//create new command object and initialize it with the user input
	Command c(userinput);

	CommandProcessor::validate(*currentgamestate, userinput, c);
	CommandProcessor::saveCommand(c);
}
