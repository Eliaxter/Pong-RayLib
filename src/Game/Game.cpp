#include "Game.h"

#include "raylib.h"

#include <iostream>

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

	float timer = 0;

	void GameLoop()
	{
		InitializeGlobal();
		while (true)
		{
			if (stateMenu == true)
			{
				Menu();
			}
			if (stateGame == true)
			{
				Input();
				Update();
				Draw();
				if (IsKeyDown(KEY_ESCAPE))
				{
					stateMenu = false;
					stateGame = false;
					stateEndMenu = false;
					CloseWindow();
				}
				timer++;
			}
			if (stateEndMenu == true)
			{
				FinalMenu();
			}

		}
		Unload();
		EndDrawing();
	}
}
	/*
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
				if (PVE == true)
				{
					AI();
				}
				else
				{
					Input();
				}
				Update();
				Draw();
				if (IsKeyDown(KEY_ESCAPE))
				{
					stateGame = false;
					CloseWindow();
				}
				timer++;
			}
			while (stateEndMenu == true)
			{
				FinalMenu();
			}*/
			/*
			if (IsKeyDown(KEY_ESCAPE))
			{
				break;
			}*/
		/*}
		Unload();
		EndDrawing();
		std::cin.get();
	}
}*/