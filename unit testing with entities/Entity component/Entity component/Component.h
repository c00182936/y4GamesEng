#pragma once
#include <string>
class Component
{
public:
	Component();
	~Component();
	std::string type;
	virtual int getHealth() = 0;
	virtual void loseHealth(int dmg)=0;
};
