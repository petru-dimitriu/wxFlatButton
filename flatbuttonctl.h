/***********************************************************
    wxFlatButton
    implements a flat modern-looking button for wxWidgets
    Petru Dimitriu, 2014
    This is in public domain. Attribution not required.
************************************************************/

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <wx/log.h>

#pragma once

#define EVT_FLATBUTTON_UP      1
#define EVT_FLATBUTTON_HOVER   2
#define EVT_FLATBUTTON_DOWN    3

class wxFlatButton : public wxPanel
{

private:
    wxColour NormalColour = wxColour(200,230,255),
             HoveredColour= wxColour(175,220,250),
             PressedColour= wxColour(90,170,235),
             BorderColour = wxColour(0,128,255);

    wxFont font = *wxNORMAL_FONT;
    int BigSize, SmallSize;
    wxString BigText, SmallText;
    bool Hovered = 0, Pressed = 0;

    void paintEvent (wxPaintEvent&);
    void mouseMoved (wxMouseEvent&);
    void mouseDown (wxMouseEvent&);
    void mouseReleased (wxMouseEvent&);
    void mouseLeftWindow (wxMouseEvent&);
    void eraseEvent (wxEraseEvent&);
    void sizeEvent (wxSizeEvent&);
    wxSize DoGetBestClientSize();

public:
    wxFlatButton(wxWindow* parent, const long id, wxString SmallText,
                 wxString BigText = "", wxFont f = *wxNORMAL_FONT,
                 int smallSize = 10, int bigSize = 15);

    void SetSmallText(wxString);
    void SetBigText(wxString);
    void SetBorderColour(wxColour);
    void SetNormalColour(wxColour);
    void SetHoveredColour(wxColour);
    void SetPressedColour(wxColour);
    wxColour GetBorderColour();
    wxColour GetNormalColour();
    wxColour GetHoveredColour();
    wxColour GetPressedColour();
    wxString GetSmallText();
    wxString GetBigText();

public:
    int x, y, height, width;


    DECLARE_EVENT_TABLE()
};
