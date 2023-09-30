/**
 * @file CatalogList.h
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

#ifndef CatalogList_H
#define CatalogList_H

#include "wx/xml/xml.h"
#include <wx/string.h>
#include <wx/treectrl.h>
#include <vector>

#include "Defs.h"

#include "catalog/CatalogDefs.h"
#include "catalog/CatalogVolume.h"


namespace Catalog {

    class CatalogVolume;

    int WayToSort( Catalog::CatalogVolume* sect1, Catalog::CatalogVolume* sect2 );

    ///  @brief The array that contains all the catalogs
    ///  
    class CatalogList
    {


    public:

        ///  @brief Construct a new Catalog List object
        ///  
        CatalogList( ) {
            m_currVolume = ( CatalogVolume* ) 0;
        };


        ///  @brief Destroy the Catalog List object
        ///  
        ~CatalogList( ) { };

        //   void BuildVolumeNameStrings( );
        //   void SortNameArray( );
        void dumpArray( wxArrayString& array );

        ///  @brief 
        ///  
        ///  @return true 
        ///  @return false 
      //  bool IsOK( );

        ///  @brief Crete a new catalog volume and add it to the list
        ///  
        ///  @return Catalog::CatalogVolume* 
       // Catalog::CatalogVolume* NewCatalogVolume( );

        Catalog::CatalogVolume* FindVolume( wxString str );
        //    int FindVolumeNameArrayNdx( wxString str );

            ///  @brief Get the Catalog Volume object
            ///  
            ///  @return Catalog::CatalogVolume* 
        Catalog::CatalogVolume* GetCatalogVolume( );

        void Insert( wxString str, Catalog::CatalogVolume* vol );

        ///  @brief Save all the catalog volumes
        ///  
        void SaveCatalogVolumes( );

        ///  @brief Load all the catalog volumes
        ///  
//        void Load( );

        ///  @brief Remove all the elements of thearray and delete it.
        ///  
        ///  @return true 
        ///  @return false 
        bool ClearCatalogArray( );

        ///  @brief Get the array cotaining volume names
        ///  
        ///  @return wxArrayString& 
        // wxArrayString& GetVolumeNameStrings( ) {
        //     return m_volumeNameStrings;
        // };

        ///  @brief Set the ndx of the currently selected volume
        ///  
        ///  @param i 
        void SetCatalogVolume( CatalogVolume* vol );

        ///  @brief Get the array of catalog volumes
        ///  
        ///  @return Catalog::CatalogVolumeArray* 
        Catalog::CatalogVolumeArray* GetCatalogArray( ) {
            return &m_catalogArray;
        };

        CatalogVolumeArray::iterator FindVolumeIterator( wxString str );

        void Insert( int id, wxTreeItemId treeId );
        CatalogMenuIDArray::iterator FindMenuIDIterator( int id );
        wxTreeItemId FindMenuID( int id );

        // int FindVolume( wxString str );
        wxXmlNode* AddChild( wxXmlNode* child );


    private:
        CatalogMenuIDArray m_menuIDArray;

        Catalog::CatalogVolumeArray m_catalogArray;
        //int m_catalogVolumeNdx;
        Catalog::CatalogVolume* m_currVolume;
        // wxArrayString m_volumeNameStrings;
    };
}
#endif