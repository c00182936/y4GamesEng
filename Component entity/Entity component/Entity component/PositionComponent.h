#pragma once
#include <SDL.h>
class PositionComponent
{
public:
	PositionComponent();
	~PositionComponent();


	bool checkCollision(PositionComponent other);
	SDL_Rect getSDLRect();
	float positionX;
	float positionY;
	float width;
	float height;
};

