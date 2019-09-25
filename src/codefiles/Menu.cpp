#include "../headers/Menu.h"

#include "raylib.h"

#include "../headers/Palette.h"
#include "../headers/Gameplay.h"
#include "../headers/Initialize.h"

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
	}
	EndDrawing();
}