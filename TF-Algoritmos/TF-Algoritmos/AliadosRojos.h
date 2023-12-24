#pragma once
#include "Figura.h"


class AliadosRojos :public Figura
{
public:
	AliadosRojos(int _x, int _y);
	~AliadosRojos();
	void dibujar(BufferedGraphics^ buffer);
	void mover(BufferedGraphics^ buffer);
	bool getActiva() { return activa; }
	void desplazar(BufferedGraphics^ buffer);

private:
	int indiceX, indiceY;
	bool activa;
};

AliadosRojos::AliadosRojos(int _x, int _y) :Figura(_x, _y)
{
	dx = 5;
	dy = 5;
	indiceX = indiceY = 0;
}

AliadosRojos::~AliadosRojos()
{

}
void AliadosRojos::dibujar(BufferedGraphics^ buffer) {
	if (activa) {
		Bitmap^ imgAliado = gcnew Bitmap(gcnew System::String("Imagenes/Aliado.png"));
		ancho = imgAliado->Width / 6;
		alto = imgAliado->Height / 4;
		Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 0.7, alto * 0.7);
		buffer->Graphics->DrawImage(imgAliado, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
		delete imgAliado;
	}
}

void AliadosRojos::desplazar(BufferedGraphics^ buffer) {
	if (activa) {

		indiceY = 0; dx = 0;
		if (indiceX >= 0 && indiceX < 2) ++indiceX;
		else indiceX = 0;

		if (y + dy + alto * 0.7> buffer->Graphics->VisibleClipBounds.Height)
			activa = false;
		y += dy;
	}
}

void AliadosRojos::mover(BufferedGraphics^ buffer) {
	if (activa) {
		desplazar(buffer);
		dibujar(buffer);
	}
}