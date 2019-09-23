#pragma once
#include "raylib.h"

extern const int minSpeedBall; //ball
extern const int maxSpeedBall; //ball
extern const int initialRadius; //ball
extern const int ballRadius; //ball
extern const int powerBallRadius; //ball
extern int randBallPosition; //ball
extern Vector2 ballPosition; //ball
extern Vector2 ballSpeed; //ball
extern Vector2 powerBall; //ball

extern int sizeColors; //ball
extern Color colors[8]; //ball
extern Color colorBall; //ball

void RandomBallPos();
void CollisionPowerBall();
