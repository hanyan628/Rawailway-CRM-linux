#ifndef INPUTPARAMETERITEMDIALOG_H
#define INPUTPARAMETERITEMDIALOG_H

//(*Headers(InputParameterItemDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class InputParameterItemDialog: public wxDialog
{
    //----------------------------------------------------------
    //      My Progrman
    //----------------------------------------------------------
public:
    const wxString& getCategory()
    {
        return szCategory;
    };
    const wxString& getKey()
    {
        return szKey;
    };
    const wxString& getValue()
    {
        return szValue;
    };
    void setCategory(const wxString& s)
    {
        szCategory = s;
    };
    void setKey(const wxString& s)
    {
        szKey = s;
    };
    void setValue(const wxString& s)
    {
        szValue = s;
    };
private:
    wxString szCategory;
    wxString szKey;
    wxString szValue;
    //----------------------------------------------------------

public:

    InputParameterItemDialog(wxWindow* parent);
    virtual ~InputParameterItemDialog();

    wxTextCtrl* ctlValue;
    wxTextCtrl* ctlKey;
    wxTextCtrl* ctlCategory;
private:
    //(*Handlers(InputParameterItemDialog)
    void OnInit(wxInitDialogEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
