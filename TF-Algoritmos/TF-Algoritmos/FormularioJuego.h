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
	/// Resumen de FormularioJuego
	/// </summary>
	public ref class FormularioJuego : public System::Windows::Forms::Form
	{
	private:
		Juego* oJuego;
		Bitmap^ fondo;
	public:
		FormularioJuego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//	
		StartPosition:CenterToScreen(); //CenterToScreen logra que nuestro formulario se encuentre centrado en la pantalla
			fondo = gcnew Bitmap("Imagenes/fondoFacil.png");
			oJuego = new Juego(1);
			oJuego->generarPersonaje("Imagenes/Jugador.png");			
			oJuego->agregarMosquitos(5);
			oJuego->agregarPacientesEnfermos();
			oJuego->agregarObstaculosFacil();
			timerJuego->Enabled = true;
			timerJuego->Interval = 50;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormularioJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timerJuego;
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timerJuego
			// 
			this->timerJuego->Tick += gcnew System::EventHandler(this, &FormularioJuego::timerJuego_Tick);
			// 
			// FormularioJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 600);
			this->Name = L"FormularioJuego";
			this->Text = L"FormularioJuego";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormularioJuego::FormularioJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormularioJuego::FormularioJuego_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		Rectangle area_usar = Rectangle(0, 0, fondo->Width, fondo->Height);
		Rectangle reduccion_usar = Rectangle(0, 0, fondo->Width, fondo->Height / 2);
		buffer->Graphics->DrawImage(fondo, reduccion_usar, area_usar, GraphicsUnit::Pixel);

		oJuego->moverPersonaje(buffer);
		oJuego->moverProyectiles(buffer);
		oJuego->moverAliados(buffer);
		oJuego->moverMosquitos(buffer);
		oJuego->dibujarObstaculos(buffer);
		oJuego->dibujarPacientesEnfermos(buffer);
		oJuego->dibujarCurado(buffer);
		oJuego->verificarColisionMosquitoPersonaje(1);
		oJuego->verificarColisionPacientesEnfermosJugador(buffer);
		oJuego->verificarColisionAliadoRojoPersonaje();
		oJuego->verificarColisionAliadoAzulPersonaje();
		oJuego->verificaColisionMosquitoObstaculo();
		oJuego->verificaColisionMosquitoProyectil();
		oJuego->MensajesFacil(buffer);
		buffer->Render(g);
		
		if (oJuego->getPacientesEnfermos() == 0 && oJuego->getMosquitosRestantes() == 0)
		{
			timerJuego->Enabled = false;
			GanastePantalla^ oFormGanar= gcnew GanastePantalla();
			oFormGanar->ShowDialog();
			delete oFormGanar;
			this->Close();
		}
		if (oJuego->getVidas() == 0) {
			timerJuego->Enabled = false;
			PerdistePantalla^ oFormPerder = gcnew PerdistePantalla();
			oFormPerder->ShowDialog();
			delete oFormPerder;
			this->Close();
		}
	}
	private: System::Void FormularioJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oJuego->atenderMovimientoPersonaje(true, e->KeyCode);
		switch (e->KeyCode)
		{
		case Keys::Escape:
			this->Close();
		}
	}
	private: System::Void FormularioJuego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oJuego->atenderMovimientoPersonaje(false, e->KeyCode);
	}
	};
}
