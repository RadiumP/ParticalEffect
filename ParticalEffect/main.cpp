
#include <SDL.h>
#include <iostream>
#include <math.h>

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
		int elapsed = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
	



		//Draw
		for (int y = 0; y < screen.SCR_H; y++)
			for (int x = 0; x < screen.SCR_W; x++)
			{
				screen.setPixel(x, y, red,green,blue);
			}

		//screen.setPixel(400, 300, 0, 0, 0);

		screen.update();

		if (!screen.processEvents())
		{
			break;
		}
	}


	
	return 0;
}