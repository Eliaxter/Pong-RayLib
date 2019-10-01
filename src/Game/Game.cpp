#include "Game.h"

#include "raylib.h"

#include <iostream>
using namespace std;

#include "Initialize.h"
#include "Menu.h"
#include "Gameplay.h"
#include "FinalMenu.h"
#include "Unload.h"

namespace Game
{
	bool stateGame = false;
	bool stateMenu = true;
	bool stateEndMenu = false;

	static float timer = 0;

	void GameLoop()
	{
		InitializeGlobal();
		while (true)
		{
			while (stateMenu == true)
			{
				Menu();
			}
			while (stateGame == true)
			{
				Input();
				Update();
				Draw();
				if (IsKeyDown(KEY_ESCAPE))
				{
					stateGame = false;
				}
				timer++;
			}
			while (stateEndMenu == true)
			{
				FinalMenu();
			}

			if (IsKeyDown(KEY_ESCAPE))
			{
				break;
			}
		}
		Unload();
		std::cin.get();
	}
}