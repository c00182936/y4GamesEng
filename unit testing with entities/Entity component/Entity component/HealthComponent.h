#pragma once
#include "Component.h"
class HealthComponent:public Component
{
public:
	HealthComponent() { type = "health"; };
	HealthComponent(int h) { health = h; type = "health";
	};
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
	int getHealth() { return health; };
	
};

