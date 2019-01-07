#include "funtzioak.h" 
#include "kontrolak.h"

int main()
{
	int egoera;

	denaHasi();
	do
	{
		egoera = ebentuaJasoGertatuBada();
		ebentoaDetektatu(egoera);
	} while (egoera != GAME_OVER); //GAME_OVER itzuliko du ESC sakatzean
	bukatu();
	return 0;
}