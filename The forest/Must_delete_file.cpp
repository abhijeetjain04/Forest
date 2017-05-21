#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#define emma
#ifndef emma

int main(int argc, char *argv[])
{
	bool quit = false;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = NULL;
	SDL_Window* window1 = NULL;

	window = SDL_CreateWindow("My first RPG!", 100, 100, 600, 500, SDL_WINDOW_SHOWN);
	window1 = SDL_CreateWindow("My asdasd RPG!", 100, 100, 600, 500, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		return 0;
	}

	SDL_Renderer* renderer = NULL;
	SDL_Renderer* renderer1 = NULL;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event* mainEvent = new SDL_Event();

	SDL_Texture* grass_image = NULL;
	grass_image = IMG_LoadTexture(renderer,"data/grass.bmp");

	SDL_Texture* grass_image1 = NULL;
	grass_image1 = IMG_LoadTexture(renderer1,"data/grass.bmp");

	if (grass_image == NULL)
	{
		std::cout << "Couldn't Load Grass!" << std::endl;
	}

	SDL_Rect grass_rect;
	grass_rect.x = 0;
	grass_rect.y = 0;
	grass_rect.w = 600;
	grass_rect.h = 500;

	SDL_Rect grass_rect1;
	grass_rect1.x = 0;
	grass_rect1.y = 0;
	grass_rect1.w = 600;
	grass_rect1.h = 500;

	SDL_Texture* bob_image = NULL;
	bob_image = IMG_LoadTexture(renderer,"data/bob.png");

	SDL_Texture* bob_image1 = NULL;
	bob_image1 = IMG_LoadTexture(renderer1,"data/bob.png");

	if (bob_image == NULL)
	{
		std::cout << "Couldn't Load Bob!" << std::endl;
	}

	SDL_Rect bob_rect;
	bob_rect.x = 300;
	bob_rect.y = 250;
	bob_rect.w = 100;
	bob_rect.h = 180;

	SDL_Rect bob_rect1;
	bob_rect1.x = 300;
	bob_rect1.y = 250;
	bob_rect1.w = 100;
	bob_rect1.h = 180;

	while (!quit && mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);


		SDL_RenderCopy(renderer,grass_image, NULL, &grass_rect);
		SDL_RenderCopy(renderer,bob_image, NULL, &bob_rect);

		SDL_RenderCopy(renderer1,grass_image1, NULL, &grass_rect1);
		SDL_RenderCopy(renderer1,bob_image1, NULL, &bob_rect1);


		SDL_RenderPresent(renderer);
		SDL_RenderPresent(renderer1);
	}

	SDL_DestroyTexture(grass_image);
	SDL_DestroyTexture(bob_image);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyRenderer(renderer1);
	delete mainEvent;

	return 0;
}

# endif emma