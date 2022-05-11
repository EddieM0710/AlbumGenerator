/**
 * @file CSV.cpp
 * @author Eddie Monroe ()
 * @brief This file contains the class that reads .csv files
 * and loads them into an XML structure.
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

#include <wx/arrimpl.cpp>
#include <wx/msgdlg.h>
#include "catalog/CatalogCode.h"
#include "catalog/Classification.h"
#include "utils/CSV.h"
#include "utils/Settings.h"
#include "Defs.h"
#include "catalog/Stamp.h"
#include <wx/tokenzr.h>
#include "catalog/CatalogData.h"
#include "utils/XMLUtilities.h"
#include "AlbumGenApp.h"

wxDECLARE_APP( AlbumGenApp );

namespace Utils {

    bool CSVData::ReadDataFile( wxString& filename )
    {
        bool status = false;
        m_filename = filename;

        wxFileInputStream l_file( filename );

        if ( l_file.IsOk( ) )
        {
            wxTextInputStream text( l_file );
            // process Header
            wxString inLine = text.ReadLine( );
            m_lineCnt = 0;

            // find the line that begins with "Name"
            while ( !inLine.StartsWith( "Name" ) && !l_file.Eof( ) )
            {
                inLine = text.ReadLine( );
                m_lineCnt++;
            }
            if ( !l_file.Eof( ) )
            {
                // comma separated Variables on line; i, e, .csv file
                wxStringTokenizer tokenizer( inLine, "," );

                wxString colStr;
                while ( tokenizer.HasMoreTokens( ) )
                {
                    colStr = tokenizer.GetNextToken( );
                    wxString rest;
                    if ( colStr.StartsWith( wxT( "\"" ), &rest ) )
                        colStr = rest;
                    if ( colStr.EndsWith( wxT( "\"" ), &rest ) )
                        colStr = rest;
                    m_csvColName.push_back( colStr );
                }
            }

            // figure out how to map the csv file data to the stamp array
            MakeColMap( );

            if ( ReadTextInStream( l_file, text ) )
            {
                status = true;
            }
        }
        if ( !status )
        {
            wxString caption = "CSV Load Error";
            wxString message = wxString::Format( "Error tryng to load csv file %s.", m_filename );
            wxMessageDialog* msg = new wxMessageDialog( wxGetApp( ).GetFrame( ),
                message, caption, wxOK | wxCENTRE | wxICON_ERROR );
            msg->ShowModal( );
            msg->~wxMessageDialog( );
        }
        return status;
    };

    void CSVData::DoLoad( wxString& filename, wxXmlNode* catalogData )
    {
        m_nodeData = catalogData;

        ReadDataFile( filename );
    };


    bool CSVData::GetIDNbr( wxString catCodes, wxString& id )
    {
        wxStringTokenizer tokenizer( catCodes, "," );
        wxString codePrefix = GetSettings( )->GetCatCodePrefix( );
        //std::cout << "GetIDNbr   codePrefix:>"<< codePrefix << " < catCodes:>" << catCodes << "<\n";
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
            valStr = valStr.Trim( );
            valStr = valStr.Trim( false );
            int len = codePrefix.Length( );
            if ( len )
            {
                int pos = valStr.Find( codePrefix );//               .StartsWith( codePrefix, &rest );
                if ( pos != wxNOT_FOUND )
                {
                    valStr = valStr.substr( pos );
                    valStr = valStr.Trim( );
                    valStr = valStr.Trim( false );
                    //std::cout << "GetIDNbr "<< catCodes << " found id >" << valStr << "<\n";
                    id = valStr;
                    return true;
                }

            }
        }
        //std::cout << "GetIDNbr "<< catCodes << " has no id with " << codePrefix << "\n";

                //couldn't find it; just get the first one.
        wxStringTokenizer tokenizer2( catCodes, "," );
        if ( tokenizer2.HasMoreTokens( ) )
        {
            valStr = tokenizer2.GetNextToken( );
            valStr = valStr.Trim( );
            valStr = valStr.Trim( false );
            id = valStr;
            return true;
        }
        return false;
    }

    void CSVData::MakeColMap( void )
    {
        for ( int j = 0; j < NbrColNames( )+10; j++ )
        {
            m_csvColMap.push_back( ( Catalog::DataTypes )-1 );
        }
        for ( int j = 0; j < NbrColNames( ); j++ )
        {
            for ( int i = 0; i < Catalog::DT_NbrTypes; i++ )
            {
                if ( !Catalog::DT_DataNames[ i ].Cmp( GetColName( j ) ) )
                {
                    m_csvColMap.at(j)=( ( Catalog::DataTypes )i );
                    break;
                }
            }
        }
    }
    bool CSVData::FixUpLine( wxString& line, int lineNbr )
    {
        int curr = 0;
        int last = line.length( );
        int firstQuote = 0;
        int nextQuote = 0;
        int comma = 0;
        while ( curr < last )
        {
            firstQuote = line.find( "\"", curr );
            if ( firstQuote < 0 )
            {
                return true;
            }
            nextQuote = line.find_first_of( "\"", firstQuote + 1 );
            if ( nextQuote < 0 )
            {
                // unmatched parens
                // this means the csv is messed up
                //std::cout << "Format error in csv file at line number " << lineNbr << ".\n";
                wxString caption = "CSV Format Error";
                wxString message;
                message = message.Format( "Format error in csv file %s at line number %d. \n\n%s", m_filename, lineNbr, line );
                wxMessageDialog* msg = new wxMessageDialog( wxGetApp( ).GetFrame( ),
                    message, caption, wxOK | wxCENTRE | wxICON_ERROR );
                msg->ShowModal( );
                msg->~wxMessageDialog( );
                return false;
            }
            comma = line.find_first_of( ",", firstQuote );
            bool check_again = true;
            while ( check_again )
            {
                if ( ( comma > firstQuote ) && ( comma < nextQuote ) )
                {
                    line = line.replace( comma, 1, "{" );
                    comma = line.find_first_of( ",", firstQuote );
                }
                else
                {
                    check_again = false;
                }
            }
            curr = nextQuote + 1;
        }
        return true;
    };

    bool CSVData::ReadTextInStream( wxFileInputStream& file,
        wxTextInputStream& text )
    {
        bool status = false;
        bool valFound = false;
        int csvCol;
        bool endOfData = false;
        wxXmlNode* docRoot = m_nodeData;

        if ( file.IsOk( ) )
        {
            while ( !file.Eof( ) && !endOfData )
            {
                // read a line and parse it
                //	wxString inLine = text.ReadLine ( );
                if ( !file.Eof( ) )
                {
                    status = true;
                    // read a line and parse it
                    wxString line = text.ReadLine( );
                    if ( line.length( ) > 0 )
                    {
                        m_lineCnt++;
                        if ( !file.Eof( ) && FixUpLine( line, m_lineCnt ) )
                        {
                            // comma separated Variables on line; i, e, .csv file
                            wxStringTokenizer tokenizer( line, "," );

                            wxXmlNode* stampElement = NewNode( docRoot, Catalog::CatalogBaseNames[ Catalog::NT_Stamp ] );

                            Catalog::Stamp* stampNode = new Catalog::Stamp( stampElement );
                            csvCol = 0;
                            valFound = false;
                            wxString valStr;
                            wxString rest;
                            while ( tokenizer.HasMoreTokens( ) )
                            {
                                // watch out for commas within quotes
                                valStr = tokenizer.GetNextToken( );
                                if ( valStr.StartsWith( wxT( "\"" ), &rest ) )
                                    valStr = rest;
                                if ( valStr.EndsWith( wxT( "\"" ), &rest ) )
                                    valStr = rest;
                                valStr.Replace( "{", ",", true );

                                //std::cout <<  "valStr:>"<< valStr<<"<; \n"   ;                                   

                                Catalog::DataTypes stampType = m_csvColMap.at( csvCol );
                                if ( stampType > 0 )
                                {
                                    Utils::SetAttrStr( stampElement, Catalog::DT_XMLDataNames[ stampType ], valStr );
                                    //                           Catalog::Stamp* stamp = new Catalog::Stamp();
                                    wxString id = "";
                                    if ( stampType == Catalog::DT_Catalog_Codes )
                                    {
                                        //std::cout <<  "stampNode->ProcessCatalogCodes( "<< valStr<<" ); \n"   ;                                   
                                        stampNode->ProcessCatalogCodes( valStr );
                                        if ( GetIDNbr( valStr, id ) )
                                        {
                                            wxString codePrefix = GetSettings( )->GetCatCodePrefix( );
                                            int pos = id.Find( "2502" );//               .StartsWith( codePrefix, &rest );
                                            if ( pos != wxNOT_FOUND )
                                            {
                                                //                                                std::cout << "ID_Nbr>"<<valStr<<"<\n";

                                            }

                                            //std::cout <<  "stampNode->SetID( "<< id<<" ); \n"   ; 
                                            stampNode->SetID( id );
                                            //std::cout <<  "stampNode->GetID( ); \n"   ; 
                                            id = stampNode->GetID( );
                                            //std::cout <<  "stampNode->GetID( ); returned >"<< id << "<\n"; 
                                            if ( id.IsEmpty( ) )
                                            {
                                                std::cout << "ID_Nbr>" << valStr << "<\n";
                                                int a = 0;
                                            }
                                        }
                                        else
                                        {
                                            //                                            std::cout << "ID_Nbr>"<<valStr<<"<\n";
                                            stampNode->SetID( valStr );
                                        }
                                    }
                                    valFound = true;



                                }
                                csvCol++;
                            }
                            wxString id = stampNode->GetID( );
                            id = id.Trim( );
                            id = id.Trim( false );
                            if ( id.IsEmpty( ) )
                            {
                                std::cout << "ID_Nbr>" << valStr << "<\n";
                                int a = 0;
                            }
                            if ( valFound )//&& ( stampNode->GetID( ).Length( ) > 0 ) )
                            {
                                // docRoot->AddChild( ( wxXmlNode* )stampElement );
                            }
                            else
                            {
                                // delete stampNode;
                            }
                        }
                    }
                    else
                    {
                        endOfData = true;
                    }
                }
            }

            //            XMLDumpNode( ( wxXmlNode* )docRoot, "" );
        }
        return status;
    };

}