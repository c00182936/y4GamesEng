#pragma once
#include "Entity.h"
#include "Player.h"
#include "HealthComponent.h"
#include "HealthSystem.h"
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
	AiSystem aiSys;
	RenderSystem renderSys;
	HealthSystem healthSys;
	~Game();
private:
	bool loop=true;

};

