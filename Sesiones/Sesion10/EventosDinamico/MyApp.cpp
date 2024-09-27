/*
Archivo que contiene la definici�n del m�todo App::OnInit()
Que se ejecuta al inicializar la aplicaci�n
*/

#include "MyApp.hpp"
#include "MainFrame.hpp"

wxIMPLEMENT_APP(App); // Busca el m�todo OnInit() para iniciar la aplicaci�n

// Definici�n de m�todo OnInit()
bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("C++ GUI"); // Crea un MainFrame (ventana)
	// mainFrame->SetClientSize(800, 600); // Establecer tama�o del MainFrame
	// mainFrame->Center(); // Centrar
	mainFrame->Show(); // Mostrar el MainFrame
	return true; // Indicar estado de inicializaci�n
}