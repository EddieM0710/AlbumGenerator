/////////////////////////////////////////////////////////////////////////////
// Name:        ManageCatalogData.cpp
// Purpose:     
// Author:      Eddie Monroe
// Modified by: 
// Created:     Sat 22 Jan 2022 13:01:18 CST
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), Sat 22 Jan 2022 13:01:18 CST

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "StampTreeCtrl.h"
#include "wx/imaglist.h"
////@end includes

#include "ManageCatalogData.h"

////@begin XPM images
////@end XPM images


/*
 * ManageCatalogData type definition
 */

IMPLEMENT_DYNAMIC_CLASS( ManageCatalogData, wxPanel )


/*
 * ManageCatalogData event table definition
 */

BEGIN_EVENT_TABLE( ManageCatalogData, wxPanel )

////@begin ManageCatalogData event table entries
    EVT_TEXT( ID_TEXTCTRL, ManageCatalogData::OnTextctrlTextUpdated )
////@end ManageCatalogData event table entries

END_EVENT_TABLE()


/*
 * ManageCatalogData constructors
 */

ManageCatalogData::ManageCatalogData()
{
    Init();
}

ManageCatalogData::ManageCatalogData( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, pos, size, style);
}


/*
 * ManageCatalogData creator
 */

bool ManageCatalogData::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ManageCatalogData creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY);
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end ManageCatalogData creation
    return true;
}


/*
 * ManageCatalogData destructor
 */

ManageCatalogData::~ManageCatalogData()
{
////@begin ManageCatalogData destruction
////@end ManageCatalogData destruction
}


/*
 * Member initialisation
 */

void ManageCatalogData::Init()
{
////@begin ManageCatalogData member initialisation
    m_title = NULL;
    m_listTree = NULL;
////@end ManageCatalogData member initialisation
}


/*
 * Control creation for ManageCatalogData
 */

void ManageCatalogData::CreateControls()
{    
////@begin ManageCatalogData content construction
    // Generated by DialogBlocks, Sat 22 Jan 2022 13:14:49 CST (unregistered)

    ManageCatalogData* itemPanel1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemPanel1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer1, 0, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText2 = new wxStaticText( itemPanel1, wxID_STATIC, _("Title"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer1->Add(itemStaticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_title = new wxTextCtrl( itemPanel1, ID_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer1->Add(m_title, 0, wxGROW|wxALL, 0);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 2, wxGROW|wxALL, 0);

    m_listTree = new StampTreeCtrl( itemPanel1, ID_TREECTRL, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS |wxTR_FULL_ROW_HIGHLIGHT|wxTR_SINGLE|wxSUNKEN_BORDER|wxTR_DEFAULT_STYLE );
    itemBoxSizer3->Add(m_listTree, 2, wxGROW|wxALL, 0);

////@end ManageCatalogData content construction
}


/*
 * Should we show tooltips?
 */

bool ManageCatalogData::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap ManageCatalogData::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin ManageCatalogData bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end ManageCatalogData bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon ManageCatalogData::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin ManageCatalogData icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end ManageCatalogData icon retrieval
}


/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
 */

void ManageCatalogData::OnTextctrlTextUpdated( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL in ManageCatalogData.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL in ManageCatalogData. 
}


void ManageCatalogData::SetStamp( Stamp* stamp )
{
    m_stamp = stamp;
//    SetGallery( );
}

void ManageCatalogData::UpdateStatus( )
{
}

void ManageCatalogData::LoadCatalogTree( )
{
    m_listTree->LoadTree( );
}

void ManageCatalogData::ClearCatalogTree( )
{
    m_listTree->DeleteAllItems( );
}
