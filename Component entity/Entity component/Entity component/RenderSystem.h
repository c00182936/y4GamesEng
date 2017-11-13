#pragma once
#include <SDL_image.h>
#include <SDL.h>
class RenderSystem
{
public:
	
	RenderSystem();
	void renderSquare(SDL_Rect sqr, int r, int g, int b);
	~RenderSystem();
	SDL_Rect windowSize;
	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Surface *renderSurface;
};

