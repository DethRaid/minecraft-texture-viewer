#include "data_loading.h"

renderable load_cube() {
	auto cube_mat = load_material("cube");

	auto cube = renderable{};

	cube.set_material(cube_mat);
}