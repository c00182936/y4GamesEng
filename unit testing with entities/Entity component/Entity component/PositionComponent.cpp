#include "PositionComponent.h"



PositionComponent::PositionComponent()
{
	type = "position";
}


PositionComponent::~PositionComponent()
{
}

bool PositionComponent::checkCollision(PositionComponent other)
{
	return false;
}
//
//SDL_Rect PositionComponent::getSDLRect()
//{
//	return SDL_Rect();
//}
