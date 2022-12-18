#include "mainframe.h"

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, wxT("Шаблон wxWdgets"))
{
    SetIcon(wxIcon(logo_xpm));

}

MainFrame::~MainFrame()
{
}

