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
#include <vector>

//
#include "InputHandler.h"
#include "Game.h"

//
InputHandler* InputHandler::s_pInstance;
using namespace std;
string user_output;

void InputHandler::update() {}

void InputHandler::clean() {}

void InputHandler::readLine()
{	
	string input = "";
	getline(cin, input);
	user_output = input;
}

void InputHandler::setCommandLine(string input) {
	cout << input << endl;
}

void InputHandler::setCommandNewLine(string input) {
	cout << input;
}

string InputHandler::getOutput() {
	return user_output;
}