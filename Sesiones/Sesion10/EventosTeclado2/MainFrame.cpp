/*
Archivo que contiene la definici�n del constructor de la clase MainFrame, as� como de las funciones declaradas
para manejar eventos de teclado.
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Crear botones contenidos dentro de panel
	wxButton* btn1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 150), wxSize(200, 100));
	wxButton* btn2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 100));

	// Asociar (bindear) evento de teclado dentro del panel a la funci�n definida para modificar el status bar
	// Son detectados de acuerdo a d�nde est� enfocada la interfaz en ese momento
	// panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this); // No funciona cuando se hace bind a panel pues no se puede enfocar el panel
	btn1->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);  // Cuando se enfoca el bot�n ahora s� funciona

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();
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

