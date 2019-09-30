#include "Collision.h"

#include "raylib.h"

#include "Gameplay.h"
#include "Ball.h"
#include "Palette.h"

namespace Game
{
	const int dontCheckCollisionFrames = 5;
	bool previusFrameCollisionP1 = false;
	int lastCollisionFramesP1 = 0;
	bool previusFrameCollisionP2 = false;
	int lastCollisionFramesP2 = 0;
	bool previusFrameCollision = false;
	int lastCollisionFrames = 0;
	static float reverseSpeed = -1.0f;

	void WindowCollision()
	{
		if (previusFrameCollision)
		{
			lastCollisionFrames++;
			if (lastCollisionFrames >= dontCheckCollisionFrames)
			{
				lastCollisionFrames = 0;
				previusFrameCollision = false;
			}
		}

		if ((ballPosition.y >= (screenHeight - ballRadius)) || (ballPosition.y <= ballRadius))
		{
			ballSpeed.y *= reverseSpeed;
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

		if (CheckCollisionCircleRec(ballPosition, ballRadius, player1))
		{
			if (!previusFrameCollisionP1)
			{
				ballSpeed.x = ballSpeed.x * -1.0f;
				ballPosition.y += ballSpeed.y * -1.0f;
				colorBall = player1.color;
				PlaySound(collisionWave);
				previusFrameCollisionP1 = true;
			}

		}

		if (CheckCollisionCircleRec(ballPosition, ballRadius, player2))
		{
			
			if (!previusFrameCollisionP2)
			{
				ballSpeed.x = ballSpeed.x * -1.0f;
				ballPosition.y += ballSpeed.y * -1.0f;
				colorBall = player2.color;
				PlaySound(collisionWave);
				previusFrameCollisionP2 = true;
			}
		}
	}
}