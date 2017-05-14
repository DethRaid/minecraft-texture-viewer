#include "export_options_dialogue.h"

#include <easylogging++.h>

export_options_dialogue::export_options_dialogue(wxWindow* parent, textures_struct textures) :
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
	});
}