/*
Archivo que contiene la definición del constructor de la clase MainFrame, así como de las funciones declaradas
para manejar eventos de la forma dinámica y explicar la propagación de eventos.

Se colocan dos botones en el MainFrame, los cuales ambos reaccionan al bind a la función OnButtonClicked(), pues están dentro de panel
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Botón 1 dentro de panel, en la posición (300, 275) y tamaño 200x50
	wxButton* button = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));

	// Botón 2 dentro de panel, en la posición (300, 350) y tamaño 200x50
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	// Asociar (bindear) evento de botón dentro del MainFrame a la función definida para modificar el status bar	
	this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); // Funciona para los dos botones del MainFrame

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();
}

// Definición de función cuando se presiona el botón
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked"); // Mensaje mostrado que se presionó
}


