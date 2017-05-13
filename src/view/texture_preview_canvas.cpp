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

void APIENTRY error_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* user_param) {
	LOG(ERROR) << message;
}

texture_preview_canvas::texture_preview_canvas(wxFrame* parent, wxGLAttributes& attrs, wxSize& size) 
	: wxGLCanvas(parent, attrs, wxID_ANY, wxDefaultPosition, size) {
	wxGLContextAttrs contextAttribs;
	contextAttribs.PlatformDefaults().CoreProfile().OGLVersion(4, 5).DebugCtx().EndList();

	context = std::make_unique<wxGLContext>(this, nullptr, &contextAttribs);

	if(!context->IsOK()) {
		LOG(ERROR) << "Could not create OpenGL context";
		throw std::runtime_error("Could not initialize OpenGL");
	}

	SetCurrent(*context);

	init_opengl();
	glViewport(0, 0, window_width, window_height);
	SwapBuffers();

	init_resources();

	timer = std::make_unique<render_timer>(this);
	timer->start();
}

void texture_preview_canvas::on_size_change(wxSize& size) {
	SetCurrent(*context);

	window_height = size.y;
	window_width = size.x;
	LOG(INFO) << "Changing size to " << window_width << " by " << window_height;

	glViewport(0, 0, window_width, window_height);
	if(render_framebuffer) {
		render_framebuffer.reset();
	}
	render_framebuffer = std::make_unique<framebuffer>(window_width, window_height);
}

void texture_preview_canvas::on_paint(wxPaintEvent& evt) {
	render();
}

void texture_preview_canvas::on_idle(wxIdleEvent& evt) {
	Refresh();
}

void texture_preview_canvas::init_opengl() {
	if(!gladLoadGL()) {
		LOG(ERROR) << "Could not load OpenGL functions";
		el::Loggers::flushAll();
	
		//throw std::runtime_error("Could not initialize OpenGL");
	}

	glDebugMessageCallback(error_callback, nullptr);

	render_available = true;
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearDepth(1.0);

	LOG(INFO) << "OpenGL functions loaded";
}

void texture_preview_canvas::init_resources() {
	cube = std::make_shared<renderable>(load_cube());

	test_mat = load_material("test");
	cube_combine = load_material("cube_combine_pass");

	render_framebuffer = std::make_unique<framebuffer>(window_width, window_height);
}

void texture_preview_canvas::render() {
	wxPaintDC dc(this);
	SetCurrent(*context);

	wxPaintDC(this);

	render_framebuffer->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cube->set_material(test_mat);
	cube->draw();

	render_framebuffer->generate_mipmaps();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cube->set_material(cube_combine);
	cube->draw();
	
	glFlush();
	SwapBuffers();
}

wxBEGIN_EVENT_TABLE(texture_preview_canvas, wxGLCanvas)
	EVT_PAINT(texture_preview_canvas::on_paint)
	EVT_IDLE(texture_preview_canvas::on_idle)
wxEND_EVENT_TABLE()