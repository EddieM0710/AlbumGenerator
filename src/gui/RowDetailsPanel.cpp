/*
 * @file  RowDetailsPanel.cpp
 * @author Eddie Monroe
 * @brief
 * @version 0.1
 * @date 2022-04-29
 *
 * @copyright Copyright ( c ) 2022
 *
 * This file is part of StampTool.
 *
 * StampTool is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or any later version.
 *
 * StampTool is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * StampTool. If not, see <https://www.gnu.org/licenses/>.
 */


#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


#include "wx/imaglist.h"
#include "wx/notebook.h"

#include "gui/RowDetailsPanel.h"
#include "gui/LabeledTextBox.h"
#include "gui/FontPickerHelper.h"
#include "design/Row.h"
 //#include "design/DesignDefs.h"
#include "design/Album.h"
#include "utils/FontList.h"


 /*
  * RowDetailsPanel type definition
  */
IMPLEMENT_DYNAMIC_CLASS( RowDetailsPanel, HelperPanel )


/*
 * RowDetailsPanel event table definition
 */
    BEGIN_EVENT_TABLE( RowDetailsPanel, HelperPanel )
    EVT_RADIOBUTTON( ID_DEFAULTRADIOBUTTON, RowDetailsPanel::OnDefaultRadioButtonSelected )
    EVT_RADIOBUTTON( ID_TOPRADIOBUTTON, RowDetailsPanel::OnTopRadioButtonSelected )
    EVT_RADIOBUTTON( ID_BOTTOMRADIOBUTTON, RowDetailsPanel::OnBottomRadioButtonSelected )
    EVT_RADIOBUTTON( ID_CALCULATEDRADIOBUTTON, RowDetailsPanel::OnCalculatedClick )
    EVT_RADIOBUTTON( ID_FIXEDRADIOBUTTON, RowDetailsPanel::OnFixedClick )
    END_EVENT_TABLE( )
    ;

/*
 * RowDetailsPanel constructors
 */

RowDetailsPanel::RowDetailsPanel( )
{
    Init( );
}

RowDetailsPanel::RowDetailsPanel( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init( );
    Create( parent, id, caption, pos, size, style );
}


/*
 * RowDetailsPanel creator
 */

bool RowDetailsPanel::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    // RowDetailsPanel creation
    SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls( );
    if ( GetSizer( ) )
    {
        GetSizer( )->SetSizeHints( this );
    }
    Centre( );
    // RowDetailsPanel creation
    return true;
}



RowDetailsPanel::~RowDetailsPanel( )
{

}


void RowDetailsPanel::Init( )
{

    m_frameCheckbox = NULL;
    m_statusList = NULL;
}


void RowDetailsPanel::CreateControls( )
{
    RowDetailsPanel* theDialog = this;

    wxBoxSizer* detailsHorizontalSizer = new wxBoxSizer( wxHORIZONTAL );
    theDialog->SetSizer( detailsHorizontalSizer );

    wxBoxSizer* m_leftColumnVerticalSizer = new wxBoxSizer( wxVERTICAL );
    detailsHorizontalSizer->Add( m_leftColumnVerticalSizer, 1, wxGROW | wxALL, 0 );

    wxBoxSizer* m_rightColumnVerticalSizer = new wxBoxSizer( wxVERTICAL );
    detailsHorizontalSizer->Add( m_rightColumnVerticalSizer, 1, wxGROW | wxALL, 0 );

    wxBoxSizer* firstRowHorizontalSizer = new wxBoxSizer( wxHORIZONTAL );
    m_leftColumnVerticalSizer->Add( firstRowHorizontalSizer, 0, wxGROW | wxALL, 5 );

    m_frameCheckbox = new wxCheckBox( theDialog, ID_FRAMECHECKBOX, _( "Show Frame" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_frameCheckbox->SetValue( false );
    firstRowHorizontalSizer->Add( m_frameCheckbox, 0, wxLEFT | wxALL, 5 );

    int lastID = ID_LastID;


    m_titleHelper = SetupTitleHelper( theDialog, m_leftColumnVerticalSizer, lastID, DefaultTitleHelperStyle,
        wxCommandEventHandler( RowDetailsPanel::OnTitleCheckboxClick ),
        wxCommandEventHandler( RowDetailsPanel::OnTitleTextChanged ),
        wxCommandEventHandler( RowDetailsPanel::OnSubTitleCheckboxClick ),
        wxCommandEventHandler( RowDetailsPanel::OnSubTitleTextChanged ) );

    SetupFontPicker( theDialog, m_leftColumnVerticalSizer, lastID,
        _( "Title" ), _( "Default" ),
        m_titleFontPicker, m_titleColorPicker,
        wxFontPickerEventHandler( RowDetailsPanel::OnTitleFontPicker ),
        wxColourPickerEventHandler( RowDetailsPanel::OnTitleColorPicker ),
        wxCommandEventHandler( RowDetailsPanel::OnTitleDefaultClick ) );


    FontPicker* titleFontPicker = SetupFontPicker( theDialog, m_leftColumnVerticalSizer, lastID,
        _( "SubTitle" ), _( "Default" ),
        m_subTitleFontPicker, m_subTitleColorPicker,
        wxFontPickerEventHandler( RowDetailsPanel::OnSubTitleFontPicker ),
        wxColourPickerEventHandler( RowDetailsPanel::OnSubTitleColorPicker ),
        wxCommandEventHandler( RowDetailsPanel::OnSubTitleDefaultClick ) );



    m_TitleLocationBox = new wxStaticBox( theDialog, wxID_ANY, _( "Member Title Location" ) );
    m_titleLocationVSizer = new wxStaticBoxSizer( m_TitleLocationBox, wxVERTICAL );
    m_rightColumnVerticalSizer->Add( m_titleLocationVSizer, 0, wxGROW | wxALL, 5 );

    m_titleLocationHSizer = new wxBoxSizer( wxHORIZONTAL );
    m_titleLocationVSizer->Add( m_titleLocationHSizer, 0, wxGROW | wxALL, 0 );

    m_defaultButton = new wxRadioButton( m_titleLocationVSizer->GetStaticBox( ), ID_DEFAULTRADIOBUTTON, _( "Default" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_defaultButton->SetValue( false );
    m_titleLocationHSizer->Add( m_defaultButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

    m_topButton = new wxRadioButton( m_titleLocationVSizer->GetStaticBox( ), ID_TOPRADIOBUTTON, _( "Top" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_topButton->SetValue( true );
    m_titleLocationHSizer->Add( m_topButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

    m_bottomButton = new wxRadioButton( m_titleLocationVSizer->GetStaticBox( ), ID_BOTTOMRADIOBUTTON, _( "Bottom" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_bottomButton->SetValue( false );
    m_titleLocationHSizer->Add( m_bottomButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

    wxStaticBox* memberPositionStaticBox = new wxStaticBox( theDialog, wxID_ANY, _( "Member Position" ) );
    wxStaticBoxSizer* memberPositionStaticBoxSizer = new wxStaticBoxSizer( memberPositionStaticBox, wxHORIZONTAL );
    m_rightColumnVerticalSizer->Add( memberPositionStaticBoxSizer, 0, wxALIGN_TOP | wxALL, 5 );

    m_positionCalculated = new wxRadioButton( memberPositionStaticBoxSizer->GetStaticBox( ), ID_CALCULATEDRADIOBUTTON, _( "Calculated" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_positionCalculated->SetValue( true );
    m_positionCalculated->SetToolTip( _( "Evenly Distributed" ) );
    memberPositionStaticBoxSizer->Add( m_positionCalculated, 0, wxALIGN_LEFT | wxALL, 5 );

    memberPositionStaticBoxSizer->Add( 5, 5, 0, wxALIGN_LEFT | wxALL, 5 );


    m_positionFixed = new wxRadioButton( memberPositionStaticBoxSizer->GetStaticBox( ), ID_FIXEDRADIOBUTTON, _( "Fixed" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_positionFixed->SetValue( false );
    memberPositionStaticBoxSizer->Add( m_positionFixed, 0, wxALIGN_LEFT | wxALL, 5 );

    m_positionFixedSize = new wxTextCtrl( memberPositionStaticBoxSizer->GetStaticBox( ), ID_FIXEDSIZETEXTCTRL, _( "4" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_positionFixedSize->SetToolTip( _( "mm" ) );
    m_positionFixedSize->Enable( false );
    memberPositionStaticBoxSizer->Add( m_positionFixedSize, 0, wxALIGN_LEFT | wxALL, 5 );


    //>>error list ctrls
    wxBoxSizer* errorListSizer = new wxBoxSizer( wxHORIZONTAL );
    m_rightColumnVerticalSizer->Add( errorListSizer, 2, wxGROW | wxALL, 5 );

    wxArrayString m_statusListStrings;
    m_statusList = new wxListBox( theDialog, ID_LISTCTRL, wxDefaultPosition, wxDefaultSize, m_statusListStrings, wxLB_SINGLE );
    errorListSizer->Add( m_statusList, 2, wxGROW | wxALL, 0 );
    //<< error list ctrls

}
Design::TitleLocation  RowDetailsPanel::GetTitleLocationType( )
{
    return m_titleLocation;
}


void RowDetailsPanel::SetTitleLocation( )
{

    m_titleLocation = m_row->GetTitleLocationType( );
    if ( m_titleLocation == Design::AT_TitleLocationTop )
    {
        m_topButton->SetValue( true );
    }
    else if ( m_titleLocation == Design::AT_TitleLocationBottom )
    {
        m_bottomButton->SetValue( true );
    }

    else //if ( m_titleLocation == Design::AT_TitleLocationDefault )
    {
        m_defaultButton->SetValue( true );;
    }
}

void RowDetailsPanel::UpdateControls( )
{

    SetTitle( m_row->GetTitleString( ) );
    SetShowTitle( m_row->GetShowTitle( ) );
    SetShowSubTitle( m_row->GetShowSubTitle( ) );
    SetShowFrame( m_row->GetShowFrame( ) );
    SetColor( m_row->GetTitleFrame( )->GetColor( ) );
    SetTitleLocation( );
    SetCalculateSpacing( m_row->CalculateSpacing( ) );
    SetFixedSpacingSize( m_row->GetFixedSpacing( ) );

    wxListBox* m_statusList;
}


void RowDetailsPanel::SetupDialog( Design::Row* row )
{
    m_row = row;
    UpdateControls( );
    wxArrayString* errors = m_row->GetErrorArray( );


    if ( !errors->IsEmpty( ) )
    {
        m_statusList->InsertItems( *errors, 0 );
    }
};
bool RowDetailsPanel::GetShowTitle( ) {
    return m_titleHelper->titleCheckbox->IsChecked( );
};;
bool RowDetailsPanel::GetShowSubTitle( ) {
    return m_titleHelper->subTitleCheckbox->IsChecked( );

};;
bool RowDetailsPanel::GetShowFrame( ) {
    return m_frameCheckbox->IsChecked( );

};


void RowDetailsPanel::SetShowTitle( bool state ) {
    m_titleHelper->titleCheckbox->SetValue( state );
};
void RowDetailsPanel::SetShowSubTitle( bool state ) {
    m_titleHelper->subTitleCheckbox->SetValue( state );
};
void RowDetailsPanel::SetShowFrame( bool state ) {
    m_frameCheckbox->SetValue( state );
};

wxString RowDetailsPanel::GetTitle( ) {
    return m_titleHelper->titleLabel->GetValue( );
};


void RowDetailsPanel::SetTitle( wxString str ) {
    m_titleHelper->titleLabel->SetValue( str );
};


void RowDetailsPanel::SetFont( wxFont font )
{
    m_titleFontPicker->SetSelectedFont( font );
}

void RowDetailsPanel::SetColor( wxColour color )
{
    m_titleColorPicker->SetColour( color );
}

void RowDetailsPanel::SetCalculateSpacing( bool val )
{
    if ( val )
    {
        m_positionCalculated->SetValue( true );
        m_positionFixed->SetValue( false );
        m_positionFixedSize->Enable( false );
    }
    else
    {
        m_positionFixed->SetValue( true );
        m_positionCalculated->SetValue( false );
        m_positionFixedSize->Enable( true );

    }
};


void RowDetailsPanel::OnTopRadioButtonSelected( wxCommandEvent& event )
{
    m_titleLocation = Design::AT_TitleLocationTop;
    event.Skip( );
}

void RowDetailsPanel::OnBottomRadioButtonSelected( wxCommandEvent& event )
{
    m_titleLocation = Design::AT_TitleLocationBottom;
    event.Skip( );
}



void RowDetailsPanel::OnDefaultRadioButtonSelected( wxCommandEvent& event )
{
    m_titleLocation = Design::AT_TitleLocationDefault;
    event.Skip( );
}


void RowDetailsPanel::OnCalculatedClick( wxCommandEvent& event )
{
    m_positionFixedSize->Enable( false );
    event.Skip( );
}
void RowDetailsPanel::OnFixedClick( wxCommandEvent& event )
{
    m_positionFixedSize->Enable( true );
    event.Skip( );
}



void RowDetailsPanel::OnTitleTextChanged( wxCommandEvent& event )
{
}
void RowDetailsPanel::OnSubTitleTextChanged( wxCommandEvent& event )
{
}


void RowDetailsPanel::OnTitleFontPicker( wxFontPickerEvent& event )
{
}
void RowDetailsPanel::OnTitleColorPicker( wxColourPickerEvent& event )
{
}

void RowDetailsPanel::OnSubTitleFontPicker( wxFontPickerEvent& event )
{
}
void RowDetailsPanel::OnSubTitleColorPicker( wxColourPickerEvent& event )
{
}
void RowDetailsPanel::OnTitleDefaultClick( wxCommandEvent& event )
{
    int ndx = Design::GetAlbum( )->GetFontNdx( Design::AT_TitleFontType );
    Utils::FontList* fontList = GetFontList( );
    wxFont font = fontList->GetFont( ndx );
    wxColour color = fontList->GetColor( ndx );
    m_titleFontPicker->SetSelectedFont( font );
    m_titleColorPicker->SetColour( color );
    event.Skip( );
}



void RowDetailsPanel::OnSubTitleDefaultClick( wxCommandEvent& event )
{
    int ndx = Design::GetAlbum( )->GetFontNdx( Design::AT_SubTitleFontType );
    Utils::FontList* fontList = GetFontList( );
    wxFont font = fontList->GetFont( ndx );
    wxColour color = fontList->GetColor( ndx );
    m_subTitleFontPicker->SetSelectedFont( font );
    m_subTitleColorPicker->SetColour( color );
    event.Skip( );
}


void RowDetailsPanel::OnTitleCheckboxClick( wxCommandEvent& event )
{
    UpdateTitleState( m_titleHelper );
    Layout( );
}



void RowDetailsPanel::OnSubTitleCheckboxClick( wxCommandEvent& event )
{
    UpdateSubTitleState( m_titleHelper );
    m_dialogVerticalSizer->Layout( );
};
