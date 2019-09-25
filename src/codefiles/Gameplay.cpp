#include "../headers/Gameplay.h"

#include "raylib.h"

#include "../headers/Palette.h"
#include "../headers/Ball.h"
#include "../headers/Texture.h"

const int screenWidth = 800; //gameplay
const int screenHeight = 450; //gameplay
const int minScreenW = 0; //gameplay
const int minScreenH = 0; //gameplay
const int screenBorderX = -2; //gameplay
const int halfScreenWidth = 402; //gameplay
const int halfScreenHeight = 227; //gameplay
const int halfNegativeScreenWidth = 398; //gameplay
const int halfNegativeScreenHeight = 223; //gameplay
const int randomPowerUPW1 = 30; //gameplay
const int randomPowerUPW2 = 770; //gameplay
const int randomPowerUPH1 = 30; //gameplay
const int randomPowerUPH2 = 420; //gameplay

const int startPoints = 0; //gameplay
const int winPoints = 4; //gameplay
int pointsP1; //gameplay
int pointsP2; //gameplay
int player1Wins; //gameplay
int player2Wins; //gameplay
int games; //gameplay
int gamesToWin = 3; //gameplay
int incrementGames = 1; //gameplay
int initialGames = 0; //gameplay

//Music bgMusic; //music
//Sound collisionWave; //sound


void Game() 
{
	// Update
	//----------------------------------------------------------------------------------
	UpdateMusicStream(bgMusic);
	if (IsKeyDown(KEY_W)) player1.y -= 5.0f;
	if (IsKeyDown(KEY_S)) player1.y += 5.0f;
	player2.y = ballPosition.y - 50;
	//if (IsKeyDown(KEY_UP)) player2.y -= 5.0f;
	//if (IsKeyDown(KEY_DOWN)) player2.y += 5.0f;
	//----------------------------------------------------------------------------------
	// Draw
	//----------------------------------------------------------------------------------
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
	PlayMusicStream(bgMusic);
	//Conditions
	//-----------------------Resto de Funciones------------------------------------------
	CollisionPlayerWithBall();
	PlayerGetPoints();
	PlayerPointsConditions();
	EndDrawing();
}