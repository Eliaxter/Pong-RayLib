#include "Palette.h"

#include <iostream>
#include <time.h>

#include "raylib.h"

#include "Ball.h"
#include "Collision.h"
#include "Gameplay.h"
#include "Initialize.h"
#include "Texture.h"
#include "Game.h"

namespace Game 
{
	const int player1X = 2;
	const int player1Y = 200;

	const int player2X = 747;
	const int player2Y = 200;

	const float speedPlayer1 = 5.0f;
	const float speedPlayer2 = 5.0f;

	void InitPlayers()
	{
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
	}

	void InitPlayerPointsMenu()
	{
		pointsP1 = startPoints;
		pointsP2 = startPoints;
		games = initialGames;
		stateGame = true;
		stateMenu = false;
		stateEndMenu = false;
	}

	void PlayerGetPoints()
	{
		if (ballPosition.x > screenWidth)
		{
			InitBall();
			ballPosition.x = (float)screenWidth / 2;
			ballPosition.y = (float)screenHeight / 2;
			pointsP1++;
			colorBall = WHITE;
		}
		if (ballPosition.x < screenBorderX)
		{
			InitBall();
			ballPosition.x = (float)screenWidth / 2;
			ballPosition.y = (float)screenHeight / 2;
			pointsP2++;
			colorBall = WHITE;
		}
	}

	void PlayerPointsConditions()
	{
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
	}

	void CheckPlayerWins()
	{
		if (player1Wins > player2Wins)
		{
			DrawText("Player 1 Win", 300, 180, 20, RAYWHITE);
		}
		if (player2Wins > player1Wins)
		{
			DrawText("Player 2 Win", 300, 180, 20, RAYWHITE);
		}
	}
}