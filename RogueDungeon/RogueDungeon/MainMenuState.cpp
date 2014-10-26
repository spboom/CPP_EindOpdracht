#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include "stdafx.h"
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <windows.h>
#include <strsafe.h>
#include <tchar.h>
#include <string>
#include <wincon.h>
#include <conio.h>
#include <cstdlib>

#include <sstream>
#include <vector>
#include <fstream>

//
#include "MainMenuState.h"
#include "Game.h"
#include "InputHandler.h"
#include "Controller.h"

//
using namespace std;

void MainMenuState::update(int dt) {}

void MainMenuState::render() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

bool MainMenuState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/states/mainmenustate.txt");
	//TheController::Instance()->xmlFileController("../Inputfiles/example1.xml");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");
	TheInputHandler::Instance()->setCommandNewLine(">");

	return true;
}

bool MainMenuState::onExit() { return true; }

void MainMenuState::OutputHandler(string input)
{
	if (input != "")
	{
		if (input == "PLAY") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToPlay();
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