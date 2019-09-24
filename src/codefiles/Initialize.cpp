#include "../headers/Game.h"

void InitializeGlobal() 
{
	//-----------Initialize--------------
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, "Pong Elias");
	InitAudioDevice();
	bgMusic = LoadMusicStream("sounds/background-music.ogg");
	collisionWave = LoadSound("sounds/dung.wav");
	//-----------Initialize--------------
}

void InitializeGame() 
{
	SetTargetFPS(60);
	ColorBall();
	InitPlayers();
	InitBall();
	InitPowerUp();
	RandomBallSpeed();
	LoadImageBG();
	LoadTextureBG();
}