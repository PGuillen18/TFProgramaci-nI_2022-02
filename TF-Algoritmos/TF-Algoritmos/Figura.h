#pragma once

#include<vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Media;

enum acciones { izquierda, derecha, arriba, abajo, derrotado, ninguna };
class Figura
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;

public:
	Figura(int _x, int _y);
	~Figura();


	Rectangle getArea();
	Rectangle getSigArea();
	Rectangle getAreaZoomeadaPersonaje();
	Rectangle getAreaMosquitosPersonaje();
	Rectangle getAreaEnfermoPersonaje();
	Rectangle getAreaDificil();
	void setX(int _x);
	void setY(int _y);
	void setDX(int _dx);
	void setDY(int _dy);
	int getDX();
	int getDY();
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
};


Figura::Figura(int _x, int _y)
{
	x = _x;
	y = _y;
	dx = 5;
	dy = 5;
	ancho = alto = 0;
}
Figura::~Figura() {}

Rectangle Figura::getArea()
{
	return Rectangle(x, y, ancho, alto);
}

Rectangle Figura::getAreaZoomeadaPersonaje()
{
	return Rectangle(x, y, ancho * 0.5, alto * 0.5);
}
Rectangle Figura::getSigArea()
{
	return Rectangle(x + dx, y + dy, ancho*0.5, alto*0.5);
}
Rectangle Figura::getAreaMosquitosPersonaje()
{
	return Rectangle(x, y, ancho * 0.4, alto * 0.4);
}
Rectangle Figura::getAreaEnfermoPersonaje() {
	return Rectangle(x, y, ancho * 1, alto * 1);
}
Rectangle Figura::getAreaDificil() {
	return Rectangle(x, y, ancho * 0.2, alto * 0.2);
}

void Figura::setX(int _x) { x = _x; }
void Figura::setY(int _y) { y = _y; }
void Figura::setDX(int _dx) { dx = _dx; }
void Figura::setDY(int _dy) { dy = _dy; }
int Figura::getDX() { return dx; }
int Figura::getDY() { return dy; }