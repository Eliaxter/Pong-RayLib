#include "../headers/DeInit.h"

#include "raylib.h"

#include "../headers/Gameplay.h"

Music bgMusic;
Sound collisionWave;

void DeInit() 
{
	UnloadSound(collisionWave);
	UnloadMusicStream(bgMusic);
	CloseWindow();
}