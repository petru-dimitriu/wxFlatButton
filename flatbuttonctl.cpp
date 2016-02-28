/***********************************************************
    wxFlatButton
    implements a flat modern-looking button for wxWidgets
    Petru Dimitriu, 2014
    This is in public domain. Attribution not required.
************************************************************/

#include "flatbuttonctl.h"

wxFlatButton :: wxFlatButton(wxWindow * parent, const long id, wxString st, wxString bt, wxFont f, int ss, int bs) : wxPanel(parent, id)
{
    SmallText = st;
    font = f;
    BigText = bt;
    SmallSize=ss;
    BigSize=bs;
    CalculateSize();
}

void wxFlatButton::CalculateSize()
{
    wxMemoryDC dc;
    x = 5, y = 5, height = 5, width = GetSize().GetWidth();
    int smallTextWidth, bigTextWidth;

    wxFont f = font;

    if (BigText!="")
    {
        f.SetPointSize(BigSize);
        dc.SetFont(f);
        height += dc.GetCharHeight() + 5;
    }

    f.SetPointSize(SmallSize);
    dc.SetFont(f);

    smallTextWidth = dc.GetTextExtent(SmallText).GetWidth()+10;

    f.SetPointSize(BigSize);
    dc.SetFont(f);
    bigTextWidth = dc.GetTextExtent(BigText).GetWidth()+10;

    height += dc.GetCharHeight();

    width = std::max(std::max(smallTextWidth,bigTextWidth),width);
    SetMinClientSize(wxSize(width,height));

}

void wxFlatButton:: paintEvent (wxPaintEvent &evt)
{
    wxBufferedPaintDC dc(this);
    wxFont f = font;

    CalculateSize();

    dc.SetBrush(wxBrush(NormalColour));
    dc.SetPen(wxPen(BorderColour));

    if (Hovered)
        dc.SetBrush(wxBrush(HoveredColour));

    if (Pressed)
        dc.SetBrush(wxBrush(PressedColour));

    dc.DrawRectangle(0,0,width,height);

    f.SetPointSize(BigSize);
    if (BigText!="")
    {
        dc.SetFont(f);
        dc.DrawText(BigText,x,y);
        y += dc.GetCharHeight() + 5;
    }

    f.SetPointSize(SmallSize);
    dc.SetFont(f);
    dc.DrawText(SmallText,5,y);

    SetMinClientSize(wxSize(width,height));
}

void wxFlatButton:: SetSmallText(wxString s)
{
    SmallText = s;
    Refresh();
}

void wxFlatButton:: SetBigText(wxString s)
{
    BigText = s;
    Refresh();
}

void wxFlatButton::SetBorderColour(wxColour c)
{
    BorderColour = c;
    Refresh();
}

void wxFlatButton::SetNormalColour(wxColour c)
{
    NormalColour = c;
    Refresh();
}

void wxFlatButton::SetHoveredColour(wxColour c)
{
    HoveredColour = c;
    Refresh();
}

void wxFlatButton::SetPressedColour(wxColour c)
{
    PressedColour = c;
    Refresh();
}

wxString wxFlatButton::GetSmallText()
{
    return SmallText;
}

wxString wxFlatButton::GetBigText()
{
    return BigText;
}

wxColour wxFlatButton::GetBorderColour()
{
    return BorderColour;
}

wxColour wxFlatButton::GetNormalColour()
{
    return NormalColour;
}

wxColour wxFlatButton::GetHoveredColour()
{
    return HoveredColour;
}

wxColour wxFlatButton::GetPressedColour()
{
    return PressedColour;
}

void wxFlatButton:: mouseMoved(wxMouseEvent &evt)
{
    if (Hovered == 0)
    {
        Hovered = 1;
        // Sends the event that the user has pressed the button
        wxCommandEvent e(EVT_FLATBUTTON_HOVER, GetId() );
        e.SetEventObject( this );
        GetEventHandler()->ProcessEvent(e);
    }
    Refresh();
}

void wxFlatButton:: mouseDown(wxMouseEvent &evt)
{
    if (!Pressed)
    {
        Pressed = 1;
        // Sends the event that the user has pressed the button
        wxCommandEvent e(EVT_FLATBUTTON_DOWN, GetId() );
        e.SetEventObject( this );
        GetEventHandler()->ProcessEvent(e);
    }
    Refresh();
}

void wxFlatButton:: mouseReleased(wxMouseEvent &evt)
{
    if (Pressed)
    {
        Pressed = 0;
        // Sends the event that the user has pressed the button
        wxCommandEvent e(EVT_FLATBUTTON_UP, GetId() );
        e.SetEventObject( this );
        GetEventHandler()->ProcessEvent(e);
    }
    Refresh();
}

void wxFlatButton:: mouseLeftWindow(wxMouseEvent &evt)
{
    Pressed = 0;
    Hovered = 0;
    Refresh();
}

void wxFlatButton:: sizeEvent(wxSizeEvent &evt)
{
    CalculateSize();
    Refresh();
}

void wxFlatButton:: eraseEvent(wxEraseEvent& event){ }

BEGIN_EVENT_TABLE(wxFlatButton, wxPanel)

    EVT_PAINT(wxFlatButton::paintEvent)
    EVT_MOTION(wxFlatButton::mouseMoved)
    EVT_LEFT_DOWN(wxFlatButton::mouseDown)
    EVT_LEFT_UP(wxFlatButton::mouseReleased)
    EVT_LEAVE_WINDOW(wxFlatButton::mouseLeftWindow)
    EVT_ERASE_BACKGROUND(wxFlatButton::eraseEvent)
    EVT_SIZE(wxFlatButton::sizeEvent)

END_EVENT_TABLE()
