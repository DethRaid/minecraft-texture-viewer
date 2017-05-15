#ifndef PREVIEW_PANEL_H
#define PREVIEW_PANEL_H

#include <memory>
#include "../render/glad.h"
#include "../render/renderable.h"
#include "../render/material.h"
#include "../render/data_loading.h"
#include "../render/framebuffer.h"
#include "../render/transform.h"
#include "../render/uniform_buffer.h"
#include "../render/buffers.h"
#include "../render/entity.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/glcanvas.h>
#include <wx/timer.h>

#include <glm/glm.hpp>

#define CUBE_ROTATE_SPEED 1

#undef near
#undef far

struct camera {
	float fov;
	float aspect_ratio;
	float near;
	float far;
};

class texture_preview_canvas;

class render_timer : public wxTimer {
	texture_preview_canvas* pane;
public:
	render_timer(texture_preview_canvas* pane);
	void Notify();
	void start();
};

class texture_preview_canvas : public wxGLCanvas {
public:
	texture_preview_canvas(wxFrame* parent, wxGLAttributes& attrs, wxSize& size);
	void on_size_change(wxSize& size);
	void on_paint(wxPaintEvent& evt);
	void on_idle(wxIdleEvent& evt);
	void render();
protected:
	wxDECLARE_EVENT_TABLE();
private:
	std::unique_ptr<wxGLContext> context;
	int window_height = 200;
	int window_width = 200;

	double delta_time;
	double elapsed_time = 0;
	clock_t last_frame_end = 0;

	bool render_available = false;

	std::unique_ptr<render_timer> timer;
	
	std::unique_ptr<uniform_buffer<camera_matrices>> camera_mats;
	std::unique_ptr<framebuffer> render_framebuffer;

	std::unique_ptr<entity> cube;
	std::shared_ptr<material> cube_lighting;
	std::shared_ptr<material> cube_combine;

	std::unique_ptr<entity> skybox;
	std::shared_ptr<material> skybox_mat;

	std::unique_ptr<entity> fullscreen_quad;
	std::shared_ptr<material> post_processing_mat;

	std::shared_ptr<material> test_mat;

	transform_data camera_transform;
	camera main_camera;

	void init_opengl();
	void init_resources();

	void do_tick();
};


#endif // !PREVIEW_PANEL_H