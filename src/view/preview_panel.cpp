#include "../render/glad.h"

#include "preview_panel.h"

#include <easylogging++.h>
#include <stdexcept>

texture_preview_canvas::texture_preview_canvas(wxFrame* parent, wxGLAttributes& attrs) : wxGLCanvas(parent, attrs) {
	wxGLContextAttrs contextAttribs;
	contextAttribs.PlatformDefaults().CoreProfile().OGLVersion(4, 5).EndList();

	context = std::make_unique<wxGLContext>(this, nullptr, &contextAttribs);

	if(!context->IsOK()) {
		LOG(ERROR) << "Could not create OpenGL context";
		//throw std::runtime_error("Could not initialize OpenGL");
	}

	context->SetCurrent(*this);
	SetCurrent(*context);

	init_opengl();
	glViewport(0, 0, window_width, window_height);
}

void texture_preview_canvas::render(wxPaintEvent& WXUNUSED(event)) {
	LOG(INFO) << "Rendering";
	wxPaintDC(this);
	SetCurrent(*context);

	if(render_available) {
		glClear(GL_COLOR);

		glFlush();
	}
	SwapBuffers();
}

void texture_preview_canvas::on_size_change(wxSizeEvent& event) {
	event.Skip();

	SetCurrent(*context);

	PostSizeEvent();

	window_height = event.GetSize().y;
	window_height = event.GetSize().x;

	glViewport(0, 0, window_width, window_height);
}

void texture_preview_canvas::init_opengl() {
	if(!gladLoadGL()) {
		LOG(ERROR) << "Could not load OpenGL functions";
		//throw std::runtime_error("Could not initialize OpenGL");
	}

	render_available = true;
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearDepth(1.0);
}

wxBEGIN_EVENT_TABLE(texture_preview_canvas, wxGLCanvas)
EVT_PAINT(texture_preview_canvas::render)
EVT_SIZE(texture_preview_canvas::on_size_change)
wxEND_EVENT_TABLE()