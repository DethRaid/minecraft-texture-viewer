#version 450

layout(binding = 1) uniform sampler2D environment;

in vec2 texcoord;

layout(location = 0) out vec3 color;

void main() {
	color = texture(environment, texcoord).rgb;
}