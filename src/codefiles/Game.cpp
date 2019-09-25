#include "../headers/Game.h"

#include "raylib.h"

#include "../headers/Initialize.h"
#include "../headers/Menu.h"
#include "../headers/Gameplay.h"
#include "../headers/FinalMenu.h"
#include "../headers/Unload.h"

bool stateGame = true;
bool stateMenu = true;
bool stateEndMenu = true;
bool AI;

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
				stateGame = false;
		}
		while (stateEndMenu == true)
		{
			FinalMenu();
		}

		if (IsKeyDown(KEY_ESCAPE))
			break;
	}
	Unload();
}