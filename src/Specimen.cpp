/**
 * @file Specimen.cpp
 * @author Eddie Monroe ()
 * @brief 
 * @version 0.1
 * @date 2021-02-25
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

#include "Specimen.h"
#include "XMLUtilities.h"
#include <wx/strconv.h>

bool Specimen::IsOK( )
{
    if ( GetElement( ) )
    {
        if ( IsNodeType( GetElement( ), NT_Specimen ) )
        {
            return true;
        }
    }
    return false;
}

void Specimen::SetAttr( ItemDataTypes type, wxString val )
{
    if ( IsOK( ) )
    {
        GetElement( )->SetAttribute( ItemDataNames[ type ].char_str( ),
                                  val.fn_str( ) );
    };
}

wxString Specimen::GetAttr( ItemDataTypes type )
{
    if ( IsOK( ) )
    {
        const XMLAttribute *attr
            = this->GetElement( )->FindAttribute( ItemDataNames[ type ] );
        if ( attr )
        {
            return wxString::FromUTF8Unchecked( attr->Value( ) );
        }
    }
    return wxString( "" );
}

XMLElement *Specimen::GetData( wxVector<wxVariant> *data )
{
    data->push_back( GetType( ) );
    data->push_back( GetCondition( ) );
    data->push_back( GetValue( ) );
    data->push_back( GetLocation( ) );
    data->push_back( GetRemarks( ) );
    return GetElement( );
}