#pragma once
#include "Entity.h"
class Dog:public Entity
{
public:
	Dog();
	void removeComponent(Component *c);
	~Dog();
};

