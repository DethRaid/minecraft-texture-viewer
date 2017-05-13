#version 450

in vec2 uv;
in vec3 normal;

layout(binding = 13) uniform sampler2D diffuse_color_tex;
layout(binding = 14) uniform sampler2D diffuse_light_tex;
layout(binding = 15) uniform sampler2D specular_light_tex;
layout(binding = 16) uniform sampler2D normal_tex;

layout(location = 0) out vec4 final_color;

void main() {
	vec3 color_sample = texture(diffuse_color_tex, uv).rgb;

	final_color = vec4(color_sample, 1);
}