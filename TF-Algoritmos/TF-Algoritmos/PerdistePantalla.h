#pragma once
#include "Figura.h"

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Resumen de PerdistePantalla
	/// </summary>
	public ref class PerdistePantalla : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ perder;
	public:
		PerdistePantalla(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		StartPosition:CenterToScreen(); //CenterToScreen logra que nuestro formulario se encuentre centrado en la pantalla
			perder = gcnew SoundPlayer("Sonidos/PerderSonido.wav");
			perder->PlayLooping();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PerdistePantalla()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnSalir;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PerdistePantalla::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-120, -34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(815, 533);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 24));
			this->btnSalir->Location = System::Drawing::Point(191, 505);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(208, 40);
			this->btnSalir->TabIndex = 1;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &PerdistePantalla::btnSalir_Click);
			// 
			// PerdistePantalla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"PerdistePantalla";
			this->Text = L"PerdistePantalla";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		perder->Stop();
		this->Close();
	}
	};
}
