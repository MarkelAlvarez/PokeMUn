#include "funtzioak.h"
#include "kontrolak.h"
#include "irudiak.h"
#include "hitbox.h"

int galderenHitboxa()
{
	POSIZIOA saguPos;
	int ebentua, erantzuna = 0;

	saguPos = saguarenPosizioa();
	ebentua = ebentuaJasoGertatuBada();
	if (ebentua == SAGU_BOTOIA_EZKERRA)
	{
		//ArrIzq
		if ((saguPos.x >= 40 && saguPos.x <= 300) && (saguPos.y >= 386 && saguPos.y <= 421))
		{
			erantzuna = ERANTZUN1;
			printf("ikutu du 1\n");
		}
		//ArrDer
		if ((saguPos.x >= 340 && saguPos.x <= 600) && (saguPos.y >= 386 && saguPos.y <= 421))
		{
			erantzuna = ERANTZUN2;
			printf("ikutu du 2\n");
		}
		//AbaIzq
		if ((saguPos.x >= 40 && saguPos.x <= 300) && (saguPos.y >= 424 && saguPos.y <= 460))
		{
			erantzuna = ERANTZUN3;
			printf("ikutu du 3\n");
		}
		//AbaDer
		if ((saguPos.x >= 340 && saguPos.x <= 600) && (saguPos.y >= 424 && saguPos.y <= 460))
		{
			erantzuna = ERANTZUN4;
			printf("ikutu du 4\n");
		}
	}

	return erantzuna;
}

int mapenHitboxak(int tecla) 
{
	int baimena = 1;

	if (player.mapa == MAPA_MUNDUA)
	{
		baimena = HITBOX_mundua(tecla);
	}
	else if (player.mapa == MAPA_ETXEA)
	{
		baimena = HITBOX_hasieraEtxea(tecla);
	}
	else if (player.mapa == MAPA_GIM1)
	{
		baimena = HITBOX_gim1(tecla);
	}
	else if (player.mapa == MAPA_GIM2)
	{
		baimena = HITBOX_gim2(tecla);
	}
	else if (player.mapa == MAPA_GIM3)
	{
		baimena = HITBOX_gim3(tecla);
	}
	else if (player.mapa == MAPA_GIM4)
	{
		baimena = HITBOX_gim4(tecla);
	}
	else if (player.mapa == MAPA_GIM5)
	{
		baimena = HITBOX_gim5(tecla);
	}
	else if (player.mapa == MAPA_NOTA)
	{
		baimena = HITBOX_notaMapa(tecla);
	}
	return baimena;
}

int HITBOX_mundua(int tecla)
{
	int baimena = 1;
	
	//BORDEAK
	if (player.pos.y > 430 && tecla == TECLA_s) baimena = 0;
	if (player.pos.y < 20 && tecla == TECLA_w) baimena = 0;
	if (player.pos.x < 10 && tecla == TECLA_a) baimena = 0;
	if (player.pos.x > 610 && tecla == TECLA_d) baimena = 0;

	if (player.pos.x > 265 && player.pos.x < 590 && player.pos.y < 80 && player.pos.y > 70 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x > 245 && player.pos.x < 270 && player.pos.y < 85 && player.pos.y>30 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 265 && player.pos.x < 590 && player.pos.y > 20 && player.pos.y < 45 && tecla == TECLA_s)baimena = 0;
	if (player.pos.x > 595 && player.pos.x < 620 && player.pos.y < 100 && player.pos.y>  30 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 570 && player.pos.x < 580 && player.pos.y < 125 && player.pos.y>60 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 580 && player.pos.x < 640 && player.pos.y < 135 && player.pos.y > 125 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x > 580 && player.pos.x < 640 && player.pos.y > 155 && player.pos.y < 190 && tecla == TECLA_s)baimena = 0;
	if (player.pos.x > 560 && player.pos.x < 590 && player.pos.y < 230 && player.pos.y>160 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 580 && player.pos.x < 640 && player.pos.y < 230 && player.pos.y > 200 && tecla == TECLA_w)baimena = 0;

	//1. ERAIKINA
	if (player.pos.x > 25 && player.pos.x < 118 && player.pos.y < 380 && player.pos.y > 360 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x < 118 && player.pos.x > 110 && player.pos.y < 375 && player.pos.y>280 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 8 && player.pos.x < 30 && player.pos.y < 375 && player.pos.y>280 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 25 && player.pos.x < 118 && player.pos.y > 260 && player.pos.y < 300 && tecla == TECLA_s)baimena = 0;
	//2.ERAIKINA
	if (player.pos.x > 455 && player.pos.x < 560 && player.pos.y < 275 && player.pos.y > 260 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x < 560 && player.pos.x > 550 && player.pos.y < 275 && player.pos.y>160 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 440 && player.pos.x < 470 && player.pos.y < 275 && player.pos.y>160 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 455 && player.pos.x < 560 && player.pos.y > 155 && player.pos.y < 180 && tecla == TECLA_s)baimena = 0;
	//3.ERAIKINA
	if (player.pos.x > 155 && player.pos.x < 230 && player.pos.y < 215 && player.pos.y > 100 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x < 240 && player.pos.x > 220 && player.pos.y < 205 && player.pos.y>95 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 150 && player.pos.x < 160 && player.pos.y < 205 && player.pos.y>95 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 160 && player.pos.x < 240 && player.pos.y >90 && player.pos.y < 130 && tecla == TECLA_s)baimena = 0;
	//4. ERAIKINA
	if (player.pos.x > 0 && player.pos.x < 150 && player.pos.y < 120 && player.pos.y > 20 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x < 160 && player.pos.x > 140 && player.pos.y < 120 && player.pos.y>20 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 0 && player.pos.x < 150 && player.pos.y >20 && player.pos.y < 50 && tecla == TECLA_s)baimena = 0;
	//5. GARREN ERAIKINA
	if (player.pos.x > 435 && player.pos.x < 555 && player.pos.y < 135 && player.pos.y > 90 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x < 555 && player.pos.x > 550 && player.pos.y < 135 && player.pos.y>80 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 435 && player.pos.x < 460 && player.pos.y < 135 && player.pos.y>80 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 455 && player.pos.x < 555 && player.pos.y >60 && player.pos.y < 120 && tecla == TECLA_s)baimena = 0;
	//EXTEA
	if (player.pos.x > 535 && player.pos.x < 615 && player.pos.y < 385 && player.pos.y > 360 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x < 615 && player.pos.x > 600 && player.pos.y < 385 && player.pos.y>330 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 530 && player.pos.x < 540 && player.pos.y < 385 && player.pos.y>330 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 535 && player.pos.x < 615 && player.pos.y >320 && player.pos.y < 350 && tecla == TECLA_s)baimena = 0;

	return baimena;
}

int HITBOX_hasieraEtxea(int tecla)
{
	int baimena = 1;
	
	
	//Azpiko bordea
	if ((player.pos.x >= 174 && player.pos.x <= 466) && (player.pos.y >= 297 && player.pos.y <= 307) && tecla == TECLA_s) baimena = 0;
	//Ezkerreko bordea
	if ((player.pos.y >= 153 && player.pos.y <= 286) && (player.pos.x >= 174 && player.pos.x <= 176) && tecla == TECLA_a) baimena = 0;
	//Eskubiko bordea
	if ((player.pos.y >= 153 && player.pos.y <= 286) && (player.pos.x >= 440 && player.pos.x <= 444) && tecla == TECLA_d) baimena = 0;
	//Goiko bordea
	if ((player.pos.x >= 174 && player.pos.x <= 466) && (player.pos.y >= 150 && player.pos.y <= 160) && tecla == TECLA_w) baimena = 0;
	//Mazetak ezkerra
	if ((player.pos.y >= 258 && player.pos.y <= 265) && (player.pos.x >= 175 && player.pos.x <= 190) && tecla == TECLA_s) baimena = 0;

	if ((player.pos.y <= 300 && player.pos.y >= 293) && (player.pos.x == 197) && tecla == TECLA_a) baimena = 0;
	//Mazetak eskubi
	if ((player.pos.y >= 258 && player.pos.y <= 265)&& (player.pos.x >= 442 && player.pos.x <= 460) && tecla == TECLA_s) baimena = 0;

	if ((player.pos.y <= 300 && player.pos.y >= 293) && (player.pos.x == 418 && player.pos.x <= 428) && tecla == TECLA_d) baimena = 0;

	return baimena;
}

int HITBOX_gim1(int tecla)
{
	int baimena = 1;

	//Pasillo
	if ((player.pos.y >= 343 && player.pos.y <= 392) && (player.pos.x == 288) && tecla == TECLA_a) baimena = 0;
	if ((player.pos.y >= 343 && player.pos.y <= 392) && (player.pos.x == 330) && tecla == TECLA_d) baimena = 0;
	if ((player.pos.x >= 288 && player.pos.x <= 330) && (player.pos.y == 392) && tecla == TECLA_s) baimena = 0;
	//Azpiko bordea
	if ((player.pos.x >= 351 && player.pos.x <= 428) && (player.pos.y == 329) && tecla == TECLA_s) baimena = 0;
	if ((player.pos.x >= 190 && player.pos.x <= 281) && (player.pos.y == 329) && tecla == TECLA_s) baimena = 0;
	//Ezkerreko bordea
	if ((player.pos.y >= 105 && player.pos.y <= 329) && (player.pos.x == 190) && tecla == TECLA_a) baimena = 0;
	//Eskubiko bordea
	if ((player.pos.y >= 105 && player.pos.y <= 329) && (player.pos.x == 428) && tecla == TECLA_d) baimena = 0;
	//Goiko bordea
	if ((player.pos.x >= 190 && player.pos.x <= 428) && (player.pos.y == 105) && tecla == TECLA_w) baimena = 0;

	return baimena;
}

int HITBOX_gim2(int tecla)
{
	int baimena = 1;

	//Azpiko bordea
	if ((player.pos.x >= 109 && player.pos.x <= 531) && (player.pos.y >= 360 && player.pos.y <= 367) && tecla == TECLA_s) baimena = 0;
	//Ezkerreko bordea
	if ((player.pos.y >= 101 && player.pos.y <= 365) && (player.pos.x >= 110 && player.pos.x <= 115) && tecla == TECLA_a) baimena = 0;
	//Eskubiko bordea
	if ((player.pos.y >= 101 && player.pos.y <= 365) && (player.pos.x >= 500 && player.pos.x <= 510) && tecla == TECLA_d) baimena = 0;
	//Goiko bordea
	if ((player.pos.x >= 109 && player.pos.x <= 531) && (player.pos.y >= 100 && player.pos.y <= 107) && tecla == TECLA_w) baimena = 0;

	return baimena;
}

int HITBOX_gim3(int tecla)
{
	int baimena = 1;

	//PASILLO
	if ((player.pos.y >= 263 && player.pos.y <= 420) && (player.pos.x >= 291 && player.pos.x <= 295) && tecla == TECLA_a) baimena = 0;
	if ((player.pos.y >= 263 && player.pos.y <= 420) && (player.pos.x >= 319) && tecla == TECLA_d) baimena = 0;
	//Azpiko bordea
	if ((player.pos.x >= 242 && player.pos.x <= 284) && (player.pos.y >= 246 && player.pos.y <= 256) && tecla == TECLA_s) baimena = 0;
	if ((player.pos.x >= 333 && player.pos.x <= 382) && (player.pos.y >= 246 && player.pos.y <= 256) && tecla == TECLA_s) baimena = 0;
	//Ezkerreko bordea
	if ((player.pos.y >= 144 && player.pos.y <= 249) && (player.pos.x >= 232 && player.pos.x <= 242) && tecla == TECLA_a) baimena = 0;
	//Eskubiko bordea
	if ((player.pos.y >= 144 && player.pos.y <= 325) && (player.pos.x >= 375 && player.pos.x <= 389) && tecla == TECLA_d) baimena = 0;
	//Goiko bordea
	if ((player.pos.x >= 228 && player.pos.x <= 382) && (player.pos.y >= 141 && player.pos.y <= 151)&& tecla == TECLA_w) baimena = 0;
	
	return baimena;
}

int HITBOX_gim4(int tecla)
{
	int baimena = 1;

	//Azpiko bordea
	if ((player.pos.x >= 221 && player.pos.x <= 420) && (player.pos.y >= 318 && player.pos.y <=328) && tecla == TECLA_s) baimena = 0;
	//Ezkerreko bordea
	if ((player.pos.y >= 144 && player.pos.y <= 325) && (player.pos.x >= 218 && player.pos.x <= 228) && tecla == TECLA_a) baimena = 0;
	//Eskubiko bordea
	if ((player.pos.y >= 144 && player.pos.y <= 325) && (player.pos.x >= 400 && player.pos.x <= 410) && tecla == TECLA_d) baimena = 0;
	//Goiko bordea
	if ((player.pos.x >= 221 && player.pos.x <= 420) && (player.pos.y >= 157 && player.pos.y <= 167) && tecla == TECLA_w) baimena = 0;

	return baimena;
}

int HITBOX_gim5(int tecla)
{
	int baimena = 1;
	
	//Azpiko bordea
	if ((player.pos.x >= 210 && player.pos.x <= 430) && (player.pos.y >= 343 && player.pos.y <= 350) && tecla == TECLA_s) baimena = 0;
	//Ezkerreko bordea
	if ((player.pos.y >= 136 && player.pos.y <= 360) && (player.pos.x >= 212 && player.pos.x <= 222) && tecla == TECLA_a) baimena = 0;
	//Eskubiko bordea
	if ((player.pos.y >= 136 && player.pos.y <= 360) && (player.pos.x >= 409 && player.pos.x <= 419) && tecla == TECLA_d) baimena = 0;
	//Goiko bordea
	if ((player.pos.x >= 210 && player.pos.x <= 430) && (player.pos.y >= 133 && player.pos.y <= 143) && tecla == TECLA_w) baimena = 0;

	return baimena;
}

int HITBOX_notaMapa(int tecla) 
{
	int baimena = 1;
	if (player.pos.x > 0 && player.pos.x < 170 && player.pos.y < 140 && player.pos.y > 90 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x > 165 && player.pos.x < 475 && player.pos.y < 360 && player.pos.y > 340 && tecla == TECLA_w)baimena = 0;
	if (player.pos.x > 120 && player.pos.x < 520 && player.pos.y < 450 && player.pos.y > 370 && tecla == TECLA_s)baimena = 0;
	if (player.pos.x > 0 && player.pos.x < 125 && player.pos.y < 360 && player.pos.y > 160 && tecla == TECLA_s)baimena = 0;
	if (player.pos.x > 460 && player.pos.x < 485 && player.pos.y < 350 && player.pos.y > 290 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 490 && player.pos.x < 530 && player.pos.y < 404 && player.pos.y > 290 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 120 && player.pos.x < 137 && player.pos.y < 500 && player.pos.y > 180 && tecla == TECLA_a)baimena = 0;
	if (player.pos.x > 145 && player.pos.x < 153 && player.pos.y < 330 && player.pos.y >130 && tecla == TECLA_d)baimena = 0;
	if (player.pos.x > 460 && player.pos.x < 490 && player.pos.y < 290 && player.pos.y > 300 && tecla == TECLA_w)baimena = 0;
	return baimena;
}

int HITBOX_npcInRange(GYM* boss)
{
	int baimena = 0;

	if ((player.pos.x >= boss->boss.x - 7 && player.pos.x <= boss->boss.x + 32) && (player.pos.y >= boss->boss.y && player.pos.y <= boss->boss.y + 45))
	{
		baimena = 1;
	}

	return baimena;
}