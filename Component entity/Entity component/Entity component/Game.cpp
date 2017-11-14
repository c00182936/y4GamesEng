#include "Game.h"



Game::Game()
{
	HealthComponent health;
	PositionComponent position;
	player.addComponent(&health);
	player.addComponent(&position);
	ayyLmao.addComponent(&health);
	ayyLmao.addComponent(&position);
	pupper.addComponent(&health);
	pupper.addComponent(&position);

	cade.addComponent(&health);
	cade.addComponent(&position);
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
