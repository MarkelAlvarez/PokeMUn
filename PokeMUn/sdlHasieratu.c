#include "funtzioak.h"
#include "irudiak.h"
//The window we'll be rendering to
SDL_Window* window = NULL;
//The surface contained by the window
SDL_Surface* screenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* HelloWorld = NULL;
SDL_Rect sprite;

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
		gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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

int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest)
{
	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = pDest->w;
	src.h = pDest->h;
	SDL_RenderCopy(gRenderer, texture, &src, pDest);

	return 0;
}

int mediaKargatu()
{
	int hasieratua = 0;

	//Load BMP image
	//HelloWorld = SDL_LoadBMP(".\\img\\sprite.bmp");
	hasieratua = IRUDIAK_spriteSortu();
	if (hasieratua != NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", ".\\img\\sprite.bmp", SDL_GetError());
		hasieratua = 0;
	}

	return hasieratua;
}

void bukatu()
{
	//Deallocate surface
	SDL_FreeSurface(HelloWorld);
	HelloWorld = NULL;
	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;
	//Quit SDL subsystems
	SDL_Quit();
}

void denaHasi()
{
	if (!SDLHasi())
	{
		printf("\n Errorea egon da hasieratzean.");
		printf("\n %s", SDL_GetError());
	}
	else
	{
		if (mediaKargatu())
		{
			printf("\n Errorea egon da media kargatzerakoan.");
			printf("\n %s", SDL_GetError());
		}
		else
		{
			SDL_RenderPresent(gRenderer);
			SDL_UpdateWindowSurface(window);
		}
	}
}