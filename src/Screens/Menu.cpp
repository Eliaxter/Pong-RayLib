#include "Menu.h"

#include "raylib.h"

#include "Palette.h"
#include "Gameplay.h"
#include "Initialize.h"

bool windowsSize = false;

void Menu()
{
	while (!windowsSize)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Play Pong Elias", 300, 160, 20, RAYWHITE);
		DrawText("To play in mode PVP press Enter", 300, 180, 20, RAYWHITE);
		DrawText("To play in mode PVE press E", 300, 200, 20, RAYWHITE);
		DrawText("To play in FULL HD Resolution press Z", 300, 220, 20, RAYWHITE);
		UpdateMusicStream(bgMusic);
		if (IsKeyDown(KEY_Z))
		{
			screenWidth = 1920;
			screenHeight = 1080;
			windowsSize = true;
		}
		if (IsKeyDown(KEY_ENTER))
		{
			InitPlayerPointsMenu();
			InitializeGame();
			InitializeTime();
			windowsSize = true;
		}
		/*if (IsKeyDown(KEY_E))
		{
			InitPlayerPointsMenu();
			InitializeGame();
			InitializeTime();
			windowsSize = true;
		}*/
		EndDrawing();
	}
}