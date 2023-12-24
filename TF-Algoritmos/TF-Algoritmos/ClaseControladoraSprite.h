#pragma once
#include "GanarSprite.h"

class SpriteControlador
{
public:
	SpriteControlador();
	~SpriteControlador();
	void generarSprite(char* _path_imagen);
	void moverSprite(BufferedGraphics^ buffer);
private:
	GanarSprite* oSprite;
};

SpriteControlador::SpriteControlador()
{
	oSprite = new GanarSprite(50, 50);
}

SpriteControlador::~SpriteControlador()
{
}

void SpriteControlador::generarSprite(char* _path_imagen) {
	oSprite->generarSpriteGanar(_path_imagen);
}

void SpriteControlador::moverSprite(BufferedGraphics^ buffer) {
	oSprite->mover(buffer);
}