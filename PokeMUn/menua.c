#include"SDLHasieratu.h"
#include "irudiak.h"
#include "funtzioak.h"
#include "kontrolak.h"
#include "menua.h"

PLAYER player;
int pausa = 0;

int hasierakomenu(PLAYER menu)
{
	Mix_Music *gMusic = NULL;
	//PLAYER menu;
	POSIZIOA saguPos;
	saguPos = saguarenPosizioa();
	int ebentu = 0, generoa = 0, egoera = 0, kargatu = 0;

	pantailaGarbitu();
	ebentu = ebentuaJasoGertatuBada();
	saguPos = saguarenPosizioa();
	if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 159) && (saguPos.y < 213))
	{
		irudiaKendu(menu.id);
		pantailaGarbitu();
		menu.id = irudiaSortu(KARGATU);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		kargatu = kargatzekoMenua();
		if (kargatu == 1)//PARTIDA BERRIA
		{
			kargatuta = 1;
			player.generoa = pertsonaiaAukeratu();
			playerHasieratu();
			jokuaHasi(generoa);
			SDL_RenderPresent(gRenderer);
			do {
				ebentu = ebentuaJasoGertatuBada();
				egoera = ebentoaDetektatu(ebentu);
			} while (egoera != GAME_OVER);
		}
		else if (kargatu == 2)//KARGATU
		{
			do {
				ebentu = ebentuaJasoGertatuBada();
				egoera = ebentoaDetektatu(ebentu);
			} while (egoera != GAME_OVER);
		}
	}
	pantailaGarbitu();
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);
	if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 236) && (saguPos.y < 289))
	{
		do
		{
			irudiaKendu(menu.id);
			pantailaGarbitu();
			menu.id = irudiaSortu(KONTROLAK);
			pantailaGarbitu();
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != SAGU_BOTOIA_EZKERRA);
		irudiaKendu(menu.id);
		menu.id = irudiaSortu(MENU);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 313) && (saguPos.y < 366))
	{
		do
		{
			irudiaKendu(menu.id);
			pantailaGarbitu();
			menu.id = irudiaSortu(KREDITOAK);
			pantailaGarbitu();
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != SAGU_BOTOIA_EZKERRA);
		irudiaKendu(menu.id);
		menu.id = irudiaSortu(MENU);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 20) && (saguPos.x < 95) && (saguPos.y > 407) && (saguPos.y < 470))
	{
		//If the music is paused
		if ((Mix_PausedMusic() == 1) && (ebentu == SAGU_BOTOIA_EZKERRA))
		{
			//Resume the music
			Mix_ResumeMusic();
			pausa = 0;
			irudiaKendu(menu.id);
			menu.id = irudiaSortu(MENU);
			pantailaGarbitu();
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
		}
		//If the music is playing
		else
		{
			if (ebentu == SAGU_BOTOIA_EZKERRA)
			{
				//Pause the music
				Mix_PauseMusic();
				irudiaKendu(menu.id);
				menu.id = irudiaSortu(MENUMUTE);
				pantailaGarbitu();
				irudiakMarraztu();
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 309) && (saguPos.x < 365) && (saguPos.y > 385) && (saguPos.y < 435))
	{
		egoera = GAME_OVER;
	}


	return egoera;
}

int kargatzekoMenua()
{
	POSIZIOA saguPos;
	int ebentoa, kargatu = 0;

	do
	{
		ebentoa = ebentuaJasoGertatuBada();
		saguPos = saguarenPosizioa();
		if (ebentoa == SAGU_BOTOIA_EZKERRA)
		{
			if ((saguPos.x >= 169 && saguPos.x <= 265) && (saguPos.y >= 196 && saguPos.y <= 285))
			{
				kargatu = 1; //PARTIDA BERRIA
			}
			else if ((saguPos.x >= 406 && saguPos.x <= 503) && (saguPos.y >= 196 && saguPos.y <= 285))
			{
				kargatu = 2; //KARGATU
			}
		}
	} while (kargatu == 0);

	return kargatu;
}

int pertsonaiaAukeratu()
{
	POSIZIOA saguPos;
	PLAYER menu;
	int generoa = 0;

	menu.id = irudiaSortu(PERTSONAIA_MENUA);
	saguPos = saguarenPosizioa();
	do
	{
		ANIMAZIOAK_menuPertsonaiak();
		generoa = HITBOX_menuPertsonaiak();
	} while (generoa == 0);

	return generoa;
}

int HITBOX_menuPertsonaiak()
{
	int ebentua, generoa = 0;
	POSIZIOA saguPos;

	saguPos = saguarenPosizioa();
	ebentua = ebentuaJasoGertatuBada();
	if (ebentua == SAGU_BOTOIA_EZKERRA)
	{
		if ((saguPos.x >= 139 && saguPos.x <= 233) && (saguPos.y >= 161 && saguPos.y <= 319))
		{
			generoa = 1; //NESKA
		}
		else if ((saguPos.x >= 425 && saguPos.x <= 507) && (saguPos.y >= 161 && saguPos.y <= 319))
		{
			generoa = 2; //MUTILA
		}
	}

	return generoa;
}

void ANIMAZIOAK_menuPertsonaiak()
{
	POSIZIOA saguPos;
	PLAYER menu;
	int ebentua, ID_pertsonaiaAukeratu = 0, ikutu = 0, aux = 0;

	ebentua = ebentuaJasoGertatuBada();
	saguPos = saguarenPosizioa();
	if ((saguPos.x >= 139 && saguPos.x <= 233) && (saguPos.y >= 161 && saguPos.y <= 319))
	{
		menu.id = irudiaSortu(PERTSONAIA_MENUA);
		ID_pertsonaiaAukeratu = irudiaSortu(PERTSONAIA_AUKERATU);
		irudiaMugitu(ID_pertsonaiaAukeratu, 120, 160);
		irudiakMarraztu();
		//aux aldagaia erabiliko dugu behin xagua hitboxatik kenduta pertsonaia inguratzen duen zati gorriak kentzeko
		aux = 1;
		irudiaKendu(menu.id);
		SDL_RenderPresent(gRenderer);
	}
	else if (aux == 1)
	{
		irudiaKendu(ID_pertsonaiaAukeratu);
		SDL_RenderPresent(gRenderer);
		aux = 0;
	}
	else if ((saguPos.x >= 425 && saguPos.x <= 507) && (saguPos.y >= 161 && saguPos.y <= 319))
	{
		menu.id = irudiaSortu(PERTSONAIA_MENUA);
		ID_pertsonaiaAukeratu = irudiaSortu(PERTSONAIA_AUKERATU);
		irudiaMugitu(ID_pertsonaiaAukeratu, 403, 160);
		irudiakMarraztu();
		irudiaKendu(ID_pertsonaiaAukeratu);
		aux = 2;
		irudiaKendu(menu.id);
	}
	else if (aux == 2)
	{
		irudiaKendu(ID_pertsonaiaAukeratu);
		aux = 0;
	}
	SDL_RenderPresent(gRenderer);
}
