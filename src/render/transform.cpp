#include "transform.h"

#include <glm/gtc/matrix_transform.hpp>

void transform_data::rotate_by(float angle, glm::vec3 axis) {
	rotation = glm::rotate(rotation, angle, axis);
}

void transform_data::translate_by(glm::vec3 translation) {
	position += translation;
}

void transform_data::set_position(glm::vec3 position) {
	this->position = position;
}

void transform_data::set_rotation(float angle, glm::vec3 axis) {
	rotation = glm::rotate(glm::mat4(), angle, axis);
}

void transform_data::set_scale(glm::vec3 scale) {
	this->scale = scale;
}

void transform_data::look_at(glm::vec3 look_at_point) {
	rotation = glm::lookAt(look_at_point - position, position, glm::vec3(0, 1, 0));
}

glm::mat4 transform_data::get_transform_matrix() {
	glm::mat4 matrix = glm::translate(glm::mat4(), position);
	matrix *= rotation;
	matrix = glm::scale(matrix, scale);

	return matrix;
}
