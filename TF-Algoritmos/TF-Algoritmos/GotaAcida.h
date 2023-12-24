#pragma once
#include "Figura.h"

class GotaAcida:public Figura
{
public:
	GotaAcida(int _x, int _y);
	~GotaAcida();
	void dibujar(BufferedGraphics^ buffer);
	void desplazar(BufferedGraphics^ buffer);
	void mover(BufferedGraphics^ buffer);
	bool getActiva() { return activa; }
	void setActiva(bool _activa) { activa = _activa; }
private:
	int indiceX, indiceY;
	bool activa = true;
	
};

GotaAcida::GotaAcida(int _x, int _y):Figura (_x,_y)
{
	dx = 0;
	dy = 3;
	indiceX = indiceY = 0;
}

GotaAcida::~GotaAcida()
{
}

void GotaAcida::dibujar(BufferedGraphics^ buffer) {
	if (activa)
	{
		Bitmap^ imgGotaAcida = gcnew Bitmap(gcnew System::String("Imagenes/GotaAcida.png"));
		ancho = imgGotaAcida->Width;
		alto = imgGotaAcida->Height;
		Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 0.2, alto * 0.2);
		buffer->Graphics->DrawImage(imgGotaAcida, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
		delete imgGotaAcida;
	}
}

void GotaAcida::desplazar(BufferedGraphics^ buffer) {
	if (activa) {
		if (y + dy + alto * 0.2 > buffer->Graphics->VisibleClipBounds.Width)
		{
			activa = false;
		}
		y += dy;
	}
}

void GotaAcida::mover(BufferedGraphics^ buffer) {
	if (activa) {
		desplazar(buffer);
		dibujar(buffer);
	}
}