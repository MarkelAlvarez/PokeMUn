#include "funtzioak.h" 
#include "kontrolak.h"
#include "menua.h"
#include "irudiak.h"

#include "funtzioak.h" 
#include "kontrolak.h"
#include "menua.h"
#include "irudiak.h"

int main()
{
	int egoera = 0, errorea;
	PLAYER menu;

	errorea = SDLHasi();
	if (errorea == 0)
	{
		printf(" Erroreak gertatu dira.");
	}
	else
	{
		menu.id = irudiaSortu(MENU);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		do
		{
			egoera = hasierakomenu(menu);
		} while (egoera != GAME_OVER);
		bukatu();
	}

	return 0;
}