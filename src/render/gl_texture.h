#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

#include "glad.h"

#include <string>

class gl_texture {
public:
	/*!
	* \brief Initializes a new texture_model with the given texture data
	*
	* The given data is sent to the GPU
	*
	* \param data The raw data of the texture
	* \param width The width of the texture, in pixels
	* \param height The height of the texture, in pixels
	* \param num_components The number of color components that this texture has
	*/
	gl_texture();

	gl_texture(gl_texture&& other);

	/*!
	* \brief Destructor. Deletes the texture data and deletes the GPU texture object
	*/
	~gl_texture();

	GLuint get_gl_name();

	void set_color(int red, int green, int blue);
	void set_color(int grayscale);
	void load_from_file(std::string filename);

private:
	unsigned char* data;
	int width;
	int height;
	int num_components;

	GLuint gl_name;

	void upload_texture_data();
};

#endif