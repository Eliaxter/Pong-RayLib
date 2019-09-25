#include "../headers/Ball.h"

#include <iostream>
#include <time.h>

#include "raylib.h"

#include "../headers/Gameplay.h"
#include "../headers/Palette.h"


const int minSpeedBall = 6; //ball
const int maxSpeedBall = 7; //ball
float initialRadius = 20; //ball
float ballRadius = 20; //ball
float powerBallRadius = 15; //ball
int randBallPosition; //ball
Vector2 ballPosition; //ball
Vector2 ballSpeed; //ball
Vector2 powerBall; //ball

int sizeColors = 5; //ball
Color colors[8]; //ball
Color colorBall; //ball

Rectangle player1;
Rectangle player2;

void RandomBallPos()
{
	switch (randBallPosition) //ball
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
}

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
}

void InitBall() 
{
	//-------initBall---------
	randBallPosition = rand() % 2;

	ballPosition.x = (float)screenWidth / 2;
	ballPosition.y = (float)screenHeight / 2;
	ballSpeed.x = 0;
	ballSpeed.y = 0;
	//--------initBall-----------
}

void InitPowerUp()
{
	//--------initPowerUp---------
	int random1 = 0;
	random1 = GetRandomValue(randomPowerUPW1, randomPowerUPW2);
	powerBall.x = random1;
	int random2 = 0;
	random2 = GetRandomValue(randomPowerUPH1, randomPowerUPH2);
	powerBall.y = random2;
	//--------initPowerUp---------
}

void RandomBallSpeed() 
{
	ballSpeed.x = minSpeedBall + rand() % (maxSpeedBall - minSpeedBall); //ball
	ballSpeed.y = minSpeedBall + rand() % (maxSpeedBall - minSpeedBall); //ball
}