/*
Implementaci�n del MainFrame
Define el constructor de la clase MainFrame
A�ade a�ade controles con estilos al MainFrame:
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

// Definici�n del constructor de Mainframe: Parent->nullptr, ID->wxID_ANY, title->String recibido
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this); // Asignar panel al MainFrame

	// Bot�n contenido dentro de panel, en la posici�n (150, 50) y tama�o (100, 35). Alineado a la izquierda
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);

	// CheckBox contenido dentro de panel, en la posici�n (550, 55). Permite tercer estado para el checkbox
	wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 55), wxDefaultSize,
		wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	// StaticText (texto est�tico) contenido dentro de panel, en la posici�n (0, 150) y largo de 400
	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable", wxPoint(0, 150),
		wxSize(400, -1), wxALIGN_CENTRE_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY); // Color de fondo gris

	// TextCtrl (espacio para escribir texto) contenido dentro de panel, en la posici�n (500, 145) y tama�o 200 de largo y altura por defecto (-1)
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD); // Estilo contrase�a

	// Slider contenido dentro de panel, con valor de 25 (l�mite inferior de 0 y superior de 100), en la posici�n (100, 250)
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL); // Label con el valor

	// Gauge contenido de panel, con rango de 100, en la posici�n (590, 205), largo por defecto y altura de 125
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(590, 205), wxSize(-1, 125), wxGA_VERTICAL); // Posici�n vertical
	gauge->SetValue(50); // Establecer valor de gauge a 50

	// ArrayString (elementos de lista desplegable) con opciones "Item A", "Item B", "Item C"
	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	// Choice (lista desplegable) con opciones choices contenido dentro de panel, en la posici�n (150, 375), largo 100 y altura por defecto (-1)
	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
	choice->Select(0); // Seleccionar primera opci�n

	// SpinCtrl contenido dentro de panel, en la posici�n (550, 375), largo 100 y altura por defecto (-1). Al disminuir m�s que 0 se va a 100 y viceversa
	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);

	// ListBox contenido dentro de panel, en la posici�n (150, 475) y opciones choices. Permite seleccionar m�ltiples opciones
	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

	// RadioBox contenido dentro de panel, en la posici�n (555, 450), tama�o por defecto y opciones choices. Opciones verticalmente
	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(555, 450), wxDefaultSize, choices, 3, wxRA_SPECIFY_ROWS);
}
