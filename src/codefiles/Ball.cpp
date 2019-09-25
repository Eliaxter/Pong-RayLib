#include "../headers/Ball.h"

#include <iostream>
#include <time.h>

#include "raylib.h"

#include "../headers/Gameplay.h"
#include "../headers/Palette.h"
#include "../headers/Collision.h"


const int minSpeedBall = 6;
const int maxSpeedBall = 7;
float initialRadius = 20;
float ballRadius = 20;
float powerBallRadius = 15;
int randBallPosition;
Vector2 ballPosition;
Vector2 ballSpeed;
Vector2 powerBall;

int sizeColors = 5;
Color colors[8];
Color colorBall;

Rectangle player1;
Rectangle player2;

void CollisionPowerBall() 
{
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
	if (CheckCollisionCircleRec(ballPosition, ballRadius, player1) == 3.0f || CheckCollisionCircleRec(ballPosition, ballRadius, player2) == 3.0f)
		ballRadius = initialRadius;
}

void ColorBall()
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
}

void InitBall() 
{
	randBallPosition = rand() % 2;

	ballPosition.x = (float)screenWidth / 2;
	ballPosition.y = (float)screenHeight / 2;
	ballSpeed.x = 0;
	ballSpeed.y = 0;
}

void InitPowerUp()
{
	int random1 = 0;
	random1 = GetRandomValue(randomPowerUPW1, randomPowerUPW2);
	powerBall.x = random1;
	int random2 = 0;
	random2 = GetRandomValue(randomPowerUPH1, randomPowerUPH2);
	powerBall.y = random2;
}

void RandomBallSpeed() 
{
	ballSpeed.x = minSpeedBall + rand() % (maxSpeedBall - minSpeedBall);
	ballSpeed.y = minSpeedBall + rand() % (maxSpeedBall - minSpeedBall);
}

void MoveBall()
{
	ballPosition.x += ballSpeed.x;
	ballPosition.y -= ballSpeed.y;

}