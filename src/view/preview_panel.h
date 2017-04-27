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
	preview_panel(wxFrame* parent);
	void render(wxPaintEvent& event);
protected:
	wxDECLARE_EVENT_TABLE();
private:
	std::unique_ptr<wxGLContext> context;
};


#endif // !PREVIEW_PANEL_H