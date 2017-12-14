#include "ControlComponent.h"



ControlComponent::ControlComponent()
{
	type = "control";
	inputVector.reserve(40);
}


ControlComponent::~ControlComponent()
{

}

void ControlComponent::Update()
{
	//inputVector.clear();
	//SDL_Event e;
	//switch (e.type)
	//{

	//case SDL_KEYDOWN:
	//	switch (e.key.keysym.sym)
	//	{//take inputs and push them to the vector


	//	default:
	//		break;
	//	}
	//default:
	//	break;
	//}
}
