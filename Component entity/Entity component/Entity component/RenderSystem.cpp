#include "RenderSystem.h"



RenderSystem::RenderSystem()
{
}

void RenderSystem::renderSquare(SDL_Rect sqr, int r, int g, int b)
{
}


void RenderSystem::Render()
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		std::cout << "rendered object"<<std::endl;
	}
}

RenderSystem::~RenderSystem()
{
}
