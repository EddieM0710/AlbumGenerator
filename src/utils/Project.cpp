/**
 * @file Project.cpp
 * @author Eddie Monroe ( you@domain.com )
 * @brief
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

#include <iostream>
#include <vector>
#include <wx/filename.h>
#include <wx/filefn.h> 
#include <wx/wfstream.h>

#include "utils/Project.h"

#include "Defs.h"
#include "utils/Settings.h"

#include "catalog/CatalogList.h"
#include "catalog/CatalogData.h"
#include "catalog/CatalogVolume.h"
#include "design/DesignDefs.h"
#include "design/AlbumVolume.h"
#include "design/AlbumList.h"
#include "design/AlbumBase.h"
#include "design/AlbumData.h"
#include "collection/CollectionData.h"

#include "gui/CatalogTreeCtrl.h"
#include "gui/AlbumTreeCtrl.h"
#include "gui/StampToolFrame.h"

 //#include "mount/StampMount.h"

namespace Utils {

    Project::Project( )
    {
        m_ProjectDoc = ( wxXmlDocument* ) 0;
    }
    void Project::InitProject( )
    {
        InitDefs( );
        SetDirty( false );
    }

    // 

    wxString Project::GetImagePath( )
    {
        return m_imagePath;
    };
    void Project::SetImagePath( wxString imagePath )
    {
        m_imagePath = imagePath;
        m_dirty = true;
    };

    wxString Project::GetDesignFilename( )
    {
        return m_designFilename;
    };

    //

    void Project::SetDesignFilename( wxString albumFilename )
    {
        m_designFilename = albumFilename;
        m_dirty = true;
    };

    // void Project::SetCatalogFilename( wxString catalogFilename )
    // {
    //     if ( m_catalogFilename.Cmp( catalogFilename ) )
    //     {
    //         m_catalogFilename = catalogFilename;
    //         SetDirty( );
    //     }
    // };

    //
    void Project::SetCaption( )
    {
        StampToolFrame* frame = GetFrame( );
        if ( frame )
        {
            GetSettings( )->SetLastFile( m_projectFilename );
            frame->SetCaption( GetSettings( )->GetLastFile( ) );
        }
    }
    void Project::SetProjectFilename( wxString name )
    {
        m_projectFilename = name;
        GetSettings( )->SetLastFile( m_projectFilename );
        SetCaption( );

    };

    //

    wxString Project::MakeFileAbsolute( wxString filename )
    {
        wxFileName newFile( filename );
        if ( !newFile.IsAbsolute( ) )
        {
            newFile.MakeAbsolute( );
        }
        return newFile.GetFullPath( );
    }



    //

    bool Project::LoadProjectXML( )
    {
        wxFileName projFile( m_projectFilename );
        wxString str;

        projFile.DirName( str );

        if ( projFile.FileExists( ) )
        {
            if ( !projFile.IsAbsolute( ) )
            {
                projFile.MakeAbsolute( );
            }
        }
        else
        {
            //setup new files
            return false;
        }

        wxString cwd = projFile.GetPath( );
        wxSetWorkingDirectory( cwd );

        m_ProjectDoc = new wxXmlDocument( );
        wxFileInputStream stream( m_projectFilename );
        if ( !stream.IsOk( ) )
        {
            return false;
        }
        //return Load(stream, encoding, flags);


        if ( !m_ProjectDoc->Load( stream ) )
        {
            ReportError( "Project::Load", "error loading Prokect xml file.", true );
            return false;
        }

        wxXmlNode* projectRoot = m_ProjectDoc->GetRoot( );
        wxString name = projectRoot->GetName( );
        if ( name.Cmp( "Project" ) )
        {
            // std::cout << "Initial node must be <Project>" << "\n";
            // std::cout << "Found \"" << name << "\" instead.\n";
            return false;
        }
        LoadAttributes( projectRoot );

        // // Get Collections
        // wxXmlNode* collectionNode = FirstChildElement( projectRoot, "CollectionList" );
        // if ( collectionNode )
        // {
        //     Inventory::CollectionData* collectionData = GetCollectionList( );
        //     wxString name = collectionNode->GetAttribute( "Filename", "" );
        //     collectionData->SetFilename( name );
        // }

        // Get Albums
        wxXmlNode* listNode = FirstChildElement( projectRoot, "AlbumList" );
        Design::AlbumList& albumList = GetAlbumData( )->GetAlbumList( );

        albumList.ClearAlbumVolumeArray( );
        if ( listNode )
        {
            wxXmlNode* album = FirstChildElement( listNode, "Album" );
            if ( !album )
            {
                album = FirstChildElement( listNode, "Volume" );
            }
            if ( !album )
            {
                std::cout << "No album files found.\n";
            }
            while ( album )
            {
                wxString name = album->GetAttribute( "FileName" );

                wxFileName albumFile( name );

                if ( albumFile.FileExists( ) )
                {

                    if ( albumFile.IsAbsolute( ) )
                    {
                        albumFile.MakeRelativeTo( cwd );
                    }

                    Design::AlbumVolume* albumVolume = GetAlbumData( )->NewAlbumVolume( );
                    albumVolume->SetAlbumFilename( albumFile.GetFullPath( ) );
                }
                else
                {
                    std::cout << "Volume " << name << " dosen't exist.\n";
                }

                album = album->GetNext( );
            }
        }

        // Get Mounts
        wxXmlDocument* mountDoc = GetCatalogData( )->LoadMountCSV( );

        // Get Catalogs
        wxXmlNode* catListNode = FirstChildElement( projectRoot, "CatalogList" );
        Catalog::CatalogList* catalogList = GetCatalogData( )->GetCatalogList( );

        catalogList->ClearCatalogArray( );
        if ( catListNode )
        {
            wxXmlNode* volume = FirstChildElement( catListNode, "Catalog" );
            if ( !volume )
            {
                volume = FirstChildElement( catListNode, "Section" );
                if ( !volume )
                {
                    volume = FirstChildElement( catListNode, "Volume" );
                }
            }
            while ( volume )
            {
                wxString name = volume->GetAttribute( "FileName" );

                wxFileName catFile( name );

                if ( catFile.FileExists( ) )
                {
                    if ( catFile.IsAbsolute( ) )
                    {
                        catFile.MakeRelativeTo( cwd );
                    }
                    Catalog::CatalogVolume* volumeData = GetCatalogData( )->GetCatalogList( )->NewCatalogVolume( );
                    //GetCatalogData( )->NewCatalogVolume( );

                    volumeData->SetVolumeFilename( catFile.GetFullPath( ) );
                }
                else
                {
                    std::cout << "Volume " << name << " dosen't exist.\n";
                }

                volume = volume->GetNext( );
            }
        }


        GetSettings( )->SetLastFile( m_projectFilename );

        SetDirty( false );
        return true;
    }

    // AddMount( Catalog::CatalogVolume* volumeData, wxXmlDocument* mountDoc )
    // {
    //     wxXmlDocument* catDoc = volumeData->GetDoc( );
    // }


    //

    void Project::LoadAttributes( wxXmlNode* thisObject )
    {
        const wxXmlAttribute* attr = thisObject->GetAttributes( );
        wxFileName filename;
        while ( attr )
        {
            wxString name = attr->GetName( );
            wxString val = attr->GetValue( );

            if ( !name.Cmp( "OutputName" ) )
            {
                //               m_ODTOutputFilename = MakeFileAbsolute( val );
            }
            else if ( !name.Cmp( "Album" ) )
            {
                m_designFilename = MakeFileAbsolute( val );
            }
            else if ( !name.Cmp( "ImagePath" ) )
            {
                m_imagePath = MakeFileAbsolute( val );
                SetImagePath( m_imagePath );
            }
            // else if ( !name.Cmp( "Catalog" ) )
            // {
            //     m_catalogFilename = MakeFileAbsolute( val );
            // }
            else if ( !name.Cmp( "Country" ) )
            {
                m_defaultCountryID = val;
            }
            else if ( !name.Cmp( "CatalogCode" ) )
            {
                m_defaultCatalogCode = val;
            }
            attr = attr->GetNext( );
        }
    }



    void Project::FileNewProject( wxString sptName )
    {
        GetProject( )->SetProjectFilename( sptName );
        wxString lastFile = wxGetCwd( );
        lastFile += "/" + sptName;
        GetSettings( )->SetLastFile( lastFile );

        //clear catalog volume wxList
        GetCatalogData( )->GetCatalogList( )->ClearCatalogArray( );
        //clear dialog volume list
        GetAlbumData( )->GetAlbumList( ).ClearAlbumVolumeArray( );
        //clear catalog tree
        GetCatalogTreeCtrl( )->ClearCatalogTree( );
        //GetAlbumPageTreeCtrl( )->ClearCatalogTree( );
        //clear dialog tree
        GetAlbumTreeCtrl( )->ClearDesignTree( );

    }

    void Project::Save( )
    {

        if ( wxFileExists( m_projectFilename ) )
        {
            wxFileName bakFile( m_projectFilename );
            bakFile.SetExt( "bak.spt" );
            wxRenameFile( m_projectFilename, bakFile.GetFullName( ), true );
        }
        if ( m_ProjectDoc )
        {
            delete m_ProjectDoc;
        }
        m_ProjectDoc = new wxXmlDocument( );
        wxXmlNode* root = new wxXmlNode( wxXML_ELEMENT_NODE, "Project" );
        root->AddAttribute( "Country", GetProjectCountryID( ) );
        root->AddAttribute( "CatalogCode", GetProjectCatalogCode( ) );
        root->AddAttribute( "ImagePath", m_imagePath );

        wxXmlNode* newNode = NewNode( root, "AlbumList" );
        Design::AlbumList albumList = GetAlbumData( )->GetAlbumList( );
        Design::AlbumVolumeArray* albumArray = albumList.GetAlbumVolumeArray( );

        for ( Design::AlbumVolumeArray::iterator it = std::begin( *albumArray );
            it != std::end( *albumArray );
            ++it )
        {
            Design::AlbumVolume* volume = ( Design::AlbumVolume* ) ( *it );
            //newNode->AddAttribute( "FileName", m_designFilename );
            wxString filename = volume->GetAlbumFilename( );
            wxString cwd = wxGetCwd( );
            wxFileName sectFile( filename );
            sectFile.MakeRelativeTo( cwd );
            wxXmlNode* newVolume = NewNode( newNode, "Album" );
            newVolume->AddAttribute( "FileName", sectFile.GetFullPath( ) );
        }

        newNode = NewNode( root, "CatalogList" );
        //Catalog::CatalogVolume* volumeData = 
        Catalog::CatalogList* catalogList = GetCatalogData( )->GetCatalogList( );
        Catalog::CatalogVolumeArray* catalogArray = catalogList->GetCatalogArray( );

        for ( Catalog::CatalogVolumeArray::iterator it = std::begin( *catalogArray );
            it != std::end( *catalogArray );
            ++it )
        {
            Catalog::CatalogVolume* volume = ( Catalog::CatalogVolume* ) ( *it );
            wxString filename = volume->GetVolumeFilename( );
            wxString cwd = wxGetCwd( );
            wxFileName sectFile( filename );
            sectFile.MakeRelativeTo( cwd );
            wxXmlNode* newVolume = NewNode( newNode, "Volume" );
            wxString sectFileFullPath = sectFile.GetFullPath( );
            newVolume->AddAttribute( "FileName", sectFile.GetFullPath( ) );
        }
        m_ProjectDoc->SetRoot( root );

        m_ProjectDoc->Save( m_projectFilename );

        GetCatalogData( )->FileSave( );
        GetAlbumData( )->FileSave( );

        SetDirty( false );
    }

    // Load the Catalog and Design data then populate trees
    void Project::LoadData( )
    {
        bool state = wxLog::IsEnabled( );
        //GetCollectionData( )->LoadData( );
        GetCatalogData( )->LoadData( );
        GetAlbumData( )->LoadData( );
        GetCatalogData( )->SetCollectionListStrings( );
        GetCatalogData( )->SetCollectionListSelection( );
    }

    void Project::FileOpenProject( wxString filename )
    {
        SetProjectFilename( filename );
        wxFileName sptFile( filename );
        wxString path = sptFile.GetPath( );
        wxSetWorkingDirectory( sptFile.GetPath( ) );
        GetSettings( )->SetLastFile( filename );
        LoadProjectXML( );
        LoadData( );
    }

    void Project::FileSaveProject( )
    {
        GetSettings( )->Save( );
        Save( );
    }

    void Project::FileSaveAsProject( wxString filename )
    {
        SetProjectFilename( filename );
        GetSettings( )->SetLastFile( filename );
        FileSaveProject( );
    }

}

