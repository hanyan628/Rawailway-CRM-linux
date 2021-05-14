#ifndef TESTDIALOG_H
#define TESTDIALOG_H

//(*Headers(testDialog)
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/bmpcbox.h>
//*)
#include <wx/imaglist.h>

class testDialog: public wxDialog
{
	public:

		testDialog(wxWindow* parent, wxImageList* imgs);
		virtual ~testDialog();

		//(*Declarations(testDialog)
		wxBitmapComboBox* ComboBox1;
		wxButton* Button2;
		wxStaticLine* StaticLine1;
		//*)

	protected:

		//(*Identifiers(testDialog)
		//*)

	private:
        wxImageList* m_image_list;
        void InitList();

		//(*Handlers(testDialog)
		//*)
		void OnComboBoxSelected(wxCommandEvent& event);

		DECLARE_EVENT_TABLE()
};

#endif
