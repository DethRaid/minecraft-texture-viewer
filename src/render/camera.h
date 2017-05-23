#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

struct camera {
	float fov;
	float aspect_ratio;
	float near_plane;
	float far_plane;

	glm::mat4 get_view_matrix();
	glm::mat4 get_projection_matrix();
};

#endif
