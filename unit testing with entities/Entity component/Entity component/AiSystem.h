#pragma once
#include "Entity.h"
#include <vector>
#include <iostream>
class AiSystem
{
public:
	AiSystem();
	std::vector<Entity*> entities;
	void addEntity(Entity*e) { entities.push_back(e); }
	void Update() { std::cout << "ai updated" << std::endl; }
	~AiSystem();
};

