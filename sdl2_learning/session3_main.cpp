#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

// You shouldn't really use this statement, but it's fine for small programs
using namespace std;

bool init();
void kill();
bool load();

SDL_Window *window;
SDL_Surface *winSurface;
SDL_Surface *image1;
SDL_Surface *image2;

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char *args[])
{
	if (!init()) return 1;
	if (!load()) return 1;

	SDL_BlitSurface(image1, NULL, winSurface, NULL);
	
	SDL_Rect dest;
	dest.x = 160;
	dest.y = 120;
	dest.w = 320;
	dest.h = 240;
	SDL_BlitScaled(image2, NULL, winSurface, &dest);

	SDL_UpdateWindowSurface(window);

	SDL_Delay(3000);
	kill();

	return 0;
}

bool load()
{
	SDL_Surface *temp1, *temp2;
	temp1 = SDL_LoadBMP("1.BMP");
	temp2 = SDL_LoadBMP("2.BMP");
	if (!temp1 || !temp2) {
		cout << "Error Loading image:" << SDL_GetError() << endl;
	}
	image1 = SDL_ConvertSurface(temp1, winSurface->format, 0);
	image2 = SDL_ConvertSurface(temp2, winSurface->format, 0);

	SDL_FreeSurface(temp1);
	SDL_FreeSurface(temp2);
	if (!image1 || !image2) {
		cout << "Error converting surface:" << SDL_GetError() << endl;
		return false;
	}

	return true;
}

bool init()
{
	// Initialize SDL. SDL_Init will return -1 if it fails.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		return false;
	}

	window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	if (!window) {
		cout << "Error creating window:" << SDL_GetError() << endl;
		return false;
	}

	winSurface = SDL_GetWindowSurface(window);
	if (!winSurface) {
		cout << "Error creating window:" << SDL_GetError() << endl;
		return false;
	}

	return true;
}

void kill()
{
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);

	SDL_DestroyWindow(window);
	SDL_Quit();
}