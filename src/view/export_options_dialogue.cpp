#include "export_options_dialogue.h"

#include <easylogging++.h>

#include <wx/msgdlg.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

export_options_dialogue::export_options_dialogue(wxWindow* parent, textures_struct& textures) :
	_export_options_dialogue(parent), textures(textures) {
	export_folder_picker->Bind(wxEVT_FILEPICKER_CHANGED, [&](wxFileDirPickerEvent& event) {
		LOG(DEBUG) << "Set output file path to " << event.GetPath();
		output_directory = event.GetPath().ToStdString();
	});

	export_filename_input->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
		LOG(DEBUG) << "Set output filename to " << export_filename_input->GetValue();
		grab_filename_base();
	});

	export_resolution_combobox->Bind(wxEVT_COMBOBOX, [&](auto& event) {
		auto resolution = std::atoi(export_resolution_combobox->GetValue().ToStdString().c_str());
		LOG(DEBUG) << "Set output resolution to " << resolution;
		texture_size = resolution;
	});

	export_button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		LOG(INFO) << "Building textures";
		grab_filename_base();

		if(output_directory.size() < 1) {
			LOG(ERROR) << "No output directory set";
			wxMessageBox("Please enter a value for the output directory", "Error", wxOK | wxICON_ERROR, this);
			return;
		}

		if(filename_base.size() < 1) {
			LOG(ERROR) << "No filename base set";
			wxMessageBox("Please enter a value for the filename base", "Error", wxOK | wxICON_ERROR, this);
			return;
		}

		output_pbr_color_texture();
		output_pbr_normal_texture();
		//output_pbr_data_texture();
	});
}

void export_options_dialogue::grab_filename_base() {
	filename_base = export_filename_input->GetValue().ToStdString();

	color_tex_name_output->SetLabel(filename_base + ".png");
	normal_tex_name_output->SetLabel(filename_base + "_n.png");
	data_tex_name_output->SetLabel(filename_base + "_s.png");
}

void export_options_dialogue::output_pbr_color_texture() {
	float pixel_size = 1.0f / texture_size;
	char * data = new char[texture_size * texture_size * 4];
	int idx = 0;

	for(float v = 0; v <= 1; v += pixel_size) {
		for(float u = 0; u <= 1; u += pixel_size) {
			auto color_sample = textures.albedo_tex->at({ u, v });
			auto opacity_sample = textures.opacity_tex->at({ u, v });

			data[idx] = color_sample.r;
			data[idx + 1] = color_sample.g;
			data[idx + 2] = color_sample.b;
			data[idx + 3] = opacity_sample.r;

			idx += 4;
		}
	}

	auto color_file_path = output_directory + filename_base + ".png";
	auto err = stbi_write_png(color_file_path.c_str(), texture_size, texture_size, 4, data, 0);
	if(err) {
		LOG(ERROR) << "Could not write color texture " << color_file_path;
		wxMessageBox("Could not write color texture " + color_file_path, "Error", wxOK | wxICON_ERROR, this);
	}
}

void export_options_dialogue::output_pbr_normal_texture() {
	float pixel_size = 1.0f / texture_size;
	char * data = new char[texture_size * texture_size * 4];
	int idx = 0;

	for(float v = 0; v <= 1; v += pixel_size) {
		for(float u = 0; u <= 1; u += pixel_size) {
			auto sample_pos = glm::vec2{ u, v };
			auto normal_sample = textures.normal_tex->at(sample_pos);
			auto ao_sample = textures.ao_tex->at(sample_pos);
			auto emission_sample = textures.emission_tex->at(sample_pos);
			auto translucence_sample = textures.translucence_tex->at(sample_pos);
			auto color_sample = textures.albedo_tex->at(glm::vec2(u, v));
			auto opacity_sample = textures.opacity_tex->at(glm::vec2(u, v));

			data[idx] = color_sample.r;
			data[idx + 1] = color_sample.g;
			data[idx + 2] = color_sample.b;
			data[idx + 3] = opacity_sample.r;

			idx += 4;
		}
	}

	auto normal_texture_path = output_directory + filename_base + "_n.png";
	auto err = stbi_write_png(normal_texture_path.c_str(), texture_size, texture_size, 4, data, 0);
	if(err) {
		LOG(ERROR) << "Could not write normal texture " << normal_texture_path;
		wxMessageBox("Could not write normal texture " + normal_texture_path, "Error", wxOK | wxICON_ERROR, this);
	}
}

