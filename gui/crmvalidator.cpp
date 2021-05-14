#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#if wxUSE_VALIDATORS

#ifndef WX_PRECOMP
#include "wx/dynarray.h"
#include "wx/utils.h"
#include "wx/intl.h"
#include "wx/choice.h"
#include "wx/combobox.h"
#include "wx/radiobox.h"
#include "wx/radiobut.h"
#include "wx/checkbox.h"
#include "wx/scrolbar.h"
#include "wx/gauge.h"
#include "wx/stattext.h"
#include "wx/textctrl.h"
#include "wx/button.h"
#include "wx/listbox.h"
#include "wx/slider.h"
#include "wx/checklst.h"
#endif

#include "wx/spinctrl.h"
#include "wx/datectrl.h"

#if wxUSE_SPINBTN
#include "wx/spinbutt.h"
#endif
#if wxUSE_TOGGLEBTN
#include "wx/tglbtn.h"
#endif

#include <wx/log.h>
#include "crmvalidator.h"
#include "../src/parameter.h"

IMPLEMENT_CLASS(crmValidator, wxValidator)

crmValidator::crmValidator(long style, std::string *val)
    :wxValidator()
{
    Initialize();
    m_validatorStyle = style;
    m_pSTDString = val;
    if (m_pSTDString)
        m_strBuffer = wxString::FromUTF8(val->c_str());
    InitRegex();
}

crmValidator::crmValidator(long style, double *val)
    :wxValidator()
{
    Initialize();
    m_validatorStyle = style;
    m_pFloat = val;
    if (m_pFloat)
        m_strBuffer.Printf(wxT("%.2f"), *val);
    InitRegex();
}

crmValidator::crmValidator(long style, int *val)
    :wxValidator()
{
    Initialize();
    m_validatorStyle = style;
    m_pInt = val;
    if (m_pInt)
        m_strBuffer.Printf(wxT("%d"), *val);
    InitRegex();
}

crmValidator::crmValidator(const crmValidator& val)
    :wxValidator()
{
    Copy(val);
}

bool crmValidator::Copy(const crmValidator& val)
{
    wxValidator::Copy(val);
    Initialize();
    m_pSTDString = val.m_pSTDString;
    m_pFloat = val.m_pFloat;
    m_pInt = val.m_pInt;
    m_strBuffer = val.m_strBuffer;
    m_validatorStyle = val.m_validatorStyle;
    InitRegex();
    return true;
}

crmValidator::~crmValidator()
{

}

void crmValidator::Initialize()
{
    m_strBuffer     = wxT("");
    m_pSTDString    = 0;
    m_pFloat        = 0;
    m_pInt          = 0;
}

bool crmValidator::InitRegex()
{
    if (HasFlag(crmFILTER_FLOAT))
        return m_regex.Compile(wxString::FromUTF8(theParameter().Get("regex","price")));
    if (HasFlag(crmFILTER_TIME))
        return m_regex.Compile(wxString::FromUTF8(theParameter().Get("regex","time")));
    if (HasFlag(crmFILTER_DATE))
        return m_regex.Compile(wxString::FromUTF8(theParameter().Get("regex","date")));
    if (HasFlag(crmFILTER_DATETIME))
        return m_regex.Compile(wxString::FromUTF8(theParameter().Get("regex","datetime")));
    if (HasFlag(crmFILTER_TRAININFO))
        return m_regex.Compile(wxString::FromUTF8(theParameter().Get("regex","traininfo")));
    return true;
}

bool crmValidator::TransferToWindow()
{
    if ( !m_validatorWindow )
        return false;

    if (m_pFloat)
    {
        m_strBuffer.Printf(wxT("%.2f"), *m_pFloat);
    }
    else if (m_pSTDString)
    {
        m_strBuffer = wxString::FromUTF8(m_pSTDString->c_str());
    }
    else if (m_pInt)
    {
        m_strBuffer = wxString::Format(wxT("%d"), *m_pInt);
    }

#if wxUSE_TEXTCTRL
    if (m_validatorWindow->IsKindOf(CLASSINFO(wxTextCtrl)) )
    {
        wxTextCtrl* pControl = (wxTextCtrl*) m_validatorWindow;
        pControl->SetValue(m_strBuffer);
    }
    else
#endif
#if wxUSE_COMBOBOX
        if (m_validatorWindow->IsKindOf(CLASSINFO(wxComboBox)) )
        {
            wxComboBox* pControl = (wxComboBox*) m_validatorWindow;
            if (pControl->FindString(m_strBuffer) != wxNOT_FOUND)
            {
                pControl->SetStringSelection(m_strBuffer);
            }
            if ((m_validatorWindow->GetWindowStyle() & wxCB_READONLY) == 0)
            {
                pControl->SetValue(m_strBuffer);
            }
        }
        else
#endif
#if wxUSE_SPINCTRL && !defined(__WXMOTIF__)
            if (m_validatorWindow->IsKindOf(CLASSINFO(wxSpinCtrl)) )
            {
                wxSpinCtrl* pControl = (wxSpinCtrl*) m_validatorWindow;
                if (m_pInt)
                {
                    pControl->SetValue(*m_pInt);
                }
            }
            else
#endif
            {
                // to match the last 'else' above
            }

    return true;
}

bool crmValidator::TransferFromWindow()
{
    if ( !m_validatorWindow )
        return false;


#if wxUSE_TEXTCTRL
    if (m_validatorWindow->IsKindOf(CLASSINFO(wxTextCtrl)) )
    {
        wxTextCtrl* pControl = (wxTextCtrl*) m_validatorWindow;
        m_strBuffer = pControl->GetValue();
    }
    else
#endif
#if wxUSE_COMBOBOX
        if (m_validatorWindow->IsKindOf(CLASSINFO(wxComboBox)) )
        {
            wxComboBox* pControl = (wxComboBox*) m_validatorWindow;
            if (m_validatorWindow->GetWindowStyle() & wxCB_READONLY)
                m_strBuffer = pControl->GetStringSelection();
            else
                m_strBuffer = pControl->GetValue();
        }
        else
#endif
#if wxUSE_SPINCTRL && !defined(__WXMOTIF__)
            if (m_validatorWindow->IsKindOf(CLASSINFO(wxSpinCtrl)) )
            {
                wxSpinCtrl* pControl = (wxSpinCtrl*) m_validatorWindow;
                if (m_pInt)
                {
                    *m_pInt = pControl->GetValue();
                    return true;
                }
            }
            else
#endif
            {
                // to match the last 'else' above
            }


    if ( m_pSTDString )
    {
        *m_pSTDString = (const char*)m_strBuffer.ToUTF8();
        return true;
    }

    if ( m_pFloat && m_strBuffer.ToDouble(m_pFloat) )
    {
        return true;
    }

    if ( m_pInt && m_strBuffer.IsNumber() )
    {
        *m_pInt = wxAtoi(m_strBuffer);
        return true;
    }

    return false;

}

bool crmValidator::Validate(wxWindow* parent)
{
    // If window is disabled, simply return
    if ( !m_validatorWindow->IsEnabled() )
        return true;

    wxString val(wxT(""));
#if wxUSE_TEXTCTRL
    if (m_validatorWindow->IsKindOf(CLASSINFO(wxTextCtrl)) )
    {
        wxTextCtrl* pControl = (wxTextCtrl*) m_validatorWindow;
        val = pControl->GetValue();
    }
    else
#endif
#if wxUSE_COMBOBOX
        if (m_validatorWindow->IsKindOf(CLASSINFO(wxComboBox)) )
        {
            wxComboBox* pControl = (wxComboBox*) m_validatorWindow;
            if (m_validatorWindow->GetWindowStyle() & wxCB_READONLY)
                val = pControl->GetStringSelection();
            else
                val = pControl->GetValue();
        }
#endif
#if wxUSE_SPINCTRL && !defined(__WXMOTIF__)
    if (m_validatorWindow->IsKindOf(CLASSINFO(wxSpinCtrl)) )
    {
        wxSpinCtrl* pControl = (wxSpinCtrl*) m_validatorWindow;
        val = wxString::Format(wxT("%d"), pControl->GetValue());
    }
#endif
    {
        // to match the last 'else' above
    }


    wxString errormsg(wxT(""));
    if ( HasFlag(crmFILTER_EMPTY) && val.empty() )
    {
        errormsg = _("Required information entry is empty.");
    }
    else if ( !(errormsg = IsValid(val)).empty() )
    {
        // NB: this format string should always contain exactly one '%s'
        wxString buf;
        buf.Printf(errormsg, val.c_str());
        errormsg = buf;
    }

    if ( !errormsg.empty() )
    {
        m_validatorWindow->SetFocus();
        wxLogError(wxT("%s:\t%s"), _("Validation conflict"),errormsg);
        return false;
    }

    return true;
}

wxString crmValidator::IsValid(const wxString& val) const
{
    // wxFILTER_EMPTY is checked for in wxTextValidator::Validate

    if ( HasFlag(crmFILTER_ASCII) && !val.IsAscii() )
        return _("'%s' should only contain ASCII characters.");
    if ( HasFlag(crmFILTER_NUMERIC) && !val.IsNumber() )
        return _("'%s' should be numeric.");
    if ( HasFlag(crmFILTER_FLOAT) && !m_regex.Matches(val) )
        return _("'%s' should be price.");
    if ( HasFlag(crmFILTER_DATE) && !m_regex.Matches(val) )
        return _("'%s' should be date.");
    if ( HasFlag(crmFILTER_TIME) && !m_regex.Matches(val) )
        return _("'%s' should be time.");
    if ( HasFlag(crmFILTER_DATETIME) && !m_regex.Matches(val) )
        return _("'%s' should be datetime.");
    if ( HasFlag(crmFILTER_TRAININFO) && !m_regex.Matches(val) )
        return _("'%s' should be traininfo.");

    return wxEmptyString;
}
#endif  //if wxUSE_VALIDATOR
