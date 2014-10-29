#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <wincon.h>
#include <conio.h>
#include <cstdlib>

#include <sstream>
#include <vector>
#include <fstream>

//
#include "MainMenuState.h"
#include "../Controller/Game.h"
#include "../Controller/InputHandler.h"
#include "../Controller/Controller.h"

//
using namespace std;

void MainMenuState::update(int dt) {}

void MainMenuState::render() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

bool MainMenuState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/states/mainmenustate.txt");
	TheController::Instance()->xmlFileController("Inputfiles/example1.xml");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");
	TheInputHandler::Instance()->setCommandNewLine(">");

	return true;
}

bool MainMenuState::onExit() { return true; }

void MainMenuState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
		if (input == "PLAY" || input == "Play" || input == "play") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToPlay();
		}
		else if (input == "CREDITS" || input == "Credits" || input == "credits") {
			TheGame::Instance()->clean();
			TheGame::Instance()->goToCredits();
		}
		else if (input == "QUIT" || input == "Quit" || input == "quit") {
			TheInputHandler::Instance()->setCommandLine("Are you sure? Yes or No!");
			TheInputHandler::Instance()->setCommandNewLine(">");
		}
		else if (input == "Yes") {
			TheInputHandler::Instance()->setCommandLine("Thank you for playing Rogue and Dungeon!");
			TheGame::Instance()->quitGame(0);
		}
		else if (input == "No") {
			TheInputHandler::Instance()->setCommandLine("Ok! You're still in the game!");
			TheInputHandler::Instance()->setCommandNewLine(">");
		}
		else {
			TheInputHandler::Instance()->setCommandLine("Caution! Wrong input!");
			TheInputHandler::Instance()->setCommandNewLine(">");
		}
	}

	//
}