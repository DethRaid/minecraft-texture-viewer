#include "data_loading.h"

renderable load_cube() {
	auto cube_mat = load_material("cube_lighting_pass");

	auto cube = renderable{};

	cube.set_material(cube_mat);
}