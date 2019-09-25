#include "../headers/Game.h"

#include "raylib.h"

#include "../headers/Initialize.h"
#include "../headers/Menu.h"
#include "../headers/Gameplay.h"
#include "../headers/FinalMenu.h"
#include "../headers/DeInit.h"


void GameLoop() 
{
	InitializeGlobal();
	while (true) //Game Loop
	{
		while (stateMenu == true)
		{
			Menu();
		}
		while (stateGame == true)
		{
			Game();
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
	DeInit();
}