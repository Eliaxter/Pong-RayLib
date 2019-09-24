#include "../headers/Game.h"

Image bgImage; //image
Image imgBall; //image
Image imgPlayer1; //image
Image imgPlayer2; //image

void LoadImageBG()
{
	bgImage = LoadImage("img/bg.png"); //Image
}

void UnloadImage()
{
	UnloadImage(bgImage); //UnloadImage
}