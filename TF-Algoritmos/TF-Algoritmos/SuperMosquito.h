#pragma once
#include "Personaje.h"
#include "Figura.h"

class SuperMosquito:public Figura
{
public:
	SuperMosquito(int _x, int _y);
	~SuperMosquito();
	void dibujar(BufferedGraphics^ buffer);
	void mover(BufferedGraphics^ buffer, Personaje* oPersonaje);
	void desplazar(BufferedGraphics^ buffer,Personaje* oPersonaje);
private:
	int indiceX;
	int indiceY;
};

SuperMosquito::SuperMosquito(int _x, int _y):Figura(_x,_y)
{
	dx = dy = 1;
	indiceX = indiceY = 0;
}

SuperMosquito::~SuperMosquito()
{
}

void SuperMosquito::dibujar(BufferedGraphics^ buffer) {
	Bitmap^ imgSuperMosquito = gcnew Bitmap(gcnew System::String("Imagenes/SuperMosquito.png"));
	ancho = imgSuperMosquito->Width / 3;
	alto = imgSuperMosquito->Height / 4;
	Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 1, alto * 1);
	buffer->Graphics->DrawImage(imgSuperMosquito, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
	delete imgSuperMosquito;
}

void SuperMosquito::desplazar(BufferedGraphics^ buffer, Personaje* oPersonaje) {
	if (x == oPersonaje->getX()) {
		x += 0;
	}
	else if (x > oPersonaje->getX()) {
		x -= dx;	
		indiceY = 2;	
	}
	else if (x < oPersonaje->getX()) {
		x += dx;	
		indiceY = 3;	
	}

	if (y == oPersonaje->getY()) {
		y += 0;
	}
	else if (y > oPersonaje->getY()) {
		y -= dy;	
		indiceY = 0;	
	}
	else if (y < oPersonaje->getY()) {
		y += dy;	
		indiceY = 1;
	}

	indiceX++;
	if (indiceX > 2) indiceX = 0;
}

void SuperMosquito::mover(BufferedGraphics^ buffer, Personaje* oPersonaje)
{
	desplazar(buffer, oPersonaje);
	dibujar(buffer);
}