#include "texture_preview_canvas.h"

#include "../render/hdr_texture.h"

#include <easylogging++.h>
#include <stdexcept>
#include <glm/gtc/matrix_transform.hpp>

void APIENTRY error_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* user_param) {
	LOG(ERROR) << message;
}

texture_preview_canvas::texture_preview_canvas(glm::ivec2& size, textures_struct& textures) : textures(textures) {
	window_height = size.y;
	window_width = size.x;

	init_opengl();

	init_resources();

	last_frame_end = clock();
}

void texture_preview_canvas::on_size_change(glm::ivec2& size) {
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

void texture_preview_canvas::on_mouse_event(wxMouseEvent& event) {
	event.Skip();

	auto mouse_pos = glm::vec2{ event.GetX(), event.GetY() };

	if(event.Dragging()) {
		mouse_delta = mouse_pos - last_mouse_pos;
	} else {
		dragging = false;
		mouse_delta = glm::vec2{ 0 };
	}

	last_mouse_pos = mouse_pos;

	auto wheel_rotation = (float)event.GetWheelRotation();
	auto wheel_delta = (float)event.GetWheelDelta();

	mousewheel_delta = wheel_rotation * wheel_delta;

	main_camera.respond_to_mouse_wheel(mousewheel_delta);
}

void texture_preview_canvas::init_opengl() {
	glDebugMessageCallback(error_callback, nullptr);

	render_available = true;
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearDepth(1.0);
	glViewport(0, 0, window_width, window_height);

	glHint(GL_AUTO_GENERATE_MIPMAP, GL_FASTEST);
	glHint(GL_MANUAL_GENERATE_MIPMAP, GL_NICEST);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
	glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
	glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
}

void texture_preview_canvas::init_resources() {
	load_shaders();

	cube = std::make_unique<entity>();
	cube->set_geometry(load_cube());
	cube->set_material(cube_lighting);
	
	fullscreen_quad = std::make_unique<entity>();
	fullscreen_quad->set_geometry(load_fullscreen_quad());
	fullscreen_quad->set_material(cube_combine);

	render_framebuffer = std::make_unique<framebuffer>(window_width, window_height);

	main_camera.rotation = { 0, 20 };
	main_camera.dist_from_origin = 4;

	main_camera.fov = 60;
	main_camera.aspect_ratio = (float) window_width / (float) window_height;
	main_camera.near_plane = 0.1f;
	main_camera.far_plane = 100;

	camera_mats.projection_matrix = main_camera.get_projection_matrix();

	change_background("golden_autumn_road.hdr");
}

void texture_preview_canvas::load_shaders() {
	cube_lighting = load_material("cube_lighting_pass");
	cube_combine = load_material("cube_combine_pass");
	skybox_mat = load_material("skybox");
}

void texture_preview_canvas::do_tick() {
	cube->get_transform().set_rotation(static_cast<float>(CUBE_ROTATE_SPEED * elapsed_time), glm::vec3(0, 1, 0));
	main_camera.respond_to_mouse_move(mouse_delta, static_cast<float>(delta_time));

	render();

	auto cur_time = clock();
	delta_time = double(cur_time - last_frame_end) / CLOCKS_PER_SEC;
	last_frame_end = cur_time;
	elapsed_time += delta_time;
}

void texture_preview_canvas::render() {
	render_framebuffer->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDepthMask(static_cast<GLboolean>(false));
	fullscreen_quad->set_material(skybox_mat);
	fullscreen_quad->render(camera_mats);
	glDepthMask(static_cast<GLboolean>(true));

	camera_mats.view_matrix = main_camera.get_view_matrix();

	cube->set_material(cube_lighting);
	setup_gbuffer_textures(cube_lighting);
	cube->render(camera_mats);

	render_framebuffer->generate_mipmaps();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	fullscreen_quad->set_material(cube_combine);
	setup_composite_textures(cube_combine);
	fullscreen_quad->render();

	glFlush();
}

void texture_preview_canvas::change_background(std::string background_name) {
	LOG(DEBUG) << "Loading background texture " << background_name;
	skybox_tex = std::make_shared<hdr_texture>(1, "textures/" + background_name);
}

void texture_preview_canvas::setup_gbuffer_textures(std::shared_ptr<material> mat) {
	auto environment_location = mat->get_uniform_location("environment");
	glUniform1i(environment_location, 1);

	auto albedo_tex_location = mat->get_uniform_location("albedo_tex");
	glUniform1i(albedo_tex_location, 3);
}

void texture_preview_canvas::setup_composite_textures(std::shared_ptr<material> mat) {
	auto diffuse_color_tex_location = mat->get_uniform_location("diffuse_color_tex");
	glUniform1i(diffuse_color_tex_location, 13);

	auto diffuse_light_tex_location = mat->get_uniform_location("diffuse_light_tex");
	glUniform1i(diffuse_light_tex_location, 14);

	auto specular_light_tex_location = mat->get_uniform_location("specular_light_tex");
	glUniform1i(specular_light_tex_location, 15);

	auto normal_tex_location = mat->get_uniform_location("normal_tex");
	glUniform1i(normal_tex_location, 16);
}