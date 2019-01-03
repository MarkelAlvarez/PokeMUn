#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <SDL.h>
#include <Windows.h>

typedef struct
{
	int x;
	int y;

}POSIZIOA;

typedef struct
{
	int id;
	//Bere posizioa aldatzeko/fitxategian gordetzeko
	POSIZIOA pos;

}PLAYER;

void ebentoaDetektatu(int ebentoa);
POSIZIOA movePlayer(int signX, int signY);
int ebentuaJasoGertatuBada();
void karratuaMarraztu(int x, int y);
int rngGenerator(int min, int max);
void randomColor();

#endif