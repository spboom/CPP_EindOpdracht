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

void FightState::render() {}

void FightState::step()
{
	Game::Instance()->cleanScreen();
	InputHandler::Instance()->setCommandLine("Je bent in gevecht met:");
	for (int i = 0; i < enemies.size(); i++)
	{
		stringstream line;

		line << enemies[i]->name << " " << i + 1 << " " << enemies[i]->getDiscription();
		InputHandler::Instance()->setCommandLine(line.str());
	}

	InputHandler::Instance()->setCommandLine("");
	InputHandler::Instance()->setCommandLine("acties tegenstanders:");
	for (int i = 0; i < enemies.size(); i++)
	{
		stringstream line;

		line << enemies[i]->name << " " << i + 1 << " doet " << enemies[i]->attack(player) << "shade";
		InputHandler::Instance()->setCommandLine(line.str());
	}

	InputHandler::Instance()->setCommandLine("");

	stringstream line;
	line << "je hebt nog " << player->lifepoints << " van de " << player->maxLifepoints << " levenspunten over";
	InputHandler::Instance()->setCommandLine(line.str());

	InputHandler::Instance()->setCommandLine("");
	InputHandler::Instance()->setCommandLine("wat doe je?");

	InputHandler::Instance()->setCommandLine("");
	TheInputHandler::Instance()->setCommandLine("[aanval:vlucht:gebruik item]");

	InputHandler::Instance()->setCommandLine("");
	InputHandler::Instance()->appendCommandLine(">");

}

bool FightState::onEnter() {

	// 
	//TheController::Instance()->txtFileController("Inputfiles/States/creditsstate.txt");

	//
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
			if (InputHandler::Instance()->getLastOutput() == "aanval" && i < enemies.size() && i <= 0)
			{
				stringstream line;
				step();
				line << "je deed " << player->attack(enemies[i - 1]) << " shade";
				InputHandler::Instance()->setCommandLine(line.str());
			}
			else if (InputHandler::Instance()->getLastOutput() == "gebruik item" && i < player->items.size() && i <= 0)
			{
				player->useItem(player->items[i - 1]);
				step();
			}
			else
			{
				GameState::OutputHandler(input);
			}
		}
	}


	//
}

