#include "Menu.h"

#include "raylib.h"

#include "Palette.h"
#include "Gameplay.h"
#include "Initialize.h"
#include "Game.h"

namespace Game
{
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
			InitializeGamePVP();
		}
		if (IsKeyDown(KEY_E))
		{
			PVE = true;
			InitPlayerPointsMenu();
			InitializeGamePVE();
		}
		EndDrawing();
	}
}