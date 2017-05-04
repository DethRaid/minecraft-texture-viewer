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
private:
	std::unique_ptr<texture_preview_canvas> gl_canvas;

	gl_texture albedo;

	void hook_up_albedo_controls();

	void on_albedo_slider(wxScrollEvent& event);

	DECLARE_EVENT_TABLE()

	enum {
		main_window_albedo_slider,
	};
};


#endif //TEXTUREPREVIEWER_MAIN_WINDOW_H
