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
	ID_menua = irudiaKargatu(MENU);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	do {
		ebentu = ebentuaJasoGertatuBada();
		saguPos = saguarenPosizioa();
		if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 159) && (saguPos.y < 213) && (tt != 1)) {
			pantailaGarbitu();
			ID_menuJokatu = irudiaKargatu(MENU_JOKATU);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			tt = 1;
		}
		if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 236) && (saguPos.y < 289) && (tt != 2)) {
			pantailaGarbitu();
			ID_menuKontrolak = irudiaKargatu(MENU_KONTROLAK);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
			tt = 2;
		}
		if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 313) && (saguPos.y < 366) && (tt != 3)) {
			pantailaGarbitu();
			ID_menuKreditoak = irudiaKargatu(MENU_KREDITOAK);
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
	int ID_pertsonaiMenua, ebentua, ID_pertsonaiaAukeratu, ikutu = 0;
	POSIZIOA saguPos;

	saguPos = saguarenPosizioa();
	ID_pertsonaiMenua = IRUDIAK_pertsonaiMenua;
	//y = 161 goian y = 319 behean
	//x = 139 - 233
	SDL_RenderPresent(gRenderer);
	do
	{
		ebentua = ebentuaJasoGertatuBada();
		saguPos = saguarenPosizioa();
		if ((saguPos.x >= 139 && saguPos.x <= 233) && (saguPos.y >= 161 && saguPos.y <= 319))
		{
			ID_pertsonaiaAukeratu = irudiaKargatu(PERTSONAIA_AUKERATU);
			irudiaMugitu(ID_pertsonaiaAukeratu, 180, 236);
			SDL_RenderPresent(gRenderer);
			irudiaKendu(ID_pertsonaiaAukeratu);
		}
	} while (ikutu == 0);
}