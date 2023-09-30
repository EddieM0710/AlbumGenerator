/**
 * @file CatalogData.cpp
 * @author Eddie Monroe
 * @brief
 * @version 0.1
 * @date 2022-03-31
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
 */

#include "catalog/CatalogData.h"
#include "catalog/CatalogVolume.h"
#include "catalog/Entry.h"
#include "gui/CatalogTreeCtrl.h"
#include "gui/CatalogPanel.h"
#include "gui/AlbumPanel.h"
#include "gui/StampDescriptionPanel.h"
#include "utils/Project.h"
#include "Defs.h" 
#include "catalog/StampMount.h"

namespace Catalog
{

    ///  @brief Create anew empty Catalog
    ///  
    ///  @return Catalog::CatalogVolume* 
    Catalog::CatalogVolume* CatalogData::NewCatalogVolume( )
    {
        return NewCatalogVolumeInstance( );
    };

    Catalog::CatalogVolume* CatalogData::NewCatalogVolume( wxString filename )
    {
        CatalogVolume* vol = NewCatalogVolumeInstance( );
        vol->SetFilename( filename );
        vol->Load( );
        wxString volName = vol->GetName( );
        Catalog::CatalogList* list = GetCatalogData( )->GetCatalogList( );
        list->SetCatalogVolume( vol );
        return vol;
    }

    ///  @brief Open a catalog file
    ///  
    ///  @param filename 
    void CatalogData::FileOpen( wxString filename )
    {
        NewCatalogVolume( filename );
        // GetCatalogList( )->BuildVolumeNameStrings( );
        // UpdateCatalogVolumeStrings( );
        // LoadCatalogTree( );
    }

    ///  @brief Save a catalog file
    ///  
    void CatalogData::FileSave( )
    {
        m_catalogList.SaveCatalogVolumes( );
    }


    InventoryPanel* CatalogData::GetInventoryPanel( ) {
        return GetDescriptionPanel( )->GetInventoryPanel( );
    };

    void CatalogData::LoadCatalogTree( )
    {

        GetCatalogTreeCtrl( )->LoadTree( );
    }

    bool CatalogData::ImportCSV( wxString csvFilename )
    {
        wxFileName csvFile( csvFilename );
        wxString ext = csvFile.GetExt( );
        if ( !ext.CmpNoCase( "csv" ) )
        {

            wxString cwd = wxGetCwd( );
            wxFileName catalogFile;// = csvFile;
            catalogFile.SetPath( cwd );

            wxString name = csvFile.GetName( );
            catalogFile.SetName( name );
            catalogFile.SetExt( "cat" );

            Catalog::CatalogVolume* catalogVolume = NewCatalogVolumeInstance( );
            wxString fullPath = catalogFile.GetFullPath( );
            wxString fullName = catalogFile.GetFullName( );
            wxString path = catalogFile.GetPath( );
            catalogVolume->SetFilename( catalogFile.GetFullPath( ) );

            bool readStatus = catalogVolume->LoadCSV( csvFile.GetFullPath( ) );
            if ( readStatus )
            {
                //  GetCatalogList( )->BuildVolumeNameStrings( );
                //  UpdateCatalogVolumeStrings( );
                //  GetCatalogVolume( )->EditDetailsDialog( m_catalogTreePanel );

               //   GetCatalogData( )->LoadCatalogTree( );
            }
            return readStatus;
        }
        return false;
    }

    ///  @brief  Load the Catalog data then populate trees
    ///  
    void CatalogData::LoadData( )
    {
        // m_catalogList.Load( );
        // GetCatalogList( )->BuildVolumeNameStrings( );
        // UpdateCatalogVolumeStrings( );
        LoadCatalogTree( );
    }

    wxXmlDocument* CatalogData::LoadMountCSV( )
    {
        wxString mountFile = "StampMounts.csv";
        wxXmlDocument* res = GetStampMountData( )->LoadXML( );
        return res;
    }

    void CatalogData::LoadNew( wxString catFile )
    {
        // Catalog::CatalogVolume* volume = GetCatalogList( )->NewCatalogVolume( );
        // volume->SetVolumeFilename( catFile );
        // LoadCatalogTree( );
        SetDirty( );
    }

    void CatalogData::SetCurrentStamp( wxXmlNode* xmlNode )
    {
        m_stamp = xmlNode;
        GetDescriptionPanel( )->UpdatePanel( );
        GetDescriptionPanel( )->Show( );
    };

    void CatalogData::SetCollectionListStrings( )
    {
        //       m_catalogTreePanel->SetCollectionListStrings( );
    }
    void CatalogData::SetCollectionListSelection( )
    {
        m_catalogTreePanel->SetCollectionListSelection( );
    }

    // void CatalogData::UpdateCatalogVolumeStrings( )
    // {
    //     m_catalogTreePanel->SetVolumeListStrings( m_catalogList.GetVolumeNameStrings( ) );
    //     Catalog::CatalogVolume* vol = m_catalogList.GetCatalogVolume( );
    //     if ( vol )
    //     {
    //         wxString name = vol->GetVolumeName( );
    //         m_catalogTreePanel->SetVolumeListSelection( name );
    //     }
    // }
}