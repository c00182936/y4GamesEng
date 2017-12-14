#pragma once
#include "ComponentTypes.h"
#include "Component.h"
#include <vector>
class Entity
{
	int id;
public:

	~Entity() {};
	void addComponent(Component *c) { components.push_back(c); }
	virtual void removeComponent(Component *c) = 0;
	std::vector<Component*> components;
	int findEntity(std::string ent) {
		for (int i=0; i < components.size(); i++) { if (components[i]->type == ent) { return i; } }
	};


private:

};
