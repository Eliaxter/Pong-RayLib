#include "../headers/Game.h"

void FinalMenu()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Final del Juego!", 300, 160, 20, RAYWHITE);
	CheckPlayerWins();
	DrawText("Volver al Menu principal: M", 300, 220, 20, RAYWHITE);
	if (IsKeyDown(KEY_M))
	{
		pointsP1 = startPoints;
		pointsP2 = startPoints;
		stateMenu = true;
		stateEndMenu = false;
		stateGame = false;
		StopMusicStream(bgMusic);

	}
	DrawText("Volver a jugar: Y/N", 300, 200, 20, RAYWHITE);
	if (IsKeyDown(KEY_Y))
	{
		stateGame = true;
		stateEndMenu = false;
		pointsP1 = startPoints;
		pointsP2 = startPoints;
		games = initialGames;
	}
	if (IsKeyDown(KEY_N))
	{
		pointsP1 = startPoints;
		pointsP2 = startPoints;
		stateMenu = false;
		stateGame = false;
		stateEndMenu = false;
		CloseWindow();
	}
	EndDrawing();
}