#pragma once
#include "Figura.h"


class AliadosAzules :public Figura
{
public:
	AliadosAzules(int _x, int _y);
	~AliadosAzules();
	void dibujar(BufferedGraphics^ buffer);
	void mover(BufferedGraphics^ buffer);
	bool getActiva() { return activa; }
	void desplazar(BufferedGraphics^ buffer);

private:
	int indiceX, indiceY;
	bool activa;
};

AliadosAzules::AliadosAzules(int _x, int _y) :Figura(_x, _y)
{
	dx = 5;
	dy = 5;
	indiceX = indiceY = 0;
}

AliadosAzules::~AliadosAzules()
{

}
void AliadosAzules::dibujar(BufferedGraphics^ buffer) {
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

void AliadosAzules::desplazar(BufferedGraphics^ buffer) {
	if (activa) {
		
		indiceY = 2; dy = 0;
		if (indiceX >= 3 && indiceX < 5) ++indiceX;
		else indiceX = 3;
		
		if (x + dx + ancho> buffer->Graphics->VisibleClipBounds.Width)
			activa = false;
			x += dx;
	}
}

void AliadosAzules::mover(BufferedGraphics^ buffer) {
	if (activa) {
		desplazar(buffer);
		dibujar(buffer);
	}
}