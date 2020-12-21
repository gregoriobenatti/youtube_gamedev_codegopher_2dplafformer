#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

Entity::Entity(Vector2f p_position, SDL_Texture* p_texture) 
:position(p_position), texture(p_texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

SDL_Texture* Entity::getTexture()
{
	return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}
