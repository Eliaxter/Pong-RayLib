#ifndef PALETTE_H
#define PALETTE_H
#include "raylib.h"

namespace Game
{
	extern Rectangle player1;
	extern Rectangle player2;

	extern const int player1X;
	extern const int player1Y;
	extern const int player2X;
	extern const int player2Y;

	extern const float speedPlayer1;
	extern const float speedPlayer2;

	void InitPlayers();
	void InitPlayerPointsMenu();
	void CollisionPlayerWithBall();
	void PlayerGetPoints();
	void PlayerPointsConditions();
	void CheckPlayerWins();
}

#endif