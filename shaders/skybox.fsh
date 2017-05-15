#version 450

layout(binding = 1) uniform sampler2D skybox;

in vec2 texcoord;
in vec3 view_vector;

layout(location = 0) out vec3 color;

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
	vec2 sky_coord = get_sky_coord(view_vector);
	color = texture(skybox, sky_coord).rgb;
}