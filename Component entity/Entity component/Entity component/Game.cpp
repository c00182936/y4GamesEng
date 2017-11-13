#include "Game.h"



Game::Game()
{
	HealthComponent health;
	PositionComponent position;
	player.addComponent(&health);
	player.addComponent(&position);
}

void Game::update()
{
	while (loop)
	{

		loop = false;
	}
}


Game::~Game()
{
}
