//
// Created by gold1 on 26-Apr-17.
//

#include "main_window.h"

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

	auto options_panel_width = options_panel->GetSize().GetWidth();

	auto size = GetClientSize();
	size -= wxSize(options_panel_width, 0);
	gl_canvas = std::make_unique<texture_preview_canvas>(this, attrs, size);
}

void main_window::hook_up_albedo_controls() {
	auto slider_update_function = [&](wxScrollEvent& event) {
		auto red_val = albedo_red_slider->GetValue();
		auto green_value = albedo_green_slider->GetValue();
		auto blue_val = albedo_blue_slider->GetValue();

		albedo->set_color(red_val, green_value, blue_val);
	};
}
