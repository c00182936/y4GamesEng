#pragma once
//#include <SDL.h>
#include <vector>
#include "Component.h"
class ControlComponent:public Component

{
public:
	ControlComponent();
	~ControlComponent();
	void Update();
	std::vector<int> inputVector;
	int getHealth() { return -1; };
	void loseHealth(int dmg) {};
};

