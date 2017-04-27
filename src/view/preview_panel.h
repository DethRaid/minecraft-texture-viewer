#ifndef PREVIEW_PANEL_H
#define PREVIEW_PANEL_H

#include <memory>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/glcanvas.h>

class texture_preview_canvas : public wxGLCanvas {
public:
	texture_preview_canvas(wxFrame* parent, wxGLAttributes& attrs);
	void render(wxPaintEvent& event);
	void on_size_change(wxSizeEvent& event);
protected:
	wxDECLARE_EVENT_TABLE();
private:
	std::unique_ptr<wxGLContext> context;
	int window_height = 200;
	int window_width = 200;

	bool render_available = false;

	void init_opengl();
};


#endif // !PREVIEW_PANEL_H