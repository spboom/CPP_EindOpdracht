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

void MainMenuState::update(int dt) 
{
}

void MainMenuState::render()
{
}

bool MainMenuState::onEnter() {
	
	TheController::Instance()->txtFileController("test.txt");

	TheInputHandler::Instance()->setCommandLine("entering MenuState");
	TheInputHandler::Instance()->setCommandLine("Choose your option:");
	TheInputHandler::Instance()->setCommandNewLine(">");
	return true;
}

bool MainMenuState::onExit() {
	
	//std::cout << "exiting MenuState\n";
	return true;
}