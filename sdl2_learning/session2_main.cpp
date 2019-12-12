#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

// You shouldn't really use this statement, but it's fine for small programs
using namespace std;

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char *args[])
{

	// Pointers to our window and surface
	SDL_Surface *winSurface = NULL;
	SDL_Window *window = NULL;

	// Initialize SDL. SDL_Init will return -1 if it fails.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		return 1;
	} else {
		//cout << "init ok" << endl;
	}

	window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	if (!window) {
		cout << "Error creating window:" << SDL_GetError() << endl;
	}

#if 1
	winSurface = SDL_GetWindowSurface(window);
	if (!winSurface) {
		cout << "Error creating window:" << SDL_GetError() << endl;
	}

	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format,255,255,255));
#endif

	SDL_UpdateWindowSurface(window);
	
	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
