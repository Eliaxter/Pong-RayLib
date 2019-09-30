#include "FinalMenu.h"

#include "raylib.h"

#include "Game.h"
#include "Gameplay.h"
#include "Palette.h"
#include "Unload.h"

static float resetTimer = 0.0f;

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
			stateMenu = true;
			stateEndMenu = false;
			stateGame = false;
			StopMusicStream(bgMusic);
		}
		DrawText("Play Again: Y/N", 300, 200, 20, RAYWHITE);
		if (IsKeyDown(KEY_Y))
		{
			pointsP1 = startPoints;
			pointsP2 = startPoints;
			games = initialGames;
			InitPlayers();
			timer = resetTimer;
			stateMenu = false;
			stateGame = true;
			stateEndMenu = false;
		}
		if (IsKeyDown(KEY_N))
		{
			stateMenu = false;
			stateGame = false;
			stateEndMenu = false;
			CloseWindow();
		}
		EndDrawing();
	}
}