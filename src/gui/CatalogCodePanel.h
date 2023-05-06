/**
 * @file CatalogCodePanel.h
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


#ifndef _CatalogCode_H_
#define _CatalogCode_H_

#include <vector>
#include <wx/dataview.h>
#include "wx/grid.h"

#include "catalog/Entry.h"
#include "gui/GuiDefs.h"

class wxGrid;

#define SYMBOL_CATALOGCODEPANEL_STYLE wxTAB_TRAVERSAL
#define SYMBOL_CATALOGCODEPANEL_TITLE _( "CatalogCode" )
#define SYMBOL_CATALOGCODEPANEL_IDNAME ID_CATALOGCODEPANEL
#define SYMBOL_CATALOGCODEPANEL_SIZE wxSize( 800, 200 )
#define SYMBOL_CATALOGCODEPANEL_POSITION wxDefaultPosition

class CatalogCodePanel : public wxPanel
{
    DECLARE_DYNAMIC_CLASS( CatalogCodePanel )
        DECLARE_EVENT_TABLE( )

public:
    enum  CatalogCodePanelGuiDefs
    {
        ID_GRID = ID_CATALOGCODEPANEL + 1,
    };


    ///  @brief Default Constructor a new CatalogCodePanel object
    ///  @details Must be used in conjunction with Create.
    ///
    CatalogCodePanel( );

    /**
     * @brief Construct a new CatalogCodePanel object
     *
     * @param  parent	The parent window.
     * @param  id	An identifier for the panel. wxID_ANY is taken to mean a default.
     * @param  pos	The panel position. The value wxDefaultPosition indicates a default position, chosen by either the windowing system or wxWidgets, depending on platform.
     * @param  size	The panel size. The value wxDefaultSize indicates a default size, chosen by either the windowing system or wxWidgets, depending on platform.
     * @param  style	The window style.
     * @see wxPanel.
     */
    CatalogCodePanel( wxWindow* parent,
        wxWindowID id = SYMBOL_CATALOGCODEPANEL_IDNAME,
        const wxPoint& pos = SYMBOL_CATALOGCODEPANEL_POSITION,
        const wxSize& size = SYMBOL_CATALOGCODEPANEL_SIZE,
        long style = SYMBOL_CATALOGCODEPANEL_STYLE );

    ~CatalogCodePanel( );

    /**
     * @brief  Used for two-step panel construction.
     * Use with default constructor.
     *
     * @param  parent	The parent window.
     * @param  id	An identifier for the panel. wxID_ANY is taken to mean a default.
     * @param  pos	The panel position. The value wxDefaultPosition indicates a default position, chosen by either the windowing system or wxWidgets, depending on platform.
     * @param  size	The panel size. The value wxDefaultSize indicates a default size, chosen by either the windowing system or wxWidgets, depending on platform.
     * @param  style	The window style.
     * @return bool
     *
     */
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_CATALOGCODEPANEL_IDNAME,
        const wxPoint& pos = SYMBOL_CATALOGCODEPANEL_POSITION,
        const wxSize& size = SYMBOL_CATALOGCODEPANEL_SIZE,
        long style = SYMBOL_CATALOGCODEPANEL_STYLE );

    /**
     * @brief Add an intery to the wxGrid
     *
     * @return int index of the new row
     */
    int AddNewRow( );

    /**
     * @brief Creates the controls and sizers
     *
     */
    void CreateControls( );

    /**
     * @brief   Initialises member variables
     *
     */
    void Init( );

    /**
     * @brief creates a new empty catalog code
     *
     */
    wxXmlNode* InitNewCatCode( );

    /**
     * @brief  ID_CatalogCodePANEL
     *
     * @param event  Contains information about context menu events
     */
    void OnContextMenu( wxContextMenuEvent& event );

    /**
     * @brief ID_GRID
     *
     * @param event   Contains information about grid events
     */
    void OnCellChanged( wxGridEvent& event );

    /**
     * @brief shows context menu to add or remove CatalogCode entries
     *
     * @param event   Contains information about command events
     */
    void OnContextPopup( wxCommandEvent& event );

    void SetDataEditable( bool val );

    /**
     * @brief Load the grid with the CatalogCode items
     *
     */
    void ShowEntry( );

    /**
     * @brief
     *
     * @return bool ( autogenerated. Dummy. Always true )
     */
    static bool ShowToolTips( );

    /**
     * @brief gets the item from the CatalogCode list and populates the columns with it
     *
     * @param row index of row to populate
     */
    void ShowRow( int row );

    /**
     * @brief Set the Entry object
     *
     * @param entry  set the currently displayed entry to this
     */
    void UpdatePanel( );

private:

    wxGrid* m_grid;  ///< wxGrid to display item entries
    //    Catalog::Entry* m_entry; ///< pointer to the currently displayed entry 
    std::vector<wxXmlNode*> m_catCodeList;  ///< list containing each of the entries
};

#endif
// _CatalogCode_H_
