#include "Zubov1.h"

	using namespace System;
	using namespace System::Windows::Forms;

	[STAThreadAttribute]

	int main(array<String^> ^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Yevgen::Zubov1 form;
	Application::Run(% form);
}
