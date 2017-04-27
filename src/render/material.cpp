#include "material.h"

material::material(std::string fragment_shader_soruce, std::string vertex_shader_source) {
	program_id = glCreateProgram();
}