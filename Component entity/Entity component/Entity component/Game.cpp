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
	renderSys.addEntity(&player);
	renderSys.addEntity(&ayyLmao);
	renderSys.addEntity(&cade);
	renderSys.addEntity(&pupper);
	aiSys.addEntity(&ayyLmao);
	aiSys.addEntity(&pupper);
	aiSys.addEntity(&cade);
	healthSys.addEntity(&player);
	healthSys.addEntity(&ayyLmao);
	healthSys.addEntity(&cade);
	healthSys.addEntity(&pupper);
}

void Game::update()
{
	while (loop)
	{
		aiSys.Update();
		renderSys.Render();
		healthSys.Update();
		loop = false;
	}
}


Game::~Game()
{
}
