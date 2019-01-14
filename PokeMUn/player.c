#include "funtzioak.h"
#include "kontrolak.h"
#include "irudiak.h"

SDL_Event event;
POSIZIOA saguPos;
POSIZIOA saguarenPosizioa() { return saguPos; }
int ID_gim2;
PLAYER player;
GYM gimnasioak[5]; 
//NOTA: FUNTZIO BAT GIMNASIOAK HASIERATZEKO

int gim3Interakzioa()
{
	int interakzioa = 0;

	if (gim3Ireki(player) == SARTU)
	{
		irudiaSortu(GIM3);
		irudiaKendu(player.id);
		player.pos.x = 285;
		player.pos.y = 325;
		player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		interakzioa = 1;
	}
	else if (gim3Ireki(player) == IRTEN)
	{
		irudiaSortu(MUNDUA);
		irudiaKendu(player.id);
		player.pos.x = 198;
		player.pos.y = 193;
		player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		interakzioa = 1;
	}
}

int gim3Ireki()
{
	int ret = 0;

	if ((player.pos.y <= 135 && player.pos.y >= 126) && (player.pos.x >= 497 && player.pos.x <= 505))
	{
		ret = SARTU;
	}
	else
	{
		if ((player.pos.y >= 1350 && player.pos.y <= 1260) && (player.pos.x >= 497 && player.pos.x <= 505))
		{
			ret = IRTEN;
		}
	}

	return ret;
}

int gim1Interakzioa()
{
	int interakzioa = 0;

	if (gim1Ireki(player) == SARTU)
	{
		irudiaSortu(GIM1);
		irudiaKendu(player.id);
		player.pos.x = 285;
		player.pos.y = 325;
		player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		interakzioa = 1;
	}
	else if (gim1Ireki(player) == IRTEN)
	{
		irudiaSortu(MUNDUA);
		irudiaKendu(player.id);
		player.pos.x = 198;
		player.pos.y = 193;
		player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		interakzioa = 1;
	}
}

int gim1Ireki()
{
	int ret = 0;

	if ((player.pos.y <= 203 && player.pos.y >= 193) && (player.pos.x >= 188 && player.pos.x <= 217))
	{
		ret = SARTU;
	}
	else
	{
		if ((player.pos.y >= 385 && player.pos.y <= 395) && (player.pos.x >= 305 && player.pos.x <= 337))
		{
			ret = IRTEN;
		}
	}

	return ret;
}

int gim4Interakzioa()
{
	int interakzioa = 0;

	if (gim4Ireki(player) == SARTU)
	{
		irudiaSortu(GIM4);
		irudiaKendu(player.id);
		player.pos.x = 285;
		player.pos.y = 325;
		player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		interakzioa = 1;
	}
	else if (gim4Ireki(player) == IRTEN)
	{
		irudiaSortu(MUNDUA);
		irudiaKendu(player.id);
		player.pos.x = 80;
		player.pos.y = 123;
		player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		interakzioa = 1;
	}

	return interakzioa;
}

int gim4Ireki()
{
	int ret = 0;

	if ((player.pos.y <= 127 && player.pos.y >= 119) && (player.pos.x >= 76 && player.pos.x <= 91))
	{
		ret = SARTU;
	}
	else
	{
		if ((player.pos.y >= 316 && player.pos.y <= 339) && (player.pos.x >= 300 && player.pos.x <= 320))
		{
			ret = IRTEN;
		}
	}

	return ret;
}

int gim2Interakzioa()
{
	int interakzioa = 0;

		if (gim2Ireki(player) == SARTU)
		{
			ID_gim2 = irudiaSortu(GIM2);
			irudiaKendu(player.id);
			player.pos.x = 310;
			player.pos.y = 369;
			player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
			irudiaMugitu(player.id, player.pos.x, player.pos.y);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			interakzioa = 1;
		}
		else if (gim2Ireki(player) == IRTEN)
		{
			irudiaKendu(ID_gim2);
			irudiaSortu(MUNDUA);
			irudiaKendu(player.id);
			player.pos.x = 63;
			player.pos.y = 379;
			player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
			irudiaMugitu(player.id, player.pos.x, player.pos.y);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			interakzioa = 1;
		}

		return interakzioa;
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
		if ((player.pos.x >= 310 && player.pos.x <= 320) && (player.pos.y >= 360 && player.pos.y <= 374))
		{
			ret = IRTEN;
		}
	}

	return ret;
}

int etxearekikoInterakzioa()
{
	int interakzioa = 0;

	if (etxeaIreki(player) == SARTU)
	{
		irudiaSortu(HASIERA_ETXEA);
		irudiaKendu(player.id);
		player.pos.x = 268;
		player.pos.y = 312;
		player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		interakzioa = 1;
	}
	else if (etxeaIreki(player) == IRTEN)
	{
		irudiaSortu(MUNDUA);
		irudiaKendu(player.id);
		player.pos.x = 564;
		player.pos.y = 382;
		player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		interakzioa = 1;
	}

	return interakzioa;
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
		if ((player.pos.y >= 300 && player.pos.y <= 310) && (player.pos.x >= 260 && player.pos.x <= 285))
		{
			ret = IRTEN;
		}
	}

	return ret;
}

int pausaMenua()
{
	int egoera, id, ret;

	id = irudiaSortu(PAUSE);
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
		player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
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
		player.id = irudiaSortu(SPRITE_PLAYER_IZQIZQ);
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
		player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
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
		player.id = irudiaSortu(SPRITE_PLAYER_DERIZQ);
		player.pos = movePlayer(1, 0);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_e)
	{
		if (etxearekikoInterakzioa() == 1);
		else if (gim1Interakzioa() == 1);
		else if (gim2Interakzioa() == 1);
		else if (gim3Interakzioa() == 1);
		else if (gim4Interakzioa() == 1);
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