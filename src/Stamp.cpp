/**
 * @file Stamp.cpp
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

#include "CatalogCode.h"
#include "Settings.h"
#include "Stamp.h"
#include <wx/datetime.h>
#include <wx/strconv.h>
#include <wx/tokenzr.h>

inline bool Stamp::IsOK( )
{
    XMLElement* ele = GetElement( );
    wxString str;
    if ( ele )
    {
        str = ele->Value( );
        str = NodeNameStrings.Item( NT_Stamp );
    }
    if ( GetElement( )
        && !NodeNameStrings.Item( NT_Stamp ).Cmp( GetElement( )->Value( ) ) )
    {
        m_OK = true;
        return m_OK;
    }
    m_OK = false;
    return m_OK;
};

void Stamp::SetAttr( DataTypes type, wxString val )
{
    if ( IsOK( ) )
    {
        this->GetElement( )->SetAttribute( DT_XMLDataNames[ type ].char_str( ),
            val.fn_str( ) );
    };
}

wxString Stamp::GetAttr( DataTypes type )
{
    if ( IsOK( ) )
    {
        const XMLAttribute* attr
            = this->GetElement( )->FindAttribute( DT_XMLDataNames[ type ] );
        if ( attr )
        {
            return wxString::FromUTF8Unchecked( attr->Value( ) );
        }
    }
    return wxString( "" );
}

StatusType Stamp::GetStatusType( )
{
    wxString status = GetAttr( DT_Status );
    for ( int i = ST_Checked; i < ST_NbrTypes; i++ )
    {
        wxString str = ST_StatusStrings[ i ];
        if ( !status.CmpNoCase( ST_StatusStrings[ i ] ) )
        {
            return ( StatusType )i;
        }
    }
    return ( StatusType )ST_Unchecked;
};

FormatType Stamp::GetFormatType( )
{
    wxString format = GetAttr( DT_Format );
    for ( int i = FT_FormatUnknown; i < FT_NbrTypes; i++ )
    {
        wxString str = FT_FormatStrings[ i ];
        if ( !format.CmpNoCase( FT_FormatStrings[ i ] ) )
        {
            return ( FormatType )i;
        }
    }
    return ( FormatType )FT_FormatUnknown;
}

DataTypes Stamp::FindDataType( wxString name )
{
    for ( int i = DT_ID_Nbr; i < DT_NbrTypes; i++ )
    {
        if ( !name.Cmp( DT_XMLDataNames[ i ] ) )
        {
            return ( DataTypes )i;
        }
    }
    return ( DataTypes )-1;
}

bool Stamp::IsMultiple( )
{
    FormatType format = GetFormatType( );
    if ( format == FT_Se_tenant || format == FT_Mini_Sheet
        || format == FT_Souvenir_Sheet || format == FT_Booklet
        || format == FT_Booklet_Pane )
    {
        return true;
    }
    return false;
}

wxString Stamp::GetYear( )
{
    wxDateTime dt;
    wxString dateStr = GetIssuedDate( );
    wxString::const_iterator end;
    if ( ( dt.ParseFormat( dateStr, "%Y-%m-%d", &end ) )
        || ( dt.ParseFormat( dateStr, "%Y", &end ) )
        || ( dt.ParseFormat( dateStr, "%Y-%m", &end ) ) )
    {
        int year = dt.GetYear( );
        wxString yearStr = wxString::Format( "%d", year );
        return yearStr;
    }
    return wxString( "Unknown" );
}

wxString Stamp::GetDecade( )
{
    wxString year = GetYear( );
    if ( !year.Cmp( "Unknown" ) )
    {
        return year;
    }

    double yd;
    year.ToDouble( &yd );
    int yi = yd / 10;
    yi = yi * 10;
    wxString decade = wxString::Format( "%ds", yi );
    return decade;
}

wxString Stamp::GetPeriod( )
{
    wxString year = GetYear( );
    if ( !year.Cmp( "Unknown" ) )
    {
        return year;
    }
    double yd;
    year.ToDouble( &yd );

    long lowerDivision;
    long upperDivision;
    wxString lowerDivisionStr = GetSettings( )->GetLowerDivision( );
    lowerDivisionStr.ToLong( &lowerDivision );
    wxString upperDivisionStr = GetSettings( )->GetUpperDivision( );
    upperDivisionStr.ToLong( &upperDivision );
    if ( yd < lowerDivision )
    {
        return GetSettings( )->GetLowerPeriod( );
    }
    else if ( yd >= upperDivision )
    {
        return GetSettings( )->GetUpperPeriod( );
    }
    else
    {
        return GetSettings( )->GetMiddlePeriod( );
    }
}
wxString Stamp::GetID( ) { return GetAttr( DT_ID_Nbr ); };

wxString Stamp::GetName( ) { return GetAttr( DT_Name ); };

wxString Stamp::GetCountry( ) { return GetAttr( DT_Country ); };
wxString Stamp::GetSeries( ) { return GetAttr( DT_Series ); };
wxString Stamp::GetCatalogCodes( ) { return GetAttr( DT_Catalog_Codes ); };
wxString Stamp::GetIssuedDate( ) { return GetAttr( DT_Issued_on ); };
wxString Stamp::GetExpiryDate( ) { return GetAttr( DT_Expiry_date ); };
wxString Stamp::GetWidth( ) { return GetAttr( DT_Width ); };
wxString Stamp::GetHeight( ) { return GetAttr( DT_Height ); };
wxString Stamp::GetPaper( ) { return GetAttr( DT_Paper ); };
wxString Stamp::GetWatermark( ) { return GetAttr( DT_Watermark ); };
wxString Stamp::GetEmission( ) { return GetAttr( DT_Emission ); };
wxString Stamp::GetFormat( ) { return GetAttr( DT_Format ); };
wxString Stamp::GetVariant( ) { return GetAttr( DT_Variant ); };
wxString Stamp::GetThemes( ) { return GetAttr( DT_Themes ); };
wxString Stamp::GetScore( ) { return GetAttr( DT_Score ); };
wxString Stamp::GetPrintRun( ) { return GetAttr( DT_Print_run ); };
wxString Stamp::GetPrinting( ) { return GetAttr( DT_Printing ); };
wxString Stamp::GetPerforation( ) { return GetAttr( DT_Perforation ); };
wxString Stamp::GetLink( ) { return GetAttr( DT_Link ); };
wxString Stamp::GetGum( ) { return GetAttr( DT_Gum ); };
wxString Stamp::GetFaceValue( ) { return GetAttr( DT_FaceValue ); };
wxString Stamp::GetDescription( ) { return GetAttr( DT_Description ); };
wxString Stamp::GetCurrency( ) { return GetAttr( DT_Currency ); };
wxString Stamp::GetColors( ) { return GetAttr( DT_Colors ); };
wxString Stamp::GetAccuracy( ) { return GetAttr( DT_Accuracy ); };
void Stamp::SetWidth( wxString val ) { SetAttr( DT_Width, val ); };
void Stamp::SetWatermark( wxString val ) { SetAttr( DT_Watermark, val ); };
void Stamp::SetVariant( wxString val ) { SetAttr( DT_Variant, val ); };
void Stamp::SetThemes( wxString val ) { SetAttr( DT_Themes, val ); };
void Stamp::SetSeries( wxString val ) { SetAttr( DT_Series, val ); };
void Stamp::SetScore( wxString val ) { SetAttr( DT_Score, val ); };
void Stamp::SetPrintRun( wxString val ) { SetAttr( DT_Print_run, val ); };
void Stamp::SetPrinting( wxString val ) { SetAttr( DT_Printing, val ); };
void Stamp::SetPerforation( wxString val ) { SetAttr( DT_Perforation, val ); };
void Stamp::SetPaper( wxString val ) { SetAttr( DT_Paper, val ); };
void Stamp::SetName( wxString val ) { SetAttr( DT_Name, val ); };
void Stamp::SetLink( wxString val ) { SetAttr( DT_Link, val ); };
void Stamp::SetIssuedDate( wxString val ) { SetAttr( DT_Issued_on, val ); };
void Stamp::SetID( wxString val ) { SetAttr( DT_ID_Nbr, val ); };
void Stamp::SetHeight( wxString val ) { SetAttr( DT_Height, val ); };
void Stamp::SetGum( wxString val ) { SetAttr( DT_Gum, val ); };
void Stamp::SetFormat( wxString val ) { SetAttr( DT_Format, val ); };
void Stamp::SetFaceValue( wxString val ) { SetAttr( DT_FaceValue, val ); };
void Stamp::SetExpiryDate( wxString val ) { SetAttr( DT_Expiry_date, val ); };
void Stamp::SetEmission( wxString val ) { SetAttr( DT_Emission, val ); };
void Stamp::SetDescription( wxString val ) { SetAttr( DT_Description, val ); };
void Stamp::SetCurrency( wxString val ) { SetAttr( DT_Currency, val ); };
void Stamp::SetCountry( wxString val ) { SetAttr( DT_Country, val ); };
void Stamp::SetColors( wxString val ) { SetAttr( DT_Colors, val ); };
void Stamp::SetCatalogCodes( wxString val ) { SetAttr( DT_Catalog_Codes, val ); };
void Stamp::SetAttr( DataTypes type, wxString val );
void Stamp::SetAccuracy( wxString val ) { SetAttr( DT_Accuracy, val ); };

wxString Stamp::GetClassificationName( Stamp* stamp, NodeType type )
{
    switch ( type )
    {
    case NT_Period:
    {
        return stamp->GetPeriod( );
        break;
    }
    case NT_Decade:
    {
        return stamp->GetDecade( );
        break;
    }
    case NT_Year:
    {
        return stamp->GetYear( );
        break;
    }
    case NT_Emission:
    {
        return stamp->GetEmission( );
        break;
    }
    case NT_Catalog:
    {
        return "Catalog";
        break;
    }
    case NT_Country:
    {
        return stamp->GetCountry( );
        break;
    }
    default:
        return wxString( "" );
    }
}

XMLElement* Stamp::AddSpecimen( )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        return ele->InsertNewChildElement( NodeNameStrings[ NT_Specimen ] );
    }
    return ( XMLElement* )0;
}

void Stamp::DeleteSpecimen( XMLElement* deleteThisNode )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        ele->DeleteChild( deleteThisNode );
    }
}

bool Stamp::HasChildSpecimen( )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        if ( ele->FirstChildElement( NodeNameStrings[ NT_Specimen ] ) )
        {
            return true;
        }
    }
    return false;
}
XMLElement* Stamp::GetFirstChildSpecimen( )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        return ele->FirstChildElement( NodeNameStrings[ NT_Specimen ] );
    }
    return ( XMLElement* )0;
}
XMLElement* Stamp::GetNextChildSpecimen( )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        return ele->NextSiblingElement( NodeNameStrings[ NT_Specimen ] );
    }
    return ( XMLElement* )0;
}


XMLElement* Stamp::AddCode( )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        return ele->InsertNewChildElement( NodeNameStrings[ NT_CatalogCode ] );
    }
    return ( XMLElement* )0;
}

void Stamp::DeleteCode( XMLElement* deleteThisNode )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        ele->DeleteChild( deleteThisNode );
    }
}

bool Stamp::HasChildCode( )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        if ( ele->FirstChildElement( NodeNameStrings[ NT_CatalogCode ] ) )
        {
            return true;
        }
    }
    return false;
}

XMLElement* Stamp::GetFirstChildCode( )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        return ele->FirstChildElement( NodeNameStrings[ NT_CatalogCode ] );
    }
    return ( XMLElement* )0;
}

XMLElement* Stamp::GetNextChildCode( XMLElement* ele )
{
    if ( ele )
    {
        return ele->NextSiblingElement( NodeNameStrings[ NT_CatalogCode ] );
    }
    return ( XMLElement* )0;
}

XMLElement* Stamp::GetCodeForCatalog( const char* catalog )
{
    XMLElement* ele = GetElement( );
    if ( ele )
    {
        XMLElement* childCode = ele->FirstChildElement( NodeNameStrings[ NT_CatalogCode ] );
        if ( childCode )
        {
            const XMLAttribute* attr = childCode->FindAttribute( CC_CatalogCodeNames[ CC_Catalog ] );
            if ( attr )
            {
                const char* code = attr->Value( );
                if ( !strncmp( catalog, code, strlen( catalog ) ) )
                {
                    return childCode;
                }
            }
        }
    }
    return ( XMLElement* )0;
}


void Stamp::ProcessCatalogCodes(  )
{
    if ( !HasChildCode( ) )
    {
        wxString catCodes = GetCatalogCodes();
        if ( catCodes.IsEmpty() )
        {
            return;
        }

        wxStringTokenizer tokenizer( catCodes, "," );

        wxString valStr;
        wxString rest;
        while ( tokenizer.HasMoreTokens( ) )
        {
            valStr = tokenizer.GetNextToken( );
            if ( valStr.StartsWith( wxT( "\"" ), &rest ) )
                valStr = rest;
            if ( valStr.EndsWith( wxT( "\"" ), &rest ) )
                valStr = rest;

            // "Mi:US 1, Sn:US 1b, Yt:US 1, Sg:US 1, Un:US 1b"
            valStr.Trim( );
            valStr.Trim( false );

            int pos = valStr.Find( ":" );
            wxString catalog = valStr.Mid( 0, pos );
            valStr = valStr.Mid( pos + 1 );
            pos = valStr.Find( " " );
            wxString country = valStr.Mid( 0, pos );
            wxString id = valStr.Mid( pos + 1 );

            XMLElement* catCodeElement = GetElement( )->InsertNewChildElement( NodeNameStrings.Item( NT_CatalogCode ) );

            CatalogCode * catCodeNode = new CatalogCode( catCodeElement );
            catCodeNode->SetCatalog( catalog );
            catCodeNode->SetCountry( country );
            catCodeNode->SetID( id );
        }
    }
}
