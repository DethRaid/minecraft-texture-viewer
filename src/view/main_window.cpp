//
// Created by gold1 on 26-Apr-17.
//

#include "main_window.h"
#include <wx/filepicker.h>

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
	hook_up_albedo_controls();
}

void main_window::hook_up_albedo_controls() {
	auto slider_update_function = [&](wxCommandEvent& event) {
		LOG(INFO) << "Updating albedo color";
		auto red_val = albedo_red_slider->GetValue();
		auto green_value = albedo_green_slider->GetValue();
		auto blue_val = albedo_blue_slider->GetValue();

		albedo.set_color(red_val, green_value, blue_val);
	};

	albedo_red_slider->Bind(wxEVT_SLIDER, [&](wxCommandEvent& event) {
		LOG(INFO) << "Updating albedo color";
		auto red_val = albedo_red_slider->GetValue();
		auto green_value = albedo_green_slider->GetValue();
		auto blue_val = albedo_blue_slider->GetValue();

		albedo.set_color(red_val, green_value, blue_val);
	});

	albedo_green_slider->Bind(wxEVT_SLIDER, slider_update_function);
	albedo_blue_slider->Bind(wxEVT_SLIDER, slider_update_function);
}

void main_window::on_albedo_slider(wxScrollEvent& event) {

	wxEventType eventType = event.GetEventType();

	/*
	This array takes the EXACT order of the declarations in
	include/wx/event.h
	(section "wxScrollBar and wxSlider event identifiers")
	*/
	static const wxChar *eventNames[] =
	{
		wxT("wxEVT_SCROLL_TOP"),
		wxT("wxEVT_SCROLL_BOTTOM"),
		wxT("wxEVT_SCROLL_LINEUP"),
		wxT("wxEVT_SCROLL_LINEDOWN"),
		wxT("wxEVT_SCROLL_PAGEUP"),
		wxT("wxEVT_SCROLL_PAGEDOWN"),
		wxT("wxEVT_SCROLL_THUMBTRACK"),
		wxT("wxEVT_SCROLL_THUMBRELEASE"),
		wxT("wxEVT_SCROLL_CHANGED")
	};

	int index = eventType - wxEVT_SCROLL_TOP;

	/*
	If this assert is triggered, there is an unknown slider event which
	should be added to the above eventNames array.
	*/
	wxASSERT_MSG(index >= 0 && (size_t)index < WXSIZEOF(eventNames),
		wxT("Unknown slider event"));


	static int s_numSliderEvents = 0;

	wxLogMessage(wxT("Slider event #%d: %s (pos = %d, int value = %d)"),
		s_numSliderEvents++,
		eventNames[index],
		event.GetPosition(),
		event.GetInt());

	LOG(INFO) << "Updating albedo color";
	auto red_val = albedo_red_slider->GetValue();
	auto green_value = albedo_green_slider->GetValue();
	auto blue_val = albedo_blue_slider->GetValue();

	albedo.set_color(red_val, green_value, blue_val);
}

wxBEGIN_EVENT_TABLE(main_window, _main_window)
	EVT_COMMAND_SCROLL(albedo_slider, main_window::on_albedo_slider)
wxEND_EVENT_TABLE()
