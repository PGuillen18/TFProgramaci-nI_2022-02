#pragma once
#include "Figura.h"

class Archivo
{
	vector<string>vLineas;
public:
	Archivo();
	~Archivo();
	void leerArchivo();
	vector<string> getLineas() { return vLineas; }
};

Archivo::Archivo()
{}

Archivo::~Archivo()
{}

void Archivo::leerArchivo() {
	ifstream miArchivo;
	miArchivo.open("Datos.txt", ios::in);
	string texto;
	if (miArchivo.is_open())
	{
		//Leer del Archivo
		while (!miArchivo.eof()) //eof: end of file
		{
			getline(miArchivo, texto);
			vLineas.push_back(texto);
		}
		miArchivo.close();
	}
	else
	{
		cout << "Error: No se pudo abrir el Archivo !";
	}

}

