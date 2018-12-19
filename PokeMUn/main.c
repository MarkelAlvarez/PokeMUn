#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
	//The image we will load and show on the screen
	SDL_Surface* HelloWorld = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("PokeMUn", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			//Update the surface
			SDL_UpdateWindowSurface(window);
			//Wait two seconds
			SDL_Delay(2000);
			//Load BMP image
			HelloWorld = SDL_LoadBMP( "IMG/PokeMUn.bmp" );
		    if(HelloWorld == NULL)
		    {
		        printf( "Unable to load image %s! SDL Error: %s\n", "IMG/PokeMUn.bmp", SDL_GetError() );
		        //Si da error que salga de la aplicaion
		    }
		}
	}

	//Deallocate surface
    SDL_FreeSurface( HelloWorld );
    HelloWorld = NULL;
	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;
	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}