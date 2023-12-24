#pragma once
#include "Figura.h"

class Enfermos:public Figura
{
public:
	Enfermos(int _x, int _y,int _indiceX);
	~Enfermos();
	void dibujar(BufferedGraphics^ buffer);

private:

	int indiceX, indiceY;
};

Enfermos::Enfermos(int _x, int _y,int _indiceX):Figura (_x,_y)
{
	indiceX = _indiceX;
	indiceY = 0;
	dx = 0;
	dy = 0;
}

Enfermos::~Enfermos()
{
}

void Enfermos::dibujar(BufferedGraphics^ buffer) {
	Bitmap^ imgEnfermo = gcnew Bitmap(gcnew System::String("Imagenes/PacientesEnfermos.png"));
	ancho = imgEnfermo->Width / 12;
	alto = imgEnfermo->Height;
	Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 1, alto * 1);
	buffer->Graphics->DrawImage(imgEnfermo, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
	delete imgEnfermo;
}

