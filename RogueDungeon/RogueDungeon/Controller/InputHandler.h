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
	void appendCommandLine(string input);
	string getOutput();
	string getLastOutput();
	string getLastInput();
private:
	string user_output;
	string last_user_output;

	InputHandler();
	virtual ~InputHandler();
	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;
#endif /* _INPUTHANDLER_H_ */