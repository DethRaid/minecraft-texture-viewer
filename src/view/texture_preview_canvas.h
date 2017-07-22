#ifndef PREVIEW_PANEL_H
#define PREVIEW_PANEL_H

#include <memory>
#include "../render/glad.h"
#include "../render/renderable.h"
#include "../render/material.h"
#include "../render/data_loading.h"
#include "../render/framebuffer.h"
#include "../render/transform.h"
#include "../render/buffers.h"
#include "../render/entity.h"
#include "../render/gl_texture.h"
#include "../render/camera.h"


#include <glm/glm.hpp>

#define CUBE_ROTATE_SPEED 0.1f

class texture_preview_canvas {
public:
	explicit texture_preview_canvas(glm::ivec2& size, textures_struct& textures);

	void do_tick();

	void load_shaders();
	void change_background(std::string background_name);

	void on_size_change(glm::ivec2& size);

private:
	int window_height = 200;
	int window_width = 200;

	double delta_time = 0;
	double elapsed_time = 0;
	clock_t last_frame_end = 0;

	textures_struct& textures;

	bool render_available = false;

	bool dragging = false;
	glm::vec2 last_mouse_pos;
	glm::vec2 mouse_delta;
	float mousewheel_delta = 0;

	camera_matrices camera_mats;
	std::unique_ptr<framebuffer> render_framebuffer;

	std::unique_ptr<entity> cube;
	std::shared_ptr<material> cube_lighting;
	std::shared_ptr<material> cube_combine;

	std::unique_ptr<entity> fullscreen_quad;
	std::shared_ptr<texture> skybox_tex;
	std::shared_ptr<material> skybox_mat;
	std::shared_ptr<material> post_processing_mat;
	
	camera main_camera;

	void init_opengl();
	void init_resources();

	void setup_gbuffer_textures(std::shared_ptr<material> mat);
	void setup_composite_textures(std::shared_ptr<material> mat);

	void render();
};


#endif // !PREVIEW_PANEL_H