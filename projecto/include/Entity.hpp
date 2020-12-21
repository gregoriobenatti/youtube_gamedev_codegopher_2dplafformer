#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "Math.hpp"

class Entity
{
public:
	Entity(Vector2f p_position, SDL_Texture* p_texture);
	Vector2f& getPosition()
	{
		return position;
	}
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();

private:
	Vector2f position;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};
