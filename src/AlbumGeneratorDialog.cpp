/////////////////////////////////////////////////////////////////////////////
// Name:        AbumGeneratorDialog.cpp
// Purpose:     
// Author:      Eddie Monroe
// Modified by: 
// Created:     Sun 16 Jan 2022 19:17:13 CST
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), Sun 16 Jan 2022 19:17:13 CST

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "AlbumGeneratorDialog.h"

////@begin XPM images
////@end XPM images


/*
 * AlbumGeneratorDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( AlbumGeneratorDialog, wxDialog )


/*
 * AlbumGeneratorDialog event table definition
 */

BEGIN_EVENT_TABLE( AlbumGeneratorDialog, wxDialog )

////@begin AlbumGeneratorDialog event table entries
    EVT_BUTTON( ID_BUTTON, AlbumGeneratorDialog::OnButtonClick )
////@end AlbumGeneratorDialog event table entries

END_EVENT_TABLE()


/*
 * AlbumGeneratorDialog constructors
 */

AlbumGeneratorDialog::AlbumGeneratorDialog()
{
    Init();
}

AlbumGeneratorDialog::AlbumGeneratorDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * AbumGeneratorDialog creator
 */

bool AlbumGeneratorDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin AlbumGeneratorDialog creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();

    if (FindWindow(ID_PRIMARYSPLITTERWINDOW))
        ((wxSplitterWindow*) FindWindow(ID_PRIMARYSPLITTERWINDOW))->SetSashPosition(100);
    if (FindWindow(ID_SECONDARYSPLITTERWINDOW))
        ((wxSplitterWindow*) FindWindow(ID_SECONDARYSPLITTERWINDOW))->SetSashPosition(100);
////@end AlbumGeneratorDialog creation
    return true;
}


/*
 * AlbumGeneratorDialog destructor
 */

AlbumGeneratorDialog::~AlbumGeneratorDialog()
{
////@begin AlbumGeneratorDialog destruction
////@end AlbumGeneratorDialog destruction
}


/*
 * Member initialisation
 */

void AlbumGeneratorDialog::Init()
{
////@begin AlbumGeneratorDialog member initialisation
    m_primarySplitterWindow = NULL;
    m_itemListBox = NULL;
    m_secondarySplitterWindow = NULL;
    m_AECommnands = NULL;
    m_richTextCtrl = NULL;
////@end AlbumGeneratorDialog member initialisation
}


/*
 * Control creation for AbumGeneratorDialog
 */

void AlbumGeneratorDialog::CreateControls()
{    
////@begin AlbumGeneratorDialog content construction
    // Generated by DialogBlocks, Sun 16 Jan 2022 20:04:24 CST (unregistered)

    AlbumGeneratorDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer1, 1, wxGROW, 5);

    m_primarySplitterWindow = new wxSplitterWindow( itemDialog1, ID_PRIMARYSPLITTERWINDOW, wxDefaultPosition, wxSize(100, 100), wxSP_3DBORDER|wxSP_3DSASH|wxNO_BORDER );
    m_primarySplitterWindow->SetMinimumPaneSize(0);

    wxArrayString m_itemListBoxStrings;
    m_itemListBox = new wxCheckListBox( m_primarySplitterWindow, ID_CHECKLISTBOX, wxDefaultPosition, wxDefaultSize, m_itemListBoxStrings, wxLB_SINGLE );

    m_secondarySplitterWindow = new wxSplitterWindow( m_primarySplitterWindow, ID_SECONDARYSPLITTERWINDOW, wxDefaultPosition, wxSize(100, 100), wxSP_3DBORDER|wxSP_3DSASH|wxNO_BORDER );
    m_secondarySplitterWindow->SetMinimumPaneSize(0);

    wxArrayString m_AECommnandsStrings;
    m_AECommnands = new wxListBox( m_secondarySplitterWindow, ID_AECMDLISTBOX, wxDefaultPosition, wxDefaultSize, m_AECommnandsStrings, wxLB_SINGLE );

    m_richTextCtrl = new wxTextCtrl( m_secondarySplitterWindow, ID_RICHTEXTTEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_RICH|wxTE_RICH2 );

    m_secondarySplitterWindow->SplitVertically(m_AECommnands, m_richTextCtrl, 100);
    m_primarySplitterWindow->SplitVertically(m_itemListBox, m_secondarySplitterWindow, 100);
    itemBoxSizer1->Add(m_primarySplitterWindow, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton4 = new wxButton( itemDialog1, ID_BUTTON, _("Generate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemButton4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton1 = new wxButton( itemDialog1, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemButton1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    // Connect events and objects
    m_itemListBox->Connect(ID_CHECKLISTBOX, wxEVT_RIGHT_UP, wxMouseEventHandler(AlbumGeneratorDialog::OnRightUp), NULL, this);
////@end AlbumGeneratorDialog content construction
}


/*
 * Should we show tooltips?
 */

bool AlbumGeneratorDialog::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap AlbumGeneratorDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin AlbumGeneratorDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end AlbumGeneratorDialog bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon AlbumGeneratorDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin AlbumGeneratorDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end AlbumGeneratorDialog icon retrieval
}


/*
 * wxEVT_RIGHT_UP event handler for ID_CHECKLISTBOX
 */

void AlbumGeneratorDialog::OnRightUp( wxMouseEvent& event )
{
////@begin wxEVT_RIGHT_UP event handler for ID_CHECKLISTBOX in AbumGeneratorDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_RIGHT_UP event handler for ID_CHECKLISTBOX in AbumGeneratorDialog. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void AlbumGeneratorDialog::OnButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in AbumGeneratorDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in AbumGeneratorDialog. 
}

