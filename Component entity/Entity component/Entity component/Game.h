#pragma once
#include "Entity.h"
#include "Player.h"
#include "HealthComponent.h"
#include "ControlComponent.h"
#include "PositionComponent.h"
#include "RenderSystem.h"

class Game
{
public:
	Game();
	void update();
	Player player;
	

	~Game();
private:
	bool loop;

};

