/*
Archivo que contiene la definición del constructor de la clase MainFrame, así como de las funciones declaradas
para manejar eventos de forma estática.
Se declara un enum con los IDs de cada control dentro de la ventana y una tabla de eventos para asociar cada
evento con su respectiva función
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

// Declaración de los ID de cada elemento dentro del MainFrame
enum IDs {
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4
};

// Definición de tabla de eventos para MainFrame: Recibe la clase y la clase base
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked) // Evento al presionar el botón
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged) // Evento al mover el slider
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)       // Evento al cambiar el texto
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Botón dentro de panel, en la posición (300, 275) y tamaño 200x50
	wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));

	// Slider dentro de panel con valor 0 (límite inferior 0 y superior 100) en la posición (300, 200)
	wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));

	// TextCtrl dentro de panel en la posición (300, 375)
	wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));

	// Crear barra de estado abajo de la ventana
	CreateStatusBar();
}

// Definición de función cuando se presiona el botón
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button Clicked"); // Mensaje mostrado que se presionó
}

// Definición de función cuando se cambia el slider
void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Slider Value: %d", evt.GetInt()); // Mostrar valor del slider en el status bar
	wxLogStatus(str);
}

// Definición de función cuando se cambia el valor del texto
void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Text: %s", evt.GetString()); // Mostrar string ingresado en el status bar
	wxLogStatus(str);
}

