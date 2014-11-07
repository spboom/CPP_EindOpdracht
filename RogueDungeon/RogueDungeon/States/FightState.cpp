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

FightState::FightState(vector<Enemy*> enemies, Player* player)
{
	this->enemies = enemies;
	this->player = player;
}
FightState::~FightState() {}

void FightState::update() {
	OutputHandler(TheInputHandler::Instance()->getOutput());
	GameState::update();
}

void FightState::render() {
}

bool FightState::onEnter() {

	// 
	//TheController::Instance()->txtFileController("Inputfiles/States/creditsstate.txt");

	//
	TheInputHandler::Instance()->setCommandLine("SELECT FROM MENU");
	TheInputHandler::Instance()->setCommandLine("");
	TheInputHandler::Instance()->setCommandLine("[aanval:vlucht:gebruik item]");
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
		if (input == "aanval")
		{
			InputHandler::Instance()->setCommandLine("val welke aan?");
		}
		else if (input == "vlucht"){

			InputHandler::Instance()->setCommandLine("welke richting?");
		}
		else if (input == "gebruik item")
		{
			InputHandler::Instance()->setCommandLine("welk item?");
		}
		else
		{
			int i = atoi(input.c_str());
			if (lastInput == "aanval" && i < enemies.size())
			{
				player->attack(enemies[i]);
			}
			else if (lastInput == "gebruik item"&& i < player->items.size())
			{
				player->useItem(player->items[i]);
			}
			GameState::OutputHandler(input);
		}
	}


	//
}

