#pragma once
#include "ComponentTypes.h"
#include "Component.h"
#include <vector>
class Entity
{
	int id;
public:

	virtual ~Entity()=0;
	void addComponent(Component *c) { components.push_back(c); }
	virtual void removeComponent(Component *c) = 0;
	std::vector<Component*> components;
private:

};
