#include"SDLHasieratu.h"
#include "irudiak.h"
#include "funtzioak.h"
#include "kontrolak.h"
#include "menua.h"

int hasierakomenu() 
{
	POSIZIOA saguPos;
	saguPos = saguarenPosizioa();
	int tt = 0;
	int ebentu = 0;
	int egoera;
	int ID_menua, ID_menuJokatu, ID_menuKontrolak, ID_menuKreditoak;

	pantailaGarbitu();
	ID_menua = irudiaSortu(MENU);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	do {
		ebentu = ebentuaJasoGertatuBada();
		saguPos = saguarenPosizioa();
		if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 159) && (saguPos.y < 213) && (tt != 1)) {
			pantailaGarbitu();
			ID_menuJokatu = irudiaSortu(MENU_JOKATU);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			tt = 1;
		}
		if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 236) && (saguPos.y < 289) && (tt != 2)) {
			pantailaGarbitu();
			ID_menuKontrolak = irudiaSortu(MENU_KONTROLAK);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			tt = 2;
		}
		if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 313) && (saguPos.y < 366) && (tt != 3)) {
			pantailaGarbitu();
			ID_menuKreditoak = irudiaSortu(MENU_KREDITOAK);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			tt = 3;
		}

	} while (ebentu != SAGU_BOTOIA_EZKERRA);

	if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 159) && (saguPos.y < 213)) //jokatu
	{
		egoera = JOLASTEN;
		irudiaKendu(ID_menua);
		irudiaKendu(ID_menuJokatu);
	}
	else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 236) && (saguPos.y < 289))//kontrolak
	{
		egoera = GAME_OVER;
		irudiaKendu(ID_menua);
	}
	else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 313) && (saguPos.y < 366))//kreditoak
	{
		egoera = GAME_OVER;
		irudiaKendu(ID_menua);
	}
	else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 309) && (saguPos.x < 365) && (saguPos.y > 385) && (saguPos.y < 435))//etxea
	{
		egoera = GAME_OVER;
		irudiaKendu(ID_menua);
	}

	return egoera;

}

int pertsonaiaAukeratu()
{
	int ikutu = 0;

	do
	{
		ANIMAZIOAK_menuPertsonaiak();
		ikutu = HITBOX_menuPertsonaiak();
		
	} while (ikutu == 0);
}

int HITBOX_menuPertsonaiak()
{
	int ebentua, ikutu = 0;
	POSIZIOA saguPos;

	saguPos = saguarenPosizioa();
	ebentua = ebentuaJasoGertatuBada();
	if (ebentua == SAGU_BOTOIA_EZKERRA)
	{
		if ((saguPos.x >= 139 && saguPos.x <= 233) && (saguPos.y >= 161 && saguPos.y <= 319))//NESKA
		{
			ikutu = 1;
		}
		else if ((saguPos.x >= 425 && saguPos.x <= 507) && (saguPos.y >= 161 && saguPos.y <= 319))//MUTILA
		{
			ikutu = 2;
		}
	}

	return ikutu;
}

void ANIMAZIOAK_menuPertsonaiak()
{
	int ID_pertsonaiMenua, ebentua, ID_pertsonaiaAukeratu = 0, ikutu = 0, aux = 0;
	POSIZIOA saguPos;

	ID_pertsonaiMenua = irudiaSortu(PERTSONAI_MENUA);
	ebentua = ebentuaJasoGertatuBada();
	saguPos = saguarenPosizioa();
	if ((saguPos.x >= 139 && saguPos.x <= 233) && (saguPos.y >= 161 && saguPos.y <= 319))
	{
		ID_pertsonaiaAukeratu = irudiaSortu(PERTSONAIA_AUKERATU);
		irudiaMugitu(ID_pertsonaiaAukeratu, 120, 160);
		irudiakMarraztu();
		//aux aldagaia erabiliko dugu behin xagua hitboxatik kenduta pertsonaia inguratzen duen zati gorriak kentzeko
		aux = 1;
		irudiaKendu(ID_pertsonaiMenua);
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
		ID_pertsonaiaAukeratu = irudiaSortu(PERTSONAIA_AUKERATU);
		irudiaMugitu(ID_pertsonaiaAukeratu, 403, 160);
		irudiakMarraztu();
		irudiaKendu(ID_pertsonaiaAukeratu);
		aux = 2;
		irudiaKendu(ID_pertsonaiMenua);
	}
	else if (aux == 2)
	{
		irudiaKendu(ID_pertsonaiaAukeratu);
		//SDL_RenderPresent(gRenderer);
		aux = 0;
	}
	SDL_RenderPresent(gRenderer);
}