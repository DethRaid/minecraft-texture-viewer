#include "data_loading.h"

#include <fstream>

#include <easylogging++.h>

#define MATERIAL_DIRECTORY "shaders/"

renderable load_cube() {
	auto cube = renderable{};

	auto vertices = std::vector<vertex>{
		// Front face
		{
			{ -0.5, -0.5, 0.5 },
			{ 0, 0, 1 },
			{ 1, 0, 0 },
			{ 0, 1 }
		},
		{
			{ -0.5, 0.5, 0.5 },
			{ 0, 0, 1 },
			{ 1, 0, 0 },
			{ 0, 0 }
		},
		{
			{ 0.5, -0.5, 0.5 },
			{ 0, 0, 1 },
			{ 1, 0, 0 },
			{ 1, 1 }
		},
		{
			{ 0.5, 0.5, 0.5 },
			{ 0, 0, 1 },
			{ 1, 0, 0 },
			{ 1, 0 }
		},

		// Back face
		{
			{ 0.5, -0.5, -0.5 },
			{ 0, 0, -1 },
			{ -1, 0, 0 },
			{ 0, 1 }
		},
		{
			{ 0.5, 0.5, -0.5 },
			{ 0, 0, -1 },
			{ -1, 0, 0 },
			{ 0, 0 }
		},
		{
			{ -0.5, -0.5, -0.5 },
			{ 0, 0, -1 },
			{ -1, 0, 0 },
			{ 1, 1 }
		},
		{
			{ -0.5, 0.5, -0.5 },
			{ 0, 0, -1 },
			{ -1, 0, 0 },
			{ 1, 0 }
		},

		// Right face
		{
			{ 0.5, -0.5, 0.5 },
			{ 1, 0, 0 },
			{ 0, 0, -1 },
			{ 0, 1 }
		},
		{
			{ 0.5, 0.5, 0.5 },
			{ 1, 0, 0 },
			{ 0, 0, -1 },
			{ 0, 0 }
		},
		{
			{ 0.5, -0.5, -0.5 },
			{ 1, 0, 0 },
			{ 0, 0, -1 },
			{ 1, 1 }
		},
		{
			{ 0.5, 0.5, -0.5 },
			{ 1, 0, 0 },
			{ 0, 0, -1 },
			{ 1, 0 }
		},

		// Left face
		{
			{ -0.5, -0.5, -0.5 },
			{ -1, 0, 0 },
			{ 0, 0, 1 },
			{ 0, 1 }
		},
		{
			{ -0.5, -0.5, 0.5 },
			{ -1, 0, 0 },
			{ 0, 0, 1 },
			{ 0, 0 }
		},
		{
			{ -0.5, 0.5, -0.5 },
			{ -1, 0, 0 },
			{ 0, 0, 1 },
			{ 1, 1 }
		},
		{
			{ -0.5, 0.5, 0.5 },
			{ -1, 0, 0 },
			{ 0, 0, 1 },
			{ 1, 0 }
		},

		// Top face
		{
			{ -0.5, 0.5, 0.5 },
			{ 0, 1, 0 },
			{ 1, 0, 0 },
			{ 0, 1 }
		},
		{
			{ 0.5, 0.5, 0.5 },
			{ 0, 1, 0 },
			{ 1, 0, 0 },
			{ 0, 0 }
		},
		{
			{ -0.5, 0.5, -0.5 },
			{ 0, 1, 0 },
			{ 1, 0, 0 },
			{ 1, 1 }
		},
		{
			{ 0.5, 0.5, -0.5 },
			{ 0, 1, 0 },
			{ 1, 0, 0 },
			{ 1, 0 }
		},

		// Bottom face
		{
			{ 0.5, -0.5, -0.5 },
			{ 0, -1, 0 },
			{ -1, 0, 0 },
			{ 0, 1 }
		},
		{
			{ -0.5, -0.5, -0.5 },
			{ 0, -1, 0 },
			{ -1, 0, 0 },
			{ 0, 0 }
		},
		{
			{ 0.5, -0.5, 0.5 },
			{ 0, -1, 0 },
			{ -1, 0, 0 },
			{ 1, 1 }
		},
		{
			{ -0.5, -0.5, 0.5 },
			{ 0, -1, 0 },
			{ -1, 0, 0 },
			{ 1, 0 }
		},
	};

	auto indices = std::vector<int>{
		0, 1, 2, 1, 2, 3,
		4, 5, 6, 5, 6, 7,
		8, 9, 10, 9, 10, 11,
		12, 13, 14, 13, 14, 15,
		16, 17, 18, 17, 18, 19,
		20, 21, 22, 21, 22, 23
	};

	cube.set_vertex_data(vertices, indices);

	return cube;
}

std::shared_ptr<material> load_material(std::string material_name) {
	auto vertex_shader_filename = MATERIAL_DIRECTORY + material_name + ".vsh";
	auto vertex_shader_file = std::ifstream(vertex_shader_filename, std::ios_base::in);
	if(!vertex_shader_file) {
		LOG(FATAL) << "Could not load vertex shader for material " << material_name;
	}

	auto vertex_buffer = std::stringstream{};
	vertex_buffer << vertex_shader_file.rdbuf();
	auto vertex_shader_source = vertex_buffer.str();

	auto fragment_shader_filename = MATERIAL_DIRECTORY + material_name + ".fsh";
	auto fragment_shader_file = std::ifstream(fragment_shader_filename, std::ios_base::in);
	if(!fragment_shader_file) {
		LOG(FATAL) << "Could not load fragment shader for material " << material_name;
	}

	auto fragment_buffer = std::stringstream{};
	fragment_buffer << fragment_shader_file.rdbuf();
	auto fragment_shader_soruce = fragment_buffer.str();
	
	return std::make_shared<material>(fragment_shader_soruce, vertex_shader_source);
}