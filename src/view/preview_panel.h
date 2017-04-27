#ifndef PREVIEW_PANEL_H
#define PREVIEW_PANEL_H

#include <memory>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/glcanvas.h>

class preview_panel : public wxGLCanvas {
public:
	preview_panel(wxFrame* parent, wxGLAttributes& attrs);
	void render(wxPaintEvent& event);
	void on_size_change(wxSizeEvent& event);
protected:
	wxDECLARE_EVENT_TABLE();
private:
	std::unique_ptr<wxGLContext> context;
	int window_height;
	int window_width;
};


#endif // !PREVIEW_PANEL_H