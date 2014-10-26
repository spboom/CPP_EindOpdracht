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
#include <fstream>

//
#include "Controller.h"
#include "Game.h"
#include "InputHandler.h"

//
Controller* Controller::s_pInstance;
using namespace std;

void Controller::txtFileController(string txtPath) {
	// Read from file
	ifstream fin(txtPath.c_str());  
	if (!fin) {
		cerr << "error: open file for input failed!" << endl;
		abort();
	}
	char ch;
	while (fin.get(ch)) {  
		std::string str(1, ch);
		TheInputHandler::Instance()->setCommandNewLine(str);
	}
	fin.close();
}

void Controller::saveFile() {

}

void Controller::writeFile() {

}