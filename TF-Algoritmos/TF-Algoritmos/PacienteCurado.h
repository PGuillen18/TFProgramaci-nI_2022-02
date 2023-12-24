#pragma once
#include "Figura.h"

class Curado:Figura
{
public:
	Curado(int _x, int _y);
	~Curado();
	void dibujar(BufferedGraphics^ buffer);	

private:

	int indiceX, indiceY;
};

Curado::Curado(int _x, int _y) :Figura(_x, _y)
{
	indiceX = 0;
	indiceY = 0;
	dx = 0;
	dy = 0;
}

Curado::~Curado()
{
}

void Curado::dibujar(BufferedGraphics^ buffer) {
	Bitmap^ imgCurado= gcnew Bitmap(gcnew System::String("Imagenes/CheckBueno.png"));
	ancho = imgCurado->Width;
	alto = imgCurado->Height;
	Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje= Rectangle(x, y, ancho * 0.15, alto * 0.15);
	buffer->Graphics->DrawImage(imgCurado, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
	delete imgCurado;
}