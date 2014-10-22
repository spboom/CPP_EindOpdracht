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

void InputHandler::update() {
	
}

void InputHandler::clean() {

}

void InputHandler::userInputHandler()
{
	string input;
	cin >> input;
	userOutputHandler(input);
}

void InputHandler::userOutputHandler(string input)
{
	// Check for Main Menu options
	if (input == "Play" || input == "play" || input == "PLAY") {
		cout << "Let's play Roque and Dungeon!\n";
		TheGame::Instance()->clean();
		TheGame::Instance()->goToPlay();
	}
	else if (input == "Quit" || input == "quit" || input == "QUIT") {
		cout << "Thank you for playing Rogue and Dungeon!\n";
		TheGame::Instance()->quitGame(0);
	}
	else {
		cout << "Chosen option don't exist! Is your input right?\n>";
	}
}

void InputHandler::readLine(string input)
{	

}

