#include "Initialize.h"

#include "raylib.h"

#include <iostream>
#include <time.h>

#include "Ball.h"
#include "Palette.h"
#include "Image.h"
#include "Texture.h"
#include "Gameplay.h"

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
	InitSecondPowerUP();
	RandomBallSpeed();
	ColorBall();
	LoadImageBG();
	LoadTextureBG();
}

void InitializeTime()
{
	timer = GetTime();
	oldTimer = GetTime();
	timer = clock();
	oldTimer = clock();
}