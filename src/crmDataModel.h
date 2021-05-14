#ifndef CRMDATAMODEL_H
#define CRMDATAMODEL_H

#include <wx/dataview.h>
#include <wx/vector.h>
#include <wx/arrstr.h>
#include "../sqlite3/CppSQLite3.h"

class crmDataViewColumn
{
public:
    crmDataViewColumn(CppSQLite3Query* query = NULL);
    virtual ~crmDataViewColumn();

    void Load(CppSQLite3Query* query);

    void save();

    void Clear()
    {
        save();
        m_cols.Clear();
        m_types.Clear();
        m_widths.Clear();
    }

    const wxString GetColumnName(const int col) const
    {
        return m_cols[col];
    }

    const wxString GetColumnType(const int col) const
    {
        return m_types[col];
    }

    const int GetColumnWidth(const int col) const
    {
        return m_widths[col];
    }

    void SetColumnWidth(const unsigned int col, const int width)
    {
        if ( col >= 0 && col < m_widths.Count() )
            m_widths[col] = width;
    }

    const unsigned int GetCount() const
    {
        return m_cols.Count();
    }

private:
    wxArrayString   m_cols;
    wxArrayString   m_types;
    wxArrayInt      m_widths;
};

class crmDataBuffer
{
public:
    crmDataBuffer(CppSQLite3Query* query  = NULL);
    virtual ~crmDataBuffer();

    void Retrieve(CppSQLite3Query* query);

    void SortByCol(const unsigned col, bool asAsc);

    const wxString GetValue(const int row, const int col) const
    {
        return m_data[row][col];
    }

    void SetValue(const wxString& val, const int row, const int col)
    {
        m_data[row][col] = val;
    }

    const unsigned int GetCount() const
    {
        return m_row_count;
    }

private:
    wxVector<wxArrayString> m_data;
    int m_col_count;
    long m_row_count;
    static unsigned int m_sorted_col;
    static bool m_sorted_asc;
    static int compare(const wxArrayString& s1, const wxArrayString& s2)
    {
        wxASSERT(m_sorted_col<s1.Count() && m_sorted_col<s2.Count() && s1.Count()== s2.Count());
        if ( m_sorted_col<s1.Count() && m_sorted_col<s2.Count() && s1.Count()== s2.Count() )
        {
            if ( crmDataBuffer::m_sorted_asc)
            {
                return s1.Item(crmDataBuffer::m_sorted_col).Cmp(s2.Item(crmDataBuffer::m_sorted_col));
            }
            return s2.Item(crmDataBuffer::m_sorted_col).Cmp(s1.Item(crmDataBuffer::m_sorted_col));
        }
        return 0;
    };
};


class crmDataModel : public wxDataViewVirtualListModel
{
public:
    crmDataModel(CppSQLite3Query* query = NULL);
    virtual ~crmDataModel();

    crmDataViewColumn* GetColumns()
    {
        return &m_columns;
    };

    crmDataBuffer* GetDataBuffer()
    {
        return &m_buffer;
    };

    void Sort(const unsigned col, bool asAsc);

    void RetrieveData(CppSQLite3Query* query)
    {
        m_columns.Clear();
        m_columns.Load(query);
        m_buffer.Retrieve(query);
        Reset(m_buffer.GetCount());
    };

    // implementation of base class virtuals to define model

    virtual unsigned int GetColumnCount() const
    {
        return m_columns.GetCount();
    };

    virtual wxString GetColumnType( unsigned int col ) const
    {
        return m_columns.GetColumnType(col);
    };

    virtual unsigned int GetRowCount()
    {
        return m_buffer.GetCount();
    };

    virtual void GetValueByRow( wxVariant &variant,
                                unsigned int row, unsigned int col ) const;
    virtual bool GetAttrByRow( unsigned int row, unsigned int col,
                               wxDataViewItemAttr &attr ) const;
    virtual bool SetValueByRow( const wxVariant &variant,
                                unsigned int row, unsigned int col );

protected:
private:
    crmDataViewColumn m_columns;
    crmDataBuffer m_buffer;
    const bool CheckRowAndCol(const unsigned int row, const unsigned int col) const;
};

#endif // CRMDATAMODEL_H
