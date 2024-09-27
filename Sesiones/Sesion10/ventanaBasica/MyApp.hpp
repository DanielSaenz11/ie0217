/*
Header file para la clase App
Contiene el m�todo OnInit() que se ejecuta al inciar la aplicaci�n
*/

#include <wx/wx.h>

// Declaraci�n de clase App: Hereda p�blicamente de wxApp
class App : public wxApp {
public:
	// Método por donde entra la aplicaci�n en la ejecuci�n
	bool OnInit();
};