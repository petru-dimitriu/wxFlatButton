#pragma once

#include <wx/thread.h>
#include <wx/aui/aui.h>

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/textctrl.h>

class MainWindow: public wxFrame
{
    public:

        MainWindow(wxWindow* parent,wxWindowID id = -1);
        virtual ~MainWindow();

    private:
        void FlatButtonDown(wxCommandEvent &event);
        void FlatButtonUp(wxCommandEvent &event);
        void FlatButtonHover(wxCommandEvent &event);
        void FlatButtonLeft(wxCommandEvent &event);

};

class MessageWindow : public wxFrame
{
public:
    MessageWindow();
    ~MessageWindow();
    wxTextCtrl * Box;

};
