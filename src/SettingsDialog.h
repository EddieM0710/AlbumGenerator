/////////////////////////////////////////////////////////////////////////////
// Name:        SettingsDialog.h
// Purpose:     
// Author:      Eddie Monroe
// Modified by: 
// Created:     Wed 12 Jan 2022 07:42:21 CST
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), Wed 12 Jan 2022 07:42:21 CST

#ifndef _SETTINGSDIALOG_H_
#define _SETTINGSDIALOG_H_


/*!
 * Includes
 */

////@begin includes
////@end includes

#include "Defs.h"
/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
//#define ID_SETTINGSDIALOG 10000
#define ID_IMAGEDIRECTORTEXTBOX 11001
#define ID_WORKINGDIRECTORYTEXTBOX 11002
#define ID_COUNTRYTEXTBOX 11003
#define ID_CATALOGTEXTBOX 11004
#define ID_OPENLASTCHECKBOX 11005
#define ID_RECENTSIZETEXTCTRL 10001
#define SYMBOL_SETTINGSDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_SETTINGSDIALOG_TITLE _("SettingsDialog")
#define SYMBOL_SETTINGSDIALOG_IDNAME ID_SETTINGSDIALOG
#define SYMBOL_SETTINGSDIALOG_SIZE wxSize(600, 300)
#define SYMBOL_SETTINGSDIALOG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * SettingsDialog class declaration
 */

class SettingsDialog: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( SettingsDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    SettingsDialog();
    SettingsDialog( wxWindow* parent, wxWindowID id = SYMBOL_SETTINGSDIALOG_IDNAME, const wxString& caption = SYMBOL_SETTINGSDIALOG_TITLE, const wxPoint& pos = SYMBOL_SETTINGSDIALOG_POSITION, const wxSize& size = SYMBOL_SETTINGSDIALOG_SIZE, long style = SYMBOL_SETTINGSDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_SETTINGSDIALOG_IDNAME, const wxString& caption = SYMBOL_SETTINGSDIALOG_TITLE, const wxPoint& pos = SYMBOL_SETTINGSDIALOG_POSITION, const wxSize& size = SYMBOL_SETTINGSDIALOG_SIZE, long style = SYMBOL_SETTINGSDIALOG_STYLE );

    /// Destructor
    ~SettingsDialog();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin SettingsDialog event handler declarations

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_IMAGEDIRECTORTEXTBOX
    void OnImagedirectortextboxTextUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_WORKINGDIRECTORYTEXTBOX
    void OnWorkingdirectorytextboxTextUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_COUNTRYTEXTBOX
    void OnCountrytextboxTextUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_CATALOGTEXTBOX
    void OnCatalogtextboxTextUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_OPENLASTCHECKBOX
    void OnOpenlastcheckboxClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_RECENTSIZETEXTCTRL
    void OnRecentsizetextctrlTextUpdated( wxCommandEvent& event );

////@end SettingsDialog event handler declarations

    void OnOkClick( wxCommandEvent& event );

////@begin SettingsDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    wxIcon GetIconResource( const wxString& name );
    /// Retrieves Save( )
    /// Should we show tooltips?
    static bool ShowToolTips();

    bool IsDirty( ) { return m_dirty; };

    void UpdateSettings();

////@begin SettingsDialog member variables
    wxTextCtrl* m_imageDirectory;
    wxTextCtrl* m_workingDirectory;
    wxTextCtrl* m_country;
    wxTextCtrl* m_catalog;
    wxCheckBox* m_loadLastFileAtStartUp;
    wxTextCtrl* m_recentListSize;
////@end SettingsDialog member variables
    bool m_dirty;

};

#endif
    // _SETTINGSDIALOG_H_
