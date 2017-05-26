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
	
	m_menubar1 = new wxMenuBar( 0 );
	export_menu = new wxMenu();
	wxMenuItem* export_pbr_menuitem;
	export_pbr_menuitem = new wxMenuItem( export_menu, ID_EXPORT_PBR, wxString( wxT("To PBR Format") ) + wxT('\t') + wxT("CTRL+e"), wxEmptyString, wxITEM_NORMAL );
	export_menu->Append( export_pbr_menuitem );
	
	m_menubar1->Append( export_menu, wxT("Export") ); 
	
	this->SetMenuBar( m_menubar1 );
	
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
	
	albedo_red_slider = new wxSlider( albedo_panel, albedo_slider, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer2->Add( albedo_red_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_red_input = new wxTextCtrl( albedo_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer2->Add( albedo_red_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label1 = new wxStaticText( albedo_panel, wxID_ANY, wxT("red"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label1->Wrap( -1 );
	gbSizer2->Add( red_label1, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_green_slider = new wxSlider( albedo_panel, albedo_slider, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer2->Add( albedo_green_slider, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_green_input = new wxTextCtrl( albedo_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer2->Add( albedo_green_input, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	green_label = new wxStaticText( albedo_panel, wxID_ANY, wxT("green"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	green_label->Wrap( -1 );
	gbSizer2->Add( green_label, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_blue_slider = new wxSlider( albedo_panel, albedo_slider, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer2->Add( albedo_blue_slider, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	albedo_blue_input = new wxTextCtrl( albedo_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer2->Add( albedo_blue_input, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	blue_label = new wxStaticText( albedo_panel, wxID_ANY, wxT("blue"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	blue_label->Wrap( -1 );
	gbSizer2->Add( blue_label, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer3->Add( gbSizer2, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline21 = new wxStaticLine( albedo_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer3->Add( m_staticline21, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	albedo_file_picker = new wxFilePickerCtrl( albedo_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer3->Add( albedo_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	albedo_panel->SetSizer( gbSizer3 );
	albedo_panel->Layout();
	gbSizer3->Fit( albedo_panel );
	gbSizer1->Add( albedo_panel, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline331 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline331, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	opacity_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer331;
	gbSizer331 = new wxGridBagSizer( 0, 0 );
	gbSizer331->SetFlexibleDirection( wxVERTICAL );
	gbSizer331->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	roughness_texture_name_labell1 = new wxStaticText( opacity_panel, wxID_ANY, wxT("Opacity"), wxDefaultPosition, wxDefaultSize, 0 );
	roughness_texture_name_labell1->Wrap( -1 );
	gbSizer331->Add( roughness_texture_name_labell1, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	opacity_color_preview = new wxStaticBitmap( opacity_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer331->Add( opacity_color_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline1131 = new wxStaticLine( opacity_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer331->Add( m_staticline1131, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer221;
	gbSizer221 = new wxGridBagSizer( 0, 0 );
	gbSizer221->SetFlexibleDirection( wxBOTH );
	gbSizer221->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	opacity_slider = new wxSlider( opacity_panel, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer221->Add( opacity_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	opacity_input = new wxTextCtrl( opacity_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer221->Add( opacity_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label121 = new wxStaticText( opacity_panel, wxID_ANY, wxT("opacity"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label121->Wrap( -1 );
	gbSizer221->Add( red_label121, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer331->Add( gbSizer221, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline2121 = new wxStaticLine( opacity_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer331->Add( m_staticline2121, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	opacity_file_picker = new wxFilePickerCtrl( opacity_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer331->Add( opacity_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	opacity_panel->SetSizer( gbSizer331 );
	opacity_panel->Layout();
	gbSizer331->Fit( opacity_panel );
	gbSizer1->Add( opacity_panel, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	m_staticline3312 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline3312, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
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
	
	normal_file_picker = new wxFilePickerCtrl( normal_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer31->Add( normal_file_picker, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	normal_panel->SetSizer( gbSizer31 );
	normal_panel->Layout();
	gbSizer31->Fit( normal_panel );
	gbSizer1->Add( normal_panel, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline3311 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline3311, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	specular_color_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer32;
	gbSizer32 = new wxGridBagSizer( 0, 0 );
	gbSizer32->SetFlexibleDirection( wxVERTICAL );
	gbSizer32->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	texture_name_label12 = new wxStaticText( specular_color_panel, wxID_ANY, wxT("F0"), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	specular_red_slider = new wxSlider( specular_color_panel, specular_slider, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer21->Add( specular_red_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	specular_red_input = new wxTextCtrl( specular_color_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer21->Add( specular_red_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label11 = new wxStaticText( specular_color_panel, wxID_ANY, wxT("red"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label11->Wrap( -1 );
	gbSizer21->Add( red_label11, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer32->Add( gbSizer21, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline211 = new wxStaticLine( specular_color_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer32->Add( m_staticline211, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	specular_file_picker = new wxFilePickerCtrl( specular_color_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer32->Add( specular_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	specular_color_panel->SetSizer( gbSizer32 );
	specular_color_panel->Layout();
	gbSizer32->Fit( specular_color_panel );
	gbSizer1->Add( specular_color_panel, wxGBPosition( 7, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline33111 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline33111, wxGBPosition( 8, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	smoothness_panel = new wxPanel( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer33;
	gbSizer33 = new wxGridBagSizer( 0, 0 );
	gbSizer33->SetFlexibleDirection( wxVERTICAL );
	gbSizer33->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	roughness_texture_name_labell = new wxStaticText( smoothness_panel, wxID_ANY, wxT("Smoothness"), wxDefaultPosition, wxDefaultSize, 0 );
	roughness_texture_name_labell->Wrap( -1 );
	gbSizer33->Add( roughness_texture_name_labell, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	roughness_color_preview = new wxStaticBitmap( smoothness_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer33->Add( roughness_color_preview, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER|wxALL, 5 );
	
	m_staticline113 = new wxStaticLine( smoothness_panel, wxID_ANY, wxDefaultPosition, wxSize( 264,-1 ), wxLI_HORIZONTAL );
	gbSizer33->Add( m_staticline113, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	wxGridBagSizer* gbSizer22;
	gbSizer22 = new wxGridBagSizer( 0, 0 );
	gbSizer22->SetFlexibleDirection( wxBOTH );
	gbSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	smoothness_slider = new wxSlider( smoothness_panel, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer22->Add( smoothness_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	smoothness_input = new wxTextCtrl( smoothness_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer22->Add( smoothness_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label12 = new wxStaticText( smoothness_panel, wxID_ANY, wxT("smoothness"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label12->Wrap( -1 );
	gbSizer22->Add( red_label12, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer33->Add( gbSizer22, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline212 = new wxStaticLine( smoothness_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer33->Add( m_staticline212, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	smoothness_file_picker = new wxFilePickerCtrl( smoothness_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer33->Add( smoothness_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	smoothness_panel->SetSizer( gbSizer33 );
	smoothness_panel->Layout();
	gbSizer33->Fit( smoothness_panel );
	gbSizer1->Add( smoothness_panel, wxGBPosition( 9, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	ao_ = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( ao_, wxGBPosition( 10, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
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
	
	emission_slider = new wxSlider( emission_panel, wxID_ANY, 0, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer24->Add( emission_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	emission_input = new wxTextCtrl( emission_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer24->Add( emission_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label13 = new wxStaticText( emission_panel, wxID_ANY, wxT("emission"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label13->Wrap( -1 );
	gbSizer24->Add( red_label13, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer34->Add( gbSizer24, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline213 = new wxStaticLine( emission_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer34->Add( m_staticline213, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	emission_file_picker = new wxFilePickerCtrl( emission_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer34->Add( emission_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	emission_panel->SetSizer( gbSizer34 );
	emission_panel->Layout();
	gbSizer34->Fit( emission_panel );
	gbSizer1->Add( emission_panel, wxGBPosition( 11, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline332 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline332, wxGBPosition( 12, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
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
	
	height_slider = new wxSlider( height_panel, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer25->Add( height_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	height_input = new wxTextCtrl( height_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer25->Add( height_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label14 = new wxStaticText( height_panel, wxID_ANY, wxT("height"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label14->Wrap( -1 );
	gbSizer25->Add( red_label14, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer35->Add( gbSizer25, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline214 = new wxStaticLine( height_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer35->Add( m_staticline214, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	height_file_picker = new wxFilePickerCtrl( height_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer35->Add( height_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	height_panel->SetSizer( gbSizer35 );
	height_panel->Layout();
	gbSizer35->Fit( height_panel );
	gbSizer1->Add( height_panel, wxGBPosition( 13, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline333 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline333, wxGBPosition( 14, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
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
	
	porosity_input = new wxTextCtrl( porosity_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer26->Add( porosity_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label15 = new wxStaticText( porosity_panel, wxID_ANY, wxT("porosity"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label15->Wrap( -1 );
	gbSizer26->Add( red_label15, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer36->Add( gbSizer26, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline215 = new wxStaticLine( porosity_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer36->Add( m_staticline215, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	porosity_file_picker = new wxFilePickerCtrl( porosity_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer36->Add( porosity_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	porosity_panel->SetSizer( gbSizer36 );
	porosity_panel->Layout();
	gbSizer36->Fit( porosity_panel );
	gbSizer1->Add( porosity_panel, wxGBPosition( 15, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline334 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline334, wxGBPosition( 16, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
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
	
	translucence_slider = new wxSlider( translucense_panel, wxID_ANY, 0, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer28->Add( translucence_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	translucence_input = new wxTextCtrl( translucense_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer28->Add( translucence_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label17 = new wxStaticText( translucense_panel, wxID_ANY, wxT("translucense"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label17->Wrap( -1 );
	gbSizer28->Add( red_label17, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer38->Add( gbSizer28, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline217 = new wxStaticLine( translucense_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer38->Add( m_staticline217, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	translucence_file_picker = new wxFilePickerCtrl( translucense_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer38->Add( translucence_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	translucense_panel->SetSizer( gbSizer38 );
	translucense_panel->Layout();
	gbSizer38->Fit( translucense_panel );
	gbSizer1->Add( translucense_panel, wxGBPosition( 17, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticline3341 = new wxStaticLine( texture_selector_scroll, wxID_ANY, wxDefaultPosition, wxSize( -1,8 ), wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline3341, wxGBPosition( 18, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
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
	
	ao_slider = new wxSlider( ao_panel, wxID_ANY, 0, 0, 255, wxDefaultPosition, wxSize( 140,20 ), wxSL_HORIZONTAL );
	gbSizer27->Add( ao_slider, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	ao_input = new wxTextCtrl( ao_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_PROCESS_ENTER );
	gbSizer27->Add( ao_input, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	red_label16 = new wxStaticText( ao_panel, wxID_ANY, wxT("AO"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	red_label16->Wrap( -1 );
	gbSizer27->Add( red_label16, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer37->Add( gbSizer27, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	m_staticline216 = new wxStaticLine( ao_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer37->Add( m_staticline216, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	ao_file_picker = new wxFilePickerCtrl( ao_panel, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Image files|*.png;*.jpg;*.jpeg;*.tiff"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	gbSizer37->Add( ao_file_picker, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	
	ao_panel->SetSizer( gbSizer37 );
	ao_panel->Layout();
	gbSizer37->Fit( ao_panel );
	gbSizer1->Add( ao_panel, wxGBPosition( 19, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	texture_selector_scroll->SetSizer( gbSizer1 );
	texture_selector_scroll->Layout();
	gbSizer1->Fit( texture_selector_scroll );
	bSizer2->Add( texture_selector_scroll, 1, wxEXPAND, 5 );
	
	
	options_panel->SetSizer( bSizer2 );
	options_panel->Layout();
	bSizer15->Add( options_panel, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
}

_main_window::~_main_window()
{
}

_export_options_dialogue::_export_options_dialogue( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Select output directory:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText26->Wrap( -1 );
	fgSizer2->Add( m_staticText26, 0, wxALL, 5 );
	
	export_folder_picker = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxSize( 300,-1 ), wxDIRP_DEFAULT_STYLE );
	fgSizer2->Add( export_folder_picker, 0, wxALL, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Filename base:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText27->Wrap( -1 );
	fgSizer2->Add( m_staticText27, 0, wxALL, 5 );
	
	export_filename_input = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), wxTE_PROCESS_ENTER );
	fgSizer2->Add( export_filename_input, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Color texure name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer2->Add( m_staticText28, 0, wxALL, 5 );
	
	color_tex_name_output = new wxStaticText( this, wxID_ANY, wxT(".png"), wxDefaultPosition, wxDefaultSize, 0 );
	color_tex_name_output->Wrap( -1 );
	fgSizer2->Add( color_tex_name_output, 0, wxALL, 5 );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Normal texture name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	fgSizer2->Add( m_staticText32, 0, wxALL, 5 );
	
	normal_tex_name_output = new wxStaticText( this, wxID_ANY, wxT("_n.png"), wxDefaultPosition, wxDefaultSize, 0 );
	normal_tex_name_output->Wrap( -1 );
	fgSizer2->Add( normal_tex_name_output, 0, wxALL, 5 );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Data texture name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer2->Add( m_staticText29, 0, wxALL, 5 );
	
	data_tex_name_output = new wxStaticText( this, wxID_ANY, wxT("_s.png"), wxDefaultPosition, wxDefaultSize, 0 );
	data_tex_name_output->Wrap( -1 );
	fgSizer2->Add( data_tex_name_output, 0, wxALL, 5 );
	
	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Output resolution"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	fgSizer2->Add( m_staticText34, 0, wxALL, 5 );
	
	export_resolution_combobox = new wxComboBox( this, wxID_ANY, wxT("128"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY|wxTE_PROCESS_ENTER );
	export_resolution_combobox->Append( wxT("16") );
	export_resolution_combobox->Append( wxT("32") );
	export_resolution_combobox->Append( wxT("64") );
	export_resolution_combobox->Append( wxT("128") );
	export_resolution_combobox->Append( wxT("256") );
	export_resolution_combobox->Append( wxT("512") );
	export_resolution_combobox->Append( wxT("1024") );
	export_resolution_combobox->Append( wxT("2048") );
	export_resolution_combobox->Append( wxT("4096") );
	export_resolution_combobox->SetSelection( 3 );
	fgSizer2->Add( export_resolution_combobox, 0, wxALL, 5 );
	
	
	fgSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	export_button = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( export_button, 0, wxALL, 5 );
	
	
	this->SetSizer( fgSizer2 );
	this->Layout();
	fgSizer2->Fit( this );
	
	this->Centre( wxBOTH );
}

_export_options_dialogue::~_export_options_dialogue()
{
}
