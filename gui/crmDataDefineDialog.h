#ifndef CRMDATADEFINEDIALOG_H
#define CRMDATADEFINEDIALOG_H

//(*Headers(crmDataDefineDialog)
#include <wx/dialog.h>
#include <wx/dataview.h>
#include "./crmEditDataDialog.h"
#include "./crmFilterDataDialog.h"
#include "../datamodule/crm_dataset.h"
#include "../datamodule/crm_backup.h"
#include "../src/crmDataModel.h"
//*)

class crmDataDefineDialog: public wxDialog
{
public:

    crmDataDefineDialog(wxWindow* parent);
    virtual ~crmDataDefineDialog();

    //(*Declarations(crmDataDefineDialog)
    //*)
    wxDataViewCtrl* ctlDataView;

protected:

    //(*Identifiers(crmDataDefineDialog)
    //*)

private:
    wxObjectDataPtr<crmDataModel> m_data_list;

    //(*Handlers(crmDataDefineDialog)
    void OnInit     (   wxInitDialogEvent&  event   );
    void OnEdit     (   wxCommandEvent&     event   );
    void OnDelete   (   wxCommandEvent&     event   );
    void OnFilter   (   wxCommandEvent&     event   );
    void OnImport   (   wxCommandEvent&     event   );
    void OnExport   (   wxCommandEvent&     event   );
    void OnInsert   (   wxCommandEvent&     event   );
    void OnRetrieve (   wxCommandEvent&     event   );
    void OnClose    (   wxCloseEvent&       event   );
    void OnSorted   (   wxDataViewEvent&    event   );
    //*)


    //----------------------------------------------------------------
    //             My progrman
    //----------------------------------------------------------------
public:
    void SetTableMask(const MODULE_RIGHTS mask);
private:
    bool doEdit(crmObject* obj);
    void InitViewColumns();
    void RetrieveTable();
    crmDataSet* m_pds;
    crmEditDataDialog* m_edit_dlg;
    crmFilterDataDialog* m_filter_dlg;
    crmBackup* m_backup;
    bool m_filter_first;
    MODULE_RIGHTS m_table_mask;
    //----------------------------------------------------------------

    DECLARE_EVENT_TABLE()
};

#endif
