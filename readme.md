# wxFlatButton
A simple flat button custom widget for wxWidgets. Tested on wxWidgets 2.9.*

## Overview
A modern simplistic flat button which may contain two rows of text of different sizes.

## Screenshots
![wxPianoControl](https://raw.githubusercontent.com/petru-dimitriu/wxFlatButton/master/screen1.png)

## API
The prototype of the constructor is as follows:

`wxFlatButton(wxWindow* parent, const long id, wxString SmallText,
                 wxString BigText = "", wxFont f = *wxNORMAL_FONT,
                 int smallSize = 10, int bigSize = 15);`
				 
### Events
The widget sends the following wxCommandEvents:

* `EVT_FLATBUTTON_DOWN`, when the user presses the button
* `EVT_FLATBUTTON_UP`, when the user releases the button
* `EVT_FLATBUTTON_HOVER`, when the user hovers the mouse pointer over the button

### Methods

#### Getters
* `wxColour GetBorderColour()`
* `wxColour GetNormalColour()`
* `wxColour GetHoveredColour()`
* `wxColour GetPressedColour()`
* `wxString GetSmallText()`
* `wxString GetBigText()`

#### Setters
* `void SetSmallText(wxString)`
* `void SetBigText(wxString)`
* `void SetBorderColour(wxColour)`
* `void SetNormalColour(wxColour)`
* `void SetHoveredColour(wxColour)`
* `void SetPressedColour(wxColour)`

## License
I hereby release this to the public domain. I don't mind if you credit me, though.
