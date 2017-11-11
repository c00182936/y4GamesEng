#include "PositionComponent.h"



PositionComponent::PositionComponent()
{
}


PositionComponent::~PositionComponent()
{
}

bool PositionComponent::checkCollision(PositionComponent other)
{
	return false;
}

SDL_Rect PositionComponent::getSDLRect()
{
	return SDL_Rect();
}
