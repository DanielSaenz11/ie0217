/*
Archivo que contiene la declaraci�n de la clase MainFrame

Abarca el constructor de la clase y la funci�n que se ejecuta al haber eventos de teclado
*/

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
	// Contructor de MainFrame: Recibe t�tulo de la ventana principal
	MainFrame(const wxString& title);

private:
	void OnKeyEvent(wxKeyEvent& evt); // Eventos de teclado
};