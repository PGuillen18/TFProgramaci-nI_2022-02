#pragma once
#include "Figura.h"
class AliadoSecreto:public Figura
{
public:
	AliadoSecreto(int _x, int _y);
	~AliadoSecreto();
	void dibujar(BufferedGraphics^ buffer);
	void desplazar(BufferedGraphics^ buffer);
	void mover(BufferedGraphics^ buffer);
private:
	int indiceX, indiceY;
};

AliadoSecreto::AliadoSecreto(int _x, int _y):Figura(_x,_y)
{
	dx = 0;
	dy = 0;
	indiceX = 0;
	indiceY = 1;
}

AliadoSecreto::~AliadoSecreto()
{
}

void AliadoSecreto::dibujar(BufferedGraphics^ buffer) {
	Bitmap^ imgSecreto= gcnew Bitmap(gcnew System::String("Imagenes/AliadoSecreto.png"));
	ancho = imgSecreto->Width / 13;
	alto = imgSecreto->Height/3;
	Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 0.3, alto * 0.3);
	buffer->Graphics->DrawImage(imgSecreto, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
	delete imgSecreto;
}

void AliadoSecreto::desplazar(BufferedGraphics^ buffer) {

	if (indiceX < 12) {
		indiceX++;
		if (indiceX == 12) {
			indiceX = 0;
		}
	}
}

void AliadoSecreto::mover(BufferedGraphics^ buffer) {
	desplazar(buffer);
	dibujar(buffer);
}