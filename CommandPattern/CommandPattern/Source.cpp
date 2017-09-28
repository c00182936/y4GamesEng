

#include <iostream>
#include <SDL.h>
#include <stdio.h>
#undef main
using namespace std;


int main()
{
	int screenWidth=800;
	int screenHeight = 600;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Event e;
	int r=0, g=0, b=0;
	int *pr = &r, *pg = &g, *pb = &b;
	bool gameLoop = true;
	
	if (SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("could not initialize");
	}
	else
	{
		window = SDL_CreateWindow("tttttt", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (window == NULL) { printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); }
		else { //Get window surface 
			screenSurface = SDL_GetWindowSurface( window ); //Fill the surface white 
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, r, g, b ) ); //Update the surface 
			SDL_UpdateWindowSurface( window ); //Wait two seconds 
			SDL_Delay( 2000 ); }
	}
	while (gameLoop)
	{
		while (SDL_PollEvent(&e)!=0)
		{
			if (e.type == SDL_QUIT)
			{
				gameLoop = false;
			}
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
			if (currentKeyStates[SDL_SCANCODE_ESCAPE])
			{
				gameLoop = false;
			}
			if (currentKeyStates[SDL_SCANCODE_1])
			{

			}
			if (currentKeyStates[SDL_SCANCODE_2])
			{

			}
			if (currentKeyStates[SDL_SCANCODE_3])
			{

			}
			if (currentKeyStates[SDL_SCANCODE_Q])
			{

			}
			if (currentKeyStates[SDL_SCANCODE_W])
			{

			}
			if (currentKeyStates[SDL_SCANCODE_E])
			{

			}
			if (currentKeyStates[SDL_SCANCODE_LSHIFT])
			{
				if (currentKeyStates[SDL_SCANCODE_Z])
				{

				}
				if (currentKeyStates[SDL_SCANCODE_Y])
				{

				}
			}
		}




		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, r, g, b)); //Update the surface 
		SDL_UpdateWindowSurface(window); //Wait two seconds 
	}
	system("PAUSE");
	return 0;
}