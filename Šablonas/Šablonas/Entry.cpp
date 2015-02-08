#include "MyProgram.h" //Pagrindinië forma

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Pagrindinis::PagrindineForma Form;
	Application::Run(%Form);
	return 0;
}