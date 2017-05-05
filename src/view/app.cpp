#include "app.h"
#include <easylogging++.h>
#include <easylogging++.cc>

INITIALIZE_EASYLOGGINGPP

bool texture_previewer_app::OnInit() {
	main_app_window = std::make_unique<main_window>();
	main_app_window->Show(true);
	return true;
}

int texture_previewer_app::OnExit() {
	main_app_window.release();
	return 0;
}

void main(int argc, char** argv) {
	wxApp* app = new texture_previewer_app();
	wxApp::SetInstance(app);
	wxEntry(argc, argv);
}