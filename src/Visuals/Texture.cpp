#include "Texture.h"

#include "Image.h"

namespace Game
{
	Texture2D p1;
	Texture2D p2;
	Texture bgTexture;
	Texture textureBall;
	Texture texturePlayer1;
	Texture texturePlayer2;

	void LoadTextureBG()
	{
		bgTexture = LoadTextureFromImage(bgImage);
	}
}