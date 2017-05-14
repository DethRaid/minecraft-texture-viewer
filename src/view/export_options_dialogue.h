#ifndef EXPORT_DIALOGUE_OPTIONS_H
#define EXPORT_DIALOGUE_OPTIONS_H

#include <string>
#include <memory>
#include "noname.h"
#include "../render/gl_texture.h"

class export_options_dialogue : public _export_options_dialogue {
public:
	export_options_dialogue(wxWindow* parent, textures_struct textures);

private:
	textures_struct textures;
	int texture_size;

	std::string export_folder;
	std::string export_filename;
};

#endif