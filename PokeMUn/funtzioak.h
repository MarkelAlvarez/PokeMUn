#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H
#include "sdlHasieratu.h"

typedef struct
{
	int x;
	int y;

}POSIZIOA;

typedef struct
{
	int id;
	POSIZIOA pos;
	int kredituak;
}PLAYER;

PLAYER player;

int gim2Ireki(PLAYER player);
void gim2Interakzioa();
void etxearekikoInterakzioa();
int etxeaIreki(PLAYER player);
POSIZIOA saguarenPosizioa();
void ebentoaDetektatu(int ebentoa);
POSIZIOA movePlayer(int signX, int signY);
int ebentuaJasoGertatuBada();
int rngGenerator(int min, int max);
int pausaMenua();

#endif
