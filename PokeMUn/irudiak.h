#include "funtzioak.h"
#ifndef IRUDIAK_H
#define IRUDIAK_H

#define MAX_IMG 500
#define SPRITE_PLAYER ".\\img\\sprite.bmp"

typedef struct
{
	int id;
	SDL_Surface* imagen;
	SDL_Texture* texture;
	SDL_Rect dest;
}IMG;

int irudiaKargatu(char* fileName);
int irudiarenPosizioaAurkitu(int id);
int IRUDIAK_spriteSortu();
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
#endif
