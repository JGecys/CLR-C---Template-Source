#pragma once

#include <fstream>
#include "GUIEssentials.h"

namespace Pagrindinis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace std;

	/// <summary>
	/// Summary for txtEditor
	/// </summary>
	public ref class txtEditor : public System::Windows::Forms::Form
	{
	public:
		txtEditor(string file, bool canEdit){
			InitializeComponent();
			this->saveToolStripMenuItem->Enabled = canEdit;
			richTextBox->ReadOnly = !canEdit;
			fileName = new string(file);
			this->Text = GUIEssentials::stdToString(file);
			Load();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~txtEditor()
		{
			if (components)
			{
				delete components;
			}
			if (fileName){
				delete fileName;
			}
		}

	private:
		bool _isChanged = false;
		string* fileName;


	protected:


	private: System::Windows::Forms::RichTextBox^  richTextBox;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox
			// 
			this->richTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->richTextBox->Location = System::Drawing::Point(0, 24);
			this->richTextBox->Name = L"richTextBox";
			this->richTextBox->Size = System::Drawing::Size(721, 349);
			this->richTextBox->TabIndex = 4;
			this->richTextBox->Text = L"";
			this->richTextBox->TextChanged += gcnew System::EventHandler(this, &txtEditor::OnTextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(721, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &txtEditor::OnSaveClick);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &txtEditor::OnExitClick);
			// 
			// txtEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 373);
			this->Controls->Add(this->richTextBox);
			this->Controls->Add(this->menuStrip1);
			this->MinimumSize = System::Drawing::Size(737, 412);
			this->Name = L"txtEditor";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Editor";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &Pagrindinis::txtEditor::OnClosing);

		}
#pragma endregion
		void OnSaveClick(System::Object ^sender, System::EventArgs ^e);
		void OnTextChanged(System::Object ^sender, System::EventArgs ^e);
		void OnExitClick(System::Object ^sender, System::EventArgs ^e);
		void OnClosing(System::Object ^sender, System::ComponentModel::CancelEventArgs ^e);
		void Save();
		void Load();
};
}

