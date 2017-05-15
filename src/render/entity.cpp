#include "entity.h"

void entity::set_material(std::shared_ptr<material> new_mat) {
	mat = new_mat;
}

void entity::set_geometry(std::shared_ptr<renderable> new_geometry) {
	geometry = new_geometry;
}

transform_data& entity::get_transform() {
	return transform;
}

void entity::render(camera_matrices& camera_mats) {
	mat->bind();

	auto model_matrix = transform.get_transform_matrix();
	auto model_matrix_location = mat->get_uniform_location("model_matrix");
	glUniformMatrix4fv(model_matrix_location, 1, false, &model_matrix[0][0]);

	auto view_matrix_location = mat->get_uniform_location("view_matrix");
	glUniformMatrix4fv(view_matrix_location, 1, false, &camera_mats.view_matrix[0][0]);

	auto projection_matrix_location = mat->get_uniform_location("projection_matrix");
	glUniformMatrix4fv(projection_matrix_location, 1, false, &camera_mats.projection_matrix[0][0]);

	geometry->draw();
}
