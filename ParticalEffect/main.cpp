
#include <SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
	const int SCR_W = 800;
	const int SCR_H = 600;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Failed" << endl;
		return 1;
	}
	// init window
	SDL_Window* window = SDL_CreateWindow("Particle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);

	if (window == NULL) 
	{
		SDL_Quit();
		return 2;
	}
	

	bool quit = false;
	SDL_Event event;
	
	//init render, texture and buffer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, SCR_W, SCR_H);//255

	if (renderer == NULL)
	{
		cout << "Create renderer failed" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	if (texture == NULL)
	{
		cout << "Create texture failed" << endl;
		
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCR_W*SCR_H];
	memset(buffer, 255, SCR_W*SCR_H*sizeof(Uint32));//set block of memory; init to white
	SDL_UpdateTexture(texture, NULL, buffer, SCR_W*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	//game loop
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}


	//close
	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}