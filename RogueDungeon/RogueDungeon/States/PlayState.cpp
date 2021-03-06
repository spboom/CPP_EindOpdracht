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
	GameState::update();
}

void PlayState::render() {
	//player->location->getDescription();
}

bool PlayState::onEnter() {

	// 

	dungeon = TheFactory::Instance()->createDungeon(10, 10, 2);
	level = 0;
	player = new Player(dungeon->getStart());

	onReEnter();


	return true;
}

bool PlayState::onReEnter()
{
	Game::Instance()->cleanScreen();
	TheController::Instance()->txtFileController("Inputfiles/State/state_play.txt");

	setText();
	return true;
}

bool PlayState::onExit() {
	GameState::onExit();
	return true;
}

void PlayState::OutputHandler(string input)
{
	if (input != "")
	{
		if (input == "kaart" || input == "bekijk kaart") {
			TheGame::Instance()->cleanScreen();
			drawMap();
		}
		else if (input == "main menu") {
			TheGame::Instance()->cleanScreen();
			TheGame::Instance()->goToMainMenu();
		}
		else if (input == "credits") {
			TheGame::Instance()->cleanScreen();
			TheGame::Instance()->goToCredits();
		}
		else if (input == "") {
			TheGame::Instance()->cleanScreen();
		}
		else if (input == "noord")
		{
			if (player->move(Directions::Direction::North))
			{
				setText();
			}
		}
		else if (input == "oost")
		{
			if (player->move(Directions::Direction::East))
			{
				setText();
			}
		}
		else if (input == "zuid")
		{
			if (player->move(Directions::Direction::South))
			{
				setText();
			}
		}
		else if (input == "west")
		{
			if (player->move(Directions::Direction::West))
			{
				setText();
			}
		}
		else if (input == "vecht")
		{
			Room* room = player->location;
			if (!room->enemies.empty())
			{
				TheGame::Instance()->goToFight(room->enemies, player);
			}
			else
			{
				InputHandler::Instance()->setCommandLine("er zijn geen vijanden in de kamer");
			}
		}
		else if (input == "vlucht")
		{
			TheInputHandler::Instance()->setCommandLine("Welke richting?");
		}
		else if (input == "zoek")
		{

		}
		else if (input == "rust uit")
		{

		}
		else if (input == "bekijk spullen")
		{

		}
		else if (input == "terug")
		{
			TheInputHandler::Instance()->setCommandLine("Welke richting?");
		}
		else {
			GameState::OutputHandler(input);
		}
	}
}

PlayState::PlayState() {}

PlayState::~PlayState()
{
	delete dungeon;
	delete player;
}

void PlayState::drawMap()
{
	vector<vector<Room*>> floor = dungeon->getFloor(player->location->getLevel());
	InputHandler::Instance()->setCommandLine("Kerker Kaart:");
	for (int y = 0; y < floor.size(); y++)
	{

		stringstream roomLine;
		stringstream hallLine;

		for (int x = 0; x < floor[y].size(); x++)
		{
			Room* room = floor[y][x];
			roomLine << room->getSymbol();
			if (room->visited && room->hasHallway(Directions::East))
			{
				roomLine << "-";
			}
			else
			{
				roomLine << " ";
			}

			if (room->hasHallway(Directions::South) && room->getHallway(Directions::South)->connectedToVisited())
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
	InputHandler::Instance()->setCommandLine("");
	InputHandler::Instance()->setCommandLine("[terug]");
	InputHandler::Instance()->setCommandLine("");

}

void PlayState::setText()
{
	TheGame::Instance()->cleanScreen();
	TheController::Instance()->txtFileController("Inputfiles/State/state_play.txt");
	TheInputHandler::Instance()->setCommandLine(player->location->getDescription());
	TheInputHandler::Instance()->setCommandLine(player->location->getExits());
	TheInputHandler::Instance()->setCommandLine(player->location->getEnemy());
	TheInputHandler::Instance()->setCommandLine(player->location->getGeneralDescription());
	TheInputHandler::Instance()->setCommandLine(player->location->getGamePlayMenu());
}