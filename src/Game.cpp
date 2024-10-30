#include <iostream>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "../include/Game.h"

#define SDL_FLAGS (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)
#define IMG_FLAGS (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)
#define MIX_FLAGS (MIX_INIT_MP3 | MIX_INIT_OGG)

Game* Game::instance = nullptr;

Game::Game(const std::string& title, int width, int height)
{
	if (instance != nullptr)
	{
		std::cerr << "Game instance already exists" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	instance = this;

	if (SDL_Init(SDL_FLAGS) < 0)
	{
		std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (!(IMG_Init(IMG_FLAGS) & IMG_FLAGS))
	{
		std::cerr << "Unable to initialize SDL_image: " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (!(Mix_Init(MIX_FLAGS) & MIX_FLAGS))
	{
		std::cerr << "Unable to initialize SDL_mixer: " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(32);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (window == nullptr || renderer == nullptr)
	{
		std::cerr << "Unable to create window: " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	state = new State();
}

Game::~Game()
{
	delete state;

	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Game& Game::GetInstance()
{
	if (instance == nullptr)
	{
		new Game("Henrique Rodrigues Rocha - 211036061", 1200, 900);
	}
	return *instance;
}

SDL_Renderer* Game::GetRenderer()
{
	return renderer;
}

State& Game::GetState()
{
	return *state;
}

void Game::Run()
{
	while (!state->QuitRequested())
	{
		state->Update(0);
		state->Render();

		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}
