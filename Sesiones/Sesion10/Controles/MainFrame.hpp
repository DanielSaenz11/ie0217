/*
Programa que crea la ventana principal del programa
Como su nombre lo indica, frame principal
*/

#include <wx/wx.h>

// Declaración de clase para el frame principal: Hereda públicamente de wxFrame
class MainFrame : public wxFrame {
public:
	// Constructor del MainFrame: Recibe un string con el título
	MainFrame(const wxString& title);
};