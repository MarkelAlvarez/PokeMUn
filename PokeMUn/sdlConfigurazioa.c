#include "funtzioak.h"
#include "irudiak.h"
/* VIDEOA */
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* HelloWorld = NULL;
/* AUDIOA */
Mix_Music *gMusic = NULL;

SDL_Rect sprite;
TTF_Font *font = 0;
PLAYER player;

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
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	//Initialize SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
	else
	{
		gMusic = Mix_LoadMUS(".\\Sounds\\fondo.wav");
		if( gMusic == NULL )
		{
			printf("Ezin izan da musika kargatu. SDL_mixer Error: %s\n", Mix_GetError() );
		}
		Mix_PlayMusic(gMusic, -1);

		window = SDL_CreateWindow("PokeMUn", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		HelloWorld = IMG_Load(ICON);
		SDL_SetWindowIcon(window, HelloWorld);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			hasieratua = 1;
		}
	}

	return hasieratua;
}

void textuaGaitu()
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
	SDL_Color textColor = { 0, 0, 0 };
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

void textuaDesgaitu()
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

void bukatu()
{ 
    //Free the music
    Mix_FreeMusic(gMusic);
    gMusic = NULL;
	//Deallocate surface
	SDL_FreeSurface(HelloWorld);
	HelloWorld = NULL;
	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;
	//Quit SDL subsystems
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

void jokuaHasi(int generoa)
{
	PLAYER menu;

	irudiaMugitu(player.id, 400, 200);
	player.pos.x = 400;
	player.pos.y = 200;
	menu.id = irudiaSortu(HASIERA_ETXEA);
	if (generoa == 1)
	{
		player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
		irudiaMugitu(player.id, 400, 200);
		player.pos.x = 400;
		player.pos.y = 200;
		irudiakMarraztu(SPRITE_PLAYER_ABAJOIZQ);
	}
	else if (generoa == 2)
	{
		player.id = irudiaSortu(PLAYER_ABAJOIZQ);
		irudiaMugitu(player.id, 400, 200);
		player.pos.x = 400;
		player.pos.y = 200;
		irudiakMarraztu(PLAYER_ABAJOIZQ);
	}
	SDL_RenderPresent(gRenderer);
	SDL_UpdateWindowSurface(window);
}