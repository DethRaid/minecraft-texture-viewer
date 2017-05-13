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

void main_window::hook_up_albedo_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto red = albedo_red_slider->GetValue();
		auto green = albedo_green_slider->GetValue();
		auto blue = albedo_blue_slider->GetValue();

		LOG(DEBUG) << "Updating albedo color to (" << red << ", " << green << ", " << blue << ")";

		albedo_tex = std::make_shared<gl_texture>(ALBEDO_BINDING, red, green, blue);

		set_albedo_inputs(red, green, blue);
	};

	albedo_red_slider->Bind(wxEVT_SLIDER, slider_update_function);
	albedo_green_slider->Bind(wxEVT_SLIDER, slider_update_function);
	albedo_blue_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto red = std::atoi(albedo_red_input->GetValue());
		auto green = std::atoi(albedo_green_input->GetValue());
		auto blue = std::atoi(albedo_blue_input->GetValue());

		LOG(DEBUG) << "Updating albedo color to (" << red << ", " << green << ", " << blue << ")";

		albedo_tex = std::make_shared<gl_texture>(ALBEDO_BINDING, red, green, blue);

		set_albedo_inputs(red, green, blue);
	};

	albedo_red_input->Bind(wxEVT_TEXT_ENTER, input_update);
	albedo_green_input->Bind(wxEVT_TEXT_ENTER, input_update);
	albedo_blue_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		albedo_tex = std::make_shared<gl_texture>(3, event.GetPath().ToStdString());
	};

	albedo_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_albedo_inputs(int red, int green, int blue) {
	set_text_input_value(albedo_red_input, red);
	set_text_input_value(albedo_green_input, green);
	set_text_input_value(albedo_blue_input, blue);

	albedo_red_slider->SetValue(red);
	albedo_green_slider->SetValue(green);
	albedo_blue_slider->SetValue(blue);
}

void main_window::hook_up_normal_controls() {
	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		normal_tex = std::make_shared<gl_texture>(NORMAL_BINDING, event.GetPath().ToStdString());
	};

	normal_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);
}

void main_window::hook_up_specular_color_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto red = specular_red_slider->GetValue();
		auto green = specular_green_slider->GetValue();
		auto blue = specular_blue_slider->GetValue();

		LOG(DEBUG) << "Updating specular color to (" << red << ", " << green << ", " << blue << ")";

		specular_tex = std::make_shared<gl_texture>(F0_BINDING, red, green, blue);

		set_specular_inputs(red, green, blue);
	};

	specular_red_slider->Bind(wxEVT_SLIDER, slider_update_function);
	specular_green_slider->Bind(wxEVT_SLIDER, slider_update_function);
	specular_blue_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto red = std::atoi(specular_red_input->GetValue());
		auto green = std::atoi(specular_green_input->GetValue());
		auto blue = std::atoi(specular_blue_input->GetValue());

		LOG(DEBUG) << "Updating specular color to (" << red << ", " << green << ", " << blue << ")";

		specular_tex = std::make_shared<gl_texture>(F0_BINDING, red, green, blue);

		set_specular_inputs(red, green, blue);
	};

	specular_red_input->Bind(wxEVT_TEXT_ENTER, input_update);
	specular_green_input->Bind(wxEVT_TEXT_ENTER, input_update);
	specular_blue_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		specular_tex = std::make_shared<gl_texture>(F0_BINDING, event.GetPath().ToStdString());
	};

	specular_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_specular_inputs(int red, int green, int blue) {
	set_text_input_value(specular_red_input, red);
	set_text_input_value(specular_green_input, green);
	set_text_input_value(specular_blue_input, blue);

	specular_red_slider->SetValue(red);
	specular_green_slider->SetValue(green);
	specular_blue_slider->SetValue(blue);
}

void main_window::hook_up_smoothness_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto smoothness = smoothness_slider->GetValue();

		LOG(DEBUG) << "Updating smoothness to " << smoothness;

		smoothness_tex = std::make_shared<gl_texture>(SMOOTHNESS_BINDING, smoothness);

		set_smoothness_inputs(smoothness);
	};

	smoothness_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto smoothness = std::atoi(smoothness_input->GetValue());

		LOG(DEBUG) << "Updating smoothness to " << smoothness;

		smoothness_tex = std::make_shared<gl_texture>(SMOOTHNESS_BINDING, smoothness);

		set_smoothness_inputs(smoothness);
	};

	smoothness_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		smoothness_tex = std::make_shared<gl_texture>(SMOOTHNESS_BINDING, event.GetPath().ToStdString());
	};

	smoothness_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_smoothness_inputs(int smoothness) {
	set_text_input_value(smoothness_input, smoothness);

	smoothness_slider->SetValue(smoothness);
}

void main_window::hook_up_emission_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto emission = emission_slider->GetValue();

		LOG(DEBUG) << "Updating emission to " << emission;

		emission_tex = std::make_shared<gl_texture>(EMISSION_BINDING, emission);

		set_emission_inputs(emission);
	};

	emission_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto emission = std::atoi(emission_input->GetValue());

		LOG(DEBUG) << "Updating emission to " << emission;

		emission_tex = std::make_shared<gl_texture>(EMISSION_BINDING, emission);

		set_emission_inputs(emission);
	};

	emission_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		emission_tex = std::make_shared<gl_texture>(EMISSION_BINDING, event.GetPath().ToStdString());
	};

	emission_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_emission_inputs(int emission) {
	set_text_input_value(emission_input, emission);

	emission_slider->SetValue(emission);
}

wxBEGIN_EVENT_TABLE(main_window, _main_window)
	EVT_SIZE(main_window::on_size_change)
wxEND_EVENT_TABLE()

void set_text_input_value(wxTextCtrl* input, int value) {
	std::stringstream converter;
	converter << value;
	input->SetValue(converter.str());
}
