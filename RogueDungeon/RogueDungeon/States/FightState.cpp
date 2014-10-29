#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <iostream>
#include <string>
#include <sstream>

//
#include "../Controller/Game.h"
#include "FightState.h"
#include "../Controller/InputHandler.h"
#include "../Controller/Controller.h"

void FightState::update(int dt) {}

void FightState::render() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

bool FightState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/states/creditsstate.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");

	return true;
}

bool FightState::onExit() { return true; }

void FightState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
	}
	else
	{
		TheInputHandler::Instance()->setCommandNewLine(">");
	}

	//
}