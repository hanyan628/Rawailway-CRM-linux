#include "./crm_welcome.h"
#include "../src/parameter.h"
#include <wx/log.h>

crmTrainDir::~crmTrainDir()
{
    m_data.clear();
}

void crmTrainDir::Init()
{
    if ( !m_data.empty() )
    {
        m_data.clear();
    }

    try
    {
        CppSQLite3Buffer szSQL;
        if ( atoi(theParameter().Get("welcome","show_arrive_train")) )
        {
            szSQL.format("SELECT id FROM crm_train_dir ORDER BY start_time;");
        }
        else
        {
            szSQL.format("SELECT id FROM crm_train_dir "
                         "WHERE end_station_name<>%Q "
                         "ORDER BY start_time;",
                         theParameter().Get("welcome","my_station"));
        }

        crmTrainDef ds;
        CppSQLite3Table* tbl = ds.GetTable(szSQL);
        for(int i=0; i<tbl->numRows(); ++i)
        {
            tbl->setRow(i);
            strucTrain train = *((strucTrain*)ds.getData(tbl->getIntField(0)));
            m_data.push_back(train);
        }
    }
    catch(CppSQLite3Exception e)
    {
        wxLogError(e.errorMessage());
    }
}

const int crmTrainDir::Find(const char* train_code)
{
    for( int i=0; i<Count(); ++i )
    {
        if (m_data[i].train_code == train_code)
            return i;
    }
    return -1;
}

const char* crmTrainDir::GetText(const int row)
{
    if ( row<0 || row>=Count() )
    {
        return NULL;
    }
    buffer.clear();
    std::string strBuf = Get(row)->train_code;
    strBuf += std::string("          ");
    strBuf = strBuf.substr(0,10);
    buffer = strBuf + "["
            + Get(row)->start_station_name
            + " - "
            + Get(row)->end_station_name
            + "]";
    return buffer.c_str();
}

const strucTrain* crmTrainDir::Get(const int row)
{
    if ( row<0 || row>=Count() )
    {
        return NULL;
    }
    return &m_data[row];
}

void crmTrainDir::setRange(const char* _start, const char* _end)
{
    m_start = -1;
    m_end = -1;
    const std::string start = _start;
    const std::string end = _end;
    for(int i=0; i<Count(); ++i)
    {
        if ( m_start == -1 && m_data[i].start_time>=start )
        {
            m_start=i;
        }
        if ( m_end == -1 && m_data[i].start_time>=end )
        {
            m_end = i;
        }
    }
    if (m_start<0)
    {
        m_start = 0;
    }
    if (m_end<0)
    {
        m_end = Count() - 1;
    }
}


//*************************************************************************************
//class crmWelcomeDiaplay
//*************************************************************************************
crmWelcomeDisplay::~crmWelcomeDisplay()
{

}

bool crmWelcomeDisplay::setRow(const int row)
{
    m_current_row = row + theTrainDir().Start();
    if ( m_current_row >= theTrainDir().Count() )
    {
        m_current_row -= theTrainDir().Count();
    }
    return true;
}

void crmWelcomeDisplay::Refresh(const char* start /*="00:00"*/,
                                const char* end   /*="23:59"*/)
{
    theTrainDir().setRange(start,end);
}

const int crmWelcomeDisplay::getPeopleCount(const char* train_date)
{
    crmRecordDef ds;
    CppSQLite3Buffer szSQL;
    const strucTrain* tr = theTrainDir().Get(m_current_row);
    if (!tr)
    {
        return -1;
    }

    try
    {
        szSQL.format("SELECT SUM(people_count) FROM crm_welcome_record WHERE "
                     "train_date >= %Q AND train_code like '%s%%';",
                     train_date,
                     tr->train_code.c_str());
        CppSQLite3Table* tbl = ds.GetTable(szSQL);
        return tbl->getIntField(0);
    }
    catch(CppSQLite3Exception e)
    {
        wxLogError(e.errorMessage());
    }
    return -1;
}

const int crmWelcomeDisplay::Count()
{
    int ret = 0;
    if ( theTrainDir().Start() < theTrainDir().End() )
    {
        ret = theTrainDir().End() - theTrainDir().Start() + 1;
    }
    if ( theTrainDir().Start() > theTrainDir().End() )
    {
        ret = theTrainDir().Count() - ( theTrainDir().Start() - theTrainDir().End() );
    }
    return ret;
}
