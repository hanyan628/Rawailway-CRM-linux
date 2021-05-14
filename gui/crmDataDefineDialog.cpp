#include "crmDataDefineDialog.h"

//(*InternalHeaders(crmDataDefineDialog)
#include <wx/xrc/xmlres.h>
//*)
#include "../src/parameter.h"
#include "./crmTrainDefDialog.h"
#include "./crmTrainFilterDialog.h"
#include "./crmOperatorDefDialog.h"
#include "./crmImageDefDialog.h"
#include "./crmGuestDefDialog.h"
#include "./crmRecordModifyDialog.h"
#include "./crmRecordFilterDialog.h"
#include "./crmGuestFilterDialog.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/notifmsg.h>
#include <wx/log.h>
//(*IdInit(crmDataDefineDialog)
//*)

BEGIN_EVENT_TABLE(crmDataDefineDialog,wxDialog)
    //(*EventTable(crmDataDefineDialog)
    EVT_INIT_DIALOG(crmDataDefineDialog::OnInit)
    EVT_BUTTON(XRCID("ID_BUTTON_EDIT"),                     crmDataDefineDialog::OnEdit)
    EVT_BUTTON(XRCID("ID_BUTTON_DELETE"),                   crmDataDefineDialog::OnDelete)
    EVT_BUTTON(XRCID("ID_BUTTON_INSERT"),                   crmDataDefineDialog::OnInsert)
    EVT_BUTTON(XRCID("ID_BUTTON_FILTER"),                   crmDataDefineDialog::OnFilter)
    EVT_BUTTON(XRCID("ID_BUTTON_EXPORT"),                   crmDataDefineDialog::OnExport)
    EVT_BUTTON(XRCID("ID_BUTTON_IMPORT"),                   crmDataDefineDialog::OnImport)
    EVT_BUTTON(XRCID("ID_BUTTON_RETRIEVE"),                 crmDataDefineDialog::OnRetrieve)
    EVT_DATAVIEW_COLUMN_SORTED(XRCID("ID_DATAVIEW_CRM"),    crmDataDefineDialog::OnSorted)
    EVT_CLOSE(                                              crmDataDefineDialog::OnClose)
    //*)
END_EVENT_TABLE()

crmDataDefineDialog::crmDataDefineDialog(wxWindow* parent)
    :m_pds(0),m_edit_dlg(0),m_filter_dlg(0),m_backup(0),
     m_filter_first(false),m_table_mask(maskNoneDefine)
{
    wxXmlResource::Get()->LoadObject(this,parent,_T("crmDataDefineDialog"),_T("wxDialog"));
    ctlDataView = new wxDataViewCtrl(this, XRCID("ID_DATAVIEW_CRM"), wxDefaultPosition,
                                     wxDefaultSize, wxDV_ROW_LINES | wxDV_MULTIPLE );
    wxXmlResource::Get()->AttachUnknownControl(wxT("ID_DATAVIEW_CRM"), ctlDataView, this);
}

crmDataDefineDialog::~crmDataDefineDialog()
{
    if (m_filter_dlg)
    {
        m_filter_dlg->Show(false);
        m_filter_dlg->Close();
    }

    if (m_edit_dlg)
    {
        m_edit_dlg->Show(false);
        m_edit_dlg->Close();
    }

    if (m_backup)
        delete m_backup;

    if (m_pds)
        delete m_pds;

    if ( m_data_list )
        m_data_list.reset(NULL);
}

void crmDataDefineDialog::OnClose(wxCloseEvent& event)
{
    // save columns width
    crmDataViewColumn* column = m_data_list->GetColumns();
    for(unsigned int col=0; col<ctlDataView->GetColumnCount(); ++col)
    {
        wxDataViewColumn* p = ctlDataView->GetColumn(col);
        column->SetColumnWidth(col, p->GetWidth());
    }
    event.Skip();
}

void crmDataDefineDialog::SetTableMask(const MODULE_RIGHTS mask)
{
    m_filter_first = false;

    if (m_pds)
    {
        delete m_pds;
        m_pds = 0;
    }

    if (m_edit_dlg)
    {
        delete m_edit_dlg;
        m_edit_dlg = 0;
    }

    if (m_filter_dlg)
    {
        delete m_filter_dlg;
        m_filter_dlg = 0;
    }

    switch(mask)
    {
    case maskGuestsDef:
        m_pds        =  new crmGuestDef();
        m_edit_dlg   =  new crmGuestDefDialog(this);
        m_filter_dlg =  new crmGuestFilterDialog(this);
        m_backup     =  new crmGuestBackup(true, this);
        break;
    case maskOperatorDef:
        m_pds        =  new crmOperatorDef();
        m_edit_dlg   =  new crmOperatorDefDialog(this);
        m_backup     =  new crmOperatorDefBackup(true, this);
        break;
    case maskImageDef:
        m_pds        =  new crmImageDef();
        m_edit_dlg   =  new crmImageDefDialog(this);
        m_backup     =  new crmImageDefBackup(this);
        break;
    case maskRecordModify:
        m_pds        =  new crmRecordDef();
        m_edit_dlg   =  new crmRecordModifyDialog(this);
        m_filter_dlg =  new crmRecordFilterDialog(this);
        m_backup     =  new crmRecordBackup(true, this);
        m_filter_first = true;
        break;
    case maskTrainsDef:
        m_pds        =  new crmTrainDef();
        m_edit_dlg   =  new crmTrainDefDialog(this);
        m_filter_dlg =  new crmTrainFilterDialog(this);
        m_backup     =  new crmTrainDirBackup(true, this);
        break;
    default:
        m_pds        = 0;
        m_edit_dlg   = 0;
        m_filter_dlg = 0;
        m_backup     = 0;
    }
    m_table_mask     = mask;
}

void crmDataDefineDialog::RetrieveTable()
{
    if ( !m_pds )
    {
        return;
    }

    wxNotificationMessage info( _("tip:"),_("retrieve table, please wait ..."), this);
    info.Show(wxNotificationMessage::Timeout_Never);
    Update();
    wxWindowDisabler disableAll;
#if 1
    wxSafeYield(this, true);
#endif

    try
    {
        CppSQLite3Query* query = 0;
        if ( m_filter_dlg && m_filter_dlg->IsFilter() )
        {
            query = m_pds->GetFilterQuery(m_filter_dlg->getFilter());
        }
        else
        {
            query = m_pds->GetQuery();
        }

        if ( m_data_list )
        {
            m_data_list->RetrieveData(query);
        }
        else
        {
            m_data_list = new crmDataModel(query);
            ctlDataView->AssociateModel(m_data_list.get());
        }


    }
    catch(CppSQLite3Exception e)
    {
        wxLogError(wxString::FromUTF8(e.errorMessage()));
    }
}

bool crmDataDefineDialog::doEdit(crmObject* pObj)
{
    if ( !m_pds || !m_edit_dlg)
    {
        return false;
    }

    m_edit_dlg->SetDataObject(pObj);

    return (m_edit_dlg->ShowModal() == wxID_OK);
}

void crmDataDefineDialog::OnInit(wxInitDialogEvent& event)
{
    if ( !m_data_list )
    {
        m_data_list = new crmDataModel;
        ctlDataView->AssociateModel(m_data_list.get());
    }

    if ( !m_pds )
    {
        wxLogError(_("mush define dataset first!"));
        event.Skip();
        return;
    }

    if ( !m_filter_dlg )
    {
        FindWindow(XRCID("ID_BUTTON_FILTER"))->Disable();
    }

    if ( !m_backup )
    {
        FindWindow(XRCID("ID_BUTTON_IMPORT"))->Disable();
        FindWindow(XRCID("ID_BUTTON_EXPORT"))->Disable();
    }

    if ( m_filter_dlg && m_filter_first )
        m_filter_dlg->ShowModal();

    RetrieveTable();
    InitViewColumns();

    wxFont ft = ctlDataView->GetFont();
    ft.SetPixelSize(wxSize(16,16));
    ft.SetFaceName("Sans");
    ctlDataView->SetFont(ft);

    Fit();
    Center();

    event.Skip();
}

void crmDataDefineDialog::InitViewColumns()
{
    const crmDataViewColumn* columns = m_data_list->GetColumns();
    for( unsigned int col=0; col<columns->GetCount(); ++col)
    {
        //wxDataViewColumn* pColumn =
        ctlDataView->AppendTextColumn(columns->GetColumnName(col), col,
                                      wxDATAVIEW_CELL_INERT,
                                      columns->GetColumnWidth(col),
                                      columns->GetColumnType(col) == "long" || columns->GetColumnType(col) == "double" ?
                                      wxALIGN_RIGHT : wxALIGN_LEFT,
                                      wxDATAVIEW_COL_RESIZABLE);
//                                      wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE | wxDATAVIEW_COL_RESIZABLE);

        //wxLogError(columns->GetColumnType(col));
    }
}

//**********************************************************************
// button event function
//**********************************************************************
void crmDataDefineDialog::OnEdit(wxCommandEvent& event)
{
    if ( !m_pds )
    {
        return;
    }

    wxDataViewItemArray sel;
    const int len = ctlDataView->GetSelections(sel);
    if ( len != 1 )
    {
        wxLogError(_("Please selected one row first!"));
        return;
    }

    if (!sel[0].IsOk())
        return;

    const int row = m_data_list->GetRow(sel[0]);
    wxVariant var;
    m_data_list->GetValueByRow(var, row, 0);
    const int id = atoi(var.GetString().c_str());
    crmObject* pObj = m_pds->getData(id);
    if ( doEdit(pObj) )
    {
        try
        {
            m_pds->Update(pObj);
            RetrieveTable();
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(wxString::FromUTF8(e.errorMessage()));
        }
    }
}

void crmDataDefineDialog::OnDelete(wxCommandEvent& event)
{
    if ( !m_pds )
    {
        return;
    }
    wxDataViewItemArray sel;
    const int len = ctlDataView->GetSelections(sel);
    if ( len <= 0 )
    {
        wxLogError(_("Please selected a row first!"));
        return;
    }

    for(int i=0; i<len; ++i)
    {
        if (!sel[i].IsOk())
            continue;

        const int row = m_data_list->GetRow(sel[i]);
        wxVariant var;
        m_data_list->GetValueByRow(var, row, 0);
        const int id = atoi(var.GetString().c_str());
        try
        {
            m_pds->Delete(id);
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(wxString::FromUTF8(e.errorMessage()));
        }
    }
    RetrieveTable();
}

void crmDataDefineDialog::OnFilter(wxCommandEvent& event)
{
    if (m_filter_dlg && m_filter_dlg->ShowModal()==wxID_OK )
    {
        RetrieveTable();
    }
}

void crmDataDefineDialog::OnImport(wxCommandEvent& event)
{
    if (!m_backup)
    {
        return;
    }

    if ( m_backup->DoImportConfigure() )
    {
        wxWindowDisabler    disableAll;
        wxBusyCursor        wait;

        int ret = m_backup->bcpin();
        if ( ret == -1 )
        {
            wxLogError(_("truncate table error!"));
            return;
        }

        if ( ret == -2 )
        {
            wxLogError(_("open import file error!"));
            return;
        }

        wxMessageBox(wxString::Format(_("import finish, %d rows error, insert %d rows."),
                                      m_backup->getErrRows(),
                                      m_backup->getRows()));

        RetrieveTable();
    }
}

void crmDataDefineDialog::OnExport(wxCommandEvent& event)
{
    if (!m_backup)
    {
        return;
    }

    if (m_filter_dlg && m_filter_dlg->IsFilter())
    {
        m_backup->setFilter(m_filter_dlg->getFilter());
    }

    if ( m_backup->DoExportConfigure() )
    {
        wxWindowDisabler    disableAll;
        wxBusyCursor        wait;

        int ret = m_backup->bcpout();
        if ( ret <= 0 )
        {
            wxLogError(_("export table error!"));
            return;
        }

        wxMessageBox(wxString::Format(_("export finish, %d rows error, export %d rows."),
                                      m_backup->getErrRows(),
                                      m_backup->getRows()));
    }
}

void crmDataDefineDialog::OnInsert(wxCommandEvent& event)
{
    if ( !m_pds )
    {
        return;
    }

    crmObject* pObj = m_pds->getNewData();

    if ( doEdit(pObj) )
    {
        try
        {
            m_pds->Insert(pObj);
            RetrieveTable();
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(wxString::FromUTF8(e.errorMessage()));
        }
    }
    if ( pObj )
        delete pObj;
}

void crmDataDefineDialog::OnRetrieve(wxCommandEvent& event)
{
    RetrieveTable();
}

void crmDataDefineDialog::OnSorted(wxDataViewEvent& event)
{
    wxDataViewColumn* column = event.GetDataViewColumn();
    int pos = ctlDataView->GetColumnPosition( column );
    //wxLogError(wxString::Format("sorted by postion = %d, %s", pos,
    //                            column->IsSortOrderAscending()? "ASC":"DESC"));
    m_data_list->Sort(pos, column->IsSortOrderAscending());
    event.Skip();
}
