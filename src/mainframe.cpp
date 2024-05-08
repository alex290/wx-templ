#include "mainframe.h"

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, wxString::FromUTF8("Шаблон wxWdgets"))
{
    wxBitmapBundle btbl = wxBitmapBundle::FromSVG(icon_svg.c_str(), wxSize(64, 64));
    SetIcon(btbl.GetIcon(wxSize(64, 64)));
}

MainFrame::~MainFrame()
{
}

