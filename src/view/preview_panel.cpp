#include "preview_panel.h"

#include <easylogging++.h>
#include <stdexcept>

preview_panel::preview_panel(wxFrame* parent) : wxGLCanvas(parent, wxID_ANY, nullptr, wxDefaultPosition, wxDefaultSize, 0, wxT("GLCanvas")) {
	wxGLContextAttrs contextAttribs;
	contextAttribs.CoreProfile().OGLVersion(4, 5).Robust().ResetIsolation().EndList();

	context = std::make_unique<wxGLContext>(this, nullptr, &contextAttribs);

	if(!context->IsOK()) {
		LOG(ERROR) << "Could not create OpenGL context";
		throw std::runtime_error("Could not initialize OpenGL");
	}

	context->SetCurrent(*this);
}

void preview_panel::render(wxPaintEvent& WXUNUSED(event)) {
	wxPaintDC(this);
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR);

	glFlush();
	SwapBuffers();
}

wxBEGIN_EVENT_TABLE(preview_panel, wxGLCanvas)
EVT_PAINT(preview_panel::render)
wxEND_EVENT_TABLE()