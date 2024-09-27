/*
Implementación del MainFrame
Define el constructor de la clase MainFrame
*/

#include <wx/wx.h>
#include "MainFrame.hpp"

// Definición del constructor de Mainframe: Parent->nullptr, ID->wxID_ANY, title->String recibido
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {}
