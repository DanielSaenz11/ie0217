/*
Archivo que contiene la definici�n del constructor de la clase MainFrame, as� como de las funciones declaradas
para manejar eventos de la forma din�mica y explicar la propagaci�n de eventos.
Se establecen relaciones (binds) entre los eventos de los controles y las funciones que se desean realizar.
Se hace un bind del bot�n, de un bot�n presionado dentro del panel y de un bot�n presionado dentro del frame (por separado)
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Bot�n dentro de panel, en la posici�n (300, 275) y tama�o 200x50
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));

	// Asociar (bindear) evento de cada control a la funci�n definida para modificar el status bar	
	// button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	// panel->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); // Si en el panel existe un bot�n presionado
	this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); // Si en todo el frame se presiona un bot�n

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();
}

// Definici�n de funci�n cuando se presiona el bot�n
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button Clicked"); // Mensaje mostrado que se presion�
}


