#include "Login.h"
using namespace View; //agregar el namespace del proyecto para poder usar el formulario
using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String^>^ args) //aqui creer el main para ejecutar el formulario
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Login form;
	Application::Run(%form);
	return 0;
}
