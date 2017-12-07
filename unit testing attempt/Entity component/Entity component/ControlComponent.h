#pragma once
//#include <SDL.h>
#include <vector>
class ControlComponent

{
public:
	ControlComponent();
	~ControlComponent();
	void Update();
	std::vector<int> inputVector;
};

