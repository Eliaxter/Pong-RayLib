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
		UpdateMusicStream(bgMusic);
		if (IsKeyDown(KEY_ENTER))
		{
			InitPlayerPointsMenu();
			InitializeGamePVP();
			pointsP1 = startPoints;
			pointsP2 = startPoints;
			games = initialGames;
			timer = 0.0f;
			stateMenu = false;
			stateGame = true;
		}
		EndDrawing();
	}
}