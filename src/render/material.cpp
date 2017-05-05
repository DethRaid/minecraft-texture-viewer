#include "material.h"

#include <easylogging++.h>

material::material(std::string fragment_shader_soruce, std::string vertex_shader_source) {
	auto fragment_id = create_shader(fragment_shader_soruce, GL_FRAGMENT_SHADER);
	auto vertex_id = create_shader(vertex_shader_source, GL_VERTEX_SHADER);

	program_id = create_program(fragment_id, vertex_id);
}

GLuint material::get_uniform_location(std::string uniform_name) {
	if(uniform_locations.find(uniform_name) == uniform_locations.end()) {
		uniform_locations[uniform_name] = glGetUniformLocation(program_id, uniform_name.c_str());
	}

	return uniform_locations[uniform_name];
}

GLuint create_program(GLuint vertex_id, GLuint fragment_id) {
	GLuint program_id = glCreateProgram();
	LOG(TRACE) << "Created shader program " << program_id;

	glAttachShader(program_id, vertex_id);
	glAttachShader(program_id, fragment_id);

	glLinkProgram(program_id);
	check_for_linking_errors(program_id);

	LOG(DEBUG) << "Program " << program_id << " linked successfully";

	// Clean up our resources. I'm told that this is a good thing.
	glDetachShader(program_id, vertex_id);
	glDeleteShader(vertex_id);
	glDetachShader(program_id, fragment_id);
	glDeleteShader(fragment_id);

	return program_id;
}

GLuint create_shader(const std::string& shader_source, const GLenum shader_type) {
	// Check what kind of shader we're dealing with

	auto shader_name = glCreateShader(shader_type);

	const char *shader_source_char = shader_source.c_str();

	glShaderSource(shader_name, 1, &shader_source_char, NULL);

	glCompileShader(shader_name);

	check_for_shader_errors(shader_name);

	return shader_name;
}

void check_for_shader_errors(GLuint shader_to_check) {
	GLint success = 0;

	glGetShaderiv(shader_to_check, GL_COMPILE_STATUS, &success);

	if(success == GL_FALSE) {
		GLint log_size = 0;
		glGetShaderiv(shader_to_check, GL_INFO_LOG_LENGTH, &log_size);

		std::vector<GLchar> error_log((unsigned long long int) log_size);
		glGetShaderInfoLog(shader_to_check, log_size, &log_size, &error_log[0]);

		if(log_size > 0) {
			glDeleteShader(shader_to_check);
			LOG(ERROR) << error_log.data();
		}
	}
}

void check_for_linking_errors(GLuint gl_name) {
	GLint is_linked = 0;
	glGetProgramiv(gl_name, GL_LINK_STATUS, &is_linked);

	if(is_linked == GL_FALSE) {
		GLint log_length = 0;
		glGetProgramiv(gl_name, GL_INFO_LOG_LENGTH, &log_length);

		GLchar *info_log = (GLchar *)malloc(log_length * sizeof(GLchar));
		glGetProgramInfoLog(gl_name, log_length, &log_length, info_log);

		if(log_length > 0) {
			glDeleteProgram(gl_name);

			LOG(ERROR) << "Error linking program " << gl_name << ":\n" << info_log;
		}

	}
}