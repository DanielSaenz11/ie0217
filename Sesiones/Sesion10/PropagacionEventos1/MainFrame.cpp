/*
Archivo que contiene la definición del constructor de la clase MainFrame, así como de las funciones declaradas
para manejar eventos de la forma dinámica y explicar la propagación de eventos.
Se establecen relaciones (binds) entre los eventos de los controles y las funciones que se desean realizar.
Se hace un bind del botón, de un botón presionado dentro del panel y de un botón presionado dentro del frame (por separado)
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Botón dentro de panel, en la posición (300, 275) y tamaño 200x50
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));

	// Asociar (bindear) evento de cada control a la función definida para modificar el status bar	
	// button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	// panel->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); // Si en el panel existe un botón presionado
	this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); // Si en todo el frame se presiona un botón

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();
}

// Definición de función cuando se presiona el botón
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button Clicked"); // Mensaje mostrado que se presionó
}


