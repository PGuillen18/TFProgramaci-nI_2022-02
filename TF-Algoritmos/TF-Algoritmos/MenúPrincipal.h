#pragma once
#include "FormularioJuego.h"
#include "FormularioJuegoDificil.h"
#include "InstruccionesCreditos.h"
namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenúPrincipal
	/// </summary>
	public ref class MenúPrincipal : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ sonidoInicio;
	public:
		MenúPrincipal(void)
		{
			InitializeComponent();
		StartPosition:CenterToScreen(); //CenterToScreen logra que nuestro formulario se encuentre centrado en la pantalla
			//
			//TODO: agregar código de constructor aquí
			//
			sonidoInicio = gcnew SoundPlayer("Sonidos/AudioInicio.wav");
			sonidoInicio->PlayLooping();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenúPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_Facil;
	protected:
	private: System::Windows::Forms::Button^ btn_Dificil;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ btn_InstruccionesCreditos;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenúPrincipal::typeid));
			this->btn_Facil = (gcnew System::Windows::Forms::Button());
			this->btn_Dificil = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_InstruccionesCreditos = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_Facil
			// 
			this->btn_Facil->Font = (gcnew System::Drawing::Font(L"MV Boli", 20));
			this->btn_Facil->Location = System::Drawing::Point(161, 326);
			this->btn_Facil->Name = L"btn_Facil";
			this->btn_Facil->Size = System::Drawing::Size(326, 43);
			this->btn_Facil->TabIndex = 0;
			this->btn_Facil->Text = L"Nivel Fácil";
			this->btn_Facil->UseVisualStyleBackColor = true;
			this->btn_Facil->Click += gcnew System::EventHandler(this, &MenúPrincipal::btn_Facil_Click);
			// 
			// btn_Dificil
			// 
			this->btn_Dificil->Font = (gcnew System::Drawing::Font(L"MV Boli", 20));
			this->btn_Dificil->Location = System::Drawing::Point(924, 326);
			this->btn_Dificil->Name = L"btn_Dificil";
			this->btn_Dificil->Size = System::Drawing::Size(326, 43);
			this->btn_Dificil->TabIndex = 2;
			this->btn_Dificil->Text = L"Nivel Difícil ";
			this->btn_Dificil->UseVisualStyleBackColor = true;
			this->btn_Dificil->Click += gcnew System::EventHandler(this, &MenúPrincipal::btn_Dificil_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MV Boli", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(401, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(631, 63);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Last Hope: The Videogame";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(134, 99);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(365, 221);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(905, 99);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(365, 221);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// btn_InstruccionesCreditos
			// 
			this->btn_InstruccionesCreditos->Font = (gcnew System::Drawing::Font(L"MV Boli", 20));
			this->btn_InstruccionesCreditos->Location = System::Drawing::Point(535, 188);
			this->btn_InstruccionesCreditos->Name = L"btn_InstruccionesCreditos";
			this->btn_InstruccionesCreditos->Size = System::Drawing::Size(326, 43);
			this->btn_InstruccionesCreditos->TabIndex = 6;
			this->btn_InstruccionesCreditos->Text = L"Instrucciones y Créditos";
			this->btn_InstruccionesCreditos->UseVisualStyleBackColor = true;
			this->btn_InstruccionesCreditos->Click += gcnew System::EventHandler(this, &MenúPrincipal::button1_Click);
			// 
			// MenúPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1377, 401);
			this->Controls->Add(this->btn_InstruccionesCreditos);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_Dificil);
			this->Controls->Add(this->btn_Facil);
			this->Name = L"MenúPrincipal";
			this->Text = L"MenúPrincipal";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_Facil_Click(System::Object^ sender, System::EventArgs^ e) {
		sonidoInicio->Stop();
		FormularioJuego^ oFormJuego = gcnew FormularioJuego();
		oFormJuego->ShowDialog();
		delete oFormJuego;
	}
	private: System::Void btn_Dificil_Click(System::Object^ sender, System::EventArgs^ e) {
		sonidoInicio->Stop();
		FormularioJuegoDificil^ oFormJuego = gcnew FormularioJuegoDificil();
		oFormJuego->ShowDialog();
		delete oFormJuego;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		InstruccionesCreditos^ oFormJuego = gcnew InstruccionesCreditos();
		oFormJuego->ShowDialog();
		delete oFormJuego;
	}
};
}
