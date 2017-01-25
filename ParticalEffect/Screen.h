#pragma once

#include <SDL.h>

class Screen
{
public:
	const int SCR_W = 800;
	const int SCR_H = 600;

	Screen();
	~Screen();
	
	bool init();
	bool processEvents();
	void close();

private:
	// init window
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	Uint32 *buffer;
};

