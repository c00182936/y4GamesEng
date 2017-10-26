#pragma once
class PositionComponent
{
public:
	PositionComponent();
	~PositionComponent();


	bool checkCollision(PositionComponent other);
	
	float positionX;
	float positionY;
	float width;
	float height;
};

