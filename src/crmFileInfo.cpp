#include "crmFileInfo.h"

wxBitmapType crmFileInfo::GetImageType()
{
    wxString fileExt = GetExt();
    fileExt.Trim();
    fileExt.MakeLower();

    if ( fileExt.Cmp(wxT("png")) == 0 )
        return wxBITMAP_TYPE_PNG;

    if ( fileExt.Cmp(wxT("bmp")) == 0 )
        return wxBITMAP_TYPE_BMP;

    if ( fileExt.Cmp(wxT("jpg")) == 0 )
        return wxBITMAP_TYPE_JPEG;

    if ( fileExt.Cmp(wxT("ico")) == 0 )
        return wxBITMAP_TYPE_ICO;

    if ( fileExt.Cmp(wxT("gif")) == 0 )
        return wxBITMAP_TYPE_GIF;

    return wxBITMAP_TYPE_ANY;
}

wxBitmapType crmFileInfo::getImageType(const wxString fType)
{
    if ( fType.Cmp(wxT("png")) == 0 )
        return wxBITMAP_TYPE_PNG;

    if ( fType.Cmp(wxT("bmp")) == 0 )
        return wxBITMAP_TYPE_BMP;

    if ( fType.Cmp(wxT("jpg")) == 0 )
        return wxBITMAP_TYPE_JPEG;

    if ( fType.Cmp(wxT("ico")) == 0 )
        return wxBITMAP_TYPE_ICO;

    if ( fType.Cmp(wxT("gif")) == 0 )
        return wxBITMAP_TYPE_GIF;

    return wxBITMAP_TYPE_ANY;
}
