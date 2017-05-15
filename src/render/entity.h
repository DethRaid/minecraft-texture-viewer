#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <glm/glm.hpp>

#include "transform.h"
#include "renderable.h"
#include "buffers.h"

class entity {
public:
	void set_material(std::shared_ptr<material> new_mat);
	void set_geometry(std::shared_ptr<renderable> new_geometry);

	transform_data& get_transform();

	void render(camera_matrices& camera_mats);
private:
	transform_data transform;
	std::shared_ptr<material> mat;
	std::shared_ptr<renderable> geometry;
};

#endif