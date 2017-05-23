#include "texture_preview_canvas.h"

#include "../render/hdr_texture.h"

#include <easylogging++.h>
#include <stdexcept>
#include <glm/gtc/matrix_transform.hpp>

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
	SwapBuffers();

	init_resources();

	timer = std::make_unique<render_timer>(this);
	timer->start();

	mouse = std::make_unique<mouse_events_manager>(this, main_camera);
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
	main_camera.aspect_ratio = (float)window_width / (float)window_height;
}

void texture_preview_canvas::on_paint(wxPaintEvent& evt) {
	do_tick();
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
	LOG(DEBUG) << "OpenGL functions loaded";

	glDebugMessageCallback(error_callback, nullptr);

	render_available = true;
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearDepth(1.0);
	glViewport(0, 0, window_width, window_height);
}

void texture_preview_canvas::init_resources() {
	cube_lighting = load_material("cube_lighting_pass");
	cube_combine = load_material("cube_combine_pass");
	skybox_mat = load_material("skybox");

	cube = std::make_unique<entity>();
	cube->set_geometry(load_cube());
	cube->set_material(cube_lighting);
	
	fullscreen_quad = std::make_unique<entity>();
	fullscreen_quad->set_geometry(load_fullscreen_quad());
	fullscreen_quad->set_material(cube_combine);

	render_framebuffer = std::make_unique<framebuffer>(window_width, window_height);

	camera_transform.set_position({ 0, -0.75f, -2 });
	camera_transform.look_at({ 0, -0.75f, 0 });

	main_camera.fov = 60;
	main_camera.aspect_ratio = (float) window_width / (float) window_height;
	main_camera.near_plane = 0.1f;
	main_camera.far_plane = 100;

	camera_mats.projection_matrix = glm::perspective(glm::radians(main_camera.fov), main_camera.aspect_ratio, main_camera.near_plane, main_camera.far_plane);

	skybox_tex = std::make_shared<hdr_texture>(1, "textures/golden_autumn_road_small.hdr");
}

void texture_preview_canvas::do_tick() {
	cube->get_transform().set_rotation(CUBE_ROTATE_SPEED * elapsed_time, glm::vec3(0, 1, 0));

	render();

	auto cur_time = clock();
	delta_time = double(cur_time - last_frame_end) / CLOCKS_PER_SEC;
	last_frame_end = cur_time;
	elapsed_time += delta_time;
}

void texture_preview_canvas::render() {
	wxPaintDC dc(this);
	SetCurrent(*context);

	wxPaintDC(this);

	render_framebuffer->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDepthMask(false);
	fullscreen_quad->set_material(skybox_mat);
	fullscreen_quad->render(camera_mats);
	glDepthMask(true);

	camera_mats.view_matrix = camera_transform.get_transform_matrix();

	cube->render(camera_mats);

	render_framebuffer->generate_mipmaps();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	fullscreen_quad->set_material(cube_combine);
	fullscreen_quad->render();

	glFlush();
	SwapBuffers();
}

wxBEGIN_EVENT_TABLE(texture_preview_canvas, wxGLCanvas)
	EVT_PAINT(texture_preview_canvas::on_paint)
	EVT_IDLE(texture_preview_canvas::on_idle)
wxEND_EVENT_TABLE()