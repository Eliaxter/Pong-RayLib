#pragma once

//Players
extern Rectangle player1;
extern Rectangle player2;
//Player1
extern const int player1X;
extern const int player1Y;
//Player2
extern const int player2X;
extern const int player2Y;

void InitPlayers();
void InitPlayerPointsMenu();
void CollisionPlayerWithBall();
void PlayerGetPoints();
void PlayerPointsConditions();
void CheckPlayerWins();