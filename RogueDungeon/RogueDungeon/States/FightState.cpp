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

void FightState::step(bool attack)
{
	step(attack, "");
}
void FightState::step(bool attack, string aditionalLine)
{
	lines = vector<string>();
	Game::Instance()->cleanScreen();
	lines.push_back("Je bent in gevecht met:");
	for (int i = 0; i < enemies.size(); i++)
	{
		stringstream line;

		line << enemies[i]->name << " " << i + 1 << " " << enemies[i]->getDiscription();
		lines.push_back(line.str());
	}

	lines.push_back("");

	if (attack)
	{
		lines.push_back("acties tegenstanders:");

		for (int i = 0; i < enemies.size(); i++)
		{
			stringstream line;

			line << enemies[i]->name << " " << i + 1 << " doet " << enemies[i]->attack(player) << "shade";
			lines.push_back(line.str());
		}

		lines.push_back("");
	}
	stringstream line;
	line << "je hebt nog " << player->lifepoints << " van de " << player->maxLifepoints << " levenspunten over";
	lines.push_back(line.str());

	lines.push_back("");
	lines.push_back("wat doe je?");

	lines.push_back("");
	lines.push_back("[aanval:vlucht:gebruik item]");

	lines.push_back("");
	if (aditionalLine != "")
	{
		lines.push_back(aditionalLine);
		lines.push_back("");
	}

	for (int i = 0; i < lines.size(); i++)
	{
		InputHandler::Instance()->setCommandLine(lines[i]);
	}

	bool allDead = true;
	for (int i = 0; i < enemies.size(); i++)
	{
		if (!enemies[i]->isDead())
		{
			allDead = false;
			break;
		}
	}

	if (player->isDead())
	{
		Game::Instance()->GameOver();
	}

	if (allDead)
	{
		Game::Instance()->getStateMachine()->popState();
		InputHandler::Instance()->setCommandLine("alle vijanden zijn dood");
	}
}

bool FightState::onEnter() {

	// 
	//TheController::Instance()->txtFileController("Inputfiles/States/creditsstate.txt");

	step(false);
	//
	return true;
}

bool FightState::onReEnter()
{
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
			int i = atoi(input.c_str()) - 1;
			if (InputHandler::Instance()->getLastOutput() == "aanval" && i < enemies.size() && i <= 0)
			{
				stringstream line;
				if (!enemies[i]->isDead())
				{
					line << "je deed " << player->attack(enemies[i]) << " shade";
					step(true, line.str());
				}
				else
				{
					line << "vijand " << input << " is al dood";
					InputHandler::Instance()->setCommandLine(line.str());
				}
			}
			else if (InputHandler::Instance()->getLastOutput() == "gebruik item" && i < player->items.size() && i <= 0)
			{
				player->useItem(player->items[i]);
				step(true);
			}
			else
			{
				GameState::OutputHandler(input);
			}
		}
	}


	//
}

