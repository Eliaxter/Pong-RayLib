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
		bgMusic = LoadMusicStream("assets/music/bg-music-new.ogg");
		collisionWave = LoadSound("assets/sounds/collision.wav");
	}

	void InitializeGamePVP()
	{
		SetTargetFPS(60);
		PlayMusicStream(bgMusic);
		ColorBall();
		InitPlayers();
		InitBall();
		InitPowerUp();
		InitSecondPowerUP();
		LoadImageBG();
		LoadTextureBG();
	}
}