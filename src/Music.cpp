#include <iostream>
#include <string>
#include <SDL_mixer.h>
#include "../include/Music.h"

Music::Music()
{
	music = nullptr;
}

Music::Music(const std::string& file)
{
	music = nullptr;
	Open(file);
}

Music::~Music()
{
	Stop();
	Mix_FreeMusic(music);
}

bool Music::IsOpen()
{
	return music != nullptr;
}

void Music::Open(const std::string& file)
{
	music = Mix_LoadMUS(file.c_str());

	if (music == nullptr)
	{
		std::cerr << "Unable to load track " << file << ": " << SDL_GetError() << std::endl;
		std::exit(-1);
	}
}

void Music::Play(int times)
{
	if (music == nullptr)
	{
		std::cerr << "Track not loaded" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop)
{
	Mix_FadeOutMusic(msToStop);
}
