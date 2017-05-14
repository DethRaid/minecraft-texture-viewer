#version 450

layout(location = 0) in vec3 position_in;
layout(location = 1) in vec3 normal_in;
layout(location = 2) in vec3 tangent_in;
layout(location = 3) in vec2 uv_in;

layout(binding = 0, std140) uniform MVP {
	mat4 model_matrix;
	mat4 view_matrix;
	mat4 projection_matrix;
};

out vec2 uv;
out vec3 normal;

out mat3 tbn_matrix;

out vec3 view_vector;

void main() {
    uv = uv_in;
    normal = normal_in;

	mat4 mvp = projection_matrix * view_matrix * model_matrix;
    
    gl_Position = mvp * vec4(position_in - vec3(0, 0, 0.8), 1);

	tbn_matrix = mat3(view_matrix * model_matrix);

	view_vector = vec3(0, 0.75, 0) - (view_matrix * model_matrix * vec4(position_in, 1.0)).xyz;
}