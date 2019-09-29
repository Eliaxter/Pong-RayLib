#ifndef GAME_H
#define GAME_H

namespace Game
{
	extern bool stateGame;
	extern bool stateMenu;
	extern bool stateEndMenu;
	extern bool PVE;

	void GameLoop();
}

#endif