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

	void CollisionPlayerWithBall()
	{
		if (previusFrameCollisionP1)
		{
			lastCollisionFramesP1++;
			if (lastCollisionFramesP1 >= dontCheckCollisionFrames)
			{
				lastCollisionFramesP1 = 0;
				previusFrameCollisionP1 = false;
			}
		}


		if (previusFrameCollisionP2)
		{
			lastCollisionFramesP2++;
			if (lastCollisionFramesP2 >= dontCheckCollisionFrames)
			{
				lastCollisionFramesP2 = 0;
				previusFrameCollisionP2 = false;
			}
		}

		if (CheckCollisionCircleRec(ballPosition, (ballRadius), player1))
		{
			if (!previusFrameCollisionP1)
			{
				ballPosition.x *= -1 * GetFrameTime();
				ballPosition.y *= -1;
				colorBall = player1.color;
				PlaySound(collisionWave);
				previusFrameCollisionP1 = true;
			}

		}

		if (CheckCollisionCircleRec(ballPosition, (ballRadius), player2))
		{
			if (!previusFrameCollisionP2)
			{
				ballPosition.x *= -1 * GetFrameTime();
				ballPosition.y *= -1;
				colorBall = player2.color;
				PlaySound(collisionWave);
				previusFrameCollisionP2 = true;

			}
		}
	}
}