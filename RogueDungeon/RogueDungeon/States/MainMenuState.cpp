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
#include "../Factory/LocationFactory.h"

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
	characters = TheCharacterFactory::Instance()->parseXML("Inputfiles/Character/Enemy/enemy.xml");
	items =  TheItemFactory::Instance()->parseXML("Inputfiles/Item/item.xml");
	location = TheLocationFactory::Instance()->parseXML("Inputfiles/Location/location.xml");

	return true;
}

bool MainMenuState::onExit(){
	GameState::onExit();
	return true;
}

MainMenuState::MainMenuState() {}

MainMenuState::~MainMenuState()
{
	for (int i = 0; i < characters.size(); i++)
	{
		delete characters[i];
	}
	for (int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	for (int i = 0; i < location.size(); i++)
	{
		delete location[i];
	}
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