#include "CommandProcessing.h"

using namespace std;

int main(int argc, char* argv[])
{
	//if no argument
	if (argc == 1)
	{
		CommandProcessing::CommandProcessor cp;

		while (true)
		{
			cp.getCommand();
		}
	}
	//if console
	else if (argc == 2 && strcmp(argv[1], "-console") == 0)
	{
		CommandProcessing::CommandProcessor cp;

		while (true)
		{
			cp.getCommand();
		}
	}
	//if filename is mentioned
	else if (argc == 3 && strcmp(argv[1], "-file") == 0)
	{
		//CommandProcessing::CommandProcessor cp;
		CommandProcessing::FileCommandProcessorAdapter fcp(argv[2]);

		while (true)
		{
			fcp.getCommand();
		}
	}
	//else
	else
	{
		/*
		cout << argc << endl;
		cout << argv[0] << endl;
		cout << argv[1] << endl;
		cout << argv[2] << endl;
		*/
		cout << "Invalid command line arguments." << endl;
	}

}