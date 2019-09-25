#include "Menu.h"

#include "raylib.h"

#include "Palette.h"
#include "Gameplay.h"
#include "Initialize.h"

void Menu()
{
	/*
	if (!IsMusicPlaying(bgMusic))
	{
		PlayMusicStream(bgMusic);
	}*/

	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Pong Elias", 300, 160, 20, RAYWHITE);
	DrawText("Press Enter to Play Pong Elias", 300, 180, 20, RAYWHITE);
	UpdateMusicStream(bgMusic);
	if (IsKeyDown(KEY_ENTER))
	{
		InitPlayerPointsMenu();
		InitializeGame();
		InitializeTime();
	}
	EndDrawing();
}