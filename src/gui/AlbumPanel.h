/////////////////////////////////////////////////////////////////////////////
// Name:        manageaecmddata.h
// Purpose:     
// Author:      Eddie Monroe
// Modified by: 
// Created:     Sat 22 Jan 2022 13:28:32 CST
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), Sat 22 Jan 2022 13:28:32 CST

#ifndef _MANAGEAECMDDATA_H_
#define _MANAGEAECMDDATA_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/treectrl.h"
////@end includes
#include "Defs.h"
#include <vector>
/*!
 * Forward declarations
 */

////@begin forward declarations
class AlbumTreeCtrl;
class StaticItem;
////@end forward declarations
class ReadAlbumEasyFile;
/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_MANAGEAECMDDATA 10000
#define ID_AECMDTREECTRL 10001
#define ID_SCROLLEDWINDOW 10003
#define ID_CMDDATATEXTCTRL 10005
#define SYMBOL_MANAGEAECMDDATA_STYLE wxTAB_TRAVERSAL
#define SYMBOL_MANAGEAECMDDATA_TITLE _("AlbumPanel")
#define SYMBOL_MANAGEAECMDDATA_IDNAME ID_MANAGEAECMDDATA
#define SYMBOL_MANAGEAECMDDATA_SIZE wxSize(400, 300)
#define SYMBOL_MANAGEAECMDDATA_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * AlbumPanel class declaration
 */

class AlbumPanel: public wxPanel
{    
    DECLARE_DYNAMIC_CLASS( AlbumPanel )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    AlbumPanel();
    AlbumPanel( wxWindow* parent, wxWindowID id = SYMBOL_MANAGEAECMDDATA_IDNAME, const wxPoint& pos = SYMBOL_MANAGEAECMDDATA_POSITION, const wxSize& size = SYMBOL_MANAGEAECMDDATA_SIZE, long style = SYMBOL_MANAGEAECMDDATA_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_MANAGEAECMDDATA_IDNAME, const wxPoint& pos = SYMBOL_MANAGEAECMDDATA_POSITION, const wxSize& size = SYMBOL_MANAGEAECMDDATA_SIZE, long style = SYMBOL_MANAGEAECMDDATA_STYLE );

    /// Destructor
    ~AlbumPanel();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin AlbumPanel event handler declarations

////@end AlbumPanel event handler declarations

////@begin AlbumPanel member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end AlbumPanel member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

    void LoadAlbumLayout( );

    void LoadAEData( wxString filename );

    AlbumTreeCtrl* GetAlbumTreeCtrl(){ return m_albumTreeCtrl; };

////@begin AlbumPanel member variables
    AlbumTreeCtrl* m_albumTreeCtrl;
    StaticItem* m_CmdDataTextCtrl;
////@end AlbumPanel member variables
 //ArrayWrapper* m_AEItemArray;
};

#endif
    // _MANAGEAECMDDATA_H_
