#ifndef DATA_LOADING_H
#define DATA_LOADING_H

#include "renderable.h"

renderable load_cube();

std::shared_ptr<material> load_material(std::string material_name);

#endif // !DATA_LOADING_H
