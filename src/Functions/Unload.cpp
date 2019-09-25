#include "Unload.h"

#include "raylib.h"

#include "Gameplay.h"

Music bgMusic;
Sound collisionWave;

void Unload() 
{
	UnloadSound(collisionWave);
	UnloadMusicStream(bgMusic);
	CloseWindow();
}