#include "funtzioak.h" 
#include "kontrolak.h"
#include "menua.h"
#include "irudiak.h"

int main()
{
	int egoera, ebentoa;

	SDLHasi();
	egoera = hasierakomenu();
	//if gitano honen ordez funtzio bat aukerak kudeatzeko
	if (egoera == JOLASTEN)
	{
		pantailaGarbitu();
		//pertsonaia aukeratu
		jokuaHasi();
		SDL_RenderPresent(gRenderer);
		do {
			ebentoa = ebentuaJasoGertatuBada();
			egoera = ebentoaDetektatu(ebentoa);
		} while (egoera != GAME_OVER);
	}
	bukatu();
	return 0;
}