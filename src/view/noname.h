///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 29 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/filepicker.h>
#include <wx/gbsizer.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_EXPORT_PBR 1000
#define ID_REFRESH_SHADERS 1001
#define ID_BLUE_HOUR_AT_PIER_BACKGROUND 1002
#define ID_GOLDEN_AUTUMN_ROAD_BACKGROUND 1003
#define ID_ROAD_IN_VALLEY_BACKGROUND 1004
#define specular_slider 1005

///////////////////////////////////////////////////////////////////////////////
/// Class _main_window
///////////////////////////////////////////////////////////////////////////////
class _main_window : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* export_menu;
		wxMenu* m_menu2;
		wxMenu* background_change_menu;
		wxPanel* options_panel;
		wxStaticText* m_staticText1;
		wxScrolledWindow* texture_selector_scroll;
		wxStaticLine* m_staticline33;
		wxPanel* albedo_panel;
		wxStaticText* texture_name_label1;
		wxButton* albedo_collapse_button;
		wxStaticBitmap* albedo_preview;
		wxStaticLine* m_staticline11;
		wxFilePickerCtrl* albedo_file_picker;
		wxStaticLine* m_staticline331;
		wxPanel* opacity_panel;
		wxStaticText* roughness_texture_name_labell1;
		wxStaticBitmap* opacity_color_preview;
		wxStaticLine* m_staticline1131;
		wxSlider* opacity_slider;
		wxTextCtrl* opacity_input;
		wxStaticText* red_label121;
		wxStaticLine* m_staticline2121;
		wxFilePickerCtrl* opacity_file_picker;
		wxButton* opacity_collapse_button;
		wxStaticLine* m_staticline3312;
		wxPanel* normal_panel;
		wxStaticText* texture_name_label11;
		wxButton* normal_collapse_button;
		wxStaticBitmap* normal_preview;
		wxStaticLine* m_staticline111;
		wxFilePickerCtrl* normal_file_picker;
		wxStaticLine* m_staticline3311;
		wxPanel* specular_color_panel;
		wxStaticText* texture_name_label12;
		wxButton* f0_collapse_button;
		wxStaticBitmap* specualr_color_preview;
		wxStaticLine* m_staticline112;
		wxSlider* specular_red_slider;
		wxTextCtrl* specular_red_input;
		wxStaticText* red_label11;
		wxStaticLine* m_staticline211;
		wxFilePickerCtrl* specular_file_picker;
		wxStaticLine* m_staticline33111;
		wxPanel* smoothness_panel;
		wxStaticText* roughness_texture_name_labell;
		wxButton* smoothness_collapse_button;
		wxStaticBitmap* roughness_color_preview;
		wxStaticLine* m_staticline113;
		wxSlider* smoothness_slider;
		wxTextCtrl* smoothness_input;
		wxStaticText* red_label12;
		wxStaticLine* m_staticline212;
		wxFilePickerCtrl* smoothness_file_picker;
		wxStaticLine* ao_;
		wxPanel* emission_panel;
		wxStaticText* texture_name_label13;
		wxStaticBitmap* emission_preview;
		wxStaticLine* m_staticline114;
		wxSlider* emission_slider;
		wxTextCtrl* emission_input;
		wxStaticText* red_label13;
		wxStaticLine* m_staticline213;
		wxFilePickerCtrl* emission_file_picker;
		wxStaticLine* m_staticline332;
		wxPanel* height_panel;
		wxStaticText* texture_name_label14;
		wxStaticBitmap* height_color_preview;
		wxStaticLine* m_staticline115;
		wxSlider* height_slider;
		wxTextCtrl* height_input;
		wxStaticText* red_label14;
		wxStaticLine* m_staticline214;
		wxFilePickerCtrl* height_file_picker;
		wxStaticLine* m_staticline333;
		wxPanel* porosity_panel;
		wxStaticText* texture_name_label15;
		wxStaticBitmap* porosity_color_preview;
		wxStaticLine* m_staticline116;
		wxSlider* porosity_slider;
		wxTextCtrl* porosity_input;
		wxStaticText* red_label15;
		wxStaticLine* m_staticline215;
		wxFilePickerCtrl* porosity_file_picker;
		wxStaticLine* m_staticline334;
		wxPanel* translucense_panel;
		wxStaticText* texture_name_label17;
		wxStaticBitmap* translucence_color_preview;
		wxStaticLine* m_staticline118;
		wxSlider* translucence_slider;
		wxTextCtrl* translucence_input;
		wxStaticText* red_label17;
		wxStaticLine* m_staticline217;
		wxFilePickerCtrl* translucence_file_picker;
		wxStaticLine* m_staticline3341;
		wxPanel* ao_panel;
		wxStaticText* texture_name_label16;
		wxStaticBitmap* ao_color_preview;
		wxStaticLine* m_staticline117;
		wxSlider* ao_slider;
		wxTextCtrl* ao_input;
		wxStaticText* red_label16;
		wxStaticLine* m_staticline216;
		wxFilePickerCtrl* ao_file_picker;
		wxStatusBar* m_statusBar1;
	
	public:
		
		_main_window( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1268,1196 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~_main_window();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _export_options_dialogue
///////////////////////////////////////////////////////////////////////////////
class _export_options_dialogue : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText26;
		wxDirPickerCtrl* export_folder_picker;
		wxStaticText* m_staticText27;
		wxTextCtrl* export_filename_input;
		wxStaticText* m_staticText28;
		wxStaticText* color_tex_name_output;
		wxStaticText* m_staticText32;
		wxStaticText* normal_tex_name_output;
		wxStaticText* m_staticText29;
		wxStaticText* data_tex_name_output;
		wxStaticText* m_staticText34;
		wxComboBox* export_resolution_combobox;
		wxStaticText* m_staticText321;
		wxCheckBox* leaf_checkbox;
		wxButton* export_button;
	
	public:
		
		_export_options_dialogue( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Export Options"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~_export_options_dialogue();
	
};

#endif //__NONAME_H__
