#include "mainframe.h"

class MyApp : public wxApp
{
public:
    virtual bool OnExceptionInMainLoop() override
    {
        try
        {
            throw;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() <<  + "C++ Exception Caught" << std::endl;
            // MessageBoxA(NULL, e.what(), "C++ Exception Caught", MB_OK);
        }
        return true; // continue on. Return false to abort program
    }
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

inline bool MyApp::OnInit()
{
    MainFrame *frame = new MainFrame();
    frame->Show(true);
    return true;
}
