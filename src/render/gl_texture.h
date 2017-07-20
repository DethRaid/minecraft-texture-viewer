#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

#include "glad.h"

#include <string>
#include <memory>

#include <glm/glm.hpp>

#define ALBEDO_BINDING			3
#define OPACITY_BINDING			4
#define NORMAL_BINDING			5
#define HEIGHT_BINDING			6
#define EMISSION_BINDING		7
#define TRANSLUCENCE_BINDING	8
#define SMOOTHNESS_BINDING		9
#define POROSITY_BINDING		10
#define F0_BINDING				11
#define AO_BINDING				12

class texture {
public:
	/*!
	* \brief Initializes a new gl_texture and sets its binding to the given binding location, initializing it to the 
	* provided color
	*
	* \param binding The location to bind this texture to
	* \param red The amount of red to be in the texture
	* \param green The amount of green to be in the texture
	* \param blue The amount of blue to be in the texture
	*/
	texture(int binding, int red, int green, int blue);

	/*!
	 * \brief Initializes a new gl_texture and sets its binding to the given binding location, initializing it to 
	 * provided grayscale value
	 *
	 * \param binding The location to bind this texture to
	 * \param grayscale The gray value of the texture
	 */
	texture(int binding, int grayscale);

	/*!
	 * \brief Initializes a new gl_texture and sets its binding to the given binding location, initializing it from the 
	 * provided file path
	 *
	 * \param binding The location to bind this texture to
	 * \param filename The full filename of the file to load the file from. Should be a PNG, JPEG, or TIFF file
	 */
	texture(int binding, std::string& filename);

	texture(texture&& other);

	/*!
	* \brief Destructor. Deletes the texture data and deletes the GPU texture object
	*/
	~texture();

	GLuint get_gl_name();

	std::string& get_filepath();

	/*!
	 * \brief Gets the value of the texture at the specified UV coordinates
	 *
	 * If the texture has fewer than four channels, the missing components wil be set to 0
	 *
	 * \param uv The UV coordinate to get the value of
	 * \prarm bilinear If true, use bilinear filtering. If false, use point filtering
	 * \return The texel at the given UV coordinate
	 */
	glm::vec4 at(glm::vec2 uv, bool bilinear = false);

protected:
	unsigned char* data = nullptr;
	int width;
	int height;
	int num_components;

	GLuint gl_name;
	std::string filepath;

	texture();

	void create(int binding);
	virtual void upload_texture_data();

	glm::vec4 at_point(glm::vec2 uv);
	glm::vec4 at_bilinear(glm::vec2 uv);
	glm::vec4 texel_fetch(int x, int y);
};

struct textures_struct {
	std::shared_ptr<texture> albedo_tex;
	std::shared_ptr<texture> opacity_tex;
	std::shared_ptr<texture> normal_tex;
	std::shared_ptr<texture> f0_tex;
	std::shared_ptr<texture> smoothness_tex;
	std::shared_ptr<texture> emission_tex;
	std::shared_ptr<texture> height_tex;
	std::shared_ptr<texture> porosity_tex;
	std::shared_ptr<texture> translucence_tex;
	std::shared_ptr<texture> ao_tex;
};

glm::vec4 operator*(glm::vec4 vec, float f);

#endif