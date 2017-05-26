#ifndef EXPORT_DIALOGUE_OPTIONS_H
#define EXPORT_DIALOGUE_OPTIONS_H

#include <string>
#include <memory>
#include "noname.h"
#include "../render/gl_texture.h"

class export_options_dialogue : public _export_options_dialogue {
public:
	export_options_dialogue(wxWindow* parent, textures_struct& textures);

private:
	textures_struct& textures;
	int texture_size = 128;

	std::string output_directory;
	std::string filename_base;

	void grab_filename_base();

	void output_pbr_color_texture();
	void output_pbr_normal_texture();
	//void output_pbr_data_texture();
};

#endif