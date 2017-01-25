#include "Screen.h"

#include <iostream>




Screen::Screen():
	window(NULL), renderer(NULL),texture(NULL), buffer(NULL)
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
	memset(buffer, 255, SCR_W*SCR_H*sizeof(Uint32));//set block of memory; init to white

	SDL_UpdateTexture(texture, NULL, buffer, SCR_W*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);


	return true;
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
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

}