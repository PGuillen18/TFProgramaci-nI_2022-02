#pragma once
#include "Juego.h"
#include "GanastePantalla.h"
#include "PerdistePantalla.h"
namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormularioJuegoDificil
	/// </summary>
	public ref class FormularioJuegoDificil : public System::Windows::Forms::Form
	{
	private:
		Juego* oJuego;
		
	private: System::Windows::Forms::Timer^ timerMosquitosPersecutores;
	private: System::Windows::Forms::Timer^ timerLluviaAcida;
	private: System::Windows::Forms::Timer^ timerSecreto;
		   Bitmap^ fondo;

	public:
		FormularioJuegoDificil(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		StartPosition:CenterToScreen(); //CenterToScreen logra que nuestro formulario se encuentre centrado en la pantalla
			fondo = gcnew Bitmap("Imagenes/fondoDificil.png");
			oJuego = new Juego(2);
			oJuego->generarPersonaje("Imagenes/Jugador.png");
			oJuego->agregarMosquitos(3);
			oJuego->agregarSuperMosquito();
			oJuego->agregarObstaculosDificil();
			oJuego->agregarEnfermosDificil();
			timerDificilJuego->Enabled = true;
			timerDificilJuego->Interval = 50;
			timerMosquitosPersecutores->Enabled = true;
			timerMosquitosPersecutores->Interval = 10000;
			timerLluviaAcida->Enabled = true;
			timerLluviaAcida->Interval= 5000;
			timerSecreto->Enabled = true;
			timerSecreto->Interval = 30000;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormularioJuegoDificil()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timerDificilJuego;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timer1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerDificilJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerMosquitosPersecutores = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerLluviaAcida = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerSecreto = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timerDificilJuego
			// 
			this->timerDificilJuego->Tick += gcnew System::EventHandler(this, &FormularioJuegoDificil::timerDificilJuego_Tick);
			// 
			// timerMosquitosPersecutores
			// 
			this->timerMosquitosPersecutores->Tick += gcnew System::EventHandler(this, &FormularioJuegoDificil::timerMosquitosPersecutores_Tick);
			// 
			// timerLluviaAcida
			// 
			this->timerLluviaAcida->Tick += gcnew System::EventHandler(this, &FormularioJuegoDificil::timerLluviaAcida_Tick);
			// 
			// timerSecreto
			// 
			this->timerSecreto->Tick += gcnew System::EventHandler(this, &FormularioJuegoDificil::timerSecreto_Tick);
			// 
			// FormularioJuegoDificil
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 645);
			this->Name = L"FormularioJuegoDificil";
			this->Text = L"FormularioJuegoDificil";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormularioJuegoDificil::FormularioJuegoDificil_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormularioJuegoDificil::FormularioJuegoDificil_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerDificilJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		Rectangle area_usar = Rectangle(0, 0, fondo->Width, fondo->Height);
		Rectangle reduccion_usar = Rectangle(0, 0, fondo->Width*3, fondo->Height*2);
		buffer->Graphics->DrawImage(fondo, reduccion_usar, area_usar, GraphicsUnit::Pixel);

		oJuego->moverPersonaje(buffer);
		oJuego->moverMosquitoSuper(buffer);
		oJuego->moverMosquitos(buffer);
		oJuego->moverAliados(buffer);
		oJuego->moverMosquitosPersecutores(buffer);
		oJuego->moverGotasAcidas(buffer);
		oJuego->moverProyectiles(buffer);
		oJuego->verificaColisionMosquitoProyectil();
		oJuego->verificarColisionPacientesEnfermosJugador(buffer);
		oJuego->dibujarObstaculos(buffer);
		oJuego->movimientoSecreto(buffer);
		if (oJuego->getInvencible() == false) {
			oJuego->verificarColisionMosquitoPersonaje(2);
			oJuego->verificarColisionAcidoPersonaje();
			oJuego->verificarColisionPersecutorPersonaje();
			oJuego->verificarColisionSuperMosquitoPersonaje();
		}
		oJuego->verificarColisionPacientesEnfermosJugador(buffer);
		oJuego->verificarColisionProyectilPersecutor();
		oJuego->verificaColisionMosquitoObstaculo();
		oJuego->dibujarPacientesEnfermos(buffer);
		oJuego->dibujarCurado(buffer);
		oJuego->verificarColisionPersonajeSecreto();
		oJuego->serInvencible();
		oJuego->verificarColisionAliadoAzulPersonaje();
		oJuego->verificarColisionAliadoRojoPersonaje();
		oJuego->verificarColisionesAcidoPersecutor();
		oJuego->MensajesDificil(buffer);
		buffer->Render(g);
		if (oJuego->getVidasDificil() == 0 )
		{
			timerDificilJuego->Enabled = false;
			timerLluviaAcida->Enabled = false;
			timerMosquitosPersecutores->Enabled = false;
			timerSecreto->Enabled = false;
			PerdistePantalla^ oFormPerder = gcnew PerdistePantalla();
			oFormPerder->ShowDialog();
			delete oFormPerder;
			this->Close();
		}

		if (oJuego->getPacientesEnfermos() == 0 && oJuego->getMosquitosRestantes() == 0)
		{
			timerDificilJuego->Enabled = false;
			timerLluviaAcida->Enabled = false;
			timerMosquitosPersecutores->Enabled = false;
			timerSecreto->Enabled = false;
			GanastePantalla^ oFormGanar = gcnew GanastePantalla();
			oFormGanar->ShowDialog();
			delete oFormGanar;
			this->Close();
		}
	}
	private: System::Void FormularioJuegoDificil_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oJuego->atenderMovimientoPersonajeDificil(true, e->KeyCode);
		switch (e->KeyCode)
		{
		case Keys::Escape:
			this->Close();
		}
	}
	private: System::Void FormularioJuegoDificil_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oJuego->atenderMovimientoPersonajeDificil(false, e->KeyCode);
	}
	private: System::Void timerMosquitosPersecutores_Tick(System::Object^ sender, System::EventArgs^ e) {
		oJuego->agregarMosquitosPersecutores();
	}
    private: System::Void timerLluviaAcida_Tick(System::Object^ sender, System::EventArgs^ e) {
		oJuego->agregarGotasAcidas();
    }
private: System::Void timerSecreto_Tick(System::Object^ sender, System::EventArgs^ e) {
	oJuego->agregarAliadoSecreto();
}
};
}
