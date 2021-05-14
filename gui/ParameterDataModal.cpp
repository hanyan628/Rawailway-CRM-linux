#include "ParameterDataModal.h"
#include <wx/log.h>

ParameterDataModal::ParameterDataModal()
{
    if ( !m_doc.LoadFile( theParameter().GetXMLFileName() ) )
    {
        wxLogError(_("read parameter file error!"));
        return;
    }
}

ParameterDataModal::~ParameterDataModal()
{

}

// **************************************************************************************************
// implementation of base class virtuals to define model
// **************************************************************************************************
void ParameterDataModal::GetValue( wxVariant &variant,
                                   const wxDataViewItem &item, unsigned int col ) const
{
    wxASSERT(item.IsOk());

    TiXmlElement *node = (TiXmlElement*) item.GetID();
    switch (col)
    {
    case 0:
        variant = wxString::FromUTF8( node->Value() );
        break;
    case 1:
        variant = wxString::FromUTF8( node->Attribute("value") );
        break;

    default:
        wxLogError( "ParameterDataModel::GetValue: wrong column %d", col );
    }
}

bool ParameterDataModal::SetValue( const wxVariant &variant,
                                   const wxDataViewItem &item, unsigned int col )
{
    wxASSERT(item.IsOk());

    TiXmlElement *node = (TiXmlElement*) item.GetID();
    if (!node)
        return false;

    switch (col)
    {
    case 1:
        node->SetAttribute("value", variant.GetString().ToUTF8());
        return true;

    default:
        wxLogError( "ParameterDataModel::SetValue: wrong column" );
    }
    return false;
}

wxDataViewItem ParameterDataModal::GetParent( const wxDataViewItem &item ) const
{
    // the invisible root node has no parent
    if (!item.IsOk())
        return wxDataViewItem(0);

    TiXmlElement *node = (TiXmlElement*) item.GetID();

    // "Category" also has no parent
    if ( node == m_doc.RootElement() )
        return wxDataViewItem(0);

    return wxDataViewItem( (void*) node->Parent() );

}

bool ParameterDataModal::IsContainer( const wxDataViewItem &item ) const
{
    TiXmlElement *node = (TiXmlElement*) item.GetID();

    // "Category" also has no parent
    return !(node && node->NoChildren());
}

unsigned int ParameterDataModal::GetChildren( const wxDataViewItem &parent,
        wxDataViewItemArray &array ) const
{
    TiXmlElement *node = (TiXmlElement*) parent.GetID();
    if (!node)
    {
        array.Add( wxDataViewItem( (void*) m_doc.RootElement() ));
        return 1;
    }

    if ( node->NoChildren() )
    {
        return 0;
    }

    unsigned int count = 0;

    TiXmlElement* el= node->FirstChildElement();
    for(; el; el = el->NextSiblingElement())
    {
        array.Add( wxDataViewItem( (void*) el ) );
        count ++;
    }

    return count;
}

bool ParameterDataModal::GetAttr(const wxDataViewItem &item, unsigned int col, wxDataViewItemAttr &attr) const
{
    if ( col==0 && IsContainer(item) )
    {
        attr.SetColour(*wxRED);
        attr.SetBold(true);
        return true;
    }

    if ( col==0 )
    {
        attr.SetColour(*wxBLUE);
    }

    return false;
}

// **************************************************************************************************
// helper methods to change the model
// **************************************************************************************************

void ParameterDataModal::Delete(const wxDataViewItem& item)
{
    TiXmlElement *node = (TiXmlElement*) item.GetID();
    if (!node)      // happens if item.IsOk()==false
        return;

    wxDataViewItem parent( node->Parent() );
    if (!parent.IsOk())
    {
        wxASSERT(node == m_doc.RootElement());

        // don't make the control completely empty:
        wxLogError( _("Cannot remove the root item!") );
        return;
    }

    // is the node one of those we keep stored in special pointers?
    if (IsContainer(item))
    {
        // don't make the control completely empty:
        wxLogError( _("Cannot remove the container item!") );
        return;
    }
    // first remove the node from the parent's array of children;
    // NOTE: MyMusicTreeModelNodePtrArray is only an array of _pointers_
    //       thus removing the node from it doesn't result in freeing it
    node->Parent()->RemoveChild( node );

    // free the node
    //delete node;

    // notify control
    ItemDeleted( parent, item );

}

wxDataViewItem ParameterDataModal::Add(const wxString& category,
                                       const wxString& key,
                                       const wxString& value)
{
    bool isNewCategory = false;
    bool isNewKey = false;

    TiXmlElement* elRoot = m_doc.RootElement();
    TiXmlElement* elCategory = elRoot->FirstChildElement();
    for(; elCategory; elCategory = elCategory->NextSiblingElement())
    {
        wxString str = wxString::FromUTF8( elCategory->Value() );
        if ( category.IsSameAs(str) )
            break;
    }
    if (!elCategory)
    {
        elCategory = new TiXmlElement(category.ToUTF8());
        elRoot->LinkEndChild(elCategory);
        isNewCategory = true;
    }

    TiXmlElement* elKey = elCategory->FirstChildElement();
    for(; elKey; elKey = elKey->NextSiblingElement())
    {
        wxString str = wxString::FromUTF8(elKey->Value());
        if ( key.IsSameAs(str) )
            break;
    }
    if (!elKey)
    {
        elKey = new TiXmlElement(key.ToUTF8());
        elCategory->LinkEndChild(elKey);
        isNewKey = true;
    }

    elKey->SetAttribute("value", value.ToUTF8());
    wxDataViewItem root( (void*) elRoot );
    wxDataViewItem parent( (void*) elCategory );
    wxDataViewItem child( (void*)  elKey );
    if (isNewCategory)
    {
        ItemAdded(root, parent);
    }
    if (isNewKey)
    {
        ItemAdded(parent, child);
    }
    else
    {
        ItemChanged(child);
    }
    return child;
}
