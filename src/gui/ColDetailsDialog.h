/*
 * @file src/gui/ColDetailsDialog.h
 * @author Eddie Monroe
 * @brief
 * @version 0.1
 * @date 2022-03-29
 *
 * @copyright Copyright ( c ) 2022
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
 */

#ifndef _COLDETAILSDIALOG_H_
#define _COLDETAILSDIALOG_H_


 /*
 * Includes
 */

#include "wx/listctrl.h"
#include <wx/fontpicker.h>
#include <wx/clrpicker.h>

#include "gui/DesignTreeCtrl.h"
#include "gui/GuiDefs.h"

 /*
 * Forward declarations
 */
class LabeledTextBox;
class wxListCtrl;
namespace Design { class Column; };


#define SYMBOL_COLDETAILSDIALOG_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCLOSE_BOX | wxTAB_TRAVERSAL
#define SYMBOL_COLDETAILSDIALOG_TITLE _( "Col Details Dialog" )
#define SYMBOL_COLDETAILSDIALOG_IDNAME ID_COLDETAILSDIALOG
#define SYMBOL_COLDETAILSDIALOG_SIZE wxSize( 400, 300 )
#define SYMBOL_COLDETAILSDIALOG_POSITION wxDefaultPosition



/*
 * ColDetailsDialog class declaration
 */

class ColDetailsDialog: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( ColDetailsDialog )
        DECLARE_EVENT_TABLE( )

public:

    enum ColDetailsDialogGuiDefs {
        ID_NAMELABELEDTEXTBOX = ID_COLDETAILSDIALOG + 1,
        ID_COLTITLECHECKBOX,
        ID_FRAMECHECKBOX,
        ID_LISTCTRL,
        ID_COLNOTEBOOK,
        ID_COLNAMEPANEL,
        ID_COLDEFAULTFONTBUTTON,
        ID_COLLAYOUTPANEL,
        ID_COLLAYOUTTEXTCTRL,
        ID_NOTEBOOKPOSITIONPANEL,
        ID_POSITIONTEXTCTRL,
        ID_NOTEBOOK,
        ID_NOTEBOOKDETAILSPANEL,
        ID_DEFAULTFONTBUTTON,
        ID_DEFAULTRADIOBUTTON,
        ID_TOPRADIOBUTTON,
        ID_BOTTOMRADIOBUTTON,
        ID_LEFTRADIOBUTTON,
        ID_RIGHTRADIOBUTTON,
        ID_CALCULATEDRADIOBUTTON,
        ID_FIXEDRADIOBUTTON,
        ID_FIXEDSIZETEXTCTRL
    };


    ColDetailsDialog( );
    ColDetailsDialog( wxWindow* parent, wxWindowID id = SYMBOL_COLDETAILSDIALOG_IDNAME, const wxString& caption = SYMBOL_COLDETAILSDIALOG_TITLE, const wxPoint& pos = SYMBOL_COLDETAILSDIALOG_POSITION, const wxSize& size = SYMBOL_COLDETAILSDIALOG_SIZE, long style = SYMBOL_COLDETAILSDIALOG_STYLE );


    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_COLDETAILSDIALOG_IDNAME, const wxString& caption = SYMBOL_COLDETAILSDIALOG_TITLE, const wxPoint& pos = SYMBOL_COLDETAILSDIALOG_POSITION, const wxSize& size = SYMBOL_COLDETAILSDIALOG_SIZE, long style = SYMBOL_COLDETAILSDIALOG_STYLE );


    ~ColDetailsDialog( );


    void Init( );


    void CreateControls( );

    void UpdateControls( );

    void SetupDialog( wxTreeItemId treeID );

    //   wxID_OK
    void OnOkClick( wxCommandEvent& event );
    void OnDefaultRadioButtonSelected( wxCommandEvent& event );
    void OnTopRadioButtonSelected( wxCommandEvent& event );
    void OnBottomRadioButtonSelected( wxCommandEvent& event );
    void OnLeftRadioButtonSelected( wxCommandEvent& event );
    void OnRightRadioButtonSelected( wxCommandEvent& event );
    void OnTitleDefaultClick( wxCommandEvent& event );

    void OnFixedClick( wxCommandEvent& event );
    void OnCalculatedClick( wxCommandEvent& event );

    static bool ShowToolTips( );
    void SetNameModified( bool state );
    bool IsNameModified( );

    void SetShowTitle( bool state = false );
    void SetShowFrame( bool state = false );
    bool GetShowTitle( );
    bool GetShowFrame( );
    void SetTitleFont( wxFont font );
    void SetTitleColor( wxColour color );
    wxFont GetTitleFont( );
    wxColour GetTitleColor( );
    void SetTitleLayoutLocation( );

    void SetCalculateSpacing( bool val );
    void SetFixedSpacingSize( wxString str ) { m_positionFixedSize->SetValue( str ); };
    wxString GetFixedSpacing( ) { return m_positionFixedSize->GetValue( ); };
    bool CalculateSpacing( ) { return m_positionCalculated->GetValue( ); };


private:

    LabeledTextBox* m_name;
    wxCheckBox* m_titleCheckbox;
    wxCheckBox* m_frameCheckbox;
    wxListBox* m_statusList;
    wxFontPickerCtrl* m_titleFontPicker;
    wxColourPickerCtrl* m_titleColorPicker;
    wxTextCtrl* positionTextCtrl;
    Design::Column* m_col;
    wxTreeItemId m_designTreeID;
    wxStaticBox* m_TitleLocationBox;
    wxStaticBoxSizer* m_titleLocationVSizer;
    wxBoxSizer* m_titleLocationHSizer;
    Design::TitleLocation m_titleLocation;
    wxRadioButton* m_topButton;
    wxRadioButton* m_bottomButton;
    wxRadioButton* m_leftButton;
    wxRadioButton* m_rightButton;
    wxRadioButton* m_defaultButton;
    wxRadioButton* m_positionCalculated;
    wxRadioButton* m_positionFixed;
    wxTextCtrl* m_positionFixedSize;
};

#endif
// _COLDETAILSDIALOG_H_
