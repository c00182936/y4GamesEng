#pragma once
#include "Entity.h"
#include <iostream>
class ControlSystem
{
public:
	ControlSystem();
	std::vector<Entity*> entities;
	void addEntity(Entity*e) { entities.push_back(e); }
	void Update() { std::cout << "controls updated" << std::endl; }
	~ControlSystem();
};

