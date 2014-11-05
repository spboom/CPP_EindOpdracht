#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

//
#include <iostream>
#include <string>
#include <sstream>

//
using namespace std;

class Controller {
public:
	static Controller* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Controller();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void txtFileController(string txtPath);
	void xmlFileController(string xmlPath);
	void saveFile();
	void writeFile();
	void clean();

private:
	Controller() {}
	~Controller();
	static Controller* s_pInstance;
};
typedef Controller TheController;
#endif /* _CONTROLLER_H_ */