#ifndef IDJ_2024_2_STATE_H_
#define IDJ_2024_2_STATE_H_

#include "Sprite.h"
#include "Music.h"

class State
{
 public:
	State();

	bool QuitRequested();

	void LoadAssets();
	void Update(float dt);
	void Render();
 private:
	Sprite bg;
	Music music;
	bool quitRequested;
};

#endif //IDJ_2024_2_STATE_H_
