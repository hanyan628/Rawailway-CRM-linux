#include "crm_backup.h"
#include <fstream>
#include <iostream>
#include <wx/string.h>
#include <wx/progdlg.h>
#include <wx/msgdlg.h>
#include <wx/log.h>
#include <wx/notifmsg.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include "../src/crmFileInfo.h"

//---------------------------------------------------------------
//          BACKUP ABS CLASS
//---------------------------------------------------------------
const bool crmBackup::DoImportConfigure()
{
    wxString caption = _("Choose Import file");
    wxString wildcard =	wxT("data files (*.csv)|*.csv|all files (*.*)|*.*");
    wxString defaultDir = wxT("./");
    wxString defaultFilename = wxEmptyString;
    wxFileDialog dialog(m_parent, caption, defaultDir,
                        defaultFilename, wildcard, wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (dialog.ShowModal() == wxID_OK)
    {
        m_file_name = dialog.GetPath();
        wxMessageDialog dlg(m_parent, _("are you truncate table of the old datas?"),
                            _("tip:"),
                            wxNO_DEFAULT|wxYES_NO|wxICON_QUESTION);
        m_isTruncateOldData = false;
        if (dlg.ShowModal() == wxID_YES)
        {
            m_isTruncateOldData = true;
        }
        return true;
    }
    return false;
}

const bool crmBackup::DoExportConfigure()
{
    wxString caption = _("Choice Export file");
    wxString wildcard =	wxT("data files (*.csv)|*.csv|all files (*.*)|*.*");
    wxString defaultDir = wxT("./");
    wxString defaultFilename = wxEmptyString;
    wxFileDialog dialog(m_parent, caption, defaultDir,
                        defaultFilename, wildcard, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (dialog.ShowModal() == wxID_OK)
    {
        m_file_name = dialog.GetPath();
        crmFileInfo fileInfo(m_file_name);
        if (fileInfo.GetExt().MakeLower() != "csv")
        {
            m_file_name += ".csv";
        }
        return true;
    }
    return false;

}
//---------------------------------------------------------------


//---------------------------------------------------------------
//          REPORT BACKUP CLASS
//---------------------------------------------------------------
const int crmReportBackup::bcpout()
{
    if ( !m_data || !m_columns )
    {
        wxLogError(_("no data or column, report bcpout error!"));
        return -1;
    }

    const int maxProgress = m_data->GetCount() + m_columns->GetCount() + 2;
    wxProgressDialog dlg(_("export report"),
                         _("report head"),
                         maxProgress,
                         m_parent,
                         wxPD_CAN_ABORT |
                         wxPD_APP_MODAL |
                         wxPD_ELAPSED_TIME |
                         wxPD_ESTIMATED_TIME |
                         wxPD_REMAINING_TIME);
    bool cont = true;

    std::ofstream out(m_file_name.c_str(), std::ios::trunc | std::ios::binary);
    if ( !out )
    {
        return -2;
    }
    cont = dlg.Update(0, _("title export ..."));

    if ( !m_title.empty() )
    {
        out << wxString::FromUTF8(m_title.c_str()).c_str() << "\n";
    }

    int ret = 0;
    //table head
    for(unsigned int i=0; i<m_columns->GetCount(); ++i)
    {
        ret ++;
        cont = dlg.Update(ret, _("head columns export ..."));
        out << "\"" << m_columns->GetColumnName(i).c_str() << "\"" << m_symbol;
    }
    out << "\n";
    //table data
    m_insert_rows = 0;
    m_error_rows = 0;
    cont = dlg.Update(ret, _("report data export ..."));
    for(unsigned int i=0; i<m_data->GetCount(); ++i)
    {
        ret ++;
        cont = dlg.Update(ret, _("report data export ..."));
        if (!cont)
        {
            if ( wxMessageBox(_("Do you really want to cancel?"),
                              _("Progress dialog question"),
                              wxYES_NO | wxICON_QUESTION) == wxYES )
                break;
            dlg.Resume();
        }
        m_insert_rows++;
        for(unsigned int j=0; j<m_columns->GetCount(); ++j)
        {
            out << "\"" << m_data->GetValue(i,j).c_str() << "\"" << m_symbol;
        }
        out << "\n";
    }

    cont = dlg.Update(maxProgress-1, _("report foot export ..."));
    if ( !m_foot.empty() )
    {
        out << wxString::FromUTF8(m_foot.c_str()).c_str() << "\n";
        ret ++;
    }

    out.close();
    cont = dlg.Update(maxProgress, _("report export finished!"));
    return ret;
}

//---------------------------------------------------------------
//          TRAIN DIR IMPORT CLASS
//---------------------------------------------------------------
const int crmTrainDirBackup::bcpin()
{
//-------------------------------------------------------------------------------------------
//          show notification message
//-------------------------------------------------------------------------------------------
    wxNotificationMessage info( _("tip:"), _("import data of train dir, please wait ..."), m_parent);
    info.Show(wxNotificationMessage::Timeout_Never);
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
//-------------------------------------------------------------------------------------------

    int ret = 0;
    try
    {
        if (m_isTruncateOldData)
        {
            m_dsTrainDir.ExecuteSQL("DELETE FROM sqlite_sequence WHERE name='crm_train_dir';");
            m_dsTrainDir.ExecuteSQL("DELETE FROM crm_train_dir;");
        }

        std::ifstream in(m_file_name.c_str(), std::ios::binary);
        m_insert_rows = 0;
        m_error_rows = 0;
        if ( !in )
        {
            return -2;
        }
        std::string strBuf;
        CppSQLite3Buffer szSQL;
        while(getline(in, strBuf))
        {
            szSQL.clear();
            szSQL.format("INSERT INTO crm_train_dir VALUES(NULL,%s);", strBuf.c_str());
            try
            {
                m_dsTrainDir.ExecuteSQL(szSQL);
                m_insert_rows++;
            }
            catch(CppSQLite3Exception e)
            {
                m_error_rows++;
            }
            ret ++;
        }
        in.close();
    }
    catch(CppSQLite3Exception e)
    {
        std::string err = e.errorMessage();
    }

//---------------------------------------------------------------------------------------------
//                  close notification message
//---------------------------------------------------------------------------------------------
    info.Close();
//---------------------------------------------------------------------------------------------

    return ret;
}

const int crmTrainDirBackup::bcpout()
{
//-------------------------------------------------------------------------------------------
//          show notification message
//-------------------------------------------------------------------------------------------
    wxNotificationMessage info( _("tip:"), _("export data of train dir, please wait ..."), m_parent);
    info.Show(wxNotificationMessage::Timeout_Never);
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
//-------------------------------------------------------------------------------------------

    std::ofstream out(m_file_name.c_str(), std::ios::trunc | std::ios::binary);
    if ( !out )
    {
        return -2;
    }
    m_insert_rows = 0;
    std::string sql = "SELECT * FROM crm_train_dir";
    if ( m_sql_filter.length() > 0 )
    {
        sql += " WHERE ";
        sql += m_sql_filter;
    }
    sql += ";";

    CppSQLite3Query* tbl = m_dsTrainDir.GetQuery(sql.c_str());
    //table data
    while(!tbl->eof())
    {
        m_insert_rows++;
        for(int j=1; j<tbl->numFields(); ++j)
        {
            out << "\"" << tbl->fieldValue(j) << "\"" << ((j == tbl->numFields() - 1) ? "" : ",");
        }
        out << "\n";
        tbl->nextRow();
    }
    out.close();

//---------------------------------------------------------------------------------------------
//                  close notification message
//---------------------------------------------------------------------------------------------
    info.Close();
//---------------------------------------------------------------------------------------------

    return m_insert_rows;
}

//---------------------------------------------------------------
//          RECORDS BACKUP CLASS
//---------------------------------------------------------------
const int crmRecordBackup::bcpin()
{
//-------------------------------------------------------------------------------------------
//          show notification message
//-------------------------------------------------------------------------------------------
    wxNotificationMessage info( _("tip:"), _("import data of welcome records, please wait ..."), m_parent);
    info.Show(wxNotificationMessage::Timeout_Never);
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
//-------------------------------------------------------------------------------------------

    int ret = 0;
    m_insert_rows = 0;
    m_error_rows = 0;

    if (m_isTruncateOldData)
    {
        try
        {
            m_dsRecord.ExecuteSQL("DELETE FROM sqlite_sequence WHERE name='crm_welcome_record';");
            m_dsRecord.ExecuteSQL("DELETE FROM crm_welcome_record;");
        }
        catch(CppSQLite3Exception e)
        {
            return -1;
        }
    }

    std::ifstream in(m_file_name.c_str(), std::ios::binary);
    if (!in)
    {
        return -2;
    }

    std::string strBuf;
    CppSQLite3Buffer szSQL;
    int i=0;
    m_dsRecord.ExecuteSQL("BEGIN TRANSACTION;");
    while(getline(in, strBuf))
    {
        try
        {
            szSQL.clear();
            szSQL.format("INSERT INTO crm_welcome_record VALUES(NULL,%s);", strBuf.c_str());
            m_dsRecord.ExecuteSQL(szSQL);
            m_insert_rows ++;
            i++;
            if (i == 1000)
            {
                m_dsRecord.ExecuteSQL("COMMIT;");
                m_dsRecord.ExecuteSQL("BEGIN TRANSACTION;");
                i = 0;
            }
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(e.errorMessage());
            m_error_rows ++;
        }
        ret++;
    }
    m_dsRecord.ExecuteSQL("COMMIT;");
    in.close();

//---------------------------------------------------------------------------------------------
//                  close notification message
//---------------------------------------------------------------------------------------------
    info.Close();
//---------------------------------------------------------------------------------------------

    return ret;
}

const int crmRecordBackup::bcpout()
{
//-------------------------------------------------------------------------------------------
//          show notification message
//-------------------------------------------------------------------------------------------
    wxNotificationMessage info( _("tip:"), _("export data of welcome records, please wait ..."), m_parent);
    info.Show(wxNotificationMessage::Timeout_Never);
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
//-------------------------------------------------------------------------------------------

    std::ofstream out(m_file_name.c_str(), std::ios::trunc | std::ios::binary);
    if ( !out )
    {
        return -2;
    }

    std::string sql = "SELECT * FROM crm_welcome_record";
    if ( m_sql_filter.length() > 0 )
    {
        sql += " WHERE ";
        sql += m_sql_filter;
    }
    sql += ";";

    CppSQLite3Query* tbl = NULL;
    try
    {
        tbl = m_dsRecord.GetQuery(sql.c_str());
    }
    catch(CppSQLite3Exception e)
    {
        wxLogError(e.errorMessage());
        return -1;
    }

    m_insert_rows = 0;
    m_error_rows = 0;
    //table data
    while(!tbl->eof())
    {
        try
        {
            m_insert_rows ++;
            for(int j=1; j<tbl->numFields(); ++j)
            {
                out << "\"" << tbl->fieldValue(j) << "\"" << ((j == tbl->numFields() - 1) ? "" : ",");
            }
            out << "\n";
            tbl->nextRow();
        }
        catch(...)
        {
            m_error_rows ++;
        }
    }
    out.close();

//---------------------------------------------------------------------------------------------
//                  close notification message
//---------------------------------------------------------------------------------------------
    info.Close();
//---------------------------------------------------------------------------------------------

    return m_insert_rows;
}


//---------------------------------------------------------------
//          GUESTS BACKUP CLASS
//---------------------------------------------------------------
const int crmGuestBackup::bcpin()
{
//-------------------------------------------------------------------------------------------
//          show notification message
//-------------------------------------------------------------------------------------------
    wxNotificationMessage info( _("tip:"), _("import data of guests, please wait ..."), m_parent);
    info.Show(wxNotificationMessage::Timeout_Never);
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
//-------------------------------------------------------------------------------------------

    int ret = 0;
    m_insert_rows = 0;
    m_error_rows = 0;

    //truncate table
    if (m_isTruncateOldData)
    {
        try
        {
            m_dsGuestDef.ExecuteSQL("DELETE FROM crm_guest_def;");
        }
        catch(CppSQLite3Exception e)
        {
            return -1;
        }
    }


    //import data
    std::ifstream in(m_file_name.c_str(), std::ios::binary);
    if (!in)
    {
        return -2;
    }

    std::string strBuf;
    CppSQLite3Buffer szSQL;
    int i=0;
    m_dsGuestDef.ExecuteSQL("BEGIN TRANSACTION;");
    while(getline(in, strBuf))
    {
        try
        {
            szSQL.clear();
            szSQL.format("INSERT INTO crm_guest_def VALUES(NULL,%s);", strBuf.c_str());
            m_dsGuestDef.ExecuteSQL(szSQL);
            m_insert_rows ++;
            i++;
            if (i == 1000)
            {
                m_dsGuestDef.ExecuteSQL("COMMIT;");
                m_dsGuestDef.ExecuteSQL("BEGIN TRANSACTION;");
                i = 0;
            }
        }
        catch(CppSQLite3Exception e)
        {
            //std::string err = e.errorMessage();
            m_error_rows ++;
        }
        ret ++;
    }
    m_dsGuestDef.ExecuteSQL("COMMIT;");
    in.close();

//---------------------------------------------------------------------------------------------
//                  close notification message
//---------------------------------------------------------------------------------------------
    info.Close();
//---------------------------------------------------------------------------------------------

    return ret;
}

const int crmGuestBackup::bcpout()
{
//-------------------------------------------------------------------------------------------
//          show notification message
//-------------------------------------------------------------------------------------------
    wxNotificationMessage info( _("tip:"), _("export data of guests, please wait ..."), m_parent);
    info.Show(wxNotificationMessage::Timeout_Never);
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
//-------------------------------------------------------------------------------------------

    std::ofstream out(m_file_name.c_str(), std::ios::trunc | std::ios::binary);
    if ( !out )
    {
        return -2;
    }
    m_insert_rows = 0;
    m_error_rows = 0;
    std::string sql = "SELECT * FROM crm_guest_def";

    if ( m_sql_filter.length() > 0 )
    {
        sql += " WHERE ";
        sql += m_sql_filter;
    }
    sql += ";";

    CppSQLite3Query* tbl = m_dsGuestDef.GetQuery(sql.c_str());

    //table data
    while(!tbl->eof())
    {
        m_insert_rows++;
        for(int j=1; j<tbl->numFields(); ++j)
        {
            out << "\"" << tbl->fieldValue(j) << "\"" << ((j == tbl->numFields() - 1) ? "" : ",");
        }
        out << "\n";
        tbl->nextRow();
    }
    out.close();

//---------------------------------------------------------------------------------------------
//                  close notification message
//---------------------------------------------------------------------------------------------
    info.Close();
//---------------------------------------------------------------------------------------------

    return m_insert_rows;
}

//---------------------------------------------------------------
//          OPERATORS BACKUP CLASS
//---------------------------------------------------------------
const int crmOperatorDefBackup::bcpin()
{
//-------------------------------------------------------------------------------------------
//          show notification message
//-------------------------------------------------------------------------------------------
    wxNotificationMessage info( _("tip:"), _("import data of operators, please wait ..."), m_parent);
    info.Show(wxNotificationMessage::Timeout_Never);
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
//-------------------------------------------------------------------------------------------

    int ret = 0;
    m_insert_rows = 0;
    m_error_rows = 0;

    //truncate table
    if (m_isTruncateOldData)
    {
        try
        {
            m_dsOperatorDef.ExecuteSQL("DELETE FROM sqlite_sequence WHERE name='crm_operator_def';");
            m_dsOperatorDef.ExecuteSQL("DELETE FROM crm_operator_def;");
        }
        catch(CppSQLite3Exception e)
        {
            return -1;
        }
    }


    //import data
    std::ifstream in(m_file_name.c_str(), std::ios::binary);
    if (!in)
    {
        return -2;
    }

    std::string strBuf;
    CppSQLite3Buffer szSQL;
    int i=0;
    m_dsOperatorDef.ExecuteSQL("BEGIN TRANSACTION;");
    while(getline(in, strBuf))
    {
        try
        {
            szSQL.clear();
            szSQL.format("INSERT INTO crm_operator_def VALUES(NULL,%s);", strBuf.c_str());
            m_dsOperatorDef.ExecuteSQL(szSQL);
            m_insert_rows ++;
            i++;
            if (i == 1000)
            {
                m_dsOperatorDef.ExecuteSQL("COMMIT;");
                m_dsOperatorDef.ExecuteSQL("BEGIN TRANSACTION;");
                i = 0;
            }
        }
        catch(CppSQLite3Exception e)
        {
            //std::string err = e.errorMessage();
            m_error_rows ++;
        }
        ret ++;
    }
    m_dsOperatorDef.ExecuteSQL("COMMIT;");
    in.close();

//---------------------------------------------------------------------------------------------
//                  close notification message
//---------------------------------------------------------------------------------------------
    info.Close();
//---------------------------------------------------------------------------------------------

    return ret;
}

const int crmOperatorDefBackup::bcpout()
{
//-------------------------------------------------------------------------------------------
//          show notification message
//-------------------------------------------------------------------------------------------
    wxNotificationMessage info( _("tip:"), _("export data of operators, please wait ..."), m_parent);
    info.Show(wxNotificationMessage::Timeout_Never);
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
//-------------------------------------------------------------------------------------------

    std::ofstream out(m_file_name.c_str(), std::ios::trunc | std::ios::binary);
    if ( !out )
    {
        return -2;
    }
    m_insert_rows = 0;
    m_error_rows = 0;
    std::string sql = "SELECT * FROM crm_operator_def";

    if ( m_sql_filter.length() > 0 )
    {
        sql += " WHERE ";
        sql += m_sql_filter;
    }
    sql += ";";

    CppSQLite3Query* tbl = m_dsOperatorDef.GetQuery(sql.c_str());

    //table data
    while(!tbl->eof())
    {
        m_insert_rows++;
        for(int j=1; j<tbl->numFields(); ++j)
        {
            out << "\"" << tbl->fieldValue(j) << "\"" << ((j == tbl->numFields() - 1) ? "" : ",");
        }
        out << "\n";
        tbl->nextRow();
    }
    out.close();

//---------------------------------------------------------------------------------------------
//                  close notification message
//---------------------------------------------------------------------------------------------
    info.Close();
//---------------------------------------------------------------------------------------------

    return m_insert_rows;
}

//---------------------------------------------------------------
//          IMAGES BACKUP CLASS
//---------------------------------------------------------------
const bool crmImageDefBackup::DoImportConfigure()
{
    wxString caption        = _("Choose image files to import");
    wxString wildcard       =	wxT("Image files (*.*)|*.*");
    wxString defaultDir     = wxT("./");
    wxString defaultFilename= wxEmptyString;
    wxFileDialog dialog(m_parent, caption, defaultDir,
                        defaultFilename, wildcard, wxFD_OPEN|wxFD_MULTIPLE|wxFD_FILE_MUST_EXIST);
    m_dir = wxT("");
    m_files.Clear();
    if (dialog.ShowModal() == wxID_OK)
    {
        dialog.GetFilenames(m_files);
        m_dir = dialog.GetDirectory();
        wxMessageDialog dlg(m_parent, _("are you truncate table of the old datas?"),
                            _("tip:"),
                            wxNO_DEFAULT|wxYES_NO|wxICON_QUESTION);
        m_isTruncateOldData = false;
        if (dlg.ShowModal() == wxID_YES)
        {
            m_isTruncateOldData = true;
        }
        return true;
    }
    return false;
}

const int crmImageDefBackup::bcpin()
{
#if 1
    if ( m_parent )
    {
        m_parent->Update();
        wxSafeYield(m_parent,  true);
    }
#endif
    const int maxProgress = m_files.Count() + 1;
    wxProgressDialog dlg(_("import image files"),
                         _("wait ..."),
                         maxProgress,
                         m_parent,
                         wxPD_CAN_ABORT |
                         wxPD_AUTO_HIDE |
                         wxPD_APP_MODAL |
                         wxPD_ELAPSED_TIME |
                         wxPD_ESTIMATED_TIME |
                         wxPD_REMAINING_TIME);
    bool cont = dlg.Update(0, _("wait ..."));

    if (m_isTruncateOldData)
    {
        try
        {
            cont = dlg.Update(1, _("truncate date of images ..."));
            m_dsImageDef.ExecuteSQL("DELETE FROM sqlite_sequence WHERE name='crm_image_def';");
            m_dsImageDef.ExecuteSQL("DELETE FROM crm_image_def WHERE id>2;");
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(e.errorMessage());
            return -1;
        }
    }

    m_insert_rows = 0;
    m_error_rows = 0;
    strucImage img;
    for(unsigned int i=0; i<m_files.GetCount(); ++i)
    {
        cont = dlg.Update(i+2, _("import image files, please wait ..."));
        if (!cont)
        {
            if ( wxMessageBox(_("Do you really want to cancel?"),
                              _("Progress dialog question"),
                              wxYES_NO | wxICON_QUESTION) == wxYES )
                break;
            dlg.Resume();
        }
        wxString            file = wxString::Format(wxT("%s/%s"), m_dir, m_files[i]);
        crmFileInfo         fileInfo(file);
        wxFileInputStream   stream(file);
        unsigned char*      buffer = new unsigned char[fileInfo.GetSize()];
        stream.Read(buffer, fileInfo.GetSize());
        img.comment     = fileInfo.GetName();
        img.image_type  = fileInfo.GetExt().MakeLower();
        img.image_size  = fileInfo.GetSize();
        img.SetImageBody(buffer, fileInfo.GetSize());
        delete [] buffer;
        try
        {
            m_dsImageDef.Insert(&img);
            m_insert_rows ++;
        }
        catch(CppSQLite3Exception e)
        {
            wxLogError(e.errorMessage());
            m_error_rows ++;
        }
    }

    return m_insert_rows;
}
/*
const int crmImageDefBackup::bcpout(const char* filename)
{
    return 0;
}
*/
