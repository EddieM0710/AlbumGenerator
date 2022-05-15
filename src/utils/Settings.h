/**
 * @file Settings.h
 * @author Eddie Monroe
 * @brief
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 **************************************************/

#ifndef Settings_H
#define Settings_H

#include <wx/arrstr.h>
#include <wx/string.h>
#include "wx/xml/xml.h"


namespace Utils {

    /**
     * @brief Settings for the application
     *
     **************************************************/
    class Settings
    {
    public:
        Settings( );
        ~Settings( ) {};
        wxString GetConfigurationDirectory( ) { return m_configurationDirectory; };
        wxString GetImageDirectory( ) { return m_imageDirectory; };
        wxString GetCatalogID( ) { return m_catalogID; };
        wxString GetCountryID( ) { return m_countryID; };

        bool GetLoadLastFileAtStartUp( ) { return m_loadLastFileAtStartUp; };
        wxString GetLowerDivision( ) { return m_lowerDivision; };
        wxString GetLowerPeriod( ) { return m_lowerPeriod; };
        wxString GetMiddlePeriod( ) { return m_middlePeriod; };
        wxArrayInt* GetSortOrder( ) { return &m_sortOrder; };
        wxString GetUpperDivision( ) { return m_upperDivision; };
        wxString GetUpperPeriod( ) { return m_upperPeriod; };

        void SetConfigurationDirectory( wxString val ) { m_configurationDirectory = val.Trim( ); m_dirty = true; };
        void SetImageDirectory( wxString val ) { m_imageDirectory = val.Trim( );m_dirty = true; };
        void SetCatalogID( wxString val ) { m_catalogID = val.Trim( );m_dirty = true; };
        void SetCountryID( wxString val ) { m_countryID = val.Trim( );m_dirty = true; };
        void SetLoadLastFileAtStartUp( bool state = true ) { m_loadLastFileAtStartUp = state; };
        void SetLowerDivision( wxString val ) { m_lowerDivision = val.Trim( );m_dirty = true; };
        void SetLowerPeriod( wxString val ) { m_lowerPeriod = val.Trim( );m_dirty = true; };
        void SetMiddlePeriod( wxString val ) { m_middlePeriod = val.Trim( );m_dirty = true; };
        void SetUpperDivision( wxString val ) { m_upperDivision = val.Trim( );m_dirty = true; };
        void SetUpperPeriod( wxString val ) { m_upperPeriod = m_configurationDirectory.Trim( );m_dirty = true; };

        int GetNextSortClassification( int current );
        void SetSettingValue( wxString& setting, wxXmlNode* parent, wxString childName, wxString defaultVal );
        void SetLastFile( wxString file );
        inline wxString GetLastFile( ) { return m_lastFile; };

        void Load( );
        void Save( );


        void AddRecent( wxString filename );
        wxArrayString* GetRecentArray( ) { return &m_recentFiles; };
        void SetNbrRecentPreference( int val ) { m_nbrRecentPreference = val; m_dirty = true; };
        int GetNbrRecentPreference( ) { return m_nbrRecentPreference; };
        void SetDirty( bool state = true );
        bool isDirty( ) { return m_dirty; };
        void SetDefaults( );
        wxString GetCatCodePrefix( )
        {
            wxString str = "";
            if ( !m_countryID.IsEmpty( ) && !m_catalogID.IsEmpty( ) )
            {
                str = m_catalogID + ":" + m_countryID;
            }
            else
            {
                str = m_defaultCatalogID + ":" + m_defaultCountryID;
            }
            return str;
        };

    private:
        wxString m_lastFile;
        bool m_loadLastFileAtStartUp;
        wxString m_configurationDirectory;
        wxString m_imageDirectory;
        wxString m_countryID;
        wxString m_catalogID;
        wxArrayInt m_sortOrder;
        wxString m_lowerDivision;
        wxString m_upperDivision;
        wxString m_lowerPeriod;
        wxString m_middlePeriod;
        wxString m_upperPeriod;
        wxArrayString m_recentFiles;
        int m_nbrRecentPreference;

        const wxString m_defaultLastFile = "";
        const bool m_defaultloadLastFileAtStartUp = true;
        const wxString m_defaultConfigurationDirectory = "";
        const wxString m_defaultImageDirectory = "";
        const wxString m_defaultCountryID = "GB";
        const wxString m_defaultCatalogID = "SG";
        wxArrayInt m_defaultSortOrder;
        const wxString m_defaultLowerDivision = "1950";
        const wxString m_defaultUpperDivision = "2000";
        const wxString m_defaultLowerPeriod = "Antique";
        const wxString m_defaultMiddlePeriod = "Classical";
        const wxString m_defaultUpperPeriod = "Modern";
        //const wxArrayString m_defaultrecentFiles;
        const int m_defaultNbrRecentPreference = 4;
        bool m_dirty;
    };
}
#endif