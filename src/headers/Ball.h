#pragma once
#include "raylib.h"

extern const int minSpeedBall; //ball
extern const int maxSpeedBall; //ball
extern float initialRadius; //ball
extern float ballRadius; //ball
extern float powerBallRadius; //ball
extern int randBallPosition; //ball
extern Vector2 ballPosition; //ball
extern Vector2 ballSpeed; //ball
extern Vector2 powerBall; //ball

extern int sizeColors; //ball
extern Color colors[8]; //ball
extern Color colorBall; //ball

void RandomBallPos();
void CollisionPowerBall();
void ColorBall();
void InitBall();
void InitPowerUp();
void RandomBallSpeed();