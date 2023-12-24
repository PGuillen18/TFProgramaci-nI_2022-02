#pragma once
#include "AliadosRojos.h"
#include "AliadosAzules.h"
#include "Personaje.h"
#include "Mosquitos.h"
#include "Obstaculos.h"
#include "PacientesEnfermos.h"
#include "PacienteCurado.h"
#include "Proyectiles.h"
#include "SuperMosquito.h"
#include "PacientePersecutor.h"
#include "GotaAcida.h"
#include "AliadoSecreto.h"
#include "Archivo.h"



class Juego
{
public:
	Juego(int dificultad);
	~Juego();
	
	void generarPersonaje(char* _path_imagen);
	void atenderMovimientoPersonaje(bool tecla_presionada, Keys tecla);
	void moverPersonaje(BufferedGraphics^ buffer);
	void moverMosquitos(BufferedGraphics^ buffer);
	void moverAliados(BufferedGraphics^ buffer);
	void moverProyectiles(BufferedGraphics^ buffer);
	void verificarColisionMosquitoPersonaje(int dificultad);
	void verificarColisionAliadoRojoPersonaje();
	void verificarColisionAliadoAzulPersonaje();
	void dibujarObstaculos(BufferedGraphics^ buffer);
	int getVidas() { return contVidasFacil; }
	int getVidasDificil() { return contVidasDificil; }
	int getMosquitosRestantes() { return vMosquitos.size(); }
	int getPacientesEnfermos() { return vEnfermos.size(); }
	void MensajesFacil(BufferedGraphics^ buffer);
	void agregarMosquitos(int _N);
	bool verificarColision_Obstaculo_Objeto(Rectangle oRec);
	void agregarObstaculosFacil();
	void agregarPacientesEnfermos();
	void dibujarPacientesEnfermos(BufferedGraphics^ buffer);
	void verificarColisionPacientesEnfermosJugador(BufferedGraphics^ buffer);
	void dibujarCurado(BufferedGraphics^ buffer);
	void verificaColisionMosquitoObstaculo();
	void verificaColisionMosquitoProyectil();
	void setEnfermosCurarPoder(bool _CurarPoder) { CurarPoder = _CurarPoder; }
	void agregarSuperMosquito();
	void moverMosquitoSuper(BufferedGraphics^ buffer);
	void agregarObstaculosDificil();
	void moverMosquitosPersecutores(BufferedGraphics^ buffer);
	void agregarMosquitosPersecutores();
	void agregarGotasAcidas();
	void moverGotasAcidas(BufferedGraphics^ buffer);
	void atenderMovimientoPersonajeDificil(bool tecla_presionada, Keys tecla);
	void verificarColisionesAcidoPersecutor();
	void agregarAliadoSecreto();
	void movimientoSecreto(BufferedGraphics^ buffer);
	void setInvencible(bool _invencible) { invencible = _invencible; }
	bool getInvencible() { return invencible; }
	void serInvencible();
	void verificarColisionPersonajeSecreto();
	void MensajesDificil(BufferedGraphics^ buffer);
	void verificarColisionAcidoPersonaje();
	void verificarColisionPersecutorPersonaje();
	void verificarColisionSuperMosquitoPersonaje();
	void agregarEnfermosDificil();
	void verificarColisionProyectilPersecutor();
	
private:
	vector <Enfermos*> vEnfermos;
	vector <AliadosRojos*> vAliadosRojos;
	vector <AliadosAzules*> vAliadosAzules;
	vector <Obstaculo*> vObstaculos;
	vector <Curado*> vCurados;
	vector <Proyectil*> vProyectiles;
	vector <Mosquitos*> vMosquitos;
	vector <PacientePersecutor*> vPersecutores;
	vector <GotaAcida*> vGotaAcidas;
	vector <AliadoSecreto*> vAliadoSecreto;
	Personaje* oPersonaje;
	SuperMosquito* oMosquito;
	Archivo* oArchivo;

	int contVidasFacil = 10;
	int contVidasDificil = 5;
	int contBalas= 0;
	int contRecargaFacil = 5;
	int contCurarInfectadosFacil = 10;
	int contRecargaDificil = 3;
	int contCurarInfectadosDificil = 8;
	int contCantidadVecesInvencible = 5;
	bool CurarPoder =false;
	bool invencible = false;
	int dificultad;
};
Juego::Juego(int dificultad)
{
	oArchivo = new Archivo();
	oArchivo->leerArchivo();
	oArchivo->getLineas();

	this->dificultad = dificultad;
	switch (this->dificultad)
	{
	case 1:
		oPersonaje = new Personaje(stoi(oArchivo->getLineas()[0]), stoi(oArchivo->getLineas()[1]));
		break;
	case 2:
		oPersonaje = new Personaje(stoi(oArchivo->getLineas()[2]), stoi(oArchivo->getLineas()[3]));
		break;
	}

}
Juego::~Juego()
{
	if (oPersonaje != nullptr)delete oPersonaje;
}
void Juego::verificarColisionPersecutorPersonaje() {
	oArchivo = new Archivo();
	oArchivo->leerArchivo();
	oArchivo->getLineas();
	for (int i = 0; i < vPersecutores.size(); i++)
	{
		if (vPersecutores[i]->getAreaMosquitosPersonaje().IntersectsWith(oPersonaje->getAreaZoomeadaPersonaje())) {
			--contVidasDificil;
			--contVidasFacil;
			oPersonaje->setX(stoi(oArchivo->getLineas()[2]));
			oPersonaje->setY(stoi(oArchivo->getLineas()[3]));
			vPersecutores.clear();
			oMosquito->setX(stoi(oArchivo->getLineas()[4]));
			oMosquito->setY(stoi(oArchivo->getLineas()[5]));
		}
	}
}
void Juego::verificarColisionSuperMosquitoPersonaje() {
	if (oMosquito->getAreaMosquitosPersonaje().IntersectsWith(oPersonaje->getAreaZoomeadaPersonaje())) {
		contVidasDificil = 0;
}
}
void Juego::verificarColisionAcidoPersonaje() {
	for (int i = 0; i < vGotaAcidas.size(); i++)
	{
		if (vGotaAcidas[i]->getAreaDificil().IntersectsWith(oPersonaje->getAreaZoomeadaPersonaje()))
		{
			--contVidasDificil;
			--contVidasFacil; 
			oPersonaje->setX(580);
			oPersonaje->setY(570);
			vGotaAcidas.clear();
		}
	}
}
void Juego::agregarMosquitosPersecutores() {
	int posX = oMosquito->getX();
	int posY = oMosquito->getY();
	vPersecutores.push_back(new PacientePersecutor(posX, posY));
}
void Juego::agregarGotasAcidas() {
	Random r;
	oArchivo = new Archivo();
	oArchivo->leerArchivo();
	oArchivo->getLineas();

	int posX = r.Next(stoi(oArchivo->getLineas()[6]), stoi(oArchivo->getLineas()[7]));
	int posY = r.Next(stoi(oArchivo->getLineas()[8]), stoi(oArchivo->getLineas()[9]));
	vGotaAcidas.push_back(new GotaAcida(posX, posY));
}
void Juego::agregarAliadoSecreto() {
	Random r;
	for (int i = 0; i < 1; i++)
	{
		AliadoSecreto* oSecreto= new AliadoSecreto(r.Next(100, 1000), r.Next(500, 600));
		if (!oSecreto->getAreaDificil().IntersectsWith(oPersonaje->getAreaZoomeadaPersonaje())
			&& !verificarColision_Obstaculo_Objeto(oSecreto->getAreaDificil()))
		{
			vAliadoSecreto.push_back(oSecreto);
		}
		else
		{
			if (oSecreto != NULL) delete oSecreto;
			--i;
		}
	}
}
void Juego::serInvencible() {
	if (invencible == true) {
		oPersonaje->setVel(10);
	}
}
void Juego::agregarEnfermosDificil() {
	Random r;
	vEnfermos.push_back(new Enfermos(235, 30, 3 * r.Next(1, 4)));
	vEnfermos.push_back(new Enfermos(500, 30, 3 * r.Next(1, 4)));
	vEnfermos.push_back(new Enfermos(740, 30, 3 * r.Next(1, 4)));
	vEnfermos.push_back(new Enfermos(880, 30, 3 * r.Next(1, 4)));
	vEnfermos.push_back(new Enfermos(1050, 510, 3 * r.Next(1, 4)));
}
void Juego::movimientoSecreto(BufferedGraphics^ buffer) {
	for (int i = 0; i < vAliadoSecreto.size(); i++)
	{
		vAliadoSecreto[i]->mover(buffer);
	}
}
void Juego::MensajesDificil(BufferedGraphics^ buffer) {
	Font^ f = gcnew Font("Times New Roman", 16, FontStyle::Italic);
	buffer->Graphics->DrawString("Vidas: " +
		Convert::ToString(contVidasDificil), f, Brushes::Black, 0, 625);
	if (invencible==true)
	{
		buffer->Graphics->DrawString("ERES INVENCIBLE!!" , f, Brushes::BlueViolet, 100, 625);
	}
	else {
		buffer->Graphics->DrawString("Esperando...", f, Brushes::BlueViolet, 100, 625);
	}
	if (contRecargaDificil>0)
	{
		buffer->Graphics->DrawString("Recargas:"+Convert::ToString(contRecargaDificil), f, Brushes::Red, 300, 625);
	}
	else {
		buffer->Graphics->DrawString("Recargas: 0", f, Brushes::Red, 300, 625);
	}
	if (contCurarInfectadosDificil > 0)
	{
		buffer->Graphics->DrawString("Vacunas:" + Convert::ToString(contCurarInfectadosDificil), f, Brushes::Black, 700, 625);
	}
	else {
		buffer->Graphics->DrawString("Vacunas: 0", f, Brushes::Red, 700, 625);
	}
	buffer->Graphics->DrawString("Mosquitos Restantes: " +
		Convert::ToString(vMosquitos.size()), f, Brushes::Blue, 200, 600);
	buffer->Graphics->DrawString("Pacientes Restantes: " +
		Convert::ToString(vEnfermos.size()), f, Brushes::Blue, 0, 600);
	if (contBalas < 0)
	{
		buffer->Graphics->DrawString("Balas: 0", f, Brushes::Purple, 850, 625);
	}
	else {
		buffer->Graphics->DrawString("Balas: " +
			Convert::ToString(contBalas), f, Brushes::Purple, 850, 625);
	}
	if (CurarPoder == false)
	{
		buffer->Graphics->DrawString("Cuidate de los infectados", f, Brushes::Red, 950, 625);
	}
	else {
		buffer->Graphics->DrawString("Cura un paciente!!!", f, Brushes::Red, 950, 625);
	}
}
void Juego::moverGotasAcidas(BufferedGraphics^ buffer) {
	for (int i = 0; i < vGotaAcidas.size(); i++)
	{
		vGotaAcidas[i]->mover(buffer);
		if (vGotaAcidas[i]->getY() > buffer->Graphics->VisibleClipBounds.Height) {
			vGotaAcidas.erase(vGotaAcidas.begin() + i);
		}
	}
}
void Juego::moverMosquitosPersecutores(BufferedGraphics^ buffer) {
	for (int i = 0; i < vPersecutores.size(); i++)
	{
		vPersecutores[i]->mover(buffer,oPersonaje);
	}
}
void Juego::agregarObstaculosDificil() {
	vObstaculos.push_back(new Obstaculo(0, 0, 1200, 15));
	vObstaculos.push_back(new Obstaculo(0, 245, 135, 20));
	vObstaculos.push_back(new Obstaculo(0, 120, 230, 25));
	vObstaculos.push_back(new Obstaculo(245, 245, 710, 20));
	vObstaculos.push_back(new Obstaculo(1060, 245, 140, 20));
	vObstaculos.push_back(new Obstaculo(300, 120, 75, 20));
	vObstaculos.push_back(new Obstaculo(340, 0, 38, 250));
	vObstaculos.push_back(new Obstaculo(587, 0, 15, 180));
	vObstaculos.push_back(new Obstaculo(685, 0, 15, 180));
	vObstaculos.push_back(new Obstaculo(1015, 0, 30, 180));
	vObstaculos.push_back(new Obstaculo(825, 150, 375, 20));
	vObstaculos.push_back(new Obstaculo(0, 435, 235, 25));
	vObstaculos.push_back(new Obstaculo(965, 435, 235, 25));
	vObstaculos.push_back(new Obstaculo(430, 418, 330, 15));
	vObstaculos.push_back(new Obstaculo(725, 380, 130, 20));
	vObstaculos.push_back(new Obstaculo(340, 380, 130, 20));
	vObstaculos.push_back(new Obstaculo(340, 270, 35, 115));
	vObstaculos.push_back(new Obstaculo(820, 270, 35, 115));
	vObstaculos.push_back(new Obstaculo(150, 0, 30, 160));
	vObstaculos.push_back(new Obstaculo(360, 150, 150, 30));
}
void Juego::agregarPacientesEnfermos() {
	Random r;
		vEnfermos.push_back(new Enfermos(125, 30, 3 * r.Next(1, 4)));
		vEnfermos.push_back(new Enfermos(375, 30, 3 * r.Next(1, 4)));
		vEnfermos.push_back(new Enfermos(750, 30, 3 * r.Next(1, 4)));

}
void Juego::verificarColisionesAcidoPersecutor() {
	for (int i = 0; i < vPersecutores.size(); i++)
	{
		for (int j = 0; j < vGotaAcidas.size(); j++)
		{
			if (vPersecutores[i]->getAreaDificil().IntersectsWith(vGotaAcidas[j]->getAreaDificil()))
			{
				int posX = vPersecutores[i]->getX();
				int posY = vPersecutores[i]->getY();
				vMosquitos.push_back(new Mosquitos(posX, posY));
				vPersecutores.erase(vPersecutores.begin() + i);
				vGotaAcidas.erase(vGotaAcidas.begin() + j);
			}
		}
	}
}
void Juego::agregarSuperMosquito() {
	oMosquito = new SuperMosquito(1100,30);
}
void Juego::moverMosquitoSuper(BufferedGraphics^ buffer) {
	oMosquito->mover(buffer, oPersonaje);
}
void Juego::dibujarCurado(BufferedGraphics^ buffer) {
	for (int i = 0; i < vCurados.size(); i++)
	{
		vCurados[i]->dibujar(buffer);
	}
}
void Juego::dibujarPacientesEnfermos(BufferedGraphics^ buffer) {
	for (int i = 0; i < vEnfermos.size(); i++)
	{

		vEnfermos[i]->dibujar(buffer);
	}
}
void Juego::agregarObstaculosFacil() {
	vObstaculos.push_back(new Obstaculo(0, 0, 1200, 25));
	vObstaculos.push_back(new Obstaculo(0, 0, 50, 600));
	vObstaculos.push_back(new Obstaculo(0, 540, 175, 70));
	vObstaculos.push_back(new Obstaculo(370, 540, 830, 70));
	vObstaculos.push_back(new Obstaculo(1150, 0, 50, 600));
	vObstaculos.push_back(new Obstaculo(0, 240, 470, 30));
	vObstaculos.push_back(new Obstaculo(0, 150, 115, 30));
	vObstaculos.push_back(new Obstaculo(180, 150, 230, 30));
	vObstaculos.push_back(new Obstaculo(303, 0, 50, 180));
	vObstaculos.push_back(new Obstaculo(603, 0, 50, 180));
	vObstaculos.push_back(new Obstaculo(480, 150, 230, 30));
	vObstaculos.push_back(new Obstaculo(780, 150, 230, 30));
	vObstaculos.push_back(new Obstaculo(1080, 150, 130, 30));
	vObstaculos.push_back(new Obstaculo(730, 330, 500, 25));
	vObstaculos.push_back(new Obstaculo(903, 0, 50, 180));
	vObstaculos.push_back(new Obstaculo(425, 240, 45, 220));
	vObstaculos.push_back(new Obstaculo(245, 448, 225, 20));
	vObstaculos.push_back(new Obstaculo(0, 365, 295, 20));
}
void Juego::generarPersonaje(char* _path_imagen) {

	oPersonaje->generandoPersonaje(_path_imagen);
}
void Juego::dibujarObstaculos(BufferedGraphics^ buffer)
{
	for (int i = 0; i < vObstaculos.size(); i++)
	{
		
		vObstaculos[i]->dibujar(buffer);
	}
}
void Juego::moverProyectiles(BufferedGraphics^ buffer) {
	for (int i = 0; i < vProyectiles.size(); i++)
	{
		if (!verificarColision_Obstaculo_Objeto(vProyectiles[i]->getArea()))
			vProyectiles[i]->mover(buffer);
		else
			vProyectiles.erase(vProyectiles.begin() + i);
	}
}
void Juego::atenderMovimientoPersonaje(bool tecla_presionada, Keys tecla) {
	Random r;
	int posX = oPersonaje->getX();
	int posY = oPersonaje->getY();
	int N;
	switch (oPersonaje->getIndiceY())
	{
	case 4:
		N = 3;
		break;
	case 5:
		N = 4;
		break;
	case 6:         //Esta función logra que obtenga la direccion en la cual la bala se dispara
		N = 1;
		break;
	case 7:
		N = 2;
		break;
	}

	if (tecla_presionada) {
		switch (tecla) {
		case Keys::Left:
			oPersonaje->setAccion(izquierda);
			break;
		case Keys::Right:
			oPersonaje->setAccion(derecha);
			break;
		case Keys::Up:
			oPersonaje->setAccion(arriba);
			break;
		case Keys::Down:
			oPersonaje->setAccion(abajo);
			break;
		case Keys::Z:
			if(contRecargaFacil>0)
			vAliadosRojos.push_back(new AliadosRojos(posX, posY - 200));
			contRecargaFacil--;
			break;
		case Keys::X:
			if(contCurarInfectadosFacil>0)
			vAliadosAzules.push_back(new AliadosAzules(posX-200, posY));
			contCurarInfectadosFacil--;
			break;
		case Keys::Space:
			if(contBalas>0)
			vProyectiles.push_back(new Proyectil(posX+15, posY+10, 7,N));
			contBalas--;
			break;
		}
	}
	else
	{
		oPersonaje->setAccion(ninguna);
	}
}
void Juego::verificarColisionProyectilPersecutor() {
	for (int i = 0; i < vPersecutores.size(); i++)
	{
		for (int j = 0; j < vProyectiles.size(); j++)
		{
			if (vPersecutores[i]->getAreaMosquitosPersonaje().IntersectsWith(vProyectiles[j]->getArea()))
			{
				vPersecutores.erase(vPersecutores.begin() + i);
				vProyectiles.erase(vProyectiles.begin() + j);
			}
		}

	}
}
void Juego::atenderMovimientoPersonajeDificil(bool tecla_presionada, Keys tecla)
{
	Random r;
	int posX = oPersonaje->getX();
	int posY = oPersonaje->getY();
	int N;
	switch (oPersonaje->getIndiceY())
	{
	case 4:
		N = 3;
		break;
	case 5:
		N = 4;
		break;
	case 6:         //Esta función logra que obtenga la direccion en la cual la bala se dispara
		N = 1;
		break;
	case 7:
		N = 2;
		break;
	}

	if (tecla_presionada) {
		switch (tecla) {
		case Keys::Left:
			oPersonaje->setAccion(izquierda);
			break;
		case Keys::Right:
			oPersonaje->setAccion(derecha);
			break;
		case Keys::Up:
			oPersonaje->setAccion(arriba);
			break;
		case Keys::Down:
			oPersonaje->setAccion(abajo);
			break;
		case Keys::Z:
			if (contRecargaDificil > 0)
				vAliadosRojos.push_back(new AliadosRojos(posX, posY - 200));
			contRecargaDificil--;
			break;
		case Keys::X:
			if (contCurarInfectadosDificil > 0)
				vAliadosAzules.push_back(new AliadosAzules(posX - 200, posY));
			contCurarInfectadosDificil--;
			break;
		case Keys::F:
			if (invencible == false) {
				if (contCantidadVecesInvencible > 0)
					setInvencible(true);
				vPersecutores.clear();
				contCantidadVecesInvencible--;
			}
			break;
		case Keys::Space:
			if (contBalas > 0)
				vProyectiles.push_back(new Proyectil(posX + 15, posY + 10, 7, N));
			contBalas--;
			break;
		}
	}
	else
	{
		oPersonaje->setAccion(ninguna);
	}
}
void Juego::moverAliados(BufferedGraphics^ buffer) {
	for (int i = 0; i < vAliadosRojos.size(); i++)
	{
		vAliadosRojos[i]->mover(buffer);
	}
	for (int i = 0; i < vAliadosAzules.size(); i++)
	{
		vAliadosAzules[i]->mover(buffer);
	}
}
void Juego::moverMosquitos(BufferedGraphics^ buffer) {
	for (int i = 0; i < vMosquitos.size(); i++)
	{
		vMosquitos[i]->mover(buffer);
	}
}
void Juego::moverPersonaje(BufferedGraphics^ buffer) {
	
	
	if (!verificarColision_Obstaculo_Objeto(oPersonaje->getSigArea()))
	{
		oPersonaje->mover(buffer);
	
	}
	else
	{
		oPersonaje->setVel(5);
		oPersonaje->setX(oPersonaje->getX() - oPersonaje->getDX());
		oPersonaje->setY(oPersonaje->getY() - oPersonaje->getDY());
		setInvencible(false);
		oPersonaje->dibujar(buffer);

	}
}
void Juego::agregarMosquitos(int _N)
{
	Random r;	
	for (int i = 0; i < _N; i++)
	{
		Mosquitos* oMosquito = new Mosquitos(r.Next(100,1000),r.Next(50,200));
		if (!oMosquito->getAreaMosquitosPersonaje().IntersectsWith(oPersonaje->getAreaZoomeadaPersonaje())	
			&& !verificarColision_Obstaculo_Objeto(oMosquito->getAreaMosquitosPersonaje())&&oMosquito->getX()>100&&oMosquito->getY()<200)	
		{
			vMosquitos.push_back(oMosquito);
		}
		else
		{
			if (oMosquito!= NULL) delete oMosquito;
			--i;
		}
	}

}
void Juego::verificaColisionMosquitoObstaculo() {
	for (int i = 0; i < vObstaculos.size(); i++)
	{
		for (int j = 0; j < vMosquitos.size(); j++)
		{
			if (vObstaculos[i]->getArea().IntersectsWith(vMosquitos[j]->getSigArea()))
			{
			
				vMosquitos[j]->setDX(vMosquitos[j]->getDX() * -1);
			}
		}
	}
}
void Juego::verificarColisionMosquitoPersonaje(int dificultad) {
	Random r;
	for (int i = 0; i < vMosquitos.size(); i++)
	{
		if (oPersonaje->getAreaZoomeadaPersonaje().IntersectsWith(vMosquitos[i]->getAreaMosquitosPersonaje()))
		{
			--contVidasDificil;
			--contVidasFacil;
			setEnfermosCurarPoder(false);
			switch (dificultad)
			{
			case 1:
				oPersonaje->setX(250);
				oPersonaje->setY(550);
				break;
			case 2:
				oPersonaje->setX(580);
				oPersonaje->setY(570);
				break;
			}
			
			
			vMosquitos[i]->setX(r.Next(60,1100));
			vMosquitos[i]->setY(200);
			vMosquitos[i]->setDY(vMosquitos[i]->getDY() * -1);
			vMosquitos[i]->setDX(vMosquitos[i]->getDX() * -1);
		}
	}
}
void Juego::verificarColisionPersonajeSecreto() {
	for (int i = 0; i < vAliadoSecreto.size(); i++)
	{
		for (int j = 0; j < vPersecutores.size(); j++)
		{
			if (oPersonaje->getAreaZoomeadaPersonaje().IntersectsWith(vAliadoSecreto[i]->getAreaDificil()))
			{
				vPersecutores.clear();
				vGotaAcidas.clear();
				vAliadoSecreto.erase(vAliadoSecreto.begin() + i);
			}
		}
		
	}
}
void Juego::MensajesFacil(BufferedGraphics^ buffer) {
	Font^ f = gcnew Font("Times New Roman", 28, FontStyle::Italic);
	buffer->Graphics->DrawString("Vidas: " +
		Convert::ToString(contVidasFacil), f, Brushes::Black, 0, 560);
	buffer->Graphics->DrawString("Mosquitos Restantes: " +
		Convert::ToString(vMosquitos.size()), f, Brushes::Blue, 400, 560);
	buffer->Graphics->DrawString("Pacientes Restantes: " +
		Convert::ToString(vEnfermos.size()), f, Brushes::Green, 800, 560);
	Font^ z = gcnew Font("Times New Roman", 18, FontStyle::Italic);
	if (contBalas <= 0)
	{
		buffer->Graphics->DrawString("Balas Disponibles: " +"0", z, Brushes::Purple, 0, 0);
	}
	else {
		buffer->Graphics->DrawString("Balas Disponibles: " +
			Convert::ToString(contBalas), z, Brushes::Purple, 0, 0);
	}
	if (CurarPoder == false)
	{
		buffer->Graphics->DrawString("Cuidate de los infectados", z, Brushes::Red, 300, 0);
	}
	else {
		buffer->Graphics->DrawString("Cura un paciente!!!" , z, Brushes::Red, 300, 0);
	}
	if (contCurarInfectadosFacil <= 0)
	{
		buffer->Graphics->DrawString("Vacunas para Inyectar:" + "0", z, Brushes::Blue, 600, 0);
	}
	else {
		buffer->Graphics->DrawString("Vacunas para Inyectar: " +
			Convert::ToString(contCurarInfectadosFacil), z, Brushes::Blue, 600, 0);
	}
	if (contRecargaFacil<= 0)
	{
		buffer->Graphics->DrawString("Recargas Disponibles:" + "0", z, Brushes::Blue, 900, 0);
	}
	else {
		buffer->Graphics->DrawString("Recargas Disponibles: " +
			Convert::ToString(contRecargaFacil), z, Brushes::Blue, 900, 0);
	}

}
void Juego::verificarColisionAliadoRojoPersonaje() {
	for (int i = 0; i < vAliadosRojos.size(); i++)
	{
		if (oPersonaje->getAreaZoomeadaPersonaje().IntersectsWith(vAliadosRojos[i]->getAreaZoomeadaPersonaje()))
		{
			contBalas = 3;		
			vAliadosRojos.erase(vAliadosRojos.begin() + i);
		}
	}
}
void Juego::verificarColisionAliadoAzulPersonaje() {
	for (int i = 0; i < vAliadosAzules.size(); i++)
	{
		if (oPersonaje->getAreaZoomeadaPersonaje().IntersectsWith(vAliadosAzules[i]->getAreaZoomeadaPersonaje()))
		{
			setEnfermosCurarPoder(true);
			vAliadosAzules.erase(vAliadosAzules.begin() + i);
		}
	}
}
bool Juego::verificarColision_Obstaculo_Objeto(Rectangle oRec)
{
	for (int i = 0; i < vObstaculos.size(); i++)
	{
		if (vObstaculos[i]->getArea().IntersectsWith(oRec))
			return true;
	}
	return false;
}
void Juego::verificarColisionPacientesEnfermosJugador(BufferedGraphics^ buffer) {
	
	for (int i = 0; i < vEnfermos.size(); i++)
	{
		if (vEnfermos[i]->getAreaEnfermoPersonaje().IntersectsWith(oPersonaje->getAreaZoomeadaPersonaje()))
		{
			if (CurarPoder == true) {
				setEnfermosCurarPoder(false);
				vCurados.push_back(new Curado(vEnfermos[i]->getX(), vEnfermos[i]->getY()));
				vEnfermos.erase(vEnfermos.begin() + i);
			}
			else
			{
				--contVidasDificil;
				--contVidasFacil;
				switch (dificultad)
				{
				case 1:
					oPersonaje->setX(250);
					oPersonaje->setY(550);
					break;
				case 2:
					oPersonaje->setX(580);
					oPersonaje->setY(570);
					break;
				}
				
			}
		}
	}
}
void Juego::verificaColisionMosquitoProyectil() {
	for (int i = 0; i < vMosquitos.size(); i++)
	{
		for (int j = 0; j < vProyectiles.size(); j++)
		{
			if (vMosquitos[i]->getAreaMosquitosPersonaje().IntersectsWith(vProyectiles[j]->getArea()))
			{
				vMosquitos.erase(vMosquitos.begin() + i);
				vProyectiles.erase(vProyectiles.begin() + j);
			}
		}
		
	}
}