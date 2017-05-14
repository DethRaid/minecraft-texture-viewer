#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

#include "glad.h"

#include <string>
#include <memory>

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

class gl_texture {
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
	gl_texture(int binding, int red, int green, int blue);

	/*!
	 * \brief Initializes a new gl_texture and sets its binding to the given binding location, initializing it to 
	 * provided grayscale value
	 *
	 * \param binding The location to bind this texture to
	 * \param grayscale The gray value of the texture
	 */
	gl_texture(int binding, int grayscale);

	/*!
	 * \brief Initializes a new gl_texture and sets its binding to the given binding location, initializing it from the 
	 * provided file path
	 *
	 * \param binding The location to bind this texture to
	 * \param filename The full filename of the file to load the file from. Should be a PNG, JPEG, or TIFF file
	 */
	gl_texture(int binding, std::string& filename);

	gl_texture(gl_texture&& other);

	/*!
	* \brief Destructor. Deletes the texture data and deletes the GPU texture object
	*/
	~gl_texture();

	GLuint get_gl_name();

private:
	unsigned char* data = nullptr;
	int width;
	int height;
	int num_components;

	GLuint gl_name;
	bool storage_allocated = false;

	void create(int binding);
	void upload_texture_data();
};

struct textures_struct {
	std::shared_ptr<gl_texture> albedo_tex;
	std::shared_ptr<gl_texture> opacity_tex;
	std::shared_ptr<gl_texture> normal_tex;
	std::shared_ptr<gl_texture> specular_tex;
	std::shared_ptr<gl_texture> smoothness_tex;
	std::shared_ptr<gl_texture> emission_tex;
	std::shared_ptr<gl_texture> height_tex;
	std::shared_ptr<gl_texture> porosity_tex;
	std::shared_ptr<gl_texture> translucence_tex;
	std::shared_ptr<gl_texture> ao_tex;
};

#endif