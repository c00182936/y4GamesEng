#include "Alien.h"



Alien::Alien()
{
}

void Alien::removeComponent(Component * c)
{
	for (size_t i = 0; i < components.size(); i++)
	{
		if (components[i] == c)
		{
			components.erase(components.begin() + i - 1);
			break;
		}
	}
}
Alien::~Alien()
{
}
