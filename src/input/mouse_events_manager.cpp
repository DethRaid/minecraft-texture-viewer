#include "mouse_events_manager.h"

mouse_events_manager::mouse_events_manager(wxWindow *win, camera& cam) : wxMouseEventsManager(win), controlled_camera(cam) {}

bool mouse_events_manager::MouseDragBegin(int item, const wxPoint& pos) {
	last_frame_pos = pos;
	is_dragging = true;
}

void mouse_events_manager::MouseDragging(int item, const wxPoint& pos) {
	wxPoint delta = pos - last_frame_pos;

	last_frame_pos = pos;
}

void mouse_events_manager::MouseDragEnd(int item, const wxPoint& pos) {}

void mouse_events_manager::MouseDragCancelled(int item) {}

int mouse_events_manager::MouseHitTest(const wxPoint& pos) {}

bool mouse_events_manager::MouseClicked(int item) {}
