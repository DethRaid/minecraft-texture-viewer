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
	hook_up_opacity_controls();
	hook_up_normal_controls();
	hook_up_specular_color_controls();
	hook_up_smoothness_controls();
	hook_up_height_controls();
	hook_up_porosity_controls();
	hook_up_translucence_controls();
	hook_up_ao_controls();
	hook_up_emission_controls();
}

void main_window::on_size_change(wxSizeEvent& event) {
	event.Skip();

	auto size = event.GetSize();
	size -= wxSize(options_panel->GetSize().GetWidth(), 0);
	gl_canvas->on_size_change(size);
}

void main_window::on_export_textures_pbr(wxCommandEvent& event) {
	LOG(INFO) << "Exporting textures...";

	export_dialogue.reset();
	export_dialogue = std::make_unique<export_options_dialogue>(this, textures);
	export_dialogue->Show(true);
}

void main_window::hook_up_albedo_controls() {
	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.albedo_tex = std::make_shared<texture>(3, event.GetPath().ToStdString());
	};

	albedo_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);
}

void main_window::hook_up_opacity_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto opacity = opacity_slider->GetValue();

		set_opacity(opacity);
	};

	opacity_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto opacity = get_input_value(opacity_input);

		set_opacity(opacity);
	};

	opacity_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.opacity_tex = std::make_shared<texture>(OPACITY_BINDING, event.GetPath().ToStdString());
	};

	opacity_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_opacity(int opacity) {
	set_text_input_value(opacity_input, opacity);

	opacity_slider->SetValue(opacity);

	LOG(DEBUG) << "Updating opacity to " << opacity;

	textures.opacity_tex = std::make_shared<texture>(OPACITY_BINDING, opacity);
}

void main_window::hook_up_normal_controls() {
	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.normal_tex = std::make_shared<texture>(NORMAL_BINDING, event.GetPath().ToStdString());
	};

	normal_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);
}

void main_window::hook_up_specular_color_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto f0 = specular_red_slider->GetValue();

		set_f0(f0);
	};

	specular_red_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto f0 = get_input_value(specular_red_input);

		set_f0(f0);
	};

	specular_red_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.f0_tex = std::make_shared<texture>(F0_BINDING, event.GetPath().ToStdString());
	};

	specular_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_f0(int f0) {
	set_text_input_value(specular_red_input, f0);

	specular_red_slider->SetValue(f0);


	LOG(DEBUG) << "Updating F0 to " << f0;

	textures.f0_tex = std::make_shared<texture>(F0_BINDING, f0);
}

void main_window::hook_up_smoothness_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto smoothness = smoothness_slider->GetValue();

		set_smoothness(smoothness);
	};

	smoothness_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto smoothness = get_input_value(smoothness_input);

		set_smoothness(smoothness);
	};

	smoothness_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.smoothness_tex = std::make_shared<texture>(SMOOTHNESS_BINDING, event.GetPath().ToStdString());
	};

	smoothness_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_smoothness(int smoothness) {
	set_text_input_value(smoothness_input, smoothness);

	smoothness_slider->SetValue(smoothness);

	LOG(DEBUG) << "Updating smoothness to " << smoothness;

	textures.smoothness_tex = std::make_shared<texture>(SMOOTHNESS_BINDING, smoothness);
}

void main_window::hook_up_emission_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto emission = emission_slider->GetValue();

		set_emission(emission);
	};

	emission_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto emission = get_input_value(emission_input);

		set_emission(emission);
	};

	emission_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.emission_tex = std::make_shared<texture>(EMISSION_BINDING, event.GetPath().ToStdString());
	};

	emission_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_emission(int emission) {
	set_text_input_value(emission_input, emission);

	emission_slider->SetValue(emission);

	LOG(DEBUG) << "Updating emission to " << emission;

	textures.emission_tex = std::make_shared<texture>(EMISSION_BINDING, emission);
}

void main_window::hook_up_height_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto height = height_slider->GetValue();

		set_height(height);
	};

	height_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto height = get_input_value(height_input);

		set_height(height);
	};

	height_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.height_tex = std::make_shared<texture>(HEIGHT_BINDING, event.GetPath().ToStdString());
	};

	height_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_height(int height) {
	set_text_input_value(height_input, height);

	height_slider->SetValue(height);

	LOG(DEBUG) << "Updating height to " << height;

	textures.height_tex = std::make_shared<texture>(HEIGHT_BINDING, height);
}

void main_window::hook_up_porosity_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto porosity = porosity_slider->GetValue();

		set_porosity(porosity);
	};

	porosity_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto porosity = get_input_value(porosity_input);

		set_porosity(porosity);
	};

	porosity_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.porosity_tex = std::make_shared<texture>(POROSITY_BINDING, event.GetPath().ToStdString());
	};

	porosity_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_porosity(int porosity) {
	set_text_input_value(porosity_input, porosity);

	porosity_slider->SetValue(porosity);

	LOG(DEBUG) << "Updating porosity to " << porosity;

	textures.porosity_tex = std::make_shared<texture>(POROSITY_BINDING, porosity);
}

void main_window::hook_up_translucence_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto translucence = translucence_slider->GetValue();

		set_translucence(translucence);
	};

	translucence_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto translucence = get_input_value(translucence_input);

		set_translucence(translucence);
	};

	translucence_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.translucence_tex = std::make_shared<texture>(TRANSLUCENCE_BINDING, event.GetPath().ToStdString());
	};

	translucence_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_translucence(int translucence) {
	set_text_input_value(translucence_input, translucence);

	translucence_slider->SetValue(translucence);

	LOG(DEBUG) << "Updating translucence to " << translucence;

	textures.translucence_tex = std::make_shared<texture>(TRANSLUCENCE_BINDING, translucence);
}

void main_window::hook_up_ao_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		auto ao = ao_slider->GetValue();

		set_ao(ao);
	};

	ao_slider->Bind(wxEVT_SLIDER, slider_update_function);

	auto input_update = [&](wxCommandEvent& event) {
		auto ao = get_input_value(ao_input);

		set_ao(ao);
	};

	ao_input->Bind(wxEVT_TEXT_ENTER, input_update);

	auto filepicker_update = [&](wxFileDirPickerEvent& event) {
		LOG(INFO) << "Grabbed file " << event.GetPath();
		textures.ao_tex = std::make_shared<texture>(AO_BINDING, event.GetPath().ToStdString());
	};

	ao_file_picker->Bind(wxEVT_FILEPICKER_CHANGED, filepicker_update);

	slider_update_function(wxCommandEvent());
}

void main_window::set_ao(int ao) {
	set_text_input_value(ao_input, ao);

	ao_slider->SetValue(ao);

	LOG(DEBUG) << "Updating ao to " << ao;

	textures.ao_tex = std::make_shared<texture>(AO_BINDING, ao);
}

void main_window::refresh_shaders(wxCommandEvent& event) {
	gl_canvas->load_shaders();
}

void main_window::change_background_to_blue_hour(wxCommandEvent& event) {
	change_background("blue_hour_at_pier.hdr");
}

void main_window::change_background_to_autumn_road(wxCommandEvent& event) {
	change_background("golden_autumn_road.hdr");
}

void main_window::change_background_to_road_in_valley(wxCommandEvent& event) {
	change_background("road_in_valley.hdr");
}

void main_window::change_background(std::string background_name) {
	gl_canvas->change_background(background_name);
}

wxBEGIN_EVENT_TABLE(main_window, _main_window)
	EVT_SIZE(									main_window::on_size_change)
	EVT_MENU(ID_EXPORT_PBR,						main_window::on_export_textures_pbr)
	EVT_MENU(ID_REFRESH_SHADERS,				main_window::refresh_shaders)
	EVT_MENU(ID_BLUE_HOUR_AT_PIER_BACKGROUND,	main_window::change_background_to_blue_hour)
	EVT_MENU(ID_GOLDEN_AUTUMN_ROAD_BACKGROUND,	main_window::change_background_to_autumn_road)
	EVT_MENU(ID_ROAD_IN_VALLEY_BACKGROUND,		main_window::change_background_to_road_in_valley)
wxEND_EVENT_TABLE()

void set_text_input_value(wxTextCtrl* input, int value) {
	static std::stringstream converter;
	converter.precision(3);
	converter << std::fixed << float(value) / 255.f;
	input->SetValue(converter.str());
	converter.str("");
}

float get_input_value(wxTextCtrl* input) {
	return std::atof(input->GetValue()) * 255;
}
