#include "texture_preview_canvas.h"

#include <easylogging++.h>
#include <stdexcept>

render_timer::render_timer(texture_preview_canvas* pane) : wxTimer(), pane(pane) {}

void render_timer::Notify() {
	pane->Refresh();
}

void render_timer::start() {
	wxTimer::Start(16);
}

texture_preview_canvas::texture_preview_canvas(wxFrame* parent, wxGLAttributes& attrs, wxSize& size) 
	: wxGLCanvas(parent, attrs, wxID_ANY, wxDefaultPosition, size) {
	wxGLContextAttrs contextAttribs;
	contextAttribs.PlatformDefaults().CoreProfile().OGLVersion(4, 5).EndList();

	context = std::make_unique<wxGLContext>(this, nullptr, &contextAttribs);

	if(!context->IsOK()) {
		LOG(ERROR) << "Could not create OpenGL context";
		throw std::runtime_error("Could not initialize OpenGL");
	}

	SetCurrent(*context);

	init_opengl();
	glViewport(0, 0, window_width, window_height);

	init_resources();

	timer = std::make_unique<render_timer>(this);
	timer->start();
}

void texture_preview_canvas::on_size_change(wxSizeEvent& event) {
	event.Skip();

	SetCurrent(*context);

	PostSizeEvent();

	window_height = event.GetSize().y;
	window_height = event.GetSize().x;

	glViewport(0, 0, window_width, window_height);
}

void texture_preview_canvas::on_paint(wxPaintEvent& evt) {
	//wxPaintDC dc(this);
	render();
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

void texture_preview_canvas::init_resources() {
	cube = std::make_shared<renderable>(load_cube());

	auto test_material = load_material("test");
	cube->set_material(test_material);
}

void texture_preview_canvas::render() {
	SetCurrent(*context);

	wxPaintDC(this);
	glClear(GL_COLOR_BUFFER_BIT);

	cube->draw();

	glFlush();
	SwapBuffers();
}

wxBEGIN_EVENT_TABLE(texture_preview_canvas, wxGLCanvas)
	EVT_SIZE(texture_preview_canvas::on_size_change)
	EVT_PAINT(texture_preview_canvas::on_paint)
wxEND_EVENT_TABLE()