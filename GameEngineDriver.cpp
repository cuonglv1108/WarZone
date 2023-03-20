#include "GameEngine.h"

using namespace std;

int main()
{
	string userinput;
	GameEngine::GameEngine ge;

	while (true)
	{
		cout << "Current Game State: " << ge.getGameState() << "." << endl;
		cin >> userinput;
		ge.setUserCommand(userinput);
		//ge.checkCommand();
		//ge.cleanUserCommand();
		ge.startupPhase();
        ge.mainGameloop();

		//GameEngine::GameEngine::cleanUserCommand();
	}
}
