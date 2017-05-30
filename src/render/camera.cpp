#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

glm::mat4 camera::get_projection_matrix() {
	return glm::perspective(glm::radians(fov), aspect_ratio, near_plane, far_plane);
}

glm::mat4 camera::get_view_matrix() {
	glm::mat4 view_matrix;
	view_matrix = glm::translate(view_matrix, { 0, 0, -dist_from_origin });
	view_matrix = glm::rotate(view_matrix, glm::radians(rotation.y), { 1, 0, 0 });
	view_matrix = glm::rotate(view_matrix, glm::radians(rotation.x), { 0, 1, 0 });

	return view_matrix;
}

void camera::respond_to_mouse_move(glm::vec2 mouse_delta, float delta_time) {
	rotation += mouse_delta * CAMERA_MOVE_SPEED * delta_time;
}

void camera::respond_to_mouse_wheel(float wheel_delta) {
	dist_from_origin += wheel_delta * CAMERA_ZOOM_SPEED;
}
