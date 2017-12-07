#pragma once
#include "Component.h"
class HealthComponent:public Component
{
public:
	HealthComponent();

	~HealthComponent();
	int health;
	int shield;
	int lives;
	void loseHealth(int dmg);
	void loseLife();
	void incHealth();
	int maxHealth;
	int maxShield;
	int maxLife;
};

