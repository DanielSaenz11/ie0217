/*
Header file para la clase App
Contiene el método OnInit() que se ejecuta al
*/

#include <wx/wx.h>

// Declaración de clase App: Hereda públicamente de wxApp
class App : public wxApp {
public:
	// Método por donde entra la aplicación en la ejecución
	bool OnInit();
};