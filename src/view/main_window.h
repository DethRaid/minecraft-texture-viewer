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

	std::shared_ptr<gl_texture> albedo;

	void hook_up_albedo_controls();
	void set_albedo_inputs(int red, int green, int blue);

	void set_input_value(wxTextCtrl* input, int value);
};


#endif //TEXTUREPREVIEWER_MAIN_WINDOW_H
