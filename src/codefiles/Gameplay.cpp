#include "../headers/Gameplay.h"

#include "raylib.h"

#include "../headers/Palette.h"
#include "../headers/Ball.h"
#include "../headers/Texture.h"
#include "../headers/Collision.h"

const int screenWidth = 800;
const int screenHeight = 450;
const int minScreenW = 0;
const int minScreenH = 0;
const int screenBorderX = -2;
const int halfScreenWidth = 402;
const int halfScreenHeight = 227;
const int halfNegativeScreenWidth = 398;
const int halfNegativeScreenHeight = 223;
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
	DrawText(TextFormat("Player 1: %i", pointsP1), 10, 10, 20, BLACK);
	DrawText(TextFormat("Games: %i", games), 400, 10, 20, BLACK);
	DrawText(TextFormat("Player 2: %i", pointsP2), 650, 10, 20, BLACK);
	DrawCircleV(ballPosition, ballRadius, colorBall);
	DrawCircleV(powerBall, powerBallRadius, WHITE);
	DrawTexture(p1, player1.x, player1.y, WHITE);
	DrawTexture(p2, player2.x, player2.y, WHITE);
}

void Input() 
{
	if (IsKeyDown(KEY_W)) player1.y -= 5.0f; //input
	if (IsKeyDown(KEY_S)) player1.y += 5.0f; //input
	//player2.y = ballPosition.y - 50;
	if (IsKeyDown(KEY_UP)) player2.y -= 5.0f;
	if (IsKeyDown(KEY_DOWN)) player2.y += 5.0f;
}