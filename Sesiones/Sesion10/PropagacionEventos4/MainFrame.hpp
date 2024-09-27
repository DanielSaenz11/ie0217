/*
Archivo que contiene la declaraci�n de la clase MainFrame

Abarca el constructor de la clase y las funciones que se ejecuta al presionar un bot�n dentro de la ventana MainFrame y cerrarla
*/

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
	// Contructor de MainFrame: Recibe t�tulo de la ventana principal
	MainFrame(const wxString& title);

private:
	void OnClose(wxCloseEvent& evt);              // Evento de cerrar la ventana
	void OnAnyButtonClicked(wxCommandEvent& evt); // Evento cuando de hace clic en cualquier bot�n
	void OnButton1Clicked(wxCommandEvent& evt);   // Evento cuando de hace clic en el bot�n 1
	void OnButton2Clicked(wxCommandEvent& evt);   // Evento cuando de hace clic en el bot�n 2
};