#include "funtzioak.h"
#include "kontrolak.h"
#define R 30

SDL_Event event;
PLAYER player;
SDL_Renderer* gRenderer;

void karratuaMarraztu(int x, int y)
{
	SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255); // Yellow color
	SDL_Rect rect = { x, y, 50, 50 }; // {x, y, width, height}
	SDL_RenderFillRect(gRenderer, &rect);
	SDL_RenderPresent(gRenderer);
}

POSIZIOA movePlayer(int signX, int signY)
{
	POSIZIOA aux;
	aux.x = player.pos.x + (15 * signX);
	aux.y = player.pos.y + (15 * signY);

	return aux;
}

void ebentoaDetektatu(int ebentoa)
{

	if (ebentoa == TECLA_w)
	{
		//Bi lerro hauek pantaila garbitzeko
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);

		player.pos = movePlayer(1, 1);
		karratuaMarraztu(player.pos.x, player.pos.y);
	}
	if (ebentoa == TECLA_a)
	{
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);

		player.pos = movePlayer(-1, 1);
		karratuaMarraztu(player.pos.x, player.pos.y);
	}
	if (ebentoa == TECLA_s)
	{
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);

		player.pos = movePlayer(-1, -1);
		karratuaMarraztu(player.pos.x, player.pos.y);
	}
	if (ebentoa == TECLA_d)
	{
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);

		player.pos = movePlayer(1, -1);
		karratuaMarraztu(player.pos.x, player.pos.y);
	}
}

int randomColor()
{
	rngGenerator(1, 255);
}

int rngGenerator(int min, int max)
{
	int rng;

	rng = min + rand() % max;

	return rng;
}

int ebentuaJasoGertatuBada()
{
	int ret = 0;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				ret = TECLA_w;
				break;
			case SDLK_d:
				ret = TECLA_d;
				break;
			case SDLK_a:
				ret = TECLA_a;
				break;
			case SDLK_s:
				ret = TECLA_s;
				break;
			case SDLK_ESCAPE:
				ret = -1;
				break;
			default:
				ret = event.key.keysym.sym;
				break;
			}
			break;
		case SDL_QUIT:
			ret = GERTAERA_IRTEN;
			break;
		}
	}
	return ret;
}