/**
 * @file Row.cpp
 * @author Eddie Monroe
 * @brief
 * @version 0.1
 * @date 2022-02-04
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
 *
 **************************************************/
#include <wx/pen.h>

#include "design/Row.h"
#include "design/Column.h"
#include "design/Stamp.h"
#include "design/Title.h"
#include "gui/DesignTreeCtrl.h"
#include "gui/AlbumImagePanel.h"
#include "gui/GuiUtils.h"

namespace Design {


    bool Row::UpdateMinimumSize( )
    {
        //Positioning across the row.
         //The min height of the row is the size of the tallest child 
         //plus the title if used
         //The min width is the sum of the min widths of the children. 
        double minWidth = 0.0;
        double minHeight = 0.0;

        wxTreeItemIdValue cookie;
        wxTreeItemId parentID = GetTreeItemId( );
        wxTreeItemId childID = GetDesignTreeCtrl( )->GetFirstChild( parentID, cookie );
        while ( childID.IsOk( ) )
        {
            LayoutBase* child = ( LayoutBase* ) GetDesignTreeCtrl( )->GetItemNode( childID );
            child->UpdateMinimumSize( );
            if ( child->GetMinHeight( ) > minHeight )
            {
                minHeight = child->GetMinHeight( );
            }
            minWidth += child->GetMinWidth( );
            childID = GetDesignTreeCtrl( )->GetNextChild( parentID, cookie );
        }

        double leftPadding = 0;
        double rightPadding = 0;
        double topPadding = 0;
        double bottomPadding = 0;
        if ( GetShowFrame( ) )
        {
            leftPadding = GetLeftContentPadding( );
            rightPadding = GetRightContentPadding( );
            topPadding = GetTopContentPadding( );
            bottomPadding = GetBottomContentPadding( );
        }


        minHeight = minHeight + topPadding + bottomPadding;
        minWidth = minWidth + leftPadding + rightPadding;

        UpdateTitleSize( minWidth );

        if ( GetShowTitle( ) )
        {
            // Allow 3 times the title height
            minHeight += 3 * GetTitleHeight( );
        }

        SetMinHeight( minHeight );
        SetMinWidth( minWidth );
        return true;
    }

    void Row::UpdateSizes( )
    {

        // Set the height and width of each child column
        // Stamps have fixed height and width
        wxTreeItemIdValue cookie;
        wxTreeItemId parentID = GetTreeItemId( );
        wxTreeItemId childID = GetDesignTreeCtrl( )->GetFirstChild( parentID, cookie );
        while ( childID.IsOk( ) )
        {
            LayoutBase* child = ( LayoutBase* ) GetDesignTreeCtrl( )->GetItemNode( childID );
            if ( child->IsNodeType( AT_Col ) )
            {
                child->SetWidth( GetMinWidth( ) );
                child->SetHeight( GetMinHeight( ) );
            }
            child->UpdateSizes( );

            childID = GetDesignTreeCtrl( )->GetNextChild( parentID, cookie );
        }

    }

    // calculate the row layout based on child parameters
    void Row::UpdatePositions( )
    {
        //        m_frame.WriteLayout( "Row::UpdatePositions <" );
                // go to the bottom of each child container object ( row, column, page ) 
                // and begin filling in position relative to the parent

        int nbrRows = 0;
        int nbrCols = 0;
        int nbrStamps = 0;
        ValidateChildType( nbrRows, nbrCols, nbrStamps );

        double xPos = 0;
        double yPos = 0;
        //First calc title position  
        if ( GetShowTitle( ) )
        {
            m_titleFrame.SetXPos( 0 + ( GetWidth( ) - m_titleFrame.GetWidth( ) ) / 2 );
            m_titleFrame.SetYPos( m_titleFrame.GetHeight( ) );
            // allow for space above title, title height and that much again for nice spaing
            yPos = m_titleFrame.GetHeight( );
        }

        // this is a row so we are positioning children across the page
        double spacing = ( GetWidth( ) - GetMinWidth( ) ) / ( nbrCols + nbrStamps + 1 );

        // inital x/y pos within the row
        xPos += spacing;

        wxTreeItemIdValue cookie;
        wxTreeItemId parentID = GetTreeItemId( );
        wxTreeItemId childID = GetDesignTreeCtrl( )->GetFirstChild( parentID, cookie );
        while ( childID.IsOk( ) )
        {
            LayoutBase* child = ( LayoutBase* ) GetDesignTreeCtrl( )->GetItemNode( childID );
            child->UpdatePositions( );

            AlbumBaseType childType = ( AlbumBaseType ) child->GetNodeType( );
            switch ( childType )
            {
            case AT_Col:
            {
                Column* col = ( Column* ) child;
                col->SetXPos( xPos );
                col->SetYPos( yPos );
                xPos += col->GetWidth( ) + spacing;
                break;
            }
            case AT_Stamp:
            {

                Stamp* stamp = ( Stamp* ) child;

                // each stamp is positioned in the cell

                double yBorder = ( GetHeight( ) - stamp->GetHeight( ) ) / 2;
                stamp->SetXPos( xPos );
                stamp->SetYPos( yPos + yBorder );
                // get xpos of next cell
                xPos += stamp->GetWidth( ) + spacing;
                break;
            }
            case AT_Text:
            {
                Text* text = ( Text* ) child;
                double yBorder = ( GetHeight( ) - text->GetHeight( ) ) / 2;
                text->SetXPos( xPos );
                text->SetYPos( yPos + yBorder );
                // get xpos of next cell
                xPos += text->GetWidth( ) + spacing;
                break;
            }
            }
            childID = GetDesignTreeCtrl( )->GetNextChild( parentID, cookie );
        }

    }

    NodeStatus Row::ValidateNode( )
    {

        NodeStatus status = AT_OK;
        if ( !HasChildren( ) )
        {
            GetErrorArray( )->Empty( );
            if ( GetHeight( ) <= 0.0 )
            {
                wxString str;
                str = wxString::Format( "Terminal leaf node must define the height. height:>>%7.2f<< \n", GetHeight( ) );
                GetErrorArray( )->Add( str );
                m_debugString.Append( str );
                status = AT_FATAL;
            }
            if ( GetWidth( ) <= 0.0 )
            {
                wxString str;
                str = wxString::Format( "Terminal leaf node must define the height. width:>>%7.2f<< \n", GetWidth( ) );
                GetErrorArray( )->Add( str );
                m_debugString.Append( str );
                status = AT_FATAL;
            }
        }

        m_nodeValid = status;
        return status;
    }

    void Row::DrawPDF( wxPdfDocument* doc, double x, double y )
    {
        double leftPadding = 0;
        double topPadding = 0;
        if ( GetShowFrame( ) )
        {
            leftPadding = GetLeftContentPadding( );
            topPadding = GetTopContentPadding( );
            m_frame.DrawPDF( doc, x, y );
        }
        //m_frame.DrawPDF( doc, x, y );

        if ( GetShowTitle( ) )
        {
            RealPoint pos( x, y );
            RealSize size( GetWidth( ), m_titleFrame.GetHeight( ) );
            //            DrawTitlePDF( doc, m_title, pos, size );
            y = y + m_titleFrame.GetHeight( );
        }

        double xPos = x + GetXPos( ) + leftPadding;
        double yPos = y + GetYPos( ) + topPadding;

        wxTreeItemIdValue cookie;
        wxTreeItemId parentID = GetTreeItemId( );
        wxTreeItemId childID = GetDesignTreeCtrl( )->GetFirstChild( parentID, cookie );
        while ( childID.IsOk( ) )
        {

            AlbumBaseType type = ( AlbumBaseType ) GetDesignTreeCtrl( )->GetItemType( childID );
            LayoutBase* child = ( LayoutBase* ) GetDesignTreeCtrl( )->GetItemNode( childID );
            child->DrawPDF( doc, xPos, yPos );

            childID = GetDesignTreeCtrl( )->GetNextChild( parentID, cookie );
        }
    };

    void Row::Draw( wxDC& dc, double x, double y )
    {
        double leftPadding = 0;
        double topPadding = 0;
        dc.SetPen( *wxTRANSPARENT_PEN );
        if ( GetShowFrame( ) )
        {
            dc.SetPen( *wxBLACK_PEN );
            leftPadding = GetLeftContentPadding( );
            topPadding = GetTopContentPadding( );
        }

        SetClientDimensions( dc, x + GetXPos( ), y + GetYPos( ), GetWidth( ), GetHeight( ) );

        m_frame.Draw( dc, x, y );

        double xPos = x + GetXPos( ) + leftPadding;
        double yPos = y + GetYPos( ) + topPadding;

        if ( GetShowTitle( ) )
        {
            wxFont currFont = dc.GetFont( );
            wxColour currColor = dc.GetTextForeground( );

            wxFont titleFont = GetTitleFont( );
            wxFont font( titleFont );
            wxColour color = GetTitleColor( );
            dc.SetFont( font );
            dc.SetTextForeground( color );

            RealPoint pos( xPos + m_titleFrame.GetXPos( ), yPos + m_titleFrame.GetYPos( ) );
            RealSize size( m_titleFrame.GetWidth( ), m_titleFrame.GetHeight( ) );

            wxString title = GetTitle( );
            GetAlbumImagePanel( )->MakeMultiLine( title, font, size.x );
            DrawLabel( dc, title, pos, size, wxALIGN_LEFT );

            dc.SetFont( currFont );
            dc.SetTextForeground( currColor );

        }

        wxTreeItemIdValue cookie;
        wxTreeItemId parentID = GetTreeItemId( );
        wxTreeItemId childID = GetDesignTreeCtrl( )->GetFirstChild( parentID, cookie );
        while ( childID.IsOk( ) )
        {

            AlbumBaseType type = ( AlbumBaseType ) GetDesignTreeCtrl( )->GetItemType( childID );
            LayoutBase* child = ( LayoutBase* ) GetDesignTreeCtrl( )->GetItemNode( childID );
            child->Draw( dc, xPos, yPos );

            childID = GetDesignTreeCtrl( )->GetNextChild( parentID, cookie );
        }
    }

    void Row::Save( wxXmlNode* xmlNode )
    {
        SetAttribute( xmlNode, AT_Name );
        SetAttribute( xmlNode, AT_ShowTitle );
        SetAttribute( xmlNode, AT_ShowFrame );
        SaveFonts( xmlNode );
    }


    void Row::ReportLayout( )
    {
        std::cout << "Layout for Row " << "\n ";
        ReportLayoutFrame( );
    };
}