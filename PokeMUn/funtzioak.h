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

typedef struct
{
	int id;
	//boss (eztakigu ze aldagai mota)
	int nota;
	POSIZIOA hitbox;

}GYM;

int gim3Interakzioa();
int gim3Ireki();
int gim1Interakzioa();
int gim1Ireki();
int gim4Ireki();
int gim4Interakzioa();
int gim2Ireki(PLAYER player);
int gim2Interakzioa();
int etxearekikoInterakzioa();
int etxeaIreki(PLAYER player);
POSIZIOA saguarenPosizioa();
int ebentoaDetektatu(int ebentoa);
POSIZIOA movePlayer(int signX, int signY);
int ebentuaJasoGertatuBada();
int rngGenerator(int min, int max);
int pausaMenua();

#endif
