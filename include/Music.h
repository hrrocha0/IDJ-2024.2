#ifndef IDJ_2024_2_MUSIC_H_
#define IDJ_2024_2_MUSIC_H_

#include <SDL_mixer.h>

class Music
{
 public:
	Music();
	Music(const std::string& file);

	~Music();

	bool IsOpen();

	void Open(const std::string& file);
	void Play(int times = -1);
	void Stop(int msToStop = 1500);
 private:
	Mix_Music* music;
};

#endif //IDJ_2024_2_MUSIC_H_
