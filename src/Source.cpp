#include "raylib.h"
#include <time.h>
//Screen
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
//Players
Rectangle player1;
Rectangle player2;
//Player1
const int player1X = 2;
const int player1Y = 200;
//Player2
const int player2X = 747;
const int player2Y = 200;

const int minSpeedBall = 6;
const int maxSpeedBall = 7;
int initialRadius = 20;
int ballRadius = 20;
int powerBallRadius = 15;
int randBallPosition; 
Vector2 ballPosition;
Vector2 ballSpeed;
Vector2 powerBall;

Texture2D p1;
Texture2D p2;

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

int sizeColors = 5;
Color colors[8];
Color colorBall;

bool stateGame = true;
bool stateMenu = true;
bool stateEndMenu = true;
bool AI = true;

Image bgImage;
Texture bgTexture;
Image imgBall;
Texture textureBall;
Image imgPlayer1;
Texture texturePlayer1;
Image imgPlayer2;
Texture texturePlayer2;

Music bgMusic;
Sound collisionWave;


const int dontCheckCollisionFrames = 10;


bool previusFrameCollisionP1 = false;
int lastCollisionFramesP1 = 0;
bool previusFrameCollisionP2 = false;
int lastCollisionFramesP2 = 0;



void InitializeGame();
void Menu();
void FinalMenu();
void Game();
int main(void)
{
	InitWindow(screenWidth, screenHeight, "Pong Elias");
	InitAudioDevice();
	bgMusic = LoadMusicStream("sounds/background-music.ogg");
	collisionWave = LoadSound("sounds/dung.wav");


	while (true)
	{
		while (stateMenu == true)
		{
			Menu();
		}
		// Main game loop
		while (stateGame == true)    // Detect window close button or ESC key
		{
			Game();
			if (IsKeyDown(KEY_ESCAPE))
				stateGame = false;
			//----------------------------------------------------------------------------------
		}
		while (stateEndMenu == true)
		{
			FinalMenu();
		}


		if (IsKeyDown(KEY_ESCAPE))
			break;
	}




	UnloadSound(collisionWave);
	UnloadMusicStream(bgMusic);

	// De-Initialization
	//--------------------------------------------------------------------------------------
	        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	return 0;
}

void Menu()
{
	if (!IsMusicPlaying(bgMusic))
	{
		PlayMusicStream(bgMusic);
	}


	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Pong Elias", 300, 160, 20, RAYWHITE);
	DrawText("Press Enter to Play Pong Elias", 300, 180, 20, RAYWHITE);
	UpdateMusicStream(bgMusic);
	if (IsKeyDown(KEY_ENTER))
	{
		pointsP1 = startPoints;
		pointsP2 = startPoints;
		games = 0;
		stateGame = true;
		stateMenu = false;
		stateEndMenu = false;
		InitializeGame();
	}
	EndDrawing();
}
void InitializeGame()
{
	colorBall = WHITE;
	colors[0] = BLUE;
	colors[1] = RED;
	colors[2] = GREEN;
	colors[3] = YELLOW;
	colors[4] = PURPLE;
	colors[5] = GOLD;
	colors[6] = VIOLET;
	colors[7] = DARKBROWN;

	randBallPosition = rand() % 2;
	
	ballPosition.x = (float)screenWidth / 2;
	ballPosition.y = (float)screenHeight / 2;
	ballSpeed.x = 0;
	ballSpeed.y = 0;

	int random1 = 0;
	random1 = GetRandomValue(randomPowerUPW1, randomPowerUPW2);
	powerBall.x = random1;
	int random2 = 0;
	random2 = GetRandomValue(randomPowerUPH1, randomPowerUPH2);
	powerBall.y = random2;

	// Set our game to run at 60 frames-per-second
	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	player1.x = player1X;
	player1.y = player1Y;
	player1.width = 25;
	player1.height = 100;
	player1.color = colors[rand() % 7];
	p1 = LoadTexture("img/player1.png");

	player2.x = player2X;
	player2.y = player2Y;
	player2.width = 25;
	player2.height = 100;
	player2.color = colors[rand() % 7];
	p2 = LoadTexture("img/player2.png");
	 
	ballSpeed.x = minSpeedBall + rand() % (maxSpeedBall - minSpeedBall);
	ballSpeed.y = minSpeedBall + rand() % (maxSpeedBall - minSpeedBall);
	bgImage = LoadImage("img/bg.png");
	bgTexture = LoadTextureFromImage(bgImage);
	UnloadImage(bgImage);
}
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
	switch (randBallPosition)
	{
	case 0:
		ballPosition.x += ballSpeed.x;
		ballPosition.y -= ballSpeed.y;
		break;
	case 1:
		ballPosition.x -= ballSpeed.x;
		ballPosition.y += ballSpeed.y;
		break;
	}
	//Player 1

	if (previusFrameCollisionP1)
	{
		lastCollisionFramesP1++;
		if (lastCollisionFramesP1 >= dontCheckCollisionFrames)
		{
			lastCollisionFramesP1 = 0;
			previusFrameCollisionP1 = false;
		}
	}


	if (previusFrameCollisionP2)
	{
		lastCollisionFramesP2++;
		if (lastCollisionFramesP2 >= dontCheckCollisionFrames)
		{
			lastCollisionFramesP2 = 0;
			previusFrameCollisionP2 = false;
		}
	}

	if (CheckCollisionCircleRec(ballPosition, ballRadius, player1))
	{
		if (!previusFrameCollisionP1)
		{
			ballSpeed.x = ballSpeed.x * -1;
			ballPosition.y += ballSpeed.y * -1;
			colorBall = player1.color;
			PlaySound(collisionWave);
			previusFrameCollisionP1 = true;
		}
		
	}
	//Player 2
	if (CheckCollisionCircleRec(ballPosition, ballRadius, player2))
	{

		if (!previusFrameCollisionP2)
		{
			ballSpeed.x = ballSpeed.x * -1;
			ballPosition.y += ballSpeed.y * -1;
			colorBall = player2.color;
			PlaySound(collisionWave);
			previusFrameCollisionP2 = true;

		}
	}
	if (CheckCollisionCircles(ballPosition, ballRadius, powerBall, powerBallRadius))
	{
		ballRadius = 40;
		if (ballPosition.x > halfScreenWidth)
		{
			pointsP1 += 2;
		}
		if (ballPosition.x < halfNegativeScreenWidth)
		{
			pointsP2 += 2;
		}
		powerBall.x = -500;
		powerBall.y = -500;
	}
	if (CheckCollisionCircleRec(ballPosition, ballRadius, player1) == 3 || CheckCollisionCircleRec(ballPosition, ballRadius, player2) == 3)
		ballRadius = initialRadius;
	//Walls
	if ((ballPosition.y >= (screenHeight - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;

	if (ballPosition.x > screenWidth)
	{
		ballPosition.x = (float)screenWidth / 2;
		ballPosition.y = (float)screenHeight / 2;
		pointsP1++;
		colorBall = WHITE;
	}
	if (ballPosition.x < screenBorderX)
	{
		ballPosition.x = (float)screenWidth / 2;
		ballPosition.y = (float)screenHeight / 2;
		pointsP2++;
		colorBall = WHITE;
	}

	if (player1.y + player1.height > screenHeight)
		player1.y = screenHeight - player1.height;
	if (player1.y < minScreenH)
		player1.y = 0;
	if (player2.y + player2.height > screenHeight)
		player2.y = screenHeight - player2.height;	
	if (player2.y < minScreenH)
		player2.y = 0;
	if (pointsP1 >= winPoints)
	{
		games += incrementGames;
		pointsP2 = startPoints;
		pointsP1 = startPoints;
		player1Wins++;
	}
	if (pointsP2 >= winPoints)
	{
		games += incrementGames;
		pointsP1 = startPoints;
		pointsP2 = startPoints;
		player2Wins++;
	}
	if (games == gamesToWin)
	{
		stateGame = false;
		stateEndMenu = true;
	}
	EndDrawing();
}
void FinalMenu()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Final del Juego!", 300, 160, 20, RAYWHITE);
	if (player1Wins > player2Wins)
		DrawText("Player 1 Win", 300, 180, 20, RAYWHITE);
	if(player2Wins > player1Wins)
		DrawText("Player 2 Win", 300, 180, 20, RAYWHITE);
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