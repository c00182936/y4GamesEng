#pragma once
#include "Entity.h"
#include "Player.h"
#include "HealthComponent.h"
#include "ControlComponent.h"
#include "PositionComponent.h"
#include "RenderSystem.h"
#include "AiSystem.h"
#include "Alien.h"
#include "Dog.h"
#include "Cat.h"
class Game
{
public:
	Game();
	void update();
	Player player;
	Alien ayyLmao;
	Dog pupper;
	Cat cade;

	~Game();
private:
	bool loop;

};

