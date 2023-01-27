/* 
 * @file Project.h
 * @author Eddie Monroe
 * @brief 
 * @version 0.1
 * @date 2022-08-01
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
#ifndef Project_h
#define Project_h

#include "wx/string.h"
#include <wx/xml/xml.h>
#include "gui/ToolData.h"

namespace Utils { 

    Project* NewProjectInstance( );

    class Project
    { 
    public:
        Project( );
        ~Project( ) { if ( m_ProjectDoc ) { delete m_ProjectDoc; } };
        
        void InitProject( );

        wxString GetProjectFilename( ) { return m_projectFilename; };
        void SetProjectFilename( wxString name );

        wxString GetODTOutputFilename( );
        void SetODTOutputFilename( wxString outputFilename );

        wxString GetDesignFilename( );
        void SetDesignFilename( wxString albumFilename );;


        wxString GetImagePath( );
        void SetImagePath( wxString imagePath );

        //wxString GetCatalogFilename( );
        void SetCatalogFilename( wxString catalogFilename );

        wxString GetProjectCountryID( ){ return m_defaultCountryID; };
        void SetProjectCountryID( wxString str ){ m_defaultCountryID = str; };
        wxString GetProjectCatalogCode( ){ return m_defaultCatalogCode; };
        void SetProjectCatalogCode( wxString str ){ m_defaultCatalogCode = str; };

        // Load the Project xml file
        bool LoadProjectXML( );

        //Load the project xml attributes
        void LoadAttributes( wxXmlNode* thisObject );

        // save the project to an xml file
        void Save( );

        // make the filename absolute if its not already
        wxString MakeFileAbsolute( wxString filename );

        //inline ToolData* GetToolData( ){ return &m_toolData; };

        void SetDirty( bool state = true ) { m_dirty = state; };
        // Is project dirty?
        bool isDirty( ) { return m_dirty; };

    private:
        wxXmlDocument* m_ProjectDoc;
        wxString m_projectFilename;
        wxString m_ODTOutputFilename;
        wxString m_designFilename;
        wxString m_imagePath;
        wxString m_catalogFilename;
        wxString m_defaultCountryID;
        wxString m_defaultCatalogCode;
        bool m_dirty;

    };
}
#endif