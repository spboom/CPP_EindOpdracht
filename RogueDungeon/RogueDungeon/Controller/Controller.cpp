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
		TheInputHandler::Instance()->setCommandNewLine(str);
	}
	fin.close();
}

void Controller::xmlFileController(string xmlPath) {
	// Read from file
	/*TiXmlDocument doc(xmlPath.c_str());
	bool loadOkay = doc.LoadFile();
	if (!loadOkay)
	{
		cerr << "error: open file for input failed!" << endl;
		abort();
	}
	else
	{
		printf("\n%s:\n", xmlPath);
	}*/ 
	XMLDocument xmlDoc;
	xmlDoc.LoadFile(xmlPath.c_str());

	XMLDocument dxml;
	//Parse the xml sxml 
	int rslt = dxml.Parse(xmlPath.c_str());
	XMLNode *rootnode = dxml.FirstChild();
}

void Controller::saveFile() {

}

void Controller::writeFile() {

}