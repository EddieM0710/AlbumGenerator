/**
 * @file AlbumImagePanel.cpp
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
 **************************************************/



#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/file.h"
#include "wx/filename.h"
#include "wx/graphics.h"
#include "wx/image.h"
#include <wx/treectrl.h>
#include <wx/pdfdc.h>
#include <wx/pdfdocument.h>

#include "Defs.h"
#include "AlbumImagePanel.h"
#include "design/DesignData.h"
#include "design/Album.h"
#include "design/DesignDefs.h"
#include "design/LayoutBase.h"
#include "design/LayoutBase.h"
#include "utils/Project.h"

#include "art/NotFound.xpm"
#include "gui/DesignTreeCtrl.h"
#include "gui/GuiUtils.h"




IMPLEMENT_DYNAMIC_CLASS( AlbumImagePanel, wxPanel )

/*
 * AlbumImagePanel event table definition
 */

    BEGIN_EVENT_TABLE( AlbumImagePanel, wxPanel )

    // AlbumImagePanel event table entries
    EVT_PAINT( AlbumImagePanel::OnPaint )
    EVT_LEFT_DOWN( AlbumImagePanel::OnLeftDown )
    EVT_CONTEXT_MENU( AlbumImagePanel::OnContextMenu )
    EVT_MENU( ID_RESIZE, AlbumImagePanel::OnResize )
    EVT_MENU( wxID_ZOOM_IN, AlbumImagePanel::OnZoom )
    EVT_MENU( wxID_ZOOM_OUT, AlbumImagePanel::OnZoom )
    EVT_MENU( wxID_ZOOM_100, AlbumImagePanel::OnZoom )
    END_EVENT_TABLE( )
    ;  // silly business; The above macro screws up the formatter

AlbumImagePanel::AlbumImagePanel( )
{
    Init( );
}


AlbumImagePanel::AlbumImagePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos,
    const wxSize& size, long style )
{
    Init( );
    Create( parent, id, pos, size, style );
}

bool AlbumImagePanel::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos,
    const wxSize& size, long style )
{
    // AlbumImagePanel creation
    SetExtraStyle( wxWS_EX_VALIDATE_RECURSIVELY );
    wxScrolledWindow::Create( parent, id, pos, size, style );

    CreateControls( );
    Centre( );
    // AlbumImagePanel creation
    return true;
}

AlbumImagePanel::~AlbumImagePanel( )
{
}

void AlbumImagePanel::Init( )
{

}

void AlbumImagePanel::CreateControls( )
{
    m_once = false;
    m_zoom = .4;
}

bool AlbumImagePanel::ShowToolTips( )
{
    return true;
}

/*
 * OnResize
 *
 **************************************************/
void AlbumImagePanel::OnResize( wxCommandEvent& WXUNUSED( event ) )
{
    wxImage img( m_bitmap.ConvertToImage( ) );

    const wxSize size = GetClientSize( );
    img.Rescale( size.x, size.y, wxIMAGE_QUALITY_HIGH );
    m_bitmap = wxBitmap( img );
}

/*
 * SetZoom
 *
 **************************************************/
void AlbumImagePanel::SetZoom( double zoom )
{
    m_zoom = zoom;
    Refresh( );
}

/*
 * OnZoom
 *
 **************************************************/
void AlbumImagePanel::OnZoom( wxCommandEvent& event )
{
    if ( event.GetId( ) == wxID_ZOOM_IN )
        m_zoom *= 1.2;
    else if ( event.GetId( ) == wxID_ZOOM_OUT )
        m_zoom /= 1.2;
    else // wxID_ZOOM_100
        m_zoom = .4;
    Refresh( );
}

void AlbumImagePanel::Draw( wxDC& dc, Design::LayoutBase* node, wxPoint pt )
{
    wxPoint newPoint( pt.x + node->GetXPos( ), pt.y + node->GetYPos( ) );
    wxRect rect( pt.x, pt.y, node->GetWidth( ), node->GetHeight( ) );
    dc.DrawRectangle( rect );

    wxTreeItemIdValue cookie;
    wxTreeItemId nodeID = node->GetTreeItemId( );
    wxTreeItemId childID = GetDesignTreeCtrl( )->GetFirstChild( nodeID, cookie );
    while ( childID.IsOk( ) )
    {
        Design::LayoutBase* child = ( Design::LayoutBase* ) GetDesignTreeCtrl( )->GetItemNode( childID );
        Draw( dc, child, newPoint );
        childID = GetDesignTreeCtrl( )->GetNextChild( nodeID, cookie );
    }
}

/*
 * ID_ALBUMIMAGEPANEL
 *
 **************************************************/
void AlbumImagePanel::OnPaint( wxPaintEvent& event )
{
    Design::DesignData* designData = GetDesignData( );
    if ( designData )
    {
        wxPaintDC dc( this );
        DoPrepareDC( dc );
        dc.SetMapMode( wxMM_METRIC );
        dc.Clear( );
        Design::InitDesignDefs( );

        Design::Album* album = GetDesignData( )->GetAlbum( );
        if ( album )
        {
            double width = album->GetAttrDbl( Design::AT_PageWidth ) * Design::ScaleFactor.x;
            double height = album->GetAttrDbl( Design::AT_PageHeight ) * Design::ScaleFactor.y;

            /* init scrolled area size, scrolling speed, etc. */
            if ( m_once == false )
            {
                m_once = true;
                SetScrollbars( Design::ScaleFactor.x, Design::ScaleFactor.y, width * 2, height * 2, 0, 0 );
            }
            const wxSize size = GetClientSize( );
            double scale = 1.;

            if ( size.x < width )
            {
                scale = ( double ) size.x / ( double ) width;
            }
            if ( size.y < ( height * scale ) )
            {
                scale = ( double ) size.y / ( ( ( double ) height * scale ) * scale );
            }

            dc.SetUserScale( scale * m_zoom, scale * m_zoom );

            dc.DrawRectangle( 0, 0, width, height );

            Design::LayoutBase* pageNode = Design::GetSelectedNodePage( );
            if ( pageNode && pageNode->IsStatusOK( ) )
            {
                //pageNode->Draw( dc, album->GetAttrDbl( Design::AT_LeftMargin ), album->GetAttrDbl( Design::AT_TopMargin ) );
                pageNode->Draw( dc, 0, 0 );
            }
        }
    }
}

/*
 *  ID_IMAGEPANEL
 */
void AlbumImagePanel::OnLeftDown( wxMouseEvent& event )
{
    wxPoint clientpt = event.GetPosition( );

    Design::LayoutBase* pageNode = Design::GetSelectedNodePage( );

    if ( pageNode )
    {
        Design::LayoutBase* item = pageNode->FindObjectByPos( clientpt.x, clientpt.y );
        if ( item )
        {
            wxTreeItemId newID = item->GetTreeItemId( );
            GetDesignTreeCtrl( )->SelectItem( newID );
        }
    }

    event.Skip( );

}


void AlbumImagePanel::OnContextMenu( wxContextMenuEvent& event )
{
    wxPoint screenpt = event.GetPosition( );
    wxPoint clientpt = ScreenToClient( screenpt );

    Design::LayoutBase* pageNode = Design::GetSelectedNodePage( );

    wxString name = "";

    if ( pageNode )
    {
        Design::LayoutBase* item = pageNode->FindObjectByPos( clientpt.x, clientpt.y );
        if ( item )
        {
            Design::AlbumBaseType type = item->GetNodeType( );
            name = Design::AlbumBaseNames[ type ];

            wxTreeItemId newID = item->GetTreeItemId( );
            GetDesignTreeCtrl( )->SelectItem( newID );
        }
    }
    wxMenu menu( name );

    menu.Append( ID_RESIZE, "&Fit to window\tCtrl-F" );
    menu.Append( wxID_ZOOM_IN, "Zoom &in\tCtrl-+" );
    menu.Append( wxID_ZOOM_OUT, "Zoom &out\tCtrl--" );
    menu.Append( wxID_ZOOM_100, "Reset zoom to &100%\tCtrl-1" );
    menu.AppendSeparator( );
    menu.Append( ID_ROTATE_LEFT, "Rotate &left\tCtrl-L" );
    menu.Append( ID_ROTATE_RIGHT, "Rotate &right\tCtrl-R" );

    PopupMenu( &menu );
    event.Skip( );

}

wxSize AlbumImagePanel::GetTextSize( wxFont font, wxString text )
{
    wxClientDC dc( this );
    dc.SetFont( font );
    dc.SetMapMode( wxMM_METRIC );
    DoPrepareDC( dc );

    text.Trim( );
    text.Trim( false );

    return dc.GetMultiLineTextExtent( text );
}

wxRealPoint AlbumImagePanel::GetLogicalTextExtent( wxString text, wxFont font )
{
    wxClientDC dc( this );
    dc.SetFont( font );
    dc.SetMapMode( wxMM_METRIC );
    DoPrepareDC( dc );

    wxSize size = dc.GetMultiLineTextExtent( text );

    wxRealPoint textSize;
    // convert the size from Device units to Metric
    textSize.x = size.x / Design::ScaleFactor.x;
    textSize.y = size.y / Design::ScaleFactor.y;
    return textSize;
}


void AlbumImagePanel::MakeMultiLine( wxString& text, wxFont font, double width )
{
    //adjust the with down just a bit to allow for text conversion
    width = width * .95;

    wxClientDC  dc( this );//= this->GetDC( );
    dc.SetMapMode( wxMM_METRIC );
    dc.SetFont( font );
    DoPrepareDC( dc );

    text.Trim( );
    text.Trim( false );
    int len = text.length( );
    if ( len > 0 )
    {
        wxSize ext = dc.GetTextExtent( text );
        wxSize logExt = dc.DeviceToLogicalRel( ext );
        if ( ext.x < width * Design::ScaleFactor.x )
        {
            // if it fits print it
            //all done
        }
        else
        {
            // break the line up at word DoPrepareDC( dc ); breaks; look for a space
            int start = 0;
            int pos = start;
            int origPos = start;

            wxString currStr = text;
            wxString workingStr = text;

            pos = workingStr.find( ' ', pos );

            while ( len > 0 )
            {
                if ( pos == wxNOT_FOUND )
                {
                    // no space for break so print it.
                    len = 0;
                    // all done
                }
                else
                {
                    // found a space so break into multiple lines
                    // Add words until length exceeded
                    workingStr = text.Mid( start, pos );

                    wxSize ext = dc.GetTextExtent( workingStr );
                    wxSize logExt = dc.DeviceToLogicalRel( ext );
                    if ( ext.x > width * Design::ScaleFactor.x )
                    {
                        // it won't fit; decide what to do
                        if ( start == origPos )
                        {
                            // the distance to the first space was bigger than the size of the stamp so print it
                            // i.e., a really big word or little stamp
                            text.SetChar( pos, '\n' );
                            workingStr = text.Mid( pos + 1 );
                            workingStr.Trim( );
                            workingStr.Trim( false );
                            len = workingStr.length( );
                            start = pos + 1;
                            origPos = pos + 1;
                            pos = text.find( ' ', start );

                        }
                        else
                        {
                            // backup to previous try
                            workingStr = workingStr.Mid( start, origPos );
                            pos = origPos;
                            text.SetChar( pos, '\n' );
                            workingStr = text.Mid( pos + 1 );
                            workingStr.Trim( );
                            workingStr.Trim( false );
                            len = workingStr.length( );
                            start = pos + 1;
                            origPos = pos + 1;
                            pos = text.find( ' ', start );

                        }
                    }
                    else
                    {
                        // the word will fit; can another word fit?
                        origPos = pos;
                        pos = text.find( ' ', pos + 1 );
                        if ( pos == wxNOT_FOUND )
                        {
                            // no space for break so print it.
                            text.SetChar( origPos, '\n' );
                            workingStr.Empty( );
                            len = 0;
                        }
                    }
                }
            }
        }
    }
}
