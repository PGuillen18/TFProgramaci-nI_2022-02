#pragma once
#include "Figura.h"

class Proyectil : public Figura
{
private:
	int radio;
	int N;
	bool activa;
public:
	Proyectil(int _x, int _y, int _radio,int _N);
	~Proyectil();

	int getRadio();
	bool getActiva();
	void setActiva(bool _activa) { activa = _activa; }
	void dibujar(BufferedGraphics^ bg);
	void desplazararriba(BufferedGraphics^ bg);
	void desplazarabajo(BufferedGraphics^ bg);
	void desplazarizquierda(BufferedGraphics^ bg);
	void desplazarderecha(BufferedGraphics^ bg);
	void mover(BufferedGraphics^ bg);
};

Proyectil::Proyectil(int _x, int _y, int _radio, int _N) :Figura(_x, _y)
{
	N = _N;
	radio = _radio;
	dx = 10;
	dy = 10;
	ancho = alto = 2 * radio;
	activa = true;
}
Proyectil::~Proyectil() {}

int Proyectil::getRadio() { return radio; }
bool Proyectil::getActiva() { return activa; }

void Proyectil::dibujar(BufferedGraphics^ bg) {
	if (activa)
	{
		SolidBrush^ sb = gcnew SolidBrush(Color::Blue);
		bg->Graphics->FillEllipse(sb, x, y, ancho, alto);
	}
}
void Proyectil::desplazararriba(BufferedGraphics^ bg) {
	if (activa)
	{
		if (y + dy < 0||y+dy+alto>bg->Graphics->VisibleClipBounds.Height)
		{
			activa = false;
		}
		y -= dy;
	}
}
void Proyectil::desplazarabajo(BufferedGraphics^ bg) {
	if (activa)
	{
		if (y + dy < 0 || y + dy + alto>bg->Graphics->VisibleClipBounds.Height)
		{
			activa = false;
		}
		y += dy;
	}
}

void Proyectil::desplazarderecha(BufferedGraphics^ bg) {
	if (activa)
	{
		if (x + dx < 0 || x + dx + ancho>bg->Graphics->VisibleClipBounds.Width)
		{
			activa = false;
		}
		x += dx;
	}
}
void Proyectil::desplazarizquierda(BufferedGraphics^ bg) {
	if (activa)
	{
		if (x + dx < 0 || x + dx + ancho>bg->Graphics->VisibleClipBounds.Width)
		{
			activa = false;
		}
		x -= dx;
	}
}
void Proyectil::mover(BufferedGraphics^ bg) {
	if(N==1)
		desplazararriba(bg);
	if(N==2)
		desplazarderecha(bg);
	if (N == 3)
		desplazarabajo(bg);
	if (N == 4)
		desplazarizquierda(bg);
	dibujar(bg);
}