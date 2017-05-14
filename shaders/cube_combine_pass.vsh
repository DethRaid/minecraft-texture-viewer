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

void main() {
    uv = uv_in;
    normal = normal_in;
    
    gl_Position = vec4(position_in - vec3(0, 0, 0.8), 1);
}