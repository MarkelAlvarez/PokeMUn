#include "funtzioak.h" 
#include "kontrolak.h"
#include "menua.h"
#include "irudiak.h"

int main()
{
	int egoera;

	SDLHasi();
	egoera = hasierakomenu();
	if (egoera == JOLASTEN)
	{
		pantailaGarbitu();
		jokuaHasi();
		SDL_RenderPresent(gRenderer);
		do {
			egoera = ebentuaJasoGertatuBada();
			ebentoaDetektatu(egoera);
		} while (egoera != TECLA_0);
	}
	bukatu();
	return 0;
}