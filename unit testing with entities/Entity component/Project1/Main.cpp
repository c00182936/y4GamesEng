
#include "..\Entity component\Entity.h"
#include "..\Entity component\Player.h"
#include "..\Entity component\HealthComponent.h"
#include "..\Entity component\HealthSystem.h"
#include "..\Entity component\ControlComponent.h"
#include "..\Entity component\PositionComponent.h"
#include "..\Entity component\RenderSystem.h"
#include "..\Entity component\AiSystem.h"
#include "..\Entity component\Alien.h"
#include "..\Entity component\Dog.h"
#include "..\Entity component\Cat.h"

#include<iostream>
#include <assert.h>
#define NDEBUG
#include <cassert>
Player player;
Alien ayyLmao;
Dog pupper;
Cat cade;
AiSystem aiSys;
RenderSystem renderSys;
HealthSystem healthSys;
bool preUpdate;
HealthComponent health100(100);
void testCases()
{
	if (healthSys.entities.size() <= 3)
	{
		assert(renderSys.entities.size() <= 3);
		printf("%d %s %d \n", renderSys.entities.size(), "rendersys should have: ", 4);
	}
	//if (health100.health == 100)
	//{
	//	assert(health100.health);
	//	printf("%d %s")
	//}
	int tempI;
	tempI=pupper.findEntity("health");
	if (pupper.components[tempI]->getHealth() != 100)
	{
		assert(pupper.components[tempI]->getHealth() != 100);
		printf("%d %s %d \n", pupper.components[tempI]->getHealth(), "Should be: ", 100);
	}
	if (preUpdate == false)
	{
	if (renderSys.entities.size() != renderSys.TimesRendered)
	{
		assert(renderSys.entities.size() != renderSys.TimesRendered);
		printf("%d %s %d \n", renderSys.TimesRendered, "these should be equal", renderSys.entities.size());
	}

	pupper.components[tempI]->loseHealth(1);
	if (pupper.components[tempI]->getHealth() == 100)
	{
		assert(pupper.components[tempI]->getHealth() == 100);
		printf("%d %s %d \n", pupper.components[tempI]->getHealth(), "ERROR: Should be after decrementing: ", 99);//this one will fail, lose health doesn't do anything

	}


	}






}

#ifndef main()

#undef main()

int main()
{

	preUpdate = true;

	HealthComponent health;
	PositionComponent position;

	player.addComponent(&health);
	player.addComponent(&position);
	ayyLmao.addComponent(&health);
	ayyLmao.addComponent(&position);
	pupper.addComponent(&health100);
	pupper.addComponent(&position);
	//alien=ayylmao
	//pupper=dog
	//cade=cat
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
	testCases();
	renderSys.Render();
	preUpdate = false;
	testCases();

	system("PAUSE");
	return 0;
}
#endif // !1

