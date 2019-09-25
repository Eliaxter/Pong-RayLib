#include "../headers/Initialize.h"

#include "raylib.h"

#include <iostream>
#include <time.h>

#include "../headers/Ball.h"
#include "../headers/Palette.h"
#include "../headers/Image.h"
#include "../headers/Texture.h"
#include "../headers/Gameplay.h"

void InitializeGlobal() 
{
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, "Pong Elias");
	InitAudioDevice();
	bgMusic = LoadMusicStream("sounds/background-music.ogg");
	collisionWave = LoadSound("sounds/dung.wav");
}

void InitializeGame() 
{
	SetTargetFPS(60);
	PlayMusicStream(bgMusic);
	InitPlayers();
	InitBall();
	InitPowerUp();
	RandomBallSpeed();
	ColorBall();
	LoadImageBG();
	LoadTextureBG();
}