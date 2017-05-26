#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

glm::mat4 camera::get_projection_matrix() {
	return glm::perspective(glm::radians(fov), aspect_ratio, near_plane, far_plane);
}

void camera::respond_to_mouse_move(glm::vec2 mouse_delta, float delta_time) {
	static auto world_up = glm::vec3{ 0, 1, 0 };
	auto forward = -transform.get_position();
	auto left = glm::cross(world_up, forward);
	auto up = glm::cross(-left, forward);

	auto translation_amount = up * mouse_delta.y + left * -mouse_delta.x;

	transform.translate_by(translation_amount * CAMERA_MOVE_SPEED * delta_time);
	transform.look_at({ 0, -0.75f, 0 });
}