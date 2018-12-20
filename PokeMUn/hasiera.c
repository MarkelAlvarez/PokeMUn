#include "funtzioak.h"
#include "SDLHasieratu.h"

int main(int argc, char const *argv[])
{
	punteroak();

	if (!SDLHasi())
	{
		printf("\n Errorea egon da hasieratzean.");
		printf("\n %s", SDL_GetError());
	}
	else
	{
		if (!mediaKargatu())
		{
			printf("\n Errorea egon da media kargatzerakoan.");
			printf("\n %s", SDL_GetError());
		}
		else
		{
			SDL_BlitSurface(HelloWorld, NULL, screenSurface, NULL);
			SDL_UpdateWindowSurface(window);
		}
		SDL_Delay(2000);
	}

	return 0;
}