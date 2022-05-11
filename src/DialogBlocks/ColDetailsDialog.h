/////////////////////////////////////////////////////////////////////////////
// Name:        RowDetailsDialog.h
// Purpose:     
// Author:      Eddie Monroe
// Modified by: 
// Created:     Fri 29 Apr 2022 17:39:37 CDT
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), Fri 29 Apr 2022 17:39:37 CDT

#ifndef _ROWDETAILSDIALOG_H_
#define _ROWDETAILSDIALOG_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/listctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class LabeledTextBox;
class wxListCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_ROWDETAILSDIALOG 10000
#define ID_NAMELABELEDTEXTBOX 10009
#define ID_TITLECHECKBOX 10004
#define ID_FRAMECHECKBOX 10006
#define ID_LISTCTRL 10006
#define SYMBOL_ROWDETAILSDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_ROWDETAILSDIALOG_TITLE _("Row Details Dialog")
#define SYMBOL_ROWDETAILSDIALOG_IDNAME ID_ROWDETAILSDIALOG
#define SYMBOL_ROWDETAILSDIALOG_SIZE wxSize(400, 300)
#define SYMBOL_ROWDETAILSDIALOG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * RowDetailsDialog class declaration
 */

class RowDetailsDialog: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( RowDetailsDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    RowDetailsDialog();
    RowDetailsDialog( wxWindow* parent, wxWindowID id = SYMBOL_ROWDETAILSDIALOG_IDNAME, const wxString& caption = SYMBOL_ROWDETAILSDIALOG_TITLE, const wxPoint& pos = SYMBOL_ROWDETAILSDIALOG_POSITION, const wxSize& size = SYMBOL_ROWDETAILSDIALOG_SIZE, long style = SYMBOL_ROWDETAILSDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ROWDETAILSDIALOG_IDNAME, const wxString& caption = SYMBOL_ROWDETAILSDIALOG_TITLE, const wxPoint& pos = SYMBOL_ROWDETAILSDIALOG_POSITION, const wxSize& size = SYMBOL_ROWDETAILSDIALOG_SIZE, long style = SYMBOL_ROWDETAILSDIALOG_STYLE );

    /// Destructor
    ~RowDetailsDialog();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin RowDetailsDialog event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

////@end RowDetailsDialog event handler declarations

////@begin RowDetailsDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end RowDetailsDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin RowDetailsDialog member variables
    LabeledTextBox* m_name;
    wxCheckBox* m_titleCheckbox;
    wxCheckBox* m_frameCheckbox;
    wxListCtrl* m_statusList;
////@end RowDetailsDialog member variables
};

#endif
    // _ROWDETAILSDIALOG_H_
