#pragma once
#include "Figura.h"

class GanarSprite:public Figura
{
public:
	GanarSprite(int _x, int _y);
	~GanarSprite();
	void generarSpriteGanar(char* _path_imagen);
	void desplazar(BufferedGraphics^ buffer);
	void dibujar(BufferedGraphics^ buffer);
	void mover(BufferedGraphics^ buffer);
private:
	int indiceX, indiceY;
	char* path_imagen;
};

GanarSprite::GanarSprite(int _x, int _y):Figura(_x,_y)
{
	indiceX = 0;
	indiceY = 0;
	path_imagen = new char[70];
}
GanarSprite::~GanarSprite()
{
}

void GanarSprite::generarSpriteGanar(char* _path_imagen) {
	strcpy(path_imagen, _path_imagen);
	Bitmap^ imgSprite= gcnew Bitmap(gcnew System::String(path_imagen));
	ancho = imgSprite->Width / 10;
	alto = imgSprite->Height / 3;
	delete imgSprite;
}

void GanarSprite::dibujar(BufferedGraphics^ buffer) {

	Bitmap^ imgSprite= gcnew Bitmap(gcnew System::String(path_imagen));
    Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(buffer->Graphics->VisibleClipBounds.Left, buffer->Graphics->VisibleClipBounds.Top, ancho+100 , alto ); 
	buffer->Graphics->DrawImage(imgSprite, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
	delete imgSprite;
}
void GanarSprite::desplazar(BufferedGraphics^ buffer) {
	if (indiceX >= 0 && indiceX < 9)indiceX++;
	else {
		indiceX = 0;
		indiceY++;
		if (indiceY == 2 ) {
			indiceY = 0;
		}
	}
}

void GanarSprite::mover(BufferedGraphics^ buffer) {
	desplazar(buffer);
	dibujar(buffer);
}