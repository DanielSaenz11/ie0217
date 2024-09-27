/*
Programa para probar WxWidgets

Crea una ventana y muestra el texto "Well Done! Everthing seems to be working fine"
para demostrar la correcta compilación de la biblioteca
*/

#include <wx/wx.h>

class App : public wxApp {
public:
	bool OnInit() {
		wxFrame* window = new wxFrame(NULL, wxID_ANY, "GUI Test", wxDefaultPosition, wxSize(600, 400)); // Ventana
		wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

		// Texto estático a mostrar en la ventana: Parent es el window donde se encuentra
		wxStaticText* text = new wxStaticText(window, wxID_ANY, "Well Done!\nEverything seems to be working",
			wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

		// Tamaño, tipo de letra y demás detalles
		text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		
		sizer->Add(text, 1, wxALIGN_CENTER);
		window->SetSizer(sizer);
		window->Show(); // Mostrar la ventana
		return true;
	}
};

wxIMPLEMENT_APP(App);