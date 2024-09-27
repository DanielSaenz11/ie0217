/*
Archivo que contiene la definición del constructor de la clase MainFrame, así como de las funciones declaradas
para manejar eventos de mouse.
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Crear barra de estado abajo de la ventana
	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true); // Contrarrestar el parpadeo del mouse

	// Asociar (bindear) evento de mouse dentro del MainFrame a la función definida para modificar el status bar
	// panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this); // Únicamente se muestra al ejecutar un evento de mouse
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this); // Se muestra la posición continuamente (sólo con movimiento del cursor)
}

// Definición de función cuando hay eventos de mouse
void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
	wxPoint mousePos = evt.GetPosition();
	wxString message = wxString::Format("Mouse Event Detected! (x=%d, y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}

