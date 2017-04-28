//
// Created by gold1 on 26-Apr-17.
//

#ifndef TEXTUREPREVIEWER_MAIN_WINDOW_H
#define TEXTUREPREVIEWER_MAIN_WINDOW_H

#include "noname.h"
#include "texture_preview_canvas.h"

class main_window : public _main_window {
public:
    main_window();
private:
	std::unique_ptr<texture_preview_canvas> gl_canvas;
};


#endif //TEXTUREPREVIEWER_MAIN_WINDOW_H
