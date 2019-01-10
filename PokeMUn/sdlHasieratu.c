#include "funtzioak.h"
#include "irudiak.h"
//The window we'll be rendering to
SDL_Window* window = NULL;
//The surface contained by the window
SDL_Surface* screenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* HelloWorld = NULL;
SDL_Rect sprite;
TTF_Font *font = 0;

int SDLHasi()
{
	int hasieratua = 0;

	if (TTF_Init() < 0)
	{
		printf("SDL_TTF couldn't initialize!, SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		textuaGaitu();
	}
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

void textuaGaitu(void) 
{
	font = TTF_OpenFontIndex("C:\\Windows\\Fonts\\ARIAL.TTF", 20, 0);
	if (!font)
	{
		printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
	}
}

void textuaIdatzi(int x, int y, char *str)
{
	SDL_Surface* textSurface;
	SDL_Texture *mTexture;
	SDL_Color textColor = { 0, 0, 255 };
	SDL_Rect src, dst;

	if (font == 0)
	{
		textuaGaitu();
	}
	textSurface = TTF_RenderText_Blended(font, str, textColor);
	mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	src.x = 0; dst.x = x;
	src.y = 0; dst.y = y;
	src.w = dst.w = textSurface->w;
	src.h = dst.h = textSurface->h;
	SDL_RenderCopy(gRenderer, mTexture, &src, &dst);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(mTexture);
}

void textuaDesgaitu(void)
{
	if (font != 0)
	{
		TTF_CloseFont(font);
		font = 0;
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);
		irudiakMarraztu();
	}
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

	IRUDIAK_munduaIMG();
	player.id = IRUDIAK_spriteSortuAbI();
	
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
	TTF_Quit();
	SDL_Quit();
}

void denaHasi()
{

	player.pos.x = 320;
	player.pos.y = 240;
	if (!SDLHasi())
	{
		printf("\n Errorea egon da hasieratzean.");
		printf("\n %s", SDL_GetError());
	}
	else
	{
		jokuaHasi();
	}
}

void jokuaHasi()
{
	if (mediaKargatu())
	{
		printf("Errorea egon da media kargatzerakoan.");
		printf("\n %s", SDL_GetError());
	}
	else
	{
		lehioaAktualizatu();
	}
}

void lehioaAktualizatu()
{
	SDL_RenderPresent(gRenderer);
	SDL_UpdateWindowSurface(window);
}