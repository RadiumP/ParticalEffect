#pragma once

#include <SDL.h>
#include <iostream>
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
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void clear();
	void boxBlur();

private:
	// init window
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	Uint32 *buffer;
	Uint32 *buffer2;
};

