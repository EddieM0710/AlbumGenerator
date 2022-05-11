/**
 * @file CatalogCode.cpp
 * @author Eddie Monroe
 * @brief
 * @version 0.1
 * @date 2021-03-01
 *
 * @copyright Copyright (c) 2021
 *
 **************************************************/


 // For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "catalog/CatalogCode.h"
#include <wx/strconv.h>
#include "utils/XMLUtilities.h"

namespace Catalog {

    bool CatalogCode::IsOK( )
    {
        if ( GetCatXMLNode( ) )
        {
            return true;
        }
        return false;
    }

    void CatalogCode::SetAttr( CatalogCodeTypes type, wxString val )
    {
        if ( IsOK( ) )
        {
            Utils::SetAttrStr( GetCatXMLNode( ), CC_CatalogCodeNames[ type ], val );
        };
    }

    wxString CatalogCode::GetAttr( CatalogCodeTypes type )
    {
        if ( IsOK( ) )
        {
            wxXmlAttribute* attr = Utils::GetAttribute( GetCatXMLNode( ), CC_CatalogCodeNames[ type ] );
            if ( attr )
            {
                return attr->GetValue( );
            }
        }
        return wxString( "" );
    }

    void CatalogCode::SetCatalog( wxString val )
    {
        SetVal( CC_Catalog, val );
    };

    void CatalogCode::SetCountry( wxString val )
    {
        SetVal( CC_Country, val );
    };

    void CatalogCode::SetID( wxString val )
    {
        SetVal( CC_ID, val );
    };



    wxString CatalogCode::GetCatalog( )
    {
        return GetAttr( CC_Catalog );
    };

    wxString CatalogCode::GetCountry( )
    {
        return GetAttr( CC_Country );
    };

    wxString CatalogCode::GetID( )
    {
        return GetAttr( CC_ID );
    };


    wxXmlNode* CatalogCode::GetData( wxVector<wxVariant>* data )
    {
        data->push_back( GetCatalog( ) );
        data->push_back( GetCountry( ) );
        data->push_back( GetID( ) );
        return GetCatXMLNode( );
    }
}