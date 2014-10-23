#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

//
using namespace std;

class InputHandler
{
public:
	void update();
	void clean();
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void readLine();
	void userOutputHandler(string input);
	void setCommandLine(string input);
	void setCommandNewLine(string input);
private:
	InputHandler() {}
	~InputHandler();
	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;
#endif /* _INPUTHANDLER_H_ */