/*
Archivo que contiene la declaración de la clase MainFrame

Abarca el constructor de la clase y funciones que se ejecutan al ocurrir eventos dentro de la ventana en los
controles colocados
*/

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
	// Contructor de MainFrame: Recibe título de la ventana principal
	MainFrame(const wxString& title);

private:
	void OnButtonClicked(wxCommandEvent& evt); // Evento cuando de hace clic en el botón
	void OnSliderChanged(wxCommandEvent& evt); // Evento cuando se cambia el valor del slider
	void OnTextChanged(wxCommandEvent& evt);   // Evento cuando se cambia el texto
};