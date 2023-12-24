#pragma once
#include "ClaseControladoraSprite.h"

namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Resumen de GanastePantalla
	/// </summary>
	public ref class GanastePantalla : public System::Windows::Forms::Form
	{
	private:
		SpriteControlador* Sprites;
		Graphics^ g;
		SoundPlayer^ ganar;
		BufferedGraphicsContext^ espacioBuffer;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnSalir;
		   BufferedGraphics^ buffer;
	public:
		GanastePantalla(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		StartPosition:CenterToScreen(); //CenterToScreen logra que nuestro formulario se encuentre centrado en la pantalla

			Sprites = new SpriteControlador();
			Sprites->generarSprite("Imagenes/GanarSprite.png");
			ganar = gcnew SoundPlayer("Sonidos/AudioGanar.wav");
			ganar->PlayLooping();
			timerSprite->Enabled = true;
			timerSprite->Interval = 100;
			g = this->CreateGraphics();
			espacioBuffer = BufferedGraphicsManager::Current;
			buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GanastePantalla()
		{
			if (components)
			{
				delete components;
			}
			delete buffer;
			delete espacioBuffer;
			delete g;
		}
	private: System::Windows::Forms::Timer^ timerSprite;
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GanastePantalla::typeid));
			this->timerSprite = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timerSprite
			// 
			this->timerSprite->Tick += gcnew System::EventHandler(this, &GanastePantalla::timerSprite_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Info;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 419);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(251, 130);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(348, 455);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(167, 65);
			this->btnSalir->TabIndex = 1;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &GanastePantalla::btnSalir_Click);
			// 
			// GanastePantalla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"GanastePantalla";
			this->Text = L"GanastePantalla";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerSprite_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::LightYellow);
		Sprites->moverSprite(buffer);
		buffer->Render(g);
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		ganar->Stop();
		this->Close();
	}
};
}
