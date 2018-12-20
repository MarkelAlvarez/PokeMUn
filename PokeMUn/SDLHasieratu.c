#include "funtzioak.h"
#include "SDLHasieratu.h"

void punteroak()
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
	//The image we will load and show on the screen
	SDL_Surface* HelloWorld = NULL;
}

int SDLHasi()
{
	int hasieratua = 0;

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
			hasieratua = 1;
		}
	}

	return hasieratua;
}

int mediaKargatu()
{
	int hasieratua = 1;

	//Load BMP image
	HelloWorld = SDL_LoadBMP("IMG/PokeMUn.bmp");
	if (HelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", ".\\IMG\\PokeMUn.bmp", SDL_GetError());
		hasieratua = 0;
	}

	return hasieratua;	
}

void bukatu()
{
	//Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    HelloWorld = NULL;
    //Destroy window
    SDL_DestroyWindow( gWindow );
    Window = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}