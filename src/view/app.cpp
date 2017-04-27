#include "app.h"

bool texture_previewer_app::OnInit() {
	main_app_window = std::make_unique<main_window>();
	main_app_window->Show(true);
	return true;
}

void main(int argc, char** argv) {
	wxApp* app = new texture_previewer_app();
	wxApp::SetInstance(app);
	wxEntry(argc, argv);
}