#include "funtzioak.h"
#ifndef IRUDIAK_H
#define IRUDIAK_H

#define MAX_IMG 500
#define SPRITE_PLAYER ".\\img\\sprite.bmp"
#define SPRITE_NPC ".\\img\\npc.bmp"
#define PLAYER_W 61
#define PLAYER_H 81
#define NPC_W 87
#define NPC_H 131


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
int IRUDIAK_npcSortu();
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
#endif
