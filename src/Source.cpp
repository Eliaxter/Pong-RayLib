#include "headers/Game.h"
//Screen

//Players
Rectangle player1; //palette
Rectangle player2; //palette
//Player1
const int player1X = 2; //palette
const int player1Y = 200; //palette
//Player2
const int player2X = 747; //palette
const int player2Y = 200; //pàlette

Texture2D p1; //texture
Texture2D p2; //texture



int sizeColors = 5; //ball
Color colors[8]; //ball
Color colorBall; //ball

bool stateGame = true; //Game
bool stateMenu = true; //Game
bool stateEndMenu = true; //Game
bool AI = true; //Game

Image bgImage; //image
Texture bgTexture; //texture
Image imgBall; //image
Texture textureBall; //texture
Image imgPlayer1; //image
Texture texturePlayer1; //texture
Image imgPlayer2; //image
Texture texturePlayer2; //texture

Music bgMusic; //music
Sound collisionWave; //sound




void InitializeGame(); //initialize
void Menu(); //menu
void FinalMenu(); //FinalMenu
void Game(); //Game

int main(void)
{
	//-----------Initialize--------------
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, "Pong Elias");
	InitAudioDevice();
	bgMusic = LoadMusicStream("sounds/background-music.ogg");
	collisionWave = LoadSound("sounds/dung.wav");
	//-----------Initialize--------------

	while (true) //Game Loop
	{
		while (stateMenu == true)
		{
			Menu();
		}
		while (stateGame == true)
		{
			Game();
			if (IsKeyDown(KEY_ESCAPE))
				stateGame = false;
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

void Menu() //Menu
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
void InitializeGame() //initialize
{
	//------color-------
	colorBall = WHITE;
	colors[0] = BLUE;
	colors[1] = RED;
	colors[2] = GREEN;
	colors[3] = YELLOW;
	colors[4] = PURPLE;
	colors[5] = GOLD;
	colors[6] = VIOLET;
	colors[7] = DARKBROWN;
	//-------color-------

	//-------initBall---------
	randBallPosition = rand() % 2;

	ballPosition.x = (float)screenWidth / 2;
	ballPosition.y = (float)screenHeight / 2;
	ballSpeed.x = 0;
	ballSpeed.y = 0;
	//--------initBall-----------

	//--------initPowerUp---------
	int random1 = 0;
	random1 = GetRandomValue(randomPowerUPW1, randomPowerUPW2);
	powerBall.x = random1;
	int random2 = 0;
	random2 = GetRandomValue(randomPowerUPH1, randomPowerUPH2);
	powerBall.y = random2;
	//--------initPowerUp---------

	// Set our game to run at 60 frames-per-second
	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	//---------initPlayers-----------
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
	//---------initPlayers-----------

	ballSpeed.x = minSpeedBall + rand() % (maxSpeedBall - minSpeedBall); //ball
	ballSpeed.y = minSpeedBall + rand() % (maxSpeedBall - minSpeedBall); //ball
	bgImage = LoadImage("img/bg.png");
	bgTexture = LoadTextureFromImage(bgImage);
	UnloadImage(bgImage);
}
void Game() //Gameplay
{
	
	//Actualizar la funcion gameplay a medida que agregamos funciones

	

	if (previusFrameCollisionP1) //collisions Player 1
	{
		lastCollisionFramesP1++;
		if (lastCollisionFramesP1 >= dontCheckCollisionFrames)
		{
			lastCollisionFramesP1 = 0;
			previusFrameCollisionP1 = false;
		}
	}


	if (previusFrameCollisionP2) //collisions Player 2
	{
		lastCollisionFramesP2++;
		if (lastCollisionFramesP2 >= dontCheckCollisionFrames)
		{
			lastCollisionFramesP2 = 0;
			previusFrameCollisionP2 = false;
		}
	}

	if (CheckCollisionCircleRec(ballPosition, ballRadius, player1)) //collisions Player 1
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
	if (CheckCollisionCircleRec(ballPosition, ballRadius, player2)) //collisions Player 2
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
	//----------Player Points------------
	//----points----
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
	//----------Player Points------------
	//----points----
	EndDrawing();
}
void FinalMenu() //Final Menu
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