/**
 * @file Layoutlayout/AlbumNode.h
 * @author Eddie Monroe
 * @brief
 * @version 0.1
 * @date 2022-02-04
 *
 * @copyright Copyright (c) 2022
 *
 **************************************************/

#ifndef LayoutNode_h
#define LayoutNode_h

#include <wx/string.h>

#include "Defs.h"
#include "album/AlbumNode.h"
 //#include "album/Attribute.h"
#include "utils/XMLUtilities.h"

#include <wx/xml/xml.h>
 //using namespace tinyxml2;

namespace Layout {


    class Title;

    /**
     * @brief Base class for all layout objects. The layout objects are
     * initialy loaded from the layout XML.
     *
     **************************************************/
    class LayoutNode : public AlbumNode
    {
    public:
        /**
         * @brief Unused; Construct a new Album Layout Object object
         *
         **************************************************/
        LayoutNode( ) : AlbumNode( ) {
            
        };

        /**
         * @brief Construct a new Album Layout Object
         *
         * @param name
         **************************************************/
        LayoutNode( wxXmlNode* node ) : AlbumNode( node ) {
        };


        virtual wxXmlNode* Write( wxXmlNode* parent ) = 0;

        /**
         * @brief Gets the objects x position
         *
         * @return double
         **************************************************/
        double GetXPos( );

        /**
         * @brief Sets the objects x position
         *
         * @param val
         **************************************************/
        void SetXPos( double val );

        /**
         * @brief Gets the objects y position
         *
         * @return double
         **************************************************/
        double GetYPos( ) ;

        /**
         * @brief  Sets the objects y position
         *
         * @param val
         **************************************************/
        void SetYPos( double val );

        /**
         * @brief Gets the objects  width
         *
         * @return double
         **************************************************/
        double GetWidth( );

        /**
         * @brief  Sets the objects width
         *
         * @param val
         **************************************************/
        void SetWidth( double val );

        /**
         * @brief Gets the objects height
         *
         * @return double
         **************************************************/
        double GetHeight( );

        /**
         * @brief  Sets the objects height
         *
         * @param val
         **************************************************/
        void SetHeight( double val );


        /**
         * @brief Gets the objects minimum width
         *
         * @return double
         **************************************************/
        double GetMinWidth( );

        /**
         * @brief  Sets the objects minimum width
         *
         * @param val
         **************************************************/
        void SetMinWidth( double val );

        /**
         * @brief Gets the objects minimum height
         *
         * @return double
         **************************************************/
        double GetMinHeight( );

        /**
         * @brief  Sets the objects minimum height
         *
         * @param val
         **************************************************/
        void SetMinHeight( double val );

        void ValidateChildType( int& nbrRows, int& nbrCols, int& nbrStamps );
        void ReportLayoutError( wxString funct, wxString err, bool fatal = true );



        /**
         * @brief Calculate the column layout based on child parameters
         *
         * @return true
         * @return false
         **************************************************/
        virtual void UpdatePositions( ) = 0;

        /**
         * @brief UpdateMinimumSize
         * Calculates the minimum Height and width of the object. It drills down to
         * the lowest layout object with an actual size and begins calculating the
         * min size of its parents as it progresses back up the heirarchy.
         * @return true
         * @return false
         **************************************************/
        virtual void UpdateMinimumSize( ) = 0;

        virtual void UpdateSizes( ) = 0;

        Title* GetTitle( );
        double GetTitleHeight( );


    protected:

        /**
         * @brief position relative to parent container
         *
         **************************************************/
        double m_xPos;

        /**
         * @brief  position relative to parent container
         *
         **************************************************/
        double m_yPos;

        /**
         * @brief object width
         *
         **************************************************/
        double m_width;

        /**
         * @brief object height
         *
         **************************************************/
        double m_height;


        // max width of child items; min width for this column
        double m_minWidth;

        /**
         * @brief sum of the height of child items; min height for this row
         *
         **************************************************/
        double m_minHeight;


    };
}
#endif
