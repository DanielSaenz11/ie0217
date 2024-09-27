/*
Archivo que contiene la definición del constructor de la clase MainFrame, así como de las funciones declaradas
para manejar eventos de la forma dinámica y explicar la propagación de eventos.

Se colocan dos botones en el MainFrame, los cuales ambos reaccionan al bind a la función OnAnyButtonClicked(), pues están dentro de panel
Se añadió un bind al botón 1 y botón 2 para mostrar un mensaje en el status bar, dependiendo de cuál fue presionado

Contiene un bind a una función cuando se cierra la ventana, se utiliza propagación de eventos para manejar el cerrado de la ventana
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Botón 1 dentro de panel, en la posición (300, 275) y tamaño 200x50
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));

	// Botón 2 dentro de panel, en la posición (300, 350) y tamaño 200x50
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	// Asociar (bindear) evento de botón dentro del MainFrame a la función definida para modificar el status bar
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnCloseWindow, this); // Se ejecuta al cerrar la ventana
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);  // Funciona para los dos botones del MainFrame
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this); // Bind para el botón 1 con su respectiva función
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this); // Bind para el botón 2 con su respectiva función

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();
}

// Definición de función cuando se cierra la ventana MainFrame
void MainFrame::OnClose(wxCloseEvent& evt) {
	wxLogMessage("Frame Close");
	evt.Skip(); // Propagación de evento para cerrar ventana
}

// Definición de función cuando se presiona cualquier botón
void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked"); // Mensaje mostrado como ventana flotante para cualquier botón
}

// Definición de función cuando se presiona el botón 1
void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 1 Clicked"); // En el Status Bar

	// Indica que continúe la propagación del evento y se ejecute OnAnyButtonClicked()
	evt.Skip(); // Si no se coloca, no se propaga el evento y no se muestra la ventana flotante
}

// Definición de función cuando se presiona el botón 2
void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 2 Clicked"); // En el Status Bar
	// No contiene evt.Skip() entonces no se propaga el evento para mostrar la ventana flotante, sólo se modifica el status bar
}

