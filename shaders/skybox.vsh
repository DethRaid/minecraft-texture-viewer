#version 450

layout(location = 0) in vec3 position_in;
layout(location = 3) in vec2 uv_in;

uniform mat4 view_matrix;

out vec2 texcoord;
out vec3 view_vector;

void main() {
	texcoord = uv_in;

    gl_Position = vec4(position_in, 1);

	view_vector = normalize(vec3(0, 0.75, 0) - (view_matrix * vec4(position_in, 1.0)).xyz);
}