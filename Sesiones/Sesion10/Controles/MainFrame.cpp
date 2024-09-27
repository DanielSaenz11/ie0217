/*
Implementación del MainFrame
Define el constructor de la clase MainFrame
Añade añade controles al MainFrame:
- Button
- Checkbox
- StaticText
- Text control
- Slider
- Gauge
- ArrayString
- Choice
- SpinCtrl
- ListBox
- RadioBox
*/

#include <wx/wx.h>
#include <wx/spinctrl.h> // Spinctrl
#include "MainFrame.hpp"

// Definición del constructor de Mainframe: Parent->nullptr, ID->wxID_ANY, title->String recibido
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel al MainFrame

	// Botón contenido dentro de panel, en la posición (150, 50) y tamaño (100, 35)
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));

	// CheckBox contenido dentro de panel, en la posición (550, 55)
	wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 55));

	// StaticText (texto estático) contenido dentro de panel, en la posición (120, 150)
	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable", wxPoint(120, 150));

	// TextCtrl (espacio para escribir texto) contenido dentro de panel, en la posición (100, 250) y tamaño 200 de largo y altura por defecto (-1)
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(200, -1));

	// Slider contenido dentro de panel, con valor de 25 (límite inferior de 0 y superior de 100), en la posición (100, 250)
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1));

	// Gauge contenido de panel, con rango de 100, en la posición (500, 255), largo de 200 y altura por defecto (-1)
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	gauge->SetValue(50); // Establecer valor de gauge a 50

	// ArrayString (elementos de lista desplegable) con opciones "Item A", "Item B", "Item C"
	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	// Choice (lista desplegable) con opciones choices contenido dentro de panel, en la posición (150, 375), largo 100 y altura por defecto (-1)
	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	choice->Select(0); // Seleccionar primera opción

	// SpinCtrl contenido dentro de panel, en la posición (550, 375), largo 100 y altura por defecto (-1)
	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));

	// ListBox contenido dentro de panel, en la posición (150, 475) y opciones choices
	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

	// RadioBox contenido dentro de panel, en la posición (485, 475), tamaño por defecto y opciones choices
	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);
}
