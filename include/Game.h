#ifndef IDJ_2024_2_GAME_H_
#define IDJ_2024_2_GAME_H_

#include <string>
#include <SDL.h>
#include "State.h"

class Game
{
 private:
	Game(const std::string& title, int width, int height);
 public:
	~Game();

	static Game& GetInstance();

	SDL_Renderer* GetRenderer();
	State& GetState();

	void Run();
 private:
	static Game* instance;

	SDL_Renderer* renderer;
	SDL_Window* window;
	State* state;
};

#endif //IDJ_2024_2_GAME_H_
