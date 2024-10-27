#ifndef IDJ_2024_2_SPRITE_H_
#define IDJ_2024_2_SPRITE_H_

#include <string>
#include <SDL.h>

class Sprite
{
 public:
	Sprite();
	Sprite(const std::string& file);

	~Sprite();

	void Open(const std::string& file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y);

	int GetWidth();
	int GetHeight();
	bool IsOpen();
 private:
	SDL_Texture* texture{};
	SDL_Rect clipRect{};
	int width{}, height{};
};

#endif //IDJ_2024_2_SPRITE_H_
