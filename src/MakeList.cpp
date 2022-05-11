/////////////////////////////////////////////////////////////////////////////
// Name:        MakeList.cpp
// Purpose:     
// Author:      Eddie Monroe
// Modified by: 
// Created:     Fri 14 Jan 2022 16:16:51 CST
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), Fri 14 Jan 2022 16:16:51 CST

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

#include "MakeList.h"

////@begin XPM images
////@end XPM images
#include "Defs.h"

/*
 * MakeList type definition
 */

IMPLEMENT_DYNAMIC_CLASS( MakeList, wxDialog )


/*
 * MakeList event table definition
 */

BEGIN_EVENT_TABLE( MakeList, wxDialog )

////@begin MakeList event table entries
////@end MakeList event table entries

END_EVENT_TABLE()


/*
 * MakeList constructors
 */

MakeList::MakeList()
{
    Init();
}

MakeList::MakeList( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * MakeList creator
 */

bool MakeList::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin MakeList creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();
////@end MakeList creation
    return true;
}


/*
 * MakeList destructor
 */

MakeList::~MakeList()
{
////@begin MakeList destruction
////@end MakeList destruction
}


/*
 * Member initialisation
 */

void MakeList::Init()
{
////@begin MakeList member initialisation
    m_scrolledWindow = NULL;
    m_rangeBoxSizer = NULL;
    m_yearCheckBox = NULL;
    m_fromYearTextCtrl = NULL;
    m_toTextCtrl = NULL;
    m_emissionBoxSizer = NULL;
    m_emissionCheckBox = NULL;
    m_formatBoxSizer = NULL;
    m_formatCheckBox = NULL;
    m_themeBoxSizer = NULL;
    m_themeCheckBox = NULL;
    m_themeTextCtrl = NULL;
////@end MakeList member initialisation
}


/*
 * Control creation for MakeList
 */

void MakeList::CreateControls()
{    
////@begin MakeList content construction
    // Generated by DialogBlocks, Sat 15 Jan 2022 18:32:58 CST (unregistered)

    MakeList* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer1, 1, wxGROW|wxALL, 5);

    m_scrolledWindow = new wxScrolledWindow( itemDialog1, ID_SCROLLEDWINDOW, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );
    itemBoxSizer1->Add(m_scrolledWindow, 1, wxGROW|wxALL, 5);
    m_scrolledWindow->SetScrollbars(1, 1, 0, 0);
    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    m_scrolledWindow->SetSizer(itemBoxSizer3);

    m_rangeBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(m_rangeBoxSizer, 0, wxGROW|wxALL, 5);
    m_yearCheckBox = new wxCheckBox( m_scrolledWindow, ID_YEARCHECKBOX, _("Year Range: "), wxDefaultPosition, wxDefaultSize, 0 );
    m_yearCheckBox->SetValue(false);
    m_rangeBoxSizer->Add(m_yearCheckBox, 1, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( m_scrolledWindow, wxID_STATIC, _("from"), wxDefaultPosition, wxDefaultSize, 0 );
    m_rangeBoxSizer->Add(itemStaticText6, 0, wxGROW|wxALL, 5);

    m_fromYearTextCtrl = new wxTextCtrl( m_scrolledWindow, ID_FROMTEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_rangeBoxSizer->Add(m_fromYearTextCtrl, 1, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText8 = new wxStaticText( m_scrolledWindow, wxID_STATIC, _("to"), wxDefaultPosition, wxDefaultSize, 0 );
    m_rangeBoxSizer->Add(itemStaticText8, 0, wxGROW|wxALL, 5);

    m_toTextCtrl = new wxTextCtrl( m_scrolledWindow, ID_TOTEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_rangeBoxSizer->Add(m_toTextCtrl, 1, wxGROW|wxALL, 5);

    m_emissionBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(m_emissionBoxSizer, 0, wxGROW|wxALL, 5);
    m_emissionCheckBox = new wxCheckBox( m_scrolledWindow, ID_EMISSIONCHECKBOX, _("Emission"), wxDefaultPosition, wxDefaultSize, 0 );
    m_emissionCheckBox->SetValue(false);
    m_emissionBoxSizer->Add(m_emissionCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_formatBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(m_formatBoxSizer, 0, wxGROW|wxALL, 5);
    m_formatCheckBox = new wxCheckBox( m_scrolledWindow, ID_FORMATCHECKBOX, _("Format"), wxDefaultPosition, wxDefaultSize, 0 );
    m_formatCheckBox->SetValue(false);
    m_formatBoxSizer->Add(m_formatCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_themeBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(m_themeBoxSizer, 0, wxGROW|wxALL, 5);
    m_themeCheckBox = new wxCheckBox( m_scrolledWindow, ID_THEMECHECKBOX, _("Theme"), wxDefaultPosition, wxDefaultSize, 0 );
    m_themeCheckBox->SetValue(false);
    m_themeBoxSizer->Add(m_themeCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_themeTextCtrl = new wxTextCtrl( m_scrolledWindow, ID_THEMETEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_themeBoxSizer->Add(m_themeTextCtrl, 1, wxGROW|wxALL, 5);

    m_scrolledWindow->FitInside();

////@end MakeList content construction
    AddFormatRadioGroup();
    AddEmissionRadioGroup();
    m_scrolledWindow->FitInside();

}

void MakeList::DefineRadioButton( wxRadioButton* rb, int ID, wxString name, wxGridSizer* gridSizer )
{
    rb = new wxRadioButton( m_scrolledWindow, ID, name, wxDefaultPosition, wxDefaultSize, 0 );
    rb->SetValue(false);
    gridSizer->Add(rb, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);
}

void MakeList::AddFormatRadioGroup()
{
    wxGridSizer* m_formatGridSizer = new wxGridSizer(0, 3, 0, 0);
    m_formatBoxSizer->Add(m_formatGridSizer, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    
    DefineRadioButton( m_unknown, 11000+FT_FormatUnknown, FT_FormatStrings[FT_FormatUnknown], m_formatGridSizer );
    DefineRadioButton( m_stamp, 11000+FT_Stamp, FT_FormatStrings[FT_Stamp], m_formatGridSizer );
    DefineRadioButton( m_setenant, 11000+FT_Se_tenant, FT_FormatStrings[FT_Se_tenant], m_formatGridSizer );
    DefineRadioButton( m_miniSheet, 11000+FT_Mini_Sheet, FT_FormatStrings[FT_Mini_Sheet], m_formatGridSizer );
    DefineRadioButton( m_souvenirSheet, 11000+FT_Souvenir_Sheet, FT_FormatStrings[FT_Souvenir_Sheet], m_formatGridSizer );
    DefineRadioButton( m_booklet, 11000+FT_Booklet, FT_FormatStrings[FT_Booklet], m_formatGridSizer );
    DefineRadioButton( m_bookletPane, 11000+FT_Booklet_Pane, FT_FormatStrings[FT_Booklet_Pane], m_formatGridSizer );
    DefineRadioButton( m_gutterPair, 11000+FT_Gutter_Pair, FT_FormatStrings[FT_Gutter_Pair], m_formatGridSizer );
    DefineRadioButton( m_stampWithAttachedLabel, 11000+FT_Stamp_with_Attached_Label, FT_FormatStrings[FT_Stamp_with_Attached_Label], m_formatGridSizer );
    DefineRadioButton( m_teteBeche, 11000+FT_Tete_Beche, FT_FormatStrings[FT_Tete_Beche], m_formatGridSizer );

}

void MakeList::AddEmissionRadioGroup()
{
    wxGridSizer* m_emissionGridSizer = new wxGridSizer(0, 3, 0, 0);
    m_formatBoxSizer->Add(m_emissionGridSizer, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    
    DefineRadioButton( m_commemorative, 12000+ET_Commemorative, ET_EmissionStrings[ET_Commemorative], m_emissionGridSizer );
    DefineRadioButton( m_definitive, 12000+ET_Definitive, ET_EmissionStrings[ET_Definitive], m_emissionGridSizer );
    DefineRadioButton( m_huntingPermit, 12000+ET_HuntingPermit, ET_EmissionStrings[ET_HuntingPermit], m_emissionGridSizer );
    DefineRadioButton( m_revenue, 12000+ET_Revenue, ET_EmissionStrings[ET_Revenue], m_emissionGridSizer );
    DefineRadioButton( m_airPost, 12000+ET_AirPost, ET_EmissionStrings[ET_AirPost], m_emissionGridSizer );
    DefineRadioButton( m_airPostOfficial, 12000+ET_AirPostOfficial, ET_EmissionStrings[ET_AirPostOfficial], m_emissionGridSizer );
    DefineRadioButton( m_airPostSemiPostal, 12000+ET_AirPostSemiPostal, ET_EmissionStrings[ET_AirPostSemiPostal], m_emissionGridSizer );
    DefineRadioButton( m_ATMlabels, 12000+ET_ATMlabels, ET_EmissionStrings[ET_ATMlabels], m_emissionGridSizer );
    DefineRadioButton( m_cinderella, 12000+ET_Cinderella, ET_EmissionStrings[ET_Cinderella], m_emissionGridSizer );
    DefineRadioButton( m_iIllegal, 12000+ET_Illegal, ET_EmissionStrings[ET_Illegal], m_emissionGridSizer );
    DefineRadioButton( m_insuredLetter, 12000+ET_InsuredLetter, ET_EmissionStrings[ET_InsuredLetter], m_emissionGridSizer );
    DefineRadioButton( m_military, 12000+ET_Military, ET_EmissionStrings[ET_Military], m_emissionGridSizer );
    DefineRadioButton( m_newspaper, 12000+ET_Newspaper, ET_EmissionStrings[ET_Newspaper], m_emissionGridSizer );
    DefineRadioButton( m_official, 12000+ET_Official, ET_EmissionStrings[ET_Official], m_emissionGridSizer );
    DefineRadioButton( m_parcelPost, 12000+ET_ParcelPost, ET_EmissionStrings[ET_ParcelPost], m_emissionGridSizer );
    DefineRadioButton( m_personalDelivery, 12000+ET_PersonalDelivery, ET_EmissionStrings[ET_PersonalDelivery], m_emissionGridSizer );
    DefineRadioButton( m_personalized, 12000+ET_Personalized, ET_EmissionStrings[ET_Personalized], m_emissionGridSizer );
    DefineRadioButton( m_postageDue, 12000+ET_PostageDue, ET_EmissionStrings[ET_PostageDue], m_emissionGridSizer );
    DefineRadioButton( m_postalTax, 12000+ET_PostalTax, ET_EmissionStrings[ET_PostalTax], m_emissionGridSizer );
    DefineRadioButton( m_precancelled, 12000+ET_Precancelled, ET_EmissionStrings[ET_Precancelled], m_emissionGridSizer );
    DefineRadioButton( m_private, 12000+ET_Private, ET_EmissionStrings[ET_Private], m_emissionGridSizer );
    DefineRadioButton( m_regional, 12000+ET_Regional, ET_EmissionStrings[ET_Regional], m_emissionGridSizer );
    DefineRadioButton( m_registration, 12000+ET_Registration, ET_EmissionStrings[ET_Registration], m_emissionGridSizer );
    DefineRadioButton( m_semiPostal, 12000+ET_SemiPostal, ET_EmissionStrings[ET_SemiPostal], m_emissionGridSizer );
    DefineRadioButton( m_warTax, 12000+ET_WarTax, ET_EmissionStrings[ET_WarTax], m_emissionGridSizer );

}
/*
 * Should we show tooltips?
 */

bool MakeList::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap MakeList::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin MakeList bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end MakeList bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon MakeList::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin MakeList icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end MakeList icon retrieval
}
