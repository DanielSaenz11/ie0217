/*
Archivo que contiene la definici�n del constructor de la clase MainFrame, as� como de las funciones declaradas
para manejar eventos de la forma din�mica y explicar la propagaci�n de eventos.

Se colocan dos botones en el MainFrame, los cuales ambos reaccionan al bind a la funci�n OnButtonClicked(), pues est�n dentro de panel
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Bot�n 1 dentro de panel, en la posici�n (300, 275) y tama�o 200x50
	wxButton* button = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));

	// Bot�n 2 dentro de panel, en la posici�n (300, 350) y tama�o 200x50
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	// Asociar (bindear) evento de bot�n dentro del MainFrame a la funci�n definida para modificar el status bar	
	this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); // Funciona para los dos botones del MainFrame

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();
}

// Definici�n de funci�n cuando se presiona el bot�n
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked"); // Mensaje mostrado que se presion�
}


