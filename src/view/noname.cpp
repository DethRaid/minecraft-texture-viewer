///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 29 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

_main_window::_main_window( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	opengl_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* opengl_panel_sizer;
	opengl_panel_sizer = new wxBoxSizer( wxVERTICAL );
	
	
	opengl_panel->SetSizer( opengl_panel_sizer );
	opengl_panel->Layout();
	opengl_panel_sizer->Fit( opengl_panel );
	bSizer15->Add( opengl_panel, 1, wxEXPAND | wxALL, 5 );
	
	options_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), wxTAB_TRAVERSAL );
	options_panel->SetMinSize( wxSize( 250,-1 ) );
	options_panel->SetMaxSize( wxSize( 250,-1 ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( options_panel, wxID_ANY, wxT("Rendering Data Options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	texture_selector_scroll = new wxScrolledWindow( options_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	texture_selector_scroll->SetScrollRate( 5, 5 );
	bSizer2->Add( texture_selector_scroll, 1, wxEXPAND | wxALL, 5 );
	
	
	options_panel->SetSizer( bSizer2 );
	options_panel->Layout();
	bSizer15->Add( options_panel, 1, wxALL, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

_main_window::~_main_window()
{
}

_color_texture_picker::_color_texture_picker( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	texture_name_label = new wxStaticText( this, wxID_ANY, wxT("Albedo"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label->Wrap( -1 );
	bSizer4->Add( texture_name_label, 0, wxALIGN_CENTER|wxALL, 5 );
	
	color_preview = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( color_preview, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	red_slider = new wxSlider( this, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 150,20 ), wxSL_HORIZONTAL );
	bSizer7->Add( red_slider, 0, wxALL, 5 );
	
	green_slider = new wxSlider( this, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 150,20 ), wxSL_HORIZONTAL );
	bSizer7->Add( green_slider, 0, wxALL, 5 );
	
	blue_slider = new wxSlider( this, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 150,20 ), wxSL_HORIZONTAL );
	bSizer7->Add( blue_slider, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	red_label = new wxStaticText( this, wxID_ANY, wxT("red (128)"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label->Wrap( -1 );
	bSizer9->Add( red_label, 0, wxALL, 5 );
	
	green_label = new wxStaticText( this, wxID_ANY, wxT("green (128)"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	green_label->Wrap( -1 );
	bSizer9->Add( green_label, 0, wxALL, 5 );
	
	blue_label = new wxStaticText( this, wxID_ANY, wxT("blue (128)"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	blue_label->Wrap( -1 );
	bSizer9->Add( blue_label, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer9, 1, wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer10->Add( m_staticText6, 0, wxALL, 5 );
	
	loaded_texture_label = new wxStaticText( this, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	loaded_texture_label->Wrap( -1 );
	bSizer10->Add( loaded_texture_label, 0, wxALL, 5 );
	
	
	bSizer12->Add( bSizer10, 1, wxEXPAND|wxLEFT|wxRIGHT|wxSHAPED, 5 );
	
	select_texture_button = new wxButton( this, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer4->Add( bSizer12, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
}

_color_texture_picker::~_color_texture_picker()
{
}

_constant_texture_picker::_constant_texture_picker( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	texture_name_label = new wxStaticText( this, wxID_ANY, wxT("Albedo"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label->Wrap( -1 );
	bSizer4->Add( texture_name_label, 0, wxALIGN_CENTER|wxALL, 5 );
	
	color_preview = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( color_preview, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	red_slider = new wxSlider( this, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 150,20 ), wxSL_HORIZONTAL );
	bSizer7->Add( red_slider, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	red_label = new wxStaticText( this, wxID_ANY, wxT("value (128)"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label->Wrap( -1 );
	bSizer9->Add( red_label, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer9, 1, wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer10->Add( m_staticText6, 0, wxALL, 5 );
	
	loaded_texture_label = new wxStaticText( this, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	loaded_texture_label->Wrap( -1 );
	bSizer10->Add( loaded_texture_label, 0, wxALL, 5 );
	
	
	bSizer12->Add( bSizer10, 1, 0, 5 );
	
	select_texture_button = new wxButton( this, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer4->Add( bSizer12, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
}

_constant_texture_picker::~_constant_texture_picker()
{
}
