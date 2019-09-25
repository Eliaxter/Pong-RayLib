#include "Image.h"

Image bgImage;
Image imgBall;
Image imgPlayer1;
Image imgPlayer2;

void LoadImageBG()
{
	bgImage = LoadImage("img/bg.png");
}

void UnloadImage()
{
	UnloadImage(bgImage);
}