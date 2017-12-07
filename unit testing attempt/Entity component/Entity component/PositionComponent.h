#pragma once
//#include <SDL.h>
#include "Component.h"
class PositionComponent: public Component
{
public:
	PositionComponent();
	~PositionComponent();


	bool checkCollision(PositionComponent other);
	//SDL_Rect getSDLRect();
	float positionX;
	float positionY;
	float width;
	float height;
};

