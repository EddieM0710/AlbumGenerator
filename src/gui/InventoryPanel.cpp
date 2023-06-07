/**
 * @file InventoryPanel.cpp
 * @author Eddie Monroe ( )
 * @brief
 * @version 0.1
 * @date 2021-02-25
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
 */


#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "InventoryPanel.h"
#include "catalog/CatalogData.h"
#include "collection/CollectionList.h"
#include "Specimen.h"
#include "Defs.h"
#include "utils/Settings.h"

IMPLEMENT_DYNAMIC_CLASS( InventoryPanel, wxPanel )

#define wxIDAddItem 17000
#define wxIDDeleteItem 17001


BEGIN_EVENT_TABLE( InventoryPanel, wxPanel )

EVT_CONTEXT_MENU( InventoryPanel::OnContextMenu )
EVT_GRID_CELL_CHANGED( InventoryPanel::OnCellChanged )
EVT_MENU( wxIDAddItem, InventoryPanel::OnContextPopup )
EVT_MENU( wxIDDeleteItem, InventoryPanel::OnContextPopup )

END_EVENT_TABLE( )



InventoryPanel::InventoryPanel( ) { Init( ); }

InventoryPanel::InventoryPanel( wxWindow* parent, wxWindowID id,
    const wxPoint& pos, const wxSize& size,
    long style )
{
    Init( );
    Create( parent, id, pos, size, style );
}

bool InventoryPanel::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos,
    const wxSize& size, long style )
{
    // InventoryPanel creation
    SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls( );
    Centre( );
    // InventoryPanel creation
    return true;
}

InventoryPanel::~InventoryPanel( )
{

}

void InventoryPanel::Init( )
{
    m_grid = NULL;
}

void InventoryPanel::CreateControls( )
{

    InventoryPanel* itemPanel1 = this;

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer( wxHORIZONTAL );
    itemPanel1->SetSizer( itemBoxSizer1 );

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer( wxVERTICAL );
    itemBoxSizer1->Add( itemBoxSizer2, 1, wxGROW | wxALL, 5 );

    m_grid = new wxGrid( itemPanel1, ID_INVENTORYGRID, wxDefaultPosition, wxSize( 200, 150 ),
        wxHSCROLL | wxVSCROLL );
    m_grid->SetDefaultColSize( 100 );
    m_grid->SetDefaultRowSize( 25 );
    m_grid->SetColLabelSize( 25 );
    m_grid->SetRowLabelSize( 50 );
    m_grid->CreateGrid( 0, 7, wxGrid::wxGridSelectCells );
    itemBoxSizer2->Add( m_grid, 1, wxGROW | wxALL, 5 );

    // Connect events and objects
    //    m_grid->Connect( ID_INVENTORYGRID,  CONTEXT_MENU, 
    //    wxContextMenuEventHandler( InventoryPanel::OnContextMenu ), NULL, this );
    // InventoryPanel content construction
    for ( int i = 0; i < Catalog::IDT_NbrTypes; i++ )
    {
        m_grid->SetColLabelValue( i, Catalog::ItemDataNames[ i ] );
    }
    wxString choices[ 5 ] = { wxT( "Mint" ), wxT( "MNH" ), wxT( "Unused" ), wxT( "Used" ),
                           wxT( "OG" ) }; // Make table strings
    wxGridCellAttr* attr = new wxGridCellAttr( );
    attr->SetEditor( new wxGridCellChoiceEditor( 5, choices, true ) );
    m_grid->SetColAttr( Catalog::IDT_Type, attr );

    wxString choices2[ 5 ] = { wxT( "VF" ), wxT( "F" ), wxT( "VG" ), wxT( "G" ),
                            wxT( "P" ) }; // Make table strings
    attr = new wxGridCellAttr( );
    attr->SetEditor( new wxGridCellChoiceEditor( 5, choices2, true ) );
    m_grid->SetColAttr( Catalog::IDT_Condition, attr );

    wxString choices3[ 3 ] = { wxT( "Album" ), wxT( "Stock Book" ),
                            wxT( "File Box" ) }; // Make table strings
    attr = new wxGridCellAttr( );
    attr->SetEditor( new wxGridCellChoiceEditor( 3, choices3, true ) );
    m_grid->SetColAttr( Catalog::IDT_Location, attr );

    wxString choices4[ Catalog::ST_NbrInventoryStatusTypes ];
    for ( int i = 0; i < Catalog::ST_NbrInventoryStatusTypes; i++ )
    {
        choices4[ i ] = Catalog::InventoryStatusStrings[ i ];
    }

    attr = new wxGridCellAttr( );
    attr->SetEditor( new wxGridCellChoiceEditor( Catalog::ST_NbrInventoryStatusTypes, choices4, true ) );
    m_grid->SetColAttr( Catalog::IDT_InventoryStatus, attr );

    attr = new wxGridCellAttr( );
    attr->SetEditor( new wxGridCellChoiceEditor( GetCollectionList( )->GetNameStrings( ), true ) );
    m_grid->SetColAttr( Catalog::IDT_Collection, attr );

    SetDataEditable( GetSettings( )->IsCatalogVolumeEditable( ) );

    m_grid->Refresh( );

}


void InventoryPanel::InitRow( int row )
{
    wxXmlNode* ele = m_specimenList[ row ];
    Catalog::Specimen specimen( ele );
    for ( int i = 0; i < Catalog::IDT_NbrTypes; i++ )
    {
        specimen.SetAttr( ( Catalog::ItemDataTypes ) i, "" );
        m_grid->SetCellValue( row, i, "" );
    }
}

int InventoryPanel::AddRow( )
{
    Catalog::Entry* stamp = GetCatalogData( )->GetCurrentStamp( );
    if ( stamp )
    {
        int cnt = m_grid->GetNumberRows( );
        m_grid->InsertRows( cnt, 1 );

        wxXmlNode* ele = stamp->AddSpecimen( );
        m_specimenList.push_back( ele );
        InitRow( cnt );
        return cnt;
    }
    return -1;
}

void InventoryPanel::ShowRow( int row )
{
    wxXmlNode* ele = m_specimenList[ row ];
    Catalog::Specimen specimen( ele );
    for ( int i = 0; i < Catalog::IDT_NbrTypes; i++ )
    {
        wxString str = specimen.GetAttr( ( Catalog::ItemDataTypes ) i );
        m_grid->SetCellValue( row, i, str );
    }
}

bool InventoryPanel::ShowToolTips( )
{
    return true;
}




void InventoryPanel::UpdatePanel( )
{

    //   wxGridCellAttr* attr = new wxGridCellAttr( );
    //   attr->SetEditor( new wxGridCellChoiceEditor( GetCollectionList( )->GetNameStrings( ), true ) );
    //   m_grid->SetColAttr( Catalog::IDT_Collection, attr );
    wxString currCollection = GetCollectionList( )->GetCurrentName( );

    int cnt = m_grid->GetNumberRows( );
    m_grid->ClearGrid( );
    if ( cnt > 0 )
        m_grid->DeleteRows( 0, cnt );
    m_specimenList.clear( );
    cnt = m_grid->GetNumberRows( );
    int size = m_specimenList.size( );
    int row = 0;
    Catalog::Entry* stamp = GetCatalogData( )->GetCurrentStamp( );
    if ( stamp && stamp->IsOK( ) )
    {
        if ( stamp->HasChildSpecimen( ) )
        {
            //wxXmlNode* ele = stamp->GetFirstChildSpecimen( );
            wxXmlNode* ele = stamp->GetCatXMLNode( )->GetChildren( );
            while ( ele )
            {
                if ( !ele->GetName( ).Cmp( "Specimen" ) )
                {
                    wxString specimenCollection = ele->GetAttribute( Catalog::ItemDataNames[ Catalog::IDT_Collection ], "" );
                    if ( !currCollection.Cmp( specimenCollection ) )
                    {
                        AddRow( );
                        m_specimenList.push_back( ele );
                        Catalog::Specimen specimen( ele );
                        for ( int i = 0; i < Catalog::IDT_NbrTypes; i++ )
                        {
                            wxString str = specimen.GetAttr( ( Catalog::ItemDataTypes ) i );
                            m_grid->SetCellValue( row, i, str );
                        }
                    }
                }
                ele = ele->GetNext( );
            }
        }
    }
}

void InventoryPanel::OnContextMenu( wxContextMenuEvent& event )
{

    if ( GetSettings( )->IsCatalogVolumeEditable( ) )
    {
        wxPoint point = event.GetPosition( );
        // If from keyboard
        if ( ( point.x == -1 ) && ( point.y == -1 ) )
        {
            wxSize size = GetSize( );
            point.x = size.x / 2;
            point.y = size.y / 2;
        }
        else
        {
            point = ScreenToClient( point );
        }
        wxMenu menu;
        menu.Append( wxID_ANY, wxString::Format( "Menu1" ) );
        menu.Append( wxIDAddItem, "Add Item" );
        menu.Append( wxIDDeleteItem, "Delete Item" );

        PopupMenu( &menu, point.x, point.y );
    }
    event.Skip( );

}

void InventoryPanel::OnCellChanged( wxGridEvent& event )
{
    int col = event.GetCol( );
    int row = event.GetRow( );
    wxString str = m_grid->GetCellValue( row, col );
    wxXmlNode* ele = m_specimenList[ row ];
    Catalog::Specimen specimen( ele );
    specimen.SetAttr( ( Catalog::ItemDataTypes ) col, str );

    event.Skip( );

}


void InventoryPanel::OnContextPopup( wxCommandEvent& event )
{
    int id = event.GetId( );
    switch ( id )
    {
        case wxIDAddItem:
        {
            AddRow( );
            break;
        }
        case wxIDDeleteItem:
        {
            break;
        }
    }
}

void InventoryPanel::SetDataEditable( bool val )
{
    m_grid->EnableEditing( val );
}