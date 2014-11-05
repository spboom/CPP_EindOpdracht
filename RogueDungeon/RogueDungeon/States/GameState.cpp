#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <stdio.h>
#include <string>


//
#include "GameState.h"
#include "../Controller/InputHandler.h"
#include "../Controller/Game.h"

using namespace std;

bool GameState::onExit()
{
	delete this;
	return true;
}

void GameState::OutputHandler(string input)
{
	if (input == "quit") {
		TheInputHandler::Instance()->setCommandLine("Are you sure? Yes or No!");
	}
	else if (input == "yes") {
		if (lastInput == "quit")
		{
			TheInputHandler::Instance()->setCommandLine("Thank you for playing Rogue and Dungeon!");
			TheGame::Instance()->quitGame(0);
		}
		else
		{
			TheInputHandler::Instance()->setCommandLine("yes what?");
		}

	}

	else if (input == "no") {}

	else
	{
		TheInputHandler::Instance()->setCommandLine("Caution! Wrong input!");
	}

	lastInput = input;

}
