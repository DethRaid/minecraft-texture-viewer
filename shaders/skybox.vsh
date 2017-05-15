#version 450

layout(location = 0) in vec3 position_in;
layout(location = 3) in vec2 uv_in;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;

out vec2 texcoord;
out vec3 view_vector;

void main() {
	texcoord = uv_in;

	mat4 mvp = projection_matrix * view_matrix * model_matrix;    
    gl_Position = mvp * vec4(position_in, 1);

	view_vector = vec3(0, 0.75, 0) - (view_matrix * model_matrix * vec4(position_in, 1.0)).xyz;
}