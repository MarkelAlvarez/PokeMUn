#ifndef SDLHASIERATU_H
#define SDLHASIERATU_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <SDL.h>
#include <time.h>

#define GAME_OVER -1
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int SDLHasi();
int mediaKargatu();
void bukatu();
void denaHasi();
int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest);

SDL_Renderer* gRenderer;

#endif
