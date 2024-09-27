/*
Archivo que contiene la definici�n del constructor de la clase MainFrame, as� como de las funciones declaradas
para manejar eventos de mouse.
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Crear bot�n dentro de panel, en la posici�n (300, 250) y tama�o 200x100
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100));

	// Crear barra de estado abajo de la ventana
	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true); // Contrarrestar el parpadeo del mouse

	// Asociar (bindear) evento de mouse dentro del MainFrame a la funci�n definida para modificar el status bar
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);  // Se muestra la posici�n continuamente (s�lo con movimiento del cursor)
	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this); // Se ejecuta al mover el cursor dentro del bot�n
	// Se evidencia la posici�n relativa dentro del panel/boton pues se muestra las coordenadas RELATIVAS a estos dependiendo de d�nde est� el cursor
}

// Definici�n de funci�n cuando hay eventos de mouse
void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
	wxPoint mousePos = evt.GetPosition();
	wxString message = wxString::Format("Mouse Event Detected! (x=%d, y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}

