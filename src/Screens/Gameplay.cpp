#include "Gameplay.h"

#include "raylib.h"

#include "Palette.h"
#include "Ball.h"
#include "Texture.h"
#include "Collision.h"

namespace Game
{
	int screenWidth = 800;
	int screenHeight = 450;
	const int minScreenW = 0;
	const int minScreenH = 0;
	const int screenBorderX = -2;
	const int halfScreenWidth = screenWidth / 2;
	const int halfScreenHeight = screenHeight / 2;
	const int halfNegativeScreenWidth = screenWidth / 2 - 2;
	const int halfNegativeScreenHeight = screenHeight / 2 - 2;
	const int randomPowerUPW1 = 30;
	const int randomPowerUPW2 = 770;
	const int randomPowerUPH1 = 30;
	const int randomPowerUPH2 = 420;

	const int startPoints = 0;
	const int winPoints = 4;
	int pointsP1;
	int pointsP2;
	int player1Wins;
	int player2Wins;
	int games;
	int gamesToWin = 3;
	int incrementGames = 1;
	int initialGames = 0;


	void Update()
	{
		MoveBall();
		UpdateMusicStream(bgMusic);
		WindowCollision();
		WindowLimits();
		CollisionPowerBall();
		PlayMusicStream(bgMusic);
		CollisionPlayerWithBall();
		PlayerGetPoints();
		PlayerPointsConditions();
		EndDrawing();
	}

	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(bgTexture, 0, 0, WHITE);
		DrawText(TextFormat("Player 1: %i", pointsP1), 10, 10, 20, WHITE);
		DrawText(TextFormat("Games: %i", games), 400, 10, 20, WHITE);
		DrawText(TextFormat("Player 2: %i", pointsP2), 650, 10, 20, WHITE);
		DrawCircleV(ballPosition, ballRadius, colorBall);
		DrawCircleV(powerBallPosition, powerBallRadius, WHITE);
		DrawSecondPowerUP();
		DrawTexture(p1, static_cast<int>(player1.x), static_cast<int>(player1.y), WHITE);
		DrawTexture(p2, static_cast<int>(player2.x), static_cast<int>(player2.y), WHITE);
	}

	void Input()
	{
		if (IsKeyDown(KEY_W)) player1.y -= speedPlayer1 * GetFrameTime();
		if (IsKeyDown(KEY_S)) player1.y += speedPlayer1 * GetFrameTime();
		if (IsKeyDown(KEY_UP)) player2.y -= speedPlayer2 * GetFrameTime();
		if (IsKeyDown(KEY_DOWN)) player2.y += speedPlayer2 * GetFrameTime();
	}
}