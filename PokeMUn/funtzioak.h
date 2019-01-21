#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H
#include "sdlHasieratu.h"

#define APROBATU 1
#define SUSPENSO -1
#define MAPA_MUNDUA 0
#define MAPA_GIM1 1
#define MAPA_GIM2 2
#define MAPA_GIM3 3
#define MAPA_GIM4 4
#define MAPA_GIM5 5
#define MAPA_ETXEA 6
#define MAPA_NOTA 7
#define MAPA_NOTA_BARRUTIK 8

typedef struct
{
	int x;
	int y;

}POSIZIOA;

typedef struct
{
	float gim1;
	float gim2;
	float gim3;
	float gim4;
	float gim5;
	float bataz;
}NOTA;

typedef struct
{
	int id;
	POSIZIOA pos;
	NOTA notak;
	int mapa;
	int kurtsoa;
	int generoa;
}PLAYER;

typedef struct
{
	POSIZIOA sartu;
	POSIZIOA irten;
}EGOERA;

typedef struct
{
	int id;
	POSIZIOA boss;
	int nota;
	EGOERA egoera;
}GYM;

PLAYER player;
int kargatuta;

void messagePopUp(char* message);
void denaKargatu(GYM* gimnasioak);
int kargatuPartida(GYM* gimnasioak);
void gordePartida();
int galduEdoIrabazi();
int notaHiruTxikiago();
int bukatuAlDu();
void playerHasieratu();
int gymCompleted();
void asignaturaEbaluatu(int nota);
void gymRefresh(char* gymIMG, char* bossIMG);
void endBattle();
int ezPasa();
void erantzunaHasieratu();
int galderakBaieztatu(int irakaslea, int zureErantzuna, int galdera);
int startBattle(int* fighterID, int* bossID);
int galderaKargatu(int galdera, int* fighterID, int* bossI);
int galderaPantailaratu(char* imgGaldera, char* imgAukerak, int* fighterID, int* bossID);
void battleStage();
int irakasleIrudiaAurkitu(char bossIMG[]);
int irudiaAurkitu(int id, int interakzioa, int* bossID, int* ezegin);
void eraikinInterakzio(GYM* gimnasioHitbox);
int gimnasioakHasieratu(GYM* gimnasioHitbox);
int edifizioaIreki(GYM gimnasioHitbox[], int* id, int max);
POSIZIOA saguarenPosizioa();
int ebentoaDetektatu(int ebentoa);
POSIZIOA movePlayer(int signX, int signY);
int ebentuaJasoGertatuBada();
int pausaMenua();
int mapenHitboxak(int tecla);
int beheruntzAnimazioa(int boo);
int ezkerreruntzAnimazioa(int boo);
int gorunztAnimazioa(int boo);
int eskubiruntzAnimazioa(int boo);

#endif
