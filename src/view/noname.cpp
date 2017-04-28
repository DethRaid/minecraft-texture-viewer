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
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	options_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 350,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( options_panel, wxID_ANY, wxT("Rendering Data Options"), wxDefaultPosition, wxSize( 291,-1 ), wxALIGN_CENTRE );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	texture_selector_scroll = new wxScrolledWindow( options_panel, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxVSCROLL );
	texture_selector_scroll->SetScrollRate( 5, 5 );
	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->SetFlexibleDirection( wxVERTICAL );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticline33 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline33, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	albedo_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer3;
	gbSizer3 = new wxGridBagSizer( 0, 0 );
	gbSizer3->SetFlexibleDirection( wxVERTICAL );
	gbSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label1 = new wxStaticText( albedo_panel, wxID_ANY, wxT("Albedo"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label1->Wrap( -1 );
	gbSizer3->Add( texture_name_label1, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	albedo_preview = new wxStaticBitmap( albedo_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer3->Add( albedo_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline11 = new wxStaticLine( albedo_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer3->Add( m_staticline11, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	albedo_red_slider = new wxSlider( albedo_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer2->Add( albedo_red_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_red_input = new wxTextCtrl( albedo_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer2->Add( albedo_red_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label1 = new wxStaticText( albedo_panel, wxID_ANY, wxT("red"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label1->Wrap( -1 );
	gbSizer2->Add( red_label1, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_green_slider = new wxSlider( albedo_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer2->Add( albedo_green_slider, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_green_input = new wxTextCtrl( albedo_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer2->Add( albedo_green_input, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	green_label = new wxStaticText( albedo_panel, wxID_ANY, wxT("green"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	green_label->Wrap( -1 );
	gbSizer2->Add( green_label, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_blue_slider = new wxSlider( albedo_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer2->Add( albedo_blue_slider, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_blue_input = new wxTextCtrl( albedo_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer2->Add( albedo_blue_input, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	blue_label = new wxStaticText( albedo_panel, wxID_ANY, wxT("blue"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	blue_label->Wrap( -1 );
	gbSizer2->Add( blue_label, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer3->Add( gbSizer2, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline21 = new wxStaticLine( albedo_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer3->Add( m_staticline21, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText61 = new wxStaticText( albedo_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	bSizer101->Add( m_staticText61, 0, wxALL, 5 );
	
	albedo_loaded_label = new wxStaticText( albedo_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	albedo_loaded_label->Wrap( -1 );
	bSizer101->Add( albedo_loaded_label, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer121->Add( bSizer101, 1, wxEXPAND, 5 );
	
	albedo_select_texture_button = new wxButton( albedo_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer121->Add( albedo_select_texture_button, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	gbSizer3->Add( bSizer121, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	albedo_panel->SetSizer( gbSizer3 );
	albedo_panel->Layout();
	gbSizer3->Fit( albedo_panel );
	gbSizer1->Add( albedo_panel, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline331 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline331, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	normal_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer31;
	gbSizer31 = new wxGridBagSizer( 0, 0 );
	gbSizer31->SetFlexibleDirection( wxVERTICAL );
	gbSizer31->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label11 = new wxStaticText( normal_panel, wxID_ANY, wxT("Normal"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label11->Wrap( -1 );
	gbSizer31->Add( texture_name_label11, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	normal_preview = new wxStaticBitmap( normal_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer31->Add( normal_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline111 = new wxStaticLine( normal_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer31->Add( m_staticline111, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer23;
	gbSizer23 = new wxGridBagSizer( 0, 0 );
	gbSizer23->SetFlexibleDirection( wxBOTH );
	gbSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText611 = new wxStaticText( normal_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText611->Wrap( -1 );
	gbSizer23->Add( m_staticText611, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	normal_loaded_label = new wxStaticText( normal_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	normal_loaded_label->Wrap( -1 );
	gbSizer23->Add( normal_loaded_label, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	normal_select_texture_button = new wxButton( normal_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxSize( 230,-1 ), 0 );
	gbSizer23->Add( normal_select_texture_button, wxGBPosition( 1, 0 ), wxGBSpan( 1, 2 ), wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	gbSizer31->Add( gbSizer23, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	normal_panel->SetSizer( gbSizer31 );
	normal_panel->Layout();
	gbSizer31->Fit( normal_panel );
	gbSizer1->Add( normal_panel, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline3311 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline3311, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	specular_color_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer32;
	gbSizer32 = new wxGridBagSizer( 0, 0 );
	gbSizer32->SetFlexibleDirection( wxVERTICAL );
	gbSizer32->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label12 = new wxStaticText( specular_color_panel, wxID_ANY, wxT("Specular"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label12->Wrap( -1 );
	gbSizer32->Add( texture_name_label12, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	specualr_color_preview = new wxStaticBitmap( specular_color_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer32->Add( specualr_color_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline112 = new wxStaticLine( specular_color_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer32->Add( m_staticline112, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer21;
	gbSizer21 = new wxGridBagSizer( 0, 0 );
	gbSizer21->SetFlexibleDirection( wxBOTH );
	gbSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	specular_red_slider = new wxSlider( specular_color_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer21->Add( specular_red_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	specular_red_input = new wxTextCtrl( specular_color_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer21->Add( specular_red_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label11 = new wxStaticText( specular_color_panel, wxID_ANY, wxT("red"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label11->Wrap( -1 );
	gbSizer21->Add( red_label11, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	specualr_green_slider = new wxSlider( specular_color_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer21->Add( specualr_green_slider, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	specular_green_input = new wxTextCtrl( specular_color_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer21->Add( specular_green_input, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	green_label1 = new wxStaticText( specular_color_panel, wxID_ANY, wxT("green"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	green_label1->Wrap( -1 );
	gbSizer21->Add( green_label1, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	specular_blue_slider = new wxSlider( specular_color_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer21->Add( specular_blue_slider, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	specular_blue_input = new wxTextCtrl( specular_color_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer21->Add( specular_blue_input, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	blue_label1 = new wxStaticText( specular_color_panel, wxID_ANY, wxT("blue"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	blue_label1->Wrap( -1 );
	gbSizer21->Add( blue_label1, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer32->Add( gbSizer21, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline211 = new wxStaticLine( specular_color_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer32->Add( m_staticline211, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer1211;
	bSizer1211 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1011;
	bSizer1011 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText612 = new wxStaticText( specular_color_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText612->Wrap( -1 );
	bSizer1011->Add( m_staticText612, 0, wxALL, 5 );
	
	specular_loaded_texture_label = new wxStaticText( specular_color_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	specular_loaded_texture_label->Wrap( -1 );
	bSizer1011->Add( specular_loaded_texture_label, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer1211->Add( bSizer1011, 1, wxEXPAND, 5 );
	
	specular_select_texture_button = new wxButton( specular_color_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1211->Add( specular_select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	gbSizer32->Add( bSizer1211, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	specular_color_panel->SetSizer( gbSizer32 );
	specular_color_panel->Layout();
	gbSizer32->Fit( specular_color_panel );
	gbSizer1->Add( specular_color_panel, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline33111 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline33111, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	roughness_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer33;
	gbSizer33 = new wxGridBagSizer( 0, 0 );
	gbSizer33->SetFlexibleDirection( wxVERTICAL );
	gbSizer33->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	roughness_texture_name_labell = new wxStaticText( roughness_panel, wxID_ANY, wxT("Smoothness"), wxDefaultPosition, wxDefaultSize, 0 );
	roughness_texture_name_labell->Wrap( -1 );
	gbSizer33->Add( roughness_texture_name_labell, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	roughness_color_preview = new wxStaticBitmap( roughness_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer33->Add( roughness_color_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline113 = new wxStaticLine( roughness_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer33->Add( m_staticline113, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer22;
	gbSizer22 = new wxGridBagSizer( 0, 0 );
	gbSizer22->SetFlexibleDirection( wxBOTH );
	gbSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	rougness_slider = new wxSlider( roughness_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer22->Add( rougness_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	roughness_input = new wxTextCtrl( roughness_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer22->Add( roughness_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label12 = new wxStaticText( roughness_panel, wxID_ANY, wxT("smoothness"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label12->Wrap( -1 );
	gbSizer22->Add( red_label12, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer33->Add( gbSizer22, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline212 = new wxStaticLine( roughness_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer33->Add( m_staticline212, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer1212;
	bSizer1212 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1012;
	bSizer1012 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText613 = new wxStaticText( roughness_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText613->Wrap( -1 );
	bSizer1012->Add( m_staticText613, 0, wxALL, 5 );
	
	roughness_loaded_texture_label = new wxStaticText( roughness_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	roughness_loaded_texture_label->Wrap( -1 );
	bSizer1012->Add( roughness_loaded_texture_label, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer1212->Add( bSizer1012, 1, wxEXPAND, 5 );
	
	roughness_select_texture_button = new wxButton( roughness_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1212->Add( roughness_select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	gbSizer33->Add( bSizer1212, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	roughness_panel->SetSizer( gbSizer33 );
	roughness_panel->Layout();
	gbSizer33->Fit( roughness_panel );
	gbSizer1->Add( roughness_panel, wxGBPosition( 7, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	ao_ = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( ao_, wxGBPosition( 8, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	emission_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer34;
	gbSizer34 = new wxGridBagSizer( 0, 0 );
	gbSizer34->SetFlexibleDirection( wxVERTICAL );
	gbSizer34->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label13 = new wxStaticText( emission_panel, wxID_ANY, wxT("Emission"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label13->Wrap( -1 );
	gbSizer34->Add( texture_name_label13, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	emission_preview = new wxStaticBitmap( emission_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer34->Add( emission_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline114 = new wxStaticLine( emission_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer34->Add( m_staticline114, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer24;
	gbSizer24 = new wxGridBagSizer( 0, 0 );
	gbSizer24->SetFlexibleDirection( wxBOTH );
	gbSizer24->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	emission_slider = new wxSlider( emission_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer24->Add( emission_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	emission_input = new wxTextCtrl( emission_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer24->Add( emission_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label13 = new wxStaticText( emission_panel, wxID_ANY, wxT("emission"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label13->Wrap( -1 );
	gbSizer24->Add( red_label13, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer34->Add( gbSizer24, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline213 = new wxStaticLine( emission_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer34->Add( m_staticline213, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer1213;
	bSizer1213 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1013;
	bSizer1013 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText614 = new wxStaticText( emission_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText614->Wrap( -1 );
	bSizer1013->Add( m_staticText614, 0, wxALL, 5 );
	
	emission_loaded_texture_label = new wxStaticText( emission_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	emission_loaded_texture_label->Wrap( -1 );
	bSizer1013->Add( emission_loaded_texture_label, 0, wxALL, 5 );
	
	
	bSizer1213->Add( bSizer1013, 1, wxEXPAND, 5 );
	
	emission_select_texture_button = new wxButton( emission_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1213->Add( emission_select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	gbSizer34->Add( bSizer1213, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	emission_panel->SetSizer( gbSizer34 );
	emission_panel->Layout();
	gbSizer34->Fit( emission_panel );
	gbSizer1->Add( emission_panel, wxGBPosition( 9, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline332 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline332, wxGBPosition( 10, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	height_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer35;
	gbSizer35 = new wxGridBagSizer( 0, 0 );
	gbSizer35->SetFlexibleDirection( wxVERTICAL );
	gbSizer35->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label14 = new wxStaticText( height_panel, wxID_ANY, wxT("Heightmap"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label14->Wrap( -1 );
	gbSizer35->Add( texture_name_label14, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	height_color_preview = new wxStaticBitmap( height_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer35->Add( height_color_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline115 = new wxStaticLine( height_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer35->Add( m_staticline115, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer25;
	gbSizer25 = new wxGridBagSizer( 0, 0 );
	gbSizer25->SetFlexibleDirection( wxBOTH );
	gbSizer25->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	height_slider = new wxSlider( height_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer25->Add( height_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	height_input = new wxTextCtrl( height_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer25->Add( height_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label14 = new wxStaticText( height_panel, wxID_ANY, wxT("height"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label14->Wrap( -1 );
	gbSizer25->Add( red_label14, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer35->Add( gbSizer25, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline214 = new wxStaticLine( height_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer35->Add( m_staticline214, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer1214;
	bSizer1214 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1014;
	bSizer1014 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText615 = new wxStaticText( height_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText615->Wrap( -1 );
	bSizer1014->Add( m_staticText615, 0, wxALL, 5 );
	
	height_loaded_texture_label = new wxStaticText( height_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	height_loaded_texture_label->Wrap( -1 );
	bSizer1014->Add( height_loaded_texture_label, 0, wxALL, 5 );
	
	
	bSizer1214->Add( bSizer1014, 1, wxEXPAND, 5 );
	
	height_select_texture_button = new wxButton( height_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1214->Add( height_select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	gbSizer35->Add( bSizer1214, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	height_panel->SetSizer( gbSizer35 );
	height_panel->Layout();
	gbSizer35->Fit( height_panel );
	gbSizer1->Add( height_panel, wxGBPosition( 11, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline333 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline333, wxGBPosition( 12, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	porosity_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer36;
	gbSizer36 = new wxGridBagSizer( 0, 0 );
	gbSizer36->SetFlexibleDirection( wxVERTICAL );
	gbSizer36->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label15 = new wxStaticText( porosity_panel, wxID_ANY, wxT("Porosity"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label15->Wrap( -1 );
	gbSizer36->Add( texture_name_label15, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	porosity_color_preview = new wxStaticBitmap( porosity_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer36->Add( porosity_color_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline116 = new wxStaticLine( porosity_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer36->Add( m_staticline116, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer26;
	gbSizer26 = new wxGridBagSizer( 0, 0 );
	gbSizer26->SetFlexibleDirection( wxBOTH );
	gbSizer26->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	porosity_slider = new wxSlider( porosity_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer26->Add( porosity_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	porosity_input = new wxTextCtrl( porosity_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer26->Add( porosity_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label15 = new wxStaticText( porosity_panel, wxID_ANY, wxT("porosity"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label15->Wrap( -1 );
	gbSizer26->Add( red_label15, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer36->Add( gbSizer26, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline215 = new wxStaticLine( porosity_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer36->Add( m_staticline215, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer1215;
	bSizer1215 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1015;
	bSizer1015 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText616 = new wxStaticText( porosity_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText616->Wrap( -1 );
	bSizer1015->Add( m_staticText616, 0, wxALL, 5 );
	
	porosity_loaded_texture_label = new wxStaticText( porosity_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	porosity_loaded_texture_label->Wrap( -1 );
	bSizer1015->Add( porosity_loaded_texture_label, 0, wxALL, 5 );
	
	
	bSizer1215->Add( bSizer1015, 1, wxEXPAND, 5 );
	
	porosity_select_texture_button = new wxButton( porosity_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1215->Add( porosity_select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	gbSizer36->Add( bSizer1215, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	porosity_panel->SetSizer( gbSizer36 );
	porosity_panel->Layout();
	gbSizer36->Fit( porosity_panel );
	gbSizer1->Add( porosity_panel, wxGBPosition( 13, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline334 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline334, wxGBPosition( 14, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	translucense_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer38;
	gbSizer38 = new wxGridBagSizer( 0, 0 );
	gbSizer38->SetFlexibleDirection( wxVERTICAL );
	gbSizer38->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label17 = new wxStaticText( translucense_panel, wxID_ANY, wxT("Translucence"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label17->Wrap( -1 );
	gbSizer38->Add( texture_name_label17, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	translucence_color_preview = new wxStaticBitmap( translucense_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer38->Add( translucence_color_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline118 = new wxStaticLine( translucense_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer38->Add( m_staticline118, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer28;
	gbSizer28 = new wxGridBagSizer( 0, 0 );
	gbSizer28->SetFlexibleDirection( wxBOTH );
	gbSizer28->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	translucence_slider = new wxSlider( translucense_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer28->Add( translucence_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	translucence_red_input = new wxTextCtrl( translucense_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer28->Add( translucence_red_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label17 = new wxStaticText( translucense_panel, wxID_ANY, wxT("translucense"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label17->Wrap( -1 );
	gbSizer28->Add( red_label17, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer38->Add( gbSizer28, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline217 = new wxStaticLine( translucense_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer38->Add( m_staticline217, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer1217;
	bSizer1217 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1017;
	bSizer1017 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText618 = new wxStaticText( translucense_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText618->Wrap( -1 );
	bSizer1017->Add( m_staticText618, 0, wxALL, 5 );
	
	translucence_loaded_texture_label = new wxStaticText( translucense_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	translucence_loaded_texture_label->Wrap( -1 );
	bSizer1017->Add( translucence_loaded_texture_label, 0, wxALL, 5 );
	
	
	bSizer1217->Add( bSizer1017, 1, wxEXPAND, 5 );
	
	translucence_select_texture_button = new wxButton( translucense_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1217->Add( translucence_select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	gbSizer38->Add( bSizer1217, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	translucense_panel->SetSizer( gbSizer38 );
	translucense_panel->Layout();
	gbSizer38->Fit( translucense_panel );
	gbSizer1->Add( translucense_panel, wxGBPosition( 15, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline3341 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline3341, wxGBPosition( 16, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	ao_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer37;
	gbSizer37 = new wxGridBagSizer( 0, 0 );
	gbSizer37->SetFlexibleDirection( wxVERTICAL );
	gbSizer37->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label16 = new wxStaticText( ao_panel, wxID_ANY, wxT("Ambient Occlusion"), wxDefaultPosition, wxDefaultSize, 0 );
	texture_name_label16->Wrap( -1 );
	gbSizer37->Add( texture_name_label16, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	ao_color_preview = new wxStaticBitmap( ao_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer37->Add( ao_color_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline117 = new wxStaticLine( ao_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer37->Add( m_staticline117, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer27;
	gbSizer27 = new wxGridBagSizer( 0, 0 );
	gbSizer27->SetFlexibleDirection( wxBOTH );
	gbSizer27->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ao_slider = new wxSlider( ao_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer27->Add( ao_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	ao_input = new wxTextCtrl( ao_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	gbSizer27->Add( ao_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label16 = new wxStaticText( ao_panel, wxID_ANY, wxT("AO"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label16->Wrap( -1 );
	gbSizer27->Add( red_label16, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer37->Add( gbSizer27, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline216 = new wxStaticLine( ao_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer37->Add( m_staticline216, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer1216;
	bSizer1216 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1016;
	bSizer1016 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText617 = new wxStaticText( ao_panel, wxID_ANY, wxT("Loaded Texture:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText617->Wrap( -1 );
	bSizer1016->Add( m_staticText617, 0, wxALL, 5 );
	
	ao_loaded_texture_label = new wxStaticText( ao_panel, wxID_ANY, wxT("none"), wxDefaultPosition, wxDefaultSize, 0 );
	ao_loaded_texture_label->Wrap( -1 );
	bSizer1016->Add( ao_loaded_texture_label, 0, wxALL, 5 );
	
	
	bSizer1216->Add( bSizer1016, 1, wxEXPAND, 5 );
	
	ao_select_texture_button = new wxButton( ao_panel, wxID_ANY, wxT("Select a Texture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1216->Add( ao_select_texture_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	gbSizer37->Add( bSizer1216, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	ao_panel->SetSizer( gbSizer37 );
	ao_panel->Layout();
	gbSizer37->Fit( ao_panel );
	gbSizer1->Add( ao_panel, wxGBPosition( 17, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	texture_selector_scroll->SetSizer( gbSizer1 );
	texture_selector_scroll->Layout();
	gbSizer1->Fit( texture_selector_scroll );
	bSizer2->Add( texture_selector_scroll, 1, wxEXPAND, 5 );
	
	
	options_panel->SetSizer( bSizer2 );
	options_panel->Layout();
	bSizer15->Add( options_panel, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

_main_window::~_main_window()
{
}
