#ifndef PREVIEW_PANEL_H
#define PREVIEW_PANEL_H

#include <memory>
#include "../render/glad.h"
#include "../render/renderable.h"
#include "../render/material.h"
#include "../render/data_loading.h"
#include "../render/framebuffer.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/glcanvas.h>
#include <wx/timer.h>

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

	bool render_available = false;

	std::unique_ptr<render_timer> timer;

	std::unique_ptr<framebuffer> render_framebuffer;
	std::shared_ptr<renderable> cube;
	std::shared_ptr<material> cube_lighting;
	std::shared_ptr<material> cube_combine;

	std::shared_ptr<material> test_mat;

	void init_opengl();
	void init_resources();
};


#endif // !PREVIEW_PANEL_H