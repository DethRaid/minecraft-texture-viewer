#ifndef MATERIAL_H
#define MATERIAL_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <unordered_map>
#include <string>

/*!
 * \brief Defines a material that can be used to render things
 */
class material {
	material(std::string fragment_shader_source, std::string vertex_shader_source);

	GLuint get_uniform_location(std::string uniform_name);
private:
	std::unordered_map<std::string, GLuint> uniform_locations;
	GLuint program_id;
};

#endif