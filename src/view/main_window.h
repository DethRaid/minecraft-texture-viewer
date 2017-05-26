//
// Created by gold1 on 26-Apr-17.
//

#ifndef TEXTUREPREVIEWER_MAIN_WINDOW_H
#define TEXTUREPREVIEWER_MAIN_WINDOW_H

#include "noname.h"
#include "texture_preview_canvas.h"
#include "export_options_dialogue.h"


class main_window : public _main_window {
public:
    main_window();
	void on_size_change(wxSizeEvent& event);
protected:
	wxDECLARE_EVENT_TABLE();
private:
	std::unique_ptr<texture_preview_canvas> gl_canvas;
	std::unique_ptr<export_options_dialogue> export_dialogue;

	textures_struct textures;

	void hook_up_albedo_controls();
	void set_albedo(int red, int green, int blue);

	void hook_up_opacity_controls();
	void set_opacity(int opacity);

	void hook_up_normal_controls();

	void hook_up_specular_color_controls();
	void set_f0(int f0);

	void hook_up_smoothness_controls();
	void set_smoothness(int smoothness);

	void hook_up_emission_controls();
	void set_emission(int emission);

	void hook_up_height_controls();
	void set_height(int height);

	void hook_up_porosity_controls();
	void set_porosity(int porosity);

	void hook_up_translucence_controls();
	void set_translucence(int translucence);

	void hook_up_ao_controls();
	void set_ao(int ao);

	void on_export_textures_pbr(wxCommandEvent& event);
};

void set_text_input_value(wxTextCtrl* input, int value);


#endif //TEXTUREPREVIEWER_MAIN_WINDOW_H
