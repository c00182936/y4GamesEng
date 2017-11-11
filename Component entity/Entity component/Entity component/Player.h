#pragma once
#include "ControlComponent.h"
#include "GameObject.h"
#include "HealthComponent.h"
#include "RenderComponent.h"
#include "PositionComponent.h"
class Player :
	public GameObject
{
public:
	Player();
	HealthComponent health;
	RenderComponent renderer;
	ControlComponent control;
	PositionComponent position;

	~Player();
};

