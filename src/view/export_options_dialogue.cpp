#include "export_options_dialogue.h"

#include <easylogging++.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

export_options_dialogue::export_options_dialogue(wxWindow* parent, textures_struct& textures) :
	_export_options_dialogue(parent), textures(textures) {
	export_folder_picker->Bind(wxEVT_FILEPICKER_CHANGED, [&](wxFileDirPickerEvent& event) {
		LOG(DEBUG) << "Set output file path to " << event.GetPath();
		export_folder = event.GetPath().ToStdString();
	});

	export_filename_input->Bind(wxEVT_TEXT_ENTER, [&](wxCommandEvent& event) {
		LOG(DEBUG) << "Set output filename to " << export_filename_input->GetValue();
		export_filename = export_filename_input->GetValue().ToStdString();
	});

	export_resolution_combobox->Bind(wxEVT_COMBOBOX, [&](wxCommandEvent& event) {
		auto resolution = std::atoi(export_resolution_combobox->GetValue().ToStdString().c_str());
		LOG(DEBUG) << "Set output resolution to " << resolution;
		texture_size = resolution;
	});

	export_button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		LOG(INFO) << "Building textures";
		output_pbr_color_texture();
		//output_pbr_normal_texture();
		//output_pbr_data_texture();
	});
}

void export_options_dialogue::output_pbr_color_texture() {
	float pixel_size = 1.0f / texture_size;
	char * data = new char[texture_size * texture_size * 4];
	int idx = 0;

	for(int v = 0; v <= 1; v += pixel_size) {
		for(int u = 0; u <= 1; u += pixel_size) {
			auto color_sample = textures.albedo_tex->at(glm::vec2(u, v));
			auto opacity_sample = textures.opacity_tex->at(glm::vec2(u, v));

			data[idx] = color_sample.r;
			data[idx + 1] = color_sample.g;
			data[idx + 2] = color_sample.b;
			data[idx + 3] = opacity_sample.r;

			idx += 4;
		}
	}

	auto color_file_path = export_folder + export_filename + ".png";
	auto err = stbi_write_png(color_file_path.c_str(), texture_size, texture_size, 4, data, 0);
	if(err) {
		LOG(ERROR) << "Could not write color texture " << color_file_path;
	}
}

