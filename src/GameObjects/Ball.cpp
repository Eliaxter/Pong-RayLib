#include "Ball.h"

#include <iostream>
#include <time.h>
using namespace std;

#include "raylib.h"

#include "Gameplay.h"
#include "Palette.h"
#include "Collision.h"

namespace Game
{
	const int minSpeedBall = 6;
	const int maxSpeedBall = 7;
	float initialRadius = 20.0f;
	float ballRadius;
	float powerBallRadius = 15.0f;
	float secondPowerBallRadius = 10.0f;
	int randBallPosition;
	Vector2 ballPosition;
	Vector2 ballSpeed;
	Vector2 powerBallPosition;
	Vector2 secondPowerBallPosition;

	static float teleportPowerBall = -500.0f;

	bool isTimeRunning = true;

	static bool canDrawPowerBall = false;

	int sizeColors = 5;
	Color colors[8];
	Color colorBall;

	Rectangle player1;
	Rectangle player2;

	static float resetTimer = 0.0;

	void CollisionPowerBall()
	{
		if (CheckCollisionCircles(ballPosition, ballRadius, powerBallPosition, powerBallRadius))
		{
			ballRadius = 40.0f;
			if (ballPosition.x > halfScreenWidth)
			{
				pointsP1 += 2;
			}
			if (ballPosition.x < halfNegativeScreenWidth)
			{
				pointsP2 += 2;
			}
			powerBallPosition.x = teleportPowerBall;
			powerBallPosition.y = teleportPowerBall;
		}

		if (ballRadius == 40.0f)
		{
			if (timer / (float)GetFPS() > 10.0f)
			{
				if (CheckCollisionCircleRec(ballPosition, ballRadius, player1) || CheckCollisionCircleRec(ballPosition, ballRadius, player2))
				{
					ballRadius = initialRadius;
				}
			}
		}
	}

	void ColorBall()
	{
		colorBall = WHITE;
		colors[0] = BLACK;
		colors[1] = RED;
		colors[2] = GREEN;
		colors[3] = YELLOW;
		colors[4] = PURPLE;
		colors[5] = GOLD;
		colors[6] = VIOLET;
		colors[7] = DARKBROWN;
	}

	void InitBall()
	{
		randBallPosition = rand() % 2;

		ballPosition.x = static_cast<float>(screenWidth) / 2;
		ballPosition.y = static_cast<float>(screenHeight) / 2;
		ballSpeed.x = 0;
		ballSpeed.y = 0;

		ballRadius = initialRadius;
	}

	void InitPowerUp()
	{
		int random1 = 0;
		random1 = GetRandomValue(randomPowerUPW1, randomPowerUPW2);
		powerBallPosition.x = random1;
		int random2 = 0;
		random2 = GetRandomValue(randomPowerUPH1, randomPowerUPH2);
		powerBallPosition.y = random2;
	}

	void InitSecondPowerUP()
	{
		float random3 = 0.0f;
		random3 = GetRandomValue(randomPowerUPW1, randomPowerUPW2);
		secondPowerBallPosition.x = random3;
		float random4 = 0.0f;
		random4 = GetRandomValue(randomPowerUPH1, randomPowerUPH2);
		secondPowerBallPosition.y = random4;
	}

	void DrawSecondPowerUP()
	{
		if (timer / static_cast<float>(GetFPS()) > 10.0f && !canDrawPowerBall)
		{
			canDrawPowerBall = true;
		}

		if (canDrawPowerBall)
		{
			DrawCircleV(secondPowerBallPosition, secondPowerBallRadius, BLACK);
		}

		if (CheckCollisionCircles(secondPowerBallPosition, secondPowerBallRadius, ballPosition, ballRadius))
		{
			timer = resetTimer;
			canDrawPowerBall = false;
		}
	}

	void RandomBallSpeed()
	{
		ballSpeed.x = maxSpeedBall;
		ballSpeed.y = maxSpeedBall;
	}

	void MoveBall()
	{
		ballPosition.x += ballPosition.x * GetFrameTime();
		ballPosition.y += ballPosition.y * GetFrameTime();
	}
}