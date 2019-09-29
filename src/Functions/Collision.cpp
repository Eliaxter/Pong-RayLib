#include "Collision.h"

#include "raylib.h"

#include "Gameplay.h"
#include "Ball.h"
#include "Palette.h"

namespace Game
{
	const int dontCheckCollisionFrames = 10;
	bool previusFrameCollisionP1 = false;
	int lastCollisionFramesP1 = 0;
	bool previusFrameCollisionP2 = false;
	int lastCollisionFramesP2 = 0;

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
}