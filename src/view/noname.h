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
#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/slider.h>
#include <wx/button.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class _main_window
///////////////////////////////////////////////////////////////////////////////
class _main_window : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* m_statusBar1;
		wxPanel* options_panel;
		wxStaticText* m_staticText1;
		wxScrolledWindow* texture_selector_scroll;
	
	public:
		
		_main_window( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1007,634 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~_main_window();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _color_texture_picker
///////////////////////////////////////////////////////////////////////////////
class _color_texture_picker : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* texture_name_label;
		wxStaticBitmap* color_preview;
		wxStaticLine* m_staticline1;
		wxSlider* red_slider;
		wxSlider* green_slider;
		wxSlider* blue_slider;
		wxStaticText* red_label;
		wxStaticText* green_label;
		wxStaticText* blue_label;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText6;
		wxStaticText* loaded_texture_label;
		wxButton* select_texture_button;
	
	public:
		
		_color_texture_picker( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,-1 ), long style = wxTAB_TRAVERSAL ); 
		~_color_texture_picker();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _constant_texture_picker
///////////////////////////////////////////////////////////////////////////////
class _constant_texture_picker : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* texture_name_label;
		wxStaticBitmap* color_preview;
		wxStaticLine* m_staticline1;
		wxSlider* red_slider;
		wxStaticText* red_label;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText6;
		wxStaticText* loaded_texture_label;
		wxButton* select_texture_button;
	
	public:
		
		_constant_texture_picker( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,-1 ), long style = wxTAB_TRAVERSAL ); 
		~_constant_texture_picker();
	
};

#endif //__NONAME_H__
