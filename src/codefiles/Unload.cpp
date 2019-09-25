#include "../headers/Unload.h"

#include "raylib.h"

#include "../headers/Gameplay.h"

Music bgMusic;
Sound collisionWave;

void Unload() 
{
	UnloadSound(collisionWave);
	UnloadMusicStream(bgMusic);
	CloseWindow();
}