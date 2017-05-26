#version 450

layout(binding = 1) uniform sampler2D skybox;

in vec2 texcoord;
in vec3 view_vector;

layout(location = 0) out vec3 color;

void main() {
	color = texture(skybox, texcoord).rgb;
}