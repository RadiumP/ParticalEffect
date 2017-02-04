#include "Screen.h"
#include <iostream>





Screen::Screen():
	window(NULL), renderer(NULL),texture(NULL), buffer(NULL), buffer2(NULL)
{
	
}


Screen::~Screen()
{
}


bool Screen::init() 
{
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}
	// init window
	window = SDL_CreateWindow("Particle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		SDL_Quit();
		return false;
	}


	//init render, texture and buffer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, SCR_W, SCR_H);//255

	if (renderer == NULL)
	{
		
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}
	if (texture == NULL)
	{
		
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	buffer = new Uint32[SCR_W*SCR_H];
	buffer2 = new Uint32[SCR_W*SCR_H];
	memset(buffer, 0, SCR_W*SCR_H*sizeof(Uint32));//set block of memory; init to white
	memset(buffer2, 0, SCR_W*SCR_H*sizeof(Uint32));//set block of memory; init to white
	


	return true;
}

void Screen::boxBlur()
{
	//swap buffers, so pixel is in buffer2 and drawing to buffer
	Uint32 *temp = buffer;
	buffer = buffer2;
	buffer2 = temp;



	for (int y = 0; y < SCR_H; y++)
	{
		for (int x = 0; x < SCR_W; x++)
		{

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for (int row = -1; row <= 1; row++)
			{
				for (int col = -1; col <= 1; col++)
				{
					int currentX = x + col;
					int currentY = y + row;

					if (currentX >= 0 && currentX < SCR_W && currentY >= 0 && currentY < SCR_H)
					{
						Uint32 color = buffer2[currentY * SCR_W + currentX];
						
						Uint8 red = color;
						Uint8 green = color >> 8;
						Uint8 blue = color>>16;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}

			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			setPixel(x,y,red, green, blue);

		}
	}
}

void Screen::update()
{
	SDL_UpdateTexture(texture, NULL, buffer, SCR_W*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{

	if (x < 0 || x >= SCR_W || y < 0 || y >= SCR_H)
	{
		return;
	}

	Uint32 color = 0;

	color += 0xFF;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += green;
	color <<= 8;
	color += red;
	
	//color += red;
	//color <<= 8;
	//color += green;
	//color <<= 8;
	//color += blue;
	//color <<= 8;
	//color += 0xFF;

	

	
	
	buffer[(y * SCR_W) + x] = color;//0x00FF00;

}

void Screen::clear()
{
	memset(buffer, 0, SCR_W*SCR_H*sizeof(Uint32));//set block of memory; init to white
	memset(buffer2, 0, SCR_W*SCR_H*sizeof(Uint32));//set block of memory; init to white
}

bool Screen::processEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return false;
		}
	}

	return true;
}
void Screen::close() 
{
	//close
	delete[] buffer;
	delete[] buffer2;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

}

