/*
Archivo que contiene la definici�n del constructor de la clase MainFrame, as� como de las funciones declaradas
para manejar eventos de la forma din�mica y explicar la propagaci�n de eventos.

Se colocan dos botones en el MainFrame, los cuales ambos reaccionan al bind a la funci�n OnAnyButtonClicked(), pues est�n dentro de panel
Se a�adi� un bind al bot�n 1 y bot�n 2 para mostrar un mensaje en el status bar, dependiendo de cu�l fue presionado

Contiene un bind a una funci�n cuando se cierra la ventana, se utiliza propagaci�n de eventos para manejar el cerrado de la ventana
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Bot�n 1 dentro de panel, en la posici�n (300, 275) y tama�o 200x50
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));

	// Bot�n 2 dentro de panel, en la posici�n (300, 350) y tama�o 200x50
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	// Asociar (bindear) evento de bot�n dentro del MainFrame a la funci�n definida para modificar el status bar
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnCloseWindow, this); // Se ejecuta al cerrar la ventana
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);  // Funciona para los dos botones del MainFrame
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this); // Bind para el bot�n 1 con su respectiva funci�n
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this); // Bind para el bot�n 2 con su respectiva funci�n

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();
}

// Definici�n de funci�n cuando se cierra la ventana MainFrame
void MainFrame::OnClose(wxCloseEvent& evt) {
	wxLogMessage("Frame Close");
	evt.Skip(); // Propagaci�n de evento para cerrar ventana
}

// Definici�n de funci�n cuando se presiona cualquier bot�n
void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked"); // Mensaje mostrado como ventana flotante para cualquier bot�n
}

// Definici�n de funci�n cuando se presiona el bot�n 1
void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 1 Clicked"); // En el Status Bar

	// Indica que contin�e la propagaci�n del evento y se ejecute OnAnyButtonClicked()
	evt.Skip(); // Si no se coloca, no se propaga el evento y no se muestra la ventana flotante
}

// Definici�n de funci�n cuando se presiona el bot�n 2
void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 2 Clicked"); // En el Status Bar
	// No contiene evt.Skip() entonces no se propaga el evento para mostrar la ventana flotante, s�lo se modifica el status bar
}

