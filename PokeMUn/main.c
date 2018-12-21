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
	} while (egoera != -1); //-1 itzuliko du ESC sakatzean
	bukatu();
	return 0;
}