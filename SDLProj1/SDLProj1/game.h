#pragma once
#include <string>
class game
{
public:
	game();
	void Initialize(std::string a, int b, int c, int d, int e, std::string f);
	void HandleEvents();
	void Update();
	void Render();
	bool isRunning();
	void Cleanup();
	~game();
};

