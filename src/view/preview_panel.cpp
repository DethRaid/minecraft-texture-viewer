#include "../render/glad.h"

#include "preview_panel.h"

#include <easylogging++.h>
#include <stdexcept>

preview_panel::preview_panel(wxFrame* parent, wxGLAttributes& attrs) : wxGLCanvas(parent, attrs) {
	wxGLContextAttrs contextAttribs;
	contextAttribs.PlatformDefaults().CoreProfile().OGLVersion(4, 5).EndList();

	context = std::make_unique<wxGLContext>(this, nullptr, &contextAttribs);

	if(!context->IsOK()) {
		LOG(ERROR) << "Could not create OpenGL context";
		//throw std::runtime_error("Could not initialize OpenGL");
	}

	context->SetCurrent(*this);
}

void preview_panel::render(wxPaintEvent& WXUNUSED(event)) {
	wxPaintDC(this);
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR);

	glFlush();
	SwapBuffers();
}

void preview_panel::on_size_change(wxSizeEvent& event) {
	event.Skip();

	SetCurrent(*context);

	if(gladLoadGL()) {
		LOG(ERROR) << "Could not load OpenGL functions";
		//throw std::runtime_error("Could not initialize OpenGL");
	}

	PostSizeEvent();

	SetCurrent(*context);

	window_height = event.GetSize().y;
	window_height = event.GetSize().x;

	glViewport(0, 0, window_width, window_height);
}

wxBEGIN_EVENT_TABLE(preview_panel, wxGLCanvas)
EVT_PAINT(preview_panel::render)
EVT_SIZE(preview_panel::on_size_change)
wxEND_EVENT_TABLE()