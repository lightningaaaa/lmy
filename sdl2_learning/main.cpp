	
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

using namespace std;

bool init();
void kill();
bool loop();

// Variables to hold our window and surfaces
SDL_Window* window;
SDL_Renderer *renderer;

int main(int argc, char** args) {

	if ( !init() ) return 1;

	while ( loop() ) {
		// wait before processing the next frame
		SDL_Delay(10); 
	}

	kill();
	return 0;
}

bool loop() {
	static const unsigned char *keys = SDL_GetKeyboardState(NULL);

	SDL_Event e;
	SDL_Rect r;

	static int mx0 = -1, my0 = -1, mx1 = -1, my1 = -1;
	// Blit image to entire window
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	while( SDL_PollEvent( &e ) != 0 ) {
		switch (e.type) {
			case SDL_QUIT:
				return false;
			case SDL_MOUSEBUTTONDOWN:
				mx0 = e.button.x;
				my0 = e.button.y;
				break;
			case SDL_MOUSEMOTION:
				mx1 = e.motion.x;
				my1 = e.motion.y;
				break;
			case SDL_MOUSEBUTTONUP:
				mx0 = my0 = mx1 = my1 = -1;
				break;
		}
	}

	SDL_SetRenderDrawColor(renderer,0,0,0,255);

	if (keys[SDL_SCANCODE_1]) {
		SDL_RenderDrawPoint(renderer, 10, 10);
	}
	if (keys[SDL_SCANCODE_2]) {
		SDL_RenderDrawLine(renderer, 10, 20, 10, 100);
	}

	if (keys[SDL_SCANCODE_3]) {
		r.x = 20;
		r.y = 20;
		r.w = 100;
		r.h = 100;
		SDL_RenderFillRect(renderer, &r);
	}

	if (mx0 != -1) {
		r.x = mx0;
		r.y = my0;
		r.w = mx1 - mx0;
		r.h = my1 - my0;
		SDL_RenderDrawRect(renderer, &r);
	}

	SDL_RenderPresent(renderer);
	return true;
}

bool init() {
	// See last example for comments
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		return false;
	} 

	window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );
	if ( !window ) {
		cout << "Error creating window: " << SDL_GetError()  << endl;
		return false;
	}

	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if ( !renderer ) {
		cout << "Error getting surface: " << SDL_GetError() << endl;
		return false;
	}

	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderClear(renderer);
	return true;
}

void kill() {

	SDL_DestroyRenderer(renderer);
	// Quit
	SDL_DestroyWindow( window );
	SDL_Quit();
}