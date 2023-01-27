/**
 * @file StampDetailsDialog.cpp
 * @author Eddie Monroe ( )
 * @brief
 * @version 0.1
 * @date 2022-03-27
 *
 * @copyright Copyright ( c ) 2021
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
 *
 **************************************************/

 // For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

// includes
#include "wx/imaglist.h"
// includes
#include "wx/notebook.h"

#include "gui/StampDetailsDialog.h"
#include "gui/LabeledTextBox.h"
#include "gui/CatalogTreeCtrl.h"
#include "utils/StampList.h"
#include "Defs.h"
#include "wx/treectrl.h"
#include <wx/fontpicker.h>

// XPM images
// XPM images


/*
 * StampDetailsDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( StampDetailsDialog, wxDialog )


/*
 * StampDetailsDialog event table definition
 */

    BEGIN_EVENT_TABLE( StampDetailsDialog, wxDialog )

    // StampDetailsDialog event table entries
    EVT_BUTTON( ID_REFRESHBUTTON, StampDetailsDialog::OnRefreshButtonClick )
    EVT_BUTTON( wxID_CANCEL, StampDetailsDialog::OnCancelClick )
    EVT_BUTTON( wxID_OK, StampDetailsDialog::OnOkClick )
    // StampDetailsDialog event table entries

    END_EVENT_TABLE( )


    /*
     * StampDetailsDialog constructors
     */

    StampDetailsDialog::StampDetailsDialog( )
{ 
    Init( );
}

StampDetailsDialog::StampDetailsDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{ 
    Init( );
    Create( parent, id, caption, pos, size, style );
}


/*
 * StampDetailsDialog creator
 */

bool StampDetailsDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{ 
    // StampDetailsDialog creation
    SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY | wxWS_EX_BLOCK_EVENTS );
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls( );
    if ( GetSizer( ) )
    { 
        GetSizer( )->SetSizeHints( this );
    }
    Centre( );
    // StampDetailsDialog creation
    return true;
}


/*
 * StampDetailsDialog destructor
 */

StampDetailsDialog::~StampDetailsDialog( )
{ 
    // StampDetailsDialog destruction
    // StampDetailsDialog destruction
}


/*
 * Member initialisation
 */

void StampDetailsDialog::Init( )
{ 
    // StampDetailsDialog member initialisation
    m_catNbr = NULL;
    m_name = NULL;
    m_height = NULL;
    m_width = NULL;
    m_validate = NULL;
    m_statusList = NULL;
    m_designTreeID = NULL;
    m_catNbrCheckbox = NULL;
    m_titleCheckbox = NULL;

    // StampDetailsDialog member initialisation
}


/*
 * Control creation for StampDetailsDialog
 */

void StampDetailsDialog::CreateControls( )
{ 
    // StampDetailsDialog content construction

    StampDetailsDialog* theDialog = this;

    wxBoxSizer* theDialogVerticalSizer = new wxBoxSizer( wxVERTICAL );
    theDialog->SetSizer( theDialogVerticalSizer );

    wxBoxSizer* theDialogHorizontalSizer = new wxBoxSizer( wxHORIZONTAL );
    theDialogVerticalSizer->Add( theDialogHorizontalSizer, 0, wxGROW | wxALL, 0 );

   // wxBoxSizer* detailsVerticalSizer = new wxBoxSizer( wxVERTICAL );
   // theDialogVerticalSizer->Add( detailsVerticalSizer, 0, wxGROW | wxALL, 5 );

    m_catNbr = new LabeledTextBox( theDialog/*detailsPanel*/, ID_IDLABELTEXTBOX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER | wxTAB_TRAVERSAL );
    m_catNbr->SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
    theDialogVerticalSizer->Add( m_catNbr, 0, wxGROW | wxALL, 5 );

    //wxBoxSizer* itemBoxSizer8 = new wxBoxSizer( wxVERTICAL );
    //detailsVerticalSizer->Add( itemBoxSizer8, 1, wxGROW | wxALL, 5 );

    m_name = new LabeledTextBox( theDialog/*detailsPanel*/, ID_NAMELABELEDTEXTBOX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER | wxTAB_TRAVERSAL );
    m_name->SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
    theDialogVerticalSizer->Add( m_name, 1, wxGROW | wxALL, 5 );

    wxBoxSizer* checkBoxHorizontalSizer = new wxBoxSizer( wxHORIZONTAL );
    theDialogVerticalSizer->Add( checkBoxHorizontalSizer, 0, wxGROW | wxALL, 0 );
 
    m_catNbrCheckbox = new wxCheckBox( theDialog/*detailsPanel*/, ID_CATNBRCHECKBOX, _( "Show ID" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_catNbrCheckbox->SetValue( false );
    checkBoxHorizontalSizer->Add( m_catNbrCheckbox, 0, wxALIGN_LEFT | wxALL, 5 );

    m_titleCheckbox = new wxCheckBox( theDialog/*detailsPanel*/, ID_TITLECHECKBOX, _( "Show Title" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_titleCheckbox->SetValue( false );
    checkBoxHorizontalSizer->Add( m_titleCheckbox, 0, wxALIGN_LEFT | wxALL, 5 );

    wxFontPickerCtrl* m_fontPicker = new wxFontPickerCtrl( theDialog/*detailsPanel*/, 12345, 
        *wxNORMAL_FONT, wxDefaultPosition, 
        wxDefaultSize, wxFNTP_DEFAULT_STYLE );
    theDialogVerticalSizer->Add( m_fontPicker, 1, wxGROW | wxALL, 5 );

    m_imagePath = new LabeledTextBox( theDialog/*detailsPanel*/, ID_IMAGEPATHLABELEDTEXTBOX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER | wxTAB_TRAVERSAL );
    m_imagePath->SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
    theDialogVerticalSizer->Add( m_imagePath, 0, wxGROW | wxALL, 5 );

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer( wxHORIZONTAL );
    theDialogVerticalSizer->Add( itemBoxSizer3, 0, wxGROW | wxALL, 0 );

    m_height = new LabeledTextBox( theDialog/*detailsPanel*/, ID_HEIGHTLABELEDTEXTBOX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER | wxTAB_TRAVERSAL );
    m_height->SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
    itemBoxSizer3->Add( m_height, 1, wxGROW | wxALL, 5 );

    m_width = new LabeledTextBox( theDialog/*detailsPanel*/, ID_WIDTHLABELEDTEXTBOX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER | wxTAB_TRAVERSAL );
    m_width->SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
    itemBoxSizer3->Add( m_width, 1, wxGROW | wxALL, 5 );

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer( wxHORIZONTAL );
    theDialogVerticalSizer->Add( itemBoxSizer6, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0 );

    wxButton* itemButton7 = new wxButton( theDialog/*detailsPanel*/, ID_REFRESHBUTTON, _( "Refresh from Catalog" ), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add( itemButton7, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

    itemBoxSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

    m_validate = new wxButton( theDialog/*detailsPanel*/, ID_VALIDATEBUTTON, _( "Validate" ), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add( m_validate, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

    wxBoxSizer* itemBoxSizer10 = new wxBoxSizer( wxHORIZONTAL );
    theDialogVerticalSizer->Add( itemBoxSizer10, 2, wxGROW | wxALL, 5 );

    m_statusList = new wxListCtrl( theDialog/*detailsPanel*/, ID_LISTCTRL, wxDefaultPosition, wxSize( 100, 100 ), wxLC_REPORT | wxLC_NO_HEADER );
    itemBoxSizer10->Add( m_statusList, 2, wxGROW | wxALL, 5 );

    //wxBoxSizer* itemBoxSizer14 = new wxBoxSizer( wxHORIZONTAL );
    //detailsVerticalSizer->Add( itemBoxSizer14, 2, wxGROW | wxALL, 5 );

    //<<error list ctrls

    //>>dialog Ctrl buttons
    wxBoxSizer* dialogCtrlButtonSizer = new wxBoxSizer( wxHORIZONTAL );
    theDialogVerticalSizer->Add( dialogCtrlButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0 );

    wxButton* cancelButton = new wxButton( theDialog, wxID_CANCEL, _( "Cancel" ), wxDefaultPosition, wxDefaultSize, 0 );
    dialogCtrlButtonSizer->Add( cancelButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

    wxButton* okButton = new wxButton( theDialog, wxID_OK, _( "OK" ), wxDefaultPosition, wxDefaultSize, 0 );
    dialogCtrlButtonSizer->Add( okButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );
    //>>dialog Ctrl buttons  


    m_catNbr->SetLabel( "Catalog Nbr" );
    m_name->SetLabel( "Name" );
    m_height->SetLabel( "Height" );
    m_width->SetLabel( "Width" );
    m_imagePath->SetLabel( "ImageName" );
}


/*
 * Should we show tooltips?
 */

bool StampDetailsDialog::ShowToolTips( )
{ 
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap StampDetailsDialog::GetBitmapResource( const wxString& name )
{ 
    // Bitmap retrieval
// StampDetailsDialog bitmap retrieval
    wxUnusedVar( name );
    return wxNullBitmap;
    // StampDetailsDialog bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon StampDetailsDialog::GetIconResource( const wxString& name )
{ 
    // Icon retrieval
// StampDetailsDialog icon retrieval
    wxUnusedVar( name );
    return wxNullIcon;
    // StampDetailsDialog icon retrieval
}

void StampDetailsDialog::SetHeight( wxString height )
{ 
    m_height->SetValue( height );
    m_height->SetModified( false );
}

void StampDetailsDialog::SetImageFilename( wxString path )
{ 
    m_imagePath->SetValue( path );
    m_height->SetModified( false );
}
void StampDetailsDialog::SetWidth( wxString width )
{ 
    m_width->SetValue( width );
    m_width->SetModified( false );
}

void StampDetailsDialog::SetCatNbr( wxString catNbr )
{ 

    m_catNbr->SetValue( catNbr );
    m_catNbr->SetModified( false );
}

void StampDetailsDialog::SetName( wxString name )
{ 
    m_name->SetValue( name );
    m_name->SetModified( false );
}

void StampDetailsDialog::SetShowCatNbr( bool state )
{ 
    m_catNbrCheckbox->SetValue( state );
}

void StampDetailsDialog::SetShowTitle( bool state )
{ 
    m_titleCheckbox->SetValue( state );
}

void StampDetailsDialog::SetDesignTreeID( wxTreeItemId id )
{ 
    if ( id.IsOk( ) )
    {
        m_designTreeID = id;
        DesignTreeItemData* data = ( DesignTreeItemData* )GetDesignTreeCtrl( )->GetItemData( m_designTreeID );
        Design::Stamp* stamp = (Design::Stamp*)data->GetNodeElement();
        wxArrayString* errors = stamp->GetErrorArray( );
        
    }
}


wxString StampDetailsDialog::GetImageFilename( )
{ 
    return m_imagePath->GetValue( );
}
wxString StampDetailsDialog::GetHeight( )
{ 
    return m_height->GetValue( );
}

wxString StampDetailsDialog::GetWidth( )
{ 
    return m_width->GetValue( );
}

wxString StampDetailsDialog::GetCatNbr( )
{ 
    return m_catNbr->GetValue( );
}

wxString StampDetailsDialog::GetName( )
{ 
    return m_name->GetValue( );
}

bool StampDetailsDialog::GetShowCatNbr( )
{ 
    return m_catNbrCheckbox->IsChecked( );
}

bool StampDetailsDialog::GetShowTitle( )
{ 
    return m_titleCheckbox->IsChecked( );
}

bool StampDetailsDialog::IsNameModified( )
{ 
    return m_name->IsModified( );
}

bool StampDetailsDialog::IsIDModified( )
{ 
    return m_catNbr->IsModified( );
}

bool StampDetailsDialog::IsHeightModified( )
{ 
    return m_height->IsModified( );
}

bool StampDetailsDialog::IsWidthModified( )
{ 
    return m_width->IsModified( );
}

void StampDetailsDialog::SetHeightModified( bool state )
{ 
    m_height->SetModified( state );
}

void StampDetailsDialog::SetWidthModified( bool state )
{ 
    m_width->SetModified( state );
}

void StampDetailsDialog::SetCatNbrModified( bool state )
{ 
    m_catNbr->SetModified( state );
}

void StampDetailsDialog::SetNameModified( bool state )
{ 
    m_name->SetModified( state );
}


void StampDetailsDialog::RefreshFromCatalog( )
{ 
    if ( m_designTreeID.IsOk( ) )
    { 
        DesignTreeItemData* data = ( DesignTreeItemData* )GetDesignTreeCtrl( )->GetItemData( m_designTreeID );

        Utils::StampLink* link = data->GetStampLink( );
        if ( link )
        { 
            wxTreeItemId catTreeID = link->GetCatTreeID( );
            wxXmlNode* node = GetCatalogTreeCtrl( )->GetEntryNode( catTreeID );

            if ( node )
            { 
                Catalog::CatalogSectionData* catalogSectionData = GetCatalogSectionData( );
                Catalog::Entry  stamp( node );
                SetHeight( stamp.GetHeight( ) );
                SetHeightModified( );
                SetWidth( stamp.GetWidth( ) );
                SetWidthModified( );
                SetName( stamp.GetName( ) );
                SetNameModified( );
                SetCatNbr( stamp.GetID( ) );
                SetCatNbrModified( );
                wxString label;
                label = GetCatNbr( ) + " - " + GetName( );
                GetDesignTreeCtrl( )->SetItemText( m_designTreeID, label );
            }
        }
    }
}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void StampDetailsDialog::OnRefreshButtonClick( wxCommandEvent& event )
{ 
    RefreshFromCatalog( );
    // wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in StampDetailsDialog.
        // Before editing this code, remove the block markers.
    event.Skip( );
    // wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in StampDetailsDialog. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void StampDetailsDialog::OnCancelClick( wxCommandEvent& event )
{ 
    // wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in StampDetailsDialog.
        // Before editing this code, remove the block markers.
    event.Skip( );
    // wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in StampDetailsDialog. 
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void StampDetailsDialog::OnOkClick( wxCommandEvent& event )
{ 
    // wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in StampDetailsDialog.
        // Before editing this code, remove the block markers.
    event.Skip( );
    // wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in StampDetailsDialog. 
}

