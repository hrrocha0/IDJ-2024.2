#include <iostream>
#include <string>
#include <SDL_image.h>
#include "../include/Sprite.h"
#include "../include/Game.h"

Sprite::Sprite()
{
	texture = nullptr;
}

Sprite::Sprite(const std::string& file)
{
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

void Sprite::Open(const std::string& file)
{
	Game& game = Game::GetInstance();

	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}
	texture = IMG_LoadTexture(game.GetRenderer(), file.c_str());

	if (texture == nullptr)
	{
		std::cerr << "Unable to load texture " << file << ": " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render(int x, int y)
{
	Game& game = Game::GetInstance();

	if (texture == nullptr)
	{
		std::cerr << "Texture not loaded" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	SDL_RenderCopy(game.GetRenderer(), texture, &clipRect, new SDL_Rect{ x, y, clipRect.w,
		clipRect.h });
}

int Sprite::GetWidth()
{
	return width;
}

int Sprite::GetHeight()
{
	return height;
}

bool Sprite::IsOpen()
{
	return texture != nullptr;
}
