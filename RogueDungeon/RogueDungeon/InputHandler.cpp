#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "stdafx.h"

//
#include "InputHandler.h"
#include "Game.h"

//
InputHandler* InputHandler::s_pInstance;
using namespace std;

void InputHandler::update() {}

void InputHandler::clean() {}

void InputHandler::readLine()
{	
	string input = "";
	getline(cin, input);
	userOutputHandler(input);
}

void InputHandler::setCommandLine(string input)
{
	cout << input << endl;
}

void InputHandler::setCommandNewLine(string input)
{
	cout << input;
}

void InputHandler::userOutputHandler(string input)
{
	// Check for Main Menu options
	if (input == "Play" || input == "play" || input == "PLAY") {
		setCommandLine("Let's play Roque and Dungeon!");
		TheGame::Instance()->clean();
		TheGame::Instance()->goToPlay();
	}
	else if (input == "Quit" || input == "quit" || input == "QUIT") {
		setCommandLine("Thank you for playing Rogue and Dungeon!");
		TheGame::Instance()->quitGame(0);
	}
	else {
		setCommandLine("Chosen option don't exist! Is your input right?");
		setCommandNewLine(">");
	}

	//
}