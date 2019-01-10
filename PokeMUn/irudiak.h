#include "funtzioak.h"
#ifndef IRUDIAK_H
#define IRUDIAK_H

#define MAX_IMG 500
#define SPRITE_PLAYER_ARRIBIZQ ".\\img\\personajes\\chica\\ArribIzq.bmp"
#define SPRITE_PLAYER_ABAJOIZQ ".\\img\\personajes\\chica\\AbajoIzq.bmp"
#define SPRITE_PLAYER_IZQIZQ ".\\img\\personajes\\chica\\IzqIzq.bmp"
#define SPRITE_PLAYER_DERIZQ ".\\img\\personajes\\chica\\DerIzq.bmp"
#define HASIERA_ETXEA ".\\img\\fondos\\casa_inicio.bmp"
#define SPRITE_NPC ".\\img\\npc.bmp"
#define PAUSE ".\\img\\menus\\pause.bmp"
#define MENU_JOKATU ".\\img\\menus\\menu_jokatu.bmp"
#define MENU_KONTROLAK ".\\img\\menus\\menu_kontrolak.bmp"
#define MENU_KREDITOAK ".\\img\\menus\\menu_kreditoak.bmp"
#define MENU ".\\img\\menus\\menu.bmp"
#define MUNDUA ".\\img\\menus\\mundo.bmp"
#define GIM2 ".\\img\\fondos\\gim2.bmp"
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

int IRUDIAK_hasieraEtxeaSortu();
int irudiaKargatu(char* fileName);
void irudiaKendu(int id);
int irudiarenPosizioaAurkitu(int id);
int IRUDIAK_spriteSortuAI();
int IRUDIAK_spriteSortuAbI();
int IRUDIAK_spriteSortuII();
int IRUDIAK_spriteSortuDI();
int IRUDIAK_npcSortu();
int IRUDIAK_pauseIMG();
void pantailaGarbitu();
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
int IRUDIAK_munduaIMG();
int IRUDIAK_gim2Sortu();
#endif
