#include "txtEditor.h"


void Pagrindinis::txtEditor::Save(){
	ofstream fo(*fileName);
	fo << GUIEssentials::StringToStd(richTextBox->Text) << endl;
	fo.close();
}

void Pagrindinis::txtEditor::OnSaveClick(System::Object ^sender, System::EventArgs ^e)
{
	Save();
	_isChanged = false;
}


void Pagrindinis::txtEditor::OnTextChanged(System::Object ^sender, System::EventArgs ^e)
{
	_isChanged = true;
}


void Pagrindinis::txtEditor::OnExitClick(System::Object ^sender, System::EventArgs ^e)
{
	this->Close();
}

void Pagrindinis::txtEditor::Load(){
	ifstream fi(*fileName);
	string line;
	while (!fi.eof()){
		getline(fi, line);
		richTextBox->Text += GUIEssentials::stdToString(line + "\n");
	}
	fi.close();
}

void Pagrindinis::txtEditor::OnClosing(System::Object ^sender, System::ComponentModel::CancelEventArgs ^e)
{
	if (_isChanged){
		if (GUIEssentials::MessageShow::Show("Failas buvo pakeistas. Iðsaugoti?", "Iðsaugoti?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
			Save();
		}
	}
}