/*
Archivo que contiene la definici�n del constructor de la clase MainFrame, as� como de las funciones declaradas
para manejar eventos de teclado.
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();

	// Asociar (bindear) evento de teclado dentro del panel a la funci�n definida para modificar el status bar
	panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this); // Se muestran las teclas presionadas
}

// Definici�n de funci�n cuando hay eventos de teckado
void MainFrame::OnKeyEvent(wxKeyEvent& evt) {
	wxChar keyChar = evt.GetUnicodeKey(); // Obtener valor Unicode de la tecla presionada
	
	// Si no tiene valor Unicode, se muestra el c�digo de la tecla
	if (keyChar == WXK_NONE) {
		int keyCode = evt.GetKeyCode();
		wxLogStatus("Key Event %d", keyCode);
	}
	// Si s� tiene valor Unicode, se muestra el caracter presionado
	else {
		wxLogStatus("Key Event %c", keyChar);
	}
}

