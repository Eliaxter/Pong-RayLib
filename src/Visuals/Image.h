#ifndef IMAGE_H
#define IMAGE_H
#include "raylib.h"

namespace Game
{
	extern Image bgImage;
	extern Image imgBall;
	extern Image imgPlayer1;
	extern Image imgPlayer2;

	void LoadImageBG();
	void UnloadImage();
}

#endif