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

InputHandler::InputHandler() {}

InputHandler::~InputHandler() {}

void InputHandler::update() {}

void InputHandler::clean() {
	delete this;
}

void InputHandler::readLine()
{
	string input = "";
	getline(cin, input);
	int i = 0;
	while (input[i])
	{
		input[i] = tolower(input[i]);
		++i;
	}
	last_user_output = user_output;
	user_output = input;
}

void InputHandler::setCommandLine(string input) {
	cout << input << endl;
}

void InputHandler::appendCommandLine(string input) {
	cout << input;
}

string InputHandler::getOutput() {
	return user_output;
}

string InputHandler::getLastOutput()
{
	return last_user_output;
}

