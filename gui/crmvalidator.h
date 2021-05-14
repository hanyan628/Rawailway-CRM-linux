#ifndef CRMVALIDATOR_H
#define CRMVALIDATOR_H

#include <wx/valgen.h>
#include <wx/string.h>
#include <wx/regex.h>
#include <string>

enum crmValidatorStyle
{
    crmFILTER_NONE      = 0x0,
    crmFILTER_EMPTY     = 0x1,
    crmFILTER_ASCII     = 0x2,
    crmFILTER_FLOAT     = 0x10,
    crmFILTER_NUMERIC   = 0x20,
    crmFILTER_DATETIME  = 0x40,
    crmFILTER_DATE      = 0x80,
    crmFILTER_TIME      = 0x100,
    crmFILTER_TRAININFO = 0x200
};

class crmValidator : public wxValidator
{
public:
    crmValidator(long style = crmFILTER_NONE,       std::string *val = NULL);
    crmValidator(long style = crmFILTER_FLOAT,      double *val = NULL);
    crmValidator(long style = crmFILTER_NUMERIC,    int *val = NULL);
    crmValidator(const crmValidator& val);

    // Make a clone of this validator (or return NULL) - currently necessary
    // if you're passing a reference to a validator.
    // Another possibility is to always pass a pointer to a new validator
    // (so the calling code can use a copy constructor of the relevant class).
    virtual wxObject *Clone() const
    {
        return new crmValidator(*this);
    };
    bool Copy(const crmValidator& val);

    // Called when the value in the window must be validated.
    // This function can pop up an error message.
    virtual bool Validate(wxWindow *parent);

    // Called to transfer data to the window
    virtual bool TransferToWindow();

    // Called to transfer data from the window
    virtual bool TransferFromWindow();

    virtual ~crmValidator();
protected:
    std::string*    m_pSTDString;
    double*         m_pFloat;
    int*            m_pInt;
    wxString        m_strBuffer;
    long            m_validatorStyle;
    wxRegEx         m_regex;

    void Initialize();

    bool HasFlag(crmValidatorStyle style) const
    {
        return (m_validatorStyle & style) != 0;
    }

    // returns the error message if the contents of 'val' are invalid
    virtual wxString IsValid(const wxString& val) const;
private:
    bool InitRegex();
    DECLARE_CLASS(crmValidator)
    wxDECLARE_NO_ASSIGN_CLASS(crmValidator);
};

#endif // CRMVALIDATOR_H
