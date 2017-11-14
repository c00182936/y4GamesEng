#pragma once
#include <SDL_image.h>
#include <SDL.h>
#include"Entity.h"
#include <vector>
#include <iostream>
class RenderSystem
{
public:
	
	RenderSystem();
	void renderSquare(SDL_Rect sqr, int r, int g, int b);
	std::vector<Entity*> entities;
	void addEntity(Entity*e) { entities.push_back(e); }
	void Render();
	~RenderSystem();
	SDL_Rect windowSize;
	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Surface *renderSurface;
};

