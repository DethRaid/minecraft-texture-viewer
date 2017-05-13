//
// Created by gold1 on 26-Apr-17.
//

#include "main_window.h"
#include <wx/filepicker.h>
#include <sstream>

#include <easylogging++.h>

main_window::main_window() : _main_window(nullptr, wxID_ANY, "Minecraft Shaderpack Texture Viewer") {
	wxGLAttributes attrs;
	attrs.PlatformDefaults().Defaults().EndList();
	bool accepted = wxGLCanvas::IsDisplaySupported(attrs);

	if(!accepted) {
		LOG(WARNING) << "Could not create OpenGL context with default attributes, trying again";

		attrs.Reset();
		attrs.PlatformDefaults().MinRGBA(8, 8, 8, 8).DoubleBuffer().Depth(24).EndList();
		accepted = wxGLCanvas::IsDisplaySupported(attrs);

		if(!accepted) {
			LOG(ERROR) << "Could not create OpenGL context with needed attributes";
		}
	}

	auto options_panel_width = options_panel->GetSize().GetWidth();

	auto size = GetClientSize();
	size -= wxSize(options_panel_width, 0);
	gl_canvas = std::make_unique<texture_preview_canvas>(this, attrs, size);
	hook_up_albedo_controls();
}

void main_window::on_size_change(wxSizeEvent& event) {
	auto size = event.GetSize();
	size -= wxSize(options_panel->GetSize().GetWidth(), 0);
	gl_canvas->on_size_change(size);
}

void main_window::set_input_value(wxTextCtrl* input, int value) {
	std::stringstream converter;
	converter << value;
	input->SetValue(converter.str());
}

void main_window::hook_up_albedo_controls() {
	albedo = std::make_shared<gl_texture>(3);

	auto slider_update_function = [&](wxCommandEvent& event) {
		auto red_val = albedo_red_slider->GetValue();
		auto green_value = albedo_green_slider->GetValue();
		auto blue_val = albedo_blue_slider->GetValue();

		LOG(TRACE) << "Updating albedo color to (" << red_val << ", " << green_value << ", " << blue_val << ")";

		albedo->set_color(red_val, green_value, blue_val);

		set_albedo_inputs(red_val, green_value, blue_val);
	};

	albedo_red_slider->Bind(wxEVT_SLIDER, slider_update_function);
	albedo_green_slider->Bind(wxEVT_SLIDER, slider_update_function);
	albedo_blue_slider->Bind(wxEVT_SLIDER, slider_update_function);

	slider_update_function(wxCommandEvent());
}

void main_window::set_albedo_inputs(int red, int green, int blue) {
	set_input_value(albedo_red_input, red);
	set_input_value(albedo_green_input, green);
	set_input_value(albedo_blue_input, blue);
}

wxBEGIN_EVENT_TABLE(main_window, _main_window)
	EVT_SIZE(main_window::on_size_change)
wxEND_EVENT_TABLE()
