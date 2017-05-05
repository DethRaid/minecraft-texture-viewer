#version 450

in vec2 uv;
in vec3 normal;

layout(binding = 3) uniform sampler2D albedo_tex;

out vec4 color;

void main() {
    color = vec4(1);	// texture(albedo_tex, uv).rgb;
}