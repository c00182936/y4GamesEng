#pragma once
#include <vector>
#include "Entity.h"
#include <iostream>
class HealthSystem
{
public:
	HealthSystem();
	std::vector<Entity*> entities;
	void addEntity(Entity*e) { entities.push_back(e); }
	void Update()
	{std::cout << "health updated" << std::endl; }
	~HealthSystem();
};

