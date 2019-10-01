#include "Image.h"

namespace Game 
{
	Image bgImage;
	Image imgBall;
	Image imgPlayer1;
	Image imgPlayer2;

	void LoadImageBG()
	{
		bgImage = LoadImage("assets/img/bg.png");
	}

	void UnloadImage()
	{
		UnloadImage(bgImage);
	}
}