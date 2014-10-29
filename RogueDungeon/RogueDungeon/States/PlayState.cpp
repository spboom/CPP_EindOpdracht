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
#include "PlayState.h"
#include "../Controller/InputHandler.h"
#include "../Controller/Controller.h"

void PlayState::update(int dt) {}

void PlayState::render() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

bool PlayState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/states/playstate.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");

	return true;
}

bool PlayState::onExit() { return true; }

void PlayState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
		if (input == "main menu") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToMainMenu();
		}
		else if (input == "credits") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToCredits();
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