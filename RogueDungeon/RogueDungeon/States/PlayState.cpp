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
	TheController::Instance()->txtFileController("Inputfiles/State/state_play.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");
	TheInputHandler::Instance()->appendCommandLine(">");

	return true;
}

bool PlayState::onExit() { return true; }

void PlayState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
		if (input == "MAIN MENU" || input == "Main Menu" || input == "main menu") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToMainMenu();
		}
		else if (input == "CREDITS" || input == "Credits" || input == "credits") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToCredits();
		}
		else if (input == "QUIT" || input == "Quit" || input == "quit") {
			TheInputHandler::Instance()->setCommandLine("Are you sure? Yes or No!");
			TheInputHandler::Instance()->appendCommandLine(">");
		}
		else if (input == "Yes") {
			TheInputHandler::Instance()->setCommandLine("Thank you for playing Rogue and Dungeon!");
			TheGame::Instance()->quitGame(0);
		}
		else if (input == "No") {
			TheInputHandler::Instance()->setCommandLine("Ok! You're still in the game!");
			TheInputHandler::Instance()->appendCommandLine(">");
		}
		else {
			TheInputHandler::Instance()->setCommandLine("Caution! Wrong input!");
			TheInputHandler::Instance()->appendCommandLine(">");
		}
	}

	//
}