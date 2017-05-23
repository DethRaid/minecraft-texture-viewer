#ifndef MOUSE_EVENTS_MANAGER_H
#define MOUSE_EVENTS_MANAGER_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/mousemanager.h>
#include "../render/camera.h"

/*!
 * \brief Allows people to drag on the texture previewer OpenGL canvas in order to move the camera around
 */
class mouse_events_manager : public wxMouseEventsManager {
public:
	/*!
	 * \brief Initializes this mouse_events_manager to receive mouse events from the provided wxWindow and to control
	 * the provided camera
	 *
	 * \param win The wxWindow to receive mouse events from
	 * \param cam The camera to control
	 */
	mouse_events_manager(wxWindow *win, camera& cam);

protected:
	virtual int MouseHitTest(const wxPoint& pos);

	 bool MouseClicked(int item);

	virtual bool MouseDragBegin(int item, const wxPoint& pos);

	virtual void MouseDragging(int item, const wxPoint& pos);

	virtual void MouseDragEnd(int item, const wxPoint& pos);

	virtual void MouseDragCancelled(int item);
private:
	camera& controlled_camera;

	wxPoint last_frame_pos;
	bool is_dragging;
};

#endif