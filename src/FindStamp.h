/**
 * @file FindStamp.h
 * @author Eddie Monroe ()
 * @brief 
 * @version 0.1
 * @date 2021-02-25
 * 
 * @copyright Copyright (c) 2021
 * 
 **************************************************/


#ifndef _FINDSTAMP_H_
#define _FINDSTAMP_H_

/*!
 * Includes
 */

 
 

/*!
 * Forward declarations
 */

 
 

/*!
 * Control identifiers
 */

 
#define ID_TEXTCTRL ID_FINDSTAMP+1
#define ID_IDCHECKBOX ID_FINDSTAMP+2
#define ID_TITLECHECKBOX ID_FINDSTAMP+3
#define ID_SERIESCHECKBOX ID_FINDSTAMP+4
#define ID_CTHEMEHECKBOX ID_FINDSTAMP+5
#define SYMBOL_FINDSTAMP_STYLE                                                 \
    wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxSTAY_ON_TOP | wxCLOSE_BOX  \
        | wxTAB_TRAVERSAL
#define SYMBOL_FINDSTAMP_TITLE _( "Find Stamp" )
#define SYMBOL_FINDSTAMP_IDNAME ID_FINDSTAMP
#define SYMBOL_FINDSTAMP_SIZE wxSize( 400, 300 )
#define SYMBOL_FINDSTAMP_POSITION wxDefaultPosition
 

/*!
 * FindStamp class declaration
 */

class FindStamp : public wxDialog
{
    DECLARE_DYNAMIC_CLASS( FindStamp )
    DECLARE_EVENT_TABLE( )

  public:
    // Constructors
    /**
     * @brief Default Constructor for a new FindStamp object
     * 
     **************************************************/
    FindStamp( );

    /**
     * @brief Construct a new FindStamp object
     * 
     * @param  parent	The parent window.
     * @param  id	An identifier for the panel. wxID_ANY is taken to mean a default.
     * @param  pos	The panel position. The value wxDefaultPosition indicates a default position, chosen by either the windowing system or wxWidgets, depending on platform.
     * @param  size	The panel size. The value wxDefaultSize indicates a default size, chosen by either the windowing system or wxWidgets, depending on platform.
     * @param  style	The window style. 
     * @see wxPanel.
     **************************************************/
    FindStamp( wxWindow *parent, wxWindowID id = SYMBOL_FINDSTAMP_IDNAME,
               const wxString &caption = SYMBOL_FINDSTAMP_TITLE,
               const wxPoint &pos = SYMBOL_FINDSTAMP_POSITION,
               const wxSize &size = SYMBOL_FINDSTAMP_SIZE,
               long style = SYMBOL_FINDSTAMP_STYLE );

    /**
     * @brief  Used for two-step panel construction.
     * Use with default constructor.
     * 
     * @param  parent	The parent window.
     * @param  id	An identifier for the panel. wxID_ANY is taken to mean a default.
     * @param  pos	The panel position. The value wxDefaultPosition indicates a default position, chosen by either the windowing system or wxWidgets, depending on platform.
     * @param  size	The panel size. The value wxDefaultSize indicates a default size, chosen by either the windowing system or wxWidgets, depending on platform.
     * @param  style	The window style. 
     * @return bool 
     * 
     **************************************************/
    bool Create( wxWindow *parent, wxWindowID id = SYMBOL_FINDSTAMP_IDNAME,
                 const wxString &caption = SYMBOL_FINDSTAMP_TITLE,
                 const wxPoint &pos = SYMBOL_FINDSTAMP_POSITION,
                 const wxSize &size = SYMBOL_FINDSTAMP_SIZE,
                 long style = SYMBOL_FINDSTAMP_STYLE );

    // Destructor
    ~FindStamp( );

        /**
     * @brief   Initialises member variables
     * 
     **************************************************/

    /**
     * @brief   Initialises member variables
     * 
     **************************************************/
    void Init( );

    /**
     * @brief Creates the controls and sizers
     * 
     **************************************************/
    void CreateControls( );

     // FindStamp event handler declarations

    // wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_FIND
    void OnFindClick( wxCommandEvent &event );

    // wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent &event );

     // FindStamp event handler declarations

     // FindStamp member function declarations

    /**
     * @brief Retrieves bitmap resources
     * 
     * @param  name (autogenerated. Dummy.)
     * @return wxBitmap null
     **************************************************/
    wxBitmap GetBitmapResource( const wxString &name );

    // Retrieves icon resources
    wxIcon GetIconResource( const wxString &name );
     // FindStamp member function declarations

    // Should we show tooltips?
    static bool ShowToolTips( );

     // FindStamp member variables
    wxTextCtrl *m_searchText;
    wxCheckBox *m_idCheckBox;
    wxCheckBox *m_titleCheckBox;
    wxCheckBox *m_seriesCheckBox;
    wxCheckBox *m_themeCheckBox;
    wxButton *m_cancel;
     // FindStamp member variables
};

#endif
// _FINDSTAMP_H_
