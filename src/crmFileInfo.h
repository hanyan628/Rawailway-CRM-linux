#ifndef CRMFILEINFO_H
#define CRMFILEINFO_H

#include <wx/filename.h>
#include <wx/image.h>

class crmFileInfo
{
    public:
        crmFileInfo(const wxString filename) :m_file_info(filename) {};
        virtual ~crmFileInfo() {};

        wxString    GetPath()
        {
            return m_file_info.GetFullPath();
        };

        wxString    GetExt()
        {
            return m_file_info.GetExt();
        };

        wxString    GetFullName()
        {
            return m_file_info.GetFullName();
        };

        wxString    GetName()
        {
            return m_file_info.GetName();
        };

        long        GetSize()
        {
            return m_file_info.GetSize().ToULong();
        };

        bool        IsExists()
        {
            return m_file_info.FileExists();
        }

        wxBitmapType    GetImageType();

        static wxBitmapType getImageType(const wxString fType);

    protected:
    private:
        wxFileName  m_file_info;
};

#endif // CRMFILEINFO_H
