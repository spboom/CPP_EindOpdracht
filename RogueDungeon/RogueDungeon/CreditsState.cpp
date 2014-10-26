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
#include "CreditsState.h"
#include "InputHandler.h"
#include "Controller.h"

void CreditsState::update(int dt) {}

void CreditsState::render() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

bool CreditsState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/states/creditsstate.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");
	TheInputHandler::Instance()->setCommandNewLine(">");

	return true;
}

bool CreditsState::onExit() { return true; }

void CreditsState::OutputHandler(string input)
{
	if (input != "")
	{
		if (input == "MAIN MENU") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToMainMenu();
		}
		else if (input == "PLAY") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToPlay();
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