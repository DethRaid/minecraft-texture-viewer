#version 450

in vec2 uv;
in vec3 normal;

layout(binding = 12) uniform sampler2D albedo_tex;

layout(location = 0) out vec3 color_out;
layout(location = 1) out vec3 diffuse_out;
layout(location = 3) out vec3 normal_out;

void main() {
    color_out = texture(albedo_tex, uv).rgb;
	diffuse_out = vec3(max(0, dot(vec3(1, 1, 1), normal)));
	normal_out = normal * 0.5 + 0.5;
}