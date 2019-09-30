#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

namespace Game
{
	extern int screenWidth;
	extern int screenHeight;
	extern const int minScreenW;
	extern const int minScreenH;
	extern const int screenBorderX;
	extern const int halfScreenWidth;
	extern const int halfScreenHeight;
	extern const int halfNegativeScreenWidth;
	extern const int halfNegativeScreenHeight;
	extern const int randomPowerUPW1;
	extern const int randomPowerUPW2;
	extern const int randomPowerUPH1;
	extern const int randomPowerUPH2;

	extern const int startPoints;
	extern const int winPoints;
	extern int pointsP1;
	extern int pointsP2;
	extern int player1Wins;
	extern int player2Wins;
	extern int games;
	extern int gamesToWin;
	extern int incrementGames;
	extern int initialGames;

	extern Music bgMusic;
	extern Sound collisionWave;

	extern float timer;

	void Update();
	void Draw();
	void Input();
}

#endif