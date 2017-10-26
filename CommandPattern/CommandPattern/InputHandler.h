#pragma once
#include "command.h"
#include <vector>
class InputHandler
{
private:
	Command* redInc;
	Command* redDec;
	Command*blueInc;
	Command*blueDec;
	Command*greenInc;
	Command*greenDec;


	std::vector<Command*> undoBuffer;
	

public:
	InputHandler() { undoBuffer.reserve(16); };
	void init();
	~InputHandler();
	void handleInput(int input, int* col);

};
