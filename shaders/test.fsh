#version 450

in vec2 uv;
in vec3 normal;

in mat3 tbn_matrix;

in vec3 view_vector;

layout(binding = 3) uniform sampler2D albedo_tex;

layout(location = 0) out vec3 color_out;
layout(location = 1) out vec3 diffuse_out;
layout(location = 2) out vec3 specular_out;
layout(location = 3) out vec3 normal_out;

void main() {
	vec3 light_direction = vec3(1, 1, 1);
	vec3 normal_viewspace = normalize(tbn_matrix * normal);

    color_out = texture(albedo_tex, uv).rgb;
	diffuse_out = vec3(max(0, dot(light_direction, normal_viewspace)));

	// Phong specularity
	vec3 h = (view_vector + normal_viewspace) * 0.5;
	vec3 r = reflect(-light_direction, h);
	float ndoth = max(0, dot(normal_viewspace, h));

	specular_out = vec3(pow(ndoth, 5) * 0.01);

	normal_out = normal_viewspace * 0.5 + 0.5;
}