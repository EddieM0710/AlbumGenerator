/////////////////////////////////////////////////////////////////////////////
// Name:        GenerateListSettings.cpp
// Purpose:     
// Author:      Eddie Monroe
// Modified by: 
// Created:     Fri 09 Dec 2022 14:55:49 CST
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), Fri 09 Dec 2022 14:55:49 CST

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

#include "GenerateListSettings.h"
#include "catalog/CatalogDefs.h"

////@begin XPM images
////@end XPM images


/*
 * GenerateListSettings type definition
 */

IMPLEMENT_DYNAMIC_CLASS( GenerateListSettings, wxDialog )


/*
 * GenerateListSettings event table definition
 */

BEGIN_EVENT_TABLE( GenerateListSettings, wxDialog )

////@begin GenerateListSettings event table entries
    EVT_BUTTON( ID_STATUSALLBUTTON, GenerateListSettings::OnStatusAllButtonClick )
    EVT_BUTTON( IDSTATUSCLEARBUTTON, GenerateListSettings::OnStatusClearButtonClick )
    EVT_BUTTON( ID_EMISSIONALLBUTTON, GenerateListSettings::OnEmissionAllButtonClick )
    EVT_BUTTON( ID_EMISSIONCLEARBUTTON, GenerateListSettings::OnEmissionClearButtonClick )
    EVT_BUTTON( ID_FORMATCLEARBUTTON, GenerateListSettings::OnFormatClearButtonClick )
    EVT_BUTTON( ID_CLEARYEARRANGEBUTTON, GenerateListSettings::OnClearYearRangeButtonClick )
    EVT_BUTTON( wxID_OK, GenerateListSettings::OnOkClick )
////@end GenerateListSettings event table entries

END_EVENT_TABLE()


/*
 * GenerateListSettings constructors
 */

GenerateListSettings::GenerateListSettings()
{
    Init();
}

GenerateListSettings::GenerateListSettings( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * GenerateListSettings creator
 */

bool GenerateListSettings::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin GenerateListSettings creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end GenerateListSettings creation
    return true;
}


/*
 * GenerateListSettings destructor
 */

GenerateListSettings::~GenerateListSettings()
{
////@begin GenerateListSettings destruction
////@end GenerateListSettings destruction
}


/*
 * Member initialisation
 */

void GenerateListSettings::Init()
{
////@begin GenerateListSettings member initialisation
    m_statusListCtrl = NULL;
    m_emissionListCtrl = NULL;
    m_formatListCtrl = NULL;
    m_fromYear = NULL;
    m_toYear = NULL;
////@end GenerateListSettings member initialisation
    for ( int i = 0; i < Catalog::ET_NbrTypes; i++ ) 
    {
        m_emissionListCtrlStrings.Add( _( Catalog::ET_EmissionStrings[ i ] ) );
    }    

    for ( int i = 0; i < Catalog::FT_NbrTypes; i++ ) 
    {
        m_formatListCtrlStrings.Add( _( Catalog::FT_FormatStrings[ i ] ) );
    }

    for ( int i = 0; i < Catalog::ST_NbrInventoryStatusTypes; i++ ) 
    {
        m_statusListCtrlStrings.Add( _( Catalog::ST_InventoryStatusStrings[ i ] ) );
    }
}


/*
 * Control creation for GenerateListSettings
 */

void GenerateListSettings::CreateControls()
{    
////@begin GenerateListSettings content construction
    // Generated by DialogBlocks, Fri 09 Dec 2022 17:56:58 CST (unregistered)

    GenerateListSettings* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer8->Add(itemBoxSizer9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer9->Add(itemBoxSizer1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText2 = new wxStaticText( itemDialog1, wxID_STATIC, _("Inventory"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer1->Add(itemStaticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton3 = new wxButton( itemDialog1, ID_STATUSALLBUTTON, _("All"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    itemBoxSizer1->Add(itemButton3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton4 = new wxButton( itemDialog1, IDSTATUSCLEARBUTTON, _("Clear"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    itemBoxSizer1->Add(itemButton4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_statusListCtrl = new wxCheckListBox( itemDialog1, ID_CHECKLISTBOX, wxDefaultPosition, wxSize(-1, 100), m_statusListCtrlStrings, wxLB_MULTIPLE|wxLB_HSCROLL );
    itemBoxSizer9->Add(m_statusListCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer8->Add(itemBoxSizer12, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer12->Add(itemBoxSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemDialog1, wxID_STATIC, _("Emission"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemStaticText7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton8 = new wxButton( itemDialog1, ID_EMISSIONALLBUTTON, _("All"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    itemBoxSizer6->Add(itemButton8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton9 = new wxButton( itemDialog1, ID_EMISSIONCLEARBUTTON, _("Clear"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    itemBoxSizer6->Add(itemButton9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);



    m_emissionListCtrl = new wxCheckListBox( itemDialog1, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(-1, 100), m_emissionListCtrlStrings, wxLB_MULTIPLE|wxLB_HSCROLL );
    itemBoxSizer12->Add(m_emissionListCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer8->Add(itemBoxSizer15, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer15->Add(itemBoxSizer11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText12 = new wxStaticText( itemDialog1, wxID_STATIC, _("Format"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer11->Add(itemStaticText12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton13 = new wxButton( itemDialog1, ID_FORMATALLBUTTON, _("All"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    itemBoxSizer11->Add(itemButton13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton14 = new wxButton( itemDialog1, ID_FORMATCLEARBUTTON, _("Clear"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    itemBoxSizer11->Add(itemButton14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_formatListCtrl = new wxCheckListBox( itemDialog1, ID_CHECKLISTBOX2, wxDefaultPosition, wxSize(-1, 100), m_formatListCtrlStrings, wxLB_MULTIPLE|wxLB_HSCROLL );
    itemBoxSizer15->Add(m_formatListCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer16, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticText* itemStaticText17 = new wxStaticText( itemDialog1, wxID_STATIC, _("Issue year Range:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer16->Add(itemStaticText17, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText18 = new wxStaticText( itemDialog1, wxID_STATIC, _("from"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer16->Add(itemStaticText18, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_fromYear = new wxTextCtrl( itemDialog1, ID_FROMYEARTEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer16->Add(m_fromYear, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText20 = new wxStaticText( itemDialog1, wxID_STATIC, _("to"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer16->Add(itemStaticText20, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_toYear = new wxTextCtrl( itemDialog1, ID_TOYEARTEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer16->Add(m_toYear, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton22 = new wxButton( itemDialog1, ID_CLEARYEARRANGEBUTTON, _("Clear"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    itemBoxSizer16->Add(itemButton22, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer23, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton24 = new wxButton( itemDialog1, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer23->Add(itemButton24, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end GenerateListSettings content construction
}


/*
 * Should we show tooltips?
 */

bool GenerateListSettings::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap GenerateListSettings::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin GenerateListSettings bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end GenerateListSettings bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon GenerateListSettings::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin GenerateListSettings icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end GenerateListSettings icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_STATUSALLBUTTON
 */

void GenerateListSettings::OnStatusAllButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_STATUSALLBUTTON in GenerateListSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_STATUSALLBUTTON in GenerateListSettings. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for IDSTATUSCLEARBUTTON
 */

void GenerateListSettings::OnStatusClearButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for IDSTATUSCLEARBUTTON in GenerateListSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for IDSTATUSCLEARBUTTON in GenerateListSettings. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EMISSIONALLBUTTON
 */

void GenerateListSettings::OnEmissionAllButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EMISSIONALLBUTTON in GenerateListSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EMISSIONALLBUTTON in GenerateListSettings. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EMISSIONCLEARBUTTON
 */

void GenerateListSettings::OnEmissionClearButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EMISSIONCLEARBUTTON in GenerateListSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EMISSIONCLEARBUTTON in GenerateListSettings. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FORMATCLEARBUTTON
 */

void GenerateListSettings::OnFormatClearButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FORMATCLEARBUTTON in GenerateListSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FORMATCLEARBUTTON in GenerateListSettings. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CLEARYEARRANGEBUTTON
 */

void GenerateListSettings::OnClearYearRangeButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CLEARYEARRANGEBUTTON in GenerateListSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CLEARYEARRANGEBUTTON in GenerateListSettings. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void GenerateListSettings::OnOkClick( wxCommandEvent& event )
{



////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in GenerateListSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in GenerateListSettings. 
}

int GenerateListSettings::MakeBitPatern( wxArrayInt& array )
{
    int nbr = array.Count();
    int val = 0;
    for ( int i = 0; i < nbr; i++ )
    {
        int base = 1;
        base = base<<=array[i];
        val = val | base ;
    }
    return val;
}

int GenerateListSettings::GetCheckedStatusItems( )
{
    wxArrayInt checkedStatusItems;
    m_statusListCtrl->GetCheckedItems(checkedStatusItems);
    return MakeBitPatern( checkedStatusItems);
}

int GenerateListSettings::GetCheckedFormatItems(  )
{
    wxArrayInt checkedFormatItems;
    m_formatListCtrl->GetCheckedItems(checkedFormatItems);
    return MakeBitPatern( checkedFormatItems);
}

int GenerateListSettings::GetCheckedEmissionItems( )
{
     wxArrayInt checkedEmissionItems;
    m_emissionListCtrl->GetCheckedItems(checkedEmissionItems);
    return MakeBitPatern( checkedEmissionItems);  
}

void GenerateListSettings::SetCheckedEmissionItems( int checkedEmissionItems )
{
    int base = 1;
    for ( int i = 0; i < Catalog::ET_NbrTypes; i++ ) 
    {

        if ( checkedEmissionItems & base )
        {
            m_emissionListCtrl->Check(i);
        }
        base = base<<=1;
    }   
}


void GenerateListSettings::SetCheckedFormatItems( int checkedFormatItems )
{
    int base = 1;
    for ( int i = 0; i < Catalog::FT_NbrTypes; i++ ) 
    {
        if ( checkedFormatItems & base )
        {
            m_formatListCtrl->Check(i);
        }
        base = base<<=1;
    }   
}

void GenerateListSettings::SetCheckedStatusItems( int checkedStatusItems )
{
    int base = 1;
    for ( int i = 0; i < Catalog::FT_NbrTypes; i++ ) 
    {
        if ( checkedStatusItems & base )
        {
            m_statusListCtrl->Check(i);
        }
        base = base<<=1;
    }      
}
