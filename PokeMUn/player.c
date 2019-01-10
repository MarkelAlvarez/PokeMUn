#include "funtzioak.h"
#include "kontrolak.h"
#include "irudiak.h"

SDL_Event event;
POSIZIOA saguPos;
POSIZIOA saguarenPosizioa() { return saguPos; }
int ID_gim2;

void gim2Interakzioa()
{
		if (gim2Ireki(player) == SARTU)
		{
			ID_gim2 = IRUDIAK_gim2Sortu();
			irudiaKendu(player.id);
			player.pos.x = 310;
			player.pos.y = 369;
			player.id = IRUDIAK_spriteSortuAI();
			irudiaMugitu(player.id, player.pos.x, player.pos.y);
			SDL_RenderPresent(gRenderer);
		}
		else if (gim2Ireki(player) == IRTEN)
		{
			irudiaKendu(ID_gim2);
			IRUDIAK_munduaIMG();
			irudiaKendu(player.id);
			player.pos.x = 70;
			player.pos.y = 386;
			player.id = IRUDIAK_spriteSortuAbI();
			irudiaMugitu(player.id, player.pos.x, player.pos.y);
			SDL_RenderPresent(gRenderer);
		}
}

int gim2Ireki(PLAYER player)
{
	int ret = 0;

	if ((player.pos.y <= 388 && player.pos.y >= 370) && (player.pos.x >= 63 && player.pos.x <= 79))
	{
		ret = SARTU;
	}
	else
	{
		if ((player.pos.y >= 310 && player.pos.y <= 320) && (player.pos.x >= 350 && player.pos.x <= 374))
		{
			ret = IRTEN;
		}
	}

	return ret;
}

void etxearekikoInterakzioa()
{
	if (etxeaIreki(player) == SARTU)
	{
		IRUDIAK_hasieraEtxeaSortu();
		irudiaKendu(player.id);
		player.pos.x = 280;
		player.pos.y = 315;
		player.id = IRUDIAK_spriteSortuAI();
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		SDL_RenderPresent(gRenderer);
	}
	else if (etxeaIreki(player) == IRTEN)
	{
		IRUDIAK_munduaIMG();
		irudiaKendu(player.id);
		player.pos.x = 564;
		player.pos.y = 382;
		player.id = IRUDIAK_spriteSortuAbI();
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		SDL_RenderPresent(gRenderer);
	}
}

int etxeaIreki(PLAYER player)
{
	int ret = 0;

	if ((player.pos.y <= 390 && player.pos.y >= 375) && (player.pos.x >= 552 && player.pos.x <=570))
	{
		ret = SARTU;
	}
	else
	{
		if ((player.pos.y >= 370 && player.pos.y <= 380) && (player.pos.x >= 260 && player.pos.x <= 285))
		{
			ret = IRTEN;
		}
	}

	return ret;
}

int pausaMenua()
{
	int egoera, id, ret;

	id = IRUDIAK_pauseIMG();
	do
	{
		egoera = ebentuaJasoGertatuBada();
		SDL_RenderPresent(gRenderer);
	} while (egoera != TECLA_ESCAPE && egoera != TECLA_ENTER);
	if (egoera == TECLA_ESCAPE)
	{
		ret = GAME_OVER;
	}
	else if(egoera == TECLA_ENTER)
	{
		ret = JOLASTEN;
	}
	pantailaGarbitu();
	irudiaKendu(id);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	return ret;
}

POSIZIOA movePlayer(int signX, int signY)
{
	POSIZIOA aux;

	aux = player.pos;
	aux.x = player.pos.x + (7 * signX);
	aux.y = player.pos.y + (7 * signY);

	return aux;
}

int ebentoaDetektatu(int ebentoa)
{
	int signX, signY, egoera = JOLASTEN;

	if (ebentoa == TECLA_w)
	{
		signX = 0;
		signY = -1;
		pantailaGarbitu();
		irudiaKendu(player.id);
		player.id = IRUDIAK_spriteSortuAI();
		player.pos = movePlayer(0, -1);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_a)
	{
		signX = -1;
		signY = 0;
		pantailaGarbitu();
		irudiaKendu(player.id);
		player.id = IRUDIAK_spriteSortuII();
		player.pos = movePlayer(-1, 0);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_s)
	{
		signX = 0;
		signY = 1;
		pantailaGarbitu();
		irudiaKendu(player.id);
		player.id = IRUDIAK_spriteSortuAbI();
		player.pos = movePlayer(0, 1);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_d)
	{
		signX = 1;
		signY = 0;
		pantailaGarbitu();
		irudiaKendu(player.id);
		player.id = IRUDIAK_spriteSortuDI();
		player.pos = movePlayer(1, 0);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_e)
	{
		etxearekikoInterakzioa();
		gim2Interakzioa();
	}
	if (ebentoa == TECLA_SPACE)
	{
		textuaIdatzi(100, 200, "ESTO TIRA");
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_ENTER)
	{
		textuaDesgaitu();
		SDL_RenderPresent(gRenderer);
	}
	if(ebentoa==TECLA_ESCAPE)
	{
		egoera = pausaMenua();
	}

	return egoera;
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
				ret = TECLA_ESCAPE;
				break;
			case SDLK_RETURN:
				ret = TECLA_ENTER;
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