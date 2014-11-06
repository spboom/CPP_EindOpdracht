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
#include "PlayState.h"
#include "../Controller/InputHandler.h"
#include "../Factory/MainFactory.h"
#include "../Controller/Controller.h"

void PlayState::update() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
}

void PlayState::render() {
	drawMap();
}

bool PlayState::onEnter() {

	// 
	TheController::Instance()->txtFileController("Inputfiles/State/state_play.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");

	dungeon = TheFactory::Instance()->createDungeon(10, 10, 2);
	level = 0;

	return true;
}

bool PlayState::onExit() {
	GameState::onExit();
	return true;
}

void PlayState::OutputHandler(string input)
{
	// MENU
	if (input != "")
	{
		if (input == "main menu") {
			TheGame::Instance()->cleanScreen();
			TheGame::Instance()->goToMainMenu();
		}
		else if (input == "credits") {
			TheGame::Instance()->cleanScreen();
			TheGame::Instance()->goToCredits();
		}

		else {
			GameState::OutputHandler(input);
		}
	}
}

PlayState::PlayState() {}

PlayState::~PlayState()
{
	for (int z = 0; z < dungeon.size(); z++)
	{
		for (int y = 0; y < dungeon[z].size(); y++)
		{
			for (int x = 0; x < dungeon[z][y].size(); x++)
			{
				delete dungeon[z][y][x];
			}
		}
	}
}

void PlayState::drawMap()
{
	vector<vector<Room*>> floor = dungeon[level];
	InputHandler::Instance()->setCommandLine("Kerker Kaart:");
	for (int y = 0; y < floor.size(); y++)
	{

		stringstream roomLine;
		stringstream hallLine;

		for (int x = 0; x < floor[y].size(); x++)
		{
			Room* room = floor[y][x];
			roomLine << room->getSymbol();
			if (room->hasHallway(Directions::East))
			{
				roomLine << "-";
			}
			else
			{
				roomLine << " ";
			}

			if (room->hasHallway(Directions::South))
			{
				hallLine << "| ";
			}
			else
			{
				hallLine << "  ";
			}
		}
		InputHandler::Instance()->setCommandLine(roomLine.str());
		InputHandler::Instance()->setCommandLine(hallLine.str());

	}
	InputHandler::Instance()->setCommandLine("");
	InputHandler::Instance()->setCommandLine("Legenda:");
	InputHandler::Instance()->setCommandLine(":- : Gangen");
	InputHandler::Instance()->setCommandLine("S  : Start locatie");
	InputHandler::Instance()->setCommandLine("E  : Eind Vijand");
	InputHandler::Instance()->setCommandLine("N  : Normale ruimte");
	InputHandler::Instance()->setCommandLine("L  : Trap omlaag");
	InputHandler::Instance()->setCommandLine("H  : Trap omhoog");
	InputHandler::Instance()->setCommandLine(".  : Niet bezocht");
}