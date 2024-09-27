/*
Archivo que contiene la definición del constructor de la clase MainFrame, así como de las funciones declaradas
para manejar eventos de la forma dinámica.
Se establecen relaciones (binds) entre los eventos de los controles y las funciones que se desean realizar.
*/

#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel a MainFrame

	// Botón dentro de panel, en la posición (300, 275) y tamaño 200x50
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));

	// Slider dentro de panel con valor 0 (límite inferior 0 y superior 100) en la posición (300, 200)
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));

	// TextCtrl dentro de panel en la posición (300, 375)
	wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

	// Asociar (bindear) evento de cada control a la función definida para modificar el status bar
	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

	// Desasociar (unbindear) función al evento del botón
	button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

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

