#include "FinalMenu.h"

#include "raylib.h"

#include "Game.h"
#include "Gameplay.h"
#include "Palette.h"
#include "Unload.h"

namespace Game
{
	void FinalMenu()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("End of Game!", 300, 160, 20, RAYWHITE);
		CheckPlayerWins();
		DrawText("Return to Main Menu: M", 300, 220, 20, RAYWHITE);
		StopMusicStream(bgMusic);
		if (IsKeyDown(KEY_M))
		{
			pointsP1 = startPoints;
			pointsP2 = startPoints;
			if (PVE == true)
			{
				stateMenu = true;
				stateEndMenu = false;
				stateGame = false;
				PVE = false;
			}
			StopMusicStream(bgMusic);

		}
		DrawText("Play Again: Y/N", 300, 200, 20, RAYWHITE);
		if (IsKeyDown(KEY_Y))
		{
			pointsP1 = startPoints;
			pointsP2 = startPoints;
			games = initialGames;
			if (PVE == true)
			{
				stateMenu = false;
				stateGame = true;
				stateEndMenu = false;
			}
			else
			{
				stateMenu = false;
				stateGame = true;
				stateEndMenu = false;
				PVE = false;
			}
		}
		if (IsKeyDown(KEY_N))
		{
			stateMenu = false;
			stateGame = false;
			stateEndMenu = false;
			PVE = false;
			CloseWindow();
		}
		EndDrawing();
	}
}