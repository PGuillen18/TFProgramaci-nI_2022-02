#pragma once
#include "Figura.h"
#include "Personaje.h"

class PacientePersecutor :public Figura
{
public:
	PacientePersecutor(int _x, int _y);
	~PacientePersecutor();
	void dibujar(BufferedGraphics^ buffer);
	void desplazar(BufferedGraphics^ buffer, Personaje* oPersonaje);
	void mover(BufferedGraphics^ buffer, Personaje* oPersonaje);
private:
	int indiceX, indiceY;
	bool activa;
};

PacientePersecutor::PacientePersecutor(int _x, int _y) :Figura(_x, _y)
{
	dx = 2;
	dy = 2;
	indiceX = indiceY = 0;
}

PacientePersecutor::~PacientePersecutor()
{

}
void PacientePersecutor::dibujar(BufferedGraphics^ buffer) {
	Bitmap^ imgPacientePersercutor= gcnew Bitmap(gcnew System::String("Imagenes/PacientePersecutor.png"));
	ancho = imgPacientePersercutor->Width / 3;
	alto = imgPacientePersercutor->Height / 4;
	Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 1, alto * 1);
	buffer->Graphics->DrawImage(imgPacientePersercutor, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
	delete imgPacientePersercutor;
}
void PacientePersecutor::desplazar(BufferedGraphics^ buffer,Personaje* oPersonaje) {

	if (x == oPersonaje->getX()) {
		x += 0;
	}
	else if (x > oPersonaje->getX()) {
		x -= dx;
		indiceY = 1;
	}
	else if (x < oPersonaje->getX()) {
		x += dx;
		indiceY = 2;
	}

	if (y == oPersonaje->getY()) {
		y += 0;
	}
	else if (y > oPersonaje->getY()) {
		y -= dy;
		indiceY = 3;
	}
	else if (y < oPersonaje->getY()) {
		y += dy;
		indiceY = 0;
	}

	indiceX++;
	if (indiceX > 2) indiceX = 0;

}


void PacientePersecutor::mover(BufferedGraphics^ buffer, Personaje* oPersonaje) {
	desplazar(buffer, oPersonaje);
	dibujar(buffer);

}