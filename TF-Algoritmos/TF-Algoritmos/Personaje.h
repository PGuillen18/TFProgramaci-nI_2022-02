#pragma once
#include "Figura.h"

class Personaje :public Figura
{
public:
	Personaje(int _x, int _y);
	~Personaje();

	void generandoPersonaje(char* _path_imagen);
	void dibujar(BufferedGraphics^ buffer);
	void mover(BufferedGraphics^ buffer);
	void desplazar(BufferedGraphics^ buffer);
	void setIndiceX(int _indiceX);
	void setIndiceY(int _indiceY);
	void setAccion(acciones _accion);
	acciones getAccion() { return accion; }
	int getIndiceX(){return indiceX;};
	int getIndiceY(){return indiceY;};
	void setVel(int _vel) { vel = _vel; }
private:

	char* path_imagen;
	int indiceX;
	int indiceY;
	acciones accion;
	int vel;
};

Personaje::Personaje(int _x, int _y) :Figura(_x, _y)
{
	indiceX = indiceY = 0;
	accion = ninguna;
	path_imagen = new char[70];
	vel = 5;
}

Personaje::~Personaje()
{}

void Personaje::setIndiceX(int _indiceX) { indiceX = _indiceX; }
void Personaje::setIndiceY(int _indiceY) { indiceY = _indiceY; }
void Personaje::setAccion(acciones _accion) { accion = _accion; }

void Personaje::generandoPersonaje(char* _path_imagen) {
	//Convierte la dirección del spritesheet a un string para que el bitmap lo pueda leer correctamente
	strcpy(path_imagen, _path_imagen);
	Bitmap^ imgPersonaje = gcnew Bitmap(gcnew System::String(path_imagen));
	ancho = imgPersonaje->Width / 10;
	alto = imgPersonaje->Height / 8;
	delete imgPersonaje;
}

void Personaje::dibujar(BufferedGraphics^ buffer) {
	//Dibuja al personaje
	Bitmap^ bmp = gcnew Bitmap(gcnew System::String(path_imagen));
	Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 0.5, alto * 0.5);
	buffer->Graphics->DrawImage(bmp, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
	delete bmp;
}

void Personaje::desplazar(BufferedGraphics^ buffer) {
	//Desplazamiento del personaje principal.
	switch (accion) {
	case derecha:
		indiceY = 7; dx = vel; 
		if (indiceX >= 0 && indiceX < 9) ++indiceX;
		else indiceX = 0;
		break;
	case izquierda:
		indiceY = 5; dx = -vel; 
		if (indiceX >= 0 && indiceX < 9) ++indiceX;
		else indiceX = 0;
		break;
	case arriba:
		indiceY = 6; dy = -vel;
		if (indiceX >= 0 && indiceX < 9) ++indiceX;
		else indiceX = 0;
		break;
	case abajo:
		indiceY = 4; dy = vel; 
		if (indiceX >= 0 && indiceX < 9) ++indiceX;
		else indiceX = 0;
		break;
	case ninguna:
		dx = 0;
		dy = 0;
	}
	if (x + dx < 0 || x + dx + ancho * 0.5 > buffer->Graphics->VisibleClipBounds.Width)
		dx = -dx; //En caso limite de ancho alcanzado, no sobrepase este.
	if (y + dy < 0 || y + dy + alto * 0.5 > buffer->Graphics->VisibleClipBounds.Height)
		dy = -dy; //En caso limite de alto alcanzado, no sobrepase este.

	x += dx;
	y += dy;
}

void Personaje::mover(BufferedGraphics^ buffer) {
	desplazar(buffer);
	dibujar(buffer);
}