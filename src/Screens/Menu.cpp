#include "Menu.h"

#include "raylib.h"

#include "Palette.h"
#include "Gameplay.h"
#include "Initialize.h"


void Menu()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Play Pong Elias", 300, 160, 20, RAYWHITE);
	DrawText("To play in mode PVP press Enter", 300, 180, 20, RAYWHITE);
	DrawText("To play in mode PVE press E", 300, 200, 20, RAYWHITE);
	UpdateMusicStream(bgMusic);
	if (IsKeyDown(KEY_ENTER))
	{
		InitPlayerPointsMenu();
		InitializeGame();
		InitializeTime();
	}
	if (IsKeyDown(KEY_E))
	{
		InitPlayerPointsMenu();
		InitializeGame();
		InitializeTime();
	}
	EndDrawing();
}