/*
Programa que crea la ventana principal del programa
Como su nombre lo indica, frame principal
*/

#include <wx/wx.h>

// Declaraci�n de clase para el frame principal: Hereda p�blicamente de wxFrame
class MainFrame : public wxFrame {
public:
	// Constructor del MainFrame: Recibe un string con el t�tulo
	MainFrame(const wxString& title);
};