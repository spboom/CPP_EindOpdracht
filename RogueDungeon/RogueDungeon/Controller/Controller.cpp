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
#include <fstream>
#include "tinyxml2.h"

//
#include "Controller.h"
#include "Game.h"
#include "InputHandler.h"

//
Controller* Controller::s_pInstance;
using namespace std;
using namespace tinyxml2;

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
		TheInputHandler::Instance()->appendCommandLine(str);
	}
	fin.close();
}

void Controller::xmlFileController(string xmlPath, vector<string> *objects) {
	// Read from file
	XMLDocument doc;
	doc.LoadFile(xmlPath.c_str());
	const char* title;
	// Text is just another Node to TinyXML-2. The more
	// general way to get to the XMLText:
	XMLNode *node = doc.FirstChildElement()->FirstChildElement()->FirstChildElement();
	while (node != NULL)
	{
		title = node->FirstChild()->ToText()->Value();
		// add to array
		objects->push_back(title);
		/*std::string str(title);
		TheInputHandler::Instance()->appendCommandLine(str);
		TheInputHandler::Instance()->appendCommandLine("\n\>");*/
		node = node->NextSibling();
	}
	doc.Clear();
}

void Controller::saveFile() {

}

void Controller::writeFile() {

}