#include "../headers/Texture.h"

#include "../headers/Image.h"

Texture2D p1; //texture
Texture2D p2; //texture
Texture bgTexture; //texture
Texture textureBall; //texture
Texture texturePlayer1; //texture
Texture texturePlayer2; //texture

void LoadTextureBG()
{
	bgTexture = LoadTextureFromImage(bgImage); //Texture
}