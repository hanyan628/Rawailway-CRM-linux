#include "crmDataModel.h"
#include <wx/log.h>
#include <tinyxml.h>
#include <algorithm>
//*************************************************************************
//  class crmDataModel
//*************************************************************************

crmDataModel::crmDataModel(CppSQLite3Query* query)
    :m_columns(query),m_buffer(query)
{
    Reset(m_buffer.GetCount());
}

crmDataModel::~crmDataModel()
{
    //dtor
}

void crmDataModel::GetValueByRow( wxVariant &variant,
                            unsigned int row, unsigned int col ) const
{
    if ( CheckRowAndCol(row,col) )
        variant = m_buffer.GetValue(row,col);
}

bool crmDataModel::GetAttrByRow( unsigned int row, unsigned int col,
                           wxDataViewItemAttr &attr ) const
{
    if ( !CheckRowAndCol(row,col) )
    {
        return false;
    }

    if ( m_columns.GetColumnType(col) == "long" ||
         m_columns.GetColumnType(col) == "double" )
    {
        attr.SetColour(*wxBLUE);
        return true;
    } else if ( m_columns.GetColumnType(col) == "unknown" )
    {
        attr.SetColour(*wxRED);
        return true;
    }

    return false;
}


bool crmDataModel::SetValueByRow( const wxVariant &variant,
                            unsigned int row, unsigned int col )
{
    if ( CheckRowAndCol(row,col) )
    {
        m_buffer.SetValue(variant.GetString(), row, col);
        return true;
    }

    return false;
}

const bool crmDataModel::CheckRowAndCol(const unsigned int row, const unsigned int col) const
{
    if ( row >= m_buffer.GetCount() )
    {
        wxLogError(_("the row out of range!"));
        return false;
    }

    if ( col >= m_columns.GetCount() )
    {
        wxLogError(_("the col out of range!"));
        return false;
    }

    return true;
}

void crmDataModel::Sort(const unsigned col, bool asAsc)
{
    if ( col >= GetColumnCount() )
    {
        wxLogError(_("sort column is large !"));
    }
    m_buffer.SortByCol(col, asAsc);
}
//*************************************************************************
//  class crmDataViewColumn
//*************************************************************************
crmDataViewColumn::crmDataViewColumn(CppSQLite3Query* query)
{
    if (query)
    {
        Load(query);
    }
}

crmDataViewColumn::~crmDataViewColumn()
{
    save();
}

void crmDataViewColumn::save()
{
    TiXmlDocument doc("./res/dataview.xml");
    doc.LoadFile();
    TiXmlElement* elRoot = doc.RootElement();
    if (!elRoot)
    {
        elRoot = new TiXmlElement("root");
        doc.LinkEndChild(elRoot);
    }
    TiXmlElement* el = NULL;
    for(unsigned int i=0; i<m_cols.Count(); ++i)
    {
        el = elRoot->FirstChild(m_cols[i].ToUTF8()) ? elRoot->FirstChild(m_cols[i].ToUTF8())->ToElement() : NULL;
        if (!el)
        {
            el = new TiXmlElement(m_cols[i].ToUTF8());
            elRoot->LinkEndChild(el);
        }
        el->SetAttribute("width", m_widths[i]);
    }
    doc.SaveFile();
}

void crmDataViewColumn::Load(CppSQLite3Query* query)
{
    if (!query)
    {
        wxLogError(_("init dataview column error!"));
        return;
    }

    TiXmlDocument doc("./res/dataview.xml");
    doc.LoadFile();
    TiXmlElement* elRoot = doc.RootElement();

    for(int col=0; col < query->numFields(); ++col)
    {
        m_cols.Add(wxString::FromUTF8(query->fieldName(col)));
        const int nType = query->fieldDataType(col);
        if ( nType == SQLITE_FLOAT )
        {
            m_types.Add( wxT("double") );
        }else if ( nType == SQLITE_INTEGER )
        {
            m_types.Add( wxT("long") );
        }else if ( nType == SQLITE3_TEXT )
        {
            m_types.Add( wxT("string") );
        }else
        {
            m_types.Add( wxT("unknown") );
        }
        int width=0;
        if ( elRoot && elRoot->FirstChild(query->fieldName(col)) &&
             elRoot->FirstChild(query->fieldName(col))->ToElement()->QueryIntAttribute("width",&width) == TIXML_SUCCESS )
        {
            m_widths.Add( width );
        }
        else
            m_widths.Add(80);
    }
}
//*************************************************************************
//  class crmDataBuffer
//*************************************************************************
bool crmDataBuffer::m_sorted_asc = true;
unsigned int crmDataBuffer::m_sorted_col = 0;

crmDataBuffer::crmDataBuffer(CppSQLite3Query* query)
    :m_col_count(0),m_row_count(0)
{
    if (query)
    {
        Retrieve(query);
    }
}

void crmDataBuffer::Retrieve(CppSQLite3Query* query)
{
    if (!query)
    {
        wxLogError(_("init data buffer error!"));
        return;
    }
    m_col_count = query->numFields();
    m_row_count = 0;
    m_data.clear();
    wxArrayString item;
    while(!query->eof())
    {
        item.Clear();
        for(int col = 0; col<m_col_count; ++col)
        {
            item.Add( query->fieldDataType(col) == SQLITE3_TEXT ?
                      wxString::FromUTF8(query->fieldValue(col)) : wxString(query->fieldValue(col)) );
        }
        m_data.push_back(item);
        m_row_count ++;
        query->nextRow();
    }
}


crmDataBuffer::~crmDataBuffer()
{

}


void crmDataBuffer::SortByCol(const unsigned col, bool asAsc)
{
    crmDataBuffer::m_sorted_asc = asAsc;
    crmDataBuffer::m_sorted_col = col;
    std::sort(m_data.begin(), m_data.end(), crmDataBuffer::compare);
}
