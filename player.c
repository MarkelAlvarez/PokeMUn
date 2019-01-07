#include "funtzioak.h"
#include "kontrolak.h"
#include "irudiak.h"
#define R 30

SDL_Event event;
PLAYER player;
POSIZIOA saguPos;
SDL_Renderer* gRenderer;
POSIZIOA saguarenPosizioa() { return saguPos; }

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

		player.pos = movePlayer(0, -1);
		//karratuaMarraztu(player.pos.x, player.pos.y);
		irudiaMugitu(0, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);

	}
	if (ebentoa == TECLA_a)
	{
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);

		player.pos = movePlayer(-1, 0);
		//karratuaMarraztu(player.pos.x, player.pos.y);
		irudiaMugitu(0, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_s)
	{
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);

		player.pos = movePlayer(0, 1);
		//karratuaMarraztu(player.pos.x, player.pos.y);
		irudiaMugitu(0, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_d)
	{
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);

		player.pos = movePlayer(1, 0);
		//karratuaMarraztu(player.pos.x, player.pos.y);
		irudiaMugitu(0, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
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
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				ret = SAGU_BOTOIA_EZKERRA;
				break;
			case SDL_BUTTON_RIGHT:
				ret = SAGU_BOTOIA_ESKUMA;
				break;
			default:
				ret = event.button.button;
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			//ALDAGIA OROKOR BATEN EZARRIK ODUGU X ETA Y GERO FUNZTIO BATEKIN IRAKURTZEKO AZKEN EBENTUAREN POSIZIOA
			saguPos.x = event.motion.x;
			saguPos.y = event.motion.y;
			ret = SAGU_MUGIMENDUA;
			break;

		}
	}
	return ret;
}
