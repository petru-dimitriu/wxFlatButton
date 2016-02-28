#include "mainwindow.h"
#include "flatbuttonctl.h"

extern MessageWindow* MessageViewer;

MainWindow::MainWindow(wxWindow* parent,wxWindowID id) : wxFrame(NULL,wxID_ANY,"Main window",wxDefaultPosition)
{
    wxFlatButton* Button = new wxFlatButton(this,1234,"This is some small text.","This is some big text.");
    //Piano->SetWhiteKeyColour(wxColour(255,255,0));
    Connect(1234,EVT_FLATBUTTON_DOWN,(wxObjectEventFunction)&MainWindow::FlatButtonDown);
    Connect(1234,EVT_FLATBUTTON_UP,(wxObjectEventFunction)&MainWindow::FlatButtonUp);
    Connect(1234,EVT_FLATBUTTON_HOVER,(wxObjectEventFunction)&MainWindow::FlatButtonHover);
    SetClientSize(Button->GetMinClientSize());
}

MainWindow::~MainWindow()
{
    Destroy();
}

void MainWindow::FlatButtonDown(wxCommandEvent &event)
{
    *(MessageViewer->Box) << wxString("BUTTON DOWN\n");
}

void MainWindow::FlatButtonUp(wxCommandEvent &event)
{
    *(MessageViewer->Box) << wxString("BUTTON UP\n");
}

void MainWindow::FlatButtonHover(wxCommandEvent &event)
{
    *(MessageViewer->Box) << wxString("BUTTON HOVERED\n");
}


MessageWindow::MessageWindow() : wxFrame(NULL,wxID_ANY,"Messages",wxDefaultPosition,wxSize(200,200))
{
    Box = new wxTextCtrl(this,2000,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE|wxTE_WORDWRAP);
}

MessageWindow::~MessageWindow()
{
    Destroy();
}
