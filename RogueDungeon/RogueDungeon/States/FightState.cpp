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

FightState::FightState() {}
FightState::~FightState() {}

void FightState::update() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

void FightState::render() {
}

bool FightState::onEnter() {

	// 
	//TheController::Instance()->txtFileController("Inputfiles/States/creditsstate.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");
	TheInputHandler::Instance()->appendCommandLine(">");

	return true;
}

bool FightState::onExit() {
	GameState::onExit();
	return true;
}

void FightState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
		if (input == "")//TODO
		{
		}

		else
		{
			GameState::OutputHandler(input);
		}
	}


	//
}