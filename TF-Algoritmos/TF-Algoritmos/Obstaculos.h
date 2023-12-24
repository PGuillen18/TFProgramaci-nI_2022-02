#pragma once
#include "Figura.h"

class Obstaculo : public Figura
{
public:
	Obstaculo(int _x, int _y, int _ancho, int _alto);
	~Obstaculo();

	void dibujar(BufferedGraphics^ buffer);
};

Obstaculo::Obstaculo(int _x, int _y, int _ancho, int _alto) :Figura(_x, _y)
{
	Random r;
	ancho = _ancho;
	alto = _alto;
	x = _x;
	y = _y;
}
Obstaculo::~Obstaculo() {}

void Obstaculo::dibujar(BufferedGraphics^ buffer)
{
	Pen^ lapiz = gcnew Pen(Color::Red, 1);
	buffer->Graphics->DrawRectangle(lapiz, getArea());

}