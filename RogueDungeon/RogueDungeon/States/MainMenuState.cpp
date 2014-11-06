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
#include "../Factory/MainFactory.h"
#include "../Factory/CharacterFactory.h"
#include "../Factory/ItemFactory.h"

//
using namespace std;

void MainMenuState::update() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

void MainMenuState::render() {
}

bool MainMenuState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/State/state_mainmenu.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");

	//
	TheCharacterFactory::Instance()->parseXML("Inputfiles/Character/Enemy/enemy.xml");
	TheItemFactory::Instance()->parseXML("Inputfiles/Item/item.xml");

	return true;
}

bool MainMenuState::onExit(){
	GameState::onExit();
	return true;
}

void MainMenuState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
		if (input == "play") {
			TheGame::Instance()->cleanScreen();
			TheGame::Instance()->goToPlay();
		}
		else if (input == "credits") {
			TheGame::Instance()->cleanScreen();
			TheGame::Instance()->goToCredits();
		}

		else {
			GameState::OutputHandler(input);
		}
	}

	//
}