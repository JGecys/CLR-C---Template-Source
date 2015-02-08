#pragma once

#include "GUIEssentials.h"
#include "txtEditor.h"

namespace Pagrindinis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace GUIEssentials;
	using namespace std;

	/// <summary>
	/// Dëti Konstantas èia
	/// </summary>


	/// <summary>
	/// Dëti Prototipus èia
	/// </summary>



	/// <summary>
	/// Summary for PagrindineForma
	/// </summary>
	public ref class PagrindineForma : public System::Windows::Forms::Form
	{
	public:
		PagrindineForma(void)
		{
			InitializeComponent();
			InitializeSettings();
		}

	protected:
		~PagrindineForma()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


		static String^ NustatymuFailas = "Nustatymai.txt";
		static String^ DuomenuFailas = "Duomenys.txt";
		static String^ RezultatuFailas = "Rezultatai.txt";

		static String^ DuomenuKey = "Duomenys";
		static String^ RezultatuKey = "Rezultatai";



	private: System::Windows::Forms::Button^  buttonSpausdinti;
	private: System::Windows::Forms::TextBox^  textRezultatuFailas;
	private: System::Windows::Forms::GroupBox^  groupDuomenys;
	private: System::Windows::Forms::TextBox^  textDuomenuFailas;
	private: System::Windows::Forms::Button^  buttonNuskaityti;
	private: System::Windows::Forms::GroupBox^  groupSkaiciavimai;
	private: System::Windows::Forms::GroupBox^  groupRezultatai;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Button^  buttonPreview;


	private: System::ComponentModel::IContainer^  components;

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->buttonSpausdinti = (gcnew System::Windows::Forms::Button());
			this->textRezultatuFailas = (gcnew System::Windows::Forms::TextBox());
			this->groupDuomenys = (gcnew System::Windows::Forms::GroupBox());
			this->textDuomenuFailas = (gcnew System::Windows::Forms::TextBox());
			this->buttonNuskaityti = (gcnew System::Windows::Forms::Button());
			this->groupSkaiciavimai = (gcnew System::Windows::Forms::GroupBox());
			this->groupRezultatai = (gcnew System::Windows::Forms::GroupBox());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonPreview = (gcnew System::Windows::Forms::Button());
			this->groupDuomenys->SuspendLayout();
			this->groupRezultatai->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonSpausdinti
			// 
			this->buttonSpausdinti->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonSpausdinti->Location = System::Drawing::Point(8, 45);
			this->buttonSpausdinti->Name = L"buttonSpausdinti";
			this->buttonSpausdinti->Size = System::Drawing::Size(142, 23);
			this->buttonSpausdinti->TabIndex = 3;
			this->buttonSpausdinti->Text = L"Spausdinti";
			this->buttonSpausdinti->UseVisualStyleBackColor = true;
			// 
			// textRezultatuFailas
			// 
			this->textRezultatuFailas->Location = System::Drawing::Point(8, 19);
			this->textRezultatuFailas->Name = L"textRezultatuFailas";
			this->textRezultatuFailas->Size = System::Drawing::Size(249, 20);
			this->textRezultatuFailas->TabIndex = 4;
			this->textRezultatuFailas->Leave += gcnew System::EventHandler(this, &PagrindineForma::OnRezultatuFailasLeave);
			// 
			// groupDuomenys
			// 
			this->groupDuomenys->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupDuomenys->Controls->Add(this->buttonEdit);
			this->groupDuomenys->Controls->Add(this->textDuomenuFailas);
			this->groupDuomenys->Controls->Add(this->buttonNuskaityti);
			this->groupDuomenys->Location = System::Drawing::Point(12, 12);
			this->groupDuomenys->Name = L"groupDuomenys";
			this->groupDuomenys->Size = System::Drawing::Size(263, 73);
			this->groupDuomenys->TabIndex = 3;
			this->groupDuomenys->TabStop = false;
			this->groupDuomenys->Text = L"Duomenys";
			// 
			// textDuomenuFailas
			// 
			this->textDuomenuFailas->Location = System::Drawing::Point(9, 19);
			this->textDuomenuFailas->Name = L"textDuomenuFailas";
			this->textDuomenuFailas->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textDuomenuFailas->Size = System::Drawing::Size(248, 20);
			this->textDuomenuFailas->TabIndex = 1;
			this->textDuomenuFailas->Leave += gcnew System::EventHandler(this, &PagrindineForma::OnTextDuomenuFailasLeave);
			// 
			// buttonNuskaityti
			// 
			this->buttonNuskaityti->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonNuskaityti->Location = System::Drawing::Point(9, 44);
			this->buttonNuskaityti->Name = L"buttonNuskaityti";
			this->buttonNuskaityti->Size = System::Drawing::Size(141, 23);
			this->buttonNuskaityti->TabIndex = 0;
			this->buttonNuskaityti->Text = L"Nuskaityti";
			this->buttonNuskaityti->UseVisualStyleBackColor = true;
			this->buttonNuskaityti->Click += gcnew System::EventHandler(this, &PagrindineForma::OnNuskaitytiClick);
			// 
			// groupSkaiciavimai
			// 
			this->groupSkaiciavimai->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupSkaiciavimai->Location = System::Drawing::Point(12, 91);
			this->groupSkaiciavimai->Name = L"groupSkaiciavimai";
			this->groupSkaiciavimai->Size = System::Drawing::Size(263, 123);
			this->groupSkaiciavimai->TabIndex = 5;
			this->groupSkaiciavimai->TabStop = false;
			this->groupSkaiciavimai->Text = L"Skaièiavimai";
			// 
			// groupRezultatai
			// 
			this->groupRezultatai->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupRezultatai->Controls->Add(this->buttonPreview);
			this->groupRezultatai->Controls->Add(this->textRezultatuFailas);
			this->groupRezultatai->Controls->Add(this->buttonSpausdinti);
			this->groupRezultatai->Location = System::Drawing::Point(12, 220);
			this->groupRezultatai->Name = L"groupRezultatai";
			this->groupRezultatai->Size = System::Drawing::Size(263, 75);
			this->groupRezultatai->TabIndex = 6;
			this->groupRezultatai->TabStop = false;
			this->groupRezultatai->Text = L"Rezultatai";
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonEdit->Location = System::Drawing::Point(156, 44);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(101, 23);
			this->buttonEdit->TabIndex = 2;
			this->buttonEdit->Text = L"Keisti Duomenis";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &Pagrindinis::PagrindineForma::OnEditClick);
			// 
			// buttonPreview
			// 
			this->buttonPreview->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonPreview->Location = System::Drawing::Point(156, 45);
			this->buttonPreview->Name = L"buttonPreview";
			this->buttonPreview->Size = System::Drawing::Size(101, 23);
			this->buttonPreview->TabIndex = 3;
			this->buttonPreview->Text = L"Perþiûrëti";
			this->buttonPreview->UseVisualStyleBackColor = true;
			this->buttonPreview->Click += gcnew System::EventHandler(this, &Pagrindinis::PagrindineForma::OnPreviewClick);
			// 
			// PagrindineForma
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 307);
			this->Controls->Add(this->groupRezultatai);
			this->Controls->Add(this->groupSkaiciavimai);
			this->Controls->Add(this->groupDuomenys);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"PagrindineForma";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"PagrindineForma";
			this->groupDuomenys->ResumeLayout(false);
			this->groupDuomenys->PerformLayout();
			this->groupRezultatai->ResumeLayout(false);
			this->groupRezultatai->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		void OnTextDuomenuFailasLeave(System::Object ^sender, System::EventArgs ^e);
		void OnRezultatuFailasLeave(System::Object ^sender, System::EventArgs ^e);
		void OnNuskaitytiClick(System::Object ^sender, System::EventArgs ^e);
		void InitializeSettings();

		void Nuskaityti();
		void OnEditClick(System::Object ^sender, System::EventArgs ^e);
		void OnPreviewClick(System::Object ^sender, System::EventArgs ^e);
};
}




