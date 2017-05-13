//
// Created by gold1 on 26-Apr-17.
//

#ifndef TEXTUREPREVIEWER_MAIN_WINDOW_H
#define TEXTUREPREVIEWER_MAIN_WINDOW_H

#include "../render/gl_texture.h"

#include "texture_preview_canvas.h"
#include "noname.h"


class main_window : public _main_window {
public:
    main_window();
	void on_size_change(wxSizeEvent& event);
protected:
	wxDECLARE_EVENT_TABLE();
private:
	std::unique_ptr<texture_preview_canvas> gl_canvas;

	std::shared_ptr<gl_texture> albedo_tex;
	std::shared_ptr<gl_texture> normal_tex;
	std::shared_ptr<gl_texture> specular_tex;
	std::shared_ptr<gl_texture> smoothness_tex;
	std::shared_ptr<gl_texture> emission_tex;

	void hook_up_albedo_controls();
	void set_albedo_inputs(int red, int green, int blue);

	void hook_up_normal_controls();

	void hook_up_specular_color_controls();
	void set_specular_inputs(int red, int green, int blue);

	void hook_up_smoothness_controls();
	void set_smoothness_inputs(int smoothness);

	void hook_up_emission_controls();
	void set_emission_inputs(int emission);

	void hook_up_height_controle();

	void hook_up_porosity_controls();

	void hook_up_transluscence_controls();

	void hook_up_ao_controls();
};

void set_text_input_value(wxTextCtrl* input, int value);


#endif //TEXTUREPREVIEWER_MAIN_WINDOW_H
