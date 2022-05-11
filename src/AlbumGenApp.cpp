/**
 * @file AlbumGenApp.cpp
 * @author Eddie Monroe ()
 * @brief This is the main instantiation class for the application
 * @version 0.1
 * @date 2021-02-25
 *
 * @copyright Copyright (c) 2021
 *
 **************************************************/

/**
 * 
 * @todo Complete Documentation
 * 
 * @todo integrate GIT
 * 
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

#include "Defs.h"
#include "utils/Project.h"
#include "AlbumGenApp.h"

/*
 * Application instance implementation
 */

 // implement app
IMPLEMENT_APP( AlbumGenApp )
// implement app

/*
 * AlbumGenApp type definition
 */
    IMPLEMENT_CLASS( AlbumGenApp, wxApp )
    ;
/*
 * AlbumGenApp event table definition
 */

BEGIN_EVENT_TABLE( AlbumGenApp, wxApp )

// AlbumGenApp event table entries
// AlbumGenApp event table entries

END_EVENT_TABLE( )
;  // silly business; The above macro screws up the formatter
;

/*
 * Constructor for AlbumGenApp
 */

AlbumGenApp::AlbumGenApp( )
{
    Init( );
}

/*
 * Member initialisation
 */

void AlbumGenApp::Init( )
{
    // AlbumGenApp member initialisation
    // AlbumGenApp member initialisation
}

/*
 * Initialisation for AlbumGenApp
 */

bool AlbumGenApp::OnInit( )
{
    // AlbumGenApp initialisation
   // Remove the comment markers above and below this block
   // to make permanent changes to the code.

#if wxUSE_XPM
    wxImage::AddHandler( new wxXPMHandler );
#endif
#if wxUSE_LIBPNG
    wxImage::AddHandler( new wxPNGHandler );
#endif
#if wxUSE_LIBJPEG
    wxImage::AddHandler( new wxJPEGHandler );
#endif
#if wxUSE_GIF
    wxImage::AddHandler( new wxGIFHandler );
#endif

    m_project = new Utils::Project();

    m_frame = new AlbumGenFrame( NULL );
    m_frame->SetupRecentMenu( );    
    m_frame->InitLoad( );

    m_frame->Show( true );
    // AlbumGenApp initialisation

    return true;
}

/*
 * Cleanup for AlbumGenApp
 */

int AlbumGenApp::OnExit( )
{
    // AlbumGenApp cleanup
    return wxApp::OnExit( );
    // AlbumGenApp cleanup
}
