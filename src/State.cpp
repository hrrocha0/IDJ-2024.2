#include <SDL.h>
#include "../include/State.h"

State::State()
{
	quitRequested = false;

	bg = Sprite();
	bg.Open("../resources/img/Background.png");
	bg.SetClip(0, 0, 1200, 900);

	music = Music();
	music.Open("../resources/audio/BGM.wav");
	music.Play();
}

bool State::QuitRequested()
{
	return quitRequested;
}

void State::LoadAssets()
{

}

void State::Update(float dt)
{
	if (SDL_QuitRequested())
	{
		quitRequested = true;
	}
}

void State::Render()
{
	bg.Render(0, 0);
}
