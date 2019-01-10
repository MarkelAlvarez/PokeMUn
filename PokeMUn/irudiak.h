#include "funtzioak.h"
#ifndef IRUDIAK_H
#define IRUDIAK_H

#define MAX_IMG 500
#define PERTSONAI_MENUA ".\\IMG\\menus\\menu_pertsonaiak.bmp"
#define PERTSONAIA_AUKERATU ".\\IMG\\menus\\pertsonaia_aukeratu.bmp"
#define SPRITE_PLAYER_ARRIBIZQ ".\\IMG\\personajes\\chica\\ArrIzq.bmp"
#define SPRITE_PLAYER_ABAJOIZQ ".\\IMG\\personajes\\chica\\AbaIzq.bmp"
#define SPRITE_PLAYER_IZQIZQ ".\\IMG\\personajes\\chica\\IzqIzq.bmp"
#define SPRITE_PLAYER_DERIZQ ".\\IMG\\personajes\\chica\\DerIzq.bmp"
#define HASIERA_ETXEA ".\\IMG\\fondos\\casa_inicio.bmp"
#define SPRITE_NPC ".\\IMG\\npc.bmp"
#define PAUSE ".\\IMG\\menus\\pause.bmp"
#define MENU_JOKATU ".\\IMG\\menus\\menu_jokatu.bmp"
#define MENU_KONTROLAK ".\\IMG\\menus\\menu_kontrolak.bmp"
#define MENU_KREDITOAK ".\\IMG\\menus\\menu_kreditoak.bmp"
#define MENU ".\\IMG\\menus\\menu.bmp"
#define MUNDUA ".\\IMG\\menus\\mundo.bmp"
#define GIM2 ".\\IMG\\fondos\\gim2.bmp"
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

int irudiaSortu(char* imgName);
int irudiaKargatu(char* fileName);
void irudiaKendu(int id);
int irudiarenPosizioaAurkitu(int id);
void pantailaGarbitu();
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
#endif
