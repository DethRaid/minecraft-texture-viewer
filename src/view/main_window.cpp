//
// Created by gold1 on 26-Apr-17.
//

#include "main_window.h"
#include "texture_preview_canvas.h"

#include <easylogging++.h>

main_window::main_window() : _main_window(nullptr, wxID_ANY, "Minecraft Shaderpack Texture Viewer") {
	wxGLAttributes attrs;
	attrs.PlatformDefaults().Defaults().EndList();
	bool accepted = wxGLCanvas::IsDisplaySupported(attrs);

	if(!accepted) {
		LOG(WARNING) << "Could not create OpenGL context with default attributes, trying again";

		attrs.Reset();
		attrs.PlatformDefaults().RGBA().DoubleBuffer().Depth(16).EndList();
		accepted = wxGLCanvas::IsDisplaySupported(attrs);

		if(!accepted) {
			LOG(ERROR) << "Could not create OpenGL context with needed attributes";
		}
	}

	auto texture_canvas = new texture_preview_canvas(this, attrs);
	//opengl_panel->GetSizer()->Add(texture_canvas, 1, wxEXPAND | wxALL, 0);
	//opengl_panel->Layout();
}
