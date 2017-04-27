#ifndef APP_H
#define APP_H

#include <memory>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/app.h>
#endif

#include "main_window.h"

class texture_previewer_app : public wxApp {
public:
	virtual bool OnInit();
private:
	std::unique_ptr<main_window> main_app_window;
};

#endif