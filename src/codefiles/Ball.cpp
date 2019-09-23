#include "../headers/Game.h"

const int minSpeedBall = 6; //ball
const int maxSpeedBall = 7; //ball
const int initialRadius = 20; //ball
const int ballRadius = 20; //ball
const int powerBallRadius = 15; //ball
int randBallPosition; //ball
Vector2 ballPosition; //ball
Vector2 ballSpeed; //ball
Vector2 powerBall; //ball

int sizeColors = 5; //ball
Color colors[8]; //ball
Color colorBall; //ball

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
	if (CheckCollisionCircles(ballPosition, ballRadius, powerBall, powerBallRadius)) //collisions Powe ball
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
}

