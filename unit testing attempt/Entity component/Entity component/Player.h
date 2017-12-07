#pragma once
#include "ControlComponent.h"

#include <vector>
#include "Entity.h"

class Player :
	public Entity
{
public:
	Player();
	void removeComponent(Component *c);
	~Player();
};

