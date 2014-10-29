#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

//
#include <iostream>
#include <string>
#include <sstream>

//
using namespace std;

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void update();
	void clean();
	void readLine();
	void setCommandLine(string input);
	void setCommandNewLine(string input);
	string getOutput();
private:
	InputHandler() {}
	~InputHandler();
	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;
#endif /* _INPUTHANDLER_H_ */