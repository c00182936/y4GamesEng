#include "InputHandler.h"

void InputHandler::init()
{
	//nothing i do works, inheritance seems to just not like me at the moment
	redInc = new Inc;
}

void InputHandler::handleInput(int input, int* col)
{
	if (input == 1)
	{
		redInc->execute(col);
		undoBuffer.push_back(redInc);
	}
	else if (input == 2)
	{
		redDec->execute(col);
		undoBuffer.push_back(redDec);
	}
	else if (input == 3)
	{
		blueInc->execute(col);
		undoBuffer.push_back(blueInc);
	}
	else if (input == 4)
	{
		blueDec->execute(col);
		undoBuffer.push_back(blueDec);
	}
	else if (input == 5)
	{
		greenInc->execute(col);
		undoBuffer.push_back(greenInc);
	}
	else if (input ==6)
	{
		greenDec->execute(col);
		undoBuffer.push_back(greenDec);
	}
	else if (input == 7)
	{
		//undo
	}
	else if (input == 8)
	{
		//redo
	}
}
