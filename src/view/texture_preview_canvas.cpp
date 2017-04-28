#include "texture_preview_canvas.h"

#include <easylogging++.h>
#include <stdexcept>

texture_preview_canvas::texture_preview_canvas(wxFrame* parent, wxGLAttributes& attrs, wxSize& size) 
	: wxGLCanvas(parent, attrs, wxID_ANY, wxDefaultPosition, size) {
	wxGLContextAttrs contextAttribs;
	contextAttribs.PlatformDefaults().CoreProfile().OGLVersion(4, 1).EndList();

	context = std::make_unique<wxGLContext>(this, nullptr, &contextAttribs);
	Bind(wxEVT_PAINT, &texture_preview_canvas::render, this);

	if(!context->IsOK()) {
		LOG(ERROR) << "Could not create OpenGL context";
		//throw std::runtime_error("Could not initialize OpenGL");
	}

	SetCurrent(*context);

	init_opengl();
	glViewport(0, 0, window_width, window_height);
}

void texture_preview_canvas::render(wxPaintEvent& WXUNUSED(event)) {
	LOG(INFO) << "Rendering";
	wxPaintDC(this);
	SetCurrent(*context);

	glClear(GL_COLOR);

	glFlush();
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

	LOG(INFO) << "OpenGL functions loaded";
}

wxBEGIN_EVENT_TABLE(texture_preview_canvas, wxGLCanvas)
EVT_PAINT(texture_preview_canvas::render)
EVT_SIZE(texture_preview_canvas::on_size_change)
wxEND_EVENT_TABLE()