/*
Header file para la clase App
Contiene el m�todo OnInit() que se ejecuta al iniciar la aplicacion
*/

#include <wx/wx.h>

// Declaraci�n de clase App: Hereda p�blicamente de wxApp
class App : public wxApp {
public:
	// M�todo por donde entra la aplicaci�n en la ejecuci�n
	bool OnInit();
};