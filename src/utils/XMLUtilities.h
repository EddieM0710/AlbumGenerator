/**
 * @file XMLUtilities.h
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

#ifndef XMLIterator_H
#define XMLIterator_H

#include "wx/xml/xml.h"
#include <vector>

#include "catalog/CatalogDefs.h"
#include "design/DesignDefs.h"

class wxTextOutputStream;


namespace Utils {

    // Class for iterating an XML heirarchy
    class XMLIterator
    {

    public:



        /**
         * XMLIterator - constructor for iterating an XML heirarchy
         *
         * @param   parent : is the xml element whose children will be
         * iterated.
         * @param   decend : false will iterate only the first level
         * childeren. - true ( default ) will iterate  heirarchy
         */
        XMLIterator( wxXmlNode* parent, bool decend = true );
        ~XMLIterator( );

        /**
         * Returns the first child or Null
         * @return { wxXmlNode*}  :
         */
        wxXmlNode* First( );

        /**
         *  Successively returns the next child or Null if finished.
         * @return { wxXmlNode*} :
         */
        wxXmlNode* Next( );



    private:
        wxXmlNode* m_parent;      // pointer to parent of current element
        wxXmlNode* m_currElement; // pointer to the current element
        XMLIterator* m_iterator;   // iterator for children of this element
        bool m_decend;             // bool; true = > iterate children
        bool m_firstDone; // bool; true if First has been called; if not true Next
        // just returns null
    };

    void IDElement( wxXmlNode* ele );

    typedef std::vector<wxXmlNode*> wxXmlNodeArray;

    wxXmlNode* NewNode( wxXmlNode* parent, wxString name );

    wxXmlNode* NewNode( wxXmlDocument* parent, wxString name );

    bool DeleteAttribute( wxXmlNode* node, wxString attrName );

    wxXmlNode* FirstChildElement( wxXmlNode* node, wxString name );
    wxXmlNode* GetNext( wxXmlNode* node, wxString name );

    wxXmlAttribute* GetAttribute( wxXmlNode* node, wxString attrName );

    wxString GetAttrStr( wxXmlNode* node, wxString attrName );
    double GetAttrDbl( wxXmlNode* node, wxString attrName );

    void SetAttrStr( wxXmlNode* node, wxString name, wxString val );
    void SetAttrDbl( wxXmlNode* node, wxString name, double val );
    void XMLDump( wxXmlDocument* doc );
    void XMLDumpNode( wxXmlNode* node, wxString level );
    void CopyNode( wxXmlNode* src, wxXmlNode* dest );

    wxXmlNode* AddNewNode( wxXmlNode* parent, wxXmlNodeType type, const wxString& name );

    wxXmlNode* FindFirstChildWithPropertyofValue( wxXmlNode* element, wxString& property, wxString& value );
    void AddComment( wxXmlNode* node, wxString name, wxString content );

    void Save( wxXmlDocument* doc, wxString filename );
    void SaveChild( wxTextOutputStream* text, wxXmlNode* node, wxString level );
    void SaveAttributes( wxTextOutputStream* text, wxXmlNode* node, wxString level );

    Design::FontUsageType LoadFont( wxXmlNode* fontNode, wxString& nativeString, wxString& color );
    void SaveFont( wxXmlNode* parent, Design::FontUsageType type, wxFont font, wxColour color );

    extern int zIndex;
    extern int frameIndex;
    extern int imageIndex;


    char* GetZIndex( char* str );


    char* GetImageName( char* str );


    char* GetFrameName( char* str );

    wxString GetTextStyleName( wxString& str );

    char* GetDrawName( char* str );


    char* DoubleToMMString( char* str, double nbr );


    char* IntToInchString( char* str, int nbr );

}

#endif