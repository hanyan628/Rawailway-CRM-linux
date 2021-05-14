#ifndef PARAMETERDATAMODAL_H
#define PARAMETERDATAMODAL_H

#include <wx/dataview.h>
#include "../src/parameter.h"

class ParameterDataModal : public wxDataViewModel
{
public:
    ParameterDataModal();
    virtual ~ParameterDataModal();

    // implementation of base class virtuals to define model

    virtual unsigned int GetColumnCount() const
    {
        return 2;
    }

    virtual wxString GetColumnType( unsigned int col ) const
    {
        return wxT("string");
    }

    virtual void GetValue( wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col ) const;
    virtual bool SetValue( const wxVariant &variant,
                           const wxDataViewItem &item, unsigned int col );

    virtual wxDataViewItem GetParent( const wxDataViewItem &item ) const;
    virtual bool IsContainer( const wxDataViewItem &item ) const;
    virtual unsigned int GetChildren( const wxDataViewItem &parent,
                                      wxDataViewItemArray &array ) const;
    virtual bool GetAttr(const wxDataViewItem &item, unsigned int col, wxDataViewItemAttr &attr) const;
    // helper methods to change the model

    wxDataViewItem GetRootItem()
    {
        return wxDataViewItem( (void*) m_doc.RootElement() );
    }

    void Delete(const wxDataViewItem& item);
    wxDataViewItem Add(const wxString& category, const wxString& key, const wxString& value);
    bool Save()
    {
        return m_doc.SaveFile(theParameter().GetXMLFileName());
    };
protected:
private:
    TiXmlDocument m_doc;
};

#endif // PARAMETERDATAMODAL_H
