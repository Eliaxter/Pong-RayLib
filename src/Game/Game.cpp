#include "Game.h"

#include "raylib.h"

#include <iostream>

#include "Initialize.h"
#include "Menu.h"
#include "Gameplay.h"
#include "FinalMenu.h"
#include "Unload.h"

bool stateGame = true;
bool stateMenu = true;
bool stateEndMenu = true;
bool AI;

float timer = 0;

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