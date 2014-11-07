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

CreditsState::CreditsState() {}
CreditsState::~CreditsState() {}

void CreditsState::update() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

void CreditsState::render() {
}

bool CreditsState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/State/state_credit.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");

	return true;
}

bool CreditsState::onExit() {
	GameState::onExit();
	return true;
}

void CreditsState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
		if (input == "main menu") {
			TheGame::Instance()->cleanScreen();
			TheGame::Instance()->goToMainMenu();
		}
		else if (input == "play") {
			TheGame::Instance()->cleanScreen();
			TheGame::Instance()->goToPlay();
		}
		else {
			GameState::OutputHandler(input);
		}
	}
}