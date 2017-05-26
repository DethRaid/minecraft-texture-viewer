#version 450

layout(location = 0) in vec3 position_in;
layout(location = 3) in vec2 uv_in;

uniform mat4 view_matrix;
uniform vec3 camera_position;

out vec2 texcoord;
out vec3 view_vector;

#define PI 3.14159265

vec2 get_sky_coord(in vec3 direction) {
    float lon = atan(direction.z, direction.x);
    if(direction.z < 0) {
        lon = 2 * PI - atan(-direction.z, direction.x);
    }

    float lat = acos(direction.y);

    const vec2 rads = vec2(1.0 / (PI * 2.0), 1.0 / PI);
    vec2 sphereCoords = vec2(lon, lat) * rads;

    return sphereCoords;
}

void main() {
    gl_Position = vec4(position_in, 1);

	view_vector = normalize((view_matrix * vec4(position_in, 1.0)).xyz);

	texcoord = get_sky_coord(view_vector);
}