#include "funtzioak.h"
#include "kontrolak.h"
#include "irudiak.h"
#include "hitbox.h"

SDL_Event event;
POSIZIOA saguPos;

int erantzunak[6][6];
int goraAnimaz = 0, ezkerreraAnimaz = 0, beheraAnimaz = 0, eskubiAnimaz = 0;

void messagePopUp(char* message)
{
	int messageID;

	messageID = irudiaSortu(MENSAJE);
	irudiaMugitu(messageID, 0, 363);
	irudiakMarraztu();
	textuaIdatzi(40, 410, message);
	SDL_RenderPresent(gRenderer);
	Sleep(2000);
	textuaDesgaitu();
	irudiaKendu(messageID);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);
}

void denaKargatu(GYM* gimnasioak)
{
	int bossID;

	if (player.mapa == MAPA_MUNDUA)
	{
		irudiaSortu(MUNDUA);
	}
	else if (player.mapa == MAPA_ETXEA)
	{
		irudiaSortu(HASIERA_ETXEA);
	}
	else if (player.mapa == MAPA_GIM1)
	{
		irudiaSortu(GIM1);
		bossID = irudiaSortu(IRAKASLE1);
		irudiaMugitu(bossID, gimnasioak->boss.x, gimnasioak->boss.y);
	}
	else if (player.mapa == MAPA_GIM2)
	{
		irudiaSortu(GIM2);
		bossID = irudiaSortu(IRAKASLE2);
		irudiaMugitu(bossID, gimnasioak->boss.x, gimnasioak->boss.y);
	}
	else if (player.mapa == MAPA_GIM3)
	{
		irudiaSortu(GIM3);
		bossID = irudiaSortu(IRAKASLE3);
		irudiaMugitu(bossID, gimnasioak->boss.x, gimnasioak->boss.y);
	}
	else if (player.mapa == MAPA_GIM4)
	{
		irudiaSortu(GIM4);
		bossID = irudiaSortu(IRAKASLE4);
		irudiaMugitu(bossID, gimnasioak->boss.x, gimnasioak->boss.y);
	}
	else if (player.mapa == MAPA_GIM5)
	{
		irudiaSortu(GIM5);
		bossID = irudiaSortu(IRAKASLE5);
		irudiaMugitu(bossID, gimnasioak->boss.x, gimnasioak->boss.y);
	}
	else if (player.mapa == MAPA_NOTA)
	{
		irudiaSortu(NOTA_MAPA);
	}
	else if (player.mapa == MAPA_NOTA_BARRUTIK)
	{
		irudiaSortu(NOTA_MAPA_BARRUTIK);
		bossID = irudiaSortu(IRAKASLE6);
		irudiaMugitu(bossID, gimnasioak->boss.x, gimnasioak->boss.y);
	}
	if (player.generoa == 1)
	{
		player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
	}
	else if (player.generoa == 2)
	{
		player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
	}
}

int kargatuPartida(GYM* gimnasioak)
{
	int kargatu = 0;
	FILE* save;

	save = fopen("PokeMUn.sav", "r");
	if (save == NULL)
	{
		printf("Errorea egon da fitxategia irekitzerakoan . . .\n");
	}
	else
	{
		fscanf(save, "Posizioak: %i %i Mapa: %i Generoa: %d\n", &player.pos.x, &player.pos.y, &player.mapa, &player.generoa);
		fscanf(save, "Notak: \nGim1: %f Gim2: %f Gim3: %f Gim4: %f Gim5: %f ", &player.notak.gim1, &player.notak.gim2, &player.notak.gim3, &player.notak.gim4, &player.notak.gim5);
		gimnasioakHasieratu(gimnasioak);
		denaKargatu(gimnasioak);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
		kargatu = 1;
	}
	
	return kargatu;
}

void gordePartida()
{
	FILE* save;

	save = fopen("PokeMUn.sav", "w");
	if (save == NULL)
	{
		printf("Errorea egon da fitxategia sortzerakoan. . .");
	}
	else
	{
		fprintf(save, "Posizioak: %d %d Mapa: %d Generoa: %d\n", player.pos.x, player.pos.y, player.mapa, player.generoa);
		fprintf(save, "Notak:\nGim1: %f Gim2: %f Gim3: %f Gim4: %f Gim5: %f ", player.notak.gim1, player.notak.gim2, player.notak.gim3, player.notak.gim4, player.notak.gim5);
		fclose(save);
	}
}

int bukaeraMezua(int egoera, GYM* gimnasioHitbox, int ebentoa)
{
	int bukatu = JOLASTEN, bukaeraID;

	gimnasioakHasieratu(gimnasioHitbox);
	if (player.mapa == MAPA_NOTA_BARRUTIK && HITBOX_npcInRange(gimnasioHitbox) == 1 && ebentoa == TECLA_e)
	{
		bukaeraID = irudiaSortu(BUKAERA_MEZUA);
		irudiakMarraztu();
		if (egoera == APROBATU)
		{
			textuaIdatzi(40, 415, "Zorionak aprobatzeagatik, irabazi duzu!");
		}
		if (egoera == SUSPENSO)
		{
			textuaIdatzi(40, 415, "Ikusiko gara irailean, ondo pasa oporrak :)");
		}
		SDL_RenderPresent(gRenderer);
		Sleep(3000);
		textuaDesgaitu();
		textuaIdatzi(40, 415, "ESC sakatu ateratzeko");
		SDL_RenderPresent(gRenderer);
		bukatu = GAME_OVER;
		do
		{
			ebentoa = ebentuaJasoGertatuBada();
		} while (ebentoa != TECLA_ESCAPE);
		irudiaKendu(bukaeraID);
	}

	return bukatu;
}

int notaHiruTxikiago()
{
	int suspenso = 0;

	if (player.notak.gim1 <= 3)
	{
		suspenso++;
	}
	if (player.notak.gim2 <= 3)
	{
		suspenso++;
	}
	if (player.notak.gim3 <= 3)
	{
		suspenso++;
	}
	if (player.notak.gim4 <= 3)
	{
		suspenso++;
	}
	if (player.notak.gim5 <= 3)
	{
		suspenso++;
	}

	return suspenso;
}

int zenbatSuspenso()
{
	int suspenso = 0;

	if (player.notak.gim1 < 5)
	{
		suspenso++;
	}
	if (player.notak.gim2 < 5)
	{
		suspenso++;
	}
	if (player.notak.gim3 < 5)
	{
		suspenso++;
	}
	if (player.notak.gim4 < 5)
	{
		suspenso++;
	}
	if (player.notak.gim5 < 5)
	{
		suspenso++;
	}

	return suspenso;
}

int galduEdoIrabazi()
{
	int egoera = JOLASTEN, suspenso, hiru;
	float bataz;

	bataz = (player.notak.gim1 + player.notak.gim2 + player.notak.gim3 + player.notak.gim4 + player.notak.gim5) / 5;
	suspenso = zenbatSuspenso();
	hiru = notaHiruTxikiago();
	if ((bataz < 5.25 && suspenso > 2) || hiru >= 1)
	{
		egoera = SUSPENSO;
	}
	else
	{
		egoera = APROBATU;
	}

	return egoera;
}

int bukatuAlDu()
{
	int ret = 0;

	if (player.notak.gim1 != -1 && player.notak.gim2 != -1 && player.notak.gim3 != -1 && player.notak.gim4 != -1 && player.notak.gim5 != -1)
	{
		ret = 1;
	}

	return ret;
}

int gymCompleted()
{
	int ret = 1, messageID = -1;

	if (player.mapa == MAPA_GIM1 && player.notak.gim1 != -1)
	{
		ret = 0;
		messagePopUp("Neurekin egin duzu azterketa, joan hurrengo gimnasiora.");
	}
	else if (player.mapa == MAPA_GIM2 && player.notak.gim2 != -1)
	{
		ret = 0;
		messagePopUp("Neurekin egin duzu azterketa, joan hurrengo gimnasiora.");
	}
	else if (player.mapa == MAPA_GIM3 && player.notak.gim3 != -1)
	{
		ret = 0;
		messagePopUp("Neurekin egin duzu azterketa, joan hurrengo gimnasiora.");
	}
	else if (player.mapa == MAPA_GIM4 && player.notak.gim4 != -1)
	{
		ret = 0;
		messagePopUp("Neurekin egin duzu azterketa, joan hurrengo gimnasiora.");
	}
	else if (player.mapa == MAPA_GIM5 && player.notak.gim5 != -1)
	{
		ret = 0;
		messagePopUp("Neurekin egin duzu azterketa, joan hurrengo gimnasiora.");
	}

	return ret;
}

void gymRefresh(char* gymIMG, char* bossIMG)
{

	irudiaSortu(gymIMG);
	messagePopUp("Orain zuzentzera noa, zorte on beste azterketetan!");
}

void asignaturaEbaluatu(int nota)
{
	if (player.mapa == MAPA_GIM1)player.notak.gim1 = (float)((nota * 10) / 3);
	if (player.mapa == MAPA_GIM2)player.notak.gim2 = (float)((nota * 10) / 3);
	if (player.mapa == MAPA_GIM3)player.notak.gim3 = (float)((nota * 10) / 3);
	if (player.mapa == MAPA_GIM4)player.notak.gim4 = (float)((nota * 10) / 3);
	if (player.mapa == MAPA_GIM5)player.notak.gim5 = (float)((nota * 10) / 3);
}

void playerHasieratu()
{
	player.notak.gim1 = -1;
	player.notak.gim2 = -1;
	player.notak.gim3 = -1;
	player.notak.gim4 = -1;
	player.notak.gim5 = -1;
	player.kurtsoa = 0;
	player.mapa = MAPA_ETXEA;
}

void erantzunaHasieratu()
{
	erantzunak[0][0] = 1;
	erantzunak[0][1] = 2;
	erantzunak[0][2] = 1;
	erantzunak[1][0] = 2;
	erantzunak[1][1] = 2;
	erantzunak[1][2] = 2;
	erantzunak[2][0] = 3;
	erantzunak[2][1] = 2;
	erantzunak[2][2] = 1;
	erantzunak[3][0] = 4;
	erantzunak[3][1] = 1;
	erantzunak[3][2] = 1;
	erantzunak[4][0] = 1;
	erantzunak[4][1] = 4;
	erantzunak[4][2] = 1;
}

int galderakBaieztatu(int irakaslea, int zureErantzuna, int galdera)
{
	int ondo = 0;

	if (zureErantzuna == erantzunak[irakaslea][galdera])
	{
		ondo = 1;
		printf("Ondo\n");
	}

	return ondo;
}

int galderaPantailaratu(char* imgGaldera, char* imgAukerak, int* fighterID, int* bossID)
{
	int galderaID, ebentoa;

	galderaID = irudiaSortu(imgGaldera);
	startBattle(&fighterID, &bossID);
	SDL_RenderPresent(gRenderer);
	do
	{
		ebentoa = ebentuaJasoGertatuBada();
	} while (ebentoa != SAGU_BOTOIA_EZKERRA);

	irudiaKendu(galderaID);
	galderaID = irudiaSortu(imgAukerak);
	startBattle(&fighterID, &bossID);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	return galderaID;
}

int galderaKargatu(int galdera, int* fighterID, int* bossID)
{
	int galderaID = -1;

	if (player.mapa == MAPA_GIM1)
	{
		if (galdera == 0)
		{
			galderaPantailaratu(GIM11P, GIM11O, &fighterID, &bossID);
		}
		else if (galdera == 1)
		{
			galderaPantailaratu(GIM12P, GIM12O, &fighterID, &bossID);
		}
		else if (galdera == 2)
		{
			galderaPantailaratu(GIM13P, GIM13O, &fighterID, &bossID);
		}
	}
	else if (player.mapa == MAPA_GIM2)
	{
		if (galdera == 0)
		{
			galderaPantailaratu(GIM21P, GIM21O, &fighterID, &bossID);
		}
		else if (galdera == 1)
		{
			galderaPantailaratu(GIM22P, GIM22O, &fighterID, &bossID);
		}
		else if (galdera == 2)
		{
			galderaPantailaratu(GIM23P, GIM23O, &fighterID, &bossID);
		}
	}
	else if (player.mapa == MAPA_GIM3)
	{
		if (galdera == 0)
		{
			galderaPantailaratu(GIM51P, GIM51O, &fighterID, &bossID);
		}
		else if (galdera == 1)
		{
			galderaPantailaratu(GIM52P, GIM52O, &fighterID, &bossID);
		}
		else if (galdera == 2)
		{
			galderaPantailaratu(GIM53P, GIM53O, &fighterID, &bossID);
		}
	}
	else if (player.mapa == MAPA_GIM4)
	{
		if (galdera == 0)
		{
			galderaPantailaratu(GIM41P, GIM41O, &fighterID, &bossID);
		}
		else if (galdera == 1)
		{
			galderaPantailaratu(GIM42P, GIM42O, &fighterID, &bossID);
		}
		else if (galdera == 2)
		{
			galderaPantailaratu(GIM43P, GIM43O, &fighterID, &bossID);
		}
	}
	else if (player.mapa == MAPA_GIM5)
	{
		if (galdera == 0)
		{
			galderaPantailaratu(GIM31P, GIM31O, &fighterID, &bossID);
		}
		else if (galdera == 1)
		{
			galderaPantailaratu(GIM32P, GIM32O, &fighterID, &bossID);
		}
		else if (galdera == 2)
		{
			galderaPantailaratu(GIM33P, GIM33O, &fighterID, &bossID);
		}
	}

	return galderaID;
}

int irakasleIrudiaAurkitu(char bossIMG[])
{
	int irakasle = -1;

	if (player.mapa == MAPA_GIM1)
	{
		strcpy(bossIMG, FIGHT_IRAKASLE1);
		irakasle = 0;
	}
	else if (player.mapa == MAPA_GIM2)
	{
		strcpy(bossIMG, FIGHT_IRAKASLE2);
		irakasle = 1;
	}
	else if (player.mapa == MAPA_GIM3)
	{
		strcpy(bossIMG, FIGHT_IRAKASLE3);
		irakasle = 2;
	}
	else if (player.mapa == MAPA_GIM4)
	{
		strcpy(bossIMG, FIGHT_IRAKASLE4);
		irakasle = 3;
	}
	else if (player.mapa == MAPA_GIM5)
	{
		strcpy(bossIMG, FIGHT_IRAKASLE5);
		irakasle = 4;
	}

	return irakasle;
}

int startBattle(int* fighterID, int* bossID)
{
	int irakasle;
	char bossIMG[60];

	if (player.generoa == 1)*fighterID = irudiaSortu(SPRITE_PLAYER_BATTLE);
	if (player.generoa == 2)*fighterID = irudiaSortu(PLAYER_BATTLE);
	irakasle = irakasleIrudiaAurkitu(bossIMG);
	*bossID = irudiaSortu(bossIMG);
	irudiaMugitu(*fighterID, 115, 235);
	irudiaMugitu(*bossID, 400, 25);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	return irakasle;
}

void battleStage()
{
	int fighterID, bossID, erantzuna = 0, galdera = 0, galderaID, zuzen, irakasle;
	int nota = 0;

	messagePopUp("Galdera irakurtzean sakatu saguko ezkerreko botoia");
	galderaID = galderaKargatu(galdera, &fighterID, &bossID);
	irakasle = startBattle(&fighterID, &bossID);
	erantzunaHasieratu();
	do
	{
		erantzuna = galderenHitboxa();
		if (erantzuna != 0)
		{
			irudiaKendu(galderaID);
			zuzen = galderakBaieztatu(irakasle, erantzuna, galdera);
			if (zuzen == 1)
			{
				nota++;
			}
			galdera++;
			galderaID = galderaKargatu(galdera, &fighterID, &bossID);
			irakasle = startBattle(&fighterID, &bossID);
			erantzuna = 0;
		}
	} while (galdera != 3);
	asignaturaEbaluatu(nota);
	irudiaKendu(galderaID);
	irudiaKendu(fighterID);
	irudiaKendu(bossID);
	endBattle();
	player.kurtsoa = bukatuAlDu();
	SDL_RenderPresent(gRenderer);
}

void endBattle()
{
	if (player.mapa == MAPA_GIM1)
	{
		gymRefresh(GIM1, IRAKASLE1);
	}
	else if (player.mapa == MAPA_GIM2)
	{
		gymRefresh(GIM2, IRAKASLE4);
	}
	else if (player.mapa == MAPA_GIM3)
	{
		gymRefresh(GIM3, IRAKASLE3);
	}
	else if (player.mapa == MAPA_GIM4)
	{
		gymRefresh(GIM4, IRAKASLE2);
	}
	else if (player.mapa == MAPA_GIM5)
	{
		gymRefresh(GIM5, IRAKASLE5);
	}
	if (player.generoa == 1)
	{
		player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
	}
	else if (player.generoa == 2)
	{
		player.id = irudiaSortu(PLAYER_ARRIBIZQ);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
	}
	irudiakMarraztu();
}

int gimnasioakHasieratu(GYM* gimnasioHitbox)
{
	int i = 0;

	if (player.mapa == MAPA_MUNDUA)
	{
		//HASIERA ETXEA
		gimnasioHitbox[i].egoera.sartu.x = 552;
		gimnasioHitbox[i].egoera.sartu.y = 375;
		i++;
		//GIM1
		gimnasioHitbox[i].egoera.sartu.x = 192;
		gimnasioHitbox[i].egoera.sartu.y = 213;
		i++;
		//GIM2
		gimnasioHitbox[i].egoera.sartu.x = 55;
		gimnasioHitbox[i].egoera.sartu.y = 375;
		i++;
		//GIM3
		gimnasioHitbox[i].egoera.sartu.x = 497;
		gimnasioHitbox[i].egoera.sartu.y = 126;
		i++;
		//GIM4
		gimnasioHitbox[i].egoera.sartu.x = 62;
		gimnasioHitbox[i].egoera.sartu.y = 116;
		i++;
		//GIM5
		gimnasioHitbox[i].egoera.sartu.x = 482;
		gimnasioHitbox[i].egoera.sartu.y = 273;
		i++;
		//MAPA BERRIA
		gimnasioHitbox[i].egoera.sartu.x = 615;
		gimnasioHitbox[i].egoera.sartu.y = 140;
		i++;
	}
	else if (player.mapa == MAPA_ETXEA)
	{
		//HASIERA ETXEA
		gimnasioHitbox[i].egoera.sartu.x = 552;
		gimnasioHitbox[i].egoera.sartu.y = 375;
		gimnasioHitbox[i].egoera.irten.x = 253;
		gimnasioHitbox[i].egoera.irten.y = 295;
		i++;
	}
	else if (player.mapa == MAPA_GIM1)
	{
		//GIM1
		gimnasioHitbox[i].egoera.sartu.x = 192;
		gimnasioHitbox[i].egoera.sartu.y = 213;
		gimnasioHitbox[i].egoera.irten.x = 302;
		gimnasioHitbox[i].egoera.irten.y = 392;
		gimnasioHitbox[i].boss.x = 316;
		gimnasioHitbox[i].boss.y = 80;
		i++;
	}
	else if (player.mapa == MAPA_GIM2)
	{
		//GIM2
		gimnasioHitbox[i].egoera.sartu.x = 55;
		gimnasioHitbox[i].egoera.sartu.y = 375;
		gimnasioHitbox[i].egoera.irten.x = 309;
		gimnasioHitbox[i].egoera.irten.y = 355;
		gimnasioHitbox[i].boss.x = 290;
		gimnasioHitbox[i].boss.y = 76;
		i++;
	}
	else if (player.mapa == MAPA_GIM3)
	{
		//GIM3
		gimnasioHitbox[i].egoera.sartu.x = 497;
		gimnasioHitbox[i].egoera.sartu.y = 126;
		gimnasioHitbox[i].egoera.irten.x = 298;
		gimnasioHitbox[i].egoera.irten.y = 403;
		gimnasioHitbox[i].boss.x = 296;
		gimnasioHitbox[i].boss.y = 115;
		i++;
	}
	else if (player.mapa == MAPA_GIM4)
	{
		gimnasioHitbox[i].egoera.sartu.x = 62;
		gimnasioHitbox[i].egoera.sartu.y = 116;
		gimnasioHitbox[i].egoera.irten.x = 298;
		gimnasioHitbox[i].egoera.irten.y = 321;
		gimnasioHitbox[i].boss.x = 311;
		gimnasioHitbox[i].boss.y = 145;
		i++;
	}
	else if (player.mapa == MAPA_GIM5)
	{
		gimnasioHitbox[i].egoera.sartu.x = 482;
		gimnasioHitbox[i].egoera.sartu.y = 273;
		gimnasioHitbox[i].egoera.irten.x = 236;
		gimnasioHitbox[i].egoera.irten.y = 346;
		gimnasioHitbox[i].boss.x = 302;
		gimnasioHitbox[i].boss.y = 102;
		i++;
	}
	else if (player.mapa == MAPA_NOTA)
	{
		gimnasioHitbox[i].egoera.sartu.x = 615;
		gimnasioHitbox[i].egoera.sartu.y = 140;
		gimnasioHitbox[i].egoera.irten.x = 3;
		gimnasioHitbox[i].egoera.irten.y = 147;
		i++;
		gimnasioHitbox[i].egoera.sartu.x = 484;
		gimnasioHitbox[i].egoera.sartu.y = 284;
		gimnasioHitbox[i].egoera.irten.x = 305;
		gimnasioHitbox[i].egoera.irten.y = 446;
		i++;
	}
	else if (player.mapa == MAPA_NOTA_BARRUTIK)
	{
		gimnasioHitbox[i].egoera.sartu.x = 484;
		gimnasioHitbox[i].egoera.sartu.y = 284;
		gimnasioHitbox[i].egoera.irten.x = 305;
		gimnasioHitbox[i].egoera.irten.y = 446;
		gimnasioHitbox[i].boss.x = 304;
		gimnasioHitbox[i].boss.y = 194;
		i++;
	}

	return i;
}

int edifizioaIreki(GYM gimnasioHitbox[], int* id, int max)
{
	int ret = 0, i;

	for (i = 0; i < max && ret == 0; i++)
	{
		if (i == 5)//5. gimnasioak 2 ate dituenez, 2 ateetatik sartu ahal izateko if hau dago
		{
			if ((player.pos.y <= gimnasioHitbox[i].egoera.sartu.y + 10 && player.pos.y >= gimnasioHitbox[i].egoera.sartu.y) && ((player.pos.x >= gimnasioHitbox[i].egoera.sartu.x && player.pos.x <= gimnasioHitbox[i].egoera.sartu.x + 12) || (player.pos.x >= 524 && player.pos.x <= 540)))
			{
				ret = SARTU;
				*id = i;
			}
		}
		else if ((player.pos.x >= gimnasioHitbox[i].egoera.sartu.x && player.pos.x <= gimnasioHitbox[i].egoera.sartu.x + 21) && (player.pos.y >= gimnasioHitbox[i].egoera.sartu.y && player.pos.y <= gimnasioHitbox[i].egoera.sartu.y + 21))
		{
			ret = SARTU;
			*id = i;
		}
	}
	for (i = 0; i < max && ret == 0; i++)
	{
		if (player.mapa == MAPA_GIM5)
		{
			if (((player.pos.x >= gimnasioHitbox[i].egoera.irten.x && player.pos.x <= gimnasioHitbox[i].egoera.irten.x + 21) && (player.pos.y >= gimnasioHitbox[i].egoera.irten.y && player.pos.y <= gimnasioHitbox[i].egoera.irten.y + 8)) || ((player.pos.x >= 362 && player.pos.x <= 383) && (player.pos.y >= 346 && player.pos.y <= 360)))
			{
				ret = IRTEN;
				*id = i;
			}
		}
		else if ((player.pos.x >= gimnasioHitbox[i].egoera.irten.x && player.pos.x <= gimnasioHitbox[i].egoera.irten.x + 21) && (player.pos.y >= gimnasioHitbox[i].egoera.irten.y && player.pos.y <= gimnasioHitbox[i].egoera.irten.y + 8))
		{
			ret = IRTEN;
			*id = i;
		}
	}

	return ret;
}

int irudiaAurkitu(int id, int interakzioa, int* bossID, int* ezegin)
{
	int imgID = -1, baimena = 0;
	baimena = ezPasa();
	*ezegin = 1;
	if (interakzioa == SARTU && player.mapa == MAPA_MUNDUA)
	{
		if (id == 0)
		{
			imgID = irudiaSortu(HASIERA_ETXEA);
			player.mapa = MAPA_ETXEA;
		}
		else if (id == 1)
		{
			imgID = irudiaSortu(GIM1);
			player.mapa = MAPA_GIM1;
			*bossID = irudiaSortu(IRAKASLE1);
		}
		else if (id == 2)
		{
			imgID = irudiaSortu(GIM2);
			player.mapa = MAPA_GIM2;
			*bossID = irudiaSortu(IRAKASLE2);
		}
		else if (id == 3)
		{
			imgID = irudiaSortu(GIM3);
			player.mapa = MAPA_GIM3;
			*bossID = irudiaSortu(IRAKASLE3);

		}
		else if (id == 4)
		{
			imgID = irudiaSortu(GIM4);
			player.mapa = MAPA_GIM4;
			*bossID = irudiaSortu(IRAKASLE6);
		}
		else if (id == 5)
		{
			imgID = irudiaSortu(GIM5);
			player.mapa = MAPA_GIM5;
			*bossID = irudiaSortu(IRAKASLE5);
		}
		else if (id == 6)
		{
			imgID = irudiaSortu(NOTA_MAPA);
			player.mapa = MAPA_NOTA;
		}
	}
	else if (interakzioa == SARTU && player.mapa == MAPA_NOTA)
	{
		if (baimena == 1) {
			imgID = irudiaSortu(NOTA_MAPA_BARRUTIK);
			player.mapa = MAPA_NOTA_BARRUTIK;
			*bossID = irudiaSortu(IRAKASLE4);
		}
		if (baimena == 0)*ezegin = 2;

	}
	else if (interakzioa == IRTEN)
	{
		if (player.mapa != MAPA_NOTA_BARRUTIK)
		{
			imgID = irudiaSortu(MUNDUA);
			player.mapa = MAPA_MUNDUA;
			*ezegin = 1;
		}
		else
		{
			imgID = irudiaSortu(NOTA_MAPA);
			player.mapa = MAPA_NOTA;
		}
	}

	return imgID;
}

int ezPasa()
{
	int baimena = 1;
	if (player.notak.gim1 == -1 || player.notak.gim2 == -1 || player.notak.gim3 == -1 || player.notak.gim4 == -1 || player.notak.gim5 == -1)
		baimena = 0;
	return baimena;
}

void eraikinInterakzio(GYM* gimnasioHitbox)
{
	int interakzioa = 0, id = 0, gymID, max, bossID = 0, ezegin = 1;

	max = gimnasioakHasieratu(gimnasioHitbox);
	interakzioa = edifizioaIreki(gimnasioHitbox, &id, max);

	if (interakzioa == SARTU)
	{
		gymID = irudiaAurkitu(id, interakzioa, &bossID, &ezegin);
		if (ezegin == 1) 
		{
			irudiaKendu(player.id);
			gimnasioakHasieratu(gimnasioHitbox);
			player.pos.x = gimnasioHitbox[0].egoera.irten.x;
			player.pos.y = gimnasioHitbox[0].egoera.irten.y;
			if (player.generoa == 1)
			{
				player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
			}
			else
			{
				player.id = irudiaSortu(PLAYER_ARRIBIZQ);
			}
			irudiaMugitu(player.id, player.pos.x, player.pos.y);
			irudiaMugitu(bossID, gimnasioHitbox[0].boss.x, gimnasioHitbox[0].boss.y);
			irudiakMarraztu();
			SDL_RenderPresent(gRenderer);
		}
		else
		{
			messagePopUp("Oraindik ez zara ikasgai guztietara joan");
		}

	}
	else if (interakzioa == IRTEN)
	{
		irudiaAurkitu(id, interakzioa, &bossID, &ezegin);
		irudiaKendu(player.id);
		player.pos.x = gimnasioHitbox[id].egoera.sartu.x;
		player.pos.y = gimnasioHitbox[id].egoera.sartu.y;
		if (player.generoa == 1)
		{
			player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
		}
		else
		{
			player.id = irudiaSortu(PLAYER_ABAJOIZQ);
		}
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
}

int pausaMenua()
{
	int egoera, id, ret, ikutu = 0;
	POSIZIOA saguPos;

	id = irudiaSortu(PAUSE);
	do
	{//269 372
		egoera = ebentuaJasoGertatuBada();
		saguPos = saguarenPosizioa();
		if (egoera == SAGU_BOTOIA_EZKERRA && ((saguPos.x >= 269 && saguPos.x <= 372) && (saguPos.y >= 270 && saguPos.y <= 369)))
		{
			ikutu = 1;
		}
		SDL_RenderPresent(gRenderer);
	} while (egoera != TECLA_ESCAPE && egoera != TECLA_ENTER && ikutu != 1);
	if (egoera == TECLA_ESCAPE)
	{
		ret = GAME_OVER;
	}
	else if (egoera == TECLA_ENTER)
	{
		ret = JOLASTEN;
	}
	else if (ikutu == 1)
	{
		gordePartida();
		messagePopUp("Partida ongi gorde da. . .");
		ret = JOLASTEN;
	}
	pantailaGarbitu();
	irudiaKendu(id);
	irudiakMarraztu();
	SDL_RenderPresent(gRenderer);

	return ret;
}

POSIZIOA movePlayer(int signX, int signY)
{
	POSIZIOA aux;

	aux = player.pos;
	aux.x = player.pos.x + (7 * signX);
	aux.y = player.pos.y + (7 * signY);

	return aux;
}

int ebentoaDetektatu(int ebentoa)
{
	int egoera = 1, baimena, aprobatu;
	GYM* gimnasioHitbox;

	gimnasioHitbox = (GYM*)malloc(sizeof(GYM) * 10);
	if (kargatuta != 1)
	{
		kargatuta = kargatuPartida(gimnasioHitbox);
		if (kargatuta == 0)
		{
			egoera = GAME_OVER;
			messagePopUp("Ez dago fitxategirik kargatzeko, jokua itxiko da. . .");
		}
	}
	if (ebentoa == TECLA_w)
	{
		baimena = mapenHitboxak(ebentoa);
		pantailaGarbitu();
		if (baimena == 1)player.pos = movePlayer(0, -1);
		goraAnimaz = gorunztAnimazioa(goraAnimaz);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_a)
	{
		baimena = mapenHitboxak(ebentoa);
		pantailaGarbitu();
		ezkerreraAnimaz = ezkerreruntzAnimazioa(ezkerreraAnimaz);
		if (baimena == 1)player.pos = movePlayer(-1, 0);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_s)
	{
		baimena = mapenHitboxak(ebentoa);
		pantailaGarbitu();
		beheraAnimaz = beheruntzAnimazioa(beheraAnimaz);
		if (baimena == 1)player.pos = movePlayer(0, 1);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_d)
	{
		baimena = mapenHitboxak(ebentoa);
		pantailaGarbitu();
		if (baimena == 1)player.pos = movePlayer(1, 0);
		eskubiAnimaz = eskubiruntzAnimazioa(eskubiAnimaz);
		irudiaMugitu(player.id, player.pos.x, player.pos.y);
		irudiakMarraztu();
		SDL_RenderPresent(gRenderer);
	}
	if (ebentoa == TECLA_e)
	{
		eraikinInterakzio(gimnasioHitbox);
		if (player.kurtsoa == 1)
		{
			aprobatu = galduEdoIrabazi();
			egoera = bukaeraMezua(aprobatu, gimnasioHitbox, ebentoa);
		}
		else
		{
			if (HITBOX_npcInRange(gimnasioHitbox) == 1 && gymCompleted() == 1)
			{
				battleStage();
			}
		}
	}
	if (ebentoa == TECLA_ENTER) // EASTER EGG
	{
		player.notak.gim1 = 10;
		player.notak.gim2 = 10;
		player.notak.gim3 = 10;
		player.notak.gim4 = 10;
		player.notak.gim5 = 10;
		player.kurtsoa = 1;
	}
	if (ebentoa == TECLA_ESCAPE)
	{
		egoera = pausaMenua();
	}
	free(gimnasioHitbox);

	return egoera;
}

int beheruntzAnimazioa(int boo)
{
	if (boo == 0)
	{
		irudiaKendu(player.id);
		if (player.generoa == 1)player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
		if (player.generoa == 2)player.id = irudiaSortu(PLAYER_ABAJOIZQ);
		boo = 1;
	}
	else
	{
		irudiaKendu(player.id);
		if (player.generoa == 1)player.id = irudiaSortu(SPRITE_PLAYER_ABAJODER);
		if (player.generoa == 2)player.id = irudiaSortu(PLAYER_ABAJODER);
		boo = 0;
	}

	return boo;
}

int ezkerreruntzAnimazioa(int boo) {
	if (boo == 0) {
		irudiaKendu(player.id);
		if (player.generoa == 1)player.id = irudiaSortu(SPRITE_PLAYER_IZQDER);
		if (player.generoa == 2)player.id = irudiaSortu(PLAYER_IZQDER);
		boo = 1;
	}
	else {
		irudiaKendu(player.id);
		if (player.generoa == 1)player.id = irudiaSortu(SPRITE_PLAYER_IZQIZQ);
		if (player.generoa == 2)player.id = irudiaSortu(PLAYER_IZQIZQ);
		boo = 0;
	}
	return boo;
}

int gorunztAnimazioa(int boo) {
	if (boo == 0) {
		irudiaKendu(player.id);
		if (player.generoa == 1)player.id = irudiaSortu(SPRITE_PLAYER_ARRIBDER);
		else if (player.generoa == 2)player.id = irudiaSortu(PLAYER_ARRIBDER);
		boo = 1;
	}
	else {
		irudiaKendu(player.id);
		if (player.generoa == 1)player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
		if (player.generoa == 2)player.id = irudiaSortu(PLAYER_ARRIBIZQ);
		boo = 0;
	}
	return boo;
}

int eskubiruntzAnimazioa(int boo) {
	if (boo == 0) {
		irudiaKendu(player.id);
		if (player.generoa == 1)player.id = irudiaSortu(SPRITE_PLAYER_DERDER);
		if (player.generoa == 2)player.id = irudiaSortu(PLAYER_DERDER);
		boo = 1;
	}
	else {
		irudiaKendu(player.id);
		if (player.generoa == 1)player.id = irudiaSortu(SPRITE_PLAYER_DERIZQ);
		if (player.generoa == 2)player.id = irudiaSortu(PLAYER_DERIZQ);
		boo = 0;
	}
	return boo;
}

int ebentuaJasoGertatuBada()
{
	int ret = 0;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				ret = TECLA_w;
				break;
			case SDLK_d:
				ret = TECLA_d;
				break;
			case SDLK_a:
				ret = TECLA_a;
				break;
			case SDLK_s:
				ret = TECLA_s;
				break;
			case SDLK_ESCAPE:
				ret = TECLA_ESCAPE;
				break;
			case SDLK_RETURN:
				ret = TECLA_ENTER;
				break;
			default:
				ret = event.key.keysym.sym;
				break;
			}
			break;
		case SDL_QUIT:
			ret = GERTAERA_IRTEN;
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				ret = SAGU_BOTOIA_EZKERRA;
				break;
			case SDL_BUTTON_RIGHT:
				ret = SAGU_BOTOIA_ESKUMA;
				break;
			default:
				ret = event.button.button;
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			//ALDAGIA OROKOR BATEN EZARRIKO DUGU X ETA Y GERO FUNZTIO BATEKIN IRAKURTZEKO AZKEN EBENTUAREN POSIZIOA
			saguPos.x = event.motion.x;
			saguPos.y = event.motion.y;
			ret = SAGU_MUGIMENDUA;
			break;

		}
	}
	return ret;
}

POSIZIOA saguarenPosizioa() { return saguPos; }