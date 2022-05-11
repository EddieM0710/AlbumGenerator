/////////////////////////////////////////////////////////////////////////////
// Name:        IdentificationPanel.h
// Purpose:     
// Author:      Eddie Monroe
// Modified by: 
// Created:     Sat 23 Apr 2022 14:51:45 CDT
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), Sat 23 Apr 2022 14:51:45 CDT

#ifndef _IDENTIFICATIONPANEL_H_
#define _IDENTIFICATIONPANEL_H_


/*!
 * Includes
 */

////@begin includes
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class LabeledTextBox;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_IDENTIFICATIONPANEL 10000
#define ID_IDLABELEDTEXTBOX 10001
#define ID_STATUSCHOICE 10013
#define ID_NAMELABELEDTEXTBOX 10002
#define ID_EMISSIONCHOICE 10003
#define ID_FORMATCHOICE 10004
#define ID_ISSUEDTEXTBOX 10007
#define ID_SERIESTEXTBOX 10009
#define ID_THEMETEXTBOX 10010
#define ID_COUNTRYTEXTBOX 10011
#define SYMBOL_IDENTIFICATIONPANEL_STYLE wxTAB_TRAVERSAL
#define SYMBOL_IDENTIFICATIONPANEL_TITLE _("IdentificationPanel")
#define SYMBOL_IDENTIFICATIONPANEL_IDNAME ID_IDENTIFICATIONPANEL
#define SYMBOL_IDENTIFICATIONPANEL_SIZE wxDefaultSize
#define SYMBOL_IDENTIFICATIONPANEL_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * IdentificationPanel class declaration
 */

class IdentificationPanel: public wxPanel
{    
    DECLARE_DYNAMIC_CLASS( IdentificationPanel )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    IdentificationPanel();
    IdentificationPanel( wxWindow* parent, wxWindowID id = SYMBOL_IDENTIFICATIONPANEL_IDNAME, const wxPoint& pos = SYMBOL_IDENTIFICATIONPANEL_POSITION, const wxSize& size = SYMBOL_IDENTIFICATIONPANEL_SIZE, long style = SYMBOL_IDENTIFICATIONPANEL_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_IDENTIFICATIONPANEL_IDNAME, const wxPoint& pos = SYMBOL_IDENTIFICATIONPANEL_POSITION, const wxSize& size = SYMBOL_IDENTIFICATIONPANEL_SIZE, long style = SYMBOL_IDENTIFICATIONPANEL_STYLE );

    /// Destructor
    ~IdentificationPanel();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin IdentificationPanel event handler declarations
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_STATUSCHOICE
    void OnStatuschoiceSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_EMISSIONCHOICE
    void OnEmissionchoiceSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_FORMATCHOICE
    void OnFormatchoiceSelected( wxCommandEvent& event );

////@end IdentificationPanel event handler declarations

////@begin IdentificationPanel member function declarations
    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end IdentificationPanel member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin IdentificationPanel member variables
    LabeledTextBox* m_ID;
    wxChoice* m_status;
    LabeledTextBox* m_name;
    wxChoice* m_emission;
    wxChoice* m_format;
    LabeledTextBox* m_issueDate;
    LabeledTextBox* m_series;
    LabeledTextBox* m_themes;
    LabeledTextBox* m_country;
////@end IdentificationPanel member variables
};

#endif
    // _IDENTIFICATIONPANEL_H_
