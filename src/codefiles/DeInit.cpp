#include "../headers/DeInit.h"

#include "raylib.h"

#include "../headers/Gameplay.h"

void DeInit() 
{
	UnloadSound(collisionWave);
	UnloadMusicStream(bgMusic);
}