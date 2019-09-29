#include "Initialize.h"

#include "raylib.h"

#include <iostream>
#include <time.h>

#include "Ball.h"
#include "Palette.h"
#include "Image.h"
#include "Texture.h"
#include "Gameplay.h"

namespace Game
{
	void InitializeGlobal()
	{
		srand(time(NULL));
		InitWindow(screenWidth, screenHeight, "Pong Elias");
		InitAudioDevice();
		bgMusic = LoadMusicStream("sounds/background-music.ogg");
		collisionWave = LoadSound("sounds/dung.wav");
	}

	void InitializeGamePVP()
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

	void InitializeGamePVE()
	{
		SetTargetFPS(60);
		PlayMusicStream(bgMusic);
		InitPlayers();
		InitPowerUp();
		InitSecondPowerUP();
		RandomBallSpeed();
		ColorBall();
		LoadImageBG();
		LoadTextureBG();
	}
}