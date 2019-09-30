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
	float minSpeedBall = 6;
    float maxSpeedBall = 7.0f;
	float initialRadius = 20.0f;
	float ballRadius;
	static float newRadius = 40.0f;
	float powerBallRadius = 15.0f;
	float secondPowerBallRadius = 10.0f;
	int randBallPosition;
	Vector2 ballPosition;
	Vector2 ballSpeed;
	Vector2 powerBallPosition;
	Vector2 secondPowerBallPosition;
	int sizeColors = 5;
	Color colors[8];
	Color colorBall;

	static float teleportPowerBall = -500.0f;
	static bool canDrawPowerBall = false;

	bool isTimeRunning = true;

	Rectangle player1;
	Rectangle player2;

	static int extraPointsPowerUp = 2;

	float timer = 0.0f;
	static float resetTimer = 0.0f;
	static float tenSeconds = 10.0f;

	void CollisionPowerBall()
	{
		if (CheckCollisionCircles(ballPosition, ballRadius, powerBallPosition, powerBallRadius))
		{
			ballRadius = newRadius;
			if (ballPosition.x > halfScreenWidth)
			{
				pointsP1 += extraPointsPowerUp;
			}
			if (ballPosition.x < halfNegativeScreenWidth)
			{
				pointsP2 += extraPointsPowerUp;
			}
			powerBallPosition.x = teleportPowerBall;
			powerBallPosition.y = teleportPowerBall;
		}

		if (ballRadius == newRadius)
		{
			if (timer / static_cast<float>(GetFPS()) > tenSeconds)
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
		ballPosition.x = (screenWidth) / 2;
		ballPosition.y = (screenHeight) / 2;
		ballSpeed.x = maxSpeedBall;
		ballSpeed.y = maxSpeedBall;

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
	 /*
	void RandomBallSpeed()
	{
		ballSpeed.x = maxSpeedBall;
		ballSpeed.y = maxSpeedBall;
	}*/

	void MoveBall()
	{
		ballPosition.x += ballSpeed.x;
		ballPosition.y -= ballSpeed.y;
	}
}