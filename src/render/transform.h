#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm\glm.hpp>

class transform_data {
public:
	void rotate_by(float angle, glm::vec3 axis);
	void translate_by(glm::vec3 translation);

	void set_position(glm::vec3 position);
	void set_rotation(float angle, glm::vec3 axis);
	void set_scale(glm::vec3 scale);

	void look_at(glm::vec3 look_at_point);

	glm::mat4 get_transform_matrix();

private:
	glm::vec3 position;
	glm::mat4 rotation;
	glm::vec3 scale = glm::vec3(1, 1, 1);
};

#endif