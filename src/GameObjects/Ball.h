#ifndef BALL_H
#define BALL_H
#include "raylib.h"

#include <iostream>
#include <time.h>

namespace Game
{
	extern const int minSpeedBall;
	extern const int maxSpeedBall;
	extern float initialRadius;
	extern float ballRadius;
	extern float powerBallRadius;
	extern float secondPowerBallRadius;
	extern int randBallPosition;
	extern Vector2 ballPosition;
	extern Vector2 ballSpeed;
	extern Vector2 powerBallPosition;
	extern Vector2 secondPowerBallPosition;

	extern int sizeColors;
	extern Color colors[8];
	extern Color colorBall;

	void CollisionPowerBall();
	void ColorBall();
	void InitBall();
	void InitPowerUp();
	void InitSecondPowerUP();
	void DrawSecondPowerUP();
	void RandomBallSpeed();
	void MoveBall();
}

#endif