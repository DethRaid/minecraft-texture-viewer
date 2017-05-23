#version 450

in vec2 uv;
in vec3 normal;

in mat3 tbn_matrix;

in vec3 view_vector;

layout(binding = 1) uniform sampler2D environment;
layout(binding = 3) uniform sampler2D albedo_tex;

layout(location = 0) out vec3 color_out;
layout(location = 1) out vec3 diffuse_out;
layout(location = 2) out vec3 specular_out;
layout(location = 3) out vec3 normal_out;

#define PI 3.14159265

vec2 get_sky_coord(in vec3 direction) {
    float lon = atan(direction.z, direction.x);
    if(direction.z < 0) {
        lon = 2 * PI - atan(-direction.z, direction.x);
    }

    float lat = acos(direction.y);

    const vec2 rads = vec2(1.0 / (PI * 2.0), 1.0 / PI);
    vec2 sphereCoords = vec2(lon, lat) * rads;
    sphereCoords.y = 1.0 - sphereCoords.y;

    return sphereCoords;
}

void main() {
	vec3 light_direction = vec3(1, 1, 1);
	vec3 normal_viewspace = normalize(tbn_matrix * normal);
	
    color_out = texture(albedo_tex, uv).rgb;
	diffuse_out = texture(environment, get_sky_coord(normal_viewspace), 7).rgb;
	
	vec3 reflection_direction = reflect(-view_vector, normal_viewspace);

	// Phong specularity
	vec3 h = (view_vector + normal_viewspace) * 0.5;
	vec3 r = reflect(reflection_direction, h);
	float ndoth = max(0, dot(normal_viewspace, h));

	specular_out = texture(environment, get_sky_coord(reflection_direction), 7).rgb;

	normal_out = normal_viewspace * 0.5 + 0.5;
}