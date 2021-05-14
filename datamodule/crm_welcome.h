#ifndef CRM_WELCOME_H_HEADER_INCLUDED
#define CRM_WELCOME_H_HEADER_INCLUDED

#include <vector>
#include "./crm_dataset.h"


class crmTrainDir
{
    friend crmTrainDir& theTrainDir();
    public:
        virtual ~crmTrainDir();
        void Init();
        void setRange(const char* _start,
                      const char* _end);
        const strucTrain* Get(const int row);
        const char* GetText(const int row);
        const int Find(const char* train_code);
        const int Count() { return m_data.size(); };
        const int Start() { return m_start; };
        const int End() { return m_end; };
    private:
        crmTrainDir():m_count(0),m_start(0),m_end(0) { Init(); };
    private:
        typedef std::vector< strucTrain > CRM_TRAIN_DIR;
        int m_count;
        int m_start;
        int m_end;
        CRM_TRAIN_DIR m_data;
        std::string buffer;
};

inline crmTrainDir& theTrainDir()
{
    static crmTrainDir p;
    return p;
}

class crmWelcomeDisplay
{
    friend crmWelcomeDisplay& theWelcomeDisplay();
    public:
        virtual ~crmWelcomeDisplay();
        void Refresh(const char* start="00:00",
                     const char* end="23:59");
        bool setRow(const int row);
        const char* getTrainInfo() { return theTrainDir().GetText(m_current_row); };
        const int getPeopleCount(const char* train_date);
        const int Count();
    private:
        crmWelcomeDisplay() {};
        int m_current_row;
};

inline crmWelcomeDisplay& theWelcomeDisplay()
{
    static crmWelcomeDisplay p;
    return p;
}


#endif
