#ifdef _WIN32
// Check for memory leaks. Put snippet in beginning of program: _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#define _CRTDBG_MAP_ALLOC
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
#include <string>
#include <sstream>

//
#include "Game.h"
#include "InputHandler.h"

using namespace std;

// our Game object
Game* g_game = 0;

// game constants
const string TITLE = "Rogue & Dungeon";
const string VERSION = "v0.1";
const int SCREEN_WIDTH = 100;;
const int SCREEN_HEIGHT = 50;

// MAIN point for the console application
int main(int argc, char* argv[])
{
	// Checking for memory leaks!
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	if (TheGame::Instance()->init(TITLE + " (" + VERSION + ")" ,SCREEN_WIDTH, SCREEN_HEIGHT))
	{
		while (TheGame::Instance()->running())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			TheInputHandler::Instance()->readLine();
		}
	}
	else
	{
		std::cout << "game init failure";
		return -1;
	}
	TheGame::Instance()->clean();
	return 0;
}