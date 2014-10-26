#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <iostream>
#include <string>
#include <sstream>
#include "stdafx.h"

//
#include "Game.h"
#include "PlayState.h"
#include "InputHandler.h"
#include "Controller.h"

void PlayState::update(int dt) {}

void PlayState::render() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

bool PlayState::onEnter() {
	
	// 
	TheController::Instance()->txtFileController("Inputfiles/states/playstate.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");
	TheInputHandler::Instance()->setCommandNewLine(">");

	return true;
}

bool PlayState::onExit() { return true; }

void PlayState::OutputHandler(string input)
{
	if (input != "")
	{
		if (input == "MAIN MENU") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToMainMenu();
		}
		else if (input == "CREDITS") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToCredits();
		}
		else if (input == "QUIT") {
			TheInputHandler::Instance()->setCommandLine("Thank you for playing Rogue and Dungeon!");
			TheGame::Instance()->quitGame(0);
		}
		else {
			TheInputHandler::Instance()->setCommandLine("Caution! Do you have chosen the correct menu item?");
			TheInputHandler::Instance()->setCommandNewLine(">");
		}
	}
}