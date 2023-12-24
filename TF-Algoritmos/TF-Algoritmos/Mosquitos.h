#pragma once
#include "Figura.h"

class Mosquitos :public Figura
{
public:
	Mosquitos(int _x, int _y);
	~Mosquitos();
	void dibujar(BufferedGraphics^ buffer);
	void desplazar(BufferedGraphics^ buffer);
	void mover(BufferedGraphics^ buffer);
private:
	int indiceX, indiceY;
	int anchoMosquito[6][7] = {
		{0,90,170,257,340,430,510},
	{0,73,155,235,312,390,465},
	{0,70,140,210,280,350,420},
	{0,70,140,210,280,350,420},
	{0,95,180,290,370,470,560},
	{0,90,170,260,343,430,520} };
	int altoMosquito[7] = { 0,78,160,242,336,417,477
	};
};

Mosquitos::Mosquitos(int _x, int _y) :Figura(_x, _y)
{
	dx = 3;
	dy = 3;
	indiceX = indiceY = 0;
}

Mosquitos::~Mosquitos()
{

}
void Mosquitos::dibujar(BufferedGraphics^ buffer) {
		Bitmap^ imgEnemigo = gcnew Bitmap(gcnew System::String("Imagenes/EnemigoMosquitoSprite.png"));
		ancho = anchoMosquito[indiceY][indiceX + 1] - anchoMosquito[indiceY][indiceX];
		alto = altoMosquito[indiceY + 1] - altoMosquito[indiceY];
		int ubicaX_Mosquito = anchoMosquito[indiceY][indiceX];
		int ubicaY_Mosquito = altoMosquito[indiceY];
		Rectangle areaUsar = Rectangle(ubicaX_Mosquito, ubicaY_Mosquito, ancho, alto);
		Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 0.5, alto * 0.5);
		buffer->Graphics->DrawImage(imgEnemigo, aumentoPersonaje, areaUsar, GraphicsUnit::Pixel);
		delete imgEnemigo;
}
void Mosquitos::desplazar(BufferedGraphics^ buffer) {

		switch (dy)
		{
		case 3:
			indiceY = 0;
			if (indiceX >= 0 && indiceX < 2) ++indiceX;
			else indiceX = 0;
			break;
		case -3:
			indiceY = 4;
			if (indiceX >= 0 && indiceX < 2) ++indiceX;
			else indiceX = 0;
			break;
		}
		if (y + dy < 0 || y + dy + alto * 0.5> buffer->Graphics->VisibleClipBounds.Height-30)
			dy = -dy;
		if (x + dx < 0 || x + dx + ancho * 0.5 > buffer->Graphics->VisibleClipBounds.Width-50)
			dx = -dx;
		x += dx;
		y += dy;

}


void Mosquitos::mover(BufferedGraphics^ buffer) {
desplazar(buffer);	
dibujar(buffer);
	
}