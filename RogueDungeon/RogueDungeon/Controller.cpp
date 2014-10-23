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

void Controller::txtFileController(string txtPath)
{
	fstream textfile(txtPath);

	char item;
	while (!textfile.eof())
	{
		textfile.get(item);
		//TheInputHandler::Instance()->setCommandLine(item);
		cout << item;
	}

	textfile.close();
}

void Controller::saveFile() 
{

}

void Controller::writeFile()
{

}