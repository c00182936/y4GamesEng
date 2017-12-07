#pragma once
#include "Entity.h"
class Alien:public Entity
{
public:
	Alien();
	void removeComponent(Component *c);
	~Alien();
};

