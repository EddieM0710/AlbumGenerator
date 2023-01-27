/**
 * @file Defs.cpp
 * @author Eddie Monroe ( you@domain.com )
 * @brief Resting place for Global stuff
 * @version 0.1
 * @date 2021-02-24
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

 // For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "Defs.h"
#include "CatalogDefs.h"
#include "DesignDefs.h"
#include "CatalogSectionData.h"
#include "Settings.h"
#include "utils/Project.h"
#include "StampToolApp.h"


wxDECLARE_APP( StampToolApp );

bool Dirty = false;

void SetDirty( bool state ) { Dirty = state; };
bool IsDirty( ) { return Dirty; };

// global declaration of application data 
//ToolData* m_toolData;

Utils::Settings* GetSettings( )
{ 

    return wxGetApp( ).GetToolDate( )->GetSettings( );

};

Utils::Project* GetProject( )
{ 
    return wxGetApp( ).GetToolDate( )->GetProject( );
}

inline ToolData* GetToolData( ){ return wxGetApp( ).GetToolDate( ); };

Design::DesignData* GetDesignData( ) { return GetToolData( )->GetDesignData( ); };
Catalog::CatalogSectionData* GetCatalogSectionData( ) 
{ 
    ToolData* genData = GetToolData( );
    if ( genData )
    { 
        return genData->GetCatalogSectionData( ); 
    }
    return ( Catalog::CatalogSectionData* )0;
    };
CatalogTreeCtrl* GetCatalogTreeCtrl( ){ return GetToolData( )->GetCatalogTreeCtrl( ); };
DesignTreeCtrl* GetDesignTreeCtrl( ){ return GetToolData( )->GetDesignTreeCtrl( ); };
AlbumImagePanel* GetAlbumImagePanel( ){ return GetToolData( )->GetAlbumImagePanel( ); };

void InitDefs( )
{ 
    Catalog::InitCatalogDefs( );
    Design::InitDesignDefs( );
}

void ReportError(  wxString funct, wxString msg, bool fatal )
{ 
    wxString status = "";
    if ( fatal )    
    { 
        status = "fatal";
    }
    wxLogDebug( "Warning: %s %s %s\n",funct, msg, status);
}