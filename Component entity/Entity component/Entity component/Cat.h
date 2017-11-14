#pragma once
#include "Entity.h"
class Cat :public Entity
{
public:
	Cat();
	void removeComponent(Component *c);
	~Cat();
};

