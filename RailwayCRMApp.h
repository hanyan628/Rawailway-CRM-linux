/***************************************************************
 * Name:      RailwayCRMApp.h
 * Purpose:   Defines Application Class
 * Author:    Hyan (hanyan@public.wh.hb.cn)
 * Created:   2010-11-22
 * Copyright: Hyan (http://hyan.cn)
 * License:
 **************************************************************/

#ifndef RAILWAYCRMAPP_H
#define RAILWAYCRMAPP_H

#include <wx/app.h>
#include <wx/intl.h>
#include <wx/snglinst.h>

class RailwayCRMApp : public wxApp
{
public:
    virtual bool OnInit();
    virtual int OnExit();
private:
    wxLocale    m_local;
    void loadZH();
    wxSingleInstanceChecker* m_checker;
    bool IsSingleInstance();

#if defined(__WXGTK__)
    void InitGTK();
#endif
};

#endif // RAILWAYCRMAPP_H
