/*
Archivo que contiene la definición del método App::OnInit()
Que se ejecuta al inicializar la aplicación
*/

#include "MyApp.hpp"
#include "MainFrame.hpp"

wxIMPLEMENT_APP(App); // Busca el método OnInit() para iniciar la aplicación

// Definición de método OnInit()
bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("C++ GUI"); // Crea un MainFrame (ventana)
	// mainFrame->SetClientSize(800, 600); // Establecer tamaño del MainFrame
	// mainFrame->Center(); // Centrar
	mainFrame->Show(); // Mostrar el MainFrame
	return true; // Indicar estado de inicialización
}