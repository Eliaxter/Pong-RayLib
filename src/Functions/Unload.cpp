#include "Unload.h"

#include "raylib.h"

#include "Gameplay.h"

namespace Game
{
	Music bgMusic;
	Sound collisionWave;

	void Unload()
	{
		UnloadSound(collisionWave);
		UnloadMusicStream(bgMusic);
		CloseWindow();
	}
}