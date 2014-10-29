#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <iostream>
#include <string>
#include <sstream>

//
#include "../Controller/Game.h"
#include "CreditsState.h"
#include "../Controller/InputHandler.h"
#include "../Controller/Controller.h"

void CreditsState::update(int dt) {}

void CreditsState::render() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

bool CreditsState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/states/creditsstate.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");

	return true;
}

bool CreditsState::onExit() { return true; }

void CreditsState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
		if (input == "main menu") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToMainMenu();
		}
		else if (input == "play") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToPlay();
		}
		else if (input == "quit") {
			TheInputHandler::Instance()->setCommandLine("Are you sure? Yes or No!");
			TheInputHandler::Instance()->setCommandNewLine(">");
		}
		else if (input == "yes") {
			TheInputHandler::Instance()->setCommandLine("Thank you for playing Rogue and Dungeon!");
			TheGame::Instance()->quitGame(0);
		}
		else if (input == "no") {
			TheInputHandler::Instance()->setCommandLine("Ok! You're still in the game!");
			TheInputHandler::Instance()->setCommandNewLine(">");
		}
		else {
			TheInputHandler::Instance()->setCommandLine("Caution! Wrong input!");
			TheInputHandler::Instance()->setCommandNewLine(">");
		}
	}
	else
	{
		TheInputHandler::Instance()->setCommandNewLine(">");
	}

	//
}