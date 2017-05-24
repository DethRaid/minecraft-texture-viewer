#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include "transform.h"

#define CAMERA_MOVE_SPEED	0.01f

struct camera {
	float fov;
	float aspect_ratio;
	float near_plane;
	float far_plane;
	transform_data transform;

	glm::mat4 get_projection_matrix();
	 
	/*!
	 * \brief Maked the camera respond to the provided mouse movement
	 *
	 * The idea is that the camera class can encapsulate how it responds to mouse movements. There's already far too much
	 * code in texture_preview_canvas
	 *
	 * \param mouse_delta How much the mouse moved
	 * \param delta_time The time that the last frame took
	 */
	void respond_to_mouse_move(glm::vec2 mouse_delta, float delta_time);
};

#endif
