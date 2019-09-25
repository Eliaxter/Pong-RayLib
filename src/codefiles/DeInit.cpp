#include "../headers/DeInit.h"

#include "raylib.h"

#include "../headers/Gameplay.h"

Music bgMusic; //music
Sound collisionWave; //sound

void DeInit() 
{
	UnloadSound(collisionWave);
	UnloadMusicStream(bgMusic);
}