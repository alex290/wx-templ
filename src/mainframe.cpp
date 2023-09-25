#include "mainframe.h"

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, wxString::FromUTF8("Шаблон wxWdgets"))
{
    SetIcon(wxIcon(logo_xpm));

}

MainFrame::~MainFrame()
{
}

