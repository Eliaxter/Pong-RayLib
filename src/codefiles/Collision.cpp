#include "../headers/Collision.h"

#include "raylib.h"

#include "../headers/Gameplay.h"
#include "../headers/Ball.h"
#include "../headers/Palette.h"

const int dontCheckCollisionFrames = 10;
bool previusFrameCollisionP1 = false; //collision
int lastCollisionFramesP1 = 0; //collision
bool previusFrameCollisionP2 = false; //collision
int lastCollisionFramesP2 = 0; //collision

void WindowCollision() 
{
	if ((ballPosition.y >= (screenHeight - ballRadius)) || (ballPosition.y <= ballRadius)) 
	{
		ballSpeed.y *= -1.0f;
	}
}

void WindowLimits() 
{
	if (player1.y + player1.height > screenHeight)
	{
		player1.y = screenHeight - player1.height;
	}
	if (player1.y < minScreenH)
	{
		player1.y = 0;
	}
	if (player2.y + player2.height > screenHeight)
	{
		player2.y = screenHeight - player2.height;
	}
	if (player2.y < minScreenH)
	{
		player2.y = 0;
	}
}