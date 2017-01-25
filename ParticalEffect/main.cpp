
#include <SDL.h>
#include <iostream>
#include "Screen.h"
using namespace std;

int main(int argc, char ** argv)
{
	
	Screen screen;
	if (screen.init() == false)
	{
		cout << "Failed" << endl;
	}


	//game loop
	while (true)
	{
		if (!screen.processEvents())
		{
			break;
		}
	}


	
	return 0;
}