#include "MyProgram.h"

#include <fstream>
#include <iomanip>


#pragma region Settings Methods
void Pagrindinis::PagrindineForma::InitializeSettings()
{
	Settings::LoadFile(NustatymuFailas);

	//Duomenys
	if (Settings::HasKey(DuomenuKey)){
		this->textDuomenuFailas->Text = Settings::TryGetString(DuomenuKey);
	}
	else{
		Settings::SetValue(DuomenuKey, DuomenuFailas);
		this->textDuomenuFailas->Text = DuomenuFailas;
	}
	//Rezultatai
	if (Settings::HasKey(RezultatuKey)){
		this->textRezultatuFailas->Text = Settings::TryGetString(RezultatuKey);
	}
	else{
		Settings::SetValue(RezultatuKey, RezultatuFailas);
		this->textRezultatuFailas->Text = RezultatuFailas;
	}

}


void Pagrindinis::PagrindineForma::OnTextDuomenuFailasLeave(System::Object ^sender, System::EventArgs ^e)
{
	Settings::SetValue(DuomenuKey, this->textDuomenuFailas->Text);
	Settings::SaveCurrent();
}


void Pagrindinis::PagrindineForma::OnRezultatuFailasLeave(System::Object ^sender, System::EventArgs ^e)
{
	Settings::SetValue(RezultatuKey, this->textRezultatuFailas->Text);
	Settings::SaveCurrent();
}
#pragma endregion


#pragma region Edit Methods

void Pagrindinis::PagrindineForma::OnEditClick(System::Object ^sender, System::EventArgs ^e)
{
	txtEditor ed(StringToStd(this->textDuomenuFailas->Text), true);
	ed.ShowDialog();
}


void Pagrindinis::PagrindineForma::OnPreviewClick(System::Object ^sender, System::EventArgs ^e)
{
	txtEditor ed(StringToStd(this->textRezultatuFailas->Text), false);
	ed.ShowDialog();
}
#pragma endregion

/* Duomenø nuskaitymas ðiame regione
Pakeisti -> funkcijos Nuskaityti() argumentus pagal poreiká
			funkcijos Nuskaityti() turiná*/
#pragma region Input
void Pagrindinis::PagrindineForma::Nuskaityti(){
	ifstream f;
	string fileName = StringToStd(this->textDuomenuFailas->Text);
	try{
		f.open(fileName);
		//----------------------------------------------------------



		//----------------------------------------------------------
		f.close();
	}
	catch (ifstream::failure & ex){
		throw ex;
	}
}

void Pagrindinis::PagrindineForma::OnNuskaitytiClick(System::Object ^sender, System::EventArgs ^e)
{
	try{
		Nuskaityti();
	}
	catch (ifstream::failure & ex) {
		if (MessageShow::Show("Nepavyko atidaryti/nuskaityti/uþdaryti duomenø failo. " + stdToString(string(ex.what())), "Klaida!", MessageBoxButtons::AbortRetryIgnore, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::Retry){
			OnNuskaitytiClick(sender, e);
		}
	}
}
#pragma endregion


/// <summary>
/// Dëti Metodus èia
/// </summary>