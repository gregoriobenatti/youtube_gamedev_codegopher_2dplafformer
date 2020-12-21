#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"


int main(int argc, char* argsp[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "SDL_Init has failed! SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "IMG_Inits has failed! SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	RenderWindow window("Projecto Game v1.0", 1280, 720);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	// Entity entities[4] = {
	// 	Entity(32, 100, grassTexture),
	// 	Entity(64, 100, grassTexture),
	// 	Entity(96, 100, grassTexture),
	// 	Entity(128, 68, grassTexture)
	// };
	std::vector<Entity> entities2 = {
		Entity(Vector2f(32, 100), grassTexture),
		Entity(Vector2f(64, 100), grassTexture),
		Entity(Vector2f(96, 100), grassTexture),
		Entity(Vector2f(128, 68), grassTexture)
	};
	
	{
		Entity extra_grass(Vector2f(160, 68), grassTexture);
		entities2.push_back(extra_grass);
	}

	bool gameRunning = true;
	SDL_Event event;
	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = Utils::hireTimeInSeconds();

	while(gameRunning)
	{
		int startTicks = SDL_GetTicks();
		float newTime = Utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		while(accumulator >= timeStep)
		{
			// Get your controls and events
			while(SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					gameRunning = false;
				}
			}

			accumulator -= timeStep;
		}

		//const float alpha = accumulator;
		
		window.clear();
		for (Entity& e : entities2)
		{
			window.render(e);
		}

		window.display();

		int frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.getRefreshRate())
		{
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
