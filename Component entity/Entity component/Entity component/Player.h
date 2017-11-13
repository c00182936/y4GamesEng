#pragma once
#include "ControlComponent.h"

#include "HealthComponent.h"
#include "Entity.h"
#include "PositionComponent.h"
class Player :
	public Entity
{
public:
	Player();
	HealthComponent health;

	ControlComponent control;
	PositionComponent position;
	void removeComponent(Component *c);
	~Player();
};

