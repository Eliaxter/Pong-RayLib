#pragma once
#include "raylib.h"

extern const int minSpeedBall;
extern const int maxSpeedBall;
extern float initialRadius;
extern float ballRadius;
extern float powerBallRadius;
extern int randBallPosition;
extern Vector2 ballPosition;
extern Vector2 ballSpeed;
extern Vector2 powerBall;

extern int sizeColors;
extern Color colors[8];
extern Color colorBall;

void CollisionPowerBall();
void ColorBall();
void InitBall();
void InitPowerUp();
void RandomBallSpeed();
void MoveBall();