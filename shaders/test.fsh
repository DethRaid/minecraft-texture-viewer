#version 450

in vec2 uv;
in vec3 normal;

layout(binding = 3) uniform sampler2D albedo_tex;

layout(location = 0) out vec4 color_out;
layout(location = 3) out vec3 normal_out;

void main() {
    color_out = vec4(normal, 1);	// texture(albedo_tex, uv).rgb;
	normal_out = normal * 0.5 + 0.5;
}