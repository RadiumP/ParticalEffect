
#include <SDL.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Swarm.h"
#include "Screen.h"
using namespace std;

int main(int argc, char ** argv)
{
	
	srand(time(NULL));

	Screen screen;
	if (screen.init() == false)
	{
		cout << "Failed" << endl;
	}

	Swarm swarm;

	
	//game loop
	while (true)
	{
		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);

		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
	
		////Draw
		//for (int y = 0; y < screen.SCR_H; y++)
		//	for (int x = 0; x < screen.SCR_W; x++)
		//	{
		//		screen.setPixel(x, y, red,green,blue);
		//	}

		

		const Particles * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particles particle = pParticles[i];

			int x = (particle.m_x + 1) * screen.SCR_W / 2;
			int y = (particle.m_y) * screen.SCR_W / 2 + screen.SCR_H / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();
		screen.update();

		if (!screen.processEvents())
		{
			break;
		}
	}

	screen.close();
	
	return 0;
}