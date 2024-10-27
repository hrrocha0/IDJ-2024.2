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
}

void Music::Play(int times)
{
	Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop)
{
	Mix_FadeOutMusic(msToStop);
}
