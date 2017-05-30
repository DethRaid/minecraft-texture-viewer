#version 450

layout(location = 0) in vec3 position_in;
layout(location = 1) in vec3 normal_in;
layout(location = 2) in vec3 tangent_in;
layout(location = 3) in vec2 uv_in;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;
uniform vec3 camera_position;

out vec2 uv;
out vec3 normal;

out mat3 tbn_matrix;

out vec3 view_vector;
out vec3 reflection_direction;
out vec3 position_viewspace;

void main() {
    uv = uv_in;
	
	mat4 mv = view_matrix * model_matrix;
	mat4 mvp = projection_matrix * mv;

	tbn_matrix = mat3(mv);
    normal = tbn_matrix * normal_in;
	    
    gl_Position = mvp * vec4(position_in, 1);
	
	position_viewspace = (mv * vec4(position_in, 1)).xyz;
	vec4 camera_position_viewspace = view_matrix * vec4(camera_position, 1);
	view_vector = normalize(position_viewspace.xyz - camera_position_viewspace.xyz);
	reflection_direction = reflect(view_vector, normal);
}