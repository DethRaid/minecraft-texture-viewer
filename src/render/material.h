#ifndef MATERIAL_H
#define MATERIAL_H

#include "glad.h"

#include <unordered_map>
#include <string>

/*!
 * \brief Defines a material that can be used to render things
 */
class material {
public:
	material(std::string fragment_shader_source, std::string vertex_shader_source);

	void bind();
	GLuint get_uniform_location(std::string uniform_name);
private:
	std::unordered_map<std::string, GLuint> uniform_locations;
	GLuint program_id;
};

GLuint create_shader(const std::string& shader_source, const GLenum shader_type);
GLuint create_program(GLuint vertex_id, GLuint fragment_id);
void check_for_shader_errors(GLuint shader_to_check);
void check_for_linking_errors(GLuint gl_name);

#endif